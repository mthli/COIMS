#include <gtk/gtk.h>
int main(int argc, char *argv[])
{
    /* 创建各个控件声明 */
    GtkWidget *dialog_diagnose;
    GtkWidget *person_dialog_diagnose_v_box, *person_dialog_diagnose_table,
              *person_dialog_diagnose_h_box_1, *person_dialog_diagnose_h_box_2;
    GtkWidget *person_dialog_diagnose_fixed_1, *person_dialog_diagnose_fixed_2, *person_dialog_diagnose_fixed_3,
              *person_dialog_diagnose_fixed_4, *person_dialog_diagnose_fixed_5, *person_dialog_diagnose_fixed_6,
              *person_dialog_diagnose_fixed_7, *person_dialog_diagnose_fixed_8, *person_dialog_diagnose_fixed_9;
    GtkWidget *person_dialog_diagnose_alignment_right;
    GtkWidget *person_dialog_diagnose_label;
    GtkWidget *person_dialog_diagnose_button_choose_1, *person_dialog_diagnose_button_choose_2,
              *person_dialog_diagnose_button_choose_3, *person_dialog_diagnose_button_choose_4,
              *person_dialog_diagnose_button_choose_5, *person_dialog_diagnose_button_choose_6;
    GtkWidget *person_dialog_diagnose_button_ok, *person_dialog_diagnose_button_cancel;
    /* 创建dialog内部框架 */
    person_dialog_diagnose_v_box = gtk_vbox_new(FALSE, 0);
    person_dialog_diagnose_table = gtk_table_new(3, 2, FALSE);
    person_dialog_diagnose_h_box_1 = gtk_hbox_new(FALSE, 0);
    person_dialog_diagnose_h_box_2 = gtk_hbox_new(FALSE, 0);
    person_dialog_diagnose_fixed_1 = gtk_fixed_new();
    person_dialog_diagnose_fixed_2 = gtk_fixed_new();
    person_dialog_diagnose_fixed_3 = gtk_fixed_new();
    person_dialog_diagnose_fixed_4 = gtk_fixed_new();
    person_dialog_diagnose_fixed_5 = gtk_fixed_new();
    person_dialog_diagnose_fixed_6 = gtk_fixed_new();
    person_dialog_diagnose_fixed_7 = gtk_fixed_new();
    person_dialog_diagnose_fixed_8 = gtk_fixed_new();
    person_dialog_diagnose_fixed_9 = gtk_fixed_new();
    /* 创建alignment框架 */
    person_dialog_diagnose_alignment_right = gtk_alignment_new(1, 0, 0, 0);
    /* 创建dialog内部控件 */
    person_dialog_diagnose_label = gtk_label_new("可多选：");
    person_dialog_diagnose_button_choose_1 = gtk_check_button_new_with_label("精神分裂症");
    person_dialog_diagnose_button_choose_2 = gtk_check_button_new_with_label("分裂情感性障碍");
    person_dialog_diagnose_button_choose_3 = gtk_check_button_new_with_label("偏执性精神病");
    person_dialog_diagnose_button_choose_4 = gtk_check_button_new_with_label("双相情感障碍");
    person_dialog_diagnose_button_choose_5 = gtk_check_button_new_with_label("癫痫所致精神障碍");
    person_dialog_diagnose_button_choose_6 = gtk_check_button_new_with_label("精神发育迟滞");
    person_dialog_diagnose_button_ok = gtk_button_new_with_label("确定");
    person_dialog_diagnose_button_cancel = gtk_button_new_with_label("取消");
    /* 设置控件默认大小 */
    gtk_widget_set_size_request(person_dialog_diagnose_label, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_1, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_2, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_3, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_4, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_5, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_choose_6, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_ok, 100, 25);
    gtk_widget_set_size_request(person_dialog_diagnose_button_cancel, 100, 25);
    /* 将控件放入GtkFixed框架 */
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_1), GTK_WIDGET(person_dialog_diagnose_label), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_2), GTK_WIDGET(person_dialog_diagnose_button_choose_1), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_3), GTK_WIDGET(person_dialog_diagnose_button_choose_2), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_4), GTK_WIDGET(person_dialog_diagnose_button_choose_3), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_5), GTK_WIDGET(person_dialog_diagnose_button_choose_4), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_6), GTK_WIDGET(person_dialog_diagnose_button_choose_5), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_7), GTK_WIDGET(person_dialog_diagnose_button_choose_6), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_8), GTK_WIDGET(person_dialog_diagnose_button_ok), , );
    gtk_fixed_put(GTK_FIXED(person_dialog_diagnose_fixed_9), GTK_WIDGET(person_dialog_diagnose_button_cancel), , );
    /* 将各个GtkFixed控件放入dialog框架 */
    gtk_box_pack_start(GTK_BOX(person_dialog_diagnose_h_box_1), person_dialog_diagnose_fixed_1, FALSE, FALSE, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_2, 0, 1, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_3, 1, 2, 0, 1, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_4, 0, 1, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_5, 1, 2, 1, 2, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_6, 0, 1, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    gtk_table_attach(GTK_TABLE(person_dialog_diagnose_table), person_dialog_diagnose_fixed_7, 1, 2, 2, 3, GTK_FILL, GTK_SHRINK, 0, 0);
    /* 将button控件放入alignment框架之中 */
    gtk_container_add(GTK_CONTAINER(person_dialog_diagnose_alignment_right), person_dialog_diagnose_fixed_8);
    gtk_container_add(GTK_CONTAINER(person_dialog_diagnose_alignment_right), person_dialog_diagnose_fixed_9);
    /* 将alignment框架放到h_box_2之中 */ /* 话说我为什么要设置为两个TRUE呢？真是令人费解 */
    gtk_box_pack_start(GTK_BOX(person_dialog_diagnose_h_box_2), person_dialog_diagnose_alignment_right, TRUE, TRUE, 0);
    /* 将h_box_1、table、h_box_2加入到v_box之中 */
    gtk_box_pack_start(GTK_BOX(person_dialog_diagnose_v_box), person_dialog_diagnose_h_box_1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(person_dialog_diagnose_v_box), person_dialog_diagnose_table, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(person_dialog_diagnose_v_box), person_dialog_diagnose_h_box_2, FALSE, FALSE, 0);
    /* 需将v_box放入dialog之中 */



}

