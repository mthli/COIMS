#include "coims.h"

int insert_hsp(Pchar *p)
{
    sqlite3 *db;
    char query[10000] = {0};
    int rc = 0;

    /* 注意及时关闭数据库 */
    sqlite3_open("hospital.db", &db);

    /* 开始组装插入语句，
     * 显然用sprintf()面临字符串中的空格问题，
     * 所以用strcat()
     */
    strcat(query, "INSERT INTO tb_hospital VALUES(");
    /* 身份证 */
    strcat(query, "'");
    strcat(query, (*p).id);
    strcat(query, "',");
    /* 余下都按照这种格式 */
    strcat(query, "'");
    strcat(query, (*p).photo_path);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).name);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).sex);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).birthday);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).age);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).marriage);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).edu);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).census);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).happened);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).place);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).bill);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).num);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).into_hospital);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).inps);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).out_hospital);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).outps);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).days);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).panss);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).cost);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).go_to);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).level);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).symptom);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).status);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).psy);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).dep);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).anxiety);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).heart);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).addicted);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).drug);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).body);
    strcat(query, "',");
    strcat(query, "'");
    strcat(query, (*p).infect);
    strcat(query, "');");

    /* 开始执行语句 */
    rc = sqlite3_exec(db, query, NULL, NULL, NULL);

    /* 关闭数据库 */
    sqlite3_close(db);

    return rc;
};
