#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cfenv>
#include <climits>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::fesetround(FE_TONEAREST);
    std::cout << "rounding to nearest (halfway cases to even):\n"
        << "rint(+2.3) = " << std::rint(2.3)
        << "  rint(+2.5) = " << std::rint(2.5)
        << "  rint(+3.5) = " << std::rint(3.5) << '\n'
        << "rint(-2.3) = " << std::rint(-2.3)
        << "  rint(-2.5) = " << std::rint(-2.5)
        << "  rint(-3.5) = " << std::rint(-3.5) << '\n';

    std::fesetround(FE_DOWNWARD);
    std::cout << "rounding down:\n"
        << "rint(+2.3) = " << std::rint(2.3)
        << "  rint(+2.5) = " << std::rint(2.5)
        << "  rint(+3.5) = " << std::rint(3.5) << '\n'
        << "rint(-2.3) = " << std::rint(-2.3)
        << "  rint(-2.5) = " << std::rint(-2.5)
        << "  rint(-3.5) = " << std::rint(-3.5) << '\n'
        << "rounding down with lrint\n"
        << "lrint(+2.3) = " << std::lrint(2.3)
        << "  lrint(+2.5) = " << std::lrint(2.5)
        << "  lrint(+3.5) = " << std::lrint(3.5) << '\n'
        << "lrint(-2.3) = " << std::lrint(-2.3)
        << "  lrint(-2.5) = " << std::lrint(-2.5)
        << "  lrint(-3.5) = " << std::lrint(-3.5) << '\n';

    std::cout << "lrint(-0.0) = " << std::lrint(-0.0) << '\n'
        << "lrint(-Inf) = " << std::lrint(-INFINITY) << '\n';

    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "std::rint(0.1) = " << std::rint(.1) << '\n';

    if (std::fetestexcept(FE_INEXACT)) {
        std::cout << "    FE_INEXACT was raised\n";
    }
        
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "std::lrint(LONG_MIN-2048.0) = " << std::lrint(LONG_MIN - 2048.0) << '\n';
    
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID was raised\n";
    }

    _getch();
    return 0;
}