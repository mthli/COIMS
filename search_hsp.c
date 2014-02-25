#include "coims.h"

int callback_id(void *parents, int argc, char **argv, char **headers)
{
    Pchar *p;
    int i = 0;

    /* 注意类型转换 */
    p = (Pchar *)parents;
    /* 开始进行身份证和住院号的检测 */
    for (i = 0; i < argc; i++) {
        /* 是否需要NOT NULL？ */
        if (strcmp((*p).id, argv[i]) == 0) {
            /* 采用自加方式统计重复次数，
             * 不过这样好像没什么必要，
             * 但是还是这样做吧，说不定以后有用
             */
            (*p).find_id++;
        }
    }

    return 0;
}

int callback_num(void *parents, int argc, char **argv, char **headers)
{
    Pchar *p;
    int i = 0;

    /* 注意类型转换 */
    p = (Pchar *)parents;
    /* 开始进行身份证和住院号的检测 */
    for (i = 0; i < argc; i++) {
        /* 是否需要NOT NULL？ */
        if (strcmp((*p).num, argv[i]) == 0) {
            /* 采用自加方式统计重复次数，
             * 不过这样好像没什么必要，
             * 但是还是这样做吧，说不定以后有用
             */
            (*p).find_num++;
        }
    }

    return 0;
}

int search_hsp(Pchar *p)
{
    sqlite3 *db;
    char query_id[100] = {0};
    char query_num[100] = {0};
    /* 这里rc有多种用途，
     * 但是写出来的语句不一定被用到，
     * 所以有些调用sqlite3_*语句的地方就不提取返回值了
     */
    int rc = 0;

    /* 注意及时关闭数据库 */
    sqlite3_open("hospital.db", &db);

    /* 开始组装SELECT语句 */
    strcat(query_id, "SELECT id FROM ve_hospital;");
    strcat(query_num, "SELECT num FROM ve_hospital;");

    (*p).find_id = 0;
    (*p).find_num = 0;
    /* 回调函数的应用 */
    sqlite3_exec(db, query_id, callback_id, p, NULL);
    sqlite3_exec(db, query_num, callback_num, p, NULL);
    /* 确定返回值 */
    if ((*p).find_id == 0 && (*p).find_num == 0) {
        rc = 0;
    } else if ((*p).find_id == 0 && (*p).find_num != 0) {
        rc = 1;
    } else if ((*p).find_id != 0 && (*p).find_num == 0) {
        rc = 2;
    } else {
        rc = 3;
    }

    sqlite3_close(db);

    return rc;
}

