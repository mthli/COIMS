#include "coims.h"

void into_choose(GtkWidget *widget, Item *parents)
{
    /* dialog对话框 */
    GtkWidget *dialog;
    GtkWidget *message;
    /* 日期 */
    GtkWidget *into_cal;
    int int_year = 0,
        int_month = 0,
        int_day = 0;
    char str[50] = {0},
         str_year[10] = {0},
         str_month[10] = {0},
         str_day[10] = {0};
    time_t timep;
    struct tm *p;
    int now_year = 0,
        now_month = 0,
        now_day = 0;

    /* 创建对话框 */
    dialog = gtk_dialog_new_with_buttons(
            "选择入院时间",
            NULL, GTK_DIALOG_MODAL,
            "确定", GTK_RESPONSE_ACCEPT,
            "取消", GTK_RESPONSE_REJECT,
            NULL
            );
    gtk_window_set_position(
            GTK_WINDOW(dialog),
            GTK_WIN_POS_CENTER
            );
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    /* 创建日历选择框 */
    into_cal = gtk_calendar_new();
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> vbox),
                       into_cal,
                       TRUE,
                       TRUE,
                       0);
    gtk_widget_show(into_cal);

    /* 处理事件 */
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        gtk_calendar_get_date(
                GTK_CALENDAR(into_cal),
                &int_year,
                &int_month,
                &int_day
                );
        int_month = int_month + 1; /* 因为获取的月份比实际月份小1 */
        /* 获取当前时间 */
        time(&timep);
        p = gmtime(&timep);
        now_year = 1900 + p -> tm_year;
        now_month = 1 + p -> tm_mon;
        now_day = p -> tm_mday;
        /* 错误消息提示框 */
        message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "入院时间不可能超过今天"
                );
        /* 开始进行判断 */
        if (
                (int_year > now_year) ||
                (int_year == now_year && int_month > now_month) ||
                (int_year == now_year && int_month == now_month && int_day > now_day)
           ) {
            gtk_widget_destroy(dialog);
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        } else {
            sprintf(str_year, "%d", int_year);
            sprintf(str_month, "%d", int_month);
            sprintf(str_day, "%d", int_day);
            strcat(str, str_year);
            strcat(str, "年");
            strcat(str, str_month);
            strcat(str, "月");
            strcat(str, str_day);
            strcat(str, "日");
            gtk_button_set_label(
                    GTK_BUTTON((*parents).into_button),
                    str
                    );
            gtk_widget_show_now((*parents).into_button);
            gtk_widget_destroy(dialog);
        }
    } else {
        gtk_widget_destroy(dialog);
    }
}
