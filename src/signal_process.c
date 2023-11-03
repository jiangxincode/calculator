#include <gtk/gtk.h>

#include "../include/calculator.h"

GdkPixbuf *create_pixbuf(const gchar *filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf)
	{
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

void callback_radix_convert(GtkWidget *widget, gpointer data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
	{
		if (strncmp((char *) data, "Hex", 3) == 0)
		{
			show_hex_window();
			radix = 16;
		}
		else if (strncmp((char *) data, "Dec", 3) == 0)
		{
			show_dec_window();
			radix = 10;
		}
		else if (strncmp((char *) data, "Oct", 3) == 0)
		{
			show_oct_window();
			radix = 8;
		}
		else if (strncmp((char *) data, "Bin", 3) == 0)
		{
			show_bin_window();
			radix = 2;
		}
		else
		{
			perror("error:callback_radix_convert");
			exit(1);
		}
	}
}

void binary_operator() /*双目运算*/
{
	char num[20];
	strcpy(num, gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry))));/*取得文本框的内容*/
	if (first_op == 0) /*如果没有第一个数，则存储为第一个数*/
	{
		conversion(num, radix, 10); //全部转为十进制
		first_op = value_in_decimal;
		gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), "", strlen("")); /*清空文本框*/
	}
	else /*如果已有第一个数，则应存储为第二个数*/
	{
		conversion(num, radix, 10); //全部转为十进制
		second_op = value_in_decimal;
	}
	has_dot = 0; /*表示已经没有小数点*/
}

void right_output() /*单目运算结果输出*/
{
	char num[20];
	if (gcvt(first_op, 32, num) == NULL) /*运算结果转换成字符串*/
	{
		perror("error:Right_output");
	}
	conversion(num, 10, radix); /*将运算结果（十进制字符串）转换成指定进制数*/
	gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), out, strlen(out)); /*显示结果*/
	first_op = 0;
	second_op = 0;
	method = 0;
}

float fun(int c) /*递归函数求阶乘*/
{
	float d;
	if (c == 0 || c == 1)
		d = 1;
	else
		d = fun(c - 1) * c;
	return d;
}

void error_handle(const char* info)
{
	first_op = 0;
	second_op = 0;
	method = 0;
	gchar* text = g_convert(info, -1, "UTF-8", "GB2312", NULL, NULL, NULL);
	gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), text, strlen(text)); /*显示出错信息*/
}

void output() /*双目运算结果输出*/
{
	char num[20];
	strcpy(num, gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry)))); /* 取得文本框输入的内容*/
	conversion(num, radix, 10); /*将输入的进制数转换为十进制*/
	second_op = value_in_decimal;
	switch (method)
	{
	case 0:
		first_op = first_op + second_op;
		right_output();
		break;
	case 1:
		first_op = first_op - second_op;
		right_output();
		break;
	case 2:
		first_op = first_op * second_op;
		right_output();
		break;
	case 3:
		if (second_op == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			first_op = first_op / second_op;
			right_output();
		}
		break;
	case 4:
		first_op = pow(first_op, second_op);
		right_output();
		break;
	case 5:
		first_op = ((int) first_op) & ((int) second_op);
		right_output();
		break;
	case 6:
		first_op = ((int) first_op) | ((int) second_op);
		right_output();
		break;
	case 7:
		first_op = ((int) first_op) ^ ((int) second_op);
		right_output();
		break;
	case 8:
		if (second_op == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			first_op = ((int) first_op) % ((int) second_op);
			right_output();
		}
		break;
	case 9:
		first_op = sin(second_op);
		right_output();
		break;
	case 10:
		first_op = cos(second_op);
		right_output();
		break;
	case 11:
		first_op = tan(second_op);
		right_output();
		break;
	case 12:
		first_op = exp(second_op);
		right_output();
		break;
	case 13:
		first_op = second_op * second_op * second_op;
		right_output();
		break;
	case 14:
		first_op = second_op * second_op;
		right_output();
		break;
	case 15:
		if (second_op <= 0)
		{
			error_handle("对数必须为正数");
		}
		else
		{
			first_op = log(second_op);
			right_output();
		}
		break;
	case 16:
		if (second_op <= 0)
		{
			error_handle("对数必须为正数");
		}
		else
		{
			first_op = log10(second_op);
			right_output();
		}
		break;
	case 17:
		if (second_op < 0)
		{
			error_handle("函数输入无效");
		}
		else
		{
			first_op = fun((int) (second_op));
			right_output();
		}
		break;
	case 18:
		if (second_op == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			first_op = 1 / second_op;
			right_output();
		}
		break;
	case 19:
		first_op = ~((int) second_op);
		right_output();
		break;
	case 20:
		first_op = floor(second_op);
		right_output();
		break;
	default:
		break;
	}
}

void callback_add(GtkWidget *widget, gpointer data) /*加法运算*/
{
	method = 0;
	binary_operator();
}

void callback_sub(GtkWidget *widget, gpointer data) /*减法运算*/
{
	method = 1;
	binary_operator();
}

void callback_mul(GtkWidget *widget, gpointer data) /*乘法运算*/
{
	method = 2;
	binary_operator();
}

void callback_division(GtkWidget *widget, gpointer data) /*除法运算*/
{
	method = 3;
	binary_operator();
}

void callback_pow_x_y(GtkWidget *widget, gpointer data) /*幂运算*/
{
	method = 4;
	binary_operator();
}

void callback_and(GtkWidget *widget, gpointer data) /*逻辑与*/
{
	method = 5;
	binary_operator();
}

void callback_or(GtkWidget *widget, gpointer data) /*逻辑或*/
{
	method = 6;
	binary_operator();
}

void callback_xor(GtkWidget *widget, gpointer data) /*逻辑异或*/
{
	method = 7;
	binary_operator();
}

void callback_mod(GtkWidget *widget, gpointer data) /*模运算(取余)*/
{
	method = 8;
	binary_operator();
}

void callback_sin(GtkWidget *widget, gpointer data) /*求正弦（按弧度值）*/
{
	method = 9;
	output();
}

void callback_cos(GtkWidget *widget, gpointer data) /*求余弦（按弧度值）*/
{
	method = 10;
	output();
}

void callback_tan(GtkWidget *widget, gpointer data) /*求正切（按弧度值）*/
{
	method = 11;
	output();
}

void callback_exp(GtkWidget *widget, gpointer data) /*指数运算*/
{
	method = 12;
	output();
}

void callback_cube(GtkWidget *widget, gpointer data) /*立方*/
{
	method = 13;
	output();
}

void callback_square(GtkWidget *widget, gpointer data) /*平方*/
{
	method = 14;
	output();
}

void callback_log_e(GtkWidget *widget, gpointer data) /*底数为e求对数*/
{
	method = 15;
	output();
}

void callback_log_10(GtkWidget *widget, gpointer data) /*底数为10求对数*/
{
	method = 16;
	output();
}

void callback_factorial(GtkWidget *widget, gpointer data) /*阶乘*/
{
	method = 17;
	output();
}

void callback_inverse(GtkWidget *widget, gpointer data) /*求倒数*/
{
	method = 18;
	output();
}

void callback_not(GtkWidget *widget, gpointer data) /*逻辑非*/
{
	method = 19;
	output();
}

void callback_floor(GtkWidget *widget, gpointer data) /*取整*/
{
	method = 20;
	output();
}

void callback_dot(GtkWidget *widget, gpointer data)
{
	if (has_dot == 0) /* 没有小数点则添加一个小数点。*/
	{
		const gchar *entry_text = gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry)));
		gint pos = strlen(entry_text);
		gtk_editable_insert_text(GTK_EDITABLE(entry),
				gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
		has_dot = 1;/*  表示有一个小数点。*/
	}
}

void callback_sign(GtkWidget *widget, gpointer data)
{
	char num[20];
	float c;
	strcpy(num, gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry))));/*取得文本框的内容。*/
	c = atof(num); /*转换成浮点型*/
	c = -c;
	if (gcvt(c, 32, num) == NULL) /*结果转换成字符串*/
	{
		perror("error:Sign");
	}
	gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), num, strlen(num)); /*显示结果*/
}

void callback_clear(GtkWidget *widget, gpointer data)
{
	gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), "", 0);
	has_dot = 0;
	first_op = 0;
	second_op = 0;
	method = 0;
}

void callback_input(GtkWidget *widget, gpointer data)
{

	const gchar *entry_text = gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry)));
	gint pos = strlen(entry_text);
	gtk_editable_insert_text(GTK_EDITABLE(entry),
			gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
}

void callback_input_pi(GtkWidget *widget, gpointer data)
{
	gchar* text = "3.1415926535897932384626433832795";
	gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), text, strlen(text));
}