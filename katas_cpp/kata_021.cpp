/* [6 kyu] Roman Numerals Decoder
    Create a function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer. You don't need to validate the form of the Roman numeral.

    Modern Roman numerals are written by expressing each decimal digit of the number to be encoded separately, starting with the leftmost digit and skipping any 0s. So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) and 2008 is rendered "MMVIII" (2000 = MM, 8 = VIII). The Roman numeral for 1666, "MDCLXVI", uses each letter in descending order.

    Example:

    solution("XXI"); // => 21
    Help:

    Symbol    Value
    I          1
    V          5
    X          10
    L          50
    C          100
    D          500
    M          1,000
    Courtesy of rosettacode.org
*/

#include <iostream>
#include <string>

using namespace std;

int romanToDecimal(char r) {
    switch (r)
    {
    case 'I':
        return 1;
    
    case 'V':
        return 5;

    case 'X':
        return 10;

    case 'L':
        return 50;
    
    case 'C':
        return 100;

    case 'D':
        return 500;

    case 'M':
        return 1000;
    
    default:
        return 0;
    }
}

int solution(string roman) {
    // for (int i = 0; i < roman.length(); i++) {
    //     cout << roman[i];
    // }
    int total = 0;
    int i = 0;
    while (i < roman.length())
    {
        char romanNumeral = roman[i];
        int romanValue = romanToDecimal(romanNumeral);

        cout << "[i] = " << i << endl;
        cout << "Watching: " << roman[i] << " " << romanToDecimal(roman[i]) << endl;
        cout << endl;

        int ii = i;
        int numeralCount = 0;
        int subTotal = 0;

        while (ii < roman.length())
        {
            cout << "roman[i] = " << romanNumeral << endl;
            cout << "roman[ii] = " << roman[ii] << endl;
            
            if (romanValue == romanToDecimal(roman[ii])) {
                numeralCount++;
                subTotal += romanValue;
            }
            else if (romanValue < romanToDecimal(roman[ii])) {
                subTotal = romanToDecimal(roman[ii]) - subTotal;
                romanNumeral = roman[ii];
                romanValue = romanToDecimal(roman[ii]);
                
            } else {
                // i = ii - 1;
                // cout << "i = " <<i << endl;
                i--;
                break;
            }

            cout << "subtotal = " << subTotal << endl;
            cout << endl;

            i++;
            ii++;
        }
        
        // total += romanValue * numeralCount;
        total += subTotal;
        
        i++;
    }
    
    return total;
}

int main() {
    cout << solution("LV") << endl;
    
    return 0;
}