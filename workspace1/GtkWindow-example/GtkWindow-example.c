#include <gtk/gtk.h>


#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 520
#define CONTAINER_SPACING 0
#define ICON_NAME   "nome icona"
#define BUTTON_LABEL    "Fullscreen"


static void activate(GtkApplication *app, gpointer user_data);
static void fullscreen_switch(GtkWidget *widget, gpointer user_data);


int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}


static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *container;
    GtkWidget *button;
    const char *str;
    gboolean fullscreen_flag = false;
    gpointer data_pointer = &fullscreen_flag;

    /* window */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Titolo Finestra");
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_window_set_auto_startup_notification(true);
    gtk_window_set_default_icon_name(ICON_NAME);

    str = gtk_window_get_default_icon_name();
    if(str == NULL) {
        printf("puntatore nullo");
    }else {
        printf(gtk_window_get_default_icon_name());
    }

    /* container */
    container = gtk_box_new(GTK_ORIENTATION_VERTICAL, CONTAINER_SPACING);
    gtk_widget_set_halign(container, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(container, GTK_ALIGN_CENTER);

    /* button */
    button = gtk_button_new_with_label(BUTTON_LABEL);
    g_signal_connect(button, "clicked", G_CALLBACK(fullscreen_switch), data_pointer);

    /* set visible */
	gtk_widget_set_visible(window, true);

    gtk_window_fullscreen(GTK_WINDOW(window));
}


static void fullscreen_switch(GtkWidget *widget, gpointer user_data) {
    //finire...
}   