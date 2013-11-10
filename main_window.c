#include <gtk/gtk.h>

/* 各个回调函数的声明 */
void menu_bar_help_callback(GtkWidget *widget, gpointer main_window);

/* */

int main(int argc, char *argv[]) /* 注意是char *argv[] */
{
    /* 主窗口控件声明 */
    GtkWidget *main_window;
    /* 菜单栏控件声明 */
    GtkWidget *menu_bar;
    GtkWidget *menu_file, *menu_make, *menu_data, *menu_help;
    GtkWidget *menu_bar_file, *menu_bar_make, *menu_bar_data, *menu_bar_help;
    GtkWidget *menu_bar_file_new, *menu_bar_file_open, *menu_bar_file_delete, *menu_bar_file_quit,
              *menu_bar_make_status, *menu_bar_make_cost,
              *menu_bar_data_buckup, *menu_bar_data_clean,
              *menu_bar_help_show, *menu_bar_help_about,
              *menu_bar_item_separator_1, *menu_bar_item_separator_2,
              *menu_bar_item_separator_3, *menu_bar_item_separator_4;
    /* notebook及其内部所需控件声明 */
    GtkWidget *notebook;
    GtkWidget *notebook_label_person, *notebook_label_treat, *notebook_label_grade;
    GtkWidget *notebook_window_person, *notebook_window_treat, *notebook_window_grade;
    /* ------------------------------------- notebook_window_person部分声明 ---------------------------------------- */
    GtkWidget *notebook_window_person_v_box,
              *notebook_window_person_table_1, *notebook_window_person_table_2,
              *notebook_window_person_fixed_1, *notebook_window_person_fixed_2, *notebook_window_person_fixed_3,
              *notebook_window_person_fixed_4, *notebook_window_person_fixed_5, *notebook_window_person_fixed_6,
              *notebook_window_person_fixed_7, *notebook_window_person_fixed_8, *notebook_window_person_fixed_9,
              *notebook_window_person_fixed_10, *notebook_window_person_fixed_11, *notebook_window_person_fixed_12,
              *notebook_window_person_fixed_13, *notebook_window_person_fixed_14, *notebook_window_person_fixed_15,
              *notebook_window_person_fixed_16, *notebook_window_person_fixed_17, *notebook_window_person_fixed_18,
              *notebook_window_person_fixed_19, *notebook_window_person_fixed_20, *notebook_window_person_fixed_21,
              *notebook_window_person_fixed_22, *notebook_window_person_fixed_23, *notebook_window_person_fixed_24,
              *notebook_window_person_fixed_25, *notebook_window_person_fixed_26, *notebook_window_person_fixed_27,
              *notebook_window_person_fixed_28, *notebook_window_person_fixed_29, *notebook_window_person_fixed_30,
              *notebook_window_person_fixed_31, *notebook_window_person_fixed_32, *notebook_window_person_fixed_33,
              *notebook_window_person_fixed_34, *notebook_window_person_fixed_35, *notebook_window_person_fixed_36,
              *notebook_window_person_fixed_37, *notebook_window_person_fixed_38, *notebook_window_person_fixed_39,
              *notebook_window_person_fixed_40, *notebook_window_person_fixed_41, *notebook_window_person_fixed_42,
              *notebook_window_person_fixed_43, *notebook_window_person_fixed_44, *notebook_window_person_fixed_45,
              *notebook_window_person_fixed_46, *notebook_window_person_fixed_47,
              *notebook_window_person_h_box_1, *notebook_window_person_h_box_2, *notebook_window_person_h_box_3,
              *notebook_window_person_h_box_4, *notebook_window_person_h_box_5, *notebook_window_person_h_box_6,
              *notebook_window_person_h_box_7, *notebook_window_person_h_box_8, *notebook_window_person_h_box_9,
              *notebook_window_person_h_box_10, *notebook_window_person_h_box_11, *notebook_window_person_h_box_12,
              *notebook_window_person_h_box_13, *notebook_window_person_h_box_14;
    GtkWidget *notebook_window_person_h_separator_1, *notebook_window_person_h_separator_2;
    GtkWidget *notebook_window_person_label_name, *notebook_window_person_label_sex,
              *notebook_window_person_label_age, *notebook_window_person_label_birthday,
              *notebook_window_person_label_credentials, *notebook_window_person_label_marriage,
              *notebook_window_person_label_education, *notebook_window_person_label_place,
              *notebook_window_person_label_into, *notebook_window_person_label_receipt,
              *notebook_window_person_label_ad, *notebook_window_person_label_dangerous,
              *notebook_window_person_label_happen, *notebook_window_person_label_result,
              *notebook_window_person_label_level, *notebook_window_person_label_property,
              *notebook_window_person_label_describe, *notebook_window_person_label_diagnose,
              *notebook_window_person_label_diagnose_show, *notebook_window_person_label_days,
              *notebook_window_person_label_out, *notebook_window_person_label_goto,
              *notebook_window_person_label_void;
    GtkWidget *notebook_window_person_button_photo, *notebook_window_person_button_diagnose;
    GtkWidget *notebook_window_person_combo_sex, *notebook_window_person_combo_credentials,
              *notebook_window_person_combo_education, *notebook_window_person_combo_marriage,
              *notebook_window_person_combo_place, *notebook_window_person_combo_property,
              *notebook_window_person_combo_level, *notebook_window_person_combo_goto;
    GtkWidget *notebook_window_person_text_name, *notebook_window_person_text_age,
              *notebook_window_person_text_birthday, *notebook_window_person_text_happen,
              *notebook_window_person_text_into, *notebook_window_person_text_out,
              *notebook_window_person_text_credentials, *notebook_window_person_text_receipt,
              *notebook_window_person_text_ad, *notebook_window_person_text_describe,
              *notebook_window_person_text_diagnose, *notebook_window_person_text_result,
              *notebook_window_person_text_days;
    GtkWidget *notebook_window_person_scrolled_describe, *notebook_window_person_scrolled_result,
              *notebook_window_person_scrolled_diagnose;
    /* ------------------------------------- notebook_window_treat部分声明 --------------------------------------------- */
    GtkWidget *notebook_window_treat_v_box,
              *notebook_window_treat_table_1, *notebook_window_treat_table_2, *notebook_window_treat_table_3,
              *notebook_window_treat_table_4, *notebook_window_treat_table_5, *notebook_window_treat_table_6,
              *notebook_window_treat_table_7,
              *notebook_window_treat_h_box_1, *notebook_window_treat_h_box_2, *notebook_window_treat_h_box_3,
              *notebook_window_treat_h_box_4, *notebook_window_treat_h_box_5, *notebook_window_treat_h_box_6,
              *notebook_window_treat_h_box_7, *notebook_window_treat_h_box_8, *notebook_window_treat_h_box_9,
              *notebook_window_treat_h_box_10, *notebook_window_treat_h_box_11, *notebook_window_treat_h_box_12,
              *notebook_window_treat_h_box_13, *notebook_window_treat_h_box_14, *notebook_window_treat_h_box_15,
              *notebook_window_treat_h_box_16, *notebook_window_treat_h_box_17, *notebook_window_treat_h_box_18,
              *notebook_window_treat_h_box_19, *notebook_window_treat_h_box_20, *notebook_window_treat_h_box_21,
              *notebook_window_treat_h_box_22,
              *notebook_window_treat_fixed_1, *notebook_window_treat_fixed_2, *notebook_window_treat_fixed_3,
              *notebook_window_treat_fixed_4, *notebook_window_treat_fixed_5, *notebook_window_treat_fixed_6,
              *notebook_window_treat_fixed_7, *notebook_window_treat_fixed_8, *notebook_window_treat_fixed_9,
              *notebook_window_treat_fixed_10, *notebook_window_treat_fixed_11, *notebook_window_treat_fixed_12,
              *notebook_window_treat_fixed_13, *notebook_window_treat_fixed_14, *notebook_window_treat_fixed_15,
              *notebook_window_treat_fixed_16, *notebook_window_treat_fixed_17, *notebook_window_treat_fixed_18,
              *notebook_window_treat_fixed_19, *notebook_window_treat_fixed_20, *notebook_window_treat_fixed_21,
              *notebook_window_treat_fixed_22, *notebook_window_treat_fixed_23, *notebook_window_treat_fixed_24,
              *notebook_window_treat_fixed_25, *notebook_window_treat_fixed_26, *notebook_window_treat_fixed_27,
              *notebook_window_treat_fixed_28, *notebook_window_treat_fixed_29, *notebook_window_treat_fixed_30,
              *notebook_window_treat_fixed_31, *notebook_window_treat_fixed_32, *notebook_window_treat_fixed_33,
              *notebook_window_treat_fixed_34, *notebook_window_treat_fixed_35, *notebook_window_treat_fixed_36,
              *notebook_window_treat_fixed_37, *notebook_window_treat_fixed_38, *notebook_window_treat_fixed_39,
              *notebook_window_treat_fixed_40, *notebook_window_treat_fixed_41, *notebook_window_treat_fixed_42,
              *notebook_window_treat_h_separator_1, *notebook_window_treat_h_separator_2, *notebook_window_treat_h_separator_3;
    GtkWidget *notebook_window_treat_label_new,
              *notebook_window_treat_label_new_physiology, *notebook_window_treat_label_new_violence,
              *notebook_window_treat_label_new_autotomy, *notebook_window_treat_label_new_selfstl,
              *notebook_window_treat_label_new_idioctonia,
              *notebook_window_treat_label_history,
              *notebook_window_treat_label_history_physiology, *notebook_window_treat_label_history_mentality,
              *notebook_window_treat_label_history_hospital, *notebook_window_treat_label_history_violence,
              *notebook_window_treat_label_history_autotomy, *notebook_window_treat_label_history_selfstl,
              *notebook_window_treat_label_history_idioctonia, *notebook_window_treat_label_history_ds,
              *notebook_window_treat_label_history_infect,
              *notebook_window_treat_label_diagnose,
              *notebook_window_treat_label_medicine,
              *notebook_window_treat_label_void_1;
    GtkWidget *notebook_window_treat_scrolled_new_physiology, *notebook_window_treat_scrolled_new_violence,
              *notebook_window_treat_scrolled_new_autotomy, *notebook_window_treat_scrolled_new_selfstl,
              *notebook_window_treat_scrolled_new_idioctonia,
              *notebook_window_treat_scrolled_history_physiology, *notebook_window_treat_scrolled_history_mentality,
              *notebook_window_treat_scrolled_history_hospital, *notebook_window_treat_scrolled_history_violence,
              *notebook_window_treat_scrolled_history_autotomy, *notebook_window_treat_scrolled_history_selfstl,
              *notebook_window_treat_scrolled_history_idioctonia, *notebook_window_treat_scrolled_history_ds,
              *notebook_window_treat_scrolled_history_infect,
              *notebook_window_treat_scrolled_diagnose, *notebook_window_treat_scrolled_medicine;
    GtkWidget *notebook_window_treat_text_new_physiology, *notebook_window_treat_text_new_violence,
              *notebook_window_treat_text_new_autotomy, *notebook_window_treat_text_new_selfstl,
              *notebook_window_treat_text_new_idioctonia,
              *notebook_window_treat_text_history_physiology, *notebook_window_treat_text_history_mentality,
              *notebook_window_treat_text_history_hospital, *notebook_window_treat_text_history_violence,
              *notebook_window_treat_text_history_autotomy,  *notebook_window_treat_text_history_selfstl,
              *notebook_window_treat_text_history_idioctonia, *notebook_window_treat_text_history_ds,
              *notebook_window_treat_text_history_infect,
              *notebook_window_treat_text_diagnose, *notebook_window_treat_text_medicine;
    GtkWidget *notebook_window_treat_combo_new_level_1, *notebook_window_treat_combo_new_level_2,
              *notebook_window_treat_combo_new_level_3, *notebook_window_treat_combo_new_level_4;
    GtkWidget *notebook_window_treat_button_diagnose, *notebook_window_treat_button_medicine;
    /* ------------------------------------- notebook_window_grade部分声明 ---------------------------------------------- */
    /* ---------------------------------------------------------------------------------------------------------------- */
    /* 编辑按钮及其所需框架声明 */
    GtkWidget *edit_button_check;
    GtkWidget *edit_button_ok, *edit_button_cancel;
    GtkWidget *edit_button_alignment_left, *edit_button_alignment_right;
    GtkWidget *edit_h_box, *edit_h_box_left, *edit_h_box_right;
    /* v_box框架声明 */
    GtkWidget *main_window_v_box;

    /* 每个GTK+程序必不可少的部分 */
    gtk_init(&argc, &argv);

    /* 创建主窗口 */
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* 设置主窗口名称 */
    gtk_window_set_title(GTK_WINDOW(main_window), "FWD");
    /* 设置主窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    /* 设置主窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(main_window), 840, 640);
    gtk_widget_set_size_request(GTK_WIDGET(main_window), 840, 640);
    gtk_window_set_resizable(GTK_WINDOW(main_window), FALSE);
    /* 将destroy信号与主窗口连接 */
    g_signal_connect(G_OBJECT(main_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建菜单栏 */
    menu_bar = gtk_menu_bar_new();
    /* 创建菜单外壳 */
    menu_file = gtk_menu_new();
    menu_make = gtk_menu_new();
    menu_data = gtk_menu_new();
    menu_help = gtk_menu_new();
    /* 创建各个菜单 */ /* 解决中文乱码，转为UTF-8编码格式 */
    menu_bar_file = gtk_menu_item_new_with_label("病例");
    menu_bar_make = gtk_menu_item_new_with_label("报表");
    menu_bar_data = gtk_menu_item_new_with_label("数据");
    menu_bar_help = gtk_menu_item_new_with_label("帮助");
    /* 创建各个菜单项 */
    menu_bar_file_new = gtk_menu_item_new_with_label("新建");
    menu_bar_file_open = gtk_menu_item_new_with_label("查看");
    menu_bar_file_delete = gtk_menu_item_new_with_label("删除");
    menu_bar_file_quit = gtk_menu_item_new_with_label("退出");
    menu_bar_make_status = gtk_menu_item_new_with_label("生成《危重病人救治情况月报表》");
    menu_bar_make_cost = gtk_menu_item_new_with_label("生成《危害病人救治费用明细表》");
    menu_bar_data_buckup = gtk_menu_item_new_with_label("备份所有数据");
    menu_bar_data_clean = gtk_menu_item_new_with_label("清除所有数据");
    menu_bar_help_show = gtk_menu_item_new_with_label("查看帮助");
    menu_bar_help_about = gtk_menu_item_new_with_label("关于FWD");
    menu_bar_item_separator_1 = gtk_separator_menu_item_new();
    menu_bar_item_separator_2 = gtk_separator_menu_item_new();
    menu_bar_item_separator_3 = gtk_separator_menu_item_new();
    menu_bar_item_separator_4 = gtk_separator_menu_item_new();
    /* 将各个菜单项加入到各自所属的菜单中 */
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_bar_file_new);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_bar_file_open);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_bar_file_delete);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_bar_item_separator_1);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_bar_file_quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_make), menu_bar_make_status);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_make), menu_bar_item_separator_2);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_make), menu_bar_make_cost);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_data), menu_bar_data_buckup);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_data), menu_bar_item_separator_3);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_data), menu_bar_data_clean);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_help), menu_bar_help_show);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_help), menu_bar_item_separator_4);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_help), menu_bar_help_about);
    /* 将菜单与菜单外壳相关联 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar_file), menu_file);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar_make), menu_make);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar_data), menu_data);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_bar_help), menu_help);
    /* 蒋各个菜单分别加入到菜单栏中 */
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_bar_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_bar_make);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_bar_data);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_bar_help);
    /* 将菜单项与各自的信号相关联 */
    g_signal_connect(G_OBJECT(menu_bar_file_quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(menu_bar_help_about), "activate", G_CALLBACK(menu_bar_help_callback), (gpointer)main_window);
    /* */

    /* 创建notebook控件 */
    notebook = gtk_notebook_new();
    /* 设置标签页为底部显示 */
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_BOTTOM);
    /* 设置标签页文字 */
    notebook_label_person = gtk_label_new("个人信息");
    notebook_label_treat = gtk_label_new("医疗信息");
    notebook_label_grade = gtk_label_new("相关量表测评");
    /* 创建标签内需要包含的滚动窗口 */
    notebook_window_person = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_grade = gtk_scrolled_window_new(NULL, NULL);
    /* 设置滚动条出现的方式为“自动” */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_grade), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    /* ------------------------------------------- 创建notebook_window_person部分 --------------------------------------------------- */
    /* 创建滚动窗口notebook_window_person内部的框架 */
    notebook_window_person_v_box = gtk_vbox_new(FALSE, 0);
    notebook_window_person_table_1 = gtk_table_new(3, 5, FALSE);
    notebook_window_person_table_2 = gtk_table_new(2, 3, FALSE);
    notebook_window_person_fixed_1 = gtk_fixed_new();
    notebook_window_person_fixed_2 = gtk_fixed_new();
    notebook_window_person_fixed_3 = gtk_fixed_new();
    notebook_window_person_fixed_4 = gtk_fixed_new();
    notebook_window_person_fixed_5 = gtk_fixed_new();
    notebook_window_person_fixed_6 = gtk_fixed_new();
    notebook_window_person_fixed_7 = gtk_fixed_new();
    notebook_window_person_fixed_8 = gtk_fixed_new();
    notebook_window_person_fixed_9 = gtk_fixed_new();
    notebook_window_person_fixed_10 = gtk_fixed_new();
    notebook_window_person_fixed_11 = gtk_fixed_new();
    notebook_window_person_fixed_12 = gtk_fixed_new();
    notebook_window_person_fixed_13 = gtk_fixed_new();
    notebook_window_person_fixed_14 = gtk_fixed_new();
    notebook_window_person_fixed_15 = gtk_fixed_new();
    notebook_window_person_fixed_16 = gtk_fixed_new();
    notebook_window_person_fixed_17 = gtk_fixed_new();
    notebook_window_person_fixed_18 = gtk_fixed_new();
    notebook_window_person_fixed_19 = gtk_fixed_new();
    notebook_window_person_fixed_20 = gtk_fixed_new();
    notebook_window_person_fixed_21 = gtk_fixed_new();
    notebook_window_person_fixed_22 = gtk_fixed_new();
    notebook_window_person_fixed_23 = gtk_fixed_new();
    notebook_window_person_fixed_24 = gtk_fixed_new();
    notebook_window_person_fixed_25 = gtk_fixed_new();
    notebook_window_person_fixed_26 = gtk_fixed_new();
    notebook_window_person_fixed_27 = gtk_fixed_new();
    notebook_window_person_fixed_28 = gtk_fixed_new();
    notebook_window_person_fixed_29 = gtk_fixed_new();
    notebook_window_person_fixed_30 = gtk_fixed_new();
    notebook_window_person_fixed_31 = gtk_fixed_new();
    notebook_window_person_fixed_32 = gtk_fixed_new();
    notebook_window_person_fixed_33 = gtk_fixed_new();
    notebook_window_person_fixed_34 = gtk_fixed_new();
    notebook_window_person_fixed_35 = gtk_fixed_new();
    notebook_window_person_fixed_36 = gtk_fixed_new();
    notebook_window_person_fixed_37 = gtk_fixed_new();
    notebook_window_person_fixed_38 = gtk_fixed_new();
    notebook_window_person_fixed_39 = gtk_fixed_new();
    notebook_window_person_fixed_40 = gtk_fixed_new();
    notebook_window_person_fixed_41 = gtk_fixed_new();
    notebook_window_person_fixed_42 = gtk_fixed_new();
    notebook_window_person_fixed_43 = gtk_fixed_new();
    notebook_window_person_fixed_44 = gtk_fixed_new();
    notebook_window_person_fixed_45 = gtk_fixed_new();
    notebook_window_person_fixed_46 = gtk_fixed_new();
    notebook_window_person_fixed_47 = gtk_fixed_new();
    notebook_window_person_h_box_1 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_2 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_3 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_4 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_5 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_6 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_7 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_8 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_9 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_10 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_11 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_12 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_13 = gtk_hbox_new(FALSE, 0);
    notebook_window_person_h_box_14 = gtk_hbox_new(FALSE, 0);   /* 不一定有用 */
    notebook_window_person_h_separator_1 = gtk_hseparator_new();
    notebook_window_person_h_separator_2 = gtk_hseparator_new();
    notebook_window_person_scrolled_describe = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_person_scrolled_result = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_person_scrolled_diagnose = gtk_scrolled_window_new(NULL, NULL);
    /* 创建滚动窗口notebook_window_person内部的控件 */
    notebook_window_person_label_name = gtk_label_new("姓名：");
    notebook_window_person_label_sex = gtk_label_new("性别：");
    notebook_window_person_label_age = gtk_label_new("年龄：");
    notebook_window_person_label_birthday = gtk_label_new("生日：");
    notebook_window_person_label_credentials = gtk_label_new("有效证件：");
    notebook_window_person_label_marriage = gtk_label_new("婚姻状况：");
    notebook_window_person_label_education = gtk_label_new("文化程度：");
    notebook_window_person_label_place = gtk_label_new("事发地点：");
    notebook_window_person_label_dangerous = gtk_label_new("危险行为详情：");
    notebook_window_person_label_happen = gtk_label_new("发生时间：");
    notebook_window_person_label_describe = gtk_label_new("行为描述：");
    notebook_window_person_label_property = gtk_label_new("行为性质：");
    notebook_window_person_label_result = gtk_label_new("行为后果：");
    notebook_window_person_label_level = gtk_label_new("行为分级：");
    notebook_window_person_label_diagnose = gtk_label_new("诊断结果：");
    notebook_window_person_label_into = gtk_label_new("入院时间：");
    notebook_window_person_label_receipt = gtk_label_new("三联单编号：");
    notebook_window_person_label_ad = gtk_label_new("住院号：");
    notebook_window_person_label_days = gtk_label_new("住院天数：");
    notebook_window_person_label_out = gtk_label_new("出院时间：");
    notebook_window_person_label_goto = gtk_label_new("患者去向：");
    notebook_window_person_label_void = gtk_label_new(" ");
    notebook_window_person_button_photo = gtk_button_new();
    notebook_window_person_button_diagnose = gtk_button_new_with_label("点击选择");
    notebook_window_person_text_name = gtk_entry_new();
    notebook_window_person_text_age = gtk_entry_new();
    notebook_window_person_text_birthday = gtk_entry_new();
    notebook_window_person_text_happen = gtk_entry_new();
    notebook_window_person_text_into = gtk_entry_new();
    notebook_window_person_text_out = gtk_entry_new();
    notebook_window_person_text_credentials = gtk_entry_new();
    notebook_window_person_text_describe = gtk_text_view_new();
    notebook_window_person_text_result = gtk_text_view_new();
    notebook_window_person_text_diagnose = gtk_text_view_new();
    notebook_window_person_text_receipt = gtk_entry_new();
    notebook_window_person_text_ad = gtk_entry_new();
    notebook_window_person_text_days = gtk_entry_new();
    notebook_window_person_combo_sex = gtk_combo_box_text_new();
    notebook_window_person_combo_credentials = gtk_combo_box_text_new();
    notebook_window_person_combo_marriage = gtk_combo_box_text_new();
    notebook_window_person_combo_education = gtk_combo_box_text_new();
    notebook_window_person_combo_place = gtk_combo_box_text_new();
    notebook_window_person_combo_property = gtk_combo_box_text_new();
    notebook_window_person_combo_level = gtk_combo_box_text_new();
    notebook_window_person_combo_goto = gtk_combo_box_text_new();
    /* 设置滚动窗口notebook_window_person内部控件的默认大小 */
    gtk_widget_set_size_request(notebook_window_person_button_photo, 100, 150); /* 注意调整一下尺寸 */
    gtk_widget_set_size_request(notebook_window_person_label_name, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_name, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_sex, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_sex, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_age, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_age, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_birthday, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_birthday, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_credentials, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_credentials, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_credentials, 375, 25);
    gtk_widget_set_size_request(notebook_window_person_label_marriage, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_marriage, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_education, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_education, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_dangerous, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_happen, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_happen, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_place, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_place, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_describe, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_scrolled_describe, 500, 100);
    gtk_widget_set_size_request(notebook_window_person_label_property, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_property, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_result, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_scrolled_result, 500, 100);
    gtk_widget_set_size_request(notebook_window_person_label_level, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_level, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_button_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_scrolled_diagnose, 375, 100);
    gtk_widget_set_size_request(notebook_window_person_label_into, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_into, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_receipt, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_receipt, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_ad, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_ad, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_out, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_out, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_days, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_days, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_goto, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_goto, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_void, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_h_separator_1, 625, 25);
    gtk_widget_set_size_request(notebook_window_person_h_separator_2, 625, 25);
    /* 设置各个combo_box_text内部内容 */ /* 关于行为性质部分医院文档内并未说面，需要联系咨询 */
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_sex), "男");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_sex), "女");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_sex), "不祥");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_marriage), "未婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_marriage), "已婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_marriage), "再婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_marriage), "离异");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_marriage), "不祥");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_education), "文盲");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_education), "小学");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_education), "初中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_education), "高中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_education), "本科及本科以上");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_credentials), "身份证");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_credentials), "户籍所在地证明");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "莲湖区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "碑林区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "雁塔区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "新城区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "未央区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_place), "长安区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "0级：无符合以下1——5级中的任何行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "1级：口头威胁、喊叫、但没有打砸行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "2级：打砸行为，局限在家里，针对财物；不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "3级：明显打砸行为，不分场合，针对财物或人，不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "4级：连续的打砸行为，不分场合，针对财物或人，不能接受劝说而停止；包括自伤、自杀");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_level), "5级：持械针对的任何暴力行为，或者纵火、爆炸等行为；无论在家里还是公共场合");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_goto), "救助站接走");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_goto), "转院（包括：市二院、市按摩院、西安医学院附属医院市结核医院）");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(notebook_window_person_combo_goto), "家属接走");
    /* 关于notebook_window_person_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_describe), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_result), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_diagnose), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_describe), notebook_window_person_text_describe);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_result), notebook_window_person_text_result);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_diagnose), notebook_window_person_text_diagnose);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_1), GTK_WIDGET(notebook_window_person_button_photo), 100, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_2), GTK_WIDGET(notebook_window_person_label_name), 25, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_3), GTK_WIDGET(notebook_window_person_text_name), 0, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_4), GTK_WIDGET(notebook_window_person_label_sex), 100, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_5), GTK_WIDGET(notebook_window_person_combo_sex), 0, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_6), GTK_WIDGET(notebook_window_person_label_age), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_7), GTK_WIDGET(notebook_window_person_text_age), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_8), GTK_WIDGET(notebook_window_person_label_birthday), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_9), GTK_WIDGET(notebook_window_person_text_birthday), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_10), GTK_WIDGET(notebook_window_person_label_marriage), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_11), GTK_WIDGET(notebook_window_person_combo_marriage), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_12), GTK_WIDGET(notebook_window_person_label_education), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_13), GTK_WIDGET(notebook_window_person_combo_education), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_14), GTK_WIDGET(notebook_window_person_label_credentials), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_15), GTK_WIDGET(notebook_window_person_combo_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_16), GTK_WIDGET(notebook_window_person_text_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_17), GTK_WIDGET(notebook_window_person_h_separator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_18), GTK_WIDGET(notebook_window_person_label_dangerous), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_19), GTK_WIDGET(notebook_window_person_label_happen), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_20), GTK_WIDGET(notebook_window_person_text_happen), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_21), GTK_WIDGET(notebook_window_person_label_place), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_22), GTK_WIDGET(notebook_window_person_combo_place), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_23), GTK_WIDGET(notebook_window_person_label_describe), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_24), GTK_WIDGET(notebook_window_person_scrolled_describe), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_25), GTK_WIDGET(notebook_window_person_label_result), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_26), GTK_WIDGET(notebook_window_person_scrolled_result), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_27), GTK_WIDGET(notebook_window_person_label_property), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_28), GTK_WIDGET(notebook_window_person_combo_property), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_29), GTK_WIDGET(notebook_window_person_label_level), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_30), GTK_WIDGET(notebook_window_person_combo_level), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_31), GTK_WIDGET(notebook_window_person_label_diagnose), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_32), GTK_WIDGET(notebook_window_person_button_diagnose), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_33), GTK_WIDGET(notebook_window_person_h_separator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_34), GTK_WIDGET(notebook_window_person_label_receipt), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_35), GTK_WIDGET(notebook_window_person_text_receipt), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_36), GTK_WIDGET(notebook_window_person_label_ad), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_37), GTK_WIDGET(notebook_window_person_text_ad), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_38), GTK_WIDGET(notebook_window_person_label_into), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_39), GTK_WIDGET(notebook_window_person_text_into), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_40), GTK_WIDGET(notebook_window_person_label_out), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_41), GTK_WIDGET(notebook_window_person_text_out), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_42), GTK_WIDGET(notebook_window_person_label_days), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_43), GTK_WIDGET(notebook_window_person_text_days), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_44), GTK_WIDGET(notebook_window_person_label_goto), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_45), GTK_WIDGET(notebook_window_person_combo_goto), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_46), GTK_WIDGET(notebook_window_person_label_void), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_47), GTK_WIDGET(notebook_window_person_scrolled_diagnose), 25, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_1, 0, 1, 0, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_3 , 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_5, 4, 5, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_9, 4, 5, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_1), notebook_window_person_fixed_13, 4, 5, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_2), notebook_window_person_fixed_31, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_2), notebook_window_person_fixed_32, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table_2), notebook_window_person_fixed_47, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_1), notebook_window_person_fixed_14, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_1), notebook_window_person_fixed_15, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_1), notebook_window_person_fixed_16, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_2), notebook_window_person_fixed_17, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_3), notebook_window_person_fixed_18, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_4), notebook_window_person_fixed_19, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_4), notebook_window_person_fixed_20, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_4), notebook_window_person_fixed_21, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_4), notebook_window_person_fixed_22, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_5), notebook_window_person_fixed_23, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_5), notebook_window_person_fixed_24, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_6), notebook_window_person_fixed_25, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_6), notebook_window_person_fixed_26, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_7), notebook_window_person_fixed_27, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_7), notebook_window_person_fixed_28, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_7), notebook_window_person_fixed_29, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_7), notebook_window_person_fixed_30, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_9), notebook_window_person_fixed_33, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_10), notebook_window_person_fixed_34, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_10), notebook_window_person_fixed_35, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_10), notebook_window_person_fixed_36, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_10), notebook_window_person_fixed_37, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_11), notebook_window_person_fixed_38, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_11), notebook_window_person_fixed_39, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_11), notebook_window_person_fixed_40, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_11), notebook_window_person_fixed_41, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_12), notebook_window_person_fixed_42, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_12), notebook_window_person_fixed_43, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_12), notebook_window_person_fixed_44, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_12), notebook_window_person_fixed_45, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_13), notebook_window_person_fixed_46, FALSE, FALSE, 0);
    /* 将控件、相关回调函数以及信号相关联 */
    /* */
    /* 将各个框架加入到notebook_window_person_v_box之中 */
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_11, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_12, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_13, FALSE, FALSE, 0);
    /* 将notebook_window_person_v_box加入到notebook_window_person之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person), notebook_window_person_v_box);
    /* --------------------------------------------------------------------------------------------------------- */



    /* ---------------------------------------------------------- notebook_window_treat部分 ------------------------------------------------------------- */
    /* 创建滚动窗口notebook_window_treat内部的框架 */
    notebook_window_treat_v_box = gtk_vbox_new(FALSE, 0);
    notebook_window_treat_table_1 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_table_2 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_table_3 = gtk_table_new( 2, 2, FALSE);
    notebook_window_treat_table_4 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_table_5 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_table_6 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_table_7 = gtk_table_new( 2, 3, FALSE);
    notebook_window_treat_h_box_1 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_2 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_3 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_4 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_5 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_6 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_7 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_8 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_9 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_10 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_11 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_12 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_13 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_14 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_15 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_16 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_17 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_18 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_19 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_20 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_21 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_h_box_22 = gtk_hbox_new(FALSE, 0);
    notebook_window_treat_fixed_1 = gtk_fixed_new();
    notebook_window_treat_fixed_2 = gtk_fixed_new();
    notebook_window_treat_fixed_3 = gtk_fixed_new();
    notebook_window_treat_fixed_4 = gtk_fixed_new();
    notebook_window_treat_fixed_5 = gtk_fixed_new();
    notebook_window_treat_fixed_6 = gtk_fixed_new();
    notebook_window_treat_fixed_7 = gtk_fixed_new();
    notebook_window_treat_fixed_8 = gtk_fixed_new();
    notebook_window_treat_fixed_9 = gtk_fixed_new();
    notebook_window_treat_fixed_10 = gtk_fixed_new();
    notebook_window_treat_fixed_11 = gtk_fixed_new();
    notebook_window_treat_fixed_12 = gtk_fixed_new();
    notebook_window_treat_fixed_13 = gtk_fixed_new();
    notebook_window_treat_fixed_14 = gtk_fixed_new();
    notebook_window_treat_fixed_15 = gtk_fixed_new();
    notebook_window_treat_fixed_16 = gtk_fixed_new();
    notebook_window_treat_fixed_17 = gtk_fixed_new();
    notebook_window_treat_fixed_18 = gtk_fixed_new();
    notebook_window_treat_fixed_19 = gtk_fixed_new();
    notebook_window_treat_fixed_20 = gtk_fixed_new();
    notebook_window_treat_fixed_21 = gtk_fixed_new();
    notebook_window_treat_fixed_22 = gtk_fixed_new();
    notebook_window_treat_fixed_23 = gtk_fixed_new();
    notebook_window_treat_fixed_24 = gtk_fixed_new();
    notebook_window_treat_fixed_25 = gtk_fixed_new();
    notebook_window_treat_fixed_26 = gtk_fixed_new();
    notebook_window_treat_fixed_27 = gtk_fixed_new();
    notebook_window_treat_fixed_28 = gtk_fixed_new();
    notebook_window_treat_fixed_29 = gtk_fixed_new();
    notebook_window_treat_fixed_30 = gtk_fixed_new();
    notebook_window_treat_fixed_31 = gtk_fixed_new();
    notebook_window_treat_fixed_32 = gtk_fixed_new();
    notebook_window_treat_fixed_33 = gtk_fixed_new();
    notebook_window_treat_fixed_34 = gtk_fixed_new();
    notebook_window_treat_fixed_35 = gtk_fixed_new();
    notebook_window_treat_fixed_36 = gtk_fixed_new();
    notebook_window_treat_fixed_37 = gtk_fixed_new();
    notebook_window_treat_fixed_38 = gtk_fixed_new();
    notebook_window_treat_fixed_39 = gtk_fixed_new();
    notebook_window_treat_fixed_40 = gtk_fixed_new();
    notebook_window_treat_fixed_41 = gtk_fixed_new();
    notebook_window_treat_fixed_42 = gtk_fixed_new();
    notebook_window_treat_scrolled_new_physiology = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_new_violence = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_new_autotomy = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_new_selfstl = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_new_idioctonia = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_physiology = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_mentality = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_hospital = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_violence = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_autotomy = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_selfstl = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_idioctonia = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_ds = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_history_infect = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_diagnose = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_scrolled_medicine = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_treat_h_separator_1 = gtk_hseparator_new();
    notebook_window_treat_h_separator_2 = gtk_hseparator_new();
    /* 创建滚动窗口notebook_window_treat内部的控件 */
    notebook_window_treat_label_diagnose = gtk_label_new("疾病诊断：");
    notebook_window_treat_label_medicine = gtk_label_new("药物治疗：");
    notebook_window_treat_label_new = gtk_label_new("最新记录：");
    notebook_window_treat_label_new_physiology = gtk_label_new("躯体疾病：");
    notebook_window_treat_label_new_violence = gtk_label_new("暴力行为：");
    notebook_window_treat_label_new_autotomy = gtk_label_new("自残行为：");
    notebook_window_treat_label_new_selfstl = gtk_label_new("自伤行为：");
    notebook_window_treat_label_new_idioctonia = gtk_label_new("自杀行为：");
    notebook_window_treat_label_history_physiology = gtk_label_new("既往躯体疾病史：");
    notebook_window_treat_label_history_mentality = gtk_label_new("既往精神障碍相关疾病史：");
    notebook_window_treat_label_history_hospital = gtk_label_new("既往住院治疗史：");
    notebook_window_treat_label_history_violence = gtk_label_new("既往（一月内）暴力行为记录：");
    notebook_window_treat_label_history_autotomy = gtk_label_new("既往（一月内）自残行为记录：");
    notebook_window_treat_label_history_selfstl = gtk_label_new("既往（一月内）自伤行为记录：");
    notebook_window_treat_label_history_idioctonia = gtk_label_new("既往（一月内）自杀行为记录：");
    notebook_window_treat_label_history_ds = gtk_label_new("既往吸烟及饮酒史：");
    notebook_window_treat_label_history_infect = gtk_label_new("既往传染病史：");
    notebook_window_treat_label_void_1 = gtk_label_new(" ");
    notebook_window_treat_text_diagnose = gtk_text_view_new();
    notebook_window_treat_text_medicine = gtk_text_view_new();
    notebook_window_treat_text_new_physiology = gtk_text_view_new();
    notebook_window_treat_text_new_violence = gtk_text_view_new();
    notebook_window_treat_text_new_autotomy = gtk_text_view_new();
    notebook_window_treat_text_new_selfstl = gtk_text_view_new();
    notebook_window_treat_text_new_idioctonia = gtk_text_view_new();
    notebook_window_treat_text_history_physiology = gtk_text_view_new();
    notebook_window_treat_text_history_mentality = gtk_text_view_new();
    notebook_window_treat_text_history_hospital = gtk_text_view_new();
    notebook_window_treat_text_history_violence = gtk_text_view_new();
    notebook_window_treat_text_history_autotomy = gtk_text_view_new();
    notebook_window_treat_text_history_selfstl = gtk_text_view_new();
    notebook_window_treat_text_history_idioctonia = gtk_text_view_new();
    notebook_window_treat_text_history_ds = gtk_text_view_new();
    notebook_window_treat_text_history_infect = gtk_text_view_new();
    notebook_window_treat_button_diagnose = gtk_button_new_with_label("点击选择");
    notebook_window_treat_button_medicine = gtk_button_new_with_label("点击选择");
    notebook_window_treat_combo_new_level_1 = gtk_combo_box_text_new();
    notebook_window_treat_combo_new_level_2 = gtk_combo_box_text_new();
    notebook_window_treat_combo_new_level_3 = gtk_combo_box_text_new();
    notebook_window_treat_combo_new_level_4 = gtk_combo_box_text_new();
    /* 设置滚动窗口notebook_window_treat内部控件的默认大小 */
    gtk_widget_set_size_request(notebook_window_treat_label_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_button_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_diagnose, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_medicine, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_button_medicine, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_medicine, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_h_separator_1, 625, 25);
    gtk_widget_set_size_request(notebook_window_treat_label_new, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_label_new_physiology, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_new_physiology, 500, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_new_violence, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_combo_new_level_1, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_new_violence, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_new_autotomy, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_combo_new_level_2, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_new_autotomy, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_new_selfstl, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_combo_new_level_3, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_new_selfstl, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_new_idioctonia, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_combo_new_level_4, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_new_idioctonia, 375, 100);
    gtk_widget_set_size_request(notebook_window_treat_h_separator_2, 625, 25);
    gtk_widget_set_size_request(notebook_window_treat_label_history_physiology, 95, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_physiology, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_mentality, 140, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_mentality, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_hospital, 95, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_hospital, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_violence, 165, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_violence, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_autotomy, 165, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_autotomy, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_selfstl, 165, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_selfstl, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_idioctonia, 165, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_idioctonia, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_ds, 100, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_ds, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_history_infect, 85, 25);
    gtk_widget_set_size_request(notebook_window_treat_scrolled_history_infect, 625, 100);
    gtk_widget_set_size_request(notebook_window_treat_label_void_1, 100, 25);
    /* 添加notebook_window_treat_combo*控件内容 */ /* 关于严重程度方面医院文档内部并未详细说面，需要联系咨询 */
    /* 关于notebook_window_treat_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_diagnose), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_medicine), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_physiology), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_violence), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_autotomy), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_selfstl), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_idioctonia), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_physiology), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_mentality), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_hospital), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_violence), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_autotomy), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_selfstl), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_idioctonia), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_ds), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_infect), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_diagnose), notebook_window_treat_text_diagnose);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_medicine), notebook_window_treat_text_medicine);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_physiology), notebook_window_treat_text_new_physiology);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_violence), notebook_window_treat_text_new_violence);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_autotomy), notebook_window_treat_text_new_autotomy);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_selfstl), notebook_window_treat_text_new_selfstl);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_new_idioctonia), notebook_window_treat_text_new_idioctonia);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_physiology), notebook_window_treat_text_history_physiology);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_mentality), notebook_window_treat_text_history_mentality);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_hospital), notebook_window_treat_text_history_hospital);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_violence), notebook_window_treat_text_history_violence);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_autotomy), notebook_window_treat_text_history_autotomy);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_selfstl), notebook_window_treat_text_history_selfstl);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_idioctonia), notebook_window_treat_text_history_idioctonia);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_ds), notebook_window_treat_text_history_ds);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat_scrolled_history_infect), notebook_window_treat_text_history_infect);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_1), GTK_WIDGET(notebook_window_treat_label_diagnose), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_2), GTK_WIDGET(notebook_window_treat_button_diagnose), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_3), GTK_WIDGET(notebook_window_treat_scrolled_diagnose), 25, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_4), GTK_WIDGET(notebook_window_treat_label_medicine), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_5), GTK_WIDGET(notebook_window_treat_button_medicine), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_6), GTK_WIDGET(notebook_window_treat_scrolled_medicine), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_7), GTK_WIDGET(notebook_window_treat_h_separator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_8), GTK_WIDGET(notebook_window_treat_label_new), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_9), GTK_WIDGET(notebook_window_treat_label_new_physiology), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_10), GTK_WIDGET(notebook_window_treat_scrolled_new_physiology), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_11), GTK_WIDGET(notebook_window_treat_label_new_violence), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_12), GTK_WIDGET(notebook_window_treat_combo_new_level_1), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_13), GTK_WIDGET(notebook_window_treat_scrolled_new_violence), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_14), GTK_WIDGET(notebook_window_treat_label_new_autotomy), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_15), GTK_WIDGET(notebook_window_treat_combo_new_level_2), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_16), GTK_WIDGET(notebook_window_treat_scrolled_new_autotomy), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_17), GTK_WIDGET(notebook_window_treat_label_new_selfstl), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_18), GTK_WIDGET(notebook_window_treat_combo_new_level_3), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_19), GTK_WIDGET(notebook_window_treat_scrolled_new_selfstl), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_20), GTK_WIDGET(notebook_window_treat_label_new_idioctonia), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_21), GTK_WIDGET(notebook_window_treat_combo_new_level_4), 25, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_22), GTK_WIDGET(notebook_window_treat_scrolled_new_idioctonia), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_23), GTK_WIDGET(notebook_window_treat_h_separator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_24), GTK_WIDGET(notebook_window_treat_label_history_physiology), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_25), GTK_WIDGET(notebook_window_treat_scrolled_history_physiology), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_26), GTK_WIDGET(notebook_window_treat_label_history_mentality), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_27), GTK_WIDGET(notebook_window_treat_scrolled_history_mentality), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_28), GTK_WIDGET(notebook_window_treat_label_history_hospital), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_29), GTK_WIDGET(notebook_window_treat_scrolled_history_hospital), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_30), GTK_WIDGET(notebook_window_treat_label_history_violence), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_31), GTK_WIDGET(notebook_window_treat_scrolled_history_violence), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_32), GTK_WIDGET(notebook_window_treat_label_history_autotomy), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_33), GTK_WIDGET(notebook_window_treat_scrolled_history_autotomy), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_34), GTK_WIDGET(notebook_window_treat_label_history_selfstl), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_35), GTK_WIDGET(notebook_window_treat_scrolled_history_selfstl), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_36), GTK_WIDGET(notebook_window_treat_label_history_idioctonia), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_37), GTK_WIDGET(notebook_window_treat_scrolled_history_idioctonia), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_38), GTK_WIDGET(notebook_window_treat_label_history_ds), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_39), GTK_WIDGET(notebook_window_treat_scrolled_history_ds), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_40), GTK_WIDGET(notebook_window_treat_label_history_infect), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_41), GTK_WIDGET(notebook_window_treat_scrolled_history_infect), 100, 0);
    gtk_fixed_put(GTK_FIXED(notebook_window_treat_fixed_42), GTK_WIDGET(notebook_window_treat_label_void_1), 100, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_1), notebook_window_treat_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_1), notebook_window_treat_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_1), notebook_window_treat_fixed_3, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_2), notebook_window_treat_fixed_4, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_2), notebook_window_treat_fixed_5, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_2), notebook_window_treat_fixed_6, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_1), notebook_window_treat_fixed_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_2), notebook_window_treat_fixed_8, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_3), notebook_window_treat_fixed_9, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_3), notebook_window_treat_fixed_10, 1, 2, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_4), notebook_window_treat_fixed_11, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_4), notebook_window_treat_fixed_12, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_4), notebook_window_treat_fixed_13, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_5), notebook_window_treat_fixed_14, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_5), notebook_window_treat_fixed_15, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_5), notebook_window_treat_fixed_16, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_6), notebook_window_treat_fixed_17, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_6), notebook_window_treat_fixed_18, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_6), notebook_window_treat_fixed_19, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_7), notebook_window_treat_fixed_20, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_7), notebook_window_treat_fixed_21, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_treat_table_7), notebook_window_treat_fixed_22, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_3), notebook_window_treat_fixed_23, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_4), notebook_window_treat_fixed_24, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_5), notebook_window_treat_fixed_25, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_6), notebook_window_treat_fixed_26, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_7), notebook_window_treat_fixed_27, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_8), notebook_window_treat_fixed_28, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_9), notebook_window_treat_fixed_29, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_10), notebook_window_treat_fixed_30, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_11), notebook_window_treat_fixed_31, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_12), notebook_window_treat_fixed_32, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_13), notebook_window_treat_fixed_33, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_14), notebook_window_treat_fixed_34, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_15), notebook_window_treat_fixed_35, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_16), notebook_window_treat_fixed_36, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_17), notebook_window_treat_fixed_37, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_18), notebook_window_treat_fixed_38, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_19), notebook_window_treat_fixed_39, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_20), notebook_window_treat_fixed_40, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_21), notebook_window_treat_fixed_41, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_h_box_22), notebook_window_treat_fixed_42, FALSE, FALSE, 0);
    /* 将控件、相关回调函数以及信号相关联 */
    /* */
    /* 将各个框架加入到notebook_window_treat_v_box之中 */
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_table_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_8, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_11, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_12, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_13, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_14, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_15, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_16, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_17, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_18, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_19, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_20, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_21, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_treat_v_box), notebook_window_treat_h_box_22, FALSE, FALSE, 0);
    /* 将notebook_window_person_v_box加入到notebook_window_treat之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_treat), notebook_window_treat_v_box);
    /* -------------------------------------------------------------------------------------------------- */



    /* 将窗口放置到相应的标签页中 */
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), notebook_window_person, notebook_label_person);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), notebook_window_treat, notebook_label_treat);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), notebook_window_grade, notebook_label_grade);

    /* 创建编辑按钮 */
    edit_button_check = gtk_check_button_new_with_label("编辑");
    edit_button_ok = gtk_button_new_with_label("保存");
    edit_button_cancel = gtk_button_new_with_label("取消");
    /* 创建编辑按钮的对齐框架 */
    edit_h_box = gtk_hbox_new(TRUE, 2);
    edit_h_box_left = gtk_hbox_new(TRUE, 1);
    edit_h_box_right = gtk_hbox_new(TRUE, 2);
    edit_button_alignment_left = gtk_alignment_new(0, 0, 0, 0);
    edit_button_alignment_right = gtk_alignment_new(1, 0, 0, 0);
    /* 设置编辑按钮的默认大小 */
    gtk_widget_set_size_request(edit_button_check, 75, 25);
    gtk_widget_set_size_request(edit_button_ok, 75, 25);
    gtk_widget_set_size_request(edit_button_cancel, 75, 25);
    /* 将button_edit按钮设置为“只读”状态 */
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(edit_button_check), FALSE);
    /* 将编辑按钮加入到edit_h_box子项之中 */
    gtk_box_pack_start(GTK_BOX(edit_h_box_left), edit_button_check, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(edit_h_box_right), edit_button_ok, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(edit_h_box_right), edit_button_cancel, TRUE, TRUE, 0);
    /* 将edit_h_box子项放置到对齐框架之中 */
    gtk_container_add(GTK_CONTAINER(edit_button_alignment_left), edit_h_box_left);
    gtk_container_add(GTK_CONTAINER(edit_button_alignment_right), edit_h_box_right);
    /* 将对齐框架加入到edit_h_box之中 */
    gtk_box_pack_start(GTK_BOX(edit_h_box), edit_button_alignment_left, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(edit_h_box), edit_button_alignment_right, TRUE, TRUE, 0);
    /* 将编辑按钮与各自对应的回调函数相连接 */
    /* */

    /* 创建v_box框架 */
    main_window_v_box = gtk_vbox_new(FALSE, 0);
    /* 将v_box框架放置于主窗口之中 */
    gtk_container_add(GTK_CONTAINER(main_window), main_window_v_box);

    /* 将各个控件放置于v_box之中 */
    gtk_box_pack_start(GTK_BOX(main_window_v_box), menu_bar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_window_v_box), notebook, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(main_window_v_box), edit_h_box, FALSE, FALSE, 0);

    gtk_widget_show_all(main_window);
    gtk_main();
    return 0;
}
