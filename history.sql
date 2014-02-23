/* 创建“病人历史”数据表，
 * 全部规定为TEXT数据类型，方便操作；
 * 不制作人脸识别模块和指纹识别模块，这个做不了，
 * 所以这里也没有为这两个模块提供接口，
 * 所以以后可能需要代码重构，
 * 不过暂时还是决定这样做
 */
CREATE TABLE IF NOT EXISTS
tb_history(
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

/* 新建“基本信息”视图 */
CREATE VIEW ve_person AS
SELECT
id,
photo_path,
name,
sex,
birthday,
age,
census
FROM tb_history;

/* 新建“住院历史”试图 */
CREATE VIEW ve_history AS
SELECT
id,
into_hospital,
out_hospital,
inps,
outps,
panss,
do_level,
symptom,
status,
psy,
dep,
anxiety,
heart,
addicted,
drug,
body,
infect
FROM tb_history;
