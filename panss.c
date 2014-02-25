#include "coims.h"

void panss(GtkWidget *widght, Item *parents)
{
    GtkWidget *message;
    const gchar *get_inps;
    const gchar *get_outps;
    char str_inps[10] = {0},
         str_outps[10] = {0};
    int judge = 0;
    double dou_inps = 0,
        dou_outps = 0,
        persent = 0;
    char str_per[20] = {0};
    int i = 0,
        j = 0;

    /* 获取字符串 */
    get_inps = gtk_entry_get_text(GTK_ENTRY((*parents).inps_entry));
    get_outps = gtk_entry_get_text(GTK_ENTRY((*parents).outps_entry));

    /* 对字符串进行处理 */
    strcpy(str_inps, get_inps);
    strcpy(str_outps, get_outps);
    /* 检测输入是否正确 */
    judge = 0;
    for (i = 0; i < strlen(str_inps); i++) {
        if (!('0' <= str_inps[i] && str_inps[i] <= '9')) {
            judge = 1;
            break;
        }
    }
    for (i = 0; i < strlen(str_outps); i++) {
        if (!('0' <= str_outps[i] && str_outps[i] <= '9')) {
            judge = 1;
            break;
        }
    }
    /* 如果格式错误则出现提示框，
     * 显然目前还不完善，应该在键入的时候判断输入是否有效，
     * 不过这个问题暂时搁置一边
     */
    if (judge == 1) {
        message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "入院评分或出院评分输入错误"
                );
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    } else {
        sscanf(str_inps, "%lf", &dou_inps);
        sscanf(str_outps, "%lf", &dou_outps);
        /* 0不能当分母 */
        if (dou_inps == 0) {
            message = gtk_message_dialog_new(
                        NULL,
                    GTK_DIALOG_MODAL,
                    GTK_MESSAGE_ERROR,
                    GTK_BUTTONS_CLOSE,
                    "入院评分或出院评分输入错误"
                    );
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        } else {
            persent = (dou_inps - dou_outps) / dou_inps * 100;
            sprintf(str_per, "%.2lf", persent);
            strcat(str_per, "%");
            gtk_button_set_label(
                    GTK_BUTTON((*parents).persent_button),
                    str_per
                    );
            gtk_widget_show((*parents).persent_button);
        }
    }
}

