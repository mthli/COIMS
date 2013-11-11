#include <gtk/gtk.h>
int main(int argc, char *argv[])
{
    /* 创建各个控件声明 */
    GtkWidget *treat_dialog_diagnose;
    GtkWidget *treat_dialog_diagnose_v_box, *treat_dialog_diagnose_table,
              *treat_dialog_diagnose_h_box_1, *treat_dialog_diagnose_h_box_2;
    GtkWidget *treat_dialog_diagnose_fixed_1, *treat_dialog_diagnose_fixed_2, *treat_dialog_diagnose_fixed_3,
              *treat_dialog_diagnose_fixed_4, *treat_dialog_diagnose_fixed_5, *treat_dialog_diagnose_fixed_6,
              *treat_dialog_diagnose_fixed_7, *treat_dialog_diagnose_fixed_8, *treat_dialog_diagnose_fixed_9,
              *treat_dialog_diagnose_fixed_10, *treat_dialog_diagnose_fixed_11, *treat_dialog_diagnose_fixed_12,
              *treat_dialog_diagnose_fixed_13;
    GtkWidget *treat_dialog_diagnose_alignment_right;
    GtkWidget *treat_dialog_diagnose_label;
    GtkWidget *treat_dialog_diagnose_button_choose_1, *treat_dialog_diagnose_button_choose_2,
              *treat_dialog_diagnose_button_choose_3, *treat_dialog_diagnose_button_choose_4,
              *treat_dialog_diagnose_button_choose_5, *treat_dialog_diagnose_button_choose_6,
              *treat_dialog_diagnose_button_choose_7, *treat_dialog_diagnose_button_choose_8,
              *treat_dialog_diagnose_button_choose_9, *treat_dialog_diagnose_button_choose_10;
    GtkWidget *treat_dialog_diagnose_button_ok, *treat_dialog_diagnose_button_cancel;
    /* 创建dialog内部框架 */
    treat_dialog_diagnose_v_box = gtk_vbox_new(FALSE, 0);
    treat_dialog_diagnose_table = gtk_table_new(5, 2, FALSE);
    treat_dialog_diagnose_h_box_1 = gtk_hbox_new(FALSE, 0);
    treat_dialog_diagnose_h_box_2 = gtk_hbox_new(FALSE, 0);
    treat_dialog_diagnose_fixed_1 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_2 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_3 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_4 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_5 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_6 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_7 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_8 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_9 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_10 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_11 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_12 = gtk_fixed_new();
    treat_dialog_diagnose_fixed_13 = gtk_fixed_new();
    /* 创建alignment框架 */
    treat_dialog_diagnose_alignment_right = gtk_alignment_new(1, 0, 0, 0);
    /* 创建dialog内部控件 */
    treat_dialog_diagnose_label = gtk_label_new("可多选：");
    treat_dialog_diagnose_button_choose_1 = gtk_check_button_new_with_label("精神分裂症");
    treat_dialog_diagnose_button_choose_2 = gtk_check_button_new_with_label("分裂情感性障碍");
    treat_dialog_diagnose_button_choose_3 = gtk_check_button_new_with_label("偏执性精神病");
    treat_dialog_diagnose_button_choose_4 = gtk_check_button_new_with_label("双相情感障碍");
    treat_dialog_diagnose_button_choose_5 = gtk_check_button_new_with_label("癫痫所致精神障碍");
    treat_dialog_diagnose_button_choose_6 = gtk_check_button_new_with_label("精神发育迟滞");
    treat_dialog_diagnose_button_choose_7 = gtk_check_button_new_with_label("兴奋状态");
    treat_dialog_diagnose_button_choose_8 = gtk_check_button_new_with_label("偏执状态");
    treat_dialog_diagnose_button_choose_9 = gtk_check_button_new_with_label("缄默状态");
    treat_dialog_diagnose_button_choose_10 = gtk_check_button_new_with_label("焦虑状态");
    treat_dialog_diagnose_button_ok = gtk_button_new_with_label("确定");
    treat_dialog_diagnose_button_cancel = gtk_button_new_with_label("取消");
    /* 设置控件默认大小 */
    gtk_widget_set_size_request(treat_dialog_diagnose_label, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_1, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_2, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_3, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_4, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_5, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_6, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_7, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_8, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_9, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_choose_10, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_ok, 100, 25);
    gtk_widget_set_size_request(treat_dialog_diagnose_button_cancel, 100, 25);
    /* 将控件放入GtkFixed框架 */
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_1), GTK_WIDGET(treat_dialog_diagnose_label), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_2), GTK_WIDGET(treat_dialog_diagnose_button_choose_1), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_3), GTK_WIDGET(treat_dialog_diagnose_button_choose_2), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_4), GTK_WIDGET(treat_dialog_diagnose_button_choose_3), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_5), GTK_WIDGET(treat_dialog_diagnose_button_choose_4), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_6), GTK_WIDGET(treat_dialog_diagnose_button_choose_5), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_7), GTK_WIDGET(treat_dialog_diagnose_button_choose_6), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_8), GTK_WIDGET(treat_dialog_diagnose_button_choose_7), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_9), GTK_WIDGET(treat_dialog_diagnose_button_choose_8), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_10), GTK_WIDGET(treat_dialog_diagnose_button_choose_9), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_11), GTK_WIDGET(treat_dialog_diagnose_button_choose_10), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_12), GTK_WIDGET(treat_dialog_diagnose_button_ok), , );
    gtk_fixed_put(GTK_FIXED(treat_dialog_diagnose_fixed_13), GTK_WIDGET(treat_dialog_diagnose_button_cancel), , );
    /* 将各个GtkFixed控件放入dialog框架 */
    gtk_box_pack_start(GTK_BOX(treat_dialog_diagnose_h_box_1), treat_dialog_diagnose_fixed_1, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_2, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_3, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_4, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_5, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_6, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_7, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_8, 0, 1, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_9, 1, 2, 3, 4, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_10, 0, 1, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(treat_dialog_diagnose_table), treat_dialog_diagnose_fixed_11, 1, 2, 4, 5, GTK_FILL, GTK_SHRINK, 0, 0);
    /* 将button控件放入alignment框架之中 */
    gtk_container_add(GTK_CONTAINER(treat_dialog_diagnose_alignment_right), treat_dialog_diagnose_fixed_12);
    gtk_container_add(GTK_CONTAINER(treat_dialog_diagnose_alignment_right), treat_dialog_diagnose_fixed_13);
    /* 将alignment框架放到h_box_2之中 */ /* 话说我为什么要设置为两个TRUE呢？真是令人费解 */
    gtk_box_pack_start(GTK_BOX(treat_dialog_diagnose_h_box_2), treat_dialog_diagnose_alignment_right, TRUE, TRUE, 0);
    /* 将h_box_1、table、h_box_2加入到v_box之中 */
    gtk_box_pack_start(GTK_BOX(treat_dialog_diagnose_v_box), treat_dialog_diagnose_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_diagnose_v_box), treat_dialog_diagnose_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(treat_dialog_diagnose_v_box), treat_dialog_diagnose_h_box_2, FALSE, FALSE, 0);
    /* 需将v_box放入dialog之中 */



}

