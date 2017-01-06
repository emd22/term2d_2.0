#include <term2d/term2d.hpp>

/*
term2dterm2d                                              2dterm2dter     rm2dterm2d
term2dterm2d    2dterm2dter     rm2dter   term2   rm2dt        m2dterm    rm2d    2dte
    2dte       m2dt     term   erm2     2dt    dte    ter         term2   rm2d    2dte
    2dte      rm2d       erm2 term      2dt    dte    ter         term2   rm2d    2dte
    2dte      rm2dterm2dterm2 term      2dt    dte    ter       2dterm2   rm2d    2dte
    2dte      rm2d            term      2dt           ter     rm2dterm    rm2d    2dte
    2dte       m2dt     term2 term      2dt           ter    erm2dt       rm2d    2dte
    2dte        2dterm2dter   term      2dt           ter 2dterm2dterm2dt rm2dterm2d
*/

int main() {
  ScreenSpace ss;
  RunAnimation key;
  Animation ani;

  char pressed_key;
  ss.Create(TermWidth(), TermHeight(), '.');
  key.Init(&ani, "key");

  while (true) {
    pressed_key = CurKey();
    key.Run(&ss, 10, 10, true);
    if (pressed_key == 'q') {
      return 0;
    }
  }
}
