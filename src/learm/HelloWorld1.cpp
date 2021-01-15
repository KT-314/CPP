#include "prog.h"
using namespace std::literals;

// 2. 改行を出力
void HelloWorld1() {

    auto _ = [](auto str) {

        std::cout << str << std::endl;
    };

    auto line = [](auto x) {

        for (int i = 0; i < x; i++) {

            std::cout << '-';
        }
        std::cout << std::endl;
    };

    _("1. 改行を出力");
    line(0);
    std::cout << "std::cout << \"Hello\"s << std::endl; _> ";
    std::cout << std::endl;
    std::cout << "Hello"s << std::endl;

    std::cout << "std::cout << \"Hello\"s; _> " << std::flush;
    std::cout << "Hello"s;
    std::cout << std::endl;
    std::cout << "std::cout << \"World\"s; _> " << std::flush;
    std::cout << "World"s;
    std::cout << std::endl;
    std::cout << "std::cout << '\\n';";
    std::cout << '\n';

    std::cout << "std::cout << \"A->\"s << \"<-B->\"s << \"<-C\"s << std::flush _> ";
    std::cout << "A->"s << "<-B->"s << "<-C"s << std::flush;
    std::cout << std::endl;
    std::cout << "std::cout << std::endl;";
    std::cout << std::endl;
}
