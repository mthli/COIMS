#include <gtk/gtk.h>

void dialog_button_cancel_callback(GtkWidget *widget, gpointer parents)
{
    gtk_widget_destroy(GTK_WIDGET(parents));
}
