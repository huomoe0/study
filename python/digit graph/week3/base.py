print('hello' * 3)

print("x=%d,y=%f" % (2, 3.0))

x = 3 + 2j
y = -1j
print(x * y)

strs = 'abcdefg'
print(strs[0:7:1])
print(strs[1:])
print(strs[:3])
print(strs[:-1])
print(strs[-3:-1])
print(strs[-3:])
print(strs[:])
print(strs[::2])
print(strs[::-1])


def minimal(x, y):
    if x > y:
        print('较小值为：', y)
    else:
        print('较小值为：', x)


a = float(input('输入第一个数据'))
b = float(input('输入第二个数据'))
minimal(a, b)
