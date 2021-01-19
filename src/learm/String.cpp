#include "prog.h"
using namespace std::literals;

// 3. 文字列
void String() {

    auto _ = [](auto str) { std::cout << str << std::endl; };
    auto line = [](auto x) { for (int i = 0; i < x; i++) { std::cout << '-'; }
         std::cout << std::endl; };

    _("3. 文字列");
    line(0);
    _("二重引用符で囲まれた文字列を文字どおり文字列という。\n"
      "これは文字列。");
    std::cout << "std::cout << \"hello\"s; _> ";
    std::cout << "hello"s << std::endl;
    line(0);
    _("これも文字列、ただし不便。");
    std::cout << "std::cout << \"hello\";  _> ";
    std::cout << "hello" << std::endl;
    line(0);
    _("文字列リテラルの中にバックスラッシュを書くと、\n"
      "エスケープシーケンスとして扱われる。");
    std::cout << "std::cout << \"A-a\\nB-b\\nC-c\"s; _> ";
    std::cout << "A-a\nB-b\nC-c"s << '\n';
    line(0);
    _("バックスラッシュを文字列で使いたい場合は、\n"
      "\\""\\ と書かなければならない。");
    std::cout << "std::cout << \\""\\n is a new-line.\"s; _> ";
    std::cout << "\\n is a new-line.\n"s;
    line(0);
    _("文字列は演算子operator + で足すことができる、\n"
      "文字列を足す というのは文字列を結合するという意味。");
    std::cout << "std::cout << \"Hello\"s + \"World\" + \"!\"s; _> ";
    std::cout << "Hello"s + "World"s + "!" << std::endl;
}
