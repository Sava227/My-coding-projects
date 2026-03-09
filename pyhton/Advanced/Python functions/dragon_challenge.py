import random
import time

treasures = 0
loses = 0

def intro():
    print("You are on the dragon land")
    print("You see 2 caves in front of you")
    print("In one cave there is a friendly dragon who ill share his treasure with you")
    print("In the other cave there is a hungry dragon who will eat you on sight")
    print()

def choose_cave():
    cave = 0
    while cave != 1 and cave != 2:
        cave = int(input("Which cave are you choosing? Cave number 1 or number 2?"))
    return cave

def check_cave(chosen_cave):
    print("You approach the cave...")
    time.sleep(2)
    print("The cave is really dark...")
    time.sleep(2)
    print("A large dragon jumps out in front of you! He opens his jaws and...")
    print()
    time.sleep(2)

    friendly_cave = random.randint(1, 2)

    if chosen_cave == friendly_cave:
        print("Gives you his treasure!")
        global treasures
        treasures += 1
    else:
        print("Gobbles you down in one bite!")
        global loses
        loses += 1

play_again = "yes"
while play_again.lower() == "yes":
    intro()
    cave_number = choose_cave()
    check_cave(cave_number)
    play_again = input("Do you want to play again? (yes or no)")

print()
print("The game is over")
print("You found treasures: ", treasures)
print("You got eaten: ", loses)