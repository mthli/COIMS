#include "coims.h"

/* 思考一个问题：
 * 是否需要在对话框中添加更多按钮，
 * 比如“重置”按钮。
 * 暂时不考虑这个问题，搁置一边。
 */

typedef struct _Date {
    int year;
    int month;
    int day;
} Date;

/* 计算距离当年1月1号有多少天的函数 */
int get(Date x)
{
    int month[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int year = 0;
    int day = 0;
    int i = 0;

    year = x.year - 1;
    day = year * 365 + year / 4 - year / 100 + year / 400;
    /* 求出之前闰年的个数，并在2月的天数上相加 */
    if ((x.year % 4 == 0 && x.year % 100 != 0) || (x.year % 400 == 0)) {
        month[1]++;
    }
    /* 计算出总天数 */
    for (i = 0; i < x.month - 1; i++) {
        day += month[i];
    }
    /* 当天应该不算在内 */
    day += x.day - 1;

    return day;
}

/* 计算两个日期之间的差值的函数 */
int diff(Date a, Date b)
{
    int n = 0;

    n = get(b) - get(a);

    return n;
}

int calculate_days(into_year, into_month, into_day, out_year, out_month, out_day)
{
    Date a;
    Date b;
    int n = 0;

    a.year = into_year;
    a.month = into_month;
    a.day = into_day;
    b.year = out_year;
    b.month = out_month;
    b.day = out_day;

    n = diff(a, b);

    return n;
}

void out_choose(GtkWidget *widget, Item *parents)
{
    /* 对话框 */
    GtkWidget *dialog;
    GtkWidget *message_0;
    GtkWidget *message_1;
    GtkWidget *message_2;
    /* 日期 */
    GtkWidget *out_cal;
    int out_year = 0,
        out_month = 0,
        out_day = 0;
    char str[50] = {0},
         str_year[10] = {0},
         str_month[10] = {0},
         str_day[10] = {0};
    time_t timep;
    struct tm *p;
    int now_year = 0,
        now_month = 0,
        now_day = 0;
    /* 日期字符串处理相关 */
    const gchar *into_str;
    char temp_str[50] = {0},
         temp_year[10] = {0},
         temp_month[10] = {0},
         temp_day[10] = {0};
    int into_year = 0,
        into_month = 0,
        into_day = 0;
    char cal_days[10] = {0};
    /* 临时变量 */
    int i = 0,
        j = 0,
        n = 0;

    /* 创建对话框 */
    dialog = gtk_dialog_new_with_buttons(
            "选择出院时间",
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
    out_cal = gtk_calendar_new();
    gtk_box_pack_start(
            GTK_BOX(GTK_DIALOG(dialog) -> vbox),
            out_cal,
            TRUE,
            TRUE,
            0
            );
    gtk_widget_show(out_cal);

    /* 处理事件，注意这里对字符串的处理要求高些 */
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        /* 获取into_button中的字符串 */
        into_str = gtk_button_get_label(GTK_BUTTON((*parents).into_button));
        if (strcmp(into_str, "选择日期") == 0) {
            message_0 = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "请先选择入院时间"
                );
            gtk_widget_destroy(dialog);
            gtk_dialog_run(GTK_DIALOG(message_0));
            gtk_widget_destroy(message_0);
        } else {
            gtk_calendar_get_date(
                    GTK_CALENDAR(out_cal),
                    &out_year,
                    &out_month,
                    &out_day
                    );
            out_month = out_month + 1; /* 因为获取的月份比实际月份小1 */
            /* 获取当前时间 */
            time(&timep);
            p = gmtime(&timep);
            now_year = 1900 + p -> tm_year;
            now_month = 1 + p -> tm_mon;
            now_day = p -> tm_mday;
            /* 错误消息对话框 */
            message_1 = gtk_message_dialog_new(
                    NULL,
                    GTK_DIALOG_MODAL,
                    GTK_MESSAGE_ERROR,
                    GTK_BUTTONS_CLOSE,
                    "出院时间不可能小于入院时间"
                    );
            message_2 = gtk_message_dialog_new(
                    NULL,
                    GTK_DIALOG_MODAL,
                    GTK_MESSAGE_ERROR,
                    GTK_BUTTONS_CLOSE,
                    "出院时间不可能小于今天"
                    );
            /* 开始解析出相应日期；有时间可以研究一下sscanf()函数，可能更简便些 */
            strcpy(temp_str, into_str);
            /* 提取出年份 */
            for (i = 0, j = 0; i < 4; i++, j++) {
                temp_year[j] = temp_str[i];
            }
            /* 提取出月份 */
            while (!('0' <= temp_str[i] && temp_str[i] <= '9')) {
                i++;
            }
            for (j = 0; '0' <= temp_str[i] && temp_str[i] <= '9'; i++, j++) {
                temp_month[j] = temp_str[i];
            }
            /* 提取出日期 */
            while (!('0' <= temp_str[i] && temp_str[i] <= '9')) {
                i++;
            }
            for (j = 0; '0' <= temp_str[i] && temp_str[i] <= '9'; i++, j++) {
                temp_day[j] = temp_str[i];
            }
            /* 把提取出来的字符串转换成数字 */
            sscanf(temp_year, "%d", &into_year);
            sscanf(temp_month, "%d", &into_month);
            sscanf(temp_day, "%d", &into_day);

            /* 判断日期是否合理 */
            if (
                    (into_year > out_year) ||
                    ((into_year == out_year) && (into_month > out_month)) ||
                    ((into_year == out_year) && (into_month == out_month) && (into_day > out_day))
            ) {
                gtk_widget_destroy(dialog);
                gtk_dialog_run(GTK_DIALOG(message_1));
                gtk_widget_destroy(message_1);
            } else if (
                    (out_year > now_year) ||
                    ((out_year == now_year) && (out_month > now_month)) ||
                    ((out_year == now_year) && (out_month == now_month) && (out_day > now_day))
            ) {
                gtk_widget_destroy(dialog);
                gtk_dialog_run(GTK_DIALOG(message_2));
                gtk_widget_destroy(message_2);
            } else {
                sprintf(str_year, "%d", out_year);
                sprintf(str_month, "%d", out_month);
                sprintf(str_day, "%d", out_day);
                strcat(str, str_year);
                strcat(str, "年 ");
                strcat(str, str_month);
                strcat(str, "月 ");
                strcat(str, str_day);
                strcat(str, "日");
                gtk_button_set_label(GTK_BUTTON((*parents).out_button), str);
                /* 开始计算住院天数 */
                n = calculate_days(into_year, into_month, into_day, out_year, out_month, out_day);
                sprintf(cal_days, "%d", n);
                gtk_entry_set_text(GTK_ENTRY((*parents).days_entry), cal_days);
                gtk_widget_show((*parents).out_button);
                gtk_widget_show((*parents).days_entry);
                gtk_widget_destroy(dialog);
            }
        }
    } else {
        gtk_widget_destroy(dialog);
    }
}
