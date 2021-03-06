#include "prog.h"

//  起動選択  もう一度、トライするかどうかの確認
bool confirm_retry() {

    int retry;

    std::cout << "\"Start Menu.\" 表示の確認。\n" 
              << '\n' << " 表示する... 1 / 表示しない... 0 : ";

    std::cin >> retry;

    if (retry == 1) {

        std::cout << "表示" << "\n\n";
        return static_cast<bool>(retry);
    }
    if (retry == 0) {

        std::cout << "終了" << "\n\n";
        return static_cast<bool>(retry);
    }
    else {

       std::cout << "入力が不正です。" << '\n';
       std::exit(1);
    }
}

//  セレクト  メニュー
void select_menu() {

   std::cout << "\"Start Menu.\" 起動選択してください。" << "\n\n";
   std::cout << " Learm   C++ Introduction.      ...  0" << '\n';
   std::cout << " Learm1      Operators.         ...  1" << '\n';
   std::cout << " Learm2      Container.         ...  2" << '\n';
   std::cout << " Exit.                          ... 99" << '\n';
}

void start() {

    menu* menu_obj[] = {

        new learm(),
        new learm1(),
        new learm2(),
    };

    do {
      select_menu();
      int select;
      std::cout << '\n' << "番号を 入力して下さい。: ";
      std::cin >> select;
      std::cout << '\n' << select << " を実行します。" << '\n';

      switch (select) {

          case  0: menu_obj[0]->select_start();              break;
          case  1: menu_obj[1]->select_start();              break;
          case  2: menu_obj[2]->select_start();              break;
          case 99: std::cout << " exit " << '\n'; goto Exit; break;
          default: break;
       }
    } while (confirm_retry());

Exit:

    for (size_t i = 0; i < sizeof(menu_obj) / sizeof(menu_obj[0]); i++) {

        delete menu_obj[i];
    }
    return;
}
