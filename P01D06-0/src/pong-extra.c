#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define COL 80
#define ROW 25

void initScreen();
void drawGame(int p1y, int p2y, int bx, int by, int score1, int score2);
int checkGoal(int bx);
int checkWin(int score1, int score2);
int setStartBallPos();
int setRandomDir();
int platformReflection(int x1, int x2, int xb, int yb);
int wallReflection(int by);

int main() {
    initScreen();
    // variables
    int p1y = ROW / 2;
    int p2y = ROW / 2;
    int bx = COL / 2;
    int by = setStartBallPos();
    int score1 = 0;
    int score2 = 0;
    int game = 1;
    int vx = setRandomDir();
    int vy = setRandomDir();
    // game loop
    while (game) {
        drawGame(p1y, p2y, bx, by, score1, score2);
        bx += vx;
        by += vy;
        // input
        switch (getch()) {
            case 'a':
                if (p1y > 1) {
                    --p1y;
                }
                break;
            case 'z':
                if (p1y < ROW - 2) {
                    ++p1y;
                }
                break;
            case 'k':
                if (p2y > 1) {
                    --p2y;
                }
                break;
            case 'm':
                if (p2y < ROW - 2) {
                    ++p2y;
                }
                break;
            default:
                break;
        }
        // reflections
        int tmp = platformReflection(p1y, p2y, bx, by);
        if (tmp) vx = tmp;
        tmp = wallReflection(by);
        if (tmp) vy = tmp;
        // checks
        if (checkGoal(bx) == 1) {
            ++score1;
            bx = COL / 2;
            by = setStartBallPos();
            vx = setRandomDir();
            vy = setRandomDir();
        }
        if (checkGoal(bx) == 2) {
            ++score2;
            bx = COL / 2;
            by = setStartBallPos();
            vx = setRandomDir();
            vy = setRandomDir();
        }
        game = checkWin(score1, score2);
        // delay
        napms(150);
    }
    endwin();
    return 0;
}

// Screen setup
void initScreen() {
    srand(time(NULL));
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

// Draw field
void drawGame(int p1y, int p2y, int bx, int by, int score1, int score2) {
    clear();
    for (int i = 0; i <= ROW + 1; i++) {
        for (int j = 0; j <= COL + 1; j++) {
            if (i == 0 || i == ROW + 1) {
                printw("#");
                if (j == COL + 1) {
                    printw("\n");
                }
                continue;
            }
            if ((j == 0 || j == COL + 1 || j == COL / 2) && i != ROW + 1) {
                printw("|");
                if (j == COL + 1) {
                    printw("\n");
                }
                continue;
            }
            if (j == 1 && (i == p1y || i == p1y + 1 || i == p1y + 2)) {
                printw("]");
                continue;
            }
            if (j == COL && (i == p2y || i == p2y + 1 || i == p2y + 2)) {
                printw("[");
                continue;
            }
            if (i == by && j == bx) {
                printw("o");
                continue;
            }
            printw(" ");
        }
    }
    printw("Score: %d - %d\n", score1, score2);
    refresh();
}

// Winner
int checkWin(int score1, int score2) {
    if (score1 == 21) {
        endwin();
        printf("Player1 won!\n");
        return 0;
    }
    if (score2 == 21) {
        endwin();
        printf("Player2 won!\n");
        return 0;
    } else {
        return 1;
    }
}

// Check goal
int checkGoal(int bx) {
    if (bx == COL) {
        return 1;
    }
    if (bx == 1) {
        return 2;
    } else {
        return 0;
    }
}

// Start ball position
int setStartBallPos() {
    int y = 0;
    y = rand() % ROW + 1;
    return y;
}

// Set random direction
int setRandomDir() {
    int dir = rand() % 2;
    if (dir == 0) {
        return 1;
    } else {
        return -1;
    }
}

// Wall reflection
int wallReflection(int y) {
    if (y == 1) {
        return 1;
    } else if (y == ROW) {
        return -1;
    } else {
        return 0;
    }
}

// Racket reflection
int platformReflection(int x1, int x2, int xb, int yb) {
    if ((x1 == yb || (x1 + 1 == yb) || (x1 + 2 == yb)) && xb == 2) {
        return 1;
    } else if ((x2 == yb || (x2 + 1 == yb) || (x2 + 2 == yb)) && xb == COL - 1) {
        return -1;
    } else {
        return 0;
    }
}