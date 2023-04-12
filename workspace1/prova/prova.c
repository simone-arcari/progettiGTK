/*
 *      gcc $(pkg-config --cflags gtk4) -o prova prova.c $(pkg-config --libs gtk4)
 */

#include <gtk/gtk.h>
#include <stdio.h>

static void print_msg (GtkWidget *widget, gpointer id) {
	g_print ("button%d pressed\n", (int)id);
}


static void activate (GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *main_container;
    GtkWidget *box1;
    GtkWidget *box2;

    const int box_spacing = 5; 


    /* window */
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "Prova");
	gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);


    /* container */
    main_container = gtk_box_new (GTK_ORIENTATION_VERTICAL, box_spacing);
    

    /* boxes */
    box1 = gtk_box_new (GTK_ORIENTATION_VERTICAL, box_spacing);
    box2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, box_spacing);


    /* buttons */
	button1 = gtk_button_new_with_label ("button 1");
    button2 = gtk_button_new_with_label ("button 2");
    button3 = gtk_button_new_with_label ("button 3");
    button4 = gtk_button_new_with_label ("button 4");

	g_signal_connect (button1, "clicked", G_CALLBACK (print_msg), (gpointer)1);
    g_signal_connect (button2, "clicked", G_CALLBACK (print_msg), (gpointer)2);
    g_signal_connect (button3, "clicked", G_CALLBACK (print_msg), (gpointer)3);
    g_signal_connect (button4, "clicked", G_CALLBACK (print_msg), (gpointer)4);

    /* appending... */
    gtk_box_append (GTK_BOX (box1), button1);
    gtk_box_append (GTK_BOX (box1), button2);

    gtk_box_append (GTK_BOX (box2), button3);
    gtk_box_append (GTK_BOX (box2), button4);

    gtk_box_append (GTK_BOX (main_container), box1);
    gtk_box_append (GTK_BOX (main_container), box2);

	gtk_window_set_child (GTK_WINDOW (window), main_container);


    /* set visible */
	gtk_window_present (GTK_WINDOW (window));
}


int main (int argc, char **argv) {
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}