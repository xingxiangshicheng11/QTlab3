# -*- coding: utf-8 -*-
"""生成实验3的 SQLite 数据库（lab3/hospital.db）。

用法:
    python init_db.py

脚本读取同目录的 schema.sql 并执行，可重复运行（CREATE TABLE IF NOT EXISTS
/ INSERT OR IGNORE），不会破坏已有数据。
"""

import os
import sqlite3
import sys

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DB_PATH = os.path.abspath(os.path.join(BASE_DIR, "..", "hospital.db"))
SQL_PATH = os.path.join(BASE_DIR, "schema.sql")


def main():
    if not os.path.exists(SQL_PATH):
        print("[错误] 找不到 schema.sql:", SQL_PATH)
        return 1

    with open(SQL_PATH, "r", encoding="utf-8") as f:
        script = f.read()

    conn = sqlite3.connect(DB_PATH)
    try:
        conn.execute("PRAGMA foreign_keys = ON")
        conn.executescript(script)
        conn.commit()
    except sqlite3.Error as exc:
        print("[错误] 初始化数据库失败:", exc)
        conn.close()
        return 1

    cur = conn.cursor()
    tables = [r[0] for r in cur.execute(
        "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name")]
    print("数据库文件:", DB_PATH)
    print("已创建表 (%d):" % len(tables), ", ".join(tables))
    for t in ("User", "Patient", "Department", "Doctor", "History"):
        if t in tables:
            n = cur.execute('SELECT COUNT(*) FROM "%s"' % t).fetchone()[0]
            print("  %-11s %d 条" % (t, n))
    conn.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
