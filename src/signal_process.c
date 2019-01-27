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

void on_clicked(GtkWidget *widget, gpointer data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
	{
		if (strncmp((char *) data, "Hex", 3) == 0)
		{
			show_Hex_window();
			principle = 16;
		}
		else if (strncmp((char *) data, "Dec", 3) == 0)
		{
			show_Dec_window();
			principle = 10;
		}
		else if (strncmp((char *) data, "Oct", 3) == 0)
		{
			show_Oct_window();
			principle = 8;
		}
		else if (strncmp((char *) data, "Bin", 3) == 0)
		{
			show_Bin_window();
			principle = 2;
		}
		else
		{
			perror("error:on_clicked");
			exit(1);
		}
	}
}

void Binary_Operator() /*双目运算*/
{
	char num[20];
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));/*取得文本框的内容*/
	if (a == 0) /*如果没有第一个数，则存储为第一个数*/
	{
		Conversion(num, principle, 10); //全部转为十进制
		a = p;
		gtk_entry_set_text(GTK_ENTRY(entry), ""); /*清空文本框*/
	}
	else /*如果已有第一个数，则应存储为第二个数*/
	{
		Conversion(num, principle, 10); //全部转为十进制
		b = p;
	}
	hasdot = 0; /*表示已经没有小数点*/
}

void Right_output() /*单目运算结果输出*/
{
	char num[20];
	if (gcvt(a, 32, num) == NULL) /*运算结果转换成字符串*/
	{
		perror("error:Right_output");
	}
	Conversion(num, 10, principle); /*将运算结果（十进制字符串）转换成指定进制数*/
	gtk_entry_set_text(GTK_ENTRY(entry), out); /*显示结果*/
	a = 0;
	b = 0;
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
	a = 0;
	b = 0;
	method = 0;
	gtk_entry_set_text(GTK_ENTRY(entry),
			g_convert(info, -1, "UTF-8", "GB2312", NULL, NULL, NULL)); /*显示出错信息*/
}

void output() /*双目运算结果输出*/
{
	char num[20];
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry))); /* 取得文本框输入的内容*/
	Conversion(num, principle, 10); /*将输入的进制数转换为十进制*/
	b = p;
	switch (method)
	{
	case 0:
		a = a + b;
		Right_output();
		break;
	case 1:
		a = a - b;
		Right_output();
		break;
	case 2:
		a = a * b;
		Right_output();
		break;
	case 3:
		if (b == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			a = a / b;
			Right_output();
		}
		break;
	case 4:
		a = pow(a, b);
		Right_output();
		break;
	case 5:
		a = ((int) a) & ((int) b);
		Right_output();
		break;
	case 6:
		a = ((int) a) | ((int) b);
		Right_output();
		break;
	case 7:
		a = ((int) a) ^ ((int) b);
		Right_output();
		break;
	case 8:
		if (b == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			a = ((int) a) % ((int) b);
			Right_output();
		}
		break;
	case 9:
		a = sin(b);
		Right_output();
		break;
	case 10:
		a = cos(b);
		Right_output();
		break;
	case 11:
		a = tan(b);
		Right_output();
		break;
	case 12:
		a = exp(b);
		Right_output();
		break;
	case 13:
		a = b * b * b;
		Right_output();
		break;
	case 14:
		a = b * b;
		Right_output();
		break;
	case 15:
		if (b <= 0)
		{
			error_handle("对数必须为正数");
		}
		else
		{
			a = log(b);
			Right_output();
		}
		break;
	case 16:
		if (b <= 0)
		{
			error_handle("对数必须为正数");
		}
		else
		{
			a = log10(b);
			Right_output();
		}
		break;
	case 17:
		if (b < 0)
		{
			error_handle("函数输入无效");
		}
		else
		{
			a = fun((int) (b));
			Right_output();
		}
		break;
	case 18:
		if (b == 0)
		{
			error_handle("除数不能为零");
		}
		else
		{
			a = 1 / b;
			Right_output();
		}
		break;
	case 19:
		a = ~((int) b);
		Right_output();
		break;
	case 20:
		a = floor(b);
		Right_output();
		break;
	default:
		break;
	}
}

void Add(GtkWidget *widget, gpointer data) /*加法运算*/
{
	method = 0;
	Binary_Operator();
}

void Sub(GtkWidget *widget, gpointer data) /*减法运算*/
{
	method = 1;
	Binary_Operator();
}

void Mul(GtkWidget *widget, gpointer data) /*乘法运算*/
{
	method = 2;
	Binary_Operator();
}

void Division(GtkWidget *widget, gpointer data) /*除法运算*/
{
	method = 3;
	Binary_Operator();
}

void Mathpowxy(GtkWidget *widget, gpointer data) /*幂运算*/
{
	method = 4;
	Binary_Operator();
}

void And(GtkWidget *widget, gpointer data) /*逻辑与*/
{
	method = 5;
	Binary_Operator();
}

void Or(GtkWidget *widget, gpointer data) /*逻辑或*/
{
	method = 6;
	Binary_Operator();
}

void Xor(GtkWidget *widget, gpointer data) /*逻辑异或*/
{
	method = 7;
	Binary_Operator();
}

void Mod(GtkWidget *widget, gpointer data) /*模运算(取余)*/
{
	method = 8;
	Binary_Operator();
}

void Sin(GtkWidget *widget, gpointer data) /*求正弦（按弧度值）*/
{
	method = 9;
	output();
}

void Cos(GtkWidget *widget, gpointer data) /*求余弦（按弧度值）*/
{
	method = 10;
	output();
}

void Tan(GtkWidget *widget, gpointer data) /*求正切（按弧度值）*/
{
	method = 11;
	output();
}

void Exp(GtkWidget *widget, gpointer data) /*指数运算*/
{
	method = 12;
	output();
}

void Cube(GtkWidget *widget, gpointer data) /*立方*/
{
	method = 13;
	output();
}

void Square(GtkWidget *widget, gpointer data) /*平方*/
{
	method = 14;
	output();
}

void Log_e(GtkWidget *widget, gpointer data) /*底数为e求对数*/
{
	method = 15;
	output();
}

void Log_10(GtkWidget *widget, gpointer data) /*底数为10求对数*/
{
	method = 16;
	output();
}

void Factorial(GtkWidget *widget, gpointer data) /*阶乘*/
{
	method = 17;
	output();
}

void Inverse(GtkWidget *widget, gpointer data) /*求倒数*/
{
	method = 18;
	output();
}

void Not(GtkWidget *widget, gpointer data) /*逻辑非*/
{
	method = 19;
	output();
}

void Floor(GtkWidget *widget, gpointer data) /*取整*/
{
	method = 20;
	output();
}

void dot(GtkWidget *widget, gpointer data)
{
	if (hasdot == 0) /* 没有小数点则添加一个小数点。*/
	{
		const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
		gint pos = strlen(entry_text);
		gtk_editable_insert_text(GTK_EDITABLE(entry),
				gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
		hasdot = 1;/*  表示有一个小数点。*/
	}
}

void Sign(GtkWidget *widget, gpointer data)
{
	char num[20];
	float c;
	strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry)));/*取得文本框的内容。*/
	c = atof(num); /*转换成浮点型*/
	c = -c;
	if (gcvt(c, 32, num) == NULL) /*结果转换成字符串*/
	{
		perror("error:Sign");
	}
	gtk_entry_set_text(GTK_ENTRY(entry), num); /*显示结果*/
}

void clear(GtkWidget *widget, gpointer data)
{
	gtk_entry_set_text(GTK_ENTRY(entry), "");
	hasdot = 0;
	a = 0;
	b = 0;
	method = 0;
}

void input(GtkWidget *widget, gpointer data)
{

	const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
	gint pos = strlen(entry_text);
	gtk_editable_insert_text(GTK_EDITABLE(entry),
			gtk_button_get_label(GTK_BUTTON(widget)), -1, &pos);
}

void input_pi(GtkWidget *widget, gpointer data)
{
	gtk_entry_set_text(GTK_ENTRY(entry), "3.1415926535897932384626433832795");
}

void addsignal()
{
	/* 下面的17个按钮实现数字的输入*/
	g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(input_pi), NULL);
	g_signal_connect(G_OBJECT(button14), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button15), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button16), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button17), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button18), "clicked", G_CALLBACK(input), NULL); /*A*/
	g_signal_connect(G_OBJECT(button19), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button20), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button21), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button23), "clicked", G_CALLBACK(input), NULL); /*B*/
	g_signal_connect(G_OBJECT(button24), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button25), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button26), "clicked", G_CALLBACK(input), NULL);
	g_signal_connect(G_OBJECT(button28), "clicked", G_CALLBACK(input), NULL); /*C*/
	g_signal_connect(G_OBJECT(button33), "clicked", G_CALLBACK(input), NULL); /*D*/
	g_signal_connect(G_OBJECT(button38), "clicked", G_CALLBACK(input), NULL); /*E*/
	g_signal_connect(G_OBJECT(button42), "clicked", G_CALLBACK(input), NULL); /*F*/

	/*下面的按钮实现小数点的输入*/
	g_signal_connect(G_OBJECT(button27), "clicked", G_CALLBACK(dot), NULL);

	/*下面的按钮实现正负号的输入*/
	g_signal_connect(G_OBJECT(button22), "clicked", G_CALLBACK(Sign), NULL);

	/*下面的按钮实现各种运算的输入*/
	g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(Sin), NULL);
	g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(Cos), NULL);
	g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(Tan), NULL);
	g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(Exp), NULL);
	g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(Mathpowxy), NULL);
	g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(Cube), NULL);
	g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(Square), NULL);
	g_signal_connect(G_OBJECT(button10), "clicked", G_CALLBACK(Log_e), NULL);
	g_signal_connect(G_OBJECT(button11), "clicked", G_CALLBACK(Log_10), NULL);
	g_signal_connect(G_OBJECT(button12), "clicked", G_CALLBACK(Factorial),
			NULL);
	g_signal_connect(G_OBJECT(button13), "clicked", G_CALLBACK(Inverse), NULL);
	g_signal_connect(G_OBJECT(button32), "clicked", G_CALLBACK(Add), NULL);
	g_signal_connect(G_OBJECT(button31), "clicked", G_CALLBACK(Sub), NULL);
	g_signal_connect(G_OBJECT(button30), "clicked", G_CALLBACK(Mul), NULL);
	g_signal_connect(G_OBJECT(button29), "clicked", G_CALLBACK(Division), NULL);
	g_signal_connect(G_OBJECT(button35), "clicked", G_CALLBACK(And), NULL);
	g_signal_connect(G_OBJECT(button36), "clicked", G_CALLBACK(Or), NULL);
	g_signal_connect(G_OBJECT(button37), "clicked", G_CALLBACK(Mod), NULL);
	g_signal_connect(G_OBJECT(button39), "clicked", G_CALLBACK(Not), NULL);
	g_signal_connect(G_OBJECT(button40), "clicked", G_CALLBACK(Xor), NULL);
	g_signal_connect(G_OBJECT(button41), "clicked", G_CALLBACK(Floor), NULL);

	/* 下面的按钮实现复位功能*/
	g_signal_connect(G_OBJECT(button34), "clicked", G_CALLBACK(clear), NULL);

	/* 下面的按钮实现结果输出*/
	g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(output), NULL);
	g_signal_connect(G_OBJECT(window), "delete_event",
			G_CALLBACK(gtk_main_quit), NULL);
}
