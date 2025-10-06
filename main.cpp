#include <iostream>
#include "BitString.h"

int main() {
    BitString a{1, 0, 1, 1};
    BitString b{1, 1, 0, 0};

    BitString c = a.And(b);
    BitString d = a.Or(b);
    BitString e = a.Xor(b);
    BitString f = a.Not();

    std::cout << "a AND b: " << c.ToString() << "\n";
    std::cout << "a OR  b: " << d.ToString() << "\n";
    std::cout << "a XOR b: " << e.ToString() << "\n";
    std::cout << "NOT a  : " << f.ToString() << "\n";

    return 0;
}
