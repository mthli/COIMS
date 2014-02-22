#include "coims.h"

void help_about(GtkWidget *widget, gpointer parents)
{
    GtkWidget *about;

    about = gtk_about_dialog_new();
    gtk_about_dialog_set_name(
            GTK_ABOUT_DIALOG(about), 
            "公共卫生管理系统"
            );
    gtk_about_dialog_set_version(
            GTK_ABOUT_DIALOG(about), 
            "1.0"
            );
    gtk_about_dialog_set_copyright(
            GTK_ABOUT_DIALOG(about), 
            "(c)2013-2014 西电开源社区"
            );
    gtk_about_dialog_set_website(
            GTK_ABOUT_DIALOG(about),
            "https://github.com/newmlee/COIMS"
            );
    
    gtk_dialog_run(GTK_DIALOG(about));
    gtk_widget_destroy(about);
}
