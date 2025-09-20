#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
#include "../include/calculator.h"

#define PACKAGE "calculator"
#define LOCALEDIR "locale"
#define _(string) gettext(string)
#define N_(string) string

// Calculation state
double first_op, second_op;
double value_in_dec;
int has_dot;
int method;
int radix;
char out_array[20];

// UI containers
GtkWidget *grid0;
GtkWidget *grid1;
GtkWidget *grid2;
GtkWidget *entry;

// Scientific function buttons
GtkWidget *btn_pi, *btn_sin, *btn_cos, *btn_tan;
GtkWidget *btn_exp, *btn_pow_xy, *btn_pow_3, *btn_pow_2;
GtkWidget *btn_ln, *btn_log, *btn_factorial, *btn_inverse;

// Number input buttons
GtkWidget *btn_0, *btn_1, *btn_2, *btn_3, *btn_4;
GtkWidget *btn_5, *btn_6, *btn_7, *btn_8, *btn_9;
GtkWidget *btn_a, *btn_b, *btn_c, *btn_d, *btn_e, *btn_f;

// Operator buttons
GtkWidget *btn_add, *btn_subtract, *btn_multiply, *btn_divide;
GtkWidget *btn_equals, *btn_dot, *btn_sign, *btn_clear;

// Logic operation buttons
GtkWidget *btn_and, *btn_or, *btn_xor, *btn_not, *btn_mod, *btn_int;

static void activate(GtkApplication *app);

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("edu.jiangxin.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

static void initialize_variables(void)
{
    first_op = 0.0;
    second_op = 0.0;
    has_dot = 0;
    method = 0;
    radix = 10;
}

static GtkWidget* create_window(GtkApplication *app)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), _("Calculator"));
    return window;
}

static void setup_grid_layout(void)
{
    grid0 = gtk_grid_new();
    grid1 = gtk_grid_new();
    grid2 = gtk_grid_new();

    gtk_grid_set_column_homogeneous(GTK_GRID(grid0), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid0), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid0), 1);

    gtk_grid_attach(GTK_GRID(grid0), grid1, 0, 0, 9, 2);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid1), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid1), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid1), 1);

    gtk_grid_attach(GTK_GRID(grid0), grid2, 0, 2, 9, 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid2), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid2), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid2), 1);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid1), entry, 0, 0, 9, 1);
}

static GtkWidget* make_button(const char* label, int left, int top, int width, int height)
{
    GtkWidget *button = gtk_button_new_with_mnemonic(label);
    gtk_grid_attach(GTK_GRID(grid2), button, left, top, width, height);
    return button;
}

static void create_scientific_functions(void)
{
    btn_pi = make_button("pi", 0, 0, 1, 1);
    btn_sin = make_button("sin", 0, 1, 1, 1);
    btn_cos = make_button("cos", 0, 2, 1, 1);
    btn_tan = make_button("tan", 0, 3, 1, 1);
    btn_equals = make_button("=", 0, 4, 3, 1);

    btn_exp = make_button("exp", 1, 0, 1, 1);
    btn_pow_xy = make_button("x^y", 1, 1, 1, 1);
    btn_pow_3 = make_button("x^3", 1, 2, 1, 1);
    btn_pow_2 = make_button("x^2", 1, 3, 1, 1);

    btn_ln = make_button("ln", 2, 0, 1, 1);
    btn_log = make_button("log", 2, 1, 1, 1);
    btn_factorial = make_button("n!", 2, 2, 1, 1);
    btn_inverse = make_button("1/x", 2, 3, 1, 1);
}

static void create_numeric_keypad(void)
{
    btn_7 = make_button("7", 3, 0, 1, 1);
    btn_4 = make_button("4", 3, 1, 1, 1);
    btn_1 = make_button("1", 3, 2, 1, 1);
    btn_0 = make_button("0", 3, 3, 1, 1);
    btn_a = make_button("A", 3, 4, 1, 1);

    btn_8 = make_button("8", 4, 0, 1, 1);
    btn_5 = make_button("5", 4, 1, 1, 1);
    btn_2 = make_button("2", 4, 2, 1, 1);
    btn_sign = make_button("+/-", 4, 3, 1, 1);
    btn_b = make_button("B", 4, 4, 1, 1);

    btn_9 = make_button("9", 5, 0, 1, 1);
    btn_6 = make_button("6", 5, 1, 1, 1);
    btn_3 = make_button("3", 5, 2, 1, 1);
    btn_dot = make_button(".", 5, 3, 1, 1);
    btn_c = make_button("C", 5, 4, 1, 1);
}

static void create_operators(void)
{
    btn_divide = make_button("/", 6, 0, 1, 1);
    btn_multiply = make_button("*", 6, 1, 1, 1);
    btn_subtract = make_button("-", 6, 2, 1, 1);
    btn_add = make_button("+", 6, 3, 1, 1);
    btn_d = make_button("D", 6, 4, 1, 1);

    btn_clear = make_button("CR", 7, 0, 2, 1);
    btn_and = make_button("And", 7, 1, 1, 1);
    btn_or = make_button("Or", 7, 2, 1, 1);
    btn_mod = make_button("Mod", 7, 3, 1, 1);
    btn_e = make_button("E", 7, 4, 1, 1);

    btn_not = make_button("Not", 8, 1, 1, 1);
    btn_xor = make_button("Xor", 8, 2, 1, 1);
    btn_int = make_button("Int", 8, 3, 1, 1);
    btn_f = make_button("F", 8, 4, 1, 1);
}

static void create_radix_controls(void)
{
    GtkWidget *radio1 = gtk_toggle_button_new_with_label("Hex");
    g_signal_connect(GTK_WIDGET(radio1), "clicked", G_CALLBACK(callback_radix_convert), "Hex");
    gtk_grid_attach(GTK_GRID(grid1), radio1, 0, 1, 2, 1);

    GtkWidget *radio2 = gtk_toggle_button_new_with_label("Dec");
    gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio2), GTK_TOGGLE_BUTTON(radio1));
    g_signal_connect(GTK_WIDGET(radio2), "clicked", G_CALLBACK(callback_radix_convert), "Dec");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio2), TRUE);
    gtk_grid_attach(GTK_GRID(grid1), radio2, 2, 1, 2, 1);

    GtkWidget *radio3 = gtk_toggle_button_new_with_label("Oct");
    gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio3), GTK_TOGGLE_BUTTON(radio1));
    g_signal_connect(GTK_WIDGET(radio3), "clicked", G_CALLBACK(callback_radix_convert), "Oct");
    gtk_grid_attach(GTK_GRID(grid1), radio3, 4, 1, 2, 1);

    GtkWidget *radio4 = gtk_toggle_button_new_with_label("Bin");
    gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(radio4), GTK_TOGGLE_BUTTON(radio1));
    g_signal_connect(GTK_WIDGET(radio4), "clicked", G_CALLBACK(callback_radix_convert), "Bin");
    gtk_grid_attach(GTK_GRID(grid1), radio4, 6, 1, 2, 1);
}

static void activate(GtkApplication *app)
{
    bindtextdomain(PACKAGE, LOCALEDIR);
    textdomain(PACKAGE);

    gtk_init();
    initialize_variables();

    GtkWidget *window = create_window(app);
    setup_grid_layout();
    gtk_window_set_child(GTK_WINDOW(window), grid0);

    create_scientific_functions();
    create_numeric_keypad();
    create_operators();
    create_radix_controls();

    add_signal();
    gtk_window_present(GTK_WINDOW(window));
}

void show_all()
{
    GtkWidget *buttons[] = {
        btn_pi, btn_sin, btn_cos, btn_tan, btn_equals, btn_exp, btn_pow_xy,
        btn_pow_3, btn_pow_2, btn_ln, btn_log, btn_factorial, btn_inverse,
        btn_7, btn_4, btn_1, btn_0, btn_8, btn_5, btn_2, btn_sign,
        btn_9, btn_6, btn_3, btn_dot, btn_a, btn_b, btn_c, btn_d, btn_e, btn_f,
        btn_divide, btn_multiply, btn_subtract, btn_add, btn_clear,
        btn_and, btn_or, btn_mod, btn_not, btn_xor, btn_int
    };

    for (unsigned long i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
        gtk_widget_set_sensitive(buttons[i], TRUE);
    }
}

void show_bin_window()
{
    show_all();
    
    GtkWidget *disabled[] = {
        btn_pi, btn_sin, btn_cos, btn_tan,
        btn_7, btn_4, btn_8, btn_5, btn_2, btn_9, btn_6, btn_3,
        btn_a, btn_b, btn_c, btn_d, btn_e, btn_f
    };

    for (unsigned long i = 0; i < sizeof(disabled) / sizeof(disabled[0]); i++) {
        gtk_widget_set_sensitive(disabled[i], FALSE);
    }
}

void show_dec_window()
{
    show_all();
    
    GtkWidget *disabled[] = {
        btn_a, btn_b, btn_c, btn_d, btn_e, btn_f
    };

    for (unsigned long i = 0; i < sizeof(disabled) / sizeof(disabled[0]); i++) {
        gtk_widget_set_sensitive(disabled[i], FALSE);
    }
}

void show_hex_window()
{
    show_all();
    
    GtkWidget *disabled[] = {
        btn_pi, btn_sin, btn_cos, btn_tan
    };

    for (unsigned long i = 0; i < sizeof(disabled) / sizeof(disabled[0]); i++) {
        gtk_widget_set_sensitive(disabled[i], FALSE);
    }
}

void show_oct_window()
{
    show_all();
    
    GtkWidget *disabled[] = {
        btn_pi, btn_sin, btn_cos, btn_tan,
        btn_8, btn_9, btn_a, btn_b, btn_c, btn_d, btn_e, btn_f
    };

    for (unsigned long i = 0; i < sizeof(disabled) / sizeof(disabled[0]); i++) {
        gtk_widget_set_sensitive(disabled[i], FALSE);
    }
}

void add_signal()
{
    struct {
        GtkWidget *widget;
        GCallback callback;
        gpointer data;
    } signals[] = {
        {btn_pi, G_CALLBACK(callback_input_pi), NULL},
        {btn_0, G_CALLBACK(callback_input), NULL},
        {btn_1, G_CALLBACK(callback_input), NULL},
        {btn_2, G_CALLBACK(callback_input), NULL},
        {btn_3, G_CALLBACK(callback_input), NULL},
        {btn_4, G_CALLBACK(callback_input), NULL},
        {btn_5, G_CALLBACK(callback_input), NULL},
        {btn_6, G_CALLBACK(callback_input), NULL},
        {btn_7, G_CALLBACK(callback_input), NULL},
        {btn_8, G_CALLBACK(callback_input), NULL},
        {btn_9, G_CALLBACK(callback_input), NULL},
        {btn_a, G_CALLBACK(callback_input), NULL},
        {btn_b, G_CALLBACK(callback_input), NULL},
        {btn_c, G_CALLBACK(callback_input), NULL},
        {btn_d, G_CALLBACK(callback_input), NULL},
        {btn_e, G_CALLBACK(callback_input), NULL},
        {btn_f, G_CALLBACK(callback_input), NULL},
        {btn_dot, G_CALLBACK(callback_dot), NULL},
        {btn_sign, G_CALLBACK(callback_sign), NULL},
        {btn_sin, G_CALLBACK(callback_sin), NULL},
        {btn_cos, G_CALLBACK(callback_cos), NULL},
        {btn_tan, G_CALLBACK(callback_tan), NULL},
        {btn_exp, G_CALLBACK(callback_exp), NULL},
        {btn_pow_xy, G_CALLBACK(callback_pow_x_y), NULL},
        {btn_pow_3, G_CALLBACK(callback_cube), NULL},
        {btn_pow_2, G_CALLBACK(callback_square), NULL},
        {btn_ln, G_CALLBACK(callback_log_e), NULL},
        {btn_log, G_CALLBACK(callback_log_10), NULL},
        {btn_factorial, G_CALLBACK(callback_factorial), NULL},
        {btn_inverse, G_CALLBACK(callback_inverse), NULL},
        {btn_add, G_CALLBACK(callback_add), NULL},
        {btn_subtract, G_CALLBACK(callback_sub), NULL},
        {btn_multiply, G_CALLBACK(callback_mul), NULL},
        {btn_divide, G_CALLBACK(callback_division), NULL},
        {btn_and, G_CALLBACK(callback_and), NULL},
        {btn_or, G_CALLBACK(callback_or), NULL},
        {btn_mod, G_CALLBACK(callback_mod), NULL},
        {btn_not, G_CALLBACK(callback_not), NULL},
        {btn_xor, G_CALLBACK(callback_xor), NULL},
        {btn_int, G_CALLBACK(callback_floor), NULL},
        {btn_clear, G_CALLBACK(callback_clear), NULL},
        {btn_equals, G_CALLBACK(output), NULL}
    };

    for (unsigned long i = 0; i < sizeof(signals) / sizeof(signals[0]); i++) {
        g_signal_connect(G_OBJECT(signals[i].widget), "clicked", 
                        signals[i].callback, signals[i].data);
    }
}