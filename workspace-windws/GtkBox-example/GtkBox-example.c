#include <gtk/gtk.h>

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 520
#define SPACING 0

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *container;
    GtkWidget *top_box;
    GtkWidget *right_box;
    GtkWidget *left_box;
    GtkWidget *bottom_box;
    GtkWidget *center_box;
    GdkRGBA color;

    /* window */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Titolo Finestra");
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);


    /* container */
    container = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACING);
    gtk_widget_set_halign(container, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(container, GTK_ALIGN_CENTER);


    // Creazione del box superiore
    top_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_set_expand(GTK_BOX(top_box), TRUE);
    gtk_box_set_alignment(GTK_BOX(top_box), 0.0, 0.0);
    gtk_box_pack_start(GTK_BOX(container), top_box, FALSE, FALSE, 0);

    // Creazione del box destro
    right_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_expand(GTK_BOX(right_box), TRUE);
    gtk_box_set_alignment(GTK_BOX(right_box), 1.0, 0.0);
    gtk_box_pack_end(GTK_BOX(top_box), right_box, FALSE, FALSE, 0);

    // Creazione del box sinistro
    left_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_expand(GTK_BOX(left_box), TRUE);
    gtk_box_set_alignment(GTK_BOX(left_box), 0.0, 0.0);
    gtk_box_pack_start(GTK_BOX(top_box), left_box, FALSE, FALSE, 0);

    // Creazione del box inferiore
    bottom_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_set_expand(GTK_BOX(bottom_box), TRUE);
    gtk_box_set_alignment(GTK_BOX(bottom_box), 0.5, 0.0);
    gtk_box_pack_end(GTK_BOX(container), bottom_box, FALSE, FALSE, 0);

    // Creazione del box centrale
    center_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_expand(GTK_BOX(center_box), TRUE);
    gtk_box_set_alignment(GTK_BOX(center_box), 0.5, 0.5);
    gtk_box_pack_start(GTK_BOX(bottom_box), center_box, FALSE, FALSE, 0);


    //colori box

    // Imposta il colore di background in rosso
    gdk_rgba_parse(&color, "red");
    gtk_widget_override_background_color(top_box, GTK_STATE_FLAG_NORMAL, &color);


    /* appending */
    gtk_window_set_child(GTK_WINDOW(window), container);


    /* set visible */
	gtk_widget_set_visible(window, true);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}