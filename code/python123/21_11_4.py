# num = "零一二三四五六七八九"
# n = input()
# for c in n:
#     print(num[eval(c)],end="")

# t = input()
# if t[0] in ['C']:
#     f = eval(t[1:]) * 1.8 + 32
#     print("F{:.2f}".format(f))
# elif t[0] in ['F']:
#     c = (eval(t[1:]) - 32) / 1.8
#     print("C{:.2f}".format(c))

money = input()
if money[:3] == "RMB":
    USD = eval(money[3:]) / 6.78
    print("USD{:.2f}".format(USD))
elif money[:3] == "USD":
    RMB = eval(money[3:]) * 6.78
    print("RMB{:.2f}".format(RMB))