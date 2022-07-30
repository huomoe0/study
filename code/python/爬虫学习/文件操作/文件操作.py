# 打开文件方法一，需要手动关闭文件
f = open("text.txt", "r", encoding="utf-8")
f.close()

# 打开文件方法二，自动关闭文件
with open("text.txt", "r", encoding="utf-8") as f:
    # 返回一个列表，文件中每行为列表的一个元素
    a = f.readlines()
    # 读取一行
    c = f.readline()
    # 把文件全部内容以一个字符串返回
    b = f.read()
    print(a)
    print(c)
    print(b)

with open("text.txt", "a", encoding="utf-8") as f:
    # 将字符串写入文本
    f.write("123")
    # 把列表中所有字符串写入文本中
    f.writelines(['456\n', '789\n'])
