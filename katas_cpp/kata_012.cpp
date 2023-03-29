/* [8 kyu] Twice as old

    Your function takes two arguments:

    current father's age (years)
    current age of his son (years)
    Сalculate how many years ago the father was twice as old as his son (or in how many years he will be twice as old).
*/
#include <iostream>

int twice_as_old(int dad, int son)
{
    int years;
    int d = dad;
    int s = son;
    if (dad / 2.0 < son) {
        // Was twice as old
        for (s; s > 0; s--, d--) {
            std::cout << "S: " << s << " | D: " << d << std::endl;
            if (d / 2.0 == s) return years;
            years++;
        } 
    } else if (dad / 2.0 > son) {
        // Will be twice as old
        while (true) {
            d++; s++; years++;
            if (d / 2.0 == s) return years;
        }
    } else {
        // Is twice as old
        return 0;
    }
}

int main()
{
    std::cout << twice_as_old(40, 25);
    return 0;
}