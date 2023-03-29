/* [5 kyu] Primes in numbers

    Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

    "(p1**n1)(p2**n2)...(pk**nk)"
    with the p(i) in increasing order and n(i) empty if n(i) is 1.

    Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*/
#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

class PrimeDecomp
{
    public:
        static std::string factors(int lst);
        static int nextPrime(int currentPrime);
        static bool isPrime(int n);
        static std::string createString(std::vector<int> primes);
};

std::string PrimeDecomp::factors(int lst)
{
    std::vector<int> primes;

    int decomp = lst;
    int currentPrime = 2;
    while (true) {
        if (decomp == 1) break;
        if (decomp % currentPrime == 0) {
            std::cout << decomp << " % " << currentPrime << ": " << decomp % currentPrime << std::endl;
            decomp /= currentPrime;
            primes.push_back(currentPrime);
            std::cout << "thisPrime" << std::endl;
            currentPrime = 2;
        } else {
            std::cout << decomp << " % " << currentPrime << ": " << decomp % currentPrime << std::endl;
            currentPrime = nextPrime(currentPrime);
            std::cout << "nextPrime" << std::endl;
        }

        std::cout << "Current Prime: " << currentPrime << std::endl;
        std::cout << "Decomp: " << decomp << std::endl;
        std::cout << std::endl;

        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return createString(primes);
}

int PrimeDecomp::nextPrime(int currentPrime)
{
    while (true) {
        currentPrime++;
        if (isPrime(currentPrime)) return currentPrime;
    }
}

bool PrimeDecomp::isPrime(int n) {
    for (int i = n - 1; i > 1; i--) {
        if (n % i == 0) return false;
    }
    return true;
}

std::string PrimeDecomp::createString(std::vector<int> primes)
{
    std::map<int, int> frequency;

    for (int i : primes) {
        std::cout << i << " -> ";
    }
    std::cout << std::endl;

    for (int i = 0; i < primes.size(); i++) {
        int prime = primes[i];
        if (frequency.find(prime) == frequency.end()) {
            frequency[prime] = 0;
        }

        frequency[prime]++;
    }

    std::string str;
    for (std::map<int, int>::iterator itr = frequency.begin(); itr != frequency.end(); itr++) {
        std::ostringstream stringStream;
        if (itr->second == 1) {
            stringStream << "(" << itr->first << ")";
            str.append(stringStream.str());
        } else {
            stringStream << "(" << itr->first << "**" << itr->second << ")";
            str.append(stringStream.str());
        }
    }

    return str;
}

int main()
{
    std::cout << PrimeDecomp::factors(933555431) << std::endl;
    // std::cout << PrimeDecomp::createString({2, 2, 2, 4});
    // return 0;

    // int n = 50;
    // std::cout << "Is prime?" << std::endl;

    // for (int i = 0; i < 100; i++) {
    //     std::cout << i << ": ";
    //     if (PrimeDecomp::isPrime(i)) {
    //         std::cout << "True";
    //     } else {
    //         std::cout << "False";
    //     }
    //     std::cout << std::endl;
    // }

    // return 0;
}