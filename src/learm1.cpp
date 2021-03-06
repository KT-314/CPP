#include "prog.h"

learm1::~learm1() {

    std::cout << typeid(this).name() << to_string() << '\n';
}

void learm1::debug() const {

    menu::debug();
}

std::string learm1::to_string() const {

    return " learm1 解体";
}

void learm1::select_menu() const {

    std::cout << "        起動選択してください。\n" << std::endl;
    std::cout << "---        C++ Operators.        ---" << std::endl;
    std::cout << " 1  Operator1  (n)進数　2, 8, 10, 16" << std::endl;
    std::cout << " 2  Operator2  >> 右シフト演算子 (右に1、シフト)" << std::endl;
    std::cout << "77  include/learm1.h" << std::endl;
    std::cout << "88      src/learm1.cpp" << std::endl;
    std::cout << "99  ファイルの表示" << std::endl;
    std::cout << " 0  exit-learm1" << std::endl;
}

void learm1::select_load() const {

    const char *key_word[] {

        "例: src/xxx.cpp  or  include/xxx.h or include/prog.h or",
        "    src/leram1/xxx.cpp",
        " src/learm1/Operator1.cpp    __ 1. (n)進数　2, 8, 10, 16",
        " src/learm1/Operator2.cpp    __ 2. >> 右シフト演算子 (右に1、シフト)",
    };

    do {
        select_menu();
        int select;
        std::cin >> select;
        lines(60);
        int num = sizeof(key_word) / sizeof(key_word[0]);

        switch (select) {

            case  1:  repeat(Operator1);                    break;
            case  2:  repeat(Operator2);                    break;
            case 77:  file_open("include/learm1.h");        break;
            case 88:  file_open("src/learm1.cpp");          break;
            case 99:
                      for (int i = 0; i < num; i++) {
                          std::cout << key_word[i]  << std::endl;
                      }
                      file_exist_open();                    break;
            case  0:  std::cout << " exit-learm1 " << '\n'; break;
            default:  break;
        }
    } while (confirm_retry());
}

bool learm1::confirm_retry() const {

    return menu::confirm_retry();
}

bool learm1::retry_file() const {

    return menu::retry_file();
}

void learm1::lines(int size) const {

    menu::lines(60);
}

void learm1::repeat(void(*fit)(void)) const {

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
