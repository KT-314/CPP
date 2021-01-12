#ifndef MENU_H
#define MENU_H

#include "prog.h"

class menu {

public:
    virtual ~menu() = 0;                             // デストラクタ
    virtual void debug()                  const = 0; // デバッグ用情報表示
    virtual std::string to_string()       const = 0; // menu情報の文字列表現を返却
    virtual void select_menu()            const = 0; // セレクト-メニュー
    virtual void select_load()            const = 0; // セレクト-ロード
    virtual bool confirm_retry()          const = 0; // もう一度トライするか
    virtual bool retry_file()             const = 0; // もう一度ファイルを開くか
    virtual void lines(int size)          const = 0; // サイズを指定してラインを引く
    virtual void repeat(void(*fit)(void)) const = 0; // 繰り返す

    // 情報解説付き描画
    void select_start() const {

        std::cout << typeid(*this).name() << '\n';
        select_load();
        debug();
    }

    // ファイルの存在確認
    void file_exist_open() const {

        std::string file_name;
        std::cout << "表示したいファイル名 : ";
        std::cin >> file_name;
        std::cout << "ファイルは存在"
                  << (file_exist(file_name.c_str()) ? "します\n" : "しません\n");
        std::ifstream  fis(file_name);

        if (!fis) {

            std::cerr << "ファイル" << file_name << "を オープン出来ません\n";
        }

        while (true) {

            std::string text;
            std::getline(fis, text);

            if (!fis) break;
            std::cout << text << '\n';
        }
    }

    // ファイルが存在するかどうかを判定
    bool file_exist(const char* filename) const {

        std::ifstream  fis(filename);
        return fis.is_open();
    }

    // ファイルオープン
    void file_open(std::string file_name) const {

        std::ifstream  fis(file_name);

        if (!fis) {

            std::cerr << "ファイル" << file_name << "を オープン出来ません\n";
        }
        while (true) {

         std::string text;
         std::getline(fis, text);

         if (!fis) break;
         std::cout << text << '\n';
      }
   }
};

/* menu 関数の外 */

// サイズを指定して、ラインを引く
inline void menu::lines(int size) const {

    for (int i = 0; i < size; i++) {

        std::cout << '-';
    }
    std::cout << '\n';
}

// 情報表示
inline void menu::debug() const {

    std::cout << "       型      : " << typeid(*this).name() << '\n';
    std::cout << "     アドレス  : " << this << '\n' << '\n';
}

// 純粋仮想デストラクタ
inline menu::~menu() {

    std::cout << typeid(this).name() << "          解体" << '\n';
}

// to_string が返却する文字列を表示
inline std::ostream& operator<<(std::ostream& os, const menu& m) {

    return os << m.to_string();
}

// セレクト-メニュー
inline void menu::select_menu() const {

    std::cout << '\n';
    std::cout << "      起動選択してください" << '\n';
    std::cout << "   C++        " << "\n\n";
    std::cout << " 1 list_one   " << '\n';
    std::cout << " 2 list_two   " << '\n';
    std::cout << " 3 list_three " << '\n';
    std::cout << " 4 list_four  " << '\n';
    std::cout << " 5 list_five  " << '\n';
    std::cout << " 6 list_six   " << '\n';
    std::cout << " 7 list_seven " << '\n';
    std::cout << " 8 list_eight " << '\n';
    std::cout << " 9 list_nine  " << '\n';
    std::cout << "10 list_ten   " << '\n';
    std::cout << "99 表示したいファイルの存在確認" << '\n';
    std::cout << " 0 exit "       << '\n';
}

// セレクト-ロード
inline void menu::select_load() const {

    do {
        select_menu();

        int select;
        std::cin >> select;
        lines(60);

        switch (select) {

            case  1:  break;
            case 99:  file_exist_open();             break;
            case  0:  std::cout << " exit " << '\n'; break;
            default:  break;
        }
    } while (confirm_retry());
}

// もう一度、起動するかどうかの確認
inline bool menu::confirm_retry() const {

    int retry;
    std::cout << " もう一度、起動しますか？" << '\n'
              << " Yes ... 1 / No ...  0 : ";
    std::cin >> retry;

    if (retry == 1) {

        std::cout << "起動" << "\n\n";
        return static_cast<bool>(retry);
    }
    if (retry == 0) {

        std::cout << "終了" << "\n\n";
        return static_cast<bool>(retry);
    }
    else {

      std::cout << "入力が不正です。" << '\n';
      std::exit(1);
    }
}

// もう一度、ファイルを開くか、どうかの確認
inline bool menu::retry_file() const {

    int retry;
    std::cout << " もう一度、ファイルを開きますか？\n"
              << " Yes ... 1 / No ... 0 : ";
    std::cin >> retry;

    if (retry == 1) {

        std::cout << " ファイル名を入力してください " << "\n\n";
        return static_cast<bool>(retry);
    }
    if (retry == 0) {

        std::cout << " ファイル選択 終了 " << "\n\n";
        return static_cast<bool>(retry);
    }
    else {

        std::cout << "入力が不正です" << '\n';
        std::exit(1);
     }
}

// 繰り返す
inline void menu::repeat(void(*fit)(void)) const {

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

#endif
