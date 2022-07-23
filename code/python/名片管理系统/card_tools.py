card_list = []


def show_menu():
    print("*" * 50)
    print("欢迎使用【名片管理系统】V 1.0")
    print("")
    print("1. 新建名片")
    print("2. 显示全部")
    print("3. 查询名片")
    print("")
    print("0. 退出系统")
    print("*" * 50)


def new_card():
    print("-" * 50)
    name_str = input("请输入姓名: ")
    phone_str = input("请输入电话: ")
    qq_str = input("请输入qq: ")
    email_str = input("请输入邮箱: ")
    card_dict = {"name": name_str, "phone": phone_str, "qq": qq_str, "email": email_str}
    card_list.append(card_dict)
    print(card_list)
    print("添加 %s 的名片成功" % name_str)


def show_all():
    print("-" * 50)
    if len(card_list) == 0:
        print("当前名片为空")
        return

    for k in ["姓名", "电话", "qq", "邮箱"]:
        print(k, end="\t\t")
    print("")
    print("=" * 50)
    for card_dict in card_list:
        print("%s\t\t%s\t\t%s\t\t%s" % (card_dict["name"], card_dict["phone"], card_dict["qq"], card_dict["email"]))


def search_card():
    print("-" * 50)
    find_name = input("请输入要查找的姓名: ")
    for card_dict in card_list:
        if card_dict["name"] == find_name:
            print("姓名\t\t电话\t\tqq\t\t邮箱")
            print("=" * 50)
            print("%s\t\t%s\t\t%s\t\t%s" % (card_dict["name"], card_dict["phone"], card_dict["qq"], card_dict["email"]))
            deal_card(card_dict)
            break
    else:
        print("未找到 %s" % find_name)


def deal_card(card_dict):
    action_str = input("请选择需要执行的操作[1] 修改 [2] 删除 [0] 返回上级菜单")
    if action_str == "1":
        card_dict["name"] = input_card_info(card_dict["name"], "姓名: ")
        card_dict["phone"] = input_card_info(card_dict["phone"], "电话: ")
        card_dict["qq"] = input_card_info(card_dict["qq"], "qq: ")
        card_dict["email"] = input_card_info(card_dict["email"], "邮箱: ")
        print("修改成功")
    elif action_str == "2":
        card_list.remove(card_dict)


def input_card_info(dict_value, tip_message):
    result_str = input(tip_message)
    if len(result_str) > 0:
        return result_str
    else:
        return dict_value
