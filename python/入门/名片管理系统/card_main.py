import card_tools

while True:
    card_tools.show_menu()
    choice = input("请选择: ")
    if choice in ["1", "2", "3"]:
        if choice == "1":
            card_tools.new_card()
        elif choice == "2":
            card_tools.show_all()
        elif choice == "3":
            card_tools.search_card()
    elif choice == "0":
        print("欢迎下次使用")
        break
