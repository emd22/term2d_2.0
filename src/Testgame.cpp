#include <term2d.hpp>

#define WIDTH 20
#define HEIGHT 16


int main() {
  DisableKeyPrint();
  HideTermCaret();

  int x = 0;
  int y = 0;

  int old_x = 0;
  int old_y = 0;

  bool safe_close = false;

  char key;

  ScreenSpace ss;
  ss.Create(WIDTH, HEIGHT, '.');

  for (;;) {
    old_x = x;
    old_y = y;
    key = CurKey();

    //keypress
    if (key == 'w') {
      y--;
    }
    else if (key == 'a') {
      x--;
    }
    else if (key == 's') {
      y++;
    }
    else if (key == 'd') {
      x++;
    }
    if (key == 'q') {
      ShowTermCaret();
      EnableKeyPrint();
      return 0;
    }

    //collision

    if (x >= WIDTH || x < 0) {
      x = old_x;
    }
    if (y >= HEIGHT || y < 0) {
      y = old_y;
    }

    ss.Edit(x, y, '#', 32, 50);

    ss.Print();
    TimeDelay("ms", 150);
    ss.Reset('.');
    ss.ClearObjs();
  }
}
