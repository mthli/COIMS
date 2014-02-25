/* 新建“在院病人”数据表；
 * 全部规定为TEXT数据类型，方便操作；
 * 暂时不做指纹识别和人脸识别了，做不了，
 * 所以不为指纹识别预留接口了
 */
CREATE TABLE IF NOT EXISTS
tb_hospital(
    /* 基本资料部分 */
    id TEXT PRIMARY KEY DEFAULT '\0',
    photo_path TEXT DEFAULT '\0',
    name TEXT DEFAULT '\0',
    sex TEXT DEFAULT '\0',
    birthday TEXT DEFAULT '\0',
    age TEXT DEFAULT '\0',
    marriage TEXT DEFAULT '\0',
    edu TEXT DEFAULT '\0',
    census TEXT DEFAULT '\0',
    happened TEXT DEFAULT '\0',
    place TEXT DEFAULT '\0',
    bill TEXT DEFAULT '\0',
    num TEXT DEFAULT '\0',
    into_hospital TEXT DEFAULT '\0',
    inps TEXT DEFAULT '\0',
    out_hospital TEXT DEFAULT '\0',
    outps TEXT DEFAULT '\0',
    days TEXT DEFAULT '\0',
    panss TEXT DEFAULT '\0',
    cost TEXT DEFAULT '\0',
    goto TEXT DEFAULT '\0',

    /* 诊断治疗部分 */
    do_level TEXT DEFAULT '\0',
    symptom TEXT DEFAULT '\0',
    status TEXT DEFAULT '\0',
    psy TEXT DEFAULT '\0',
    dep TEXT DEFAULT '\0',
    anxiety TEXT DEFAULT '\0',
    heart TEXT DEFAULT '\0',

    /* 补充信息部分 */
    addicted TEXT DEFAULT '\0',
    drug TEXT DEFAULT '\0',
    body TEXT DEFAULT '\0',
    infect TEXT DEFAULT '\0'
);

/* 新建“在院病人”视图，方便搜索和显示 */
CREATE VIEW ve_hospital AS
SELECT
id,
num,
name
FROM tb_hospital;

