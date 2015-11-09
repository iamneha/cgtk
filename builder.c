#include<gtk/gtk.h>
static void print_hello(GtkWidget *widget,
				gpointer data)
{
g_print("Hello World!");
}
int main(int argc, char *argv[])
{
GtkBuilder *builder;
GObject *window;
GObject *button;

gtk_init(&argc, &argv);

//construct a gtkbuilder instance and load our UI description
builder = gtk_builder_new();
gtk_builder_add_from_file(builder, "builder.ui", NULL);
//connect signal handlers to the constructed widgets
window = gtk_builder_get_object(builder, "window");
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

button = gtk_builder_get_object(builder, "Button1");
g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

button = gtk_builder_get_object(builder, "Button2");
g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

button = gtk_builder_get_object(builder, "Quit");
g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

gtk_main();
return 0;
}
