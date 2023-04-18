#include <gtk/gtk.h>
#include <glib/gstdio.h>


static void print_msg (GtkWidget *widget, gpointer id) {
    int Id = (int)id;

    if(Id != -1)
	    g_print("button%d pressed\n", Id);
    else
        g_print("ma che cazzo vuooooi?!?!?!?\n");
}


static void activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder;
    GObject *window;    //GtkWindow *window;
    GObject *button;    //GtkButton *button;

    int button_number = 8;


    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "xml.xml", NULL);


    /* Connect signal handlers to the constructed widgets. */
    window = gtk_builder_get_object(builder, "window");
    gtk_window_set_application(GTK_WINDOW(window), app);


    /* buttons */
    button = gtk_builder_get_object(builder, "button1");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)1);

    button = gtk_builder_get_object(builder, "button2");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)2);

    button = gtk_builder_get_object(builder, "button3");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)3);

    button = gtk_builder_get_object(builder, "button4");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)4);

    button = gtk_builder_get_object(builder, "button5");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)5);

    button = gtk_builder_get_object(builder, "button6");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)6);

    button = gtk_builder_get_object(builder, "button7");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)7);

    button = gtk_builder_get_object(builder, "button8");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)8);

    button = gtk_builder_get_object(builder, "quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close), window);

    button = gtk_builder_get_object(builder, "valeria_button");
    g_signal_connect (button, "clicked", G_CALLBACK (print_msg), (gpointer)-1);


    
    gtk_widget_set_visible(GTK_WIDGET(window), true); //gtk_widget_show(GTK_WIDGET(window));

    /* We do not need the builder any more */
    g_object_unref(builder);
}


int main(int argc, char *argv[]) 
{
#ifdef GTK_SRCDIR
    g_chdir(GTK_SRCDIR);
#endif

    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}