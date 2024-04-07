#include "mainpage.h"

#include <savebox.h>

Box* inputCollectM;

// Função para lidar com o clique no botão
void quitButton_clicked(GtkWidget *widget, gpointer data)
{
    // Fechar a aplicação
    gtk_main_quit();
}

int mainpage(GtkWidget *window, Box *inputCollectR){

    inputCollectM = inputCollectR;

    char* nome = malloc(sizeof(100));

    strcpy(nome, inputCollectM->name);
    g_print("Teste:%s\n", inputCollectM->name);
    g_print("Olá %s\n", nome);

    gtk_container_foreach(GTK_CONTAINER(window), (GtkCallback)gtk_widget_destroy, NULL);

    // Criar um layout vertical para organizar os widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Criar um layout horizontal para organizar a foto do perfil e a mensagem
    GtkWidget *hbox_profile = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox), hbox_profile, TRUE, TRUE, 0);

    // Carregar a imagem do perfil (substitua "profile_pic.jpg" pelo caminho da imagem)
    GtkWidget *image = gtk_image_new_from_file("src/UI/profile_pic2.jpg");
    gtk_box_pack_start(GTK_BOX(hbox_profile), image, FALSE, FALSE, 0);

    // Criar uma label para a mensagem de boas-vindas
    char welcome_message[100];
    // Substitua "Cat" pela variável que contém o nome do usuário
    sprintf(welcome_message, "Hello %s Cat", nome);
    GtkWidget *label_welcome = gtk_label_new(welcome_message);
    gtk_box_pack_start(GTK_BOX(hbox_profile), label_welcome, TRUE, TRUE, 0);

    // Criar uma label para a classe do usuário
    char user_class[50];
    // Substitua "Student" pela variável que contém a classe do usuário
    sprintf(user_class, "%s", "Student");
    GtkWidget *label_class = gtk_label_new(user_class);
    gtk_box_pack_start(GTK_BOX(vbox), label_class, TRUE, TRUE, 0);


    // Criar uma label para a idade do usuário
    int user_age = 25; // Substitua 25 pela idade do usuário
    char age_message[50];
    sprintf(age_message, "%d years old", user_age);
    GtkWidget *label_age = gtk_label_new(age_message);
    gtk_box_pack_start(GTK_BOX(vbox), label_age, TRUE, TRUE, 0);

    // Criar uma caixa de texto grande
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    // Aqui você pode adicionar o texto que desejar ao buffer da caixa de texto
    gtk_box_pack_start(GTK_BOX(vbox), text_view, TRUE, TRUE, 0);

    // Mostrar todos os widgets
    gtk_widget_show_all(window);

    // Entrar no loop principal do GTK
    gtk_main();

    return 0;
}