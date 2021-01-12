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

    std::cout << '\n';
    std::cout << "      起動選択してください" << "\n\n";
    std::cout << "--- C++ operator            ---" << '\n';
    std::cout << " 1  operator-test              " << '\n';
    std::cout << "77  include/learm1.h" << '\n';
    std::cout << "88      src/learm1.cpp" << '\n';
    std::cout << "99  ファイルの表示" << '\n';
    std::cout << " 0  exit-learm1" << '\n';
}

void learm1::select_load() const {

    do {
        select_menu();
        int select;
        std::cin >> select;
        lines(60);

        switch (select) {

            case  1:  std::cout << "operator-OK" << '\n';   break;
            case 77:  file_open("include/learm1.h");        break;
            case 88:  file_open("src/learm1.cpp");          break;
            case 99:  file_exist_open();                    break;
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
