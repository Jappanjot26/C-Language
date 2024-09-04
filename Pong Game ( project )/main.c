#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "pong_game.h"

static int ROW, COL;

int main(int argc, char *argv[]){

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
  curs_set(0);

  srand((unsigned)time(0));

  getmaxyx(stdscr, ROW, COL);
  
  start_color();

  field(ROW, COL);

  paddle(ROW / 2 - 2, 2, 1);
  paddle(ROW / 2 - 2, COL - 4, 1);

  char msg1[] = "A and Z (left-paddle), Up and Down Arrow (right-paddle)";
  char msg2[] = "Q, ESC - Quit, P - Pause the game";
  char msg3[] = "<- Press any key ->";
  char msg4[] = "Left player WON!";
  char msg5[] = "Right player WON!";

  init_pair(1, COLOR_RED, COLOR_BLACK);

  attron(COLOR_PAIR(1));

  attron(A_BOLD);

  mvprintw(ROW / 2 - 8, (COL - strlen(msg1)) / 2, "%s", msg1);
  mvprintw(ROW / 2 - 7, (COL - strlen(msg1)) / 2, "%s", msg1);

  attron(A_BLINK);

  mvprintw(ROW / 2 - 3, (COL - strlen(msg3)) / 2, "%s", msg3);

  attroff(A_BLINK);
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));

  obj scr;

  int i, cont = 0;

  bool fin = FALSE;
  obj ball1 = {COL - 2, ROW / 2, 0, FALSE, FALSE},
      ball2 = {1, ROW / 2, 0, FALSE, FALSE},
      b = {COL / 2, ROW / 2, 0, FALSE, FALSE};

  getch();

  for (nodelay(stdscr, 1); !fin; usleep(4000)){

    handlePositions(&cont, &b, &ball1, &ball2, ROW, COL);

    handleInput(&fin, &ball1, &ball2);

    erase();

    drawingElements(&b, &ball1, &ball2, ROW, COL);
  }
  
  return 0;
}
