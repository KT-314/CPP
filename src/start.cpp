#include "prog.h"

//  起動選択  もう一度、トライするかどうかの確認
bool confirm_retry() {

    int retry;

    std::cout << "\"learm\"  起動選択の確認... 起動しますか？\n" 
              << '\n' << " する... 1 / しない... 0 : ";

    std::cin >> retry;

    if (retry == 1) {

        std::cout << "learm 起動" << "\n\n";
        return static_cast<bool>(retry);
    }
    if (retry == 0) {

        std::cout << "learm 終了" << "\n\n";
        return static_cast<bool>(retry);
    }
    else {

       std::cout << "入力が不正です" << '\n';
       std::exit(1);
    }
}

//  セレクト  メニュー
void select_menu() {

   std::cout << "\"learm\"   起動選択してください。" << "\n\n";
   std::cout << " learm  C++ introduction  menu ...  0" << '\n';
   std::cout << '\n';
   std::cout << " exit                          ... 99" << '\n';
}

void start() {

    menu* menu_obj[] = {

        new learm(),
    };

    do {
      select_menu();
      int select;
      std::cout << '\n' << "番号を 入力して下さい : ";
      std::cin >> select;
      std::cout << '\n' << select << " を実行します。" << '\n';

      switch (select) {

          case  0: menu_obj[0]->select_start();              break;
          case 99: std::cout << " exit " << '\n'; goto Exit; break;
          default: break;
       }
    } while (confirm_retry());

Exit:

    for (int i = 0; i < sizeof(menu_obj) / sizeof(menu_obj[0]); i++) {

        delete menu_obj[i];
    }
    return;
}
