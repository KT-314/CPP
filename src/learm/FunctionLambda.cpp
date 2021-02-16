#include "prog.h"
using namespace std::literals;

// 6. 関数 lambda
void FunctionLambda() {

    auto _ = [](auto str) { std::cout << str << std::endl; };
    auto line = [](auto x) { for (int i = 0; i < x; i++) { std::cout << '-'; }
         std::cout << std::endl; };

    [](auto x) { std::cout << x; } ("-- ラムダ式 -- "s);
    _("ローカル関数。");
    auto message = "local_function!"s;

    [=] {
        std::cout << "auto message = \"local_function!\"s;\n";
        std::cout << "キャプチャー\n";
        std::cout << "[=] -> message => " << message;
    } ();
    line(0);
    line(60);

    _("ラムダ式 -- 関数 --");
    auto func = [](auto x) { std::cout << x << '\n'; };
    auto print = [](auto x) { std::cout << x; };
    std::cout << "auto func = [](auto x) { std::cout << x << '\\n'; };" << std::endl;
    _("関数呼び出し。");
    print("func(123);            int ..> ");   func(123);
    print("func(3.14);         double..> ");   func(3.14);
    print("func(\"hello\"); char const ..> "); func("hello");
    line(60);

    _("引数を2回標準出力する関数。");
    auto twice = [](auto x) { std::cout << x << " "s << x << '\n'; };

    std::cout <<
        "auto twice = [](auto x) { std::cout << x << \" \"s << x << '\\n'; };\n"
        "twice(5); ..> ";
    twice(5);
    line(60);

    _("引数は auto 引数名で受け取れる。");
    _("引数を複数取る場合は、カンマ,で区切る。");
    auto print_two = []( auto x, auto y ) { std::cout << x << " "s << y << '\n'; };

    std::cout <<
        "auto print_two = []( auto x, auto y ) { "
        "std::cout << x << \" \"s << y << '\\n';};\n";
    std::cout << "print_two(1, 2); ..> ";
    print_two(1, 2);
    std::cout << "print_two(\"Pi is\", 3.14); ..> ";
    print_two("Pi is", 3.14);
    line(60);

    _("引数を取らないラムダ式を書く場合は、単に()と書く。");
    auto no_args = []() { std::cout << "Nothing.\n"; };

    std::cout << "auto no_args = []() { std::cout << \"Nothing.\\n\";}; ..> ";
    std::cout << "no_args() ..> ";
    no_args();
    line(60);

    _("関数は値を返すことができる。");
    _("関数から値を返すには、return文を使う。");
    auto plus = []( auto x, auto y ) { return x + y; };
    std::cout << "auto plus = []( auto x, auto y ) { return x + y; };\n";
    std::cout << "plus(1, 2);           値 ..> "     <<  plus(1, 2)           << "\n"s;
    std::cout << "plus(1.5, 0.5);       値 ..> "     <<  plus(1.5, 0.5)       << "\n"s;
    std::cout << "plus(\"123\"s, \"456\"s); 値 ..> " <<  plus("123"s, "456"s) << '\n';
    line(60);

    auto _x = plus(1, 2);
    std::cout << "auto _x = plus(1, 2); _x ..> " << _x << '\n';
    line(60);

    std::cout << "auto _f = []() {\n";
    std::cout << "    std::cout << \"_f is called.\\n;\n";
    std::cout << "    return 0;\n";
    std::cout << "    std::cout << \"_f returned zero.\\n;\n";
    std::cout << "    return 1;\n";
    std::cout << "};\n";

    auto _f = []() {
        std::cout << "_f is called.\n";
        return 0;
        std::cout << "_f returned zero.\n";
        return 1;
    };

    std::cout << "auto result = _f(); ..> ";
    auto result = _f();
    std::cout << "result ..> " << result << std::endl;
}
