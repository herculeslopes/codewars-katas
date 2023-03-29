/* [8 kyu] String repeat

    Write a function called repeatStr which repeats the given string string exactly n times.

    repeat_str(6, "I") // "IIIIII"
    repeat_str(5, "Hello") // "HelloHelloHelloHelloHello"
*/
#include <string>

std::string repeat_str(size_t repeat, const std::string& str)
{
    std::string repeated;
    for (int i = 0; i < repeat; i++) {
        repeated.append(str);
    }
    return repeated;
}

int main()
{
    return 0;
}