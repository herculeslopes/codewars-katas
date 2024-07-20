/* [4 kyu] Roman Numerals Helper

    Write two functions that convert a roman numeral to and from an integer value. Multiple roman numeral values will be tested for each function.

    Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

    Input range : 1 <= n < 4000

    In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").

    Examples
    to roman:
    2000 -> "MM"
    1666 -> "MDCLXVI"
    1000 -> "M"
    400 -> "CD"
    90 -> "XC"
    40 -> "XL"
    1 -> "I"

    from roman:
    "MM"      -> 2000
    "MDCLXVI" -> 1666
    "M"       -> 1000
    "CD"      -> 400
    "XC"      -> 90
    "XL"      -> 40
    "I"       -> 1
    Help
    Symbol	Value
    I	1
    IV	4
    V	5
    X	10
    L	50
    C	100
    D	500
    M	1000
*/

#include <iostream>
#include <string>

class RomanHelper
{
public:
    static int romanCharValue(char rc)
    {
        switch (rc)
        {
        case 'M':
            return 1000;

        case 'D':
            return 500;

        case 'C':
            return 100;
        
        case 'L':
            return 50;

        case 'X':
            return 10;

        case 'V':
            return 5;

        case 'I':
            return 1;
        
        default:
            return 0;
        }
    }

    std::string to_roman(unsigned int n)
    {
        std::cout << "Integer: " << n << std::endl;
      
        std::string romanNumeral = "";
        
        if (n / 1000)
        {
            int n_1000 = n / 1000;
            std::cout << "n % 1000 >>> " << n / 1000 << std::endl;
            romanNumeral += std::string(n_1000, 'M');
            n -= 1000 * n_1000;
        }
        // if (n % 500)
        // {
        //     int n_500 = n % 500;
        //     romanNumeral += std::string(n_500, 'D');
        //     n -= 500 * n_500;

        // }
        if (n / 100)
        {
            int n_100 = n / 100;

            if (n_100 <= 3) {
                romanNumeral += std::string(n_100, 'C');
            } else if (n_100 == 4) {
                romanNumeral += "CD";
            } else if (n_100 == 5) {
                romanNumeral += "D";
            } else if (n_100 <= 7) {
                romanNumeral += "D" + std::string(n_100 - 5, 'C');
            } else {
                romanNumeral += "CM";
            }
            
            n -= 100 * n_100;
        }

        if (n / 10)
        {
            int n_10 = n / 10;

            if (n_10 <= 3) {
                romanNumeral += std::string(n_10, 'X');
            } else if (n_10 == 4) {
                romanNumeral += "XL";
            } else if (n_10 == 5) {
                romanNumeral += "L";
            } else if (n_10 <= 7) {
                romanNumeral += "L" + std::string(n_10 - 5, 'X');
            } else {
                romanNumeral += "XC";
            }

            n -= 10 * n_10;
        }

        if (n) {
            if (n <= 3) {
                romanNumeral += std::string(n, 'I');
            } else if (n == 4) {
                romanNumeral += "IV";
            } else if (n == 5) {
                romanNumeral += "V";
            } else if (n <= 7) {
                romanNumeral += "V" + std::string(n - 5, 'I');
            } else {
                romanNumeral += "IX";
            }
        }
        return romanNumeral;
    }
    static int from_roman(std::string rn)
    {
        int totalRomanValue = 0;
        int i = 0;
        
        while (i < rn.length())
        {
            char romanChar = rn[i];
            int romanCharValue = RomanHelper::romanCharValue(romanChar);

            int ii = i;
            int equalCharCount = 0, subTotal = 0;

            while (ii < rn.length())
            {
                if (romanCharValue == RomanHelper::romanCharValue(rn[ii]))
                {
                    equalCharCount++;
                    subTotal += romanCharValue;
                } else if (romanCharValue < RomanHelper::romanCharValue(rn[ii]))
                {
                    subTotal = RomanHelper::romanCharValue(rn[ii]) - subTotal;
                    romanChar = rn[ii];
                    romanCharValue = RomanHelper::romanCharValue(rn[ii]);
                } else
                {
                    i--;
                    break;
                }
            }

            totalRomanValue += subTotal;
            i++;
        }
        
        return totalRomanValue;
    }
} RomanNumerals;


int main()
{
    int value = RomanHelper::from_roman("III");
    
    std::cout << "Value: " << value << std::endl;
    
    return 0;
}
