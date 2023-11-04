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
GtkWidget *button1; /*42个按钮*/
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *button10;
GtkWidget *button11;
GtkWidget *button12;
GtkWidget *button13;
GtkWidget *button14;
GtkWidget *button15;
GtkWidget *button16;
GtkWidget *button17;
GtkWidget *button18;
GtkWidget *button19;
GtkWidget *button20;
GtkWidget *button21;
GtkWidget *button22;
GtkWidget *button23;
GtkWidget *button24;
GtkWidget *button25;
GtkWidget *button26;
GtkWidget *button27;
GtkWidget *button28;
GtkWidget *button29;
GtkWidget *button30;
GtkWidget *button31;
GtkWidget *button32;
GtkWidget *button33;
GtkWidget *button34;
GtkWidget *button35;
GtkWidget *button36;
GtkWidget *button37;
GtkWidget *button38;
GtkWidget *button39;
GtkWidget *button40;
GtkWidget *button41;
GtkWidget *button42;

static void activate (GtkApplication *app, gpointer user_data);

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("edu.jiangxin.calculator", G_APPLICATION_FLAGS_NONE);
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

	button1 = gtk_button_new_with_mnemonic("pi");
	gtk_grid_attach(GTK_GRID(grid2), button1, 0, 0, 1, 1);
	gtk_widget_set_size_request(button1, 40, 30);

	button2 = gtk_button_new_with_mnemonic("sin");
	gtk_grid_attach(GTK_GRID(grid2), button2, 0, 1, 1, 1);

	button3 = gtk_button_new_with_mnemonic("cos");
	gtk_grid_attach(GTK_GRID(grid2), button3, 0, 2, 1, 1);

	button4 = gtk_button_new_with_mnemonic("tan");
	gtk_grid_attach(GTK_GRID(grid2), button4, 0, 3, 1, 1);

	button5 = gtk_button_new_with_mnemonic("=");
	gtk_grid_attach(GTK_GRID(grid2), button5, 0, 4, 3, 1);

	button6 = gtk_button_new_with_mnemonic("exp");
	gtk_grid_attach(GTK_GRID(grid2), button6, 1, 0, 1, 1);
	gtk_widget_set_size_request(button6, 40, 30);

	button7 = gtk_button_new_with_mnemonic("x^y");
	gtk_grid_attach(GTK_GRID(grid2), button7, 1, 1, 1, 1);

	button8 = gtk_button_new_with_mnemonic("x^3");
	gtk_grid_attach(GTK_GRID(grid2), button8, 1, 2, 1, 1);

	button9 = gtk_button_new_with_mnemonic("x^2");
	gtk_grid_attach(GTK_GRID(grid2), button9, 1, 3, 1, 1);

	button10 = gtk_button_new_with_mnemonic("ln");
	gtk_grid_attach(GTK_GRID(grid2), button10, 2, 0, 1, 1);
	gtk_widget_set_size_request(button10, 40, 30);

	button11 = gtk_button_new_with_mnemonic("log");
	gtk_grid_attach(GTK_GRID(grid2), button11, 2, 1, 1, 1);

	button12 = gtk_button_new_with_mnemonic("n!");
	gtk_grid_attach(GTK_GRID(grid2), button12, 2, 2, 1, 1);

	button13 = gtk_button_new_with_mnemonic("1/x ");
	gtk_grid_attach(GTK_GRID(grid2), button13, 2, 3, 1, 1);

	button14 = gtk_button_new_with_label("7");
	gtk_grid_attach(GTK_GRID(grid2), button14, 3, 0, 1, 1);
	gtk_widget_set_size_request(button14, 40, 30);

	button15 = gtk_button_new_with_mnemonic("4");
	gtk_grid_attach(GTK_GRID(grid2), button15, 3, 1, 1, 1);

	button16 = gtk_button_new_with_mnemonic("1");
	gtk_grid_attach(GTK_GRID(grid2), button16, 3, 2, 1, 1);

	button17 = gtk_button_new_with_mnemonic("0");
	gtk_grid_attach(GTK_GRID(grid2), button17, 3, 3, 1, 1);

	button18 = gtk_button_new_with_mnemonic("A");
	gtk_grid_attach(GTK_GRID(grid2), button18, 3, 4, 1, 1);

	button19 = gtk_button_new_with_mnemonic("8");
	gtk_grid_attach(GTK_GRID(grid2), button19, 4, 0, 1, 1);
	gtk_widget_set_size_request(button19, 40, 30);

	button20 = gtk_button_new_with_mnemonic("5");
	gtk_grid_attach(GTK_GRID(grid2), button20, 4, 1, 1, 1);

	button21 = gtk_button_new_with_mnemonic("2");
	gtk_grid_attach(GTK_GRID(grid2), button21, 4, 2, 1, 1);

	button22 = gtk_button_new_with_mnemonic("+/-");
	gtk_grid_attach(GTK_GRID(grid2), button22, 4, 3, 1, 1);

	button23 = gtk_button_new_with_mnemonic("B");
	gtk_grid_attach(GTK_GRID(grid2), button23, 4, 4, 1, 1);

	button24 = gtk_button_new_with_mnemonic("9");
	gtk_grid_attach(GTK_GRID(grid2), button24, 5, 0, 1, 1);
	gtk_widget_set_size_request(button24, 40, 30);

	button25 = gtk_button_new_with_mnemonic("6");
	gtk_grid_attach(GTK_GRID(grid2), button25, 5, 1, 1, 1);

	button26 = gtk_button_new_with_mnemonic("3");
	gtk_grid_attach(GTK_GRID(grid2), button26, 5, 2, 1, 1);

	button27 = gtk_button_new_with_mnemonic(".");
	gtk_grid_attach(GTK_GRID(grid2), button27, 5, 3, 1, 1);

	button28 = gtk_button_new_with_mnemonic("C");
	gtk_grid_attach(GTK_GRID(grid2), button28, 5, 4, 1, 1);

	button29 = gtk_button_new_with_mnemonic("/");
	gtk_grid_attach(GTK_GRID(grid2), button29, 6, 0, 1, 1);
	gtk_widget_set_size_request(button29, 40, 30);

	button30 = gtk_button_new_with_mnemonic("*");
	gtk_grid_attach(GTK_GRID(grid2), button30, 6, 1, 1, 1);

	button31 = gtk_button_new_with_mnemonic("-");
	gtk_grid_attach(GTK_GRID(grid2), button31, 6, 2, 1, 1);

	button32 = gtk_button_new_with_mnemonic("+");
	gtk_grid_attach(GTK_GRID(grid2), button32, 6, 3, 1, 1);

	button33 = gtk_button_new_with_mnemonic("D");
	gtk_grid_attach(GTK_GRID(grid2), button33, 6, 4, 1, 1);

	button34 = gtk_button_new_with_mnemonic("CR");
	gtk_grid_attach(GTK_GRID(grid2), button34, 7, 0, 2, 1);
	gtk_widget_set_size_request(button34, 80, 30);

	button35 = gtk_button_new_with_mnemonic("And");
	gtk_grid_attach(GTK_GRID(grid2), button35, 7, 1, 1, 1);

	button36 = gtk_button_new_with_mnemonic("Or");
	gtk_grid_attach(GTK_GRID(grid2), button36, 7, 2, 1, 1);

	button37 = gtk_button_new_with_mnemonic("Mod");
	gtk_grid_attach(GTK_GRID(grid2), button37, 7, 3, 1, 1);

	button38 = gtk_button_new_with_mnemonic("E");
	gtk_grid_attach(GTK_GRID(grid2), button38, 7, 4, 1, 1);

	button39 = gtk_button_new_with_mnemonic("Not");
	gtk_grid_attach(GTK_GRID(grid2), button39, 8, 1, 1, 1);

	button40 = gtk_button_new_with_mnemonic("Xor");
	gtk_grid_attach(GTK_GRID(grid2), button40, 8, 2, 1, 1);

	button41 = gtk_button_new_with_mnemonic("Int");
	gtk_grid_attach(GTK_GRID(grid2), button41, 8, 3, 1, 1);

	button42 = gtk_button_new_with_mnemonic("F");
	gtk_grid_attach(GTK_GRID(grid2), button42, 8, 4, 1, 1);

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

	gtk_widget_show (window);
}

void show_all()
{
	gtk_widget_set_sensitive(button1, TRUE);
	gtk_widget_set_sensitive(button2, TRUE);
	gtk_widget_set_sensitive(button3, TRUE);
	gtk_widget_set_sensitive(button4, TRUE);
	gtk_widget_set_sensitive(button5, TRUE);
	gtk_widget_set_sensitive(button6, TRUE);
	gtk_widget_set_sensitive(button7, TRUE);
	gtk_widget_set_sensitive(button8, TRUE);
	gtk_widget_set_sensitive(button9, TRUE);
	gtk_widget_set_sensitive(button10, TRUE);
	gtk_widget_set_sensitive(button11, TRUE);
	gtk_widget_set_sensitive(button12, TRUE);
	gtk_widget_set_sensitive(button13, TRUE);
	gtk_widget_set_sensitive(button14, TRUE);
	gtk_widget_set_sensitive(button15, TRUE);
	gtk_widget_set_sensitive(button16, TRUE);
	gtk_widget_set_sensitive(button17, TRUE);
	gtk_widget_set_sensitive(button18, TRUE);
	gtk_widget_set_sensitive(button19, TRUE);
	gtk_widget_set_sensitive(button20, TRUE);
	gtk_widget_set_sensitive(button21, TRUE);
	gtk_widget_set_sensitive(button22, TRUE);
	gtk_widget_set_sensitive(button23, TRUE);
	gtk_widget_set_sensitive(button24, TRUE);
	gtk_widget_set_sensitive(button25, TRUE);
	gtk_widget_set_sensitive(button26, TRUE);
	gtk_widget_set_sensitive(button27, TRUE);
	gtk_widget_set_sensitive(button28, TRUE);
	gtk_widget_set_sensitive(button29, TRUE);
	gtk_widget_set_sensitive(button30, TRUE);
	gtk_widget_set_sensitive(button31, TRUE);
	gtk_widget_set_sensitive(button32, TRUE);
	gtk_widget_set_sensitive(button33, TRUE);
	gtk_widget_set_sensitive(button34, TRUE);
	gtk_widget_set_sensitive(button35, TRUE);
	gtk_widget_set_sensitive(button36, TRUE);
	gtk_widget_set_sensitive(button37, TRUE);
	gtk_widget_set_sensitive(button38, TRUE);
	gtk_widget_set_sensitive(button39, TRUE);
	gtk_widget_set_sensitive(button40, TRUE);
	gtk_widget_set_sensitive(button41, TRUE);
	gtk_widget_set_sensitive(button42, TRUE);
}
void show_bin_window()
{
	show_all();
	gtk_widget_set_sensitive(button1, FALSE);
	gtk_widget_set_sensitive(button2, FALSE);
	gtk_widget_set_sensitive(button3, FALSE);
	gtk_widget_set_sensitive(button4, FALSE);
	gtk_widget_set_sensitive(button14, FALSE);
	gtk_widget_set_sensitive(button15, FALSE);
	gtk_widget_set_sensitive(button18, FALSE);
	gtk_widget_set_sensitive(button19, FALSE);
	gtk_widget_set_sensitive(button20, FALSE);
	gtk_widget_set_sensitive(button21, FALSE);
	gtk_widget_set_sensitive(button23, FALSE);
	gtk_widget_set_sensitive(button24, FALSE);
	gtk_widget_set_sensitive(button25, FALSE);
	gtk_widget_set_sensitive(button26, FALSE);
	gtk_widget_set_sensitive(button28, FALSE);
	gtk_widget_set_sensitive(button33, FALSE);
	gtk_widget_set_sensitive(button38, FALSE);
	gtk_widget_set_sensitive(button42, FALSE);
}

void show_dec_window()
{
	show_all();
	gtk_widget_set_sensitive(button18, FALSE);
	gtk_widget_set_sensitive(button23, FALSE);
	gtk_widget_set_sensitive(button28, FALSE);
	gtk_widget_set_sensitive(button33, FALSE);
	gtk_widget_set_sensitive(button38, FALSE);
	gtk_widget_set_sensitive(button42, FALSE);
}

void show_hex_window()
{
	show_all();
	gtk_widget_set_sensitive(button1, FALSE);
	gtk_widget_set_sensitive(button2, FALSE);
	gtk_widget_set_sensitive(button3, FALSE);
	gtk_widget_set_sensitive(button4, FALSE);
}

void show_oct_window()
{
	show_all();
	gtk_widget_set_sensitive(button1, FALSE);
	gtk_widget_set_sensitive(button2, FALSE);
	gtk_widget_set_sensitive(button3, FALSE);
	gtk_widget_set_sensitive(button4, FALSE);
	gtk_widget_set_sensitive(button18, FALSE);
	gtk_widget_set_sensitive(button19, FALSE);
	gtk_widget_set_sensitive(button23, FALSE);
	gtk_widget_set_sensitive(button24, FALSE);
	gtk_widget_set_sensitive(button28, FALSE);
	gtk_widget_set_sensitive(button33, FALSE);
	gtk_widget_set_sensitive(button38, FALSE);
	gtk_widget_set_sensitive(button42, FALSE);
}

void add_signal()
{
	/* 下面的17个按钮实现数字的输入*/
	g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(callback_input_pi), NULL);
	g_signal_connect(G_OBJECT(button14), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button15), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button16), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button17), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button18), "clicked", G_CALLBACK(callback_input), NULL); /*A*/
	g_signal_connect(G_OBJECT(button19), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button20), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button21), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button23), "clicked", G_CALLBACK(callback_input), NULL); /*B*/
	g_signal_connect(G_OBJECT(button24), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button25), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button26), "clicked", G_CALLBACK(callback_input), NULL);
	g_signal_connect(G_OBJECT(button28), "clicked", G_CALLBACK(callback_input), NULL); /*C*/
	g_signal_connect(G_OBJECT(button33), "clicked", G_CALLBACK(callback_input), NULL); /*D*/
	g_signal_connect(G_OBJECT(button38), "clicked", G_CALLBACK(callback_input), NULL); /*E*/
	g_signal_connect(G_OBJECT(button42), "clicked", G_CALLBACK(callback_input), NULL); /*F*/

	/*下面的按钮实现小数点的输入*/
	g_signal_connect(G_OBJECT(button27), "clicked", G_CALLBACK(callback_dot), NULL);

	/*下面的按钮实现正负号的输入*/
	g_signal_connect(G_OBJECT(button22), "clicked", G_CALLBACK(callback_sign), NULL);

	/*下面的按钮实现各种运算的输入*/
	g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(callback_sin), NULL);
	g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(callback_cos), NULL);
	g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(callback_tan), NULL);
	g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(callback_exp), NULL);
	g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(callback_pow_x_y), NULL);
	g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(callback_cube), NULL);
	g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(callback_square), NULL);
	g_signal_connect(G_OBJECT(button10), "clicked", G_CALLBACK(callback_log_e), NULL);
	g_signal_connect(G_OBJECT(button11), "clicked", G_CALLBACK(callback_log_10), NULL);
	g_signal_connect(G_OBJECT(button12), "clicked", G_CALLBACK(callback_factorial),
			NULL);
	g_signal_connect(G_OBJECT(button13), "clicked", G_CALLBACK(callback_inverse), NULL);
	g_signal_connect(G_OBJECT(button32), "clicked", G_CALLBACK(callback_add), NULL);
	g_signal_connect(G_OBJECT(button31), "clicked", G_CALLBACK(callback_sub), NULL);
	g_signal_connect(G_OBJECT(button30), "clicked", G_CALLBACK(callback_mul), NULL);
	g_signal_connect(G_OBJECT(button29), "clicked", G_CALLBACK(callback_division), NULL);
	g_signal_connect(G_OBJECT(button35), "clicked", G_CALLBACK(callback_and), NULL);
	g_signal_connect(G_OBJECT(button36), "clicked", G_CALLBACK(callback_or), NULL);
	g_signal_connect(G_OBJECT(button37), "clicked", G_CALLBACK(callback_mod), NULL);
	g_signal_connect(G_OBJECT(button39), "clicked", G_CALLBACK(callback_not), NULL);
	g_signal_connect(G_OBJECT(button40), "clicked", G_CALLBACK(callback_xor), NULL);
	g_signal_connect(G_OBJECT(button41), "clicked", G_CALLBACK(callback_floor), NULL);

	/* 下面的按钮实现复位功能*/
	g_signal_connect(G_OBJECT(button34), "clicked", G_CALLBACK(callback_clear), NULL);

	/* 下面的按钮实现结果输出*/
	g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(output), NULL);
}
