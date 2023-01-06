#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

typedef struct Point {
    int x;
    int y;
} point;

// Global variables
point headCoord;
point fruitCoord;
int width = 30; // x
int height = 60; // y
bool GAME;

void init();
void drawBoard();
void movement();
bool checkCollision();

int main() {
    init();

    while (GAME) {
        drawBoard();
        movement();
    }
}

void init() {
    GAME = true;


    srand(time(NULL));
    headCoord.x = width / 2;
    headCoord.y = height / 2;
    VECTOR_INIT(v);

    v.pfVectorAdd(&v, headCoord);

    fruitCoordX:
        fruitCoord[0] = rand() % width;
        if (fruitCoord[0] == 0 && fruitCoord[0] != headCoord[0])
            goto fruitCoordX;

    fruitCoordY:
        fruitCoord[1] = rand() % height;
        if (fruitCoord[1] == 0 && fruitCoord[1] != headCoord[1])
            goto fruitCoordY;
}

void drawBoard() {
    system("clear");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                printf("#");
            else {
                if (i == headCoord[0] && j == headCoord[1]) {
                    printf("*");
                } else if (i == fruitCoord[0] && j == fruitCoord[1]) {
                    printf("@");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void movement() {
    usleep(0.01);
    if (kbhit()) {
        switch(getch()) {
            case 'a':
                headCoord[1]--;
                break;
            case 'w':
                headCoord[0]--;
                break;
            case 'd':
                headCoord[1]++;
                break;
            case 's':
                headCoord[0]++;
                break;
            case 27:
                GAME = false;
                break;
        }
    }
}