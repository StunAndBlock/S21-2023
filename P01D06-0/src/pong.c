#include <stdio.h>

#define ROW 25
#define COL 80

void drawGame(int p1y, int p2y, int bx, int by, int score1, int score2);
int checkGoal(int bx);
int checkWin(int score1, int score2);
int setStartBallPos();
int setRandomDir();
int platformReflection(int y1, int y2, int bx, int by);
int wallReflection(int by);

int main() {
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
    char prev_move = '\n';
    while (game) {
        drawGame(p1y, p2y, bx, by, score1, score2);
        bx += vx;
        by += vy;
        // input
        char move = getchar();
        if ((prev_move >= 'a' && prev_move <= 'z' && move != '\n') ||
            (move >= 'a' && move <= 'z' && prev_move != '\n')) {
            printf("\e[1;1H\e[2J");
            printf("n/a");
            break;
        } else {
            if (move != 'a' && move != 'z' && move != 'k' && move != 'm' && move != ' ' && move != '\n') {
                printf("\e[1;1H\e[2J");
                printf("n/a");
                break;
            }
            prev_move = move;
        }
        switch (move) {
            case 'a':
                if (p1y > 1) {
                    --p1y;
                }
                break;
            case 'z':
                if (p1y < 23) {
                    ++p1y;
                }
                break;
            case 'k':
                if (p2y > 1) {
                    --p2y;
                }
                break;
            case 'm':
                if (p2y < 23) {
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
            bx = 40;
            by = setStartBallPos();
            vx = setRandomDir();
            vy = setRandomDir();
        }
        if (checkGoal(bx) == 2) {
            ++score2;
            bx = 40;
            by = setStartBallPos();
            vy = setRandomDir();
            vx = setRandomDir();
        }
        game = checkWin(score1, score2);
    }
    return 0;
}

// Drawing field
void drawGame(int p1y, int p2y, int bx, int by, int score1, int score2) {
    printf("\e[1;1H\e[2J");
    for (int i = 0; i <= ROW + 1; i++) {
        for (int j = 0; j <= COL + 1; j++) {
            if (i == 0 || i == ROW + 1) {
                putchar('_');
                if (j == COL + 1) {
                    putchar('\n');
                }
                continue;
            }
            if ((j == 0 || j == COL + 1 || j == COL / 2) && i != ROW + 1) {
                putchar('|');
                if (j == COL + 1) {
                    putchar('\n');
                }
                continue;
            }
            if (j == 1 && (i == p1y || i == p1y + 1 || i == p1y + 2)) {
                putchar(']');
                continue;
            }
            if (j == COL && (i == p2y || i == p2y + 1 || i == p2y + 2)) {
                putchar('[');
                continue;
            }
            if (i == by && j == bx) {
                putchar('o');
                continue;
            }
            putchar(' ');
        }
    }
    printf("Score: %d - %d\n", score1, score2);
}

// Winner
int checkWin(int score1, int score2) {
    if (score1 == 21) {
        printf("\e[1;1H\e[2J");
        puts("Player1 won!");
        return 0;
    }
    if (score2 == 21) {
        printf("\e[1;1H\e[2J");
        puts("Player2 won!");
        return 0;
    } else {
        return 1;
    }
}

// Counting goals
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

// Set start ball position
int setStartBallPos() {
    static int random = 0;
    random = (1103515245 * random + 12345) % 2147483648;
    if (random < 0) {
        random *= -1;
    }
    return random % 25 + 1;
}

// Setting direction for ball
int setRandomDir() {
    static int dir = 0;
    dir = (1103515245 * dir + 12345) % 2147483648;
    if (dir % 2 == 0) {
        return -1;
    } else {
        return 1;
    }
}

// Wall reflection
int wallReflection(int by) {
    if (by == 1) {
        return 1;
    } else if (by == ROW) {
        return -1;
    } else {
        return 0;
    }
}

// Racket reflection
int platformReflection(int y1, int y2, int bx, int by) {
    if ((y1 == by || (y1 + 1 == by) || (y1 + 2 == by)) && bx == 2) {
        return 1;
    } else if ((y2 == by || (y2 + 1 == by) || (y2 + 2 == by)) && bx == COL - 1) {
        return -1;
    } else {
        return 0;
    }
}