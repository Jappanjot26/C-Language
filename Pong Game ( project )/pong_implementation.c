#include <ncurses.h>
#include <string.h>
#include <time.h>


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

void field(int ROW, int COL){

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

void handlePositions(int *cont, obj *b, obj *ball1, obj *ball2, int ROW, int COL){

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

void drawingElements(obj *b, obj *ball1, obj *ball2, int ROW, int COL){

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


