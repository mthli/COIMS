#include "coims.h"

/* 各种强制转换还是有必要的，避免错误和警告，所以还是加上的好 */

/* 回调函数声明 */
void help_about(GtkWidget *widget, gpointer parents);
void new_person(GtkWidget *widget, Item *parents);
void cancel(GtkWidget *widget, Item *parents);
void photo_choose(GtkWidget *widget, Item *parents);
void birthday_choose(GtkWidget *widget, Item *parents);
void happened_choose(GtkWidget *widget, Item *parents);
void into_choose(GtkWidget *widget, Item *parents);
void out_choose(GtkWidget *widget, Item *parents);
void panss(GtkWidget *widght, Item *parents);

int main(int argc, char **argv)
{
    /* 主框架部分 */
    GtkWidget *main_window;
    GtkWidget *main_vbox;
    GtkWidget *main_hbox;
    /* 菜单栏部分 */
    GtkWidget *menubar;
    GtkWidget *menubar_item;
    GtkWidget *menu;
    GtkWidget *menu_item;
    /* notebook部分 */
    GtkWidget *person_notebook;
    /* 临时框架 */
    GtkWidget *temp_vbox;
    GtkWidget *temp_hbox;
    GtkWidget *temp_table;
    GtkWidget *temp_scrolled;
    GtkWidget *temp_separator;
    GtkWidget *temp_label;
    GtkWidget *temp_entry;
    GtkWidget *temp_button;

    /* 开辟notebook内部控件所需的内存空间 */
    Item *item;
    item = (Item *)malloc(sizeof(Item));

    /* 所有Gtk+程序都必须有的开头 */
    gtk_init(&argc, &argv);

    /* main_window部分：
     * 暂时不考虑窗口大小和缩放问题。
     */
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(
            GTK_WINDOW(main_window),
            "公共卫生管理系统"
            );
    gtk_window_set_position(
            GTK_WINDOW(main_window),
            GTK_WIN_POS_CENTER
            );
    g_signal_connect(
            G_OBJECT(main_window),
            "destroy",
            G_CALLBACK(gtk_main_quit),
            NULL
            );
    gtk_window_set_resizable(GTK_WINDOW(main_window), FALSE);

    /* 菜单栏部分 */
    menubar = gtk_menu_bar_new();
    /* “病例”菜单 */
    menubar_item = gtk_menu_item_new_with_label("病例");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("新建");
    g_signal_connect(
            G_OBJECT(menu_item),
            "activate",
            G_CALLBACK(new_person),
            item
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    menu_item = gtk_menu_item_new_with_label("保存");
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            ); /* 回调函数 */
    menu_item = gtk_menu_item_new_with_label("取消");
    g_signal_connect(
            G_OBJECT(menu_item),
            "activate",
            G_CALLBACK(cancel),
            item
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    menu_item = gtk_menu_item_new_with_label("退出");
    g_signal_connect(G_OBJECT(menu_item),
                     "activate",
                     G_CALLBACK(gtk_main_quit),
                     NULL);
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    gtk_menu_item_set_submenu(
            GTK_MENU_ITEM(menubar_item),
            menu
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menubar),
            menubar_item
            );
    /* “报表”菜单 */
    menubar_item = gtk_menu_item_new_with_label("报表");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("生成《危重病人救治情况月报表》");
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            ); /* 回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    menu_item = gtk_menu_item_new_with_label("生成《危害病人救治费用明细表》");
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            ); /* 回调函数 */
    gtk_menu_item_set_submenu(
            GTK_MENU_ITEM(menubar_item),
            menu
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menubar),
            menubar_item
            );
    /* “数据库”菜单 */
    menubar_item = gtk_menu_item_new_with_label("数据");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("备份");
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            ); /* 回调函数 */
    gtk_menu_item_set_submenu(
            GTK_MENU_ITEM(menubar_item),
            menu
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menubar),
            menubar_item
            );
    /* “帮助”菜单 */
    menubar_item = gtk_menu_item_new_with_label("帮助");
    menu = gtk_menu_new();
    menu_item = gtk_menu_item_new_with_label("使用说明");
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            ); /* 回调函数 */
    menu_item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    menu_item = gtk_menu_item_new_with_label("关于");
    g_signal_connect(
            G_OBJECT(menu_item),
            "activate",
            G_CALLBACK(help_about),
            NULL
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menu),
            menu_item
            );
    gtk_menu_item_set_submenu(
            GTK_MENU_ITEM(menubar_item),
            menu
            );
    gtk_menu_shell_append(
            GTK_MENU_SHELL(menubar),
            menubar_item
            );
    main_vbox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(
            GTK_BOX(main_vbox),
            menubar,
            FALSE,
            FALSE,
            0
            );

    /* 侧边栏部分：
     * 注意一下控件的尺寸大小和参数选项；
     * 另外按照demo里面的例子仔细做一下搜索框，提供三个选项：
     * 1. 按照身份证搜索（必须有）
     * 2. 按照住院号搜索（必须有）
     * 3. 按照三联单号搜索（可选，所以暂时不做）
     */
    temp_vbox = gtk_vbox_new(FALSE, 0);
    temp_hbox = gtk_hbox_new(FALSE, 0);
    /* 指纹识别模块和人脸识别模块暂时不做了，做不了
     * 
    temp_button = gtk_button_new_with_label("人脸识别");
    gtk_widget_set_size_request(temp_button, 100, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            temp_button,
            TRUE,
            TRUE,
            0
            );
    temp_button = gtk_button_new_with_label("指纹识别");
    gtk_widget_set_size_request(temp_button, 100, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            temp_button,
            TRUE,
            TRUE,
            0
            );
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_hbox,
            FALSE,
            FALSE,
            0
            );
    temp_separator = gtk_hseparator_new();
    gtk_widget_set_size_request(temp_separator, 200, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_separator,
            FALSE,
            FALSE,
            0
            );
    */
    temp_hbox = gtk_hbox_new(FALSE, 0);
    temp_entry = gtk_entry_new();
    gtk_widget_set_size_request(temp_entry, 150, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            temp_entry,
            TRUE,
            TRUE,
            0
            );
    temp_button = gtk_button_new_with_label("搜索");
    gtk_widget_set_size_request(temp_button, 50, 25); /* 回调函数 */
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            temp_button,
            TRUE,
            TRUE,
            0
            );
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_hbox,
            FALSE,
            FALSE,
            0
            );
    temp_separator = gtk_hseparator_new();
    gtk_widget_set_size_request(temp_separator, 200, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_separator,
            FALSE,
            FALSE,
            0
            );
    temp_label = gtk_label_new("在院病人列表：");
    gtk_widget_set_size_request(temp_label, 200, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_label,
            FALSE,
            FALSE,
            0
            );
    temp_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(temp_scrolled),
            GTK_POLICY_AUTOMATIC,
            GTK_POLICY_AUTOMATIC
            );
    /* 在滚动窗口temp_scrolled中放置列表，
     * 注意一下文本的长短和对齐问题
     */
    (*item).hospital_list = gtk_clist_new(2);
    gtk_clist_set_row_height(
            GTK_CLIST((*item).hospital_list),
            25
            );
    gtk_clist_set_shadow_type(
            GTK_CLIST((*item).hospital_list),
            GTK_SHADOW_IN
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).hospital_list),
            0,
            "住院号"
            );
    /* gtk_clist_set_column_width(
            GTK_CLIST((*item).hospital_list),
            0,
            100
            ); */
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).hospital_list),
            0,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).hospital_list),
            0,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).hospital_list),
            1,
            "姓名"
            );
    /* gtk_clist_set_column_width(
            GTK_CLIST((*item).hospital_list),
            1,
            100
            ); */
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).hospital_list),
            1,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).hospital_list),
            1,
            TRUE
            );
    gtk_clist_column_titles_show(GTK_CLIST((*item).hospital_list));
    gtk_scrolled_window_add_with_viewport(
            GTK_SCROLLED_WINDOW(temp_scrolled),
            (*item).hospital_list
            );
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_scrolled,
            TRUE,
            TRUE,
            0
            );
    temp_button = gtk_button_new_with_label("新建");
    g_signal_connect(
            G_OBJECT(temp_button),
            "clicked",
            G_CALLBACK(new_person),
            item
            );
    gtk_widget_set_size_request(temp_button, 200, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_button,
            FALSE,
            FALSE,
            0
            );
    main_hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(
            GTK_BOX(main_hbox),
            temp_vbox,
            TRUE,
            TRUE,
            0
            );

    /* person_notebook部分 */
    person_notebook = gtk_notebook_new();
    gtk_notebook_set_tab_pos(
            GTK_NOTEBOOK(person_notebook),
            GTK_POS_TOP
            );
    /* 首先制作“住院信息”标签页 */
    temp_table = gtk_table_new(20, 5, FALSE);
    (*item).photo_button = gtk_button_new();
    g_signal_connect(
            G_OBJECT((*item).photo_button),
            "clicked",
            G_CALLBACK(photo_choose),
            item
            );
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).photo_button,
            0, 1,
            0, 6,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_button = gtk_button_new_with_label("拍照"); /* 回调函数 */
    gtk_widget_set_size_request(temp_button, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_button,
            0, 1,
            6, 7,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("姓名：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            0, 1,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).name_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).name_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).name_entry,
            2, 3,
            0, 1,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("性别：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            0, 1,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).sex_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).sex_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).sex_combo),
            "男"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).sex_combo),
            "女"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).sex_combo),
            "其他"
            );
    gtk_widget_set_size_request((*item).sex_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).sex_combo,
            4, 5,
            0, 1,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("生日：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), temp_label,
            1, 2,
            1, 2,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).birthday_button = gtk_button_new_with_label("选择日期");
    g_signal_connect(
            G_OBJECT((*item).birthday_button),
            "clicked",
            G_CALLBACK(birthday_choose),
            item
            );
    gtk_widget_set_size_request((*item).birthday_button, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).birthday_button,
            2, 3,
            1, 2,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("年龄：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            1, 2,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).age_entry = gtk_entry_new(); /* 可以由生日计算得到，这里帮忙做了 */
    gtk_widget_set_size_request((*item).age_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).age_entry,
            4, 5,
            1, 2,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("婚姻状况：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), temp_label,
            1, 2,
            2, 3,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).marriage_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            "未婚"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            "已婚"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            "再婚"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            "离异"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).marriage_combo),
            "未知"
            );
    gtk_widget_set_size_request((*item).marriage_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).marriage_combo,
            2, 3,
            2, 3,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("文化程度：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            2, 3,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).edu_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            "文盲"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            "小学"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            "初中"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            "高中"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).edu_combo),
            "本科及本科以上"
            );
    gtk_widget_set_size_request((*item).edu_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), (*item).edu_combo,
            4, 5,
            2, 3,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("身份证：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), temp_label,
            1, 2,
            3, 4,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).id_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).id_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), (*item).id_entry,
            2, 3,
            3, 4,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("户籍证明：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), temp_label,
            3, 4,
            3, 4,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).census_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).census_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), (*item).census_entry,
            4, 5,
            3, 4,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("事发时间：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            4, 5,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).happened_button = gtk_button_new_with_label("选择日期");
    g_signal_connect(
            G_OBJECT((*item).happened_button),
            "clicked",
            G_CALLBACK(happened_choose),
            item
            );
    gtk_widget_set_size_request((*item).happened_button, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).happened_button,
            2, 3,
            4, 5,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("事发地点：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            4, 5,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).place_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "莲湖区"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "碑林区"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "雁塔区"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "新城区"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "未央区"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).place_combo),
            "长安区"
            );
    gtk_widget_set_size_request((*item).place_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).place_combo,
            4, 5,
            4, 5,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("三联单：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2, 5, 6,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).bill_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).bill_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).bill_entry,
            2, 3,
            5, 6,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("住院号：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            5, 6,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).num_enrty = gtk_entry_new();
    gtk_widget_set_size_request((*item).num_enrty, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).num_enrty,
            4, 5,
            5, 6,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("入院时间：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table), temp_label,
            1, 2,
            6, 7,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).into_button = gtk_button_new_with_label("选择日期");
    g_signal_connect(
            G_OBJECT((*item).into_button),
            "clicked",
            G_CALLBACK(into_choose),
            item
            );
    gtk_widget_set_size_request((*item).into_button, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).into_button,
            2, 3,
            6, 7,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("入院评分：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            6, 7,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).inps_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).inps_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).inps_entry,
            4, 5,
            6, 7,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("出院时间：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            7, 8,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).out_button = gtk_button_new_with_label("选择日期");
    g_signal_connect(
            G_OBJECT((*item).out_button),
            "clicked",
            G_CALLBACK(out_choose),
            item
            );
    gtk_widget_set_size_request((*item).out_button, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).out_button,
            2, 3,
            7, 8,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("出院评分：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            7, 8,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).outps_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).outps_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).outps_entry,
            4, 5,
            7, 8,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("住院天数：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            8, 9,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).days_enrty = gtk_entry_new();
    gtk_widget_set_size_request((*item).days_enrty, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).days_enrty,
            2, 3,
            8, 9,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("减分率：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            8, 9,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).persent_button = gtk_button_new_with_label("计算");
    g_signal_connect(
            G_OBJECT((*item).persent_button),
            "clicked",
            G_CALLBACK(panss),
            item
            );
    gtk_widget_set_size_request((*item).persent_button, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).persent_button,
            4, 5,
            8, 9,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("住院花费：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            9, 10,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).cost_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).cost_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).cost_entry,
            2, 3,
            9, 10,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("患者去向：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4, 9, 10,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).goto_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            "救助站接走"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            "转到市二院"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            "转到市按摩院"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            "转到西安医学院附属医院市结核医院"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).goto_combo),
            "家属接走"
            );
    gtk_widget_set_size_request((*item).goto_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).goto_combo,
            4, 5,
            9, 10,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_separator = gtk_hseparator_new();
    gtk_widget_set_size_request(temp_separator, 500, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_separator,
            1, 5,
            10, 11,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("行为分级：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            11, 12,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).level_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "0级：无符合以下1——5级中的任何行为"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "1级：口头威胁、喊叫、但没有打砸行为"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "2级：打砸行为，局限在家里，针对财物；不能接受劝说而停止"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "3级：明显打砸行为，不分场合，针对财物或人，不能接受劝说而停止"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "4级：连续的打砸行为，不分场合，针对财物或人，不能接受劝说而停止；包括自伤、自杀"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).level_combo),
            "5级：持械针对的任何暴力行为，或者纵火、爆炸等行为；无论在家里还是公共场合"
            );
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).level_combo,
            2, 5,
            11, 12,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("患者症状：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            12, 13,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).symptom_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "精神分裂症"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "分裂情感性障碍"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "偏执性障碍"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "双相情感障碍"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "癫痫所致精神障碍"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).symptom_combo),
            "精神发育迟滞"
            );
    gtk_widget_set_size_request((*item).symptom_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).symptom_combo,
            2, 3,
            12, 13,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("患者状态：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            12, 13,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).status_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).status_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).status_combo),
            "兴奋状态"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).status_combo),
            "偏执状态"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).status_combo),
            "缄默状态"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).status_combo),
            "焦虑状态"
            );
    gtk_widget_set_size_request((*item).status_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).status_combo,
            4, 5,
            12, 13,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("抗精神病药物：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            13, 14,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).psy_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "氯丙嗪片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "氯丙嗪注射液"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "奋乃静片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "氟哌啶醇片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "氟哌啶醇注射液"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "奥氮平片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "喹硫平片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "阿立哌唑口腔崩解片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).psy_combo),
            "利培酮片"
            );
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).psy_combo,
            2, 3,
            13, 14,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("抗抑郁药物：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            13, 14,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).dep_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "多虑平片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "氯丙咪嗪片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "氟西丁片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "氟伏沙明片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "帕罗西丁片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "舍曲林片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "曲唑酮片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "米氯平"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).dep_combo),
            "文拉法星片"
            );
    gtk_widget_set_size_request((*item).dep_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).dep_combo,
            4, 5,
            13, 14,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("抗焦虑药物：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            14, 15,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).anxiety_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).anxiety_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).anxiety_combo),
            "阿普唑仑片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).anxiety_combo),
            "劳拉西泮片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).anxiety_combo),
            "艾司唑仑片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).anxiety_combo),
            "佐匹克隆片"
            );
    gtk_widget_set_size_request((*item).anxiety_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).anxiety_combo,
            2, 3,
            14, 15,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("心境稳定剂：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            14, 15,
            GTK_FILL,
            GTK_FILL,
            0, 0);
    (*item).heart_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).heart_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).heart_combo),
            "丙戊酸盐片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).heart_combo),
            "丙戊酸盐注射液"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).heart_combo),
            "卡马西平片"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).heart_combo),
            "碳酸锂片"
            );
    gtk_widget_set_size_request((*item).heart_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).heart_combo,
            4, 5,
            14, 15,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_separator = gtk_hseparator_new();
    gtk_widget_set_size_request(temp_separator, 500, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_separator,
            1, 5,
            15, 16,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("物质依赖：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            16, 17,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).addicted_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).addicted_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).addicted_combo),
            "吸烟"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).addicted_combo),
            "饮酒"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).addicted_combo),
            "吸烟和饮酒"
            );
    gtk_widget_set_size_request((*item).addicted_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).addicted_combo,
            2, 3,
            16, 17,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("是否吸毒：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            16, 17,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).drug_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).drug_combo),
            ""
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).drug_combo),
            "是"
            );
    gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT((*item).drug_combo),
            "否"
            );
    gtk_widget_set_size_request((*item).drug_combo, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).drug_combo,
            4, 5,
            16, 17,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("躯体疾病：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            17, 18,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).body_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).body_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).body_entry,
            2, 3,
            17, 18,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("传染病：");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            3, 4,
            17, 18,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    (*item).infect_entry = gtk_entry_new();
    gtk_widget_set_size_request((*item).infect_entry, 150, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            (*item).infect_entry,
            4, 5,
            17, 18,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new(" ");
    gtk_widget_set_size_request(temp_label, 100, 25);
    gtk_table_attach(
            GTK_TABLE(temp_table),
            temp_label,
            1, 2,
            18, 19,
            GTK_FILL,
            GTK_FILL,
            0, 0
            );
    temp_label = gtk_label_new("住院信息");
    gtk_notebook_append_page(
            GTK_NOTEBOOK(person_notebook),
            temp_table,
            temp_label
            );
    /* 接下来创建“历史记录”标签页 */
    temp_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(temp_scrolled),
            GTK_POLICY_AUTOMATIC,
            GTK_POLICY_AUTOMATIC
            );
    /* 开始创建“历史记录”列表 */
    (*item).histroy_list = gtk_clist_new(16);
    gtk_clist_set_row_height(
            GTK_CLIST((*item).histroy_list),
            25
            );
    gtk_clist_set_shadow_type(
            GTK_CLIST((*item).histroy_list),
            GTK_SHADOW_IN
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            0,
            "入院时间"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            0,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            0,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            1,
            "出院时间"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            1,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            1,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            2,
            "入院评分"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            2,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            2,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            3,
            "出院评分"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            3,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            3,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            4,
            "减分率"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            4,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            4,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            5,
            "行为分级"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            5,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            5,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            6,
            "患者症状"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            6,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            6,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            7,
            "患者状态"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            7,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            7,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            8,
            "抗精神病药物"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            8,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            8,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            9,
            "抗抑郁药物"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            9,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            9,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            10,
            "抗焦虑药物"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            10,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            10,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            11,
            "心境稳定剂"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            11,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            11,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            12,
            "物质依赖"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            12,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            12,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            13,
            "是否吸毒"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            13,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            13,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            14,
            "躯体疾病"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            14,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            14,
            TRUE
            );
    gtk_clist_set_column_title(
            GTK_CLIST((*item).histroy_list),
            15,
            "传染病"
            );
    gtk_clist_set_column_justification(
            GTK_CLIST((*item).histroy_list),
            15,
            GTK_JUSTIFY_CENTER
            );
    gtk_clist_set_column_auto_resize(
            GTK_CLIST((*item).histroy_list),
            15,
            TRUE
            );
    gtk_clist_column_titles_show(GTK_CLIST((*item).histroy_list));
    gtk_scrolled_window_add_with_viewport(
            GTK_SCROLLED_WINDOW(temp_scrolled),
            (*item).histroy_list
            );
    temp_label = gtk_label_new("历史记录");
    gtk_notebook_append_page(
            GTK_NOTEBOOK(person_notebook),
            temp_scrolled,
            temp_label
            );

    /* 底部按钮设置 */
    temp_vbox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            person_notebook,
            TRUE,
            TRUE,
            0
            );
    temp_hbox = gtk_hbox_new(FALSE, 0);
    (*item).out_check = gtk_check_button_new_with_label("确认出院");
    gtk_widget_set_size_request((*item).out_check, 100, 25);
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            (*item).out_check,
            FALSE,
            FALSE,
            0
            );
    temp_button = gtk_button_new_with_label("确定"); /* 回调函数 */
    gtk_box_pack_start(GTK_BOX(temp_hbox),
            temp_button,
            TRUE,
            TRUE,
            0
            );
    temp_button = gtk_button_new_with_label("取消");
    g_signal_connect(
            G_OBJECT(temp_button),
            "clicked",
            G_CALLBACK(cancel),
            item
            );
    gtk_box_pack_start(
            GTK_BOX(temp_hbox),
            temp_button,
            TRUE,
            TRUE,
            0
            );
    gtk_box_pack_start(
            GTK_BOX(temp_vbox),
            temp_hbox,
            TRUE,
            TRUE,
            0
            );
    gtk_box_pack_start(
            GTK_BOX(main_hbox),
            temp_vbox,
            TRUE,
            TRUE,
            0
            );
    gtk_box_pack_start(
            GTK_BOX(main_vbox),
            main_hbox,
            TRUE,
            TRUE,
            10
            );

    /* 把主框架放入主窗口 */
    gtk_container_add(
            GTK_CONTAINER(main_window),
            main_vbox
            );

    /* 显示所有控件 */
    gtk_widget_show_all(main_window);
    /* 进入事件循环 */
    gtk_main();

    return 0;
}
