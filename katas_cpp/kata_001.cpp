/*[ 8 kyu] Reversed Strings
    Complete the solution so that it reverses the string passed into it.

    'world'  =>  'dlrow'
    'word'   =>  'drow'

*/ 

#include <iostream>
#include <string>

using namespace std;

string reverseString(string str)
{
    string reversedString;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedString += str[i];
    }
    return reversedString;
}

int main()
{
    string str = "oi";
    cout << reverseString(str);

    return 0;
}