#include "prog.h"

// 1. 表示
void HelloWorld() {

    auto _ = [](auto str) {
        std::cout << str << '\n';
    };

    auto line = [](auto x) {
        for (int i = 0; i < x; i++) {
            std::cout << '-';
        }
        std::cout << '\n';
    };

    _("1. 表示   標準出力");
    line(0);
    std::cout << "std::cout << \"Hello World!\"; _> ";
    std::cout << "Hello World!";
    line(0);
}
