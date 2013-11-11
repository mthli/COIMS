void notebook_window_treat_button_medicine_callback()
{
    /* 控件声明 */
    GtkWidget *treat_dialog_medicine;
    GtkWidget *treat_dialog_medicine_v_box,
              *treat_dialog_medicine_table_1, *treat_dialog_medicine_table_2,
              *treat_dialog_medicine_table_3, *treat_dialog_medicine_table_4,
              *treat_dialog_medicine_h_box_1, *treat_dialog_medicine_h_box_2,
              *treat_dialog_medicine_h_box_3, *treat_dialog_medicine_h_box_4,
              *treat_dialog_medicine_h_box_5, *treat_dialog_medicine_h_box_6,
              *treat_dialog_medicine_h_box_right;
    GtkWidget *treat_dialog_medicine_fixed_1, *treat_dialog_medicine_fixed_2, *treat_dialog_medicine_fixed_3,
              *treat_dialog_medicine_fixed_4, *treat_dialog_medicine_fixed_5, *treat_dialog_medicine_fixed_6,
              *treat_dialog_medicine_fixed_7, *treat_dialog_medicine_fixed_8, *treat_dialog_medicine_fixed_9,
              *treat_dialog_medicine_fixed_10, *treat_dialog_medicine_fixed_11, *treat_dialog_medicine_fixed_12,
              *treat_dialog_medicine_fixed_13, *treat_dialog_medicine_fixed_14, *treat_dialog_medicine_fixed_15,
              *treat_dialog_medicine_fixed_16, *treat_dialog_medicine_fixed_17, *treat_dialog_medicine_fixed_18,
              *treat_dialog_medicine_fixed_19, *treat_dialog_medicine_fixed_20, *treat_dialog_medicine_fixed_21,
              *treat_dialog_medicine_fixed_22, *treat_dialog_medicine_fixed_23, *treat_dialog_medicine_fixed_24,
              *treat_dialog_medicine_fixed_25, *treat_dialog_medicine_fixed_26, *treat_dialog_medicine_fixed_27,
              *treat_dialog_medicine_fixed_28, *treat_dialog_medicine_fixed_29, *treat_dialog_medicine_fixed_30,
              *treat_dialog_medicine_fixed_31, *treat_dialog_medicine_fixed_32, *treat_dialog_medicine_fixed_33,
              *treat_dialog_medicine_fixed_34, *treat_dialog_medicine_fixed_35, *treat_dialog_medicine_fixed_36,
              *treat_dialog_medicine_fixed_37, *treat_dialog_medicine_fixed_38, *treat_dialog_medicine_fixed_39,
              *treat_dialog_medicine_fixed_40, *treat_dialog_medicine_fixed_41, *treat_dialog_medicine_fixed_42,
              *treat_dialog_medicine_fixed_43, *treat_dialog_medicine_fixed_44, *treat_dialog_medicine_fixed_45,
              *treat_dialog_medicine_fixed_46, *treat_dialog_medicine_fixed_47, *treat_dialog_medicine_fixed_48,
              *treat_dialog_medicine_fixed_49, *treat_dialog_medicine_fixed_50, *treat_dialog_medicine_fixed_51,
              *treat_dialog_medicine_fixed_52, *treat_dialog_medicine_fixed_53, *treat_dialog_medicine_fixed_54,
              *treat_dialog_medicine_fixed_55, *treat_dialog_medicine_fixed_56, *treat_dialog_medicine_fixed_57,
              *treat_dialog_medicine_fixed_58, *treat_dialog_medicine_fixed_59;
    GtkWidget *treat_dialog_medicine_alignment_right;
    GtkWidget *treat_dialog_medicine_label_1, *treat_dialog_medicine_label_2, *treat_dialog_medicine_label_3,
              *treat_dialog_medicine_label_4, *treat_dialog_medicine_label_5;
    GtkWidget *treat_dialog_medicine_button_check_1, *treat_dialog_medicine_button_check_2,
              *treat_dialog_medicine_button_check_3, *treat_dialog_medicine_button_check_4,
              *treat_dialog_medicine_button_check_5, *treat_dialog_medicine_button_check_6,
              *treat_dialog_medicine_button_check_7, *treat_dialog_medicine_button_check_8,
              *treat_dialog_medicine_button_check_9, *treat_dialog_medicine_button_check_10,
              *treat_dialog_medicine_button_check_11, *treat_dialog_medicine_button_check_12,
              *treat_dialog_medicine_button_check_13, *treat_dialog_medicine_button_check_14,
              *treat_dialog_medicine_button_check_15, *treat_dialog_medicine_button_check_16,
              *treat_dialog_medicine_button_check_17, *treat_dialog_medicine_button_check_18,
              *treat_dialog_medicine_button_check_19, *treat_dialog_medicine_button_check_20,
              *treat_dialog_medicine_button_check_21, *treat_dialog_medicine_button_check_22,
              *treat_dialog_medicine_button_check_23, *treat_dialog_medicine_button_check_24,
              *treat_dialog_medicine_button_check_25, *treat_dialog_medicine_button_check_26;
    GtkWidget *treat_dialog_medicine_entry_1, *treat_dialog_medicine_entry_2,
              *treat_dialog_medicine_entry_3, *treat_dialog_medicine_entry_4,
              *treat_dialog_medicine_entry_5, *treat_dialog_medicine_entry_6,
              *treat_dialog_medicine_entry_7, *treat_dialog_medicine_entry_8,
              *treat_dialog_medicine_entry_9, *treat_dialog_medicine_entry_10,
              *treat_dialog_medicine_entry_11, *treat_dialog_medicine_entry_12,
              *treat_dialog_medicine_entry_13, *treat_dialog_medicine_entry_14,
              *treat_dialog_medicine_entry_15, *treat_dialog_medicine_entry_16,
              *treat_dialog_medicine_entry_17, *treat_dialog_medicine_entry_18,
              *treat_dialog_medicine_entry_19, *treat_dialog_medicine_entry_20,
              *treat_dialog_medicine_entry_21, *treat_dialog_medicine_entry_22,
              *treat_dialog_medicine_entry_23, *treat_dialog_medicine_entry_24,
              *treat_dialog_medicine_entry_25, *treat_dialog_medicine_entry_26;
    GtkWidget *treat_dialog_medicine_button_ok, *treat_dialog_medicine_button_cancel;
    /* 创建dialog内部框架 */
    treat_dialog_medicine_v_box = gtk_vbox_new(FALSE, 0);
    treat_dialog_medicine_table_1 = gtk_table_new(5, 4, FALSE);
    treat_dialog_medicine_table_2 = gtk_table_new(5, 4, FALSE);
    treat_dialog_medicine_table_3 = gtk_table_new(2, 4, FALSE);
    treat_dialog_medicine_table_4 = gtk_table_new(2, 4, FALSE);
    treat_dialog_medicine_h_box_1 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_2 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_3 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_4 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_5 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_right = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_h_box_6 = gtk_hbox_new(FALSE, 0);
    treat_dialog_medicine_fixed_1 = gtk_fixed_new();
    treat_dialog_medicine_fixed_2 = gtk_fixed_new();
    treat_dialog_medicine_fixed_3 = gtk_fixed_new();
    treat_dialog_medicine_fixed_4 = gtk_fixed_new();
    treat_dialog_medicine_fixed_5 = gtk_fixed_new();
    treat_dialog_medicine_fixed_6 = gtk_fixed_new();
    treat_dialog_medicine_fixed_7 = gtk_fixed_new();
    treat_dialog_medicine_fixed_8 = gtk_fixed_new();
    treat_dialog_medicine_fixed_9 = gtk_fixed_new();
    treat_dialog_medicine_fixed_10 = gtk_fixed_new();
    treat_dialog_medicine_fixed_11 = gtk_fixed_new();
    treat_dialog_medicine_fixed_12 = gtk_fixed_new();
    treat_dialog_medicine_fixed_13 = gtk_fixed_new();
    treat_dialog_medicine_fixed_14 = gtk_fixed_new();
    treat_dialog_medicine_fixed_15 = gtk_fixed_new();
    treat_dialog_medicine_fixed_15 = gtk_fixed_new();
    treat_dialog_medicine_fixed_16 = gtk_fixed_new();
    treat_dialog_medicine_fixed_17 = gtk_fixed_new();
    treat_dialog_medicine_fixed_18 = gtk_fixed_new();
    treat_dialog_medicine_fixed_19 = gtk_fixed_new();
    treat_dialog_medicine_fixed_20 = gtk_fixed_new();
    treat_dialog_medicine_fixed_21 = gtk_fixed_new();
    treat_dialog_medicine_fixed_22 = gtk_fixed_new();
    treat_dialog_medicine_fixed_23 = gtk_fixed_new();
    treat_dialog_medicine_fixed_24 = gtk_fixed_new();
    treat_dialog_medicine_fixed_25 = gtk_fixed_new();
    treat_dialog_medicine_fixed_26 = gtk_fixed_new();
    treat_dialog_medicine_fixed_27 = gtk_fixed_new();
    treat_dialog_medicine_fixed_28 = gtk_fixed_new();
    treat_dialog_medicine_fixed_29 = gtk_fixed_new();
    treat_dialog_medicine_fixed_30 = gtk_fixed_new();
    treat_dialog_medicine_fixed_31 = gtk_fixed_new();
    treat_dialog_medicine_fixed_32 = gtk_fixed_new();
    treat_dialog_medicine_fixed_33 = gtk_fixed_new();
    treat_dialog_medicine_fixed_34 = gtk_fixed_new();
    treat_dialog_medicine_fixed_35 = gtk_fixed_new();
    treat_dialog_medicine_fixed_36 = gtk_fixed_new();
    treat_dialog_medicine_fixed_37 = gtk_fixed_new();
    treat_dialog_medicine_fixed_38 = gtk_fixed_new();
    treat_dialog_medicine_fixed_39 = gtk_fixed_new();
    treat_dialog_medicine_fixed_40 = gtk_fixed_new();
    treat_dialog_medicine_fixed_41 = gtk_fixed_new();
    treat_dialog_medicine_fixed_42 = gtk_fixed_new();
    treat_dialog_medicine_fixed_43 = gtk_fixed_new();
    treat_dialog_medicine_fixed_44 = gtk_fixed_new();
    treat_dialog_medicine_fixed_45 = gtk_fixed_new();
    treat_dialog_medicine_fixed_46 = gtk_fixed_new();
    treat_dialog_medicine_fixed_47 = gtk_fixed_new();
    treat_dialog_medicine_fixed_48 = gtk_fixed_new();
    treat_dialog_medicine_fixed_49 = gtk_fixed_new();
    treat_dialog_medicine_fixed_50 = gtk_fixed_new();
    treat_dialog_medicine_fixed_51 = gtk_fixed_new();
    treat_dialog_medicine_fixed_52 = gtk_fixed_new();
    treat_dialog_medicine_fixed_53 = gtk_fixed_new();
    treat_dialog_medicine_fixed_54 = gtk_fixed_new();
    treat_dialog_medicine_fixed_55 = gtk_fixed_new();
    treat_dialog_medicine_fixed_56 = gtk_fixed_new();
    treat_dialog_medicine_fixed_57 = gtk_fixed_new();
    treat_dialog_medicine_fixed_58 = gtk_fixed_new();
    treat_dialog_medicine_fixed_59 = gtk_fixed_new();
    /* 创建alignment框架 */
    treat_dialog_medicine_alignment_right = gtk_alignment_new(1, 0, 0, 0);
    /* 创建dialog内部控件 */
    treat_dialog_medicine_label_1 = gtk_label_new("可多选：");
    treat_dialog_medicine_label_2 = gtk_label_new("抗精神病药物：");
    treat_dialog_medicine_button_check_1 = gtk_check_button_new_with_label("氯丙嗪片");
    treat_dialog_medicine_button_check_2 = gtk_check_button_new_with_label("氯丙嗪注射液");
    treat_dialog_medicine_button_check_3 = gtk_check_button_new_with_label("奋乃静片");
    treat_dialog_medicine_button_check_4 = gtk_check_button_new_with_label("氟哌啶醇片");
    treat_dialog_medicine_button_check_5 = gtk_check_button_new_with_label("氟哌啶醇注射液");
    treat_dialog_medicine_button_check_6 = gtk_check_button_new_with_label("奥氮平片");
    treat_dialog_medicine_button_check_7 = gtk_check_button_new_with_label("喹硫平片");
    treat_dialog_medicine_button_check_8 = gtk_check_button_new_with_label("阿立哌唑口腔崩解片");
    treat_dialog_medicine_button_check_9 = gtk_check_button_new_with_label("利培酮片");
    treat_dialog_medicine_label_3 = gtk_label_new("抗抑郁药物：");
    treat_dialog_medicine_button_check_10 = gtk_check_button_new_with_label("多虑平片");
    treat_dialog_medicine_button_check_11 = gtk_check_button_new_with_label("氯丙咪嗪片");
    treat_dialog_medicine_button_check_12 = gtk_check_button_new_with_label("氟西丁片");
    treat_dialog_medicine_button_check_13 = gtk_check_button_new_with_label("氟伏沙明片");
    treat_dialog_medicine_button_check_14 = gtk_check_button_new_with_label("帕罗西丁片");
    treat_dialog_medicine_button_check_15 = gtk_check_button_new_with_label("舍曲林片");
    treat_dialog_medicine_button_check_16 = gtk_check_button_new_with_label("曲唑酮片");
    treat_dialog_medicine_button_check_17 = gtk_check_button_new_with_label("米氯平");
    treat_dialog_medicine_button_check_18 = gtk_check_button_new_with_label("文拉法星片");
    treat_dialog_medicine_label_4 = gtk_label_new("抗焦虑药物：");
    treat_dialog_medicine_button_check_19 = gtk_check_button_new_with_label("阿普唑仑片");
    treat_dialog_medicine_button_check_20 = gtk_check_button_new_with_label("劳拉西泮片");
    treat_dialog_medicine_button_check_21 = gtk_check_button_new_with_label("艾司唑仑片");
    treat_dialog_medicine_button_check_22 = gtk_check_button_new_with_label("佐匹克隆片");
    treat_dialog_medicine_label_5 = gtk_label_new("心境稳定剂：");
    treat_dialog_medicine_button_check_23 = gtk_check_button_new_with_label("丙戊酸盐片");
    treat_dialog_medicine_button_check_24 = gtk_check_button_new_with_label("丙戊酸盐注射液");
    treat_dialog_medicine_button_check_25 = gtk_check_button_new_with_label("卡马西平片");
    treat_dialog_medicine_button_check_26 = gtk_check_button_new_with_label("碳酸锂片");
    treat_dialog_medicine_entry_1 = gtk_entry_new();
    treat_dialog_medicine_entry_2 = gtk_entry_new();
    treat_dialog_medicine_entry_3 = gtk_entry_new();
    treat_dialog_medicine_entry_4 = gtk_entry_new();
    treat_dialog_medicine_entry_5 = gtk_entry_new();
    treat_dialog_medicine_entry_6 = gtk_entry_new();
    treat_dialog_medicine_entry_7 = gtk_entry_new();
    treat_dialog_medicine_entry_8 = gtk_entry_new();
    treat_dialog_medicine_entry_9 = gtk_entry_new();
    treat_dialog_medicine_entry_10 = gtk_entry_new();
    treat_dialog_medicine_entry_11 = gtk_entry_new();
    treat_dialog_medicine_entry_12 = gtk_entry_new();
    treat_dialog_medicine_entry_13 = gtk_entry_new();
    treat_dialog_medicine_entry_14 = gtk_entry_new();
    treat_dialog_medicine_entry_15 = gtk_entry_new();
    treat_dialog_medicine_entry_16 = gtk_entry_new();
    treat_dialog_medicine_entry_17 = gtk_entry_new();
    treat_dialog_medicine_entry_18 = gtk_entry_new();
    treat_dialog_medicine_entry_19 = gtk_entry_new();
    treat_dialog_medicine_entry_20 = gtk_entry_new();
    treat_dialog_medicine_entry_21 = gtk_entry_new();
    treat_dialog_medicine_entry_22 = gtk_entry_new();
    treat_dialog_medicine_entry_23 = gtk_entry_new();
    treat_dialog_medicine_entry_24 = gtk_entry_new();
    treat_dialog_medicine_entry_25 = gtk_entry_new();
    treat_dialog_medicine_entry_26 = gtk_entry_new();
    treat_dialog_medicine_button_ok = gtk_button_new_with_label("确定");
    treat_dialog_medicine_button_cancel = gtk_button_new_with_label("取消");
    /* 设定各个控件的默认大小 */
    gtk_widget_size_request(treat_dialog_medicine_label_1), 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_label_2), 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_1, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_1, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_2, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_2, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_3, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_3, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_4, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_4, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_5, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_5, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_6, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_6, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_7, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_7, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_8, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_8, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_9, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_9, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_label_3, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_10, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_10, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_11, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_11, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_12, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_12, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_13, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_13, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_14, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_14, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_15, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_15, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_16, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_16, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_17, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_17, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_18, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_18, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_label_4, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_19, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_19, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_20, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_20, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_21, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_21, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_22, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_22, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_label_5, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_23, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_23, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_24, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_24, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_25, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_25, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_check_26, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_entry_26, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_ok, 100, 25);
    gtk_widget_size_request(treat_dialog_medicine_button_cancel, 100, 25);
    /* 把内部控件放入GtkFixed框架之中 */
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_1), GTK_WIDGET(treat_dialog_medicine_label_1), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_2), GTK_WIDGET(treat_dialog_medicine_label_2), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_3), GTK_WIDGET(treat_dialog_medicine_button_check_1), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_4), GTK_WIDGET(treat_dialog_medicine_entry_1), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_5), GTK_WIDGET(treat_dialog_medicine_button_check_2), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_6), GTK_WIDGET(treat_dialog_medicine_entry_2), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_7), GTK_WIDGET(treat_dialog_medicine_button_check_3), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_8), GTK_WIDGET(treat_dialog_medicine_entry_3), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_9), GTK_WIDGET(treat_dialog_medicine_button_check_4), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_10), GTK_WIDGET(treat_dialog_medicine_entry_4), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_11), GTK_WIDGET(treat_dialog_medicine_button_check_5), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_12), GTK_WIDGET(treat_dialog_medicine_entry_5), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_13), GTK_WIDGET(treat_dialog_medicine_button_check_6), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_14), GTK_WIDGET(treat_dialog_medicine_entry_6), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_15), GTK_WIDGET(treat_dialog_medicine_button_check_7), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_16), GTK_WIDGET(treat_dialog_medicine_entry_7), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_17), GTK_WIDGET(treat_dialog_medicine_button_check_8), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_18), GTK_WIDGET(treat_dialog_medicine_entry_8), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_19), GTK_WIDGET(treat_dialog_medicine_button_check_9), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_20), GTK_WIDGET(treat_dialog_medicine_entry_9), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_21), GTK_WIDGET(treat_dialog_medicine_label_3), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_22), GTK_WIDGET(treat_dialog_medicine_button_check_10), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_23), GTK_WIDGET(treat_dialog_medicine_entry_10), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_24), GTK_WIDGET(treat_dialog_medicine_button_check_11), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_25), GTK_WIDGET(treat_dialog_medicine_entry_11), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_26), GTK_WIDGET(treat_dialog_medicine_button_check_12), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_27), GTK_WIDGET(treat_dialog_medicine_entry_12), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_28), GTK_WIDGET(treat_dialog_medicine_button_check_13), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_29), GTK_WIDGET(treat_dialog_medicine_entry_13), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_30), GTK_WIDGET(treat_dialog_medicine_button_check_14), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_31), GTK_WIDGET(treat_dialog_medicine_entry_14), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_32), GTK_WIDGET(treat_dialog_medicine_button_check_15), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_33), GTK_WIDGET(treat_dialog_medicine_entry_15), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_34), GTK_WIDGET(treat_dialog_medicine_button_check_16), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_35), GTK_WIDGET(treat_dialog_medicine_entry_16), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_36), GTK_WIDGET(treat_dialog_medicine_button_check_17), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_37), GTK_WIDGET(treat_dialog_medicine_entry_17), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_38), GTK_WIDGET(treat_dialog_medicine_button_check_18), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_39), GTK_WIDGET(treat_dialog_medicine_entry_18), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_40), GTK_WIDGET(treat_dialog_medicine_label_4), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_41), GTK_WIDGET(treat_dialog_medicine_button_check_19), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_42), GTK_WIDGET(treat_dialog_medicine_entry_19), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_43), GTK_WIDGET(treat_dialog_medicine_button_check_20), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_44), GTK_WIDGET(treat_dialog_medicine_entry_20), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_45), GTK_WIDGET(treat_dialog_medicine_button_check_21), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_46), GTK_WIDGET(treat_dialog_medicine_entry_21), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_47), GTK_WIDGET(treat_dialog_medicine_button_check_22), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_48), GTK_WIDGET(treat_dialog_medicine_entry_22), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_49), GTK_WIDGET(treat_dialog_medicine_label_5), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_50), GTK_WIDGET(treat_dialog_medicine_button_check_23), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_51), GTK_WIDGET(treat_dialog_medicine_entry_23), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_52), GTK_WIDGET(treat_dialog_medicine_button_check_24), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_53), GTK_WIDGET(treat_dialog_medicine_entry_24), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_54), GTK_WIDGET(treat_dialog_medicine_button_check_25), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_55), GTK_WIDGET(treat_dialog_medicine_entry_25), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_56), GTK_WIDGET(treat_dialog_medicine_button_check_26), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_57), GTK_WIDGET(treat_dialog_medicine_entry_26), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_58), GTK_WIDGET(treat_dialog_medicine_button_ok), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_medicine_fixed_59), GTK_WIDGET(treat_dialog_medicine_button_cancel), , );
    /* 把GtkFixed控件放入table和h_box之中 */
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_1), treat_dialog_medicine_fixed_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_2), treat_dialog_medicine_fixed_2, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_3, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_4, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_5, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_6, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_7, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_8, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_9, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_10, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_11, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_12, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_13, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_14, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_15, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_16, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_17, 2, 3, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_18, 3, 4, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_19, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_1), treat_dialog_medicine_fixed_20, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_3), treat_dialog_medicine_fixed_21, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_22, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_23, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_24, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_25, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_26, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_27, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_28, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_29, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_30, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_31, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_32, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_33, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_34, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_35, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_36, 2, 3, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_37, 3, 4, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_38, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_2), treat_dialog_medicine_fixed_39, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_4), treat_dialog_medicine_fixed_40, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_41, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_42, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_43, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_44, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_45, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_46, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_47, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_3), treat_dialog_medicine_fixed_48, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_5), treat_dialog_medicine_fixed_49, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_50, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_51, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_52, 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_53, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_54, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_55, 1, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_56, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_medicine_table_4), treat_dialog_medicine_fixed_57, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_right), treat_dialog_medicine_fixed_58, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_right), treat_dialog_medicine_fixed_59, FALSE, FALSE, 0);
    /* 把button_ok和button_cancel对应的GtkFixed放入alignment之中 */
    gtk_container_add(GTK_CONTAINER(treat_dialog_medicine_alignment_right), treat_dialog_medicine_h_box_right);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_h_box_6), treat_dialog_medicine_alignment_right, TRUE, TRUE, 0);
    /* 把table和h_box放入v_bok之中 */
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_table_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_table_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_medicine_v_box), treat_dialog_medicine_h_box_6, FALSE, FALSE, 0);
    /* 把v_box放入dialog之中 */
