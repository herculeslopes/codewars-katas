/* [8 kyu] Convert number to reversed array of digits

    Convert number to reversed array of digits
    Given a random non-negative number, you have to return the digits of this number within an array in reverse order.
'
    Example:
    348597 => [7,9,5,8,4,3]
    0 => [0]
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<int> digitize_1(unsigned long n)
{
    std::string strNum = std::to_string(n);
    std::vector<int> reverseNum;
    // std::vector<char> reverseNum;

    for (char& c : strNum)
    {
        std::cout << c << " -> ";
        // reverseNum.insert(reverseNum.begin(), c);
        reverseNum.insert(reverseNum.begin(), c - '0');
    }

    std::cout << std::endl;
    std::cout << "OG Value: " << n << std::endl;
    
    // for (char& c : reverseNum)
    // {
    //     std::cout << c << " -> ";
    // }

    return reverseNum;

}

int main()
{
    std::cout << "Hello World" << std::endl;
    digitize_1(348597);

    return 0;
}