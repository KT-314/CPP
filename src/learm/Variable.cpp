#include "prog.h"
using namespace std::literals;

// 5. 変数
void Variable() {

    auto _ = [](auto str) { std::cout << str << std::endl; };
    auto line = [](auto x) { for (int i = 0; i < x; i++) { std::cout << '-'; }
         std::cout << std::endl; };
    auto Variables = [](auto str, auto p_q, auto q_p) {
         std::cout << str << '\n' << p_q << " ..> " << q_p << std::endl; };

    _("5. 変数");
    line(0);

    auto answer = 10;
    Variables(" 整数の変数\nauto answer = 10;", "answer", answer);
    line(0);

    auto pi = 3.14;
    Variables(" 浮動小数点数の変数\nauto pi = 3.14;", "pi", pi);
    line(0);

    auto StrV = "Str Var."s;
    Variables(" 文字列の変数\nauto StrV = \"Str Var.\"s;", "StrV", StrV);
    line(0);
    _("変数の最初の値は、= 値の代わりに(値) や{値} と書いてもよい。");

    auto a = 1;
    std::cout << " auto a = 1;";
    std::cout << "      a ..> "  << a << std::endl;

    auto b(2);
    std::cout << " auto b(2); ";
    std::cout << "      b ..> "  << b << std::endl;

    auto c{3};
    std::cout << " auto c{3}; ";
    std::cout << "      c ..> "  << c << std::endl;
    line(0);

    _("変数は使う前に宣言しなければならない。");
    line(0);

    _("エラー、名前xは宣言されていない。");
    _("std::cout << x;");
    _("auto x = 1;");
    line(0);

    auto x
    = 1;
    _("変数の宣言    ..> auto x;");
    std::cout << "auto x = 1; x ..> " << x << " 初期化" << std::endl;;
    x = 2;
    std::cout << "     x = 2; x ..> " << x << " 代入" << std::endl;
    x = 3;
    std::cout << "     x = 3; x ..> " << x << " もう一度代入" << std::endl;
    line(0);

    _("代入演算子 operator = は左辺に変数名を、右辺に代入する値を書く。");
    auto XYZ = 10;
    XYZ = XYZ + 5;
    std::cout << "auto XYZ = 10;\nXYZ = XYZ + 5; ..> " << XYZ << std::endl;

    auto _X = 1;
    _("auto _X = 1;");

    _X += 5;
    _("(_X += 5; == _X = _X + 5; 等価)");
    std::cout << "auto _X = 1;\n"
                 "_X += 5; ..> " << _X << std::endl;
    line(0);

    _("auto _X = 1;\n\n"
      "エラー\n"
      "_X = \"hello\"s;\n"
      "_X = 2;\n\n"
      "C++では、変数 _X は整数型であり、文字列型に変わることはない。");

    auto i = 123;
    _("i は、int型 int i = 123;");
    std::cout << "auto i = 123;   ..> " << i << "(int)" << std::endl;

    auto d = 1.23;
    _("d は、double型 double d = 1.23;");
    std::cout << "auto d = 1.23;  ..> " << d << "(double)" << std::endl;

    auto s = "123"s;
    _("s は、std::string型 std::string s = \"123\"s;");
    std::cout << "auto s = \"123\"s;..> " << s << "(std::string)" << std::endl;
    line(0);

    int int_double = 3.14;
    _("浮動小数点数型を整数型に変換。");
    std::cout << "   int int_double = 3.14;   int_double ..> " << int_double << std::endl;
    line(0);

    double double_int = 123;
    _("整数型を浮動小数点数型に変換。");
    std::cout << "double double_int = 123;    double_int ..> " << double_int << std::endl;
    line(0);

    int x_int = 0.9999;
    _("浮動小数点数型を整数型に変換すると、小数部が切り捨てられる。");
    std::cout << "   int    x_int = 0.9999;     x_int    ..> " << x_int << std::endl;
    line(0);

    double x_double = 1234567890;
    _("正確に表現できるかどうかわからない。");
    std::cout << "double x_double = 1234567890; x_double ..> " << x_double << std::endl;
}

