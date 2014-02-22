#include "coims.h"

void cancel(GtkWidget *widget, Item *parents)
{
    /* “取消”按钮与“新建”按钮的逻辑不同，只是暂时这样做罢了：
     * 1. 如果是“新建”且未保存，则“取消”按钮与新建按钮功能相同，都是清空当前界面内容
     * 2. 如果是查看在院/历史病人的信息，那么“取消”按钮相当于把修改过但未保存的内容重置
     */

    /* 移除照片 */
    gtk_button_set_image(
            GTK_BUTTON((*parents).photo_button),
            NULL
            );
    remove("photo_path.txt");
    gtk_widget_show((*parents).photo_button);
    /* 移除姓名 */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).name_entry),
            ""
            );
    gtk_widget_show((*parents).name_entry);
    /* 设置“性别”下拉菜单为空 */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).sex_combo),
            -1
            );
    gtk_widget_show((*parents).sex_combo);
    /* “生日”按钮 */
    gtk_button_set_label(
            GTK_BUTTON((*parents).birthday_button),
            "选择日期"
            );
    gtk_widget_show((*parents).birthday_button);
    /* “年龄”输入框 */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).age_entry),
            ""
            );
    gtk_widget_show((*parents).age_entry);
    /* “婚姻” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).marriage_combo),
            -1
            );
    gtk_widget_show((*parents).marriage_combo);
    /* “教育” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).edu_combo),
            -1
            );
    gtk_widget_show((*parents).edu_combo);
    /* “身份证” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).id_entry),
            ""
            );
    gtk_widget_show((*parents).id_entry);
    /* “户籍” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).census_entry),
            ""
            );
    gtk_widget_show((*parents).census_entry);
    /* “发生时间” */
    gtk_button_set_label(
            GTK_BUTTON((*parents).happened_button),
            "选择日期"
            );
    gtk_widget_show((*parents).happened_button);
    /* “发生地点” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).place_combo),
            -1
            );
    gtk_widget_show((*parents).place_combo);
    /* “三联单” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).bill_entry),
            ""
            );
    gtk_widget_show((*parents).bill_entry);
    /* “住院号” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).num_enrty),
            ""
            );
    gtk_widget_show((*parents).num_enrty);
    /* “入院时间” */
    gtk_button_set_label(
            GTK_BUTTON((*parents).into_button),
            "选择日期"
            );
    gtk_widget_show((*parents).into_button);
    /* “入院评分” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).inps_entry),
            ""
            );
    gtk_widget_show((*parents).inps_entry);
    /* “出院时间” */
    gtk_button_set_label(
            GTK_BUTTON((*parents).out_button),
            "选择日期"
            );
    gtk_widget_show((*parents).out_button);
    /* “出院评分” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).outps_entry),
            ""
            );
    gtk_widget_show((*parents).outps_entry);
    /* “住院天数” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).days_enrty),
            ""
            );
    gtk_widget_show((*parents).days_enrty);
    /* “减分率” */
    gtk_button_set_label(
            GTK_BUTTON((*parents).persent_button),
            "计算"
            );
    gtk_widget_show((*parents).persent_button);
    /* “花费” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).cost_entry),
            ""
            );
    gtk_widget_show((*parents).cost_entry);
    /* “患者去向” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).goto_combo),
            -1
            );
    gtk_widget_show((*parents).goto_combo);
    /* “行为分级” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).level_combo),
            -1
            );
    gtk_widget_show((*parents).level_combo);
    /* “患者症状” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).symptom_combo),
            -1
            );
    gtk_widget_show((*parents).symptom_combo);
    /* “患者状态” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).status_combo),
            -1
            );
    gtk_widget_show((*parents).status_combo);
    /* “抗精神病药物” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).psy_combo),
            -1
            );
    gtk_widget_show((*parents).psy_combo);
    /* “抗抑郁药物” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).dep_combo),
            -1
            );
    gtk_widget_show((*parents).dep_combo);
    /* “抗焦虑药物” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).anxiety_combo),
            -1
            );
    gtk_widget_show((*parents).anxiety_combo);
    /* “心境稳定剂” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).heart_combo),
            -1
            );
    gtk_widget_show((*parents).heart_combo);
    /* “物质依赖” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).addicted_combo),
            -1
            );
    gtk_widget_show((*parents).addicted_combo);
    /* “是否吸毒” */
    gtk_combo_box_set_active(
            GTK_COMBO_BOX((*parents).drug_combo),
            -1
            );
    gtk_widget_show((*parents).drug_combo);
    /* “躯体疾病” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).body_entry),
            ""
            );
    gtk_widget_show((*parents).body_entry);
    /* “传染病” */
    gtk_entry_set_text(
            GTK_ENTRY((*parents).infect_entry),
            ""
            );
    gtk_widget_show((*parents).infect_entry);
    /* “确认出院” */
    gtk_toggle_button_set_active(
            GTK_TOGGLE_BUTTON((*parents).out_check),
            FALSE
            );

    /* 其余部分暂时不做 */
}
