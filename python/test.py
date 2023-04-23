import pandas

df = pandas.DataFrame(pandas.read_excel('D:\\Downloads\\1.xlsx'))
print(df.values)
print(type(df.values))

count = 0
for i in df.values:
    if '沐浴龙血的剑' in i:
        count += 1

print(count)

