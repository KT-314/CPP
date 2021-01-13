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
    std::cout << "--- C++ Introduction Menu. ---" << '\n';
    std::cout << " 1 表示"              << '\n';
    std::cout << "77 include/learm.h"   << '\n';
    std::cout << "88     src/learm.cpp" << '\n';
    std::cout << "99 ファイルの表示"    << '\n';
    std::cout << " 0 exit-learm"        << '\n';
}

const char *key_word[] {

        "例: src/xxx.cpp  or  include/xxx.h",
        " include/prog.h",
        " src/HelloWorld.cpp    __ 1.  表示",
    };

void learm::select_load() const {

    do {
        select_menu();
        int select;
        std::cin >> select;
        lines(60);
        int num = sizeof(key_word) / sizeof(key_word[0]);

        switch (select) {

            case  1:  repeat(HelloWorld);                  break;
            case 77:  file_open("include/learm.h");        break;
            case 88:  file_open("src/learm.cpp");          break;
            case 99:
                      for (int i = 0; i < num; i++) {
                          std::cout << key_word[i]  << '\n';
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
