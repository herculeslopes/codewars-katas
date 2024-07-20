/* [6 kyu] Backwards Read Primes

    Backwards Read Primes are primes that when read backwards in base 10 (from right to left) are a different prime. (This rules out primes which are palindromes.)

    Examples:
    13 17 31 37 71 73 are Backwards Read Primes
    13 is such because it's prime and read from right to left writes 31 which is prime too. Same for the others.

    Task
    Find all Backwards Read Primes between two positive given numbers (both inclusive), the second one always being greater than or equal to the first one. The resulting array or the resulting string will be ordered following the natural order of the prime numbers.

    Examples (in general form):
    backwardsPrime(2, 100) => [13, 17, 31, 37, 71, 73, 79, 97] backwardsPrime(9900, 10000) => [9923, 9931, 9941, 9967] backwardsPrime(501, 599) => []

    See "Sample Tests" for your language.

    Notes
    Forth Return only the first backwards-read prime between start and end or 0 if you don't find any
    Ruby Don't use Ruby Prime class, it's disabled.
*/
#include <string>
#include <iostream>
#include <cmath>

bool isPrime(int number)
{
    // Slow
    // for (int i = 2; i <= number / 2; i++)

    // Fast
    for (int i = 2; i <= std::sqrt(number); i++)
    {
        std::cout << number << " - " << number % i << std::endl;
        // remainder is 0
        if (!(number % i)) return false;
    }
    return true;
}

bool isBackwardsNonPalindromePrime(int number)
{
    std::string strNumber = std::to_string(number);
    std::string backwards = "";

    for (int i = strNumber.size() - 1; i >= 0; i--)
    {
        backwards += strNumber[i];
    }

    if (backwards == strNumber) return false;

    return isPrime(std::stoi(backwards));
}

class BackWardsPrime
{
public:
  static std::string backwardsPrime(long long start, long long end);
};

std::string BackWardsPrime::backwardsPrime(long long start, long long end) {
    std::cout << "Start: " << start << " | End: " << end << std::endl;

    std::string finalString = "";

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i) && isBackwardsNonPalindromePrime(i))
        {
            finalString += " " + std::to_string(i);
        }
    }
    
    return finalString.substr(1, finalString.size() - 1);
}

int main()
{
    std::string backwards = BackWardsPrime::backwardsPrime(50, 100);
    std::cout << "Backwards: " << backwards << std::endl;
    
    if (isPrime(9968)) std::cout << "This number is prime" << std::endl;
    else std::cout << "This number is not prime" << std::endl;
    
    return 0;
}



/*

#include <string>
#include <iostream>

bool isPrime(int number)
{
    for (int i = 2; i <= number / 2; i++)
    {
        // remainder is 0
        if (!(number % i)) return false;
    }
    return true;
}

bool isPalindromePrime(int number)
{
    std::string strNumber = std::to_string(number);
    std::string palindrome = "";

    for (int i = strNumber.size() - 1; i >= 0; i--)
    {
        palindrome += strNumber[i];
    }

    std::cout << "Palindrome: " << palindrome << " Size: " << palindrome.size() << std::endl;
    return isPrime(std::stoi(palindrome));
}

class BackWardsPrime
{
public:
  static std::string backwardsPrime(long long start, long long end);
};

std::string BackWardsPrime::backwardsPrime(long long start, long long end) {
    std::cout << "Start: " << start << " | End: " << end << std::endl;

    std::string finalString = "";

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i) && isPalindromePrime(i))
        {
            finalString += " " + std::to_string(i);
        }
    }
    
    return finalString.substr(1, finalString.size() - 1);
}
*/