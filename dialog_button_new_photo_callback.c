#include <gtk/gtk.h>

/* 相关回调函数原型 */
/* */

void dialog_button_new_photo_callback(GtkWidget *widget, gpointer parents)
{
    /* 文件选择对话框声明 */
    GtkWidget *dialog;

    /* 创建文件选择对话框 */ /* 注意一下是否使用 NULL */
    dialog = gtk_file_chooser_dialog_new("选择照片", NULL, GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "确定", GTK_RESPONSE_ACCEPT,
                                         "取消", GTK_RESPONSE_CANCEL, NULL);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

