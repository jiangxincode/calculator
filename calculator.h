#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

extern double a,b;          /*定义两个参与运算的变量，双精度型*/
extern double p;
extern int hasdot;          /*是否有小数点*/
extern int method;          /*用于区别不同的运算*/
extern int principle;       /*标识不同的进制*/
extern char out[20]; /*输出结果*/

extern GtkWidget *window;   /*这一部分是定义元件*/
extern GtkWidget *vbox;     /*垂直框*/
extern GtkWidget *table1;   /*表格1*/
extern GtkWidget *table2;   /*表格2*/
extern GSList *group;
extern GtkWidget *radio;    /*单选按钮*/
extern GtkWidget *entry;    /*文本框*/
extern GtkWidget *button1;  /*42个按钮*/
extern GtkWidget *button2;
extern GtkWidget *button3;
extern GtkWidget *button4;
extern GtkWidget *button5;
extern GtkWidget *button6;
extern GtkWidget *button7;
extern GtkWidget *button8;
extern GtkWidget *button9;
extern GtkWidget *button10;
extern GtkWidget *button11;
extern GtkWidget *button12;
extern GtkWidget *button13;
extern GtkWidget *button14;
extern GtkWidget *button15;
extern GtkWidget *button16;
extern GtkWidget *button17;
extern GtkWidget *button18;
extern GtkWidget *button19;
extern GtkWidget *button20;
extern GtkWidget *button21;
extern GtkWidget *button22;
extern GtkWidget *button23;
extern GtkWidget *button24;
extern GtkWidget *button25;
extern GtkWidget *button26;
extern GtkWidget *button27;
extern GtkWidget *button28;
extern GtkWidget *button29;
extern GtkWidget *button30;
extern GtkWidget *button31;
extern GtkWidget *button32;
extern GtkWidget *button33;
extern GtkWidget *button34;
extern GtkWidget *button35;
extern GtkWidget *button36;
extern GtkWidget *button37;
extern GtkWidget *button38;
extern GtkWidget *button39;
extern GtkWidget *button40;
extern GtkWidget *button41;
extern GtkWidget *button42;

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
float fun(int c) ;
void output();

GdkPixbuf *create_pixbuf(const gchar *filename);

void on_clicked(GtkWidget *widget, gpointer data);
void Add(GtkWidget *widget, gpointer data);
void Sub(GtkWidget *widget,gpointer data);
void Mul(GtkWidget *widget,gpointer data);
void Division(GtkWidget *widget,gpointer data);
void Mathpowxy(GtkWidget *widget,gpointer data);
void And(GtkWidget *widget,gpointer data);
void Or(GtkWidget *widget,gpointer data);
void Xor(GtkWidget *widget,gpointer data);
void Mod(GtkWidget *widget,gpointer data);
void Sin(GtkWidget *widget,gpointer data);
void Cos(GtkWidget *widget,gpointer data);
void Tan(GtkWidget *widget,gpointer data);
void Exp(GtkWidget *widget,gpointer data);
void Cube(GtkWidget *widget,gpointer data);
void Square(GtkWidget *widget,gpointer data);
void Log_e(GtkWidget *widget,gpointer data);
void Log_10(GtkWidget *widget,gpointer data);
void Factorial(GtkWidget *widget,gpointer data);
void Inverse(GtkWidget *widget,gpointer data);
void Not(GtkWidget *widget,gpointer data);
void Floor(GtkWidget *widget,gpointer data);
void dot(GtkWidget *widget,gpointer data);
void Sign(GtkWidget *widget,gpointer data);
void clear(GtkWidget *widget,gpointer data);
void input (GtkWidget *widget, gpointer data);
void input_pi (GtkWidget *widget, gpointer data);

#endif // CALCULATOR_H
