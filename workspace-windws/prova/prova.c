/*
 *      gcc $(pkg-config --cflags gtk4) -o prova prova.c $(pkg-config --libs gtk4)
 */

#include <gtk/gtk.h>
#include <stdio.h>

static void print_msg (GtkWidget *widget, gpointer id) {

    int Id = (int)id;

    if(Id != -1)
	    g_print ("button%d pressed\n", Id);
    else
        g_print ("ma che cazzo vuooooi?!?!?!?\n");
}


static void activate (GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;
    GtkWidget *button8;
    GtkWidget *quit_button;
    GtkWidget *valeria_button;
    GtkWidget *main_container;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *box3;
    GtkWidget *grid;

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
    box3 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 50);

    gtk_widget_set_halign(box3, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box3, GTK_ALIGN_CENTER);


    /* grid */
    grid = gtk_grid_new();


    /* buttons */
	button1 = gtk_button_new_with_label ("button 1");
    button2 = gtk_button_new_with_label ("button 2");
    button3 = gtk_button_new_with_label ("button 3");
    button4 = gtk_button_new_with_label ("button 4");
    button5 = gtk_button_new_with_label ("button 5");
    button6 = gtk_button_new_with_label ("button 6");
    button7 = gtk_button_new_with_label ("button 7");
    button8 = gtk_button_new_with_label ("button 8");
    quit_button = gtk_button_new_with_label ("quit");
    valeria_button = gtk_button_new_with_label ("Tasto Valeria da non premere!");

	g_signal_connect (button1, "clicked", G_CALLBACK (print_msg), (gpointer)1);
    g_signal_connect (button2, "clicked", G_CALLBACK (print_msg), (gpointer)2);
    g_signal_connect (button3, "clicked", G_CALLBACK (print_msg), (gpointer)3);
    g_signal_connect (button4, "clicked", G_CALLBACK (print_msg), (gpointer)4);
    g_signal_connect (button5, "clicked", G_CALLBACK (print_msg), (gpointer)5);
    g_signal_connect (button6, "clicked", G_CALLBACK (print_msg), (gpointer)6);
    g_signal_connect (button7, "clicked", G_CALLBACK (print_msg), (gpointer)7);
    g_signal_connect (button8, "clicked", G_CALLBACK (print_msg), (gpointer)8);
    g_signal_connect_swapped (quit_button, "clicked", G_CALLBACK (gtk_window_destroy), window);
    g_signal_connect (valeria_button, "clicked", G_CALLBACK (print_msg), (gpointer)-1);


    /* appending... */
    gtk_box_append (GTK_BOX (box1), button1);
    gtk_box_append (GTK_BOX (box1), button2);

    gtk_box_append (GTK_BOX (box2), button3);
    gtk_box_append (GTK_BOX (box2), button4);
    gtk_box_append (GTK_BOX (box2), valeria_button);
    
    gtk_box_append (GTK_BOX (box3), button7);
    gtk_box_append (GTK_BOX (box3), button8);

    gtk_grid_attach(GTK_GRID(grid), button5, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button6, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 1, 0, 1, 2);

    gtk_box_append (GTK_BOX (main_container), box1);
    gtk_box_append (GTK_BOX (main_container), box2);
    gtk_box_append (GTK_BOX (main_container), grid);
    gtk_box_append (GTK_BOX (main_container), box3);
    
	gtk_window_set_child (GTK_WINDOW (window), main_container);


    /* set visible */
	gtk_widget_set_visible(window, true); //gtk_widget_show(window);    //gtk_window_present (GTK_WINDOW (window));
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