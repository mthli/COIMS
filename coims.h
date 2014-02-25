#ifndef __COIMS__
#define __COIMS__

#include <gtk/gtk.h>
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/* 只有以下几种控件需要加入结构体：
 *      1. 不可替代的button；
 *      2. 不可替代的combo；
 *      3. 不可替代的entry；
 *      4. 不可替代的text_view；
 *      5. 不可替代的tree_view；
 *      6. 其他不可替代的控件。
 */
typedef struct _Item {
    /* “在院病人列表”树形图 */
    GtkWidget *hospital_list;
    gint get_row;
    gint get_column;

    /* “住院信息”标签页内容 */
    GtkWidget *photo_button;    /* “照片”按钮 */
    GtkWidget *name_entry;      /* “姓名”输入框 */
    GtkWidget *sex_combo;       /* “性别”下拉菜单 */
    GtkWidget *age_entry;       /* “年龄”输入框 */
    GtkWidget *birthday_button; /* “生日”选择按钮 */
    GtkWidget *marriage_combo;  /* “婚姻”下拉菜单 */
    GtkWidget *edu_combo;       /* “教育”下拉菜单 */
    GtkWidget *id_entry;        /* “身份证”输入框 */
    GtkWidget *census_entry;    /* “户籍”输入框 */
    GtkWidget *happened_button;    /* “发生时间”按钮*/
    GtkWidget *place_combo;     /* “发生地点”下拉菜单 */
    GtkWidget *bill_entry;      /* “三联单”输入框 */
    GtkWidget *num_entry;       /* “住院号”输入框 */
    GtkWidget *into_button;     /* “入院时间”选择按钮 */
    GtkWidget *inps_entry;      /* “入院评分”输入框 */
    GtkWidget *out_button;      /* “出院时间”选择按钮 */
    GtkWidget *outps_entry;     /* “出院评分”输入框 */
    GtkWidget *days_entry;      /* “住院天数”输入框 */
    GtkWidget *persent_button;   /* 计算“减分率”按钮 */
    GtkWidget *cost_entry;      /* “花费”输入框 */
    GtkWidget *goto_combo;      /* “患者去向”选择框 */
    GtkWidget *level_combo;     /* “行为分级”下拉菜单 */
    GtkWidget *symptom_combo;   /* “患者症状”下拉菜单 */
    GtkWidget *status_combo;    /* “患者状态”下拉菜单 */
    GtkWidget *psy_combo;       /* “抗精神病药物”下拉菜单 */
    GtkWidget *dep_combo;       /* “抗抑郁药物”下拉菜单 */
    GtkWidget *anxiety_combo;   /* “抗焦虑药物”下拉菜单 */
    GtkWidget *heart_combo;     /* “心境稳定剂”下拉菜单 */
    GtkWidget *addicted_combo;  /* “物质依赖”下拉菜单 */
    GtkWidget *drug_combo;      /* “吸毒”输入框 */
    GtkWidget *body_entry;      /* “躯体疾病”输入框 */
    GtkWidget *infect_entry;    /* “传染病”输入框 */

    /* “历史记录”标签页内容 */
    GtkWidget *histroy_list;    /* “历史记录”树形图 */

    /* “确认出院”按钮 */
    GtkWidget *out_check;
} Item;

/* 从界面抓取到的字符串集合，
 * 可用于数据库的操作
 */
typedef struct _Pchar {
    char photo_path[100];
    char name[100];
    char sex[100];
    char birthday[100];
    char age[100];
    char marriage[100];
    char edu[100];
    char id[100];
    char census[100];
    char happened[100];
    char place[100];
    char bill[100];
    char num[100];
    char into_hospital[100];
    char inps[100];
    char out_hospital[100];
    char outps[100];
    char days[100];
    char panss[100];
    char cost[100];
    char go_to[100];
    char level[100];
    char symptom[100];
    char status[100];
    char psy[100];
    char dep[100];
    char anxiety[100];
    char heart[100];
    char addicted[100];
    char drug[100];
    /* 注意字符串长度 */
    char body[1000];
    char infect[1000];
    /* 搜索检测 */
    int find_id;
    int find_num;
} Pchar;

#endif
