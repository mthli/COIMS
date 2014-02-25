#include "coims.h"

int search_hsp(Pchar *p);
int insert_hsp(Pchar *p);
int update_hsp(Pchar *p);

void check_sure(GtkWidget *widget, Item *parents)
{
    GtkWidget *message;
    const gchar *cnt;
    gchar *gtx;
    gboolean is_active;
    /* 注意一些数组的大小，
     * 全部把长度设置为100好了
     */
    FILE *fp;
    Pchar *p;
    int judge_id = 0;
    int judge_num = 0;
    int judge_temp = 0;
    int rc_search = 0;
    int rc_update = 0;
    int rc_sqlite = 0;
    int i = 0;

    p = (Pchar *)malloc(sizeof(Pchar));

    /* 照片路径 */
    fp = fopen("photo_path.txt", "r+");
    fgets((*p).photo_path, 101, fp);
    /* 姓名 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).name_entry)
            );
    strcpy((*p).name, cnt);
    /* 性别 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).sex_combo)
            );
    /* 这样的做法实在缺考虑，可能把Pchar结构体里面换成指针更好一些，
     * 不过用数组对数据库语句的操作比较方便吧
     */
    if (gtx == NULL) {
        strcpy((*p).sex, "\0");
    } else {
        strcpy((*p).sex, gtx);
    }
    /* 生日 */
    cnt = gtk_button_get_label(
            GTK_BUTTON((*parents).birthday_button)
            );
    strcpy((*p).birthday, cnt);
    /* 年龄 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).age_entry)
            );
    strcpy((*p).age, cnt);
    /* 婚姻状况 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).marriage_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).marriage, "\0");
    } else {
        strcpy((*p).marriage, gtx);
    }
    /* 文化程度 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).edu_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).edu, "\0");
    } else {
        strcpy((*p).edu, gtx);
    }
    /* 身份证，需要进行数据检测 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).id_entry)
            );
    strcpy((*p).id, cnt);
    /* 户籍证明 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).census_entry)
            );
    strcpy((*p).census, cnt);
    /* 事发时间 */
    cnt = gtk_button_get_label(
            GTK_BUTTON((*parents).happened_button)
            );
    strcpy((*p).happened, cnt);
    /* 事发地点 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).place_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).place, "\0");
    } else {
        strcpy((*p).place, gtx);
    }
    /* 三联单 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).bill_entry)
            );
    strcpy((*p).bill, cnt);
    /* 住院号，需要进行数据检测吗 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).num_entry)
            );
    strcpy((*p).num, cnt);
    /* 入院时间 */
    cnt = gtk_button_get_label(
            GTK_BUTTON((*parents).into_button)
            );
    strcpy((*p).into_hospital, cnt);
    /* 入院评分 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).inps_entry)
            );
    strcpy((*p).inps, cnt);
    /* 出院时间 */
    cnt = gtk_button_get_label(
            GTK_BUTTON((*parents).out_button)
            );
    strcpy((*p).out_hospital, cnt);
    /* 出院评分 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).outps_entry)
            );
    strcpy((*p).outps, cnt);
    /* 住院天数 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).days_entry)
            );
    strcpy((*p).days, cnt);
    /* 减分率 */
    cnt = gtk_button_get_label(
            GTK_BUTTON((*parents).persent_button)
            );
    strcpy((*p).panss, cnt);
    /* 住院花费 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).cost_entry)
            );
    strcpy((*p).cost, cnt);
    /* 患者去向 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).goto_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).go_to, "\0");
    } else {
        strcpy((*p).go_to, gtx);
    }
    /* 行为分级 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).level_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).level, "\0");
    } else {
        strcpy((*p).level, gtx);
    }
    /* 患者症状 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).symptom_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).symptom, "\0");
    } else {
        strcpy((*p).symptom, gtx);
    }
    /* 患者状态 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).status_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).status, "\0");
    } else {
        strcpy((*p).status, gtx);
    }
    /* 抗精神病药物 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).psy_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).psy, "\0");
    } else {
        strcpy((*p).psy, gtx);
    }
    /* 抗抑郁药物 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).dep_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).dep, "\0");
    } else {
        strcpy((*p).dep, gtx);
    }
    /* 抗焦虑药物 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).anxiety_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).anxiety, "\0");
    } else {
        strcpy((*p).anxiety, gtx);
    }
    /* 心境稳定剂 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).heart_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).heart, "\0");
    } else {
        strcpy((*p).heart, gtx);
    }
    /* 物质依赖 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).addicted_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).addicted, "\0");
    } else {
        strcpy((*p).addicted, gtx);
    }
    /* 是否吸毒 */
    gtx = gtk_combo_box_text_get_active_text(
            GTK_COMBO_BOX_TEXT((*parents).drug_combo)
    );
    if (gtx == NULL) {
        strcpy((*p).drug, "\0");
    } else {
        strcpy((*p).drug, gtx);
    }
    /* 躯体疾病，注意字符串长度 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).body_entry)
    );
    if (gtx == NULL) {
        strcpy((*p).body, "\0");
    } else {
        strcpy((*p).body, gtx);
    }
    /* 传染病，注意字符串长度 */
    cnt = gtk_entry_get_text(
            GTK_ENTRY((*parents).infect_entry)
    );
    if (gtx == NULL) {
        strcpy((*p).infect, "\0");
    } else {
        strcpy((*p).infect, gtx);
    }
    /* 释放gchar * */
    g_free(gtx);

    /* 需要对id和num进行基本的检查判断 */
    judge_id = 0;
    judge_num = 0;
    judge_temp = 0;
    /* 首先对id进行基本的判断检测 */
    if (strlen((*p).id) == 0) {
        judge_id = 1;
        message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "未填写身份证号码"
                );
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    } else if (strlen((*p).id) < 18) {
        judge_id = 1;
        message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "身份证位数未满18"
                );
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    } else if (strlen((*p).id) > 18) {
        judge_id = 1;
        message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "身份证位数超过18"
                );
        gtk_dialog_run(GTK_DIALOG(message));
        gtk_widget_destroy(message);
    } else {
        for (i = 0; i < strlen((*p).id); i++) {
            /* 其实在这里可以添加身份证号码的校检，不过暂时不做 */
            if (!(('0' <= (*p).id[i] && (*p).id[i] <= '9') || (*p).id[i] == 'X')) {
                judge_temp = 1;
                break;
            }
        }
        if (judge_temp == 1) {
            judge_id = 1;
            message = gtk_message_dialog_new(
                NULL,
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                "输入的身份证号码中含有非法字符串"
                );
            gtk_dialog_run(GTK_DIALOG(message));
            gtk_widget_destroy(message);
        } else {
            /* 再对num进行基本的检测 */
            if (strlen((*p).num) == 0) {
                judge_num = 1;
                message = gtk_message_dialog_new(
                        NULL,
                        GTK_DIALOG_MODAL,
                        GTK_MESSAGE_ERROR,
                        GTK_BUTTONS_CLOSE,
                        "未填写住院号"
                        );
                gtk_dialog_run(GTK_DIALOG(message));
                gtk_widget_destroy(message);
            }
        }
    }

    /* 如果id和num通过了基本的检测，
     * 则开始进行数据处理，
     * 点击了确定按钮后的逻辑
     * 一、如果out_check没有被选中
     *      1. 如果clist中没有选项被选中，且数据库中没有重复，则成功插入在院病人列表
     *      2. 如果clist中没有选项被选中，但数据库中有重复，则提示（报错/载入历史数据）
     *      3. 如果clist中有选项被选中，则直接更新在院病人列表
     *      4. 其他选项直接报错
     * 二、如果out_check被选中
     *      1. 如果clist中没有选项被选中，则提示报错
     *      2. 如果clist中有选项，则出院操作，归入历史数据库
     *      3. 其他选项直接报错
     * 关于out_check是否被选中，需要在new_person.c中进行具体设置一下
     */
    if (judge_id == 0 && judge_num == 0) {
        /* 获取out_check状态 */
        is_active = gtk_toggle_button_get_active(
                GTK_TOGGLE_BUTTON((*parents).out_check)
                );
        /*首先进行out_check没有被选中的处理 */
        if (is_active == FALSE) {
            /* 首先进行数据库的检索工作，对身份证和住院号进行检索，
             * 要对clist的row开始数值进行确定，到底是从0开始，还是1开始
             */
            rc_search = search_hsp(p);
            if ((*parents).get_row == -1 && rc_search == 0) {
                rc_sqlite = insert_hsp(p);
                if (rc_sqlite == SQLITE_OK) {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_INFO,
                            GTK_BUTTONS_OK,
                            "保存成功"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                } else {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "保存失败"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                }
            } else if ((*parents).get_row == -1 && rc_search != 0) {
                if (rc_search == 1) {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "住院号重复了，请重新输入"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                } else if (rc_search == 2) {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "身份证号码重复，请重新输入"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                } else {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "住院号和身份证号码均重复，请重新输入"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                }
            } else if ((*parents).get_row != -1 && rc_search == 0) {
                /* 开始更新数据 */
                rc_update = update_hsp(p);
                if (rc_update == SQLITE_OK) {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_INFO,
                            GTK_BUTTONS_OK,
                            "保存成功"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                } else {
                    message = gtk_message_dialog_new(
                            NULL,
                            GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_CLOSE,
                            "保存失败"
                            );
                    gtk_dialog_run(GTK_DIALOG(message));
                    gtk_widget_destroy(message);
                }
            } else {
                message = gtk_message_dialog_new(
                        NULL,
                        GTK_DIALOG_MODAL,
                        GTK_MESSAGE_ERROR,
                        GTK_BUTTONS_CLOSE,
                        "未知错误，请仔细填写数据"
                        );
                gtk_dialog_run(GTK_DIALOG(message));
                gtk_widget_destroy(message);
            }
        } else {
            /* 这里就是出院操作了，暂时不做 */
        }
    }
}
