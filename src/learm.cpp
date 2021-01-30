#include "prog.h"

learm::~learm() {

    std::cout << typeid(this).name() << to_string() << '\n';
}

void learm::debug() const {

    menu::debug();
}

std::string learm::to_string() const {

    return " learm   解体";
}

void learm::select_menu() const {

    std::cout << "      起動選択してください。" << "\n\n";
    std::cout << " --- C++ Introduction Menu. ---" << std::endl;
    std::cout << " 1.  表示--標準出力" << std::endl;
    std::cout << " 2.  改行を出力" << std::endl;
    std::cout << " 3.  文字列" << std::endl;
    std::cout << " 4.  整数と浮動小数点数" << std::endl;
    std::cout << " 5.  変数" << std::endl;
    std::cout << "77.  include/learm.h" << std::endl;
    std::cout << "88.      src/learm.cpp" << std::endl;
    std::cout << "99.  ファイルの表示" << std::endl;
    std::cout << " 0.  exit-learm" << std::endl;
}

void learm::select_load() const {

    const char *key_word[] {

        "例: src/xxx.cpp  or  include/xxx.h or include/prog.h or",
        "    src/leram/xxx.cpp",
        " src/learm/HelloWorld.cpp    __ 1.  表示",
        " src/learm/HelloWorld1.cpp   __ 2.  改行を出力",
        " src/learm/String.cpp        __ 3.  文字列",
        " src/learm/IntDouble.cpp     __ 4.  整数と浮動小数点数",
        " src/learm/Variable.cpp      __ 5.  変数",
    };

    do {
        select_menu();
        int select;
        std::cin >> select;
        lines(60);
        int num = sizeof(key_word) / sizeof(key_word[0]);

        switch (select) {

            case  1:  repeat(HelloWorld);                  break;
            case  2:  repeat(HelloWorld1);                 break;
            case  3:  repeat(String);                      break;
            case  4:  repeat(IntDouble);                   break;
            case  5:  repeat(Variable);                    break;
            case 77:  file_open("include/learm.h");        break;
            case 88:  file_open("src/learm.cpp");          break;
            case 99:
                      for (int i = 0; i < num; i++) {
                          std::cout << key_word[i]  << std::endl;
                      }
                      file_exist_open();                   break;
            case  0:  std::cout << " exit-learm " << '\n'; break;
            default:  break;
        }
    } while (confirm_retry());
}

bool learm::confirm_retry() const {

    return menu::confirm_retry();
}

bool learm::retry_file() const {

    return menu::retry_file();
}

void learm::lines(int size) const {

    menu::lines(60);
}

void learm::repeat(void(*fit)(void)) const {

    std::string retry;
    static int count = 1;

    do {
        std::cout << ' ' << count++ << " 回目" << '\n';
        std::cout << "好きなだけ、どうぞ! | *_* | ... 終了『 END or exit 』" << '\n';
        (*fit)();
        lines(60);
        std::cout << '\n';

        do {
            std::cout << "続ける【 Y(y)...Yes / N(n)...No 】: ";
            std::cin >> retry;

            if (retry == "exit" || retry == "END")

                goto Exit;

       } while (retry != "Y" && retry != "y" &&
                retry != "N" && retry != "n");
   } while (retry == "Y" || retry == "y");

Exit:  std::cout << "exit / END ... 終了\n";
   ;
}
