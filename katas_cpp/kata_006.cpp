/* [8 kyu] Beginner Series #4 Cockroach]

    The cockroach is one of the fastest insects. Write a function which takes its speed in km per hour and returns it in cm per second, rounded down to the integer (= floored).

    For example:

    1.08 --> 30
    Note! The input is a Real number (actual type is language dependent) and is >= 0. The result should be an Integer.
*/

#include <iostream>

int cockroach_speed(double s)
{
    std::cout << "OG: " << s << std::endl;

    int cm_hour = s * 100000;
    int cm_second = cm_hour / 3600;

    return cm_second;
}

int main()
{
    return 0;
}