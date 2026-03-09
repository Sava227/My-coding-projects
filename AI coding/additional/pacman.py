# ==============================================
# PAC-MAN (8-bit style) made with Python + Pygame
# Educational project inspired by classic Pac-Man
# ==============================================
# Install pygame first:
# pip install pygame

import pygame
import sys
import random

pygame.init()

# ------------------ CONSTANTS ------------------
TILE_SIZE = 24
COLS = 19
ROWS = 21
WIDTH = COLS * TILE_SIZE
HEIGHT = ROWS * TILE_SIZE + 50
FPS = 60

BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
PINK = (255, 105, 180)
CYAN = (0, 255, 255)
ORANGE = (255, 165, 0)
GREEN = (0, 255, 0)

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pac-Man 8-bit")
clock = pygame.time.Clock()
font = pygame.font.SysFont("arial", 20)

# ------------------ MAP ------------------
# 1 = wall, 0 = dot, 2 = empty, 3 = fruit
maze = [
    "1111111111111111111",
    "1000000000000000001",
    "1011110111110111101",
    "1000000000000000001",
    "1011110111110111101",
    "1000000000300000001",
    "1110111111111110111",
    "1000100000000010001",
    "1011101110111011101",
    "1000001000000010001",
    "1111111011111011111",
    "1000000000000000001",
    "1011110111110111101",
    "1000300000000003001",
    "1011110111110111101",
    "1000000000000000001",
    "1011110111110111101",
    "1000000000000000001",
    "1011110111110111101",
    "1000000000000000001",
    "1111111111111111111",
]

# ------------------ CLASSES ------------------
class Pacman:
    def __init__(self):
        self.x = 1 * TILE_SIZE
        self.y = 1 * TILE_SIZE
        self.speed = 3
        self.dx = 0
        self.dy = 0
        self.lives = 3

    def move(self):
        new_x = self.x + self.dx
        new_y = self.y + self.dy
        if not is_wall(new_x, new_y):
            self.x = new_x
            self.y = new_y

    def draw(self):
        pygame.draw.circle(screen, YELLOW,
                           (self.x + TILE_SIZE // 2, self.y + TILE_SIZE // 2),
                           TILE_SIZE // 2 - 2)


class Ghost:
    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color
        self.speed = 2
        self.direction = random.choice([(1,0),(-1,0),(0,1),(0,-1)])

    def move(self):
        dx, dy = self.direction
        new_x = self.x + dx * self.speed
        new_y = self.y + dy * self.speed
        if is_wall(new_x, new_y):
            self.direction = random.choice([(1,0),(-1,0),(0,1),(0,-1)])
        else:
            self.x = new_x
            self.y = new_y

    def draw(self):
        pygame.draw.rect(screen, self.color,
                         (self.x, self.y, TILE_SIZE, TILE_SIZE))


# ------------------ FUNCTIONS ------------------
def is_wall(x, y):
    col = int((x + TILE_SIZE // 2) / TILE_SIZE)
    row = int((y + TILE_SIZE // 2) / TILE_SIZE)
    return maze[row][col] == "1"


def draw_maze():
    for row in range(ROWS):
        for col in range(COLS):
            tile = maze[row][col]
            x = col * TILE_SIZE
            y = row * TILE_SIZE
            if tile == "1":
                pygame.draw.rect(screen, BLUE, (x, y, TILE_SIZE, TILE_SIZE))
            elif tile == "0":
                pygame.draw.circle(screen, WHITE,
                                   (x + TILE_SIZE // 2, y + TILE_SIZE // 2), 3)
            elif tile == "3":
                pygame.draw.circle(screen, GREEN,
                                   (x + TILE_SIZE // 2, y + TILE_SIZE // 2), 6)


def eat():
    global score
    col = int((pacman.x + TILE_SIZE // 2) / TILE_SIZE)
    row = int((pacman.y + TILE_SIZE // 2) / TILE_SIZE)
    if maze[row][col] == "0":
        maze[row] = maze[row][:col] + "2" + maze[row][col+1:]
        score += 10
    elif maze[row][col] == "3":
        maze[row] = maze[row][:col] + "2" + maze[row][col+1:]
        score += 100


def check_collision():
    for ghost in ghosts:
        if abs(pacman.x - ghost.x) < TILE_SIZE//2 and abs(pacman.y - ghost.y) < TILE_SIZE//2:
            pacman.lives -= 1
            pacman.x, pacman.y = TILE_SIZE, TILE_SIZE
            if pacman.lives <= 0:
                game_over()


def game_over():
    text = font.render("GAME OVER", True, RED)
    screen.blit(text, (WIDTH//2 - 60, HEIGHT//2))
    pygame.display.flip()
    pygame.time.delay(3000)
    pygame.quit()
    sys.exit()


# ------------------ GAME SETUP ------------------
pacman = Pacman()

ghosts = [
    Ghost(9 * TILE_SIZE, 10 * TILE_SIZE, RED),
    Ghost(10 * TILE_SIZE, 10 * TILE_SIZE, PINK),
    Ghost(8 * TILE_SIZE, 10 * TILE_SIZE, CYAN),
    Ghost(9 * TILE_SIZE, 9 * TILE_SIZE, ORANGE),
]

score = 0

# ------------------ MAIN LOOP ------------------
while True:
    clock.tick(FPS)
    screen.fill(BLACK)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                pacman.dx = -pacman.speed
                pacman.dy = 0
            if event.key == pygame.K_RIGHT:
                pacman.dx = pacman.speed
                pacman.dy = 0
            if event.key == pygame.K_UP:
                pacman.dy = -pacman.speed
                pacman.dx = 0
            if event.key == pygame.K_DOWN:
                pacman.dy = pacman.speed
                pacman.dx = 0

    pacman.move()
    eat()

    for ghost in ghosts:
        ghost.move()

    check_collision()

    draw_maze()
    pacman.draw()

    for ghost in ghosts:
        ghost.draw()

    # UI
    score_text = font.render(f"Score: {score}", True, WHITE)
    lives_text = font.render(f"Lives: {pacman.lives}", True, WHITE)
    screen.blit(score_text, (10, HEIGHT - 40))
    screen.blit(lives_text, (WIDTH - 120, HEIGHT - 40))

    pygame.display.flip()
