#include <gtk/gtk.h>

/* 相关回调函数原型 */
void dialog_button_cancel_callback(GtkWidget *widget, gpointer parents);
/* */

void dialog_button_query_person_diagnose_callback(GtkWidget *widget, gpointer parents)
{
    /* 创建各个控件声明 */
    GtkWidget *dialog;
    GtkWidget *dialog_vbox, *dialog_table;
    GtkWidget *dialog_fixed_1, *dialog_fixed_2, *dialog_fixed_3,
              *dialog_fixed_4, *dialog_fixed_5, *dialog_fixed_6;
    GtkWidget *dialog_check_1, *dialog_check_2, *dialog_check_3,
              *dialog_check_4, *dialog_check_5, *dialog_check_6;
    GtkWidget *dialog_button_ok, *dialog_button_cancel;

    /* 创建窗口 */
    dialog= gtk_dialog_new();
    /* 设置窗口名称 */
    gtk_window_set_title(GTK_WINDOW(dialog), "诊断选项，可多选");
    /* 设置窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    /* 设置窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(dialog), 300, 260);
    gtk_widget_set_size_request(GTK_WIDGET(dialog), 300, 260);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    /* 创建控件框架 */
    dialog_table = gtk_table_new(3, 2, FALSE);
    dialog_fixed_1 = gtk_fixed_new();
    dialog_fixed_2 = gtk_fixed_new();
    dialog_fixed_3 = gtk_fixed_new();
    dialog_fixed_4 = gtk_fixed_new();
    dialog_fixed_5 = gtk_fixed_new();
    dialog_fixed_6 = gtk_fixed_new();
    /* 创建控件 */
    dialog_check_1 = gtk_check_button_new_with_label("精神分裂症");
    dialog_check_2 = gtk_check_button_new_with_label("分裂情感性\n障碍");
    dialog_check_3 = gtk_check_button_new_with_label("偏执性\n精神病");
    dialog_check_4 = gtk_check_button_new_with_label("双相情感\n障碍");
    dialog_check_5 = gtk_check_button_new_with_label("癫痫所致\n精神障碍");
    dialog_check_6 = gtk_check_button_new_with_label("精神发育\n迟滞");
    /* 设置控件默认大小 */
    gtk_widget_set_size_request(dialog_check_1, 100, 40);
    gtk_widget_set_size_request(dialog_check_2, 100, 40);
    gtk_widget_set_size_request(dialog_check_3, 100, 40);
    gtk_widget_set_size_request(dialog_check_4, 100, 40);
    gtk_widget_set_size_request(dialog_check_5, 100, 40);
    gtk_widget_set_size_request(dialog_check_6, 100, 40);
    /* 将控件放入GtkFixed框架 */
    gtk_fixed_put(GTK_FIXED(dialog_fixed_1), GTK_WIDGET(dialog_check_1), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_2), GTK_WIDGET(dialog_check_2), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_3), GTK_WIDGET(dialog_check_3), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_4), GTK_WIDGET(dialog_check_4), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_5), GTK_WIDGET(dialog_check_5), 50, 25);
    gtk_fixed_put(GTK_FIXED(dialog_fixed_6), GTK_WIDGET(dialog_check_6), 25, 25);
    /* 将各个GtkFixed控件放入dialog框架 */
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_3, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_4, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_5, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_table), dialog_fixed_6, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);

    /* 创建“确定”和“取消”按钮 */
    dialog_button_ok = gtk_button_new_with_label("确定");
    dialog_button_cancel = gtk_button_new_with_label("取消");
    /* 设置按钮默认大小 */
    gtk_widget_set_size_request(dialog_button_ok, 75, 25);
    gtk_widget_set_size_request(dialog_button_cancel, 75, 25);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> vbox), dialog_table, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> action_area), dialog_button_ok, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> action_area), dialog_button_cancel, TRUE, TRUE, 0);

    /* 将相关回调函数与 dialog_button* 相关联 */
    g_signal_connect(G_OBJECT(dialog_button_cancel), "clicked", G_CALLBACK(dialog_button_cancel_callback), (gpointer)dialog);
    /* */


    /* 记住使用 dialog 控件的时候要及时显示所有控件 */
    gtk_widget_show_all(dialog_table);
    gtk_widget_show(dialog_button_ok);
    gtk_widget_show(dialog_button_cancel);

    /* 显示对话窗口 */
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

