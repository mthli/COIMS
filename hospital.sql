/* 新建“在院病人”数据表；
 * 全部规定为TEXT数据类型，方便操作；
 * 暂时不做指纹识别和人脸识别了，做不了，
 * 所以不为指纹识别预留接口了
 */
CREATE TABLE IF NOT EXISTS
tb_hospital(
    /* 基本资料部分 */
    id TEXT PRIMARY KEY,
    photo_path TEXT,
    name TEXT,
    sex TEXT,
    birthday TEXT,
    age TEXT,
    marriage TEXT,
    edu TEXT,
    census TEXT,
    happened TEXT,
    place TEXT,
    bill TEXT,
    num TEXT,
    into_hospital TEXT,
    inps TEXT,
    out_hospital TEXT,
    outps TEXT,
    days TEXT,
    panss TEXT,
    cost TEXT,
    goto TEXT,

    /* 诊断治疗部分 */
    do_level TEXT,
    symptom TEXT,
    status TEXT,
    psy TEXT,
    dep TEXT,
    anxiety TEXT,
    heart TEXT,

    /* 补充信息部分 */
    addicted TEXT,
    drug TEXT,
    body TEXT,
    infect TEXT
);

/* 新建“在院病人”视图，方便搜索和显示 */
CREATE VIEW ve_hospital AS
SELECT
id,
num,
name
FROM tb_hospital;

