#include "first.h"
#include <landingpage.h>
#include "savebox.h"

//sudo apt-get install libgtk-3-dev

extern Box* inputCollect;

int initGTK(int argc, char *argv[]){
    
    gtk_init(&argc, &argv);

    inputCollect = malloc(sizeof(Box));

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ImAStudyCat");
    gtk_window_set_default_size(GTK_WINDOW(window), 2400, 1000);

    landing_page(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show the window and enter the main GTK+ event loop
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}