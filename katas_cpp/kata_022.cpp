/* [6 kyu] Valid Braces

    Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

    This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

    All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

    What is considered Valid?
    A string of braces is considered valid if all braces are matched with the correct brace.

    Examples
    "(){}[]"   =>  True
    "([{}])"   =>  True
    "(}"       =>  False
    "[(])"     =>  False
    "[({})](]" =>  False
*/

#include <iostream>
#include <string>

// typedef struct Node {
//     char brace;
//     Node* under;
// } Node;

// Node* push(Node** under,char brace) {
//     Node* highest = new Node();
//     highest->brace = brace;
//     highest->under = *under;
//     *under = highest;
// }

char getCloseChar(char brace) {
    switch (brace)
    {
        case '(':
            return ')';
        
        case '[':
            return ']';

        case '{':
            return '}';
            
        default:
          return '0';
    }
}

bool isOpenChar(char brace) {
    switch (brace)
    {
        case '(':
        case '[':
        case '{':
            return true;

        default:
            return false;
    }
}

bool valid_braces(std::string braces) 
{

    std::cout << "String: " << braces << std::endl << std::endl;
    char bracesStack[braces.length()];

    int stack = 0;
    for (std::string::size_type i = 0; i < braces.length(); i++)
    {
        char c = braces[i];

        if (i > 0) {
            if (getCloseChar(bracesStack[stack]) == c)
            {
                // std::cout << "Fechamento de braces" << std::endl;
                bracesStack[stack] = (char) 0;
                stack--;
              
            } else if (isOpenChar(c))
            {
                // std::cout << "Abertura de braces" << std::endl;
              
                stack++;
                bracesStack[stack] = c;
            } else {
                return false;
            }
            
        } else {
            // std::cout << "Abertura de braces inicial" << std::endl;          
            bracesStack[0] = c;
        }
    }
  
    std::cout << bracesStack[0] << std::endl;

    if (!bracesStack[0]) return true;
    else return false;
    
    // int parentheses = 0, square = 0, curly = 0;
    // char parent;
    // for (char& c : braces)
    // {
    //     // If all are 0
    //     if (!parentheses && !square && !curly)
    //     {
    //         parent = c;
    //     }
        
    //     switch (c)
    //     {
    //     case '(':
    //         parentheses++;
    //         break;
        
    //     case ')':
    //         parentheses--;
    //         break;

    //     case '[':
    //         square++;
    //         break;
        
    //     case ']':
    //         square--;
    //         break;

    //     case '{':
    //         curly++;
    //         break;

    //     case '}':
    //         curly--;
    //         break;
        
    //     default:
    //         break;
    //     }
        
    //     if (parentheses < 0 || square < 0 || curly < 0) return false;
        
    //     std::cout << c << " ";
    // }

    // if (parentheses != 0 || square != 0 || curly != 0) return false;
  // valid or not valid?
}

int main()
{
    
    valid_braces("Hello world");
    return 0;
}