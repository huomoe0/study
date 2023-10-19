import pymysql

db = pymysql.connect(host="localhost", user="root", password="huomoe0", database="db1", charset='utf8')

cursor = db.cursor()
cursor.execute("SELECT VERSION()")

# cursor.execute("DROP TABLE IF EXISTS books")

data = cursor.fetchone()
print(data)

db.close()
