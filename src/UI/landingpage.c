#include <landingpage.h>
#include <string.h>
#include <savebox.h>
#include "mainpage.h"

Box* inputCollectL;
GtkWidget* window;
char* caixa;

void name_true(GtkWidget *widget, gpointer data){
    

}

// Função para lidar com o clique no botão
void button_clicked(GtkWidget *widget, gpointer data) {
    // Obter o texto do campo de entrada
    const gchar *name = gtk_entry_get_text(GTK_ENTRY(data));
    
    // Exibir uma mensagem com o nome inserido
    g_print("Nome: %s\n", name);

    inputCollectL->name = (char*)name;

    char* caixa = malloc(sizeof(100));
    strcpy(caixa, inputCollectL->name);

    g_print("Nome Após guardar: %s\n", caixa);

    //g_print("Fora: %s\n", inputCollect->name);

    
    g_print("(1)ptr: %p \n", inputCollectL);
        
    for (size_t i = 0; inputCollectL->name[i]; i++){
        g_print("%d ", inputCollectL->name[i]);
        /* code */
    }

    g_print("Cena: %s\n", caixa);
    g_print("Teste2: %s\n", inputCollectL->name);
    
    mainpage (window, inputCollectL);
    //gtk_container_foreach(window, (GtkCallback)gtk_widget_destroy, NULL);
}

int landing_page(GtkWidget* windowR, Box* inputCollectR){

    window = windowR;
    inputCollectL = inputCollectR;

    // Criar um layout vertical para organizar os widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Título centralizado
    GtkWidget *label = gtk_label_new("Bem Vindo");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    // Campo de entrada e label
    GtkWidget *name_entry = gtk_entry_new();
    GtkWidget *name_label = gtk_label_new("Nome:");
    gtk_box_pack_start(GTK_BOX(vbox), name_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), name_entry, TRUE, TRUE, 0);

    // Botão
    GtkWidget *button = gtk_button_new_with_label("Submeter");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), name_entry);
    g_signal_connect(button, "clicked", G_CALLBACK(name_true), name_entry);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    // Mostrar todos os widgets
    gtk_widget_show_all(window);
    
/*     else{
         gtk_main_quit();
    }
     */
    return 0;
}
