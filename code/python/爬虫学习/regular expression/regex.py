import re
text = """
{ url: "./202108/t20210810_1259734.html", title: '峄城区卫生健康局2021年7月卫生监督行政处罚案件', time: "2021-08-05", source:'', }
{ url: "./202107/t20210721_1249763.html", title: '峄城区市场监管局关于对枣庄越强网络科技有限公司等240家企业', time: "2021-07-22"}
{ url: "./202107/t20210721_1291713.html", title: '行政处罚...', time: "2021-07-22", source:'', }
"""
a = re.findall("title: '(.*?)', time: \"(.*?)\"", text, re.S)
print(a)
print(a[0])
print(a[1])

# a = re.search("title: '(.*?)', time: \"(.*?)\"",text,re.S)
# print(a)
# print(a.group(1))
