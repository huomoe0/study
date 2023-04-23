try:
    num = int(input("输入整数："))
    result = 8 / num
    print(result)
except ValueError:
    print("请输入正确的整数")
    
except Exception as result:
    print(f"未知错误 {result}")

else:
    print("尝试成功")
finally:
    print("无论成功与否都会执行")
