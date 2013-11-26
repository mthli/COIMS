#include "fwd.h"

/* 回调函数原型 */
void window_menubar_help_about_callback(GtkWidget *widget, gpointer parents);
void window_button_new_callback(GtkWidget *widget, gpointer parents);
void window_button_query_callback(GtkWidget *widget, gpointer parents);

/* */

int main(int argc, char *argv[]) /* 注意是char *argv[] */
{
    /* 主窗口控件声明 */
    GtkWidget *window;
    /* window_vbox 和 window_hbox 框架声明 */
    GtkWidget *window_vbox;
    GtkWidget *window_hbox;
   /* 菜单栏控件声明 */
    GtkWidget *window_menubar;
    GtkWidget *window_menu_file, *window_menu_make, *window_menu_data, *window_menu_help;
    GtkWidget *window_menubar_file, *window_menubar_make, *window_menubar_data, *window_menubar_help;
    GtkWidget *window_menubar_file_new, *window_menubar_file_query,
              *window_menubar_file_delete, *window_menubar_file_quit,
              *window_menubar_make_status, *window_menubar_make_cost,
              *window_menubar_data_buckup, *window_menubar_data_clean,
              *window_menubar_help_show, *window_menubar_help_about,
              *window_menubar_separator_1, *window_menubar_separator_2,
              *window_menubar_separator_3, *window_menubar_separator_4;
    /* 选项按钮控件声明 */
    GtkWidget *window_button_new, *window_button_query, *window_button_quit;
    /* 选项按钮的 Fixed 框架声明 */
    GtkWidget *window_fixed_new, *window_fixed_query, *window_fixed_quit;

    /* 每个 GTK+ 程序必不可少的部分 */
    gtk_init(&argc, &argv);

    /* 创建主窗口 */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* 设置主窗口名称 */
    gtk_window_set_title(GTK_WINDOW(window), "FWD");
    /* 设置主窗口默认显示位置为中心显示 */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    /* 设置主窗口默认大小，并禁止窗口最大化 */
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_widget_set_size_request(GTK_WIDGET(window), 500, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    /* 将destroy信号与主窗口连接 */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建window_vbox 和 window_hbox 框架 */
    window_vbox = gtk_vbox_new(FALSE, 0);
    window_hbox = gtk_hbox_new(FALSE, 0);

    /* 创建菜单栏 */
    window_menubar = gtk_menu_bar_new();
    /* 创建菜单外壳 */
    window_menu_file = gtk_menu_new();
    window_menu_make = gtk_menu_new();
    window_menu_data = gtk_menu_new();
    window_menu_help = gtk_menu_new();
    /* 创建各个菜单 */ /* 解决中文乱码，转为UTF-8编码格式 */
    window_menubar_file = gtk_menu_item_new_with_label("病历");
    window_menubar_make = gtk_menu_item_new_with_label("报表");
    window_menubar_data = gtk_menu_item_new_with_label("数据");
    window_menubar_help = gtk_menu_item_new_with_label("帮助");
    /* 创建各个菜单项 */
    window_menubar_file_new = gtk_menu_item_new_with_label("新建");
    window_menubar_file_query = gtk_menu_item_new_with_label("查看");
    window_menubar_file_delete = gtk_menu_item_new_with_label("删除");
    window_menubar_file_quit = gtk_menu_item_new_with_label("退出");
    window_menubar_make_status = gtk_menu_item_new_with_label("生成《危重病人救治情况月报表》");
    window_menubar_make_cost = gtk_menu_item_new_with_label("生成《危害病人救治费用明细表》");
    window_menubar_data_buckup = gtk_menu_item_new_with_label("备份所有数据");
    window_menubar_data_clean = gtk_menu_item_new_with_label("清除所有数据");
    window_menubar_help_show = gtk_menu_item_new_with_label("查看帮助");
    window_menubar_help_about = gtk_menu_item_new_with_label("关于FWD");
    window_menubar_separator_1 = gtk_separator_menu_item_new();
    window_menubar_separator_2 = gtk_separator_menu_item_new();
    window_menubar_separator_3 = gtk_separator_menu_item_new();
    window_menubar_separator_4 = gtk_separator_menu_item_new();
    /* 将各个菜单项加入到各自所属的菜单中 */
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_file), window_menubar_file_new);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_file), window_menubar_file_query);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_file), window_menubar_file_delete);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_file), window_menubar_separator_1);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_file), window_menubar_file_quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_make), window_menubar_make_status);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_make), window_menubar_separator_2);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_make), window_menubar_make_cost);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_data), window_menubar_data_buckup);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_data), window_menubar_separator_3);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_data), window_menubar_data_clean);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_help), window_menubar_help_show);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_help), window_menubar_separator_4);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menu_help), window_menubar_help_about);
    /* 将菜单与菜单外壳相关联 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(window_menubar_file), window_menu_file);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(window_menubar_make), window_menu_make);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(window_menubar_data), window_menu_data);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(window_menubar_help), window_menu_help);
    /* 蒋各个菜单分别加入到菜单栏中 */
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menubar), window_menubar_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menubar), window_menubar_make);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menubar), window_menubar_data);
    gtk_menu_shell_append(GTK_MENU_SHELL(window_menubar), window_menubar_help);
    /* 将菜单项与各自的信号相关联 */
    g_signal_connect(G_OBJECT(window_menubar_file_new), "activate", G_CALLBACK(window_button_new_callback), NULL);
    g_signal_connect(G_OBJECT(window_menubar_file_query), "activate", G_CALLBACK(window_button_query_callback), NULL);
    g_signal_connect(G_OBJECT(window_menubar_file_quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(window_menubar_help_about), "activate", G_CALLBACK(window_menubar_help_about_callback), (gpointer)window);
    /* */

    /* 创建 window_button* */
    window_button_new = gtk_button_new_with_label("新建");
    window_button_query = gtk_button_new_with_label("查看");
    window_button_quit = gtk_button_new_with_label("退出");
    /* 创建 window_button* 的 Fixed 框架 */
    window_fixed_new = gtk_fixed_new();
    window_fixed_query = gtk_fixed_new();
    window_fixed_quit = gtk_fixed_new();
    /* 设置 window_button* 的默认大小 */
    gtk_widget_set_size_request(window_button_new, 100, 100);
    gtk_widget_set_size_request(window_button_query, 100, 100);
    gtk_widget_set_size_request(window_button_quit, 100, 100);
    /* 将 window_button* 放入 Fixed 框架 */
    gtk_fixed_put(GTK_FIXED(window_fixed_new), GTK_WIDGET(window_button_new), 50, 75);
    gtk_fixed_put(GTK_FIXED(window_fixed_query), GTK_WIDGET(window_button_query), 50, 75);
    gtk_fixed_put(GTK_FIXED(window_fixed_quit), GTK_WIDGET(window_button_quit), 50, 75);
    /* 把 Fixed 框架放入 window_hbox 之中 */
    gtk_box_pack_start(GTK_BOX(window_hbox), window_fixed_new, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_hbox), window_fixed_query, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_hbox), window_fixed_quit, FALSE, FALSE, 0);
    /* 将回调函数与各个 wiindow_button* 相关联 */
    g_signal_connect(G_OBJECT(window_button_new), "clicked", G_CALLBACK(window_button_new_callback), (gpointer)window);
    g_signal_connect(G_OBJECT(window_button_query), "clicked", G_CALLBACK(window_button_query_callback), (gpointer)window);
    g_signal_connect(G_OBJECT(window_button_quit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    /* */

    /* 将各个控件放入 window_vbox 之中 */
    gtk_box_pack_start(GTK_BOX(window_vbox), GTK_WIDGET(window_menubar), FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(window_vbox), GTK_WIDGET(window_hbox), FALSE, FALSE, 0);

     /* 把 window_vbox 放入 主窗口之中 */
     gtk_container_add(GTK_CONTAINER(window), window_vbox);
     /* 显示所有窗口控件 */
     gtk_widget_show_all(window);
     /* 结束 */
     gtk_main();
     return 0;
}
