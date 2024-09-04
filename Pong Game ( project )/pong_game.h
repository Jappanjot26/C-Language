
void ball(int y, int x, int flag);

void paddle(int y, int x, int flag);

void field(int ROW, int COL);

typedef struct {

  short int x, y, c;
  bool moveH, moveV;

} obj;

void handleInput(bool *fin, obj *ball1, obj *ball2);

void handlePositions(int *cont, obj *b, obj *ball1, obj *ball2, int ROW, int COL);

void drawingElements(obj *b, obj *ball1, obj *ball2, int ROW, int COL);
