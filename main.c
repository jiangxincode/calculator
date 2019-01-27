#include <gtk/gtk.h>

#include "calculator.h"

int main(int argc, char *argv[])
{
	a = 0;
	b = 0;
	hasdot = 0;
	gtk_init(&argc, &argv);
	method = 0; /*运算方法。*/

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GCalculator");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("./data/icon.png"));

	grid0 = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid0);

	grid1 = gtk_grid_new();
	grid2 = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(grid0), grid1, 0, 0, 8, 2);
	gtk_grid_attach(GTK_GRID(grid0), grid2, 0, 2, 8, 5);

	entry = gtk_entry_new(); /*用于输入和输出的文本框*/
	gtk_grid_attach(GTK_GRID(grid1), entry, 0, 0, 8, 1);

	button1 = gtk_button_new_with_mnemonic("pi"); /*pi*/
	gtk_grid_attach(GTK_GRID(grid2), button1, 0, 0, 1, 1);
	gtk_widget_set_size_request(button1, 40, 30);

	button2 = gtk_button_new_with_mnemonic("sin"); /*sin*/
	gtk_grid_attach(GTK_GRID(grid2), button2, 0, 1, 1, 1);

	button3 = gtk_button_new_with_mnemonic("cos"); /*cos*/
	gtk_grid_attach(GTK_GRID(grid2), button3, 0, 2, 1, 1);

	button4 = gtk_button_new_with_mnemonic("tan"); /*tan*/
	gtk_grid_attach(GTK_GRID(grid2), button4, 0, 3, 1, 1);

	button5 = gtk_button_new_with_mnemonic("="); /*===*/
	gtk_grid_attach(GTK_GRID(grid2), button5, 0, 4, 3, 1);

	button6 = gtk_button_new_with_mnemonic("Exp"); /*Exp*/
	gtk_grid_attach(GTK_GRID(grid2), button6, 1, 0, 1, 1);
	gtk_widget_set_size_request(button6, 40, 30);

	button7 = gtk_button_new_with_mnemonic("x^y"); /*x^y*/
	gtk_grid_attach(GTK_GRID(grid2), button7, 1, 1, 1, 1);

	button8 = gtk_button_new_with_mnemonic("x^3"); /*x^3*/
	gtk_grid_attach(GTK_GRID(grid2), button8, 1, 2, 1, 1);

	button9 = gtk_button_new_with_mnemonic("x^2"); /*x^2*/
	gtk_grid_attach(GTK_GRID(grid2), button9, 1, 3, 1, 1);

	button10 = gtk_button_new_with_mnemonic("ln"); /*ln*/
	gtk_grid_attach(GTK_GRID(grid2), button10, 2, 0, 1, 1);
	gtk_widget_set_size_request(button10, 40, 30);

	button11 = gtk_button_new_with_mnemonic("log"); /*log*/
	gtk_grid_attach(GTK_GRID(grid2), button11, 2, 1, 1, 1);

	button12 = gtk_button_new_with_mnemonic("n!"); /*n!*/
	gtk_grid_attach(GTK_GRID(grid2), button12, 2, 2, 1, 1);

	button13 = gtk_button_new_with_mnemonic("1/x "); /*1/x*/
	gtk_grid_attach(GTK_GRID(grid2), button13, 2, 3, 1, 1);

	button14 = gtk_button_new_with_label("7"); /*数字按钮7*/
	gtk_grid_attach(GTK_GRID(grid2), button14, 3, 0, 1, 1);
	gtk_widget_set_size_request(button14, 40, 30);

	button15 = gtk_button_new_with_mnemonic("4"); /*数字按钮4*/
	gtk_grid_attach(GTK_GRID(grid2), button15, 3, 1, 1, 1);

	button16 = gtk_button_new_with_mnemonic("1"); /*数字按钮1*/
	gtk_grid_attach(GTK_GRID(grid2), button16, 3, 2, 1, 1);

	button17 = gtk_button_new_with_mnemonic("0"); /*数字按钮0*/
	gtk_grid_attach(GTK_GRID(grid2), button17, 3, 3, 1, 1);

	button18 = gtk_button_new_with_mnemonic("A"); /*数字按钮A*/
	gtk_grid_attach(GTK_GRID(grid2), button18, 3, 4, 1, 1);

	button19 = gtk_button_new_with_mnemonic("8"); /*数字按钮8*/
	gtk_grid_attach(GTK_GRID(grid2), button19, 4, 0, 1, 1);
	gtk_widget_set_size_request(button19, 40, 30);

	button20 = gtk_button_new_with_mnemonic("5"); /*数字按钮5*/
	gtk_grid_attach(GTK_GRID(grid2), button20, 4, 1, 1, 1);

	button21 = gtk_button_new_with_mnemonic("2"); /*数字按钮2*/
	gtk_grid_attach(GTK_GRID(grid2), button21, 4, 2, 1, 1);

	button22 = gtk_button_new_with_mnemonic("+/-"); /*+/-*/
	gtk_grid_attach(GTK_GRID(grid2), button22, 4, 3, 1, 1);

	button23 = gtk_button_new_with_mnemonic("B"); /*数字按钮B*/
	gtk_grid_attach(GTK_GRID(grid2), button23, 4, 4, 1, 1);

	button24 = gtk_button_new_with_mnemonic("9"); /*数字按钮9*/
	gtk_grid_attach(GTK_GRID(grid2), button24, 5, 0, 1, 1);
	gtk_widget_set_size_request(button24, 40, 30);

	button25 = gtk_button_new_with_mnemonic("6"); /*数字按钮6*/
	gtk_grid_attach(GTK_GRID(grid2), button25, 5, 1, 1, 1);

	button26 = gtk_button_new_with_mnemonic("3"); /*数字按钮3*/
	gtk_grid_attach(GTK_GRID(grid2), button26, 5, 2, 1, 1);

	button27 = gtk_button_new_with_mnemonic("."); /*小数点*/
	gtk_grid_attach(GTK_GRID(grid2), button27, 5, 3, 1, 1);

	button28 = gtk_button_new_with_mnemonic("C"); /*数字按钮C*/
	gtk_grid_attach(GTK_GRID(grid2), button28, 5, 4, 1, 1);

	button29 = gtk_button_new_with_mnemonic("/"); /*除法*/
	gtk_grid_attach(GTK_GRID(grid2), button29, 6, 0, 1, 1);
	gtk_widget_set_size_request(button29, 40, 30);

	button30 = gtk_button_new_with_mnemonic("*"); /*乘法*/
	gtk_grid_attach(GTK_GRID(grid2), button30, 6, 1, 1, 1);

	button31 = gtk_button_new_with_mnemonic("-"); /*减法*/
	gtk_grid_attach(GTK_GRID(grid2), button31, 6, 2, 1, 1);

	button32 = gtk_button_new_with_mnemonic("+"); /*加法*/
	gtk_grid_attach(GTK_GRID(grid2), button32, 6, 3, 1, 1);

	button33 = gtk_button_new_with_mnemonic("D"); /*D*/
	gtk_grid_attach(GTK_GRID(grid2), button33, 6, 4, 1, 1);

	button34 = gtk_button_new_with_mnemonic("CR"); /*CR*/
	gtk_grid_attach(GTK_GRID(grid2), button34, 7, 0, 2, 1);
	gtk_widget_set_size_request(button34, 80, 30);

	button35 = gtk_button_new_with_mnemonic("And"); /*And*/
	gtk_grid_attach(GTK_GRID(grid2), button35, 7, 1, 1, 1);

	button36 = gtk_button_new_with_mnemonic("Or"); /*Or*/
	gtk_grid_attach(GTK_GRID(grid2), button36, 7, 2, 1, 1);

	button37 = gtk_button_new_with_mnemonic("Mod"); /*Mod*/
	gtk_grid_attach(GTK_GRID(grid2), button37, 7, 3, 1, 1);

	button38 = gtk_button_new_with_mnemonic("E"); /*E*/
	gtk_grid_attach(GTK_GRID(grid2), button38, 7, 4, 1, 1);

	button39 = gtk_button_new_with_mnemonic("Not"); /*Not*/
	gtk_grid_attach(GTK_GRID(grid2), button39, 8, 1, 1, 1);

	button40 = gtk_button_new_with_mnemonic("Xor"); /*Xor*/
	gtk_grid_attach(GTK_GRID(grid2), button40, 8, 2, 1, 1);

	button41 = gtk_button_new_with_mnemonic("Int"); /*Int*/
	gtk_grid_attach(GTK_GRID(grid2), button41, 8, 3, 1, 1);

	button42 = gtk_button_new_with_mnemonic("F"); /*F*/
	gtk_grid_attach(GTK_GRID(grid2), button42, 8, 4, 1, 1);

	/*下面是创建四个单选按钮，并将"十进制"按钮设置为默认选中*/
	radio = gtk_radio_button_new_with_label(NULL, "Hex");
	g_signal_connect(GTK_WIDGET(radio), "clicked", G_CALLBACK(on_clicked),
			"Hex");
	gtk_grid_attach(GTK_GRID(grid1), radio, 0, 1, 2, 1);

	group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group, "Dec");
	g_signal_connect(GTK_WIDGET(radio), "clicked", G_CALLBACK(on_clicked),
			"Dec");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio), TRUE); /*十进制radio设置为默认选中状态*/
	gtk_grid_attach(GTK_GRID(grid1), radio, 2, 1, 2, 1);

	group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group, "Oct");
	g_signal_connect(GTK_WIDGET(radio), "clicked", G_CALLBACK(on_clicked),
			"Oct");
	gtk_grid_attach(GTK_GRID(grid1), radio, 4, 1, 2, 1);

	group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group, "Bin");
	g_signal_connect(GTK_WIDGET(radio), "clicked", G_CALLBACK(on_clicked),
			"Bin");
	gtk_grid_attach(GTK_GRID(grid1), radio, 6, 1, 2, 1);

	addsignal(); /*添加事件。*/

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
