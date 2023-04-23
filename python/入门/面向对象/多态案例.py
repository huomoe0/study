class Dog(object):
    def __init__(self,name) -> None:
        self.name = name
    def game(self):
        print("{} 蹦蹦跳跳玩耍" .format(self.name))

class XiaoTianDog(Dog):
    def game(self):
        print(f"{self.name} 飞天")

class Person(object):
    def __init__(self,name) -> None:
        self.name = name
    def game_with_dog(self,dog):
        print(f"{self.name} 和 {dog.name} 快乐玩耍")
        dog.game()

xiaoming = Person("小明")
wangcai = XiaoTianDog("飞天旺财")
xiaoming.game_with_dog(wangcai)