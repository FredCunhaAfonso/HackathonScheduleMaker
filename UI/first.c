#include <gtk/gtk.h>

//sudo apt-get install libgtk-3-dev

// Callback function to handle the "destroy" signal
static void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the "destroy" signal to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    // Display the main window
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}