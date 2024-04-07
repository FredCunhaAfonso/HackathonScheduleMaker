#ifndef MAINPAGE
#define MAINPAGE

#include <gtk/gtk.h>
#include "savebox.h"

void quitButton_clicked(GtkWidget *widget, gpointer data);
int mainpage(GtkWidget* window, Box* inputCollect);

#endif