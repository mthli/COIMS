#include "fwd.h"

/* 相关回调函数原型 */ /* 修改 gpointer 部分 */
void dialog_button_query_person_photo_callback(GtkWidget *widget, gpointer parents);
void dialog_button_query_person_diagnose_callback(GtkWidget *widget, gpointer parents);
void dialog_button_query_treat_diagnose_callback(GtkWidget *widget, gpointer parents);
void dialog_button_query_treat_medicine_callback(GtkWidget *widget, gpointer parents);
void dialog_button_cancel_callback(GtkWidget *widget, gpointer parents);
/* */

void window_button_query_callback(GtkWidget *widget, gpointer parents)
{
    /* dialog 声明 */
    GtkWidget *dialog;
    /* notebook控件声明 */
    GtkWidget *dialog_notebook;
    GtkWidget *dialog_notebook_person_label, *dialog_notebook_treat_label, *dialog_notebook_grade_label;
    GtkWidget *dialog_notebook_person_scrolled, *dialog_notebook_treat_scrolled, *dialog_notebook_grade_scrolled;
    /* dialog_notebook_person内部控件声明 */
    GtkWidget *dialog_notebook_person_vbox,
              *dialog_notebook_person_table_1, *dialog_notebook_person_table_2,
              *dialog_notebook_person_fixed_1, *dialog_notebook_person_fixed_2, *dialog_notebook_person_fixed_3,
              *dialog_notebook_person_fixed_4, *dialog_notebook_person_fixed_5, *dialog_notebook_person_fixed_6,
              *dialog_notebook_person_fixed_7, *dialog_notebook_person_fixed_8, *dialog_notebook_person_fixed_9,
              *dialog_notebook_person_fixed_10, *dialog_notebook_person_fixed_11, *dialog_notebook_person_fixed_12,
              *dialog_notebook_person_fixed_13, *dialog_notebook_person_fixed_14, *dialog_notebook_person_fixed_15,
              *dialog_notebook_person_fixed_16, *dialog_notebook_person_fixed_17, *dialog_notebook_person_fixed_18,
              *dialog_notebook_person_fixed_19, *dialog_notebook_person_fixed_20, *dialog_notebook_person_fixed_21,
              *dialog_notebook_person_fixed_22, *dialog_notebook_person_fixed_23, *dialog_notebook_person_fixed_24,
              *dialog_notebook_person_fixed_25, *dialog_notebook_person_fixed_26, *dialog_notebook_person_fixed_27,
              *dialog_notebook_person_fixed_28, *dialog_notebook_person_fixed_29, *dialog_notebook_person_fixed_30,
              *dialog_notebook_person_fixed_31, *dialog_notebook_person_fixed_32, *dialog_notebook_person_fixed_33,
              *dialog_notebook_person_fixed_34, *dialog_notebook_person_fixed_35, *dialog_notebook_person_fixed_36,
              *dialog_notebook_person_fixed_37, *dialog_notebook_person_fixed_38, *dialog_notebook_person_fixed_39,
              *dialog_notebook_person_fixed_40, *dialog_notebook_person_fixed_41, *dialog_notebook_person_fixed_42,
              *dialog_notebook_person_fixed_43, *dialog_notebook_person_fixed_44, *dialog_notebook_person_fixed_45,
              *dialog_notebook_person_hbox_1, *dialog_notebook_person_hbox_2, *dialog_notebook_person_hbox_3,
              *dialog_notebook_person_hbox_4, *dialog_notebook_person_hbox_5, *dialog_notebook_person_hbox_6,
              *dialog_notebook_person_hbox_7, *dialog_notebook_person_hbox_8, *dialog_notebook_person_hbox_9,
              *dialog_notebook_person_hbox_10, *dialog_notebook_person_hbox_11, *dialog_notebook_person_hbox_12,
              *dialog_notebook_person_hbox_13;
    GtkWidget *dialog_notebook_person_hseparator_1, *dialog_notebook_person_hseparator_2;
    GtkWidget *dialog_notebook_person_label_name, *dialog_notebook_person_label_sex,
              *dialog_notebook_person_label_age, *dialog_notebook_person_label_birthday,
              *dialog_notebook_person_label_credentials, *dialog_notebook_person_label_marriage,
              *dialog_notebook_person_label_education, *dialog_notebook_person_label_place,
              *dialog_notebook_person_label_into, *dialog_notebook_person_label_receipt,
              *dialog_notebook_person_label_ad, *dialog_notebook_person_label_dangerous,
              *dialog_notebook_person_label_happen, *dialog_notebook_person_label_result,
              *dialog_notebook_person_label_level,
              *dialog_notebook_person_label_describe, *dialog_notebook_person_label_diagnose,
              *dialog_notebook_person_label_diagnose_show, *dialog_notebook_person_label_days,
              *dialog_notebook_person_label_out, *dialog_notebook_person_label_goto,
              *dialog_notebook_person_label_void;
    GtkWidget *dialog_notebook_person_button_photo, *dialog_notebook_person_button_diagnose;
    GtkWidget *dialog_notebook_person_combo_sex, *dialog_notebook_person_combo_credentials,
              *dialog_notebook_person_combo_education, *dialog_notebook_person_combo_marriage,
              *dialog_notebook_person_combo_place,
              *dialog_notebook_person_combo_level, *dialog_notebook_person_combo_goto;
    GtkWidget *dialog_notebook_person_text_name, *dialog_notebook_person_text_age,
              *dialog_notebook_person_text_birthday, *dialog_notebook_person_text_happen,
              *dialog_notebook_person_text_into, *dialog_notebook_person_text_out,
              *dialog_notebook_person_text_credentials, *dialog_notebook_person_text_receipt,
              *dialog_notebook_person_text_ad, *dialog_notebook_person_text_describe,
              *dialog_notebook_person_text_diagnose, *dialog_notebook_person_text_result,
              *dialog_notebook_person_text_days;
    GtkWidget *dialog_notebook_person_scrolled_describe, *dialog_notebook_person_scrolled_result,
              *dialog_notebook_person_scrolled_diagnose;
    /* dialog_notebook_treat内部控件声明 */
    GtkWidget *dialog_notebook_treat_vbox,
              *dialog_notebook_treat_table_1, *dialog_notebook_treat_table_2, *dialog_notebook_treat_table_3,
              *dialog_notebook_treat_table_4, *dialog_notebook_treat_table_5, *dialog_notebook_treat_table_6,
              *dialog_notebook_treat_table_7,
              *dialog_notebook_treat_hbox_1, *dialog_notebook_treat_hbox_2, *dialog_notebook_treat_hbox_3,
              *dialog_notebook_treat_hbox_4, *dialog_notebook_treat_hbox_5, *dialog_notebook_treat_hbox_6,
              *dialog_notebook_treat_hbox_7, *dialog_notebook_treat_hbox_8, *dialog_notebook_treat_hbox_9,
              *dialog_notebook_treat_hbox_10, *dialog_notebook_treat_hbox_11, *dialog_notebook_treat_hbox_12,
              *dialog_notebook_treat_hbox_13, *dialog_notebook_treat_hbox_14, *dialog_notebook_treat_hbox_15,
              *dialog_notebook_treat_hbox_16, *dialog_notebook_treat_hbox_17, *dialog_notebook_treat_hbox_18,
              *dialog_notebook_treat_hbox_19, *dialog_notebook_treat_hbox_20, *dialog_notebook_treat_hbox_21,
              *dialog_notebook_treat_hbox_22,
              *dialog_notebook_treat_fixed_1, *dialog_notebook_treat_fixed_2, *dialog_notebook_treat_fixed_3,
              *dialog_notebook_treat_fixed_4, *dialog_notebook_treat_fixed_5, *dialog_notebook_treat_fixed_6,
              *dialog_notebook_treat_fixed_7, *dialog_notebook_treat_fixed_8, *dialog_notebook_treat_fixed_9,
              *dialog_notebook_treat_fixed_10, *dialog_notebook_treat_fixed_11, *dialog_notebook_treat_fixed_12,
              *dialog_notebook_treat_fixed_13, *dialog_notebook_treat_fixed_14, *dialog_notebook_treat_fixed_15,
              *dialog_notebook_treat_fixed_16, *dialog_notebook_treat_fixed_17, *dialog_notebook_treat_fixed_18,
              *dialog_notebook_treat_fixed_19, *dialog_notebook_treat_fixed_20, *dialog_notebook_treat_fixed_21,
              *dialog_notebook_treat_fixed_22, *dialog_notebook_treat_fixed_23, *dialog_notebook_treat_fixed_24,
              *dialog_notebook_treat_fixed_25, *dialog_notebook_treat_fixed_26, *dialog_notebook_treat_fixed_27,
              *dialog_notebook_treat_fixed_28, *dialog_notebook_treat_fixed_29, *dialog_notebook_treat_fixed_30,
              *dialog_notebook_treat_fixed_31, *dialog_notebook_treat_fixed_32, *dialog_notebook_treat_fixed_33,
              *dialog_notebook_treat_fixed_34, *dialog_notebook_treat_fixed_35, *dialog_notebook_treat_fixed_36,
              *dialog_notebook_treat_fixed_37, *dialog_notebook_treat_fixed_38, *dialog_notebook_treat_fixed_39,
              *dialog_notebook_treat_fixed_40, *dialog_notebook_treat_fixed_41, *dialog_notebook_treat_fixed_42,
              *dialog_notebook_treat_hseparator_1, *dialog_notebook_treat_hseparator_2, *dialog_notebook_treat_hseparator_3;
    GtkWidget *dialog_notebook_treat_label_new,
              *dialog_notebook_treat_label_new_physiology, *dialog_notebook_treat_label_new_violence,
              *dialog_notebook_treat_label_new_autotomy, *dialog_notebook_treat_label_new_selfstl,
              *dialog_notebook_treat_label_new_idioctonia,
              *dialog_notebook_treat_label_history,
              *dialog_notebook_treat_label_history_physiology, *dialog_notebook_treat_label_history_mentality,
              *dialog_notebook_treat_label_history_hospital, *dialog_notebook_treat_label_history_violence,
              *dialog_notebook_treat_label_history_autotomy, *dialog_notebook_treat_label_history_selfstl,
              *dialog_notebook_treat_label_history_idioctonia, *dialog_notebook_treat_label_history_ds,
              *dialog_notebook_treat_label_history_infect,
              *dialog_notebook_treat_label_diagnose,
              *dialog_notebook_treat_label_medicine,
              *dialog_notebook_treat_label_void_1;
    GtkWidget *dialog_notebook_treat_scrolled_new_physiology, *dialog_notebook_treat_scrolled_new_violence,
              *dialog_notebook_treat_scrolled_new_autotomy, *dialog_notebook_treat_scrolled_new_selfstl,
              *dialog_notebook_treat_scrolled_new_idioctonia,
              *dialog_notebook_treat_scrolled_history_physiology, *dialog_notebook_treat_scrolled_history_mentality,
              *dialog_notebook_treat_scrolled_history_hospital, *dialog_notebook_treat_scrolled_history_violence,
              *dialog_notebook_treat_scrolled_history_autotomy, *dialog_notebook_treat_scrolled_history_selfstl,
              *dialog_notebook_treat_scrolled_history_idioctonia, *dialog_notebook_treat_scrolled_history_ds,
              *dialog_notebook_treat_scrolled_history_infect,
              *dialog_notebook_treat_scrolled_diagnose, *dialog_notebook_treat_scrolled_medicine;
    GtkWidget *dialog_notebook_treat_text_new_physiology, *dialog_notebook_treat_text_new_violence,
              *dialog_notebook_treat_text_new_autotomy, *dialog_notebook_treat_text_new_selfstl,
              *dialog_notebook_treat_text_new_idioctonia,
              *dialog_notebook_treat_text_history_physiology, *dialog_notebook_treat_text_history_mentality,
              *dialog_notebook_treat_text_history_hospital, *dialog_notebook_treat_text_history_violence,
              *dialog_notebook_treat_text_history_autotomy,  *dialog_notebook_treat_text_history_selfstl,
              *dialog_notebook_treat_text_history_idioctonia, *dialog_notebook_treat_text_history_ds,
              *dialog_notebook_treat_text_history_infect,
              *dialog_notebook_treat_text_diagnose, *dialog_notebook_treat_text_medicine;
    GtkWidget *dialog_notebook_treat_combo_new_level_1, *dialog_notebook_treat_combo_new_level_2,
              *dialog_notebook_treat_combo_new_level_3, *dialog_notebook_treat_combo_new_level_4;
    GtkWidget *dialog_notebook_treat_button_diagnose, *dialog_notebook_treat_button_medicine;
    /* dialog_notebook_grade内部控件声明 */
    /* ---------------------------------------------------------------------------------------------------------------- */

    /* 创建主窗口 */
    dialog= gtk_dialog_new_with_buttons("查看",
                                        GTK_WINDOW(parents), GTK_DIALOG_MODAL,
                                        "确定",  GTK_RESPONSE_ACCEPT,
                                        "取消", GTK_RESPONSE_REJECT,
                                        NULL);
    /* 设置主窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    /* 设置主窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(dialog), 840, 640);
    gtk_widget_set_size_request(GTK_WIDGET(dialog), 840, 640);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    /* 创建notebook控件 */
    dialog_notebook = gtk_notebook_new();
    /* 设置标签页为底部显示 */
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(dialog_notebook), GTK_POS_BOTTOM);
    /* 设置标签页文字 */
    dialog_notebook_person_label = gtk_label_new("个人信息");
    dialog_notebook_treat_label = gtk_label_new("医疗信息");
    dialog_notebook_grade_label = gtk_label_new("相关量表测评");
    /* 创建标签内需要包含的滚动窗口 */
    dialog_notebook_person_scrolled = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled= gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_grade_scrolled = gtk_scrolled_window_new(NULL, NULL);
    /* 设置滚动条出现的方式为“自动” */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_grade_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    /* ------------------------------------------- 创建dialog_notebook_person部分 --------------------------------------------------- */
    /* 创建滚动窗口dialog_notebook_person内部的框架 */
    dialog_notebook_person_vbox = gtk_vbox_new(FALSE, 0);
    dialog_notebook_person_table_1 = gtk_table_new(3, 5, FALSE);
    dialog_notebook_person_table_2 = gtk_table_new(2, 3, FALSE);
    dialog_notebook_person_fixed_1 = gtk_fixed_new();
    dialog_notebook_person_fixed_2 = gtk_fixed_new();
    dialog_notebook_person_fixed_3 = gtk_fixed_new();
    dialog_notebook_person_fixed_4 = gtk_fixed_new();
    dialog_notebook_person_fixed_5 = gtk_fixed_new();
    dialog_notebook_person_fixed_6 = gtk_fixed_new();
    dialog_notebook_person_fixed_7 = gtk_fixed_new();
    dialog_notebook_person_fixed_8 = gtk_fixed_new();
    dialog_notebook_person_fixed_9 = gtk_fixed_new();
    dialog_notebook_person_fixed_10 = gtk_fixed_new();
    dialog_notebook_person_fixed_11 = gtk_fixed_new();
    dialog_notebook_person_fixed_12 = gtk_fixed_new();
    dialog_notebook_person_fixed_13 = gtk_fixed_new();
    dialog_notebook_person_fixed_14 = gtk_fixed_new();
    dialog_notebook_person_fixed_15 = gtk_fixed_new();
    dialog_notebook_person_fixed_16 = gtk_fixed_new();
    dialog_notebook_person_fixed_17 = gtk_fixed_new();
    dialog_notebook_person_fixed_18 = gtk_fixed_new();
    dialog_notebook_person_fixed_19 = gtk_fixed_new();
    dialog_notebook_person_fixed_20 = gtk_fixed_new();
    dialog_notebook_person_fixed_21 = gtk_fixed_new();
    dialog_notebook_person_fixed_22 = gtk_fixed_new();
    dialog_notebook_person_fixed_23 = gtk_fixed_new();
    dialog_notebook_person_fixed_24 = gtk_fixed_new();
    dialog_notebook_person_fixed_25 = gtk_fixed_new();
    dialog_notebook_person_fixed_26 = gtk_fixed_new(); //
    dialog_notebook_person_fixed_27 = gtk_fixed_new();
    dialog_notebook_person_fixed_28 = gtk_fixed_new();
    dialog_notebook_person_fixed_29 = gtk_fixed_new();
    dialog_notebook_person_fixed_30 = gtk_fixed_new();
    dialog_notebook_person_fixed_31 = gtk_fixed_new();
    dialog_notebook_person_fixed_32 = gtk_fixed_new();
    dialog_notebook_person_fixed_33 = gtk_fixed_new();
    dialog_notebook_person_fixed_34 = gtk_fixed_new();
    dialog_notebook_person_fixed_35 = gtk_fixed_new();
    dialog_notebook_person_fixed_36 = gtk_fixed_new();
    dialog_notebook_person_fixed_37 = gtk_fixed_new();
    dialog_notebook_person_fixed_38 = gtk_fixed_new();
    dialog_notebook_person_fixed_39 = gtk_fixed_new();
    dialog_notebook_person_fixed_40 = gtk_fixed_new();
    dialog_notebook_person_fixed_41 = gtk_fixed_new();
    dialog_notebook_person_fixed_42 = gtk_fixed_new();
    dialog_notebook_person_fixed_43 = gtk_fixed_new();
    dialog_notebook_person_fixed_44 = gtk_fixed_new();
    dialog_notebook_person_fixed_45 = gtk_fixed_new();
    dialog_notebook_person_hbox_1 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_2 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_3 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_4 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_5 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_6 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_7 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_8 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_9 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_10 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_11 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_12 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hbox_13 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_person_hseparator_1 = gtk_hseparator_new();
    dialog_notebook_person_hseparator_2 = gtk_hseparator_new();
    dialog_notebook_person_scrolled_describe = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_person_scrolled_result = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_person_scrolled_diagnose = gtk_scrolled_window_new(NULL, NULL);
    /* 创建滚动窗口dialog_notebook_person内部的控件 */
    dialog_notebook_person_label_name = gtk_label_new("姓名：");
    dialog_notebook_person_label_sex = gtk_label_new("性别：");
    dialog_notebook_person_label_age = gtk_label_new("年龄：");
    dialog_notebook_person_label_birthday = gtk_label_new("生日：");
    dialog_notebook_person_label_credentials = gtk_label_new("有效证件：");
    dialog_notebook_person_label_marriage = gtk_label_new("婚姻状况：");
    dialog_notebook_person_label_education = gtk_label_new("文化程度：");
    dialog_notebook_person_label_place = gtk_label_new("事发地点：");
    dialog_notebook_person_label_dangerous = gtk_label_new("危险行为详情：");
    dialog_notebook_person_label_happen = gtk_label_new("发生时间：");
    dialog_notebook_person_label_describe = gtk_label_new("行为描述：");
    dialog_notebook_person_label_result = gtk_label_new("行为后果：");
    dialog_notebook_person_label_level = gtk_label_new("行为分级：");
    dialog_notebook_person_label_diagnose = gtk_label_new("诊断结果：");
    dialog_notebook_person_label_into = gtk_label_new("入院时间：");
    dialog_notebook_person_label_receipt = gtk_label_new("三联单编号：");
    dialog_notebook_person_label_ad = gtk_label_new("住院号：");
    dialog_notebook_person_label_days = gtk_label_new("住院天数：");
    dialog_notebook_person_label_out = gtk_label_new("出院时间：");
    dialog_notebook_person_label_goto = gtk_label_new("患者去向：");
    dialog_notebook_person_label_void = gtk_label_new(" ");
    dialog_notebook_person_button_photo = gtk_button_new();
    dialog_notebook_person_button_diagnose = gtk_button_new_with_label("点击选择");
    dialog_notebook_person_text_name = gtk_entry_new();
    dialog_notebook_person_text_age = gtk_entry_new();
    dialog_notebook_person_text_birthday = gtk_entry_new();
    dialog_notebook_person_text_happen = gtk_entry_new();
    dialog_notebook_person_text_into = gtk_entry_new();
    dialog_notebook_person_text_out = gtk_entry_new();
    dialog_notebook_person_text_credentials = gtk_entry_new();
    dialog_notebook_person_text_describe = gtk_text_view_new();
    dialog_notebook_person_text_result = gtk_text_view_new();
    dialog_notebook_person_text_diagnose = gtk_text_view_new();
    dialog_notebook_person_text_receipt = gtk_entry_new();
    dialog_notebook_person_text_ad = gtk_entry_new();
    dialog_notebook_person_text_days = gtk_entry_new();
    dialog_notebook_person_combo_sex = gtk_combo_box_text_new();
    dialog_notebook_person_combo_credentials = gtk_combo_box_text_new();
    dialog_notebook_person_combo_marriage = gtk_combo_box_text_new();
    dialog_notebook_person_combo_education = gtk_combo_box_text_new();
    dialog_notebook_person_combo_place = gtk_combo_box_text_new();
    dialog_notebook_person_combo_level = gtk_combo_box_text_new();
    dialog_notebook_person_combo_goto = gtk_combo_box_text_new();
    /* 设置滚动窗口dialog_notebook_person内部控件的默认大小 */
    gtk_widget_set_size_request(dialog_notebook_person_button_photo, 100, 150); /* 注意调整一下尺寸 */
    gtk_widget_set_size_request(dialog_notebook_person_label_name, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_name, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_sex, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_sex, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_age, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_age, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_birthday, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_birthday, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_credentials, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_credentials, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_credentials, 375, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_marriage, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_marriage, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_education, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_education, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_dangerous, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_happen, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_happen, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_place, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_place, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_describe, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_scrolled_describe, 500, 100);
    gtk_widget_set_size_request(dialog_notebook_person_label_result, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_scrolled_result, 500, 100);
    gtk_widget_set_size_request(dialog_notebook_person_label_level, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_level, 500, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_button_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_scrolled_diagnose, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_person_label_into, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_into, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_receipt, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_receipt, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_ad, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_ad, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_out, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_out, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_days, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_text_days, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_goto, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_combo_goto, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_label_void, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_person_hseparator_1, 625, 25);
    gtk_widget_set_size_request(dialog_notebook_person_hseparator_2, 625, 25);
    /* 设置各个combo_box_text内部内容 */ /* 关于行为性质部分医院文档内并未说面，需要联系咨询 */
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_sex), "男");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_sex), "女");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_sex), "未知");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_marriage), "未婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_marriage), "已婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_marriage), "再婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_marriage), "离异");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_marriage), "未知");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_education), "文盲");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_education), "小学");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_education), "初中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_education), "高中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_education), "本科及本科以上");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_credentials), "身份证");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_credentials), "户籍所在地证明");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "莲湖区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "碑林区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "雁塔区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "新城区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "未央区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_place), "长安区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "0级：无符合以下1——5级中的任何行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "1级：口头威胁、喊叫、但没有打砸行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "2级：打砸行为，局限在家里，针对财物；不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "3级：明显打砸行为，不分场合，针对财物或人，不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "4级：连续的打砸行为，不分场合，针对财物或人，不能接受劝说而停止；包括自伤、自杀");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_level), "5级：持械针对的任何暴力行为，或者纵火、爆炸等行为；无论在家里还是公共场合");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_goto), "救助站接走");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_goto), "转院（包括：市二院、市按摩院、西安医学院附属医院市结核医院）");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_person_combo_goto), "家属接走");
    /* 关于dialog_notebook_person_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_describe), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_result), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_diagnose), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_describe), dialog_notebook_person_text_describe);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_result), dialog_notebook_person_text_result);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled_diagnose), dialog_notebook_person_text_diagnose);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_1), GTK_WIDGET(dialog_notebook_person_button_photo), 100, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_2), GTK_WIDGET(dialog_notebook_person_label_name), 25, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_3), GTK_WIDGET(dialog_notebook_person_text_name), 0, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_4), GTK_WIDGET(dialog_notebook_person_label_sex), 100, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_5), GTK_WIDGET(dialog_notebook_person_combo_sex), 0, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_6), GTK_WIDGET(dialog_notebook_person_label_age), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_7), GTK_WIDGET(dialog_notebook_person_text_age), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_8), GTK_WIDGET(dialog_notebook_person_label_birthday), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_9), GTK_WIDGET(dialog_notebook_person_text_birthday), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_10), GTK_WIDGET(dialog_notebook_person_label_marriage), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_11), GTK_WIDGET(dialog_notebook_person_combo_marriage), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_12), GTK_WIDGET(dialog_notebook_person_label_education), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_13), GTK_WIDGET(dialog_notebook_person_combo_education), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_14), GTK_WIDGET(dialog_notebook_person_label_credentials), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_15), GTK_WIDGET(dialog_notebook_person_combo_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_16), GTK_WIDGET(dialog_notebook_person_text_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_17), GTK_WIDGET(dialog_notebook_person_hseparator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_18), GTK_WIDGET(dialog_notebook_person_label_dangerous), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_19), GTK_WIDGET(dialog_notebook_person_label_happen), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_20), GTK_WIDGET(dialog_notebook_person_text_happen), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_21), GTK_WIDGET(dialog_notebook_person_label_place), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_22), GTK_WIDGET(dialog_notebook_person_combo_place), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_23), GTK_WIDGET(dialog_notebook_person_label_describe), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_24), GTK_WIDGET(dialog_notebook_person_scrolled_describe), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_25), GTK_WIDGET(dialog_notebook_person_label_result), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_26), GTK_WIDGET(dialog_notebook_person_scrolled_result), 25, 25); //
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_27), GTK_WIDGET(dialog_notebook_person_label_level), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_28), GTK_WIDGET(dialog_notebook_person_combo_level), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_29), GTK_WIDGET(dialog_notebook_person_label_diagnose), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_30), GTK_WIDGET(dialog_notebook_person_button_diagnose), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_31), GTK_WIDGET(dialog_notebook_person_scrolled_diagnose), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_32), GTK_WIDGET(dialog_notebook_person_hseparator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_33), GTK_WIDGET(dialog_notebook_person_label_receipt), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_34), GTK_WIDGET(dialog_notebook_person_text_receipt), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_35), GTK_WIDGET(dialog_notebook_person_label_ad), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_36), GTK_WIDGET(dialog_notebook_person_text_ad), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_37), GTK_WIDGET(dialog_notebook_person_label_into), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_38), GTK_WIDGET(dialog_notebook_person_text_into), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_39), GTK_WIDGET(dialog_notebook_person_label_out), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_40), GTK_WIDGET(dialog_notebook_person_text_out), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_41), GTK_WIDGET(dialog_notebook_person_label_days), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_42), GTK_WIDGET(dialog_notebook_person_text_days), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_43), GTK_WIDGET(dialog_notebook_person_label_goto), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_44), GTK_WIDGET(dialog_notebook_person_combo_goto), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_person_fixed_45), GTK_WIDGET(dialog_notebook_person_label_void), 100, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_1, 0, 1, 0, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_3 , 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_5, 4, 5, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_9, 4, 5, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_1), dialog_notebook_person_fixed_13, 4, 5, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_1), dialog_notebook_person_fixed_14, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_1), dialog_notebook_person_fixed_15, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_1), dialog_notebook_person_fixed_16, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_2), dialog_notebook_person_fixed_17, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_3), dialog_notebook_person_fixed_18, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_4), dialog_notebook_person_fixed_19, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_4), dialog_notebook_person_fixed_20, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_4), dialog_notebook_person_fixed_21, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_4), dialog_notebook_person_fixed_22, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_5), dialog_notebook_person_fixed_23, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_5), dialog_notebook_person_fixed_24, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_6), dialog_notebook_person_fixed_25, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_6), dialog_notebook_person_fixed_26, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_7), dialog_notebook_person_fixed_27, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_7), dialog_notebook_person_fixed_28, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_2), dialog_notebook_person_fixed_29, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_2), dialog_notebook_person_fixed_30, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_person_table_2), dialog_notebook_person_fixed_31, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_9), dialog_notebook_person_fixed_32, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_10), dialog_notebook_person_fixed_33, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_10), dialog_notebook_person_fixed_34, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_10), dialog_notebook_person_fixed_35, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_10), dialog_notebook_person_fixed_36, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_11), dialog_notebook_person_fixed_37, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_11), dialog_notebook_person_fixed_38, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_11), dialog_notebook_person_fixed_39, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_11), dialog_notebook_person_fixed_40, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_12), dialog_notebook_person_fixed_41, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_12), dialog_notebook_person_fixed_42, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_12), dialog_notebook_person_fixed_43, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_12), dialog_notebook_person_fixed_44, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_hbox_13), dialog_notebook_person_fixed_45, FALSE, FALSE, 0);
    /* 将控件、相关回调函数以及信号相关联 */
    g_signal_connect(G_OBJECT(dialog_notebook_person_button_photo), "clicked", G_CALLBACK(dialog_button_query_person_photo_callback), (gpointer)dialog_notebook_person_button_photo);
    g_signal_connect(G_OBJECT(dialog_notebook_person_button_diagnose), "clicked", G_CALLBACK(dialog_button_query_person_diagnose_callback), (gpointer)dialog);
    /* */
    /* 将各个框架加入到dialog_notebook_person_vbox之中 */
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_11, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_12, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_person_vbox), dialog_notebook_person_hbox_13, FALSE, FALSE, 0);
    /* 将dialog_notebook_person_vbox加入到dialog_notebook_person之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_person_scrolled), dialog_notebook_person_vbox);
    /* --------------------------------------------------------------------------------------------------------- */

    /* ---------------------------------------------------------- dialog_notebook_treat部分 ------------------------------------------------------------- */
    /* 创建滚动窗口dialog_notebook_treat内部的框架 */
    dialog_notebook_treat_vbox = gtk_vbox_new(FALSE, 0);
    dialog_notebook_treat_table_1 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_table_2 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_table_3 = gtk_table_new( 2, 2, FALSE);
    dialog_notebook_treat_table_4 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_table_5 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_table_6 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_table_7 = gtk_table_new( 2, 3, FALSE);
    dialog_notebook_treat_hbox_1 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_2 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_3 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_4 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_5 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_6 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_7 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_8 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_9 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_10 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_11 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_12 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_13 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_14 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_15 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_16 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_17 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_18 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_19 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_20 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_21 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_hbox_22 = gtk_hbox_new(FALSE, 0);
    dialog_notebook_treat_fixed_1 = gtk_fixed_new();
    dialog_notebook_treat_fixed_2 = gtk_fixed_new();
    dialog_notebook_treat_fixed_3 = gtk_fixed_new();
    dialog_notebook_treat_fixed_4 = gtk_fixed_new();
    dialog_notebook_treat_fixed_5 = gtk_fixed_new();
    dialog_notebook_treat_fixed_6 = gtk_fixed_new();
    dialog_notebook_treat_fixed_7 = gtk_fixed_new();
    dialog_notebook_treat_fixed_8 = gtk_fixed_new();
    dialog_notebook_treat_fixed_9 = gtk_fixed_new();
    dialog_notebook_treat_fixed_10 = gtk_fixed_new();
    dialog_notebook_treat_fixed_11 = gtk_fixed_new();
    dialog_notebook_treat_fixed_12 = gtk_fixed_new();
    dialog_notebook_treat_fixed_13 = gtk_fixed_new();
    dialog_notebook_treat_fixed_14 = gtk_fixed_new();
    dialog_notebook_treat_fixed_15 = gtk_fixed_new();
    dialog_notebook_treat_fixed_16 = gtk_fixed_new();
    dialog_notebook_treat_fixed_17 = gtk_fixed_new();
    dialog_notebook_treat_fixed_18 = gtk_fixed_new();
    dialog_notebook_treat_fixed_19 = gtk_fixed_new();
    dialog_notebook_treat_fixed_20 = gtk_fixed_new();
    dialog_notebook_treat_fixed_21 = gtk_fixed_new();
    dialog_notebook_treat_fixed_22 = gtk_fixed_new();
    dialog_notebook_treat_fixed_23 = gtk_fixed_new();
    dialog_notebook_treat_fixed_24 = gtk_fixed_new();
    dialog_notebook_treat_fixed_25 = gtk_fixed_new();
    dialog_notebook_treat_fixed_26 = gtk_fixed_new();
    dialog_notebook_treat_fixed_27 = gtk_fixed_new();
    dialog_notebook_treat_fixed_28 = gtk_fixed_new();
    dialog_notebook_treat_fixed_29 = gtk_fixed_new();
    dialog_notebook_treat_fixed_30 = gtk_fixed_new();
    dialog_notebook_treat_fixed_31 = gtk_fixed_new();
    dialog_notebook_treat_fixed_32 = gtk_fixed_new();
    dialog_notebook_treat_fixed_33 = gtk_fixed_new();
    dialog_notebook_treat_fixed_34 = gtk_fixed_new();
    dialog_notebook_treat_fixed_35 = gtk_fixed_new();
    dialog_notebook_treat_fixed_36 = gtk_fixed_new();
    dialog_notebook_treat_fixed_37 = gtk_fixed_new();
    dialog_notebook_treat_fixed_38 = gtk_fixed_new();
    dialog_notebook_treat_fixed_39 = gtk_fixed_new();
    dialog_notebook_treat_fixed_40 = gtk_fixed_new();
    dialog_notebook_treat_fixed_41 = gtk_fixed_new();
    dialog_notebook_treat_fixed_42 = gtk_fixed_new();
    dialog_notebook_treat_scrolled_new_physiology = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_new_violence = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_new_autotomy = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_new_selfstl = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_new_idioctonia = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_physiology = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_mentality = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_hospital = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_violence = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_autotomy = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_selfstl = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_idioctonia = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_ds = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_history_infect = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_diagnose = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_scrolled_medicine = gtk_scrolled_window_new(NULL, NULL);
    dialog_notebook_treat_hseparator_1 = gtk_hseparator_new();
    dialog_notebook_treat_hseparator_2 = gtk_hseparator_new();
    /* 创建滚动窗口dialog_notebook_treat内部的控件 */
    dialog_notebook_treat_label_diagnose = gtk_label_new("疾病诊断：");
    dialog_notebook_treat_label_medicine = gtk_label_new("药物治疗：");
    dialog_notebook_treat_label_new = gtk_label_new("最新记录：");
    dialog_notebook_treat_label_new_physiology = gtk_label_new("躯体疾病：");
    dialog_notebook_treat_label_new_violence = gtk_label_new("暴力行为：");
    dialog_notebook_treat_label_new_autotomy = gtk_label_new("自残行为：");
    dialog_notebook_treat_label_new_selfstl = gtk_label_new("自伤行为：");
    dialog_notebook_treat_label_new_idioctonia = gtk_label_new("自杀行为：");
    dialog_notebook_treat_label_history_physiology = gtk_label_new("既往躯体疾病史：");
    dialog_notebook_treat_label_history_mentality = gtk_label_new("既往精神障碍相关疾病史：");
    dialog_notebook_treat_label_history_hospital = gtk_label_new("既往住院治疗史：");
    dialog_notebook_treat_label_history_violence = gtk_label_new("既往（一月内）暴力行为记录：");
    dialog_notebook_treat_label_history_autotomy = gtk_label_new("既往（一月内）自残行为记录：");
    dialog_notebook_treat_label_history_selfstl = gtk_label_new("既往（一月内）自伤行为记录：");
    dialog_notebook_treat_label_history_idioctonia = gtk_label_new("既往（一月内）自杀行为记录：");
    dialog_notebook_treat_label_history_ds = gtk_label_new("既往吸烟及饮酒史：");
    dialog_notebook_treat_label_history_infect = gtk_label_new("既往传染病史：");
    dialog_notebook_treat_label_void_1 = gtk_label_new(" ");
    dialog_notebook_treat_text_diagnose = gtk_text_view_new();
    dialog_notebook_treat_text_medicine = gtk_text_view_new();
    dialog_notebook_treat_text_new_physiology = gtk_text_view_new();
    dialog_notebook_treat_text_new_violence = gtk_text_view_new();
    dialog_notebook_treat_text_new_autotomy = gtk_text_view_new();
    dialog_notebook_treat_text_new_selfstl = gtk_text_view_new();
    dialog_notebook_treat_text_new_idioctonia = gtk_text_view_new();
    dialog_notebook_treat_text_history_physiology = gtk_text_view_new();
    dialog_notebook_treat_text_history_mentality = gtk_text_view_new();
    dialog_notebook_treat_text_history_hospital = gtk_text_view_new();
    dialog_notebook_treat_text_history_violence = gtk_text_view_new();
    dialog_notebook_treat_text_history_autotomy = gtk_text_view_new();
    dialog_notebook_treat_text_history_selfstl = gtk_text_view_new();
    dialog_notebook_treat_text_history_idioctonia = gtk_text_view_new();
    dialog_notebook_treat_text_history_ds = gtk_text_view_new();
    dialog_notebook_treat_text_history_infect = gtk_text_view_new();
    dialog_notebook_treat_button_diagnose = gtk_button_new_with_label("点击选择");
    dialog_notebook_treat_button_medicine = gtk_button_new_with_label("点击选择");
    dialog_notebook_treat_combo_new_level_1 = gtk_combo_box_text_new();
    dialog_notebook_treat_combo_new_level_2 = gtk_combo_box_text_new();
    dialog_notebook_treat_combo_new_level_3 = gtk_combo_box_text_new();
    dialog_notebook_treat_combo_new_level_4 = gtk_combo_box_text_new();
    /* 设置滚动窗口dialog_notebook_treat内部控件的默认大小 */
    gtk_widget_set_size_request(dialog_notebook_treat_label_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_button_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_diagnose, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_medicine, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_button_medicine, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_medicine, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_hseparator_1, 625, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new_physiology, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_new_physiology, 500, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new_violence, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_combo_new_level_1, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_new_violence, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new_autotomy, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_combo_new_level_2, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_new_autotomy, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new_selfstl, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_combo_new_level_3, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_new_selfstl, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_new_idioctonia, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_combo_new_level_4, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_new_idioctonia, 375, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_hseparator_2, 625, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_physiology, 95, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_physiology, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_mentality, 140, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_mentality, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_hospital, 95, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_hospital, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_violence, 165, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_violence, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_autotomy, 165, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_autotomy, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_selfstl, 165, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_selfstl, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_idioctonia, 165, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_idioctonia, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_ds, 100, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_ds, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_history_infect, 85, 25);
    gtk_widget_set_size_request(dialog_notebook_treat_scrolled_history_infect, 625, 100);
    gtk_widget_set_size_request(dialog_notebook_treat_label_void_1, 100, 25);
    /* 添加dialog_notebook_treat_combo*控件内容 */ /* 关于严重程度方面医院文档内部并未详细说面，需要联系咨询 */
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "0级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "1级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "2级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "3级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "4级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_1), "5级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "0级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "1级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "2级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "3级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "4级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_2), "5级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "0级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "1级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "2级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "3级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "4级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_3), "5级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "0级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "1级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "2级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "3级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "4级");
     gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_notebook_treat_combo_new_level_4), "5级");
    /* 关于dialog_notebook_treat_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_diagnose), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_medicine), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_physiology), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_violence), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_autotomy), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_selfstl), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_idioctonia), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_physiology), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_mentality), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_hospital), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_violence), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_autotomy), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_selfstl), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_idioctonia), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_ds), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_infect), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_diagnose), dialog_notebook_treat_text_diagnose);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_medicine), dialog_notebook_treat_text_medicine);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_physiology), dialog_notebook_treat_text_new_physiology);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_violence), dialog_notebook_treat_text_new_violence);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_autotomy), dialog_notebook_treat_text_new_autotomy);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_selfstl), dialog_notebook_treat_text_new_selfstl);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_new_idioctonia), dialog_notebook_treat_text_new_idioctonia);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_physiology), dialog_notebook_treat_text_history_physiology);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_mentality), dialog_notebook_treat_text_history_mentality);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_hospital), dialog_notebook_treat_text_history_hospital);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_violence), dialog_notebook_treat_text_history_violence);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_autotomy), dialog_notebook_treat_text_history_autotomy);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_selfstl), dialog_notebook_treat_text_history_selfstl);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_idioctonia), dialog_notebook_treat_text_history_idioctonia);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_ds), dialog_notebook_treat_text_history_ds);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled_history_infect), dialog_notebook_treat_text_history_infect);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_1), GTK_WIDGET(dialog_notebook_treat_label_diagnose), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_2), GTK_WIDGET(dialog_notebook_treat_button_diagnose), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_3), GTK_WIDGET(dialog_notebook_treat_scrolled_diagnose), 25, 50);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_4), GTK_WIDGET(dialog_notebook_treat_label_medicine), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_5), GTK_WIDGET(dialog_notebook_treat_button_medicine), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_6), GTK_WIDGET(dialog_notebook_treat_scrolled_medicine), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_7), GTK_WIDGET(dialog_notebook_treat_hseparator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_8), GTK_WIDGET(dialog_notebook_treat_label_new), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_9), GTK_WIDGET(dialog_notebook_treat_label_new_physiology), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_10), GTK_WIDGET(dialog_notebook_treat_scrolled_new_physiology), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_11), GTK_WIDGET(dialog_notebook_treat_label_new_violence), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_12), GTK_WIDGET(dialog_notebook_treat_combo_new_level_1), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_13), GTK_WIDGET(dialog_notebook_treat_scrolled_new_violence), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_14), GTK_WIDGET(dialog_notebook_treat_label_new_autotomy), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_15), GTK_WIDGET(dialog_notebook_treat_combo_new_level_2), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_16), GTK_WIDGET(dialog_notebook_treat_scrolled_new_autotomy), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_17), GTK_WIDGET(dialog_notebook_treat_label_new_selfstl), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_18), GTK_WIDGET(dialog_notebook_treat_combo_new_level_3), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_19), GTK_WIDGET(dialog_notebook_treat_scrolled_new_selfstl), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_20), GTK_WIDGET(dialog_notebook_treat_label_new_idioctonia), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_21), GTK_WIDGET(dialog_notebook_treat_combo_new_level_4), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_22), GTK_WIDGET(dialog_notebook_treat_scrolled_new_idioctonia), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_23), GTK_WIDGET(dialog_notebook_treat_hseparator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_24), GTK_WIDGET(dialog_notebook_treat_label_history_physiology), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_25), GTK_WIDGET(dialog_notebook_treat_scrolled_history_physiology), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_26), GTK_WIDGET(dialog_notebook_treat_label_history_mentality), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_27), GTK_WIDGET(dialog_notebook_treat_scrolled_history_mentality), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_28), GTK_WIDGET(dialog_notebook_treat_label_history_hospital), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_29), GTK_WIDGET(dialog_notebook_treat_scrolled_history_hospital), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_30), GTK_WIDGET(dialog_notebook_treat_label_history_violence), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_31), GTK_WIDGET(dialog_notebook_treat_scrolled_history_violence), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_32), GTK_WIDGET(dialog_notebook_treat_label_history_autotomy), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_33), GTK_WIDGET(dialog_notebook_treat_scrolled_history_autotomy), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_34), GTK_WIDGET(dialog_notebook_treat_label_history_selfstl), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_35), GTK_WIDGET(dialog_notebook_treat_scrolled_history_selfstl), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_36), GTK_WIDGET(dialog_notebook_treat_label_history_idioctonia), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_37), GTK_WIDGET(dialog_notebook_treat_scrolled_history_idioctonia), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_38), GTK_WIDGET(dialog_notebook_treat_label_history_ds), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_39), GTK_WIDGET(dialog_notebook_treat_scrolled_history_ds), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_40), GTK_WIDGET(dialog_notebook_treat_label_history_infect), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_41), GTK_WIDGET(dialog_notebook_treat_scrolled_history_infect), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_notebook_treat_fixed_42), GTK_WIDGET(dialog_notebook_treat_label_void_1), 100, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_1), dialog_notebook_treat_fixed_1, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_1), dialog_notebook_treat_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_1), dialog_notebook_treat_fixed_3, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_2), dialog_notebook_treat_fixed_4, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_2), dialog_notebook_treat_fixed_5, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_2), dialog_notebook_treat_fixed_6, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_1), dialog_notebook_treat_fixed_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_2), dialog_notebook_treat_fixed_8, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_3), dialog_notebook_treat_fixed_9, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_3), dialog_notebook_treat_fixed_10, 1, 2, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_4), dialog_notebook_treat_fixed_11, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_4), dialog_notebook_treat_fixed_12, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_4), dialog_notebook_treat_fixed_13, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_5), dialog_notebook_treat_fixed_14, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_5), dialog_notebook_treat_fixed_15, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_5), dialog_notebook_treat_fixed_16, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_6), dialog_notebook_treat_fixed_17, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_6), dialog_notebook_treat_fixed_18, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_6), dialog_notebook_treat_fixed_19, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_7), dialog_notebook_treat_fixed_20, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_7), dialog_notebook_treat_fixed_21, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_notebook_treat_table_7), dialog_notebook_treat_fixed_22, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_3), dialog_notebook_treat_fixed_23, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_4), dialog_notebook_treat_fixed_24, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_5), dialog_notebook_treat_fixed_25, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_6), dialog_notebook_treat_fixed_26, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_7), dialog_notebook_treat_fixed_27, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_8), dialog_notebook_treat_fixed_28, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_9), dialog_notebook_treat_fixed_29, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_10), dialog_notebook_treat_fixed_30, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_11), dialog_notebook_treat_fixed_31, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_12), dialog_notebook_treat_fixed_32, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_13), dialog_notebook_treat_fixed_33, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_14), dialog_notebook_treat_fixed_34, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_15), dialog_notebook_treat_fixed_35, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_16), dialog_notebook_treat_fixed_36, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_17), dialog_notebook_treat_fixed_37, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_18), dialog_notebook_treat_fixed_38, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_19), dialog_notebook_treat_fixed_39, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_20), dialog_notebook_treat_fixed_40, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_21), dialog_notebook_treat_fixed_41, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_hbox_22), dialog_notebook_treat_fixed_42, FALSE, FALSE, 0);
    /* 将控件、相关回调函数以及信号相关联 */
    g_signal_connect(G_OBJECT(dialog_notebook_treat_button_diagnose), "clicked", G_CALLBACK(dialog_button_query_treat_diagnose_callback), (gpointer)dialog);
    g_signal_connect(G_OBJECT(dialog_notebook_treat_button_medicine), "clicked", G_CALLBACK(dialog_button_query_treat_medicine_callback), (gpointer)dialog);
    /* */
    /* 将各个框架加入到dialog_notebook_treat_vbox之中 */
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_table_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_8, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_11, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_12, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_13, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_14, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_15, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_16, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_17, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_18, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_19, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_20, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_21, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_notebook_treat_vbox), dialog_notebook_treat_hbox_22, FALSE, FALSE, 0);
    /* 将dialog_notebook_person_vbox加入到dialog_notebook_treat之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_notebook_treat_scrolled), dialog_notebook_treat_vbox);
    /* -------------------------------------------------------------------------------------------------- */

     /* 将窗口放置到相应的标签页中 */
    gtk_notebook_append_page(GTK_NOTEBOOK(dialog_notebook), dialog_notebook_person_scrolled, dialog_notebook_person_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(dialog_notebook), dialog_notebook_treat_scrolled, dialog_notebook_treat_label);
    gtk_notebook_append_page(GTK_NOTEBOOK(dialog_notebook), dialog_notebook_grade_scrolled, dialog_notebook_grade_label);

    /* 把按钮和 notebook 控件放入对话框 */
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> vbox), dialog_notebook, TRUE, TRUE, 0);
    /* 及时显示 */
    gtk_widget_show_all(dialog_notebook);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        /* 需要添加相应的内容 */
        /* */
        gtk_widget_destroy(dialog);
    } else
        gtk_widget_destroy(dialog);
}

