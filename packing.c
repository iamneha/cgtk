#include<gtk/gtk.h>
static void 
print_hello(GtkWidget *widget,
		gpointer data)
{
 g_print("Hello world!");
}
static void 
activate(GtkApplication *app,
		gpointer user_data)
{
 GtkWidget *window;
 GtkWidget *grid;
 GtkWidget *button;

	//create new window and set title
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "window");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	//construct container that is going to pack our widget
	grid = gtk_grid_new();
	//pack container in window
	gtk_container_add(GTK_CONTAINER(window), grid);
	
	button = gtk_button_new_with_label("Button1");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	//place the first button in grid cell
	gtk_grid_attach(GTK_GRID(grid), button, 0,0,1,1);

	button = gtk_button_new_with_label("Button2");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	//place second button in grid cell
	gtk_grid_attach(GTK_GRID(grid), button, 1,0,1,1);
         
	button = gtk_button_new_with_label("QUIT");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button,0, 1,2,1);
	
gtk_widget_show_all(window);
}
int main(int argc, char **argv)
{
GtkApplication *app;
int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
return status;

}
