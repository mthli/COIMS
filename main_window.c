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
              *notebook_window_person_table,
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
              *notebook_window_person_fixed_46,
              *notebook_window_person_h_box_1, *notebook_window_person_h_box_2, *notebook_window_person_h_box_3,
              *notebook_window_person_h_box_4, *notebook_window_person_h_box_5, *notebook_window_person_h_box_6,
              *notebook_window_person_h_box_7, *notebook_window_person_h_box_8, *notebook_window_person_h_box_9,
              *notebook_window_person_h_box_10, *notebook_window_person_h_box_11, *notebook_window_person_h_box_12,
              *notebook_window_person_h_box_13;
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
              *notebook_window_person_label_days, *notebook_window_person_label_out,
              *notebook_window_person_label_goto, *notebook_window_person_label_void;
    GtkWidget *notebook_window_person_button_photo, *notebook_window_person_button_birthday,
              *notebook_window_person_button_into, *notebook_window_person_button_out,
              *notebook_window_person_button_happen;
    GtkWidget *notebook_window_person_combo_box_sex, *notebook_window_person_combo_box_credentials,
              *notebook_window_person_combo_box_education, *notebook_window_person_combo_box_marriage,
              *notebook_window_person_combo_box_place, *notebook_window_person_combo_box_property,
              *notebook_window_person_combo_box_level, *notebook_window_person_combo_box_diagnose,
              *notebook_window_person_combo_box_goto;
    GtkWidget *notebook_window_person_text_name, *notebook_window_person_text_age,
              *notebook_window_person_text_credentials, *notebook_window_person_text_receipt,
              *notebook_window_person_text_ad, *notebook_window_person_text_describe, 
              *notebook_window_person_text_result, *notebook_window_person_text_days;
    GtkWidget *notebook_window_person_scrolled_describe, *notebook_window_person_scrolled_result;
    /* --------------------------------------------------------------------------------------------------------------- */
    /* ------------------------------------- notebook_window_treat部分声明 --------------------------------------------- */
    /* ---------------------------------------------------------------------------------------------------------------- */
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
    notebook_window_person_table = gtk_table_new(3, 5, FALSE);
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
    notebook_window_person_h_separator_1 = gtk_hseparator_new();
    notebook_window_person_h_separator_2 = gtk_hseparator_new();
    notebook_window_person_scrolled_describe = gtk_scrolled_window_new(NULL, NULL);
    notebook_window_person_scrolled_result = gtk_scrolled_window_new(NULL, NULL);
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
    notebook_window_person_button_birthday = gtk_button_new();
    notebook_window_person_button_happen = gtk_button_new();
    notebook_window_person_button_into = gtk_button_new();
    notebook_window_person_button_out = gtk_button_new();
    notebook_window_person_text_name = gtk_entry_new();
    notebook_window_person_text_age = gtk_entry_new();
    notebook_window_person_text_credentials = gtk_entry_new();
    notebook_window_person_text_describe = gtk_text_view_new();
    notebook_window_person_text_result = gtk_text_view_new();
    notebook_window_person_text_receipt = gtk_entry_new();
    notebook_window_person_text_ad = gtk_entry_new();
    notebook_window_person_text_days = gtk_entry_new();
    notebook_window_person_combo_box_sex = gtk_combo_box_text_new();
    notebook_window_person_combo_box_credentials = gtk_combo_box_text_new();
    notebook_window_person_combo_box_marriage = gtk_combo_box_text_new();
    notebook_window_person_combo_box_education = gtk_combo_box_text_new();
    notebook_window_person_combo_box_place = gtk_combo_box_text_new();
    notebook_window_person_combo_box_property = gtk_combo_box_text_new();
    notebook_window_person_combo_box_level = gtk_combo_box_text_new();
    notebook_window_person_combo_box_diagnose = gtk_combo_box_text_new();
    notebook_window_person_combo_box_goto = gtk_combo_box_text_new();
    /* 设置滚动窗口notebook_window_person内部控件的默认大小 */
    gtk_widget_set_size_request(notebook_window_person_button_photo, 100, 150); /* 注意调整一下尺寸 */
    gtk_widget_set_size_request(notebook_window_person_label_name, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_name, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_sex, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_sex, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_age, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_age, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_birthday, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_button_birthday, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_credentials, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_credentials, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_credentials, 375, 25);
    gtk_widget_set_size_request(notebook_window_person_label_marriage, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_marriage, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_education, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_education, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_dangerous, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_happen, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_button_happen, 100, 25); 
    gtk_widget_set_size_request(notebook_window_person_label_place, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_place, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_describe, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_scrolled_describe, 500, 100);
    gtk_widget_set_size_request(notebook_window_person_label_property, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_property, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_result, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_scrolled_result, 500, 100);
    gtk_widget_set_size_request(notebook_window_person_label_level, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_level, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_diagnose, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_into, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_button_into, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_receipt, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_receipt, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_ad, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_ad, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_out, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_button_out, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_days, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_text_days, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_goto, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_combo_box_goto, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_label_void, 100, 25);
    gtk_widget_set_size_request(notebook_window_person_h_separator_1, 625, 25);
    gtk_widget_set_size_request(notebook_window_person_h_separator_2, 625, 25);
    /* 关于notebook_window_person_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_describe), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_result), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_describe), notebook_window_person_text_describe);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person_scrolled_result), notebook_window_person_text_result);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_1), GTK_WIDGET(notebook_window_person_button_photo), 100, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_2), GTK_WIDGET(notebook_window_person_label_name), 25, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_3), GTK_WIDGET(notebook_window_person_text_name), 0, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_4), GTK_WIDGET(notebook_window_person_label_sex), 100, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_5), GTK_WIDGET(notebook_window_person_combo_box_sex), 0, 50);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_6), GTK_WIDGET(notebook_window_person_label_age), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_7), GTK_WIDGET(notebook_window_person_text_age), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_8), GTK_WIDGET(notebook_window_person_label_birthday), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_9), GTK_WIDGET(notebook_window_person_button_birthday), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_10), GTK_WIDGET(notebook_window_person_label_marriage), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_11), GTK_WIDGET(notebook_window_person_combo_box_marriage), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_12), GTK_WIDGET(notebook_window_person_label_education), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_13), GTK_WIDGET(notebook_window_person_combo_box_education), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_14), GTK_WIDGET(notebook_window_person_label_credentials), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_15), GTK_WIDGET(notebook_window_person_combo_box_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_16), GTK_WIDGET(notebook_window_person_text_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_17), GTK_WIDGET(notebook_window_person_h_separator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_18), GTK_WIDGET(notebook_window_person_label_dangerous), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_19), GTK_WIDGET(notebook_window_person_label_happen), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_20), GTK_WIDGET(notebook_window_person_button_happen), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_21), GTK_WIDGET(notebook_window_person_label_place), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_22), GTK_WIDGET(notebook_window_person_combo_box_place), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_23), GTK_WIDGET(notebook_window_person_label_describe), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_24), GTK_WIDGET(notebook_window_person_scrolled_describe), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_25), GTK_WIDGET(notebook_window_person_label_result), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_26), GTK_WIDGET(notebook_window_person_scrolled_result), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_27), GTK_WIDGET(notebook_window_person_label_property), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_28), GTK_WIDGET(notebook_window_person_combo_box_property), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_29), GTK_WIDGET(notebook_window_person_label_level), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_30), GTK_WIDGET(notebook_window_person_combo_box_level), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_31), GTK_WIDGET(notebook_window_person_label_diagnose), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_32), GTK_WIDGET(notebook_window_person_combo_box_diagnose), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_33), GTK_WIDGET(notebook_window_person_h_separator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_34), GTK_WIDGET(notebook_window_person_label_receipt), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_35), GTK_WIDGET(notebook_window_person_text_receipt), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_36), GTK_WIDGET(notebook_window_person_label_ad), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_37), GTK_WIDGET(notebook_window_person_text_ad), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_38), GTK_WIDGET(notebook_window_person_label_into), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_39), GTK_WIDGET(notebook_window_person_button_into), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_40), GTK_WIDGET(notebook_window_person_label_out), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_41), GTK_WIDGET(notebook_window_person_button_out), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_42), GTK_WIDGET(notebook_window_person_label_days), 100, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_43), GTK_WIDGET(notebook_window_person_text_days), 25, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_44), GTK_WIDGET(notebook_window_person_label_goto), 200, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_45), GTK_WIDGET(notebook_window_person_combo_box_goto), 0, 25);
    gtk_fixed_put(GTK_FIXED(notebook_window_person_fixed_46), GTK_WIDGET(notebook_window_person_label_void), 100, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_1, 0, 1, 0, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_3 , 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_5, 4, 5, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_9, 4, 5, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(notebook_window_person_table), notebook_window_person_fixed_13, 4, 5, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
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
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_8), notebook_window_person_fixed_31, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_h_box_8), notebook_window_person_fixed_32, FALSE, FALSE, 0);
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
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_8, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_11, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_12, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(notebook_window_person_v_box), notebook_window_person_h_box_13, FALSE, FALSE, 0);
    /* 将notebook_window_person_v_box加入到notebook_window_person之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(notebook_window_person), notebook_window_person_v_box);
    /* --------------------------------------------------------------------------------------------------------- */

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
