/* [8 kyu] Convert a Number to a String!

    We need a function that can transform a number into a string.

    What ways of achieving this do you know?

    Examples:
    123 --> "123"
    999 --> "999"
*/

#include <iostream>
#include <string>

std::string number_to_string(int num)
{
    std::string s = std::to_string(num);
    return s;
}

int main()
{
    std::cout << number_to_string(45);

    return 0;
}