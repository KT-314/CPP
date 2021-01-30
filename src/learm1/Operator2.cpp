#include "prog.h"

void Operator2() {

    auto print = [](auto v) { std::cout << v << '\n'; };
    auto _ = [](auto str2, auto _2, auto str8, auto _8, auto str10, auto _10, auto str16, auto _16) {

        std::cout << str2  << std::setw(3)  << _2  << " | "
                  << str8  << std::setw(3)  << _8  << " | "
                  << str10 << std::setw(3)  << _10 << " | "
                  << str16 << std::setw(3)  << _16 << " | "
                  << std::endl;
    };

    print("\" >> \"右シフト演算子 (右に1、シフト)");
    print("          2進数                8進数          10進数       16進数");
    print("________________________________________________________________________");
    _("  0. 0b0000'0000 >> 1:", 0b0000'0000 >> 1, "000 >> 1:", 000 >> 1, " 0 >> 1:",  0 >> 1, "0x00 >> 1:", 0x00 >> 1);
    _("  1. 0b0000'0001 >> 1:", 0b0000'0001 >> 1, "001 >> 1:", 001 >> 1, " 1 >> 1:",  1 >> 1, "0x01 >> 1:", 0x01 >> 1);
    _("  2. 0b0000'0010 >> 1:", 0b0000'0010 >> 1, "002 >> 1:", 002 >> 1, " 2 >> 1:",  2 >> 1, "0x02 >> 1:", 0x02 >> 1);
    _("  3. 0b0000'0011 >> 1:", 0b0000'0011 >> 1, "003 >> 1:", 003 >> 1, " 3 >> 1:",  3 >> 1, "0x03 >> 1:", 0x03 >> 1);
    _("  4. 0b0000'0100 >> 1:", 0b0000'0100 >> 1, "004 >> 1:", 004 >> 1, " 4 >> 1:",  4 >> 1, "0x04 >> 1:", 0x04 >> 1);
    _("  5. 0b0000'0101 >> 1:", 0b0000'0101 >> 1, "005 >> 1:", 005 >> 1, " 5 >> 1:",  5 >> 1, "0x05 >> 1:", 0x05 >> 1);
    _("  6. 0b0000'0110 >> 1:", 0b0000'0110 >> 1, "006 >> 1:", 006 >> 1, " 6 >> 1:",  6 >> 1, "0x06 >> 1:", 0x06 >> 1);
    _("  7. 0b0000'0111 >> 1:", 0b0000'0111 >> 1, "007 >> 1:", 007 >> 1, " 7 >> 1:",  7 >> 1, "0x07 >> 1:", 0x07 >> 1);
    _("  8. 0b0000'1000 >> 1:", 0b0000'1000 >> 1, "010 >> 1:", 010 >> 1, " 8 >> 1:",  8 >> 1, "0x08 >> 1:", 0x08 >> 1);
    _("  9. 0b0000'1001 >> 1:", 0b0000'1001 >> 1, "011 >> 1:", 011 >> 1, " 9 >> 1:",  9 >> 1, "0x09 >> 1:", 0x09 >> 1);
    _(" 10. 0b0000'1010 >> 1:", 0b0000'1010 >> 1, "012 >> 1:", 012 >> 1, "10 >> 1:", 10 >> 1, "0x0A >> 1:", 0x0A >> 1);
    _(" 11. 0b0000'1011 >> 1:", 0b0000'1011 >> 1, "013 >> 1:", 013 >> 1, "11 >> 1:", 11 >> 1, "0x0B >> 1:", 0x0B >> 1);
    _(" 12. 0b0000'1100 >> 1:", 0b0000'1100 >> 1, "014 >> 1:", 014 >> 1, "12 >> 1:", 12 >> 1, "0x0C >> 1:", 0x0C >> 1);
    _(" 13. 0b0000'1101 >> 1:", 0b0000'1101 >> 1, "015 >> 1:", 015 >> 1, "13 >> 1:", 13 >> 1, "0x0D >> 1:", 0x0D >> 1);
    _(" 14. 0b0000'1110 >> 1:", 0b0000'1110 >> 1, "016 >> 1:", 016 >> 1, "14 >> 1:", 14 >> 1, "0x0E >> 1:", 0x0E >> 1);
    _(" 15. 0b0000'1111 >> 1:", 0b0000'1111 >> 1, "017 >> 1:", 017 >> 1, "15 >> 1:", 15 >> 1, "0x0F >> 1:", 0x0F >> 1);

    _(" 16. 0b0001'0000 >> 1:", 0b0001'0000 >> 1, "020 >> 1:", 020 >> 1, "16 >> 1:", 16 >> 1, "0x10 >> 1:", 0x10 >> 1);
    _(" 17. 0b0001'0001 >> 1:", 0b0001'0001 >> 1, "021 >> 1:", 021 >> 1, "17 >> 1:", 17 >> 1, "0x11 >> 1:", 0x11 >> 1);
    _(" 18. 0b0001'0010 >> 1:", 0b0001'0010 >> 1, "022 >> 1:", 022 >> 1, "18 >> 1:", 18 >> 1, "0x12 >> 1:", 0x12 >> 1);
    _(" 19. 0b0001'0011 >> 1:", 0b0001'0011 >> 1, "023 >> 1:", 023 >> 1, "19 >> 1:", 19 >> 1, "0x13 >> 1:", 0x13 >> 1);
    _(" 20. 0b0001'0100 >> 1:", 0b0001'0100 >> 1, "024 >> 1:", 024 >> 1, "20 >> 1:", 20 >> 1, "0x14 >> 1:", 0x14 >> 1);
    _(" 21. 0b0001'0101 >> 1:", 0b0001'0101 >> 1, "025 >> 1:", 025 >> 1, "21 >> 1:", 21 >> 1, "0x15 >> 1:", 0x15 >> 1);
    _(" 22. 0b0001'0110 >> 1:", 0b0001'0110 >> 1, "026 >> 1:", 026 >> 1, "22 >> 1:", 22 >> 1, "0x16 >> 1:", 0x16 >> 1);
    _(" 23. 0b0001'0111 >> 1:", 0b0001'0111 >> 1, "027 >> 1:", 027 >> 1, "23 >> 1:", 23 >> 1, "0x17 >> 1:", 0x17 >> 1);
    _(" 24. 0b0001'1000 >> 1:", 0b0001'1000 >> 1, "030 >> 1:", 030 >> 1, "24 >> 1:", 24 >> 1, "0x18 >> 1:", 0x18 >> 1);
    _(" 25. 0b0001'1001 >> 1:", 0b0001'1001 >> 1, "031 >> 1:", 031 >> 1, "25 >> 1:", 25 >> 1, "0x19 >> 1:", 0x19 >> 1);
    _(" 26. 0b0001'1010 >> 1:", 0b0001'1010 >> 1, "032 >> 1:", 032 >> 1, "26 >> 1:", 26 >> 1, "0x1A >> 1:", 0x1A >> 1);
    _(" 27. 0b0001'1011 >> 1:", 0b0001'1011 >> 1, "033 >> 1:", 033 >> 1, "27 >> 1:", 27 >> 1, "0x1B >> 1:", 0x1B >> 1);
    _(" 28. 0b0001'1100 >> 1:", 0b0001'1100 >> 1, "034 >> 1:", 034 >> 1, "28 >> 1:", 28 >> 1, "0x1C >> 1:", 0x1C >> 1);
    _(" 29. 0b0001'1101 >> 1:", 0b0001'1101 >> 1, "035 >> 1:", 035 >> 1, "29 >> 1:", 29 >> 1, "0x1D >> 1:", 0x1D >> 1);
    _(" 30. 0b0001'1110 >> 1:", 0b0001'1110 >> 1, "036 >> 1:", 036 >> 1, "30 >> 1:", 30 >> 1, "0x1E >> 1:", 0x1E >> 1);
    _(" 31. 0b0001'1111 >> 1:", 0b0001'1111 >> 1, "037 >> 1:", 037 >> 1, "31 >> 1:", 31 >> 1, "0x1F >> 1:", 0x1F >> 1);
    _(" 32. 0b0010'0000 >> 1:", 0b0010'0000 >> 1, "040 >> 1:", 040 >> 1, "32 >> 1:", 32 >> 1, "0x20 >> 1:", 0x20 >> 1);

    std::cout << "255. 0b0'1111'1111 >> 1: " << (0b0000'1111'1111 >> 1) << std::endl;
    std::cout << "256. 0b1'0000'0000 >> 1: " << (0b0001'0000'0000 >> 1) << std::endl;
}