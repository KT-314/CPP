#include "prog.h"
using namespace std::literals;

// 4. 整数と浮動小数点数
void IntDouble() {

    auto _ = [](auto str) { std::cout << str << std::endl; };
    auto line = [](auto x) { for (int i = 0; i < x; i++) { std::cout << '-'; }
         std::cout << std::endl; };
    auto Operator = [](auto a, auto b) {
         std::cout << a << " = " << std::setw(4) << b << std::endl; };

    _("4. 整数と浮動小数点数");
    line(0);
    std::cout << "std::cout << \"Integer: \"s        << 42;   _> "s;
    std::cout << "Integer: "s        << 42   << std::endl;
    std::cout << "std::cout << \"Floating Point: \"s << 3.14; _> "s;
    std::cout << "Floating Point: "s << 3.14 << std::endl;
    line(60);
    _("整数");
    Operator("乗算  3 * 5"s, 3 * 5);
    Operator("除算  3 / 5"s, 3 / 5);
    Operator("乗除  3 % 5"s, 3 % 5);
    Operator("加算  3 + 5"s, 3 + 5);
    Operator("減算  3 - 5"s, 3 - 5);
    Operator("単項+   +10"s,   +10);
    Operator("単項-   -10"s,   -10);
    Operator("優先順位 1 + 2  * 3"s,  1 + 2  * 3);
    Operator("優先順位(1 + 2) * 3"s, (1 + 2) * 3);
    line(60);
    _("浮動小数点数同士でも四則演算ができる。剰余はできない。");
    Operator("乗算  3.5 * 7.11"s, 3.5 * 7.11);
    Operator("除算  3.5 / 7.11"s, 3.5 / 7.11);
    std::cout << "乗除  3.5 % 7.11 = 3.5 % 7.1; エラー"s << std::endl;
    Operator("加算  3.5 + 7.11"s, 3.5 + 7.11);
    Operator("減算  3.5 - 7.11"s, 3.5 - 7.11);
    Operator("単項+      +10.1"s,   +10.1);
    Operator("単項-      -10.1"s,   -10.1);
    Operator("優先順位 1.0 + 2.0  * 3.0"s,  1.0 + 2.0  * 3.0);
    Operator("優先順位(1.0 + 2.0) * 3.0"s, (1.0 + 2.0) * 3.0);
    line(60);
    Operator("std::cout << 1 + 0.1"s,  1 + 0.1);
    std::cout << "std::cout << 1 + \"234\"s; エラー"s << std::endl;
    _("C++には末尾にsを付けない文字列もある。");
    Operator("std::cout << 1 + \"234\"", 1 + "234");
    _("? 34 になる。 いまは文字列には必ず末尾に \"s\" を付けること。");
}
