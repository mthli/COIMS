/* 新建“在院病人”数据表；
 * 全部规定为TEXT数据类型，方便操作；
 * 暂时不做指纹识别和人脸识别了，做不了，
 * 所以不为指纹识别预留接口了
 */
CREATE TABLE IF NOT EXISTS
tb_hospital(
    /* 显然在“在线病人”列表中，住院号是主键 */
    num TEXT PRIMARY KEY NOT NULL,

    /* 基本资料部分 */
    photo_path TEXT,
    name TEXT,
    sex TEXT,
    birthday TEXT,
    age TEXT,
    marriage TEXT,
    edu TEXT,
    id TEXT,
    census TEXT,
    happened TEXT,
    place TEXT,
    bill TEXT,
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
SELECT num, name, id
FROM tb_hospital;

