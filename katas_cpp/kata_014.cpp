/* [7 kyu] Is this a triangle?

    Implement a function that accepts 3 integer values a, b, c. The function should return true if a triangle can be built with the sides of given length and false in any other case.

    (In this case, all triangles must have surface greater than 0 to be accepted).
*/
#include <iostream>

namespace Triangle
{
    bool isTriangle(unsigned int a, unsigned int b, unsigned int c)
    {
        std::cout << "a + b > c " << (a + b > c) << std::endl;
        std::cout << "a: " << a << " | b: " << b << " |+| " << (a + b) << std::endl;
        if (
            a + b > c &&
            b + c > a &&
            c + a > b
        ) return true;
        return false;
    }
}