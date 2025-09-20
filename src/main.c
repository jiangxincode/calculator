#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

#include "../include/calculator.h"

#define PACKAGE "calculator"
#define LOCALEDIR "locale"

#define _(string) gettext(string)
#define N_(string) string

double first_op, second_op; /*定义两个参与运算的变量，双精度型*/
double value_in_dec;
int has_dot; /*是否有小数点*/
int method; /*用于区别不同的运算*/
int radix; /*标识不同的进制*/
char out_array[20]; /*输出结果*/

GtkWidget *grid0; /*垂直框*/
GtkWidget *grid1; /*表格1*/
GtkWidget *grid2; /*表格2*/
GtkWidget *entry; /*文本框*/
GtkWidget *btn_pi; /*π按钮*/
GtkWidget *btn_sin; /*sin按钮*/
GtkWidget *btn_cos; /*cos按钮*/
GtkWidget *btn_tan; /*tan按钮*/
GtkWidget *btn_equals; /*=按钮*/
GtkWidget *btn_exp; /*exp按钮*/
GtkWidget *btn_pow_xy; /*x^y按钮*/
GtkWidget *btn_pow_3; /*x^3按钮*/
GtkWidget *btn_pow_2; /*x^2按钮*/
GtkWidget *btn_ln; /*ln按钮*/
GtkWidget *btn_log; /*log按钮*/
GtkWidget *btn_factorial; /*n!按钮*/
GtkWidget *btn_inverse; /*1/x按钮*/
GtkWidget *btn_7; /*数字7*/
GtkWidget *btn_4; /*数字4*/
GtkWidget *btn_1; /*数字1*/
GtkWidget *btn_0; /*数字0*/
GtkWidget *btn_a; /*十六进制A*/
GtkWidget *btn_8; /*数字8*/
GtkWidget *btn_5; /*数字5*/
GtkWidget *btn_2; /*数字2*/
GtkWidget *btn_sign; /*+/-按钮*/
GtkWidget *btn_b; /*十六进制B*/
GtkWidget *btn_9; /*数字9*/
GtkWidget *btn_6; /*数字6*/
GtkWidget *btn_3; /*数字3*/
GtkWidget *btn_dot; /*小数点.*/
GtkWidget *btn_c; /*十六进制C*/
GtkWidget *btn_divide; /*除法/*/
GtkWidget *btn_multiply; /*乘法**/
GtkWidget *btn_subtract; /*减法-*/
GtkWidget *btn_add; /*加法+*/
GtkWidget *btn_d; /*十六进制D*/
GtkWidget *btn_clear; /*清除CR*/
GtkWidget *btn_and; /*逻辑与And*/
GtkWidget *btn_or; /*逻辑或Or*/
GtkWidget *btn_mod; /*取模Mod*/
GtkWidget *btn_e; /*十六进制E*/
GtkWidget *btn_not; /*逻辑非Not*/
GtkWidget *btn_xor; /*异或Xor*/
GtkWidget *btn_int; /*取整Int*/
GtkWidget *btn_f; /*十六进制F*/

static void activate (GtkApplication *app, gpointer user_data);

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("edu.jiangxin.calculator", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

static void activate (GtkApplication *app, gpointer user_data)
{
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	first_op = 0;
	second_op = 0;
	has_dot = 0;
	gtk_init();
	method = 0; /*运算方法。*/

	GtkWidget *window = gtk_application_window_new(app);
	// The title will be centered with respect to the width of the box
	gtk_window_set_title(GTK_WINDOW(window), _("Calculator"));
	//gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("./res/icon.png"));

	grid0 = gtk_grid_new();
	gtk_window_set_child (GTK_WINDOW (window), grid0);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid0), true);
	gtk_grid_set_column_spacing(GTK_GRID(grid0), 1);
	gtk_grid_set_row_spacing(GTK_GRID(grid0), 1);

	grid1 = gtk_grid_new();
	grid2 = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(grid0), grid1, 0, 0, 9, 2);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid1), true);
	gtk_grid_set_column_spacing(GTK_GRID(grid1), 1);
	gtk_grid_set_row_spacing(GTK_GRID(grid1), 1);
	gtk_grid_attach(GTK_GRID(grid0), grid2, 0, 2, 9, 5);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid2), true);
	gtk_grid_set_column_spacing(GTK_GRID(grid2), 1);
	gtk_grid_set_row_spacing(GTK_GRID(grid2), 1);

	entry = gtk_entry_new(); /*用于输入和输出的文本框*/
	gtk_grid_attach(GTK_GRID(grid1), entry, 0, 0, 9, 1);

	btn_pi = gtk_button_new_with_mnemonic("pi");
	gtk_grid_attach(GTK_GRID(grid2), btn_pi, 0, 0, 1, 1);
	gtk_widget_set_size_request(btn_pi, 40, 30);

	btn_sin = gtk_button_new_with_mnemonic("sin");
	gtk_grid_attach(GTK_GRID(grid2), btn_sin, 0, 1, 1, 1);

	btn_cos = gtk_button_new_with_mnemonic("cos");
	gtk_grid_attach(GTK_GRID(grid2), btn_cos, 0, 2, 1, 1);

	btn_tan = gtk_button_new_with_mnemonic("tan");
	gtk_grid_attach(GTK_GRID(grid2), btn_tan, 0, 3, 1, 1);

	btn_equals = gtk_button_new_with_mnemonic("=");
	gtk_grid_attach(GTK_GRID(grid2), btn_equals, 0, 4, 3, 1);

	btn_exp = gtk_button_new_with_mnemonic("exp");
	gtk_grid_attach(GTK_GRID(grid2), btn_exp, 1, 0, 1, 1);
	gtk_widget_set_size_request(btn_exp, 40, 30);

	btn_pow_xy = gtk_button_new_with_mnemonic("x^y");
	gtk_grid_attach(GTK_GRID(grid2), btn_pow_xy, 1, 1, 1, 1);

	btn_pow_3 = gtk_button_new_with_mnemonic("x^3");
	gtk_grid_attach(GTK_GRID(grid2), btn_pow_3, 1, 2, 1, 1);

	btn_pow_2 = gtk_button_new_with_mnemonic("x^2");
	gtk_grid_attach(GTK_GRID(grid2), btn_pow_2, 1, 3, 1, 1);

	btn_ln = gtk_button_new_with_mnemonic("ln");
	gtk_grid_attach(GTK_GRID(grid2), btn_ln, 2, 0, 1, 1);
	gtk_widget_set_size_request(btn_ln, 40, 30);

	btn_log = gtk_button_new_with_mnemonic("log");
	gtk_grid_attach(GTK_GRID(grid2), btn_log, 2, 1, 1, 1);

	btn_factorial = gtk_button_new_with_mnemonic("n!");
	gtk_grid_attach(GTK_GRID(grid2), btn_factorial, 2, 2, 1, 1);

	btn_inverse = gtk_button_new_with_mnemonic("1/x ");
	gtk_grid_attach(GTK_GRID(grid2), btn_inverse, 2, 3, 1, 1);

	btn_7 = gtk_button_new_with_label("7");
	gtk_grid_attach(GTK_GRID(grid2), btn_7, 3, 0, 1, 1);
	gtk_widget_set_size_request(btn_7, 40, 30);

	btn_4 = gtk_button_new_with_mnemonic("4");
	gtk_grid_attach(GTK_GRID(grid2), btn_4, 3, 1, 1, 1);

	btn_1 = gtk_button_new_with_mnemonic("1");
	gtk_grid_attach(GTK_GRID(grid2), btn_1, 3, 2, 1, 1);

	btn_0 = gtk_button_new_with_mnemonic("0");
	gtk_grid_attach(GTK_GRID(grid2), btn_0, 3, 3, 1, 1);

	btn_a = gtk_button_new_with_mnemonic("A");
	gtk_grid_attach(GTK_GRID(grid2), btn_a, 3, 4, 1, 1);

	btn_8 = gtk_button_new_with_mnemonic("8");
	gtk_grid_attach(GTK_GRID(grid2), btn_8, 4, 0, 1, 1);
	gtk_widget_set_size_request(btn_8, 40, 30);

	btn_5 = gtk_button_new_with_mnemonic("5");
	gtk_grid_attach(GTK_GRID(grid2), btn_5, 4, 1, 1, 1);

	btn_2 = gtk_button_new_with_mnemonic("2");
	gtk_grid_attach(GTK_GRID(grid2), btn_2, 4, 2, 1, 1);

	btn_sign = gtk_button_new_with_mnemonic("+/-");
	gtk_grid_attach(GTK_GRID(grid2), btn_sign, 4, 3, 1, 1);

	btn_b = gtk_button_new_with_mnemonic("B");
	gtk_grid_attach(GTK_GRID(grid2), btn_b, 4, 4, 1, 1);

	btn_9 = gtk_button_new_with_mnemonic("9");
	gtk_grid_attach(GTK_GRID(grid2), btn_9, 5, 0, 1, 1);
	gtk_widget_set_size_request(btn_9, 40, 30);

	btn_6 = gtk_button_new_with_mnemonic("6");
	gtk_grid_attach(GTK_GRID(grid2), btn_6, 5, 1, 1, 1);

	btn_3 = gtk_button_new_with_mnemonic("3");
	gtk_grid_attach(GTK_GRID(grid2), btn_3, 5, 2, 1, 1);

	btn_dot = gtk_button_new_with_mnemonic(".");
	gtk_grid_attach(GTK_GRID(grid2), btn_dot, 5, 3, 1, 1);

	btn_c = gtk_button_new_with_mnemonic("C");
	gtk_grid_attach(GTK_GRID(grid2), btn_c, 5, 4, 1, 1);

	btn_divide = gtk_button_new_with_mnemonic("/");
	gtk_grid_attach(GTK_GRID(grid2), btn_divide, 6, 0, 1, 1);
	gtk_widget_set_size_request(btn_divide, 40, 30);

	btn_multiply = gtk_button_new_with_mnemonic("*");
	gtk_grid_attach(GTK_GRID(grid2), btn_multiply, 6, 1, 1, 1);

	btn_subtract = gtk_button_new_with_mnemonic("-");
	gtk_grid_attach(GTK_GRID(grid2), btn_subtract, 6, 2, 1, 1);

	btn_add = gtk_button_new_with_mnemonic("+");
	gtk_grid_attach(GTK_GRID(grid2), btn_add, 6, 3, 1, 1);

	btn_d = gtk_button_new_with_mnemonic("D");
	gtk_grid_attach(GTK_GRID(grid2), btn_d, 6, 4, 1, 1);

	btn_clear = gtk_button_new_with_mnemonic("CR");
	gtk_grid_attach(GTK_GRID(grid2), btn_clear, 7, 0, 2, 1);
	gtk_widget_set_size_request(btn_clear, 80, 30);

	btn_and = gtk_button_new_with_mnemonic("And");
	gtk_grid_attach(GTK_GRID(grid2), btn_and, 7, 1, 1, 1);

	btn_or = gtk_button_new_with_mnemonic("Or");
	gtk_grid_attach(GTK_GRID(grid2), btn_or, 7, 2, 1, 1);

	btn_mod = gtk_button_new_with_mnemonic("Mod");
	gtk_grid_attach(GTK_GRID(grid2), btn_mod, 7, 3, 1, 1);

	btn_e = gtk_button_new_with_mnemonic("E");
	gtk_grid_attach(GTK_GRID(grid2), btn_e, 7, 4, 1, 1);

	btn_not = gtk_button_new_with_mnemonic("Not");
	gtk_grid_attach(GTK_GRID(grid2), btn_not, 8, 1, 1, 1);

	btn_xor = gtk_button_new_with_mnemonic("Xor");
	gtk_grid_attach(GTK_GRID(grid2), btn_xor, 8, 2, 1, 1);

	btn_int = gtk_button_new_with_mnemonic("Int");
	gtk_grid_attach(GTK_GRID(grid2), btn_int, 8, 3, 1, 1);

	btn_f = gtk_button_new_with_mnemonic("F");
	gtk_grid_attach(GTK_GRID(grid2), btn_f, 8, 4, 1, 1);

	/*下面是创建四个单选按钮，并将"十进制"按钮设置为默认选中*/
	GtkWidget *radio1 = gtk_toggle_button_new_with_label("Hex");
	g_signal_connect(GTK_WIDGET(radio1), "clicked", G_CALLBACK(callback_radix_convert), "Hex");
	gtk_grid_attach(GTK_GRID(grid1), radio1, 0, 1, 2, 1);

	GtkWidget *radio2 = gtk_toggle_button_new_with_label("Dec");
	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio2), GTK_TOGGLE_BUTTON(radio1));
	g_signal_connect(GTK_WIDGET(radio2), "clicked", G_CALLBACK(callback_radix_convert), "Dec");
	radix = 10;
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio2), TRUE); /*十进制radio设置为默认选中状态*/
	gtk_grid_attach(GTK_GRID(grid1), radio2, 2, 1, 2, 1);

	GtkWidget *radio3 = gtk_toggle_button_new_with_label("Oct");
	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio3), GTK_TOGGLE_BUTTON(radio1));
	g_signal_connect(GTK_WIDGET(radio3), "clicked", G_CALLBACK(callback_radix_convert), "Oct");
	gtk_grid_attach(GTK_GRID(grid1), radio3, 4, 1, 2, 1);

	GtkWidget *radio4 = gtk_toggle_button_new_with_label("Bin");
	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio4), GTK_TOGGLE_BUTTON(radio1));
	g_signal_connect(GTK_WIDGET(radio4), "clicked", G_CALLBACK(callback_radix_convert), "Bin");
	gtk_grid_attach(GTK_GRID(grid1), radio4, 6, 1, 2, 1);

	add_signal(); /*添加事件。*/

	gtk_window_present (GTK_WINDOW(window));
}

void show_all()
{
	gtk_widget_set_sensitive(btn_pi, TRUE);
	gtk_widget_set_sensitive(btn_sin, TRUE);
	gtk_widget_set_sensitive(btn_cos, TRUE);
	gtk_widget_set_sensitive(btn_tan, TRUE);
	gtk_widget_set_sensitive(btn_equals, TRUE);
	gtk_widget_set_sensitive(btn_exp, TRUE);
	gtk_widget_set_sensitive(btn_pow_xy, TRUE);
	gtk_widget_set_sensitive(btn_pow_3, TRUE);
	gtk_widget_set_sensitive(btn_pow_2, TRUE);
	gtk_widget_set_sensitive(btn_ln, TRUE);
	gtk_widget_set_sensitive(btn_log, TRUE);
	gtk_widget_set_sensitive(btn_factorial, TRUE);
	gtk_widget_set_sensitive(btn_inverse, TRUE);
	gtk_widget_set_sensitive(btn_7, TRUE);
	gtk_widget_set_sensitive(btn_4, TRUE);
	gtk_widget_set_sensitive(btn_1, TRUE);
	gtk_widget_set_sensitive(btn_0, TRUE);
	gtk_widget_set_sensitive(btn_a, TRUE);
	gtk_widget_set_sensitive(btn_8, TRUE);
	gtk_widget_set_sensitive(btn_5, TRUE);
	gtk_widget_set_sensitive(btn_2, TRUE);
	gtk_widget_set_sensitive(btn_sign, TRUE);
	gtk_widget_set_sensitive(btn_b, TRUE);
	gtk_widget_set_sensitive(btn_9, TRUE);
	gtk_widget_set_sensitive(btn_6, TRUE);
	gtk_widget_set_sensitive(btn_3, TRUE);
	gtk_widget_set_sensitive(btn_dot, TRUE);
	gtk_widget_set_sensitive(btn_c, TRUE);
	gtk_widget_set_sensitive(btn_divide, TRUE);
	gtk_widget_set_sensitive(btn_multiply, TRUE);
	gtk_widget_set_sensitive(btn_subtract, TRUE);
	gtk_widget_set_sensitive(btn_add, TRUE);
	gtk_widget_set_sensitive(btn_d, TRUE);
	gtk_widget_set_sensitive(btn_clear, TRUE);
	gtk_widget_set_sensitive(btn_and, TRUE);
	gtk_widget_set_sensitive(btn_or, TRUE);
	gtk_widget_set_sensitive(btn_mod, TRUE);
	gtk_widget_set_sensitive(btn_e, TRUE);
	gtk_widget_set_sensitive(btn_not, TRUE);
	gtk_widget_set_sensitive(btn_xor, TRUE);
	gtk_widget_set_sensitive(btn_int, TRUE);
	gtk_widget_set_sensitive(btn_f, TRUE);
}
void show_bin_window()
{
	show_all();
	gtk_widget_set_sensitive(btn_pi, FALSE);
	gtk_widget_set_sensitive(btn_sin, FALSE);
	gtk_widget_set_sensitive(btn_cos, FALSE);
	gtk_widget_set_sensitive(btn_tan, FALSE);
	gtk_widget_set_sensitive(btn_7, FALSE);
	gtk_widget_set_sensitive(btn_4, FALSE);
	gtk_widget_set_sensitive(btn_a, FALSE);
	gtk_widget_set_sensitive(btn_8, FALSE);
	gtk_widget_set_sensitive(btn_5, FALSE);
	gtk_widget_set_sensitive(btn_2, FALSE);
	gtk_widget_set_sensitive(btn_b, FALSE);
	gtk_widget_set_sensitive(btn_9, FALSE);
	gtk_widget_set_sensitive(btn_6, FALSE);
	gtk_widget_set_sensitive(btn_3, FALSE);
	gtk_widget_set_sensitive(btn_c, FALSE);
	gtk_widget_set_sensitive(btn_d, FALSE);
	gtk_widget_set_sensitive(btn_e, FALSE);
	gtk_widget_set_sensitive(btn_f, FALSE);
}

void show_dec_window()
{
	show_all();
	gtk_widget_set_sensitive(btn_a, FALSE);
	gtk_widget_set_sensitive(btn_b, FALSE);
	gtk_widget_set_sensitive(btn_c, FALSE);
	gtk_widget_set_sensitive(btn_d, FALSE);
	gtk_widget_set_sensitive(btn_e, FALSE);
	gtk_widget_set_sensitive(btn_f, FALSE);
}

void show_hex_window()
{
	show_all();
	gtk_widget_set_sensitive(btn_pi, FALSE);
	gtk_widget_set_sensitive(btn_sin, FALSE);
	gtk_widget_set_sensitive(btn_cos, FALSE);
	gtk_widget_set_sensitive(btn_tan, FALSE);
}

void show_oct_window()
{
	show_all();
	gtk_widget_set_sensitive(btn_pi, FALSE);
	gtk_widget_set_sensitive(btn_sin, FALSE);
	gtk_widget_set_sensitive(btn_cos, FALSE);
	gtk_widget_set_sensitive(btn_tan, FALSE);
	gtk_widget_set_sensitive(btn_a, FALSE);
	gtk_widget_set_sensitive(btn_8, FALSE);
	gtk_widget_set_sensitive(btn_b, FALSE);
	gtk_widget_set_sensitive(btn_9, FALSE);
	gtk_widget_set_sensitive(btn_c, FALSE);
	gtk_widget_set_sensitive(btn_d, FALSE);
	gtk_widget_set_sensitive(btn_e, FALSE);
	gtk_widget_set_sensitive(btn_f, FALSE);
}

void add_signal()
{
	/* 下面的17个按钮实现数字的输入*/
	g_signal_connect(G_OBJECT(btn_pi), "clicked", G_CALLBACK(callback_input_pi), NULL);
	g_signal_connect(G_OBJECT(btn_7), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_4), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_1), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_0), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_a), "clicked", G_CALLBACK(callback_input), NULL); /*A*/
	g_signal_connect(G_OBJECT(btn_8), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_5), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_2), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_b), "clicked", G_CALLBACK(callback_input), NULL); /*B*/
	g_signal_connect(G_OBJECT(btn_9), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_6), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_3), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(btn_c), "clicked", G_CALLBACK(callback_input), NULL); /*C*/
	g_signal_connect(G_OBJECT(btn_d), "clicked", G_CALLBACK(callback_input), NULL); /*D*/
	g_signal_connect(G_OBJECT(btn_e), "clicked", G_CALLBACK(callback_input), NULL); /*E*/
	g_signal_connect(G_OBJECT(btn_f), "clicked", G_CALLBACK(callback_input), NULL); /*F*/

	/*下面的按钮实现小数点的输入*/
	g_signal_connect(G_OBJECT(btn_dot), "clicked", G_CALLBACK(callback_dot), NULL);

	/*下面的按钮实现正负号的输入*/
	g_signal_connect(G_OBJECT(btn_sign), "clicked", G_CALLBACK(callback_sign), NULL);

	/*下面的按钮实现各种运算的输入*/
	g_signal_connect(G_OBJECT(btn_sin), "clicked", G_CALLBACK(callback_sin), NULL);
	g_signal_connect(G_OBJECT(btn_cos), "clicked", G_CALLBACK(callback_cos), NULL);
	g_signal_connect(G_OBJECT(btn_tan), "clicked", G_CALLBACK(callback_tan), NULL);
	g_signal_connect(G_OBJECT(btn_exp), "clicked", G_CALLBACK(callback_exp), NULL);
	g_signal_connect(G_OBJECT(btn_pow_xy), "clicked", G_CALLBACK(callback_pow_x_y), NULL);
	g_signal_connect(G_OBJECT(btn_pow_3), "clicked", G_CALLBACK(callback_cube), NULL);
	g_signal_connect(G_OBJECT(btn_pow_2), "clicked", G_CALLBACK(callback_square), NULL);
	g_signal_connect(G_OBJECT(btn_ln), "clicked", G_CALLBACK(callback_log_e), NULL);
	g_signal_connect(G_OBJECT(btn_log), "clicked", G_CALLBACK(callback_log_10), NULL);
	g_signal_connect(G_OBJECT(btn_factorial), "clicked", G_CALLBACK(callback_factorial),
			NULL);
	g_signal_connect(G_OBJECT(btn_inverse), "clicked", G_CALLBACK(callback_inverse), NULL);
	g_signal_connect(G_OBJECT(btn_add), "clicked", G_CALLBACK(callback_add), NULL);
	g_signal_connect(G_OBJECT(btn_subtract), "clicked", G_CALLBACK(callback_sub), NULL);
	g_signal_connect(G_OBJECT(btn_multiply), "clicked", G_CALLBACK(callback_mul), NULL);
	g_signal_connect(G_OBJECT(btn_divide), "clicked", G_CALLBACK(callback_division), NULL);
	g_signal_connect(G_OBJECT(btn_and), "clicked", G_CALLBACK(callback_and), NULL);
	g_signal_connect(G_OBJECT(btn_or), "clicked", G_CALLBACK(callback_or), NULL);
	g_signal_connect(G_OBJECT(btn_mod), "clicked", G_CALLBACK(callback_mod), NULL);
	g_signal_connect(G_OBJECT(btn_not), "clicked", G_CALLBACK(callback_not), NULL);
	g_signal_connect(G_OBJECT(btn_xor), "clicked", G_CALLBACK(callback_xor), NULL);
	g_signal_connect(G_OBJECT(btn_int), "clicked", G_CALLBACK(callback_floor), NULL);

	/* 下面的按钮实现复位功能*/
	g_signal_connect(G_OBJECT(btn_clear), "clicked", G_CALLBACK(callback_clear), NULL);

	/* 下面的按钮实现结果输出*/
	g_signal_connect(G_OBJECT(btn_equals), "clicked", G_CALLBACK(output), NULL);
}
