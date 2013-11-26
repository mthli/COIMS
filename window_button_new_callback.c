#include <gtk/gtk.h>

/* 相关回调函数原型 */
void dialog_button_new_diagnose_callback(GtkWidget *widget, gpointer parents);
void dialog_button_new_photo_callback(GtkWidget *widget, gpointer parents);
void dialog_button_cancel_callback(GtkWidget *widget, gpointer parents);
/* */

void window_button_new_callback(GtkWidget *widget, gpointer parents)
{
    /* 主会话框 dialog 声明 */
    GtkWidget *dialog;
    /* 因为是新建，所以不需要像以前那样使用 notebook 控件，只需要一个 scrolled_window 控件即可 */
    GtkWidget *dialog_scrolled;
    /* 同理 dialog_scrolled 内部也不需要相当复杂的选项，首先创建相应框架 */
    GtkWidget *dialog_scrolled_vbox;
    GtkWidget *dialog_scrolled_table_1, *dialog_scrolled_table_2;
    GtkWidget *dialog_scrolled_hbox_1, *dialog_scrolled_hbox_2, *dialog_scrolled_hbox_3,
              *dialog_scrolled_hbox_4, *dialog_scrolled_hbox_5, *dialog_scrolled_hbox_6,
              *dialog_scrolled_hbox_7, *dialog_scrolled_hbox_8, *dialog_scrolled_hbox_9,
              *dialog_scrolled_hbox_10, *dialog_scrolled_hbox_11;
    GtkWidget *dialog_scrolled_fixed_1, *dialog_scrolled_fixed_2, *dialog_scrolled_fixed_3,
              *dialog_scrolled_fixed_4, *dialog_scrolled_fixed_5, *dialog_scrolled_fixed_6,
              *dialog_scrolled_fixed_7, *dialog_scrolled_fixed_8, *dialog_scrolled_fixed_9,
              *dialog_scrolled_fixed_10, *dialog_scrolled_fixed_11, *dialog_scrolled_fixed_12,
              *dialog_scrolled_fixed_13, *dialog_scrolled_fixed_14, *dialog_scrolled_fixed_15,
              *dialog_scrolled_fixed_16, *dialog_scrolled_fixed_17, *dialog_scrolled_fixed_18,
              *dialog_scrolled_fixed_19, *dialog_scrolled_fixed_20, *dialog_scrolled_fixed_21,
              *dialog_scrolled_fixed_22, *dialog_scrolled_fixed_23, *dialog_scrolled_fixed_24,
              *dialog_scrolled_fixed_25, *dialog_scrolled_fixed_26, *dialog_scrolled_fixed_27,
              *dialog_scrolled_fixed_28, *dialog_scrolled_fixed_29, *dialog_scrolled_fixed_30,
              *dialog_scrolled_fixed_31, *dialog_scrolled_fixed_32, *dialog_scrolled_fixed_33,
              *dialog_scrolled_fixed_34, *dialog_scrolled_fixed_35, *dialog_scrolled_fixed_36,
              *dialog_scrolled_fixed_37, *dialog_scrolled_fixed_38, *dialog_scrolled_fixed_39;
    GtkWidget *dialog_scrolled_hseparator_1, *dialog_scrolled_hseparator_2;
    /* 再创建相应控件 */
    GtkWidget *dialog_scrolled_label_name, *dialog_scrolled_label_sex,
              *dialog_scrolled_label_age, *dialog_scrolled_label_birthday,
              *dialog_scrolled_label_marriage, *dialog_scrolled_label_education,
              *dialog_scrolled_label_credentials,
              *dialog_scrolled_label_dangerous,
              *dialog_scrolled_label_happen,  *dialog_scrolled_label_place,
              *dialog_scrolled_label_describe,
              *dialog_scrolled_label_result,
              *dialog_scrolled_label_level,
              *dialog_scrolled_label_diagnose,
              *dialog_scrolled_label_into, *dialog_scrolled_label_receipt,
              *dialog_scrolled_label_ad,
              *dialog_scrolled_label_void;
    GtkWidget *dialog_scrolled_text_name, *dialog_scrolled_text_age,
              *dialog_scrolled_text_birthday, *dialog_scrolled_text_happen,
              *dialog_scrolled_text_credentials,
              *dialog_scrolled_text_describe, *dialog_scrolled_text_result,
              *dialog_scrolled_text_diagnose,
              *dialog_scrolled_text_ad, *dialog_scrolled_text_into, *dialog_scrolled_text_receipt;
    GtkWidget *dialog_scrolled_button_photo, *dialog_scrolled_button_diagnose;
    GtkWidget *dialog_scrolled_combo_sex, *dialog_scrolled_combo_credentials,
              *dialog_scrolled_combo_education, *dialog_scrolled_combo_marriage,
              *dialog_scrolled_combo_place, *dialog_scrolled_combo_property,
              *dialog_scrolled_combo_level;
    GtkWidget *dialog_scrolled_scrolled_describe, *dialog_scrolled_scrolled_result,
              *dialog_scrolled_scrolled_diagnose;
    /* dialog_button 控件声明 */
    GtkWidget *dialog_button_ok, *dialog_button_cancel;

    /* 创建 dialog  */
    dialog = gtk_dialog_new();
    /* 设置窗口名称 */
    gtk_window_set_title(GTK_WINDOW(dialog), "新建");
    /* 设置窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    /* 设置窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(dialog), 840, 640);
    gtk_widget_set_size_request(GTK_WIDGET(dialog), 840, 640);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    /* 创建 dialog_scrolled */
    dialog_scrolled = gtk_scrolled_window_new(NULL, NULL);
    /* 设置 dialog_scrolled 滚动条显示方式 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_scrolled), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    /* 创建 dialog_scrolled 内部框架 */
    dialog_scrolled_vbox = gtk_vbox_new(FALSE, 0);
    dialog_scrolled_table_1 = gtk_table_new(3, 5, FALSE);
    dialog_scrolled_table_2 = gtk_table_new(2, 3, FALSE);
    dialog_scrolled_fixed_1 = gtk_fixed_new();
    dialog_scrolled_fixed_2 = gtk_fixed_new();
    dialog_scrolled_fixed_3 = gtk_fixed_new();
    dialog_scrolled_fixed_4 = gtk_fixed_new();
    dialog_scrolled_fixed_5 = gtk_fixed_new();
    dialog_scrolled_fixed_6 = gtk_fixed_new();
    dialog_scrolled_fixed_7 = gtk_fixed_new();
    dialog_scrolled_fixed_8 = gtk_fixed_new();
    dialog_scrolled_fixed_9 = gtk_fixed_new();
    dialog_scrolled_fixed_10 = gtk_fixed_new();
    dialog_scrolled_fixed_11 = gtk_fixed_new();
    dialog_scrolled_fixed_12 = gtk_fixed_new();
    dialog_scrolled_fixed_13 = gtk_fixed_new();
    dialog_scrolled_fixed_14 = gtk_fixed_new();
    dialog_scrolled_fixed_15 = gtk_fixed_new();
    dialog_scrolled_fixed_16 = gtk_fixed_new();
    dialog_scrolled_fixed_17 = gtk_fixed_new();
    dialog_scrolled_fixed_18 = gtk_fixed_new();
    dialog_scrolled_fixed_19 = gtk_fixed_new();
    dialog_scrolled_fixed_20 = gtk_fixed_new();
    dialog_scrolled_fixed_21 = gtk_fixed_new();
    dialog_scrolled_fixed_22 = gtk_fixed_new();
    dialog_scrolled_fixed_23 = gtk_fixed_new();
    dialog_scrolled_fixed_24 = gtk_fixed_new();
    dialog_scrolled_fixed_25 = gtk_fixed_new();
    dialog_scrolled_fixed_26 = gtk_fixed_new();
    dialog_scrolled_fixed_27 = gtk_fixed_new();
    dialog_scrolled_fixed_28 = gtk_fixed_new();
    dialog_scrolled_fixed_29 = gtk_fixed_new();
    dialog_scrolled_fixed_30 = gtk_fixed_new();
    dialog_scrolled_fixed_31 = gtk_fixed_new();
    dialog_scrolled_fixed_32 = gtk_fixed_new();
    dialog_scrolled_fixed_33 = gtk_fixed_new();
    dialog_scrolled_fixed_34 = gtk_fixed_new();
    dialog_scrolled_fixed_35 = gtk_fixed_new();
    dialog_scrolled_fixed_36 = gtk_fixed_new();
    dialog_scrolled_fixed_37 = gtk_fixed_new();
    dialog_scrolled_fixed_38 = gtk_fixed_new();
    dialog_scrolled_fixed_39 = gtk_fixed_new();
    dialog_scrolled_hbox_1 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_2 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_3 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_4 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_5 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_6 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_7 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_8 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_9 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_10 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hbox_11 = gtk_hbox_new(FALSE, 0);
    dialog_scrolled_hseparator_1 = gtk_hseparator_new();
    dialog_scrolled_hseparator_2 = gtk_hseparator_new();
    dialog_scrolled_scrolled_describe = gtk_scrolled_window_new(NULL, NULL);
    dialog_scrolled_scrolled_result = gtk_scrolled_window_new(NULL, NULL);
    dialog_scrolled_scrolled_diagnose = gtk_scrolled_window_new(NULL, NULL);
    /* 创建 dialog_scrolled 内部控件 */
    dialog_scrolled_label_name = gtk_label_new("姓名：");
    dialog_scrolled_label_sex = gtk_label_new("性别：");
    dialog_scrolled_label_age = gtk_label_new("年龄：");
    dialog_scrolled_label_birthday = gtk_label_new("生日：");
    dialog_scrolled_label_credentials = gtk_label_new("有效证件：");
    dialog_scrolled_label_marriage = gtk_label_new("婚姻状况：");
    dialog_scrolled_label_education = gtk_label_new("文化程度：");
    dialog_scrolled_label_place = gtk_label_new("事发地点：");
    dialog_scrolled_label_dangerous = gtk_label_new("危险行为详情：");
    dialog_scrolled_label_happen = gtk_label_new("发生时间：");
    dialog_scrolled_label_describe = gtk_label_new("行为描述：");
    dialog_scrolled_label_result = gtk_label_new("行为后果：");
    dialog_scrolled_label_level = gtk_label_new("行为分级：");
    dialog_scrolled_label_diagnose = gtk_label_new("诊断结果：");
    dialog_scrolled_label_into = gtk_label_new("入院时间：");
    dialog_scrolled_label_receipt = gtk_label_new("三联单编号：");
    dialog_scrolled_label_ad = gtk_label_new("住院号：");
    dialog_scrolled_label_void = gtk_label_new(" ");
    dialog_scrolled_button_photo = gtk_button_new();
    dialog_scrolled_button_diagnose = gtk_button_new_with_label("点击选择");
    dialog_scrolled_text_name = gtk_entry_new();
    dialog_scrolled_text_age = gtk_entry_new();
    dialog_scrolled_text_birthday = gtk_entry_new();
    dialog_scrolled_text_happen = gtk_entry_new();
    dialog_scrolled_text_credentials = gtk_entry_new();
    dialog_scrolled_text_describe = gtk_text_view_new();
    dialog_scrolled_text_result = gtk_text_view_new();
    dialog_scrolled_text_diagnose = gtk_text_view_new();
    dialog_scrolled_text_receipt = gtk_entry_new();
    dialog_scrolled_text_ad = gtk_entry_new();
    dialog_scrolled_text_into = gtk_entry_new();
    dialog_scrolled_combo_sex = gtk_combo_box_text_new();
    dialog_scrolled_combo_marriage = gtk_combo_box_text_new();
    dialog_scrolled_combo_education = gtk_combo_box_text_new();
    dialog_scrolled_combo_credentials = gtk_combo_box_text_new();
    dialog_scrolled_combo_place = gtk_combo_box_text_new();
    dialog_scrolled_combo_property = gtk_combo_box_text_new();
    dialog_scrolled_combo_level = gtk_combo_box_text_new();
    /* 设置滚动窗口dialog_scrolled内部控件的默认大小 */
    gtk_widget_set_size_request(dialog_scrolled_button_photo, 100, 150);
    gtk_widget_set_size_request(dialog_scrolled_label_name, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_name, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_sex, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_sex, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_age, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_age, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_birthday, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_birthday, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_credentials, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_credentials, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_credentials, 375, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_marriage, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_marriage, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_education, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_education, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_dangerous, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_happen, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_happen, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_place, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_place, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_describe, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_scrolled_describe, 500, 100);
    gtk_widget_set_size_request(dialog_scrolled_label_result, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_scrolled_result, 500, 100);
    gtk_widget_set_size_request(dialog_scrolled_label_level, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_combo_level, 500, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_button_diagnose, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_scrolled_diagnose, 375, 100);
    gtk_widget_set_size_request(dialog_scrolled_label_receipt, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_receipt, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_ad, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_ad, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_into, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_text_into, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_label_void, 100, 25);
    gtk_widget_set_size_request(dialog_scrolled_hseparator_1, 625, 25);
    gtk_widget_set_size_request(dialog_scrolled_hseparator_2, 625, 25);
    /* 设置各个combo_box_text内部内容 */ /* 关于行为性质部分医院文档内并未说面，需要联系咨询 */
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_sex), "男");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_sex), "女");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_sex), "未知");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_marriage), "未婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_marriage), "已婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_marriage), "再婚");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_marriage), "离异");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_marriage), "未知");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_education), "文盲");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_education), "小学");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_education), "初中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_education), "高中");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_education), "本科及本科以上");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_credentials), "身份证");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_credentials), "户籍所在地证明");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "莲湖区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "碑林区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "雁塔区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "新城区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "未央区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_place), "长安区");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "0级：无符合以下1——5级中的任何行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "1级：口头威胁、喊叫、但没有打砸行为");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "2级：打砸行为，局限在家里，针对财物；不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "3级：明显打砸行为，不分场合，针对财物或人，不能接受劝说而停止");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "4级：连续的打砸行为，不分场合，针对财物或人，不能接受劝说而停止；包括自伤、自杀");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(dialog_scrolled_combo_level), "5级：持械针对的任何暴力行为，或者纵火、爆炸等行为；无论在家里还是公共场合");
     /* 关于dialog_scrolled_scrolled*控件的一些设置 */
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_describe), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_result), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_diagnose), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_describe), dialog_scrolled_text_describe);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_result), dialog_scrolled_text_result);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_scrolled_scrolled_diagnose), dialog_scrolled_text_diagnose);
    /* 将控件放入GtkFixed框架 */ /* 注意GtkFixed框架后面的参数是用来定义坐标的，所以用这个来实现对齐 */
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_1), GTK_WIDGET(dialog_scrolled_button_photo), 100, 50);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_2), GTK_WIDGET(dialog_scrolled_label_name), 25, 50);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_3), GTK_WIDGET(dialog_scrolled_text_name), 0, 50);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_4), GTK_WIDGET(dialog_scrolled_label_sex), 100, 50);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_5), GTK_WIDGET(dialog_scrolled_combo_sex), 0, 50);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_6), GTK_WIDGET(dialog_scrolled_label_age), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_7), GTK_WIDGET(dialog_scrolled_text_age), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_8), GTK_WIDGET(dialog_scrolled_label_birthday), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_9), GTK_WIDGET(dialog_scrolled_text_birthday), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_10), GTK_WIDGET(dialog_scrolled_label_marriage), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_11), GTK_WIDGET(dialog_scrolled_combo_marriage), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_12), GTK_WIDGET(dialog_scrolled_label_education), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_13), GTK_WIDGET(dialog_scrolled_combo_education), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_14), GTK_WIDGET(dialog_scrolled_label_credentials), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_15), GTK_WIDGET(dialog_scrolled_combo_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_16), GTK_WIDGET(dialog_scrolled_text_credentials), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_17), GTK_WIDGET(dialog_scrolled_hseparator_1), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_18), GTK_WIDGET(dialog_scrolled_label_dangerous), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_19), GTK_WIDGET(dialog_scrolled_label_happen), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_20), GTK_WIDGET(dialog_scrolled_text_happen), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_21), GTK_WIDGET(dialog_scrolled_label_place), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_22), GTK_WIDGET(dialog_scrolled_combo_place), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_23), GTK_WIDGET(dialog_scrolled_label_describe), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_24), GTK_WIDGET(dialog_scrolled_scrolled_describe), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_25), GTK_WIDGET(dialog_scrolled_label_result), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_26), GTK_WIDGET(dialog_scrolled_scrolled_result), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_27), GTK_WIDGET(dialog_scrolled_label_level), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_28), GTK_WIDGET(dialog_scrolled_combo_level), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_29), GTK_WIDGET(dialog_scrolled_label_diagnose), 100, 0);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_30), GTK_WIDGET(dialog_scrolled_button_diagnose), 25, 0);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_31), GTK_WIDGET(dialog_scrolled_scrolled_diagnose), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_32), GTK_WIDGET(dialog_scrolled_hseparator_2), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_33), GTK_WIDGET(dialog_scrolled_label_receipt), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_34), GTK_WIDGET(dialog_scrolled_text_receipt), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_35), GTK_WIDGET(dialog_scrolled_label_ad), 200, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_36), GTK_WIDGET(dialog_scrolled_text_ad), 0, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_37), GTK_WIDGET(dialog_scrolled_label_into), 100, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_38), GTK_WIDGET(dialog_scrolled_text_into), 25, 25);
    gtk_fixed_put(GTK_FIXED(dialog_scrolled_fixed_39), GTK_WIDGET(dialog_scrolled_label_void), 100, 25);
    /* 开始将各个GtkFixed框架加入到GtkBox和GtkTable框架之中 */
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_1, 0, 1, 0, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_2, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_3 , 2, 3, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_4, 3, 4, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_5, 4, 5, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_6, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_7, 2, 3, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_8, 3, 4, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_9, 4, 5, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_10, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_11, 2, 3, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_12, 3, 4, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_1), dialog_scrolled_fixed_13, 4, 5, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_1), dialog_scrolled_fixed_14, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_1), dialog_scrolled_fixed_15, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_1), dialog_scrolled_fixed_16, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_2), dialog_scrolled_fixed_17, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_3), dialog_scrolled_fixed_18, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_4), dialog_scrolled_fixed_19, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_4), dialog_scrolled_fixed_20, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_4), dialog_scrolled_fixed_21, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_4), dialog_scrolled_fixed_22, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_5), dialog_scrolled_fixed_23, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_5), dialog_scrolled_fixed_24, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_6), dialog_scrolled_fixed_25, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_6), dialog_scrolled_fixed_26, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_7), dialog_scrolled_fixed_27, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_7), dialog_scrolled_fixed_28, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_2), dialog_scrolled_fixed_29, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_2), dialog_scrolled_fixed_30, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(dialog_scrolled_table_2), dialog_scrolled_fixed_31, 2, 3, 0, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_8), dialog_scrolled_fixed_32, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_9), dialog_scrolled_fixed_33, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_9), dialog_scrolled_fixed_34, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_9), dialog_scrolled_fixed_35, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_9), dialog_scrolled_fixed_36, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_10), dialog_scrolled_fixed_37, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_10), dialog_scrolled_fixed_38, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_hbox_11), dialog_scrolled_fixed_39, FALSE, FALSE, 0);
    /* 将控件、相关回调函数以及信号相关联 */
    g_signal_connect(G_OBJECT(dialog_scrolled_button_photo), "clicked", G_CALLBACK(dialog_button_new_photo_callback), (gpointer)dialog_scrolled_button_photo);
    g_signal_connect(G_OBJECT(dialog_scrolled_button_diagnose), "clicked", G_CALLBACK(dialog_button_new_diagnose_callback), (gpointer)dialog);
    /* */

    /* 创建 dialog_button* 控件 */
    dialog_button_ok = gtk_button_new_with_label("确定");
    dialog_button_cancel = gtk_button_new_with_label("取消");
    /* 设置 dialog_button* 控件默认大小 */
    gtk_widget_set_size_request(dialog_button_ok, 75, 25);
    gtk_widget_set_size_request(dialog_button_cancel, 75, 25);
    /* 将相关回调函数与 dialog_button* 相关联 */
    g_signal_connect(G_OBJECT(dialog_button_cancel), "clicked", G_CALLBACK(dialog_button_cancel_callback), (gpointer)dialog);
    /* */

    /* 将各个框架和控件加入到 dialog_scrolled_vbox 之中 */
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_table_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_5, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_6, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_7, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_table_2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_8, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_9, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_10, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(dialog_scrolled_vbox), dialog_scrolled_hbox_11, FALSE, FALSE, 0);
    /* 将 dialog_scrolled_vbox 加入到 dialog_scrolled 之中 */
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(dialog_scrolled), dialog_scrolled_vbox);

    /* 将各个框架和控件加入到dialog 之中 */ /* 注意是用 TRUE 还是 FALSE */
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> vbox), dialog_scrolled, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> action_area), dialog_button_ok, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> action_area), dialog_button_cancel, TRUE, TRUE, 0);

    /* 及时显示 */
    gtk_widget_show_all(dialog_scrolled);
    gtk_widget_show(dialog_button_ok);
    gtk_widget_show(dialog_button_cancel);
    /* 运行对话框 */
    gtk_dialog_run(GTK_DIALOG(dialog));
}
