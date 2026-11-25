-- ============================================================
-- 实验3  医院诊疗系统 SQLite 数据库脚本
-- 与 Navicat 模型 lab4a.nmodel 的 5 张表一致
-- 说明：SQLite 忽略 TEXT(n) 中的 n，此处保留仅为与模型展示一致
-- 可重复执行：使用 CREATE TABLE IF NOT EXISTS / INSERT OR IGNORE
-- ============================================================

PRAGMA foreign_keys = ON;

-- 科室表
CREATE TABLE IF NOT EXISTS "Department" (
    "ID"   TEXT NOT NULL,
    "NAME" TEXT(50) NOT NULL,
    CONSTRAINT "pk_Department" PRIMARY KEY ("ID")
);

-- 医生表
CREATE TABLE IF NOT EXISTS "Doctor" (
    "ID"            TEXT NOT NULL,
    "NAME"          TEXT(50) NOT NULL,
    "DEPARTMENT_ID" TEXT,
    "EMPLOYEENO"    TEXT(32),
    CONSTRAINT "pk_Doctor" PRIMARY KEY ("ID"),
    CONSTRAINT "fk_Doctor_Department_1"
        FOREIGN KEY ("DEPARTMENT_ID") REFERENCES "Department" ("ID")
);

-- 用户表
CREATE TABLE IF NOT EXISTS "User" (
    "ID"       TEXT NOT NULL,
    "FULLNAME" TEXT(50),
    "USERNAME" TEXT(32) NOT NULL,
    "PASSWORD" TEXT(64) NOT NULL,
    CONSTRAINT "pk_User" PRIMARY KEY ("ID"),
    CONSTRAINT "uq_User_USERNAME" UNIQUE ("USERNAME")
);

-- 患者表
CREATE TABLE IF NOT EXISTS "Patient" (
    "ID"               TEXT(32) NOT NULL,
    "ID_CARD"          TEXT(20) NOT NULL,
    "NAME"             TEXT(50) NOT NULL,
    "SEX"              INTEGER NOT NULL DEFAULT 1,   -- 1=男 0=女
    "DOB"              TEXT(10),                     -- yyyy-MM-dd
    "HEIGHT"           REAL,
    "WEIGHT"           REAL,
    "MOBILEPHONE"      TEXT(20),
    "AGE"              INTEGER,
    "CREATEDTIMESTAMP" TEXT DEFAULT (datetime('now','localtime')),
    CONSTRAINT "pk_Patient" PRIMARY KEY ("ID")
);

-- 操作记录表
CREATE TABLE IF NOT EXISTS "History" (
    "ID"        TEXT NOT NULL,
    "USER_ID"   TEXT,
    "EVENT"     TEXT(255),
    "TIMESTAMP" TEXT DEFAULT (datetime('now','localtime')),
    CONSTRAINT "pk_History" PRIMARY KEY ("ID"),
    CONSTRAINT "fk_History_User_1"
        FOREIGN KEY ("USER_ID") REFERENCES "User" ("ID")
);

-- ============================================================
-- 初始化数据
-- ============================================================
INSERT OR IGNORE INTO "Department" ("ID", "NAME") VALUES
    ('D01', '内科'),
    ('D02', '外科'),
    ('D03', '儿科');

INSERT OR IGNORE INTO "Doctor" ("ID", "NAME", "DEPARTMENT_ID", "EMPLOYEENO") VALUES
    ('DOC01', '张医生', 'D01', 'E1001'),
    ('DOC02', '李医生', 'D02', 'E1002');

INSERT OR IGNORE INTO "User" ("ID", "FULLNAME", "USERNAME", "PASSWORD") VALUES
    ('U001', '系统管理员', 'admin', '123456');

INSERT OR IGNORE INTO "Patient"
    ("ID", "ID_CARD", "NAME", "SEX", "DOB", "HEIGHT", "WEIGHT", "MOBILEPHONE", "AGE") VALUES
    ('P001', '441900199001011234', '张三', 1, '1990-01-01', 172.5, 65.0, '13800000001', 35),
    ('P002', '441900199202022345', '李四', 0, '1992-02-02', 160.0, 50.5, '13800000002', 33),
    ('P003', '441900198503033456', '王五', 1, '1985-03-03', 178.0, 75.0, '13800000003', 40);
