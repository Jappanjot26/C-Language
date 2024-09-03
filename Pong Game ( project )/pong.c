#include <ncurses.h>
#include <string.h>
#include <time.h>

static int ROW, COL;

void ball(int y, int x, int flag){

  if (!flag)
    mvaddch(y, x, ' '),
        mvaddch(y, x + 1, ' ');
  else
    mvaddch(y, x, ACS_CKBOARD),
        mvaddch(y, x + 1, ACS_CKBOARD);

}

void paddle(int y, int x, int flag){

  int i;

  if (!flag){
    for (i = 0; i < 5; i++){
      ball(y + i, x, 0);
    }
  }

  else {
    for (i = 0; i < 5; i++){
      ball(y + i, x, 1);
    }
  }

}

void field(){

  int i;
  for (i = 0; i <= ROW; i++){
    if (!(i % 2)){
      ball(i, COL / 2 - 2, 1);
    }
  }

}

typedef struct {

  short int x, y, c;
  bool moveH, moveV;

} obj;

void handleInput(bool *fin, obj *ball1, obj *ball2){
  switch (getch()){

    case 'q':
    case 'Q':
    case 0x1B:
      endwin();
      *fin++;
      break;

    case 'a':
    case 'A':
      ball2->y--;
      break;

    case 'z':
    case 'Z':
      ball2->y++;
      break;

    case KEY_UP:
      ball1->y--;
      break;

    case KEY_DOWN:
      ball1->y++;
      break;

    case 'p':
      getchar();
      break;

  }
}

void handlePositions(int *cont, obj *b, obj *ball1, obj *ball2){

  if (++(*cont) % 16 == 0){

    if ((b->y == ROW - 1) || (b->y) == 1){
      b->moveV = !b->moveV;
    }

    if ((b->x >= COL - 2) || (b->x <= 2)){
      
      b->moveH = !b->moveH;

      if ((b->y == ball1->y - 1) || (b->y == ball2->y - 1)){
        b->moveV = FALSE;
      }
      
      else if ((b->y == ball1->y + 1) || (b->y == ball2->y + 1)){
        b->moveV = TRUE;
      }

      else if ((b->y != ball1->y) && (b->y != ball2->y)){
        (b->x >= COL - 2) ? ball1->c++ : ball2->c++;

        b->x = COL / 2;
        b->y = ROW / 2;
      }
    }

    b->x = b->moveH ? b->x + 1 : b->x - 1;
    b->y = b->moveV ? b->y + 1 : b->y - 1;

    if (ball1->y <= 1)
      ball1->y = ROW - 2;
    
    if (ball1->y >= ROW - 1)
      ball1->y = 2;
    
    if (ball2->y <= 1)
      ball2->y = ROW - 2;
    
    if (ball2->y >= ROW - 1)
      ball2->y = 2;
  }
}

void drawingElements(obj *b, obj *ball1, obj *ball2){

  if (ball1->c < 10){
    mvprintw(2, COL / 2 - 3, "%i | %i", ball1->c, ball2->c);
  }

  else{
    mvprintw(2, COL / 2 - 4, "%i | %i", ball1->c, ball2->c);
  }

  mvvline(0, COL / 2 - 1, ACS_VLINE, ROW);

  mvaddch(b->y, b->x - 1, ACS_CKBOARD);

  mvaddch(b->y, b->x, ACS_CKBOARD);

  for (int i = -2; i < 3; i++){

    mvaddch(ball1->y + i, ball1->x - 1, ACS_CKBOARD);
    mvaddch(ball1->y + i, ball1->x, ACS_CKBOARD);

    mvaddch(ball2->y + i, ball2->x + 1, ACS_CKBOARD);
    mvaddch(ball2->y + i, ball2->x, ACS_CKBOARD);
  }
}

int main(int argc, char *argv[]){

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
  curs_set(0);

  srand((unsigned)time(0));

  getmaxyx(stdscr, ROW, COL);
  
  start_color();

  field();

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

    handlePositions(&cont, &b, &ball1, &ball2);

    handleInput(&fin, &ball1, &ball2);

    erase();

    drawingElements(&b, &ball1, &ball2);
  }
  
  return 0;
}