#include "prog.h"
#include <array>
#include <string>
using namespace std::string_literals;

void ContainerArray() {

    auto output=[](auto& obj, const auto& container) {
        static size_t count = 0;
        std::cout << obj << sizeof(container) / sizeof(container[0]) << '\n';
        for (auto& x : container) {
            std::cout << "要素 " << count++ << ' ' << x << '\n';
        }
        count = 0;
        std::cout << std::endl;
    };

    auto _ = [](auto str) { std::cout << str << '\n'; };
    auto line = [](auto x) { for (int i = 0; i < x; i++) { std::cout << '-'; } std::cout << '\n'; };

    std::cout << "コンテナオブジェクトの構築 (#include <array>)\n"
                 " std::array クラス\n"
                 " 固定長配列 シーケンスコンテナ -- 要素の順序が維持される。--" << std::endl;
    line(60);
    _("デフォルト構築。要素数 (N)個の array オブジェクトを構築する。"s);
    _("各要素はデフォルト初期化で構築される。"s);
    std::array<int, 4> a;
    output("std::array<int, 4> a;                要素の型 int 要素の数 ", a);

    _("初期化子リストから array オブジェクトを作成する。"s);
    _("各要素は値初期化(デフォルトコンストラクタ呼び出しまたは、0クリア)される。"s);
    std::array<int, 4> b = {};
    output("std::array<int, 4> b = {};           要素の型 int 要素の数 ", b);

    _("初期化子リストから array オブジェクトを作成する。"s);
    std::array<int, 4> c = {1, 2, 3, 4};
    output("std::array<int, 4> c = {1, 2, 3, 4}; 要素の型 int 要素の数 ", c);

    _("コピー構築。渡されたarray オブジェクトの複製を作成する。"s);
    std::array<int, 4> d = c;
    output("std::array<int, 4> d = c;            要素の型 int 要素の数 ", d);

    std::array<int, 4> e0 = c;
    output("std::array<int, 4> e0 = c;           要素の型 int 要素の数 ", e0);

    _("ムーブ構築。渡されたarray オブジェクトの中身を*thisに移動する。"s);
    std::array<int, 4> e = move(e0);
    output("std::array<int, 4> e = move(e0);     要素の型 int 要素の数 ", e);
}
