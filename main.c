#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct Snake {
  int x;
  int y;
  int dirX;
  int dirY;
} Snake;

typedef struct Fruit {
  int x;
  int y;
} Fruit;

Snake snake;
Fruit fruit;

void spawn_fruit() {
  fruit.x = rand() % COLS - 2;
  fruit.y = rand() % LINES - 2;

  mvprintw(fruit.y, fruit.x, "SDJFAFAK");
  refresh();
  //wrefresh(board);
}

void moveSnake() {
  snake.x += snake.dirX;
  snake.y += snake.dirY;
}

void draw_snake() {
  clear();
  
  attron(COLOR_PAIR(1));
  mvprintw(snake.y, snake.x, "*");
  attroff(COLOR_PAIR(1));

  refresh();
}

int update() {
  int ch;

  switch (ch = getch()) {
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
  draw_snake();

  usleep(100000 * 0.5); // just a sleep for a 0.5 second

  return 0;
}

void init() {
  srand(time(NULL));

  //board = newwin(30, 30, 0, 0);
  //box(board, 1, 1);
  refresh();
  //wrefresh(board);

  spawn_fruit();

  snake.x = (int)COLS / 2;
  snake.y = (int)LINES / 2;

  init_pair(1, COLOR_GREEN, COLOR_GREEN);
}

int main() {
  initscr();
  /*curs_set(0);
  noecho();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  start_color();
  use_default_colors();*/

  WINDOW *suck = newwin(30, 30, 1, 1);
  box(suck, '*', '*');
  touchwin(suck);
  wrefresh(suck);

  getch();
  endwin();

  return 0;
}
