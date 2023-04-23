class Game(object):
    top_score = 0

    def __init__(self,player_name) -> None:
        self.player_name = player_name
    
    @staticmethod
    def show_help():
        print("让僵尸进入大门")

    @classmethod
    def show_top_score(cls):
        print("历史记录 %d" % cls.top_score)
    
    def start_game(self):
        print("%s 开始游戏了。。" % self.player_name)

Game.show_help()
Game.show_top_score()
game = Game("小明")
game.start_game()
