class Person:
    def __init__(self,name,weight) -> None:
        self.name = name
        self.weight = weight
    def __str__(self) -> str:
        return "我的名字是 %s 体重是 %.2f 公斤" % (self.name,self.weight)
    def run(self) -> None:
        print("%s 跑步" % self.name)
        self.weight -= 0.5
    def eat(self) -> None:
        print("%s 吃东西" % self.name)
        self.weight += 1
xiaoming = Person("小明", 65)
xiaoming.run()
xiaoming.eat()
print(xiaoming)