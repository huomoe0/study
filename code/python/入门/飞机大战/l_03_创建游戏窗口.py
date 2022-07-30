import pygame
from plane_sprites import GameSprite

pygame.init()

screen = pygame.display.set_mode((480, 700), )
bg = pygame.image.load("./images/background.png")
screen.blit(bg, (0, 0))

hero_rect = pygame.Rect(150, 300, 102, 126)
hero = pygame.image.load("./images/me1.png")
screen.blit(hero, hero_rect)

pygame.display.update()

clock = pygame.time.Clock()

enemy = GameSprite("./images/enemy1.png")
enemy1 = GameSprite("./images/enemy1.png", 2)
enemy_group = pygame.sprite.Group(enemy, enemy1)

while True:
    clock.tick(60)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

    hero_rect.y -= 5
    if hero_rect.y <= -126:
        hero_rect.y = 700

    screen.blit(bg, (0, 0))
    screen.blit(hero, hero_rect)

    enemy_group.update()
    enemy_group.draw(screen)
    pygame.display.update()
