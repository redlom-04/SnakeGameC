#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct Snake {
    int x;
    int y;
    int dirX;
    int dirY;
} Snake ;

Snake snake;
WINDOW *board;

void moveSnake() {
    snake.x += snake.dirX;
    snake.y += snake.dirY;
}

void drawBoard() {
    clear();
    
    mvprintw(snake.y, snake.x, "*");

    refresh();
}

int update() {
    int ch;

    switch (ch = getch())
    {
    case KEY_UP:
        if (snake.dirY == 1)
            break;
        snake.dirX = 0;
        snake.dirY = -1;
        break;
    case KEY_DOWN:
        if (snake.dirY == -1)
            break;
        snake.dirX = 0;
        snake.dirY = 1;
        break;
    case KEY_LEFT:
        if (snake.dirX == 1)
            break;
        snake.dirX = -1;
        snake.dirY = 0;
        break;
    case KEY_RIGHT:
        if (snake.dirX == -1)
            break;
        snake.dirX = 1;
        snake.dirY = 0;
        break;
    case (int)'q':
        return 1;
    case 27:
        return 1;
    default:
        break;
    }

    moveSnake();
    drawBoard();

    usleep(1000000 * 1);

    return 0;
}

int main() {
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, TRUE);
    start_color();
    use_default_colors();

    board = newwin(30, 30, 0, 0);

    snake.x = 15;
    snake.y = 15;

    while (update() == 0);

    delwin(board);

    endwin();

    return 0;
}