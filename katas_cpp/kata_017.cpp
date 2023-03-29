/* [6 kyu] The Vowel Code

    Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:

    a -> 1
    e -> 2
    i -> 3
    o -> 4
    u -> 5
    For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

    Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.

    For example, decode("h3 th2r2") would return "hi there".

    For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.
*/

#include <iostream>
#include <string>

std::string encode(const std::string &str)
{   
    std::string encoded_str;

    for (char c : str) {
        std::cout << c << " -> ";
        switch (c) {
            case 'a':
                encoded_str += '1';
                break;

            case 'e':
                encoded_str += '2';
                break;
            
            case 'i':
                encoded_str += '3';
                break;

            case 'o':
                encoded_str += '4';
                break;

            case 'u':
                encoded_str += '5';
                break;

            default:
                encoded_str += c;
        }
    }

    return encoded_str;
}

std::string decode(const std::string &str)
{
    std::string decoded_str;

    for (char c : str) {
        std::cout << c << " -> ";
        switch (c) {
            case '1':
                decoded_str += 'a';
                break;

            case '2':
                decoded_str += 'e';
                break;
            
            case '3':
                decoded_str += 'i';
                break;

            case '4':
                decoded_str += 'o';
                break;

            case '5':
                decoded_str += 'u';
                break;

            default:
                decoded_str += c;
        }
    }

    return decoded_str;
}

int main()
{
    encode("Hello");
    return 0;
}