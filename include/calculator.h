#include <math.h>

#include <gtk/gtk.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

double a, b; /*定义两个参与运算的变量，双精度型*/
double p;
int hasdot; /*是否有小数点*/
int method; /*用于区别不同的运算*/
int principle; /*标识不同的进制*/
char out[20]; /*输出结果*/

GtkWidget *window; /*这一部分是定义元件*/
GtkWidget *grid0; /*垂直框*/
GtkWidget *grid1; /*表格1*/
GtkWidget *grid2; /*表格2*/
GSList *group;
GtkWidget *radio; /*单选按钮*/
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

void show_all();
void show_Bin_window();
void show_Dec_window();
void show_Hex_window();
void show_Oct_window();

int Conversion(char num[20], int t, int n);

void error_handle(const char* info);
void addsignal();

void Binary_Operator();
void Right_output();
float fun(int c);
void output();

GdkPixbuf *create_pixbuf(const gchar *filename);

void on_clicked(GtkWidget *widget, gpointer data);
void Add(GtkWidget *widget, gpointer data);
void Sub(GtkWidget *widget, gpointer data);
void Mul(GtkWidget *widget, gpointer data);
void Division(GtkWidget *widget, gpointer data);
void Mathpowxy(GtkWidget *widget, gpointer data);
void And(GtkWidget *widget, gpointer data);
void Or(GtkWidget *widget, gpointer data);
void Xor(GtkWidget *widget, gpointer data);
void Mod(GtkWidget *widget, gpointer data);
void Sin(GtkWidget *widget, gpointer data);
void Cos(GtkWidget *widget, gpointer data);
void Tan(GtkWidget *widget, gpointer data);
void Exp(GtkWidget *widget, gpointer data);
void Cube(GtkWidget *widget, gpointer data);
void Square(GtkWidget *widget, gpointer data);
void Log_e(GtkWidget *widget, gpointer data);
void Log_10(GtkWidget *widget, gpointer data);
void Factorial(GtkWidget *widget, gpointer data);
void Inverse(GtkWidget *widget, gpointer data);
void Not(GtkWidget *widget, gpointer data);
void Floor(GtkWidget *widget, gpointer data);
void dot(GtkWidget *widget, gpointer data);
void Sign(GtkWidget *widget, gpointer data);
void clear(GtkWidget *widget, gpointer data);
void input(GtkWidget *widget, gpointer data);
void input_pi(GtkWidget *widget, gpointer data);

#endif // CALCULATOR_H
