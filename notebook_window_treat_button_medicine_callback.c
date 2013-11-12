#include <gtk/gtk.h>

void notebook_window_treat_button_medicine_callback(GtkWidget *widget, gpointer main_window)
{
    /* 窗口控件声明 */
    GtkWidget *window;
    /* 窗口v_box声明 */
    GtkWidget *window_v_box;
    /* window_notebook控件声明 */
    GtkWidget *window_notebook,
              *window_notebook_psychosis_label, *window_notebook_depression_label,
              *window_notebook_anxiety_label, *window_notebook_heart_label,
              *window_notebook_psychosis_scrolled, *window_notebook_depression_scrolled,
              *window_notebook_anxiety_scrolled, *window_notebook_heart_scrolled;
    GtkWidget *window_notebook_psychosis_v_box, *window_notebook_depression_v_box,
              *window_notebook_anxiety_v_box, *window_notebook_heart_v_box,
              *window_notebook_psychosis_table, *window_notebook_depression_table,
              *window_notebook_anxiety_table, *window_notebook_heart_table;
    GtkWidget *window_notebook_psychosis_fixed_1, *window_notebook_psychosis_fixed_2, *window_notebook_psychosis_fixed_3,
              *window_notebook_psychosis_fixed_4, *window_notebook_psychosis_fixed_5, *window_notebook_psychosis_fixed_6,
              *window_notebook_psychosis_fixed_7, *window_notebook_psychosis_fixed_8, *window_notebook_psychosis_fixed_9,
              *window_notebook_psychosis_fixed_10, *window_notebook_psychosis_fixed_11, *window_notebook_psychosis_fixed_12,
              *window_notebook_psychosis_fixed_13, *window_notebook_psychosis_fixed_14, *window_notebook_psychosis_fixed_15,
              *window_notebook_psychosis_fixed_16, *window_notebook_psychosis_fixed_17, *window_notebook_psychosis_fixed_18,
              *window_notebook_depression_fixed_1, *window_notebook_depression_fixed_2, *window_notebook_depression_fixed_3,
              *window_notebook_depression_fixed_4, *window_notebook_depression_fixed_5, *window_notebook_depression_fixed_6,
              *window_notebook_depression_fixed_7, *window_notebook_depression_fixed_8, *window_notebook_depression_fixed_9,
              *window_notebook_depression_fixed_10, *window_notebook_depression_fixed_11, *window_notebook_depression_fixed_12,
              *window_notebook_depression_fixed_13, *window_notebook_depression_fixed_14, *window_notebook_depression_fixed_15,
              *window_notebook_depression_fixed_16, *window_notebook_depression_fixed_17, *window_notebook_depression_fixed_18,
              *window_notebook_anxiety_fixed_1, *window_notebook_anxiety_fixed_2, *window_notebook_anxiety_fixed_3,
              *window_notebook_anxiety_fixed_4, *window_notebook_anxiety_fixed_5, *window_notebook_anxiety_fixed_6,
              *window_notebook_anxiety_fixed_7, *window_notebook_anxiety_fixed_8,
              *window_notebook_heart_fixed_1, *window_notebook_heart_fixed_2, *window_notebook_heart_fixed_3,
              *window_notebook_heart_fixed_4, *window_notebook_heart_fixed_5, *window_notebook_heart_fixed_6,
              *window_notebook_heart_fixed_7, *window_notebook_heart_fixed_8;
    GtkWidget *window_notebook_psychosis_check_1, *window_notebook_psychosis_check_2,
              *window_notebook_psychosis_check_3, *window_notebook_psychosis_check_4,
              *window_notebook_psychosis_check_5, *window_notebook_psychosis_check_6,
              *window_notebook_psychosis_check_7, *window_notebook_psychosis_check_8,
              *window_notebook_psychosis_check_9,
              *window_notebook_depression_check_1, *window_notebook_depression_check_2,
              *window_notebook_depression_check_3, *window_notebook_depression_check_4,
              *window_notebook_depression_check_5, *window_notebook_depression_check_6,
              *window_notebook_depression_check_7, *window_notebook_depression_check_8,
              *window_notebook_depression_check_9,
              *window_notebook_anxiety_check_1, *window_notebook_anxiety_check_2,
              *window_notebook_anxiety_check_3, *window_notebook_anxiety_check_4,
              *window_notebook_heart_check_1, *window_notebook_heart_check_2,
              *window_notebook_heart_check_3, *window_notebook_heart_check_4;
    GtkWidget *window_notebook_psychosis_entry_1, *window_notebook_psychosis_entry_2,
              *window_notebook_psychosis_entry_3, *window_notebook_psychosis_entry_4,
              *window_notebook_psychosis_entry_5, *window_notebook_psychosis_entry_6,
              *window_notebook_psychosis_entry_7, *window_notebook_psychosis_entry_8,
              *window_notebook_psychosis_entry_9,
              *window_notebook_depression_entry_1, *window_notebook_depression_entry_2,
              *window_notebook_depression_entry_3, *window_notebook_depression_entry_4,
              *window_notebook_depression_entry_5, *window_notebook_depression_entry_6,
              *window_notebook_depression_entry_7, *window_notebook_depression_entry_8,
              *window_notebook_depression_entry_9,
              *window_notebook_anxiety_entry_1, *window_notebook_anxiety_entry_2,
              *window_notebook_anxiety_entry_3, *window_notebook_anxiety_entry_4,
              *window_notebook_heart_entry_1, *window_notebook_heart_entry_2,
              *window_notebook_heart_entry_3, *window_notebook_heart_entry_4;
    /* 底部按钮部分声明 */
    GtkWidget *window_edit_h_box;
    GtkWidget *window_edit_alignment, *window_edit_alignment_h_box;
    GtkWidget *window_edit_button_ok, *window_edit_button_cancel;

    /* 创建窗口部件 */
    window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* 设置窗口名称 */
    gtk_window_set_title(GTK_WINDOW(window), "药物选择（可多选）");
    /* 设置窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    /* 设置窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_widget_set_size_request(GTK_WIDGET(window), 640, 480);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    /* 将destroy信号与主窗口连接 */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建窗口v_box框架 */
    window_v_box = gtk_vbox_new(FALSE, 0);

    /* 创建notebook控件 */
    window_notebook = gtk_notebook_new();
    /* 设置标签页文字 */
    window_notebook_psychosis_label = gtk_label_new("抗精神病药物");
    window_notebook_depression_label = gtk_label_new("抗抑郁药物");
    window_notebook_anxiety_label = gtk_label_new("抗焦虑药物");
    window_notebook_heart_label = gtk_label_new("心境稳定剂");
    /* 设置标签页为底部显示 */
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(window_notebook), GTK_POS_BOTTOM);
    /* 创建滚动窗口 */
    window_notebook_psychosis_scrolled = gtk_scrolled_window_new(NULL, NULL);
    window_notebook_depression_scrolled = gtk_scrolled_window_new(NULL, NULL);
    window_notebook_anxiety_scrolled = gtk_scrolled_window_new(NULL, NULL);
    window_notebook_heart_scrolled = gtk_scrolled_window_new(NULL, NULL);
    /* 设置滚动窗口 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(window_notebook_psychosis_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(window_notebook_depression_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(window_notebook_anxiety_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(window_notebook_heart_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    /* 创建window_notebook*内部框架 */
    window_notebook_psychosis_v_box = gtk_vbox_new(FALSE, 0);
    window_notebook_depression_v_box = gtk_vbox_new(FALSE, 0);
    window_notebook_anxiety_v_box = gtk_vbox_new(FALSE, 0);
    window_notebook_heart_v_box = gtk_vbox_new(FALSE, 0);
    window_notebook_psychosis_table = gtk_table_new(5, 4, FALSE);
    window_notebook_depression_table = gtk_table_new(5, 4, FALSE);
    window_notebook_anxiety_table = gtk_table_new(2, 4, FALSE);
    window_notebook_heart_table = gtk_table_new(2, 4, FALSE);
    window_notebook_psychosis_fixed_1 = gtk_fixed_new();
    window_notebook_psychosis_fixed_2 = gtk_fixed_new();
    window_notebook_psychosis_fixed_3 = gtk_fixed_new();
    window_notebook_psychosis_fixed_4 = gtk_fixed_new();
    window_notebook_psychosis_fixed_5 = gtk_fixed_new();
    window_notebook_psychosis_fixed_6 = gtk_fixed_new();
    window_notebook_psychosis_fixed_7 = gtk_fixed_new();
    window_notebook_psychosis_fixed_8 = gtk_fixed_new();
    window_notebook_psychosis_fixed_9 = gtk_fixed_new();
    window_notebook_psychosis_fixed_10 = gtk_fixed_new();
    window_notebook_psychosis_fixed_11 = gtk_fixed_new();
    window_notebook_psychosis_fixed_12 = gtk_fixed_new();
    window_notebook_psychosis_fixed_13 = gtk_fixed_new();
    window_notebook_psychosis_fixed_14 = gtk_fixed_new();
    window_notebook_psychosis_fixed_15 = gtk_fixed_new();
    window_notebook_psychosis_fixed_15 = gtk_fixed_new();
    window_notebook_psychosis_fixed_16 = gtk_fixed_new();
    window_notebook_psychosis_fixed_17 = gtk_fixed_new();
    window_notebook_psychosis_fixed_18 = gtk_fixed_new();
    window_notebook_depression_fixed_1 = gtk_fixed_new();
    window_notebook_depression_fixed_2 = gtk_fixed_new();
    window_notebook_depression_fixed_3 = gtk_fixed_new();
    window_notebook_depression_fixed_4 = gtk_fixed_new();
    window_notebook_depression_fixed_5 = gtk_fixed_new();
    window_notebook_depression_fixed_6 = gtk_fixed_new();
    window_notebook_depression_fixed_7 = gtk_fixed_new();
    window_notebook_depression_fixed_8 = gtk_fixed_new();
    window_notebook_depression_fixed_9 = gtk_fixed_new();
    window_notebook_depression_fixed_10 = gtk_fixed_new();
    window_notebook_depression_fixed_11 = gtk_fixed_new();
    window_notebook_depression_fixed_12 = gtk_fixed_new();
    window_notebook_depression_fixed_13 = gtk_fixed_new();
    window_notebook_depression_fixed_14 = gtk_fixed_new();
    window_notebook_depression_fixed_15 = gtk_fixed_new();
    window_notebook_depression_fixed_16 = gtk_fixed_new();
    window_notebook_depression_fixed_17 = gtk_fixed_new();
    window_notebook_depression_fixed_18 = gtk_fixed_new();
    window_notebook_anxiety_fixed_1 = gtk_fixed_new();
    window_notebook_anxiety_fixed_2 = gtk_fixed_new();
    window_notebook_anxiety_fixed_3 = gtk_fixed_new();
    window_notebook_anxiety_fixed_4 = gtk_fixed_new();
    window_notebook_anxiety_fixed_5 = gtk_fixed_new();
    window_notebook_anxiety_fixed_6 = gtk_fixed_new();
    window_notebook_anxiety_fixed_7 = gtk_fixed_new();
    window_notebook_anxiety_fixed_8 = gtk_fixed_new();
    window_notebook_heart_fixed_1 = gtk_fixed_new();
    window_notebook_heart_fixed_2 = gtk_fixed_new();
    window_notebook_heart_fixed_3 = gtk_fixed_new();
    window_notebook_heart_fixed_4 = gtk_fixed_new();
    window_notebook_heart_fixed_5 = gtk_fixed_new();
    window_notebook_heart_fixed_6 = gtk_fixed_new();
    window_notebook_heart_fixed_7 = gtk_fixed_new();
    window_notebook_heart_fixed_8 = gtk_fixed_new();
    /* 创建window_notebook内部控件 */
    window_notebook_psychosis_check_1 = gtk_check_button_new_with_label("氯丙嗪片");
    window_notebook_psychosis_check_2 = gtk_check_button_new_with_label("氯丙嗪\n注射液");
    window_notebook_psychosis_check_3 = gtk_check_button_new_with_label("奋乃静片");
    window_notebook_psychosis_check_4 = gtk_check_button_new_with_label("氟哌啶醇片");
    window_notebook_psychosis_check_5 = gtk_check_button_new_with_label("氟哌啶醇\n注射液");
    window_notebook_psychosis_check_6 = gtk_check_button_new_with_label("奥氮平片");
    window_notebook_psychosis_check_7 = gtk_check_button_new_with_label("喹硫平片");
    window_notebook_psychosis_check_8 = gtk_check_button_new_with_label("阿立哌唑\n口腔崩解片");
    window_notebook_psychosis_check_9 = gtk_check_button_new_with_label("利培酮片");
    window_notebook_depression_check_1 = gtk_check_button_new_with_label("多虑平片");
    window_notebook_depression_check_2 = gtk_check_button_new_with_label("氯丙咪嗪片");
    window_notebook_depression_check_3 = gtk_check_button_new_with_label("氟西丁片");
    window_notebook_depression_check_4 = gtk_check_button_new_with_label("氟伏沙明片");
    window_notebook_depression_check_5 = gtk_check_button_new_with_label("帕罗西丁片");
    window_notebook_depression_check_6 = gtk_check_button_new_with_label("舍曲林片");
    window_notebook_depression_check_7 = gtk_check_button_new_with_label("曲唑酮片");
    window_notebook_depression_check_8 = gtk_check_button_new_with_label("米氯平");
    window_notebook_depression_check_9 = gtk_check_button_new_with_label("文拉法星片");
    window_notebook_anxiety_check_1 = gtk_check_button_new_with_label("阿普唑仑片");
    window_notebook_anxiety_check_2 = gtk_check_button_new_with_label("劳拉西泮片");
    window_notebook_anxiety_check_3 = gtk_check_button_new_with_label("艾司唑仑片");
    window_notebook_anxiety_check_4 = gtk_check_button_new_with_label("佐匹克隆片");
    window_notebook_heart_check_1 = gtk_check_button_new_with_label("丙戊酸盐片");
    window_notebook_heart_check_2 = gtk_check_button_new_with_label("丙戊酸盐\n注射液");
    window_notebook_heart_check_3 = gtk_check_button_new_with_label("卡马西平片");
    window_notebook_heart_check_4 = gtk_check_button_new_with_label("碳酸锂片");
    window_notebook_psychosis_entry_1 = gtk_entry_new();
    window_notebook_psychosis_entry_2 = gtk_entry_new();
    window_notebook_psychosis_entry_3 = gtk_entry_new();
    window_notebook_psychosis_entry_4 = gtk_entry_new();
    window_notebook_psychosis_entry_5 = gtk_entry_new();
    window_notebook_psychosis_entry_6 = gtk_entry_new();
    window_notebook_psychosis_entry_7 = gtk_entry_new();
    window_notebook_psychosis_entry_8 = gtk_entry_new();
    window_notebook_psychosis_entry_9 = gtk_entry_new();
    window_notebook_depression_entry_1 = gtk_entry_new();
    window_notebook_depression_entry_2 = gtk_entry_new();
    window_notebook_depression_entry_3 = gtk_entry_new();
    window_notebook_depression_entry_4 = gtk_entry_new();
    window_notebook_depression_entry_5 = gtk_entry_new();
    window_notebook_depression_entry_6 = gtk_entry_new();
    window_notebook_depression_entry_7 = gtk_entry_new();
    window_notebook_depression_entry_8 = gtk_entry_new();
    window_notebook_depression_entry_9 = gtk_entry_new();
    window_notebook_anxiety_entry_1 = gtk_entry_new();
    window_notebook_anxiety_entry_2 = gtk_entry_new();
    window_notebook_anxiety_entry_3 = gtk_entry_new();
    window_notebook_anxiety_entry_4 = gtk_entry_new();
    window_notebook_heart_entry_1 = gtk_entry_new();
    window_notebook_heart_entry_2 = gtk_entry_new();
    window_notebook_heart_entry_3 = gtk_entry_new();
    window_notebook_heart_entry_4 = gtk_entry_new();
    /* 设定各个控件的默认大小 */
    gtk_widget_set_size_request(window_notebook_psychosis_check_1, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_1, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_2, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_2, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_3, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_3, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_4, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_4, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_5, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_5, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_6, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_6, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_7, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_7, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_8, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_8, 100, 20);
    gtk_widget_set_size_request(window_notebook_psychosis_check_9, 100, 40);
    gtk_widget_set_size_request(window_notebook_psychosis_entry_9, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_1, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_1, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_2, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_2, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_3, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_3, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_4, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_4, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_5, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_5, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_6, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_6, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_7, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_7, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_8, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_8, 100, 20);
    gtk_widget_set_size_request(window_notebook_depression_check_9, 100, 40);
    gtk_widget_set_size_request(window_notebook_depression_entry_9, 100, 20);
    gtk_widget_set_size_request(window_notebook_anxiety_check_1, 100, 40);
    gtk_widget_set_size_request(window_notebook_anxiety_entry_1, 100, 20);
    gtk_widget_set_size_request(window_notebook_anxiety_check_2, 100, 40);
    gtk_widget_set_size_request(window_notebook_anxiety_entry_2, 100, 20);
    gtk_widget_set_size_request(window_notebook_anxiety_check_3, 100, 40);
    gtk_widget_set_size_request(window_notebook_anxiety_entry_3, 100, 20);
    gtk_widget_set_size_request(window_notebook_anxiety_check_4, 100, 40);
    gtk_widget_set_size_request(window_notebook_anxiety_entry_4, 100, 20);
    gtk_widget_set_size_request(window_notebook_heart_check_1, 100, 40);
    gtk_widget_set_size_request(window_notebook_heart_entry_1, 100, 20);
    gtk_widget_set_size_request(window_notebook_heart_check_2, 100, 40);
    gtk_widget_set_size_request(window_notebook_heart_entry_2, 100, 20);
    gtk_widget_set_size_request(window_notebook_heart_check_3, 100, 40);
    gtk_widget_set_size_request(window_notebook_heart_entry_3, 100, 20);
    gtk_widget_set_size_request(window_notebook_heart_check_4, 100, 40);
    gtk_widget_set_size_request(window_notebook_heart_entry_4, 100, 20);
    /* 把内部控件放入GtkFixed框架之中 */
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_1), GTK_WIDGET(window_notebook_psychosis_check_1), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_2), GTK_WIDGET(window_notebook_psychosis_entry_1), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_3), GTK_WIDGET(window_notebook_psychosis_check_2), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_4), GTK_WIDGET(window_notebook_psychosis_entry_2), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_5), GTK_WIDGET(window_notebook_psychosis_check_3), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_6), GTK_WIDGET(window_notebook_psychosis_entry_3), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_7), GTK_WIDGET(window_notebook_psychosis_check_4), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_8), GTK_WIDGET(window_notebook_psychosis_entry_4), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_9), GTK_WIDGET(window_notebook_psychosis_check_5), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_10), GTK_WIDGET(window_notebook_psychosis_entry_5), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_11), GTK_WIDGET(window_notebook_psychosis_check_6), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_12), GTK_WIDGET(window_notebook_psychosis_entry_6), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_13), GTK_WIDGET(window_notebook_psychosis_check_7), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_14), GTK_WIDGET(window_notebook_psychosis_entry_7), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_15), GTK_WIDGET(window_notebook_psychosis_check_8), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_16), GTK_WIDGET(window_notebook_psychosis_entry_8), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_17), GTK_WIDGET(window_notebook_psychosis_check_9), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_psychosis_fixed_18), GTK_WIDGET(window_notebook_psychosis_entry_9), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_1), GTK_WIDGET(window_notebook_depression_check_1), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_2), GTK_WIDGET(window_notebook_depression_entry_1), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_3), GTK_WIDGET(window_notebook_depression_check_2), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_4), GTK_WIDGET(window_notebook_depression_entry_2), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_5), GTK_WIDGET(window_notebook_depression_check_3), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_6), GTK_WIDGET(window_notebook_depression_entry_3), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_7), GTK_WIDGET(window_notebook_depression_check_4), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_8), GTK_WIDGET(window_notebook_depression_entry_4), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_9), GTK_WIDGET(window_notebook_depression_check_5), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_10), GTK_WIDGET(window_notebook_depression_entry_5), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_11), GTK_WIDGET(window_notebook_depression_check_6), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_12), GTK_WIDGET(window_notebook_depression_entry_6), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_13), GTK_WIDGET(window_notebook_depression_check_7), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_14), GTK_WIDGET(window_notebook_depression_entry_7), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_15), GTK_WIDGET(window_notebook_depression_check_8), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_16), GTK_WIDGET(window_notebook_depression_entry_8), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_17), GTK_WIDGET(window_notebook_depression_check_9), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_depression_fixed_18), GTK_WIDGET(window_notebook_depression_entry_9), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_1), GTK_WIDGET(window_notebook_anxiety_check_1), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_2), GTK_WIDGET(window_notebook_anxiety_entry_1), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_3), GTK_WIDGET(window_notebook_anxiety_check_2), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_4), GTK_WIDGET(window_notebook_anxiety_entry_2), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_5), GTK_WIDGET(window_notebook_anxiety_check_3), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_6), GTK_WIDGET(window_notebook_anxiety_entry_3), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_7), GTK_WIDGET(window_notebook_anxiety_check_4), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_anxiety_fixed_8), GTK_WIDGET(window_notebook_anxiety_entry_4), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_1), GTK_WIDGET(window_notebook_heart_check_1), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_2), GTK_WIDGET(window_notebook_heart_entry_1), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_3), GTK_WIDGET(window_notebook_heart_check_2), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_4), GTK_WIDGET(window_notebook_heart_entry_2), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_5), GTK_WIDGET(window_notebook_heart_check_3), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_6), GTK_WIDGET(window_notebook_heart_entry_3), 0, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_7), GTK_WIDGET(window_notebook_heart_check_4), 75, 25);
    gtk_fixed_put(GTK_FIXED(window_notebook_heart_fixed_8), GTK_WIDGET(window_notebook_heart_entry_4), 0, 25);
    /* 把GtkFixed控件放入table和h_box之中 */
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_3, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_5, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_9, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_13, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_14, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_15, 2, 3, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_16, 3, 4, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_17, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_psychosis_table), window_notebook_psychosis_fixed_18, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_3, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_5, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_9, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_13, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_14, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_15, 2, 3, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_16, 3, 4, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_17, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_depression_table), window_notebook_depression_fixed_18, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_3, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_5, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_anxiety_table), window_notebook_anxiety_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_3, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_5, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_6, 1, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(window_notebook_heart_table), window_notebook_heart_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    /* 把table放入v_bok之中 */
    gtk_box_pack_start(GTK_BOX(window_notebook_psychosis_v_box), window_notebook_psychosis_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_notebook_depression_v_box), window_notebook_depression_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_notebook_anxiety_v_box), window_notebook_anxiety_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_notebook_heart_v_box), window_notebook_heart_table, FALSE, FALSE, 0);
    /* 把v_box放入滚动窗口之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(window_notebook_psychosis_scrolled), window_notebook_psychosis_v_box);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(window_notebook_depression_scrolled), window_notebook_depression_v_box);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(window_notebook_anxiety_scrolled), window_notebook_anxiety_v_box);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(window_notebook_heart_scrolled), window_notebook_heart_v_box);
    /* 把滚动窗口放入notebook之中 */
    gtk_notebook_append_page(GTK_NOTEBOOK(window_notebook), window_notebook_psychosis_scrolled, window_notebook_psychosis_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(window_notebook), window_notebook_depression_scrolled, window_notebook_depression_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(window_notebook), window_notebook_anxiety_scrolled, window_notebook_anxiety_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(window_notebook), window_notebook_heart_scrolled, window_notebook_heart_label);

    /* 创建“确定”和“取消”按钮 */
    window_edit_button_ok = gtk_button_new_with_label("确定");
    window_edit_button_cancel = gtk_button_new_with_label("取消");
    /* 设置按钮默认大小 */
    gtk_widget_set_size_request(window_edit_button_ok, 75, 25);
    gtk_widget_set_size_request(window_edit_button_cancel, 75, 25);
    /* 创建对齐框架 */
    window_edit_h_box = gtk_hbox_new(FALSE, 0);
    window_edit_alignment = gtk_alignment_new(1, 0, 0, 0);
    window_edit_alignment_h_box = gtk_hbox_new(FALSE, 0);
    /* 将编辑按钮放入h_box之中 */ /* 注意一下到底用TRUE还是FALSE */
    gtk_box_pack_start(GTK_BOX(window_edit_alignment_h_box), window_edit_button_ok, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_edit_alignment_h_box), window_edit_button_cancel, FALSE, FALSE, 0);
    /* 将window_edit_alignment_h_box放入对齐框架之中 */
    gtk_container_add(GTK_CONTAINER(window_edit_alignment), window_edit_alignment_h_box);
    /* 将window_edit_alignment放入window_edit_h_box之中 */
    gtk_box_pack_start(GTK_BOX(window_edit_h_box), window_edit_alignment, TRUE, TRUE, 0);

    /* 将各个部分的对齐框架放入window_v_box之中 */
    gtk_box_pack_start(GTK_BOX(window_v_box), window_notebook, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(window_v_box), window_edit_h_box, FALSE, FALSE, 0);
    /* 将window_v_box加入到window之中 */
    gtk_container_add(GTK_CONTAINER(window), window_v_box);
    /* 显示对话窗口 */
    gtk_widget_show_all(window);
}
