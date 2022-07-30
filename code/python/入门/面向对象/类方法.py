class Tool(object):
    count = 0
    @classmethod
    def show_tool_count(cls):
        print(f"工具对象数量 {cls.count}")
    
    def __init__(self,name) -> None:
        self.name = name
        Tool.count += 1

tool1 = Tool("斧头")

Tool.show_tool_count()