#include <gtk/gtk.h>
#include <stdio.h>

/* 相关回调函数原型 */
/* */

void dialog_button_query_person_photo_callback(GtkWidget *widget, gpointer parents)
{
    /* 文件选择对话框声明 */
    GtkWidget *dialog;
    /* image 控件，放置于传入的 button 控件之中 */
    GtkWidget *new_photo, *old_photo;
    GdkPixbuf *new_photo_pixbuf;
    gint choose_photo_width, choose_photo_height;
    gint new_photo_width, new_photo_height;
    /* photo_path 为照片路径 */
    gchar *choose_photo_path;
    /* 文件操作相关声明 */
    FILE *fp;

    /* 创建文件选择对话框 */
    dialog = gtk_file_chooser_dialog_new("选择照片", NULL, GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "确定", GTK_RESPONSE_ACCEPT,
                                         "取消", GTK_RESPONSE_CANCEL, NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        if ((old_photo = gtk_bin_get_child(GTK_BIN(parents))) == NULL) {
            /* 获取被选择的照片路径 */
            choose_photo_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            /* 创建照片 */
            new_photo = gtk_image_new_from_file(choose_photo_path);
            /* 获取被选择的照片的 pixbuf，用于缩放 */
            new_photo_pixbuf = gtk_image_get_pixbuf (GTK_IMAGE(new_photo));
            /* 获取原始照片资料 */
            choose_photo_width = gdk_pixbuf_get_width(new_photo_pixbuf);
            choose_photo_height = gdk_pixbuf_get_height(new_photo_pixbuf);
            /* 设置缩放系数 */
            new_photo_width = 100;
            new_photo_height = ((double)new_photo_width / choose_photo_width) * choose_photo_height;
            /* 开始进行缩放 */
            new_photo_pixbuf = gdk_pixbuf_scale_simple(new_photo_pixbuf, new_photo_width, new_photo_height, GDK_INTERP_BILINEAR);
            gtk_image_set_from_pixbuf(GTK_IMAGE(new_photo), new_photo_pixbuf);
            /* 将缩放得到的最终照片加入到界面之中 */
            gtk_container_add(GTK_CONTAINER(parents), new_photo);
            gtk_widget_show(new_photo);
            /* 将原始照片的绝对路径写入临时文本，以后有用 */
            fp = fopen("temp_query_person_photo", "w+");
            fputs(choose_photo_path, fp);
            fclose(fp);
            gtk_widget_destroy(dialog);
        } else {
            /* 移除之前选中的照片 */
            gtk_container_remove(GTK_CONTAINER(parents), old_photo);
             /* 获取被选择的照片路径 */
            choose_photo_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            /* 创建照片 */
            new_photo = gtk_image_new_from_file(choose_photo_path);
            /* 获取被选择的照片的 pixbuf，用于缩放 */
            new_photo_pixbuf = gtk_image_get_pixbuf (GTK_IMAGE(new_photo));
            /* 获取原始照片资料 */
            choose_photo_width = gdk_pixbuf_get_width(new_photo_pixbuf);
            choose_photo_height = gdk_pixbuf_get_height(new_photo_pixbuf);
            /* 设置缩放系数 */
            new_photo_width = 100;
            new_photo_height = ((double)new_photo_width / choose_photo_width) * choose_photo_height;
            /* 开始进行缩放 */
            new_photo_pixbuf = gdk_pixbuf_scale_simple(new_photo_pixbuf, new_photo_width, new_photo_height, GDK_INTERP_BILINEAR);
            gtk_image_set_from_pixbuf(GTK_IMAGE(new_photo), new_photo_pixbuf);
            /* 将缩放得到的最终照片加入到界面之中 */
            gtk_container_add(GTK_CONTAINER(parents), new_photo);
            gtk_widget_show(new_photo);
            /* 将原始照片的绝对路径写入临时文本，以后有用 */
            fp = fopen("temp_query_person_photo", "w+");
            fputs(choose_photo_path, fp);
            fclose(fp);
            gtk_widget_destroy(dialog);
        }
    }
    else
        gtk_widget_destroy(dialog);
}


