#include <gtk/gtk.h>

/* 相关回调函数原型 */
void dialog_button_cancel_callback(GtkWidget *widget, gpointer parents);
/* */

void dialog_button_query_treat_diagnose_callback(GtkWidget *widget, gpointer parents)
{
    /* 创建各个控件声明 */
    GtkWidget *dialog;
    GtkWidget *dialog_vbox, *dialog_table;
    GtkWidget *dialog_fixed_1, *dialog_fixed_2, *dialog_fixed_3,
              *dialog_fixed_4, *dialog_fixed_5, *dialog_fixed_6,
              *dialog_fixed_7, *dialog_fixed_8, *dialog_fixed_9,
              *dialog_fixed_10;
    GtkWidget *dialog_check_1, *dialog_check_2, *dialog_check_3,
              *dialog_check_4, *dialog_check_5, *dialog_check_6,
              *dialog_check_7, *dialog_check_8, *dialog_check_9,
              *dialog_check_10;

    /* 创建窗口 */ /* 注意是否需要用 NULL */
    dialog= gtk_dialog_new_with_buttons("诊断选项，可多选",
                                        GTK_WINDOW(parents), GTK_DIALOG_MODAL,
                                        "确定",  GTK_RESPONSE_ACCEPT,
                                        "取消", GTK_RESPONSE_REJECT,
                                        NULL);
    /* 设置窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    /* 设置窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(dialog), 300, 380);
    gtk_widget_set_size_request(GTK_WIDGET(dialog), 300, 380);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    /* 创建控件框架 */
    dialog_table = gtk_table_new(5, 2, FALSE);
    dialog_fixed_1 = gtk_fixed_new();
    dialog_fixed_2 = gtk_fixed_new();
    dialog_fixed_3 = gtk_fixed_new();
    dialog_fixed_4 = gtk_fixed_new();
    dialog_fixed_5 = gtk_fixed_new();
    dialog_fixed_6 = gtk_fixed_new();
    dialog_fixed_7 = gtk_fixed_new();
    dialog_fixed_8 = gtk_fixed_new();
    dialog_fixed_9 = gtk_fixed_new();
    dialog_fixed_10 = gtk_fixed_new();
    /* 创建控件 */
    dialog_check_1 = gtk_check_button_new_with_label("精神分裂症");
    dialog_check_2 = gtk_check_button_new_with_label("分裂情感性\n障碍");
    dialog_check_3 = gtk_check_button_new_with_label("偏执性\n精神病");
    dialog_check_4 = gtk_check_button_new_with_label("双相情感\n障碍");
    dialog_check_5 = gtk_check_button_new_with_label("癫痫所致\n精神障碍");
    dialog_check_6 = gtk_check_button_new_with_label("精神发育\n迟滞");
    dialog_check_7 = gtk_check_button_new_with_label("兴奋症状");
    dialog_check_8 = gtk_check_button_new_with_label("偏执状态");
    dialog_check_9 = gtk_check_button_new_with_label("缄默状态");
    dialog_check_10 = gtk_check_button_new_with_label("焦虑状态");
    /* 设置控件默认大小 */
    gtk_widget_set_size_request(dialog_check_1, 100, 40);
    gtk_widget_set_size_request(dialog_check_2, 100, 40);
    gtk_widget_set_size_request(dialog_check_3, 100, 40);
    gtk_widget_set_size_request(dialog_check_4, 100, 40);
    gtk_widget_set_size_request(dialog_check_5, 100, 40);
    gtk_widget_set_size_request(dialog_check_6, 100, 40);
    gtk_widget_set_size_request(dialog_check_7, 100, 40);
    gtk_widget_set_size_request(dialog_check_8, 100, 40);
    gtk_widget_set_size_request(dialog_check_9, 100, 40);
    gtk_widget_set_size_request(dialog_check_10, 100, 40);
    /* 将控件放入GtkFixed框架 */
    gtk_fixed_put(GTK_FIXED(dialog_fixed_1), GTK_WIDGET(dialog_check_1), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_2), GTK_WIDGET(dialog_check_2), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_3), GTK_WIDGET(dialog_check_3), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_4), GTK_WIDGET(dialog_check_4), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_5), GTK_WIDGET(dialog_check_5), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_6), GTK_WIDGET(dialog_check_6), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_7), GTK_WIDGET(dialog_check_7), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_8), GTK_WIDGET(dialog_check_8), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_9), GTK_WIDGET(dialog_check_9), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_10), GTK_WIDGET(dialog_check_10), 25, 25);
    /* 将各个GtkFixed控件放入dialog框架 */
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_3, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_4, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_5, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_6, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_7, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_8, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_9, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_10, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> vbox), dialog_table, TRUE, TRUE, 0);
    gtk_widget_show_all(dialog_table);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        /* 注意添加相应内容 */
        /* */
        gtk_widget_destroy(dialog);
    } else
        gtk_widget_destroy(dialog);
}

