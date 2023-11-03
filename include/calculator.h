#include <math.h>

#include <gtk/gtk.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

extern double first_op, second_op; /*定义两个参与运算的变量，双精度型*/
extern double value_in_decimal;
extern int has_dot; /*是否有小数点*/
extern int method; /*用于区别不同的运算*/
extern int radix; /*标识不同的进制*/
extern char out[20]; /*输出结果*/

extern GtkWidget *entry; /*文本框*/

void show_all();
void show_bin_window();
void show_dec_window();
void show_hex_window();
void show_oct_window();

int conversion(char num[20], int from_radix, int to_radix);

void error_handle(const char* info);
void add_signal();

void binary_operator();
void right_output();
float fun(int c);
void output();

GdkPixbuf *create_pixbuf(const gchar *filename);

void callback_radix_convert(GtkWidget *widget, gpointer data);
void callback_add(GtkWidget *widget, gpointer data);
void callback_sub(GtkWidget *widget, gpointer data);
void callback_mul(GtkWidget *widget, gpointer data);
void callback_division(GtkWidget *widget, gpointer data);
void callback_pow_x_y(GtkWidget *widget, gpointer data);
void callback_and(GtkWidget *widget, gpointer data);
void callback_or(GtkWidget *widget, gpointer data);
void callback_xor(GtkWidget *widget, gpointer data);
void callback_mod(GtkWidget *widget, gpointer data);
void callback_sin(GtkWidget *widget, gpointer data);
void callback_cos(GtkWidget *widget, gpointer data);
void callback_tan(GtkWidget *widget, gpointer data);
void callback_exp(GtkWidget *widget, gpointer data);
void callback_cube(GtkWidget *widget, gpointer data);
void callback_square(GtkWidget *widget, gpointer data);
void callback_log_e(GtkWidget *widget, gpointer data);
void callback_log_10(GtkWidget *widget, gpointer data);
void callback_factorial(GtkWidget *widget, gpointer data);
void callback_inverse(GtkWidget *widget, gpointer data);
void callback_not(GtkWidget *widget, gpointer data);
void callback_floor(GtkWidget *widget, gpointer data);
void callback_dot(GtkWidget *widget, gpointer data);
void callback_sign(GtkWidget *widget, gpointer data);
void callback_clear(GtkWidget *widget, gpointer data);
void callback_input(GtkWidget *widget, gpointer data);
void callback_input_pi(GtkWidget *widget, gpointer data);

#endif // CALCULATOR_H
