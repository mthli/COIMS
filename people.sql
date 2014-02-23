/* 创建“人物”数据表，
 * 全部规定为TEXT数据类型，方便操作；
 * 暂时不做指纹识别和人脸识别了，做不了，
 * 所以不为指纹识别预留接口了
 */
CREATE TABLE IF NOT EXISTS
tb_people(
    id TEXT PRIMARY KEY,
    name TEXT
);

