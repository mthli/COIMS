#include "new.h"

/* 回调函数声明 */

/* 主函数部分 */
int main(int argc, char *argv[])
{
    /* 主窗口main_window */
    GtkWidget *main_window;
    /* main_window的内部框架 */
    GtkWidget *main_vbox;
    GtkWidget *main_hbox;
    GtkWidget *main_table;

    /* 菜单栏menubar */
    GtkWidget *menubar;
    /* 菜单外壳menubar_item */
    GtkWidget *menubar_item;
    /* 菜单menu */
    GtkWidget *menu;
    /* 菜单选项menu_item */
    GtkWidget *menu_item;

    /* 主标签页main_notebook */
    GtkWidget *main_notebook;
    /* 信息标签页info_notebook */

    /* 通用框架 */
    GtkWidget *temp_vbox;
    GtkWidget *temp_hbox;
    GtkWidget *temp_table;
    /* 通用控件 */
    GtkWidget *temp_scrolled;
    GtkWidget *temp_label;
    GtkWidget *temp_entry;
    GtkWidget *temp_button;
    GtkWidget *temp_separator;

    /* 以上声明构建的控件皆为“一次信号对应一次操作”；
     * 余下的控件皆需要“一次信号对应多次操作”，因此需要使用结构体指针，
     * 暂不做处理。
     */

    /* 每个GTK+程序必不可少的部分 */
    gtk_init(&argc, &argv);
    
    /* 创建main_window */
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "公共卫生管理系统");
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    /* 暂时不设置窗口大小 */
    /* 将destroy信号与主窗口连接 */
    g_signal_connect(G_OBJECT(main_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* 创建菜单栏 */
    menubar = gtk_menu_bar_new();
    /* 首先创建“病例”菜单 */
    menubar_item = gtk_menu_item_new_with_label("病例");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("新建");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    menu_item = gtk_menu_item_new_with_label("保存");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    menu_item = gtk_menu_item_new_with_label("退出");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);
    /* 接着创建“报表”菜单 */
    menubar_item = gtk_menu_item_new_with_label("报表");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("生成《危重病人救治情况月报表》");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    menu_item = gtk_menu_item_new_with_label("生成《危害病人救治费用明细表》");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);
    /* 接着创建“数据库”菜单 */
    menubar_item = gtk_menu_item_new_with_label("数据库");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("备份数据库");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);
    /* 最后创建“帮助”菜单 */
    menubar_item = gtk_menu_item_new_with_label("帮助");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("使用说明");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    menu_item = gtk_menu_item_new_with_label("关于");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item); /* 注意添加相应的回调函数 */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_item);
    /* 至此menubar的创建工作完毕 */

    /* 开始创建main_notebook部分。
     * 首先创建其内部控件，最后再组装进main_notebook。
     */
    /* 创建一个temp_vbox框架，用于组装“搜索”部分的控件和“在院病人列表“部分的控件 */
    temp_vbox = gtk_vbox_new(FALSE, 0);
    /* 首先创建“搜索”部分的控件 */
    temp_label = gtk_label_new("身份证：");
    gtk_widget_set_size_request(GTK_WIDGET(temp_label), 100, 25); /* 后方可再调整尺寸 */
    temp_entry = gtk_entry_new();
    gtk_widget_set_size_request(GTK_WIDGET(temp_entry), 100, 25);
    temp_hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(temp_hbox), temp_label, 
                       FALSE, FALSE, 0); /* 注意一下这里的后三个参，必要时可以修改；下方同理 */
    gtk_box_pack_start(GTK_BOX(temp_hbox), temp_entry,
                       FALSE, FALSE, 0); 
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_hbox,
                       FALSE, FALSE, 0);
    temp_button = gtk_button_new_with_label("搜索历史记录");
    gtk_widget_set_size_request(GTK_WIDGET(temp_button), 200, 25); /* 注意添加相应的回调函数 */
    /* 令人疑惑的是，这里需不需要统一把控件组装进temp_hbox，再组装进temp_vbox呢？
     * 可以认真思考一下。
     */
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_button,
                       FALSE, FALSE, 0);
    temp_separator = gtk_hseparator_new();
    gtk_widget_set_size_request(GTK_WIDGET(temp_separator), 200, 25);
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_separator,
                       FALSE, FALSE, 0);
    temp_label = gtk_label_new("住院号：");
    gtk_widget_set_size_request(GTK_WIDGET(temp_label), 100, 25);
    temp_entry = gtk_entry_new();
    gtk_widget_set_size_request(GTK_WIDGET(temp_entry), 100, 25);
    temp_hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(temp_hbox), temp_label,
                       FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(temp_hbox), temp_entry,
                       FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_hbox,
                       FALSE, FALSE, 0);
    temp_button = gtk_button_new_with_label("搜索在院病人");
    gtk_widget_set_size_request(GTK_WIDGET(temp_button), 200, 25); /* 注意添加相应的回调函数 */
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_button,
                       FALSE, FALSE, 0);
    /* 至此“搜索”部分创建完毕，开始创建“在线病人列表”部分。
     * 值得注意的是，在temp_scrolled控件里面使用的tree_view控件需要使用结构体指针来完成，
     * 所以暂时只创建一个滚动窗口，其余部分后期完成。
     */
    temp_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(temp_scrolled), 
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_widget_set_size_request(GTK_WIDGET(temp_scrolled), 200, 320); /* 是否有必要设置默认大小值得商榷 */
    gtk_box_pack_start(GTK_BOX(temp_vbox), temp_scrolled, 
                       FALSE, FALSE, 0);
    /* 至此“在线病人列表”部分创建完毕 */

    /* 首先创建info_notebook内部控件，然后再将其组装进info_notebook */
    temp_table = 



