import os
import time
import random
import msvcrt

# Move cursor
def gotoxy(x, y):
    print(f"\033[{y};{x}H", end="")

# Clear screen
def clear_screen():
    os.system("cls")

# Game variables
candyX = 40
candyY = 1
boxX = 40
boxY = 14
score = 0
lifeline = 5

while True:
    clear_screen()

    gotoxy(60, 5)
    print(f"Score = {score}")

    gotoxy(60, 6)
    print(f"Lifeline = {lifeline}")

    # Candy
    gotoxy(candyX, candyY)
    print("O")

    # Box
    gotoxy(boxX, boxY)
    print("#")
    gotoxy(boxX + 7, boxY)
    print("#")
    gotoxy(boxX, boxY + 1)
    print("########")

    # Keyboard input
    if msvcrt.kbhit():
        ch = msvcrt.getch().decode().lower()

        if ch == 'a':
            if boxX > 1:
                boxX -= 1

        elif ch == 'd':
            if boxX < 70:
                boxX += 1

        elif ch == 'x':
            break

    candyY += 1

    # Collision check
    if candyY == boxY:
        d = candyX - boxX

        if 1 <= d <= 6:
            score += 1
            print("\a")   # Beep sound
        else:
            lifeline -= 1

            if lifeline == 0:
                clear_screen()
                gotoxy(35, 12)
                print("GAME OVER!")
                time.sleep(2)
                break

        candyX = random.randint(1, 70)
        candyY = 1

    time.sleep(0.15)

print("\nThanks for playing!")
