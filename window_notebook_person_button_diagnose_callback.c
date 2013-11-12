#include <gtk/gtk.h>

void window_notebook_person_button_diagnose_callback(GtkWidget *widget, gpointer main_window)
{
    /* 创建各个控件声明 */
    GtkWidget *window;
    GtkWidget *window_vbox, *window_table;
    GtkWidget *window_fixed_1, *window_fixed_2, *window_fixed_3,
              *window_fixed_4, *window_fixed_5, *window_fixed_6;
    GtkWidget *window_check_1, *window_check_2, *window_check_3,
              *window_check_4, *window_check_5, *window_check_6;
    GtkWidget *window_edit_hbox, *window_edit_alignment, *window_edit_alignment_hbox;
    GtkWidget *window_edit_button_ok, *window_edit_button_cancel;

    /* 创建窗口 */
    window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* 设置窗口名称 */
    gtk_window_set_title(GTK_WINDOW(window), "诊断选项（可多选）");
    /* 设置窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    /* 设置窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 240);
    gtk_widget_set_size_request(GTK_WIDGET(window), 300, 240);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    /* 将destroy信号与主窗口连接 */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建window_vbox框架 */
    window_vbox = gtk_vbox_new(FALSE, 0);

    /* 创建控件框架 */
    window_table = gtk_table_new(3, 2, FALSE);
    window_fixed_1 = gtk_fixed_new();
    window_fixed_2 = gtk_fixed_new();
    window_fixed_3 = gtk_fixed_new();
    window_fixed_4 = gtk_fixed_new();
    window_fixed_5 = gtk_fixed_new();
    window_fixed_6 = gtk_fixed_new();
    /* 创建控件 */
    window_check_1 = gtk_check_button_new_with_label("精神分裂症");
    window_check_2 = gtk_check_button_new_with_label("分裂情感性\n障碍");
    window_check_3 = gtk_check_button_new_with_label("偏执性\n精神病");
    window_check_4 = gtk_check_button_new_with_label("双相情感\n障碍");
    window_check_5 = gtk_check_button_new_with_label("癫痫所致\n精神障碍");
    window_check_6 = gtk_check_button_new_with_label("精神发育\n迟滞");
    /* 设置控件默认大小 */
    gtk_widget_set_size_request(window_check_1, 100, 40);
    gtk_widget_set_size_request(window_check_2, 100, 40);
    gtk_widget_set_size_request(window_check_3, 100, 40);
    gtk_widget_set_size_request(window_check_4, 100, 40);
    gtk_widget_set_size_request(window_check_5, 100, 40);
    gtk_widget_set_size_request(window_check_6, 100, 40);
    /* 将控件放入GtkFixed框架 */
    gtk_fixed_put(GTK_FIXED(window_fixed_1), GTK_WIDGET(window_check_1), 50, 25);
    gtk_fixed_put(GTK_FIXED(window_fixed_2), GTK_WIDGET(window_check_2), 25, 25);
    gtk_fixed_put(GTK_FIXED(window_fixed_3), GTK_WIDGET(window_check_3), 50, 25);
    gtk_fixed_put(GTK_FIXED(window_fixed_4), GTK_WIDGET(window_check_4), 25, 25);
    gtk_fixed_put(GTK_FIXED(window_fixed_5), GTK_WIDGET(window_check_5), 50, 25);
    gtk_fixed_put(GTK_FIXED(window_fixed_6), GTK_WIDGET(window_check_6), 25, 25);
    /* 将各个GtkFixed控件放入window框架 */
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_3, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_4, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_5, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_table), window_fixed_6, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);

    /* 创建“确定”和“取消”按钮 */
    window_edit_button_ok = gtk_button_new_with_label("确定");
    window_edit_button_cancel = gtk_button_new_with_label("取消");
    /* 设置按钮默认大小 */
    gtk_widget_set_size_request(window_edit_button_ok, 75, 25);
    gtk_widget_set_size_request(window_edit_button_cancel, 75, 25);
    /* 创建对齐框架 */
    window_edit_hbox = gtk_hbox_new(FALSE, 0);
    window_edit_alignment = gtk_alignment_new(1, 0, 0, 0);
    window_edit_alignment_hbox = gtk_hbox_new(FALSE, 0);
    /* 将编辑按钮放入h_box之中 */ /* 注意一下到底用TRUE还是FALSE */
    gtk_box_pack_start(GTK_BOX(window_edit_alignment_hbox), window_edit_button_ok, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_edit_alignment_hbox), window_edit_button_cancel, FALSE, FALSE, 0);
    /* 将window_edit_alignment_hbox放入对齐框架之中 */
    gtk_container_add(GTK_CONTAINER(window_edit_alignment), window_edit_alignment_hbox);
    /* 将window_edit_alignment放入window_edit_hbox之中 */
    gtk_box_pack_start(GTK_BOX(window_edit_hbox), window_edit_alignment, TRUE, TRUE, 0);

    /* 将hbox、table加入到vbox之中 */
    gtk_box_pack_start(GTK_BOX(window_vbox), window_table, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(window_vbox), window_edit_hbox, FALSE, FALSE, 0);
    /* 需将vbox放入window之中 */
    gtk_container_add(GTK_CONTAINER(window), window_vbox);
    /* 显示对话窗口 */
    gtk_widget_show_all(window);
}

