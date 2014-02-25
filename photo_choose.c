#include "coims.h"

/* 获取文件路径后对文件后缀名进行解析，
 * 如果不是图片的格式，则错误提醒；
 * 如果是图片，则直接通过。
 */

void photo_choose(GtkWidget *widget, Item *parents)
{
    /* 对话框 */
    GtkWidget *dialog;
    GtkWidget *message;
    /* 照片相关 */
    GtkWidget *new_photo;
    GdkPixbuf *photo_pixbuf;
    int choose_photo_width = 0,
        choose_photo_height = 0,
        new_photo_width = 0,
        new_photo_height = 0;
    /* 字符串相关 */
    gchar *choose_photo_path;
    char str_path[256] = {0};
    char *is_bmp,
         *is_jpeg,
         *is_jpg,
         *is_png;
    /* 文件相关 */
    FILE *fp;

    /* 创建文件选择框 */
    dialog = gtk_file_chooser_dialog_new(
            "选择照片",
            NULL,
            GTK_FILE_CHOOSER_ACTION_OPEN,
            "确定", GTK_RESPONSE_ACCEPT,
            "取消", GTK_RESPONSE_CANCEL,
            NULL
            );
    /* 错误消息对话框 */
    message = gtk_message_dialog_new(
            NULL,
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_CLOSE,
            "文件格式错误"
            );

    /* 处理事件 */
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        choose_photo_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        /* 通过后缀名检测被选中的文件是否为图片，
         * 支持bmp，jpeg，jpg和png；
         * 注意：
         * 通过后缀名判断文件格式显然有缺陷，在windows调用api更为合理，不过暂时这样做先；
         * 显然用strsrt()的方法并不完美，不过先暂时这样做先。
         */
        strcpy(str_path, choose_photo_path);
        is_bmp = strstr(str_path, ".bmp");
        is_jpeg = strstr(str_path, ".jpeg");
        is_jpg = strstr(str_path, ".jpg");
        is_png = strstr(str_path, ".png");
        if(is_bmp == NULL && is_jpeg == NULL && is_jpg == NULL && is_png == NULL) {
            gtk_widget_destroy(dialog);
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        } else {
            new_photo = gtk_image_new_from_file(choose_photo_path);
            /* 获取被选择的照片的 pixbuf，用于缩放 */
            photo_pixbuf = gtk_image_get_pixbuf(GTK_IMAGE(new_photo));
            /* 获取被选中的照片的信息 */
            choose_photo_width = gdk_pixbuf_get_width(photo_pixbuf);
            choose_photo_height = gdk_pixbuf_get_height(photo_pixbuf);
            /* 设置缩放系数 */
            new_photo_width = 80;
            new_photo_height = ((double)new_photo_width / choose_photo_width) * choose_photo_height;
            /* 开始进行缩放 */
            photo_pixbuf = gdk_pixbuf_scale_simple(
                    photo_pixbuf,
                    new_photo_width,
                    new_photo_height,
                    GDK_INTERP_BILINEAR
                    );
            gtk_image_set_from_pixbuf(
                    GTK_IMAGE(new_photo),
                    photo_pixbuf
                    );
            /* 将缩放得到的照片加入到界面之中 */
            gtk_button_set_image(
                    GTK_BUTTON((*parents).photo_button),
                    new_photo
                    );
            /* 将原始照片复制到相对目录的文件夹下，这部分暂时不做 */
            /* 将原始照片的绝对路径写入文本，以后有用 */
            fp = fopen("photo_path.txt", "w+");
            fputs(choose_photo_path, fp);
            fclose(fp);
            /* gchar *需要释放 */
            g_free(choose_photo_path);
            choose_photo_path = NULL;
            gtk_widget_destroy(dialog);
        }
    } else {
        gtk_widget_destroy(dialog);
    }
}
