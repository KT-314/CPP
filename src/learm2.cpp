#include "prog.h"

learm2::~learm2() {

    std::cout << typeid(this).name() << to_string() << '\n';
}

void learm2::debug() const {

    menu::debug();
}

std::string learm2::to_string() const {

    return " learm2 解体";
}

void learm2::select_menu() const {

    std::cout << "        起動選択してください。\n" << std::endl;
    std::cout << "---        C++ Container.        ---" << std::endl;
    std::cout << " 1             Array." << std::endl;
    std::cout << "77  include/learm2.h" << std::endl;
    std::cout << "88      src/learm2.cpp" << std::endl;
    std::cout << "99  ファイルの表示" << std::endl;
    std::cout << " 0  exit-learm2" << std::endl;
}

void learm2::select_load() const {

    const char *key_word[] {

        "例: src/xxx.cpp  or  include/xxx.h or include/prog.h or",
        "    src/leram2/xxx.cpp",
        " src/learm2/Container.cpp    __ 1. ",
    };

    do {
        select_menu();
        int select;
        std::cin >> select;
        lines(60);
        int num = sizeof(key_word) / sizeof(key_word[0]);

        switch (select) {

            case  1:  repeat(ContainerArray);               break;
            case 77:  file_open("include/learm2.h");        break;
            case 88:  file_open("src/learm2.cpp");          break;
            case 99:
                      for (int i = 0; i < num; i++) {
                          std::cout << key_word[i]  << std::endl;
                      }
                      file_exist_open();                    break;
            case  0:  std::cout << " exit-learm2 " << '\n'; break;
            default:  break;
        }
    } while (confirm_retry());
}

bool learm2::confirm_retry() const {

    return menu::confirm_retry();
}

bool learm2::retry_file() const {

    return menu::retry_file();
}

void learm2::lines(int size) const {

    menu::lines(60);
}

void learm2::repeat(void(*fit)(void)) const {

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
