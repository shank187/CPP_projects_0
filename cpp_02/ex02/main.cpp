#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main()
{
    using std::cout;
    using std::endl;

    cout << "=== Constructing fixed‑point values ===" << endl;
    Fixed a;                         // default constructor
    Fixed const b( Fixed(5.05f) * Fixed(2) );   // float constructor + arithmetic *
    Fixed const c(10);               // int constructor
    Fixed const d(2.5f);             // float constructor
    Fixed e = d;                      // copy constructor via assignment‑init
    Fixed f;
    f = b;                            // copy assignment operator

    cout << endl << "=== Values and conversions ===" << endl;
    cout << "a = " << a << " (should be 0 or near‑zero)" << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e (copy of d) = " << e << endl;
    cout << "f (assigned from b) = " << f << endl;

    cout << "c.toInt() = " << c.toInt() << endl;
    cout << "d.toInt() = " << d.toInt() << endl;
    cout << "b.toFloat() = " << b.toFloat() << endl;

    cout << endl << "=== Arithmetic operator tests (+, -, *, /) ===" << endl;
    cout << "c + d = " << (c + d) << endl;
    cout << "c - d = " << (c - d) << endl;
    cout << "d * Fixed(2) = " << (d * Fixed(2)) << endl;
    cout << "c / d = " << (c / d) << endl;

    cout << endl << "=== Comparison operator tests (>, <, >=, <=, ==, !=) ===" << endl;
    cout << "Is c > d ? " << (c > d ? "true" : "false") << endl;
    cout << "Is c < d ? " << (c < d ? "true" : "false") << endl;
    cout << "Is c >= d ? " << (c >= d ? "true" : "false") << endl;
    cout << "Is c <= d ? " << (c <= d ? "true" : "false") << endl;
    cout << "Is c == d ? " << (c == d ? "true" : "false") << endl;
    cout << "Is c != d ? " << (c != d ? "true" : "false") << endl;

    cout << endl << "=== Increment / Decrement operator tests ===" << endl;
    Fixed g;
    cout << "g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "g = " << g << endl;

    cout << endl << "=== min / max static methods ===" << endl;
    cout << "min(c, d) = " << Fixed::min(c, d) << endl;
    cout << "max(c, d) = " << Fixed::max(c, d) << endl;
    cout << "min(f, b) = " << Fixed::min(f, b) << endl;
    cout << "max(f, b) = " << Fixed::max(f, b) << endl;

    cout << endl << "=== Edge / Extra cases ===" << endl;
    try {
        Fixed const zero(0);
        cout << "zero = " << zero << endl;
        cout << "c / zero = "; 
        cout << (c / zero) << endl;  // watch for division by zero
    } catch (...) {
        cout << "Caught an exception (division by zero?)" << endl;
    }

    Fixed const negative(-3);
    cout << "negative = " << negative << endl;
    cout << "negative + d = " << (negative + d) << endl;
    cout << "negative * Fixed(-2) = " << (negative * Fixed(-2)) << endl;

    cout << endl << "=== End of tests ===" << endl;
    return 0;
}
