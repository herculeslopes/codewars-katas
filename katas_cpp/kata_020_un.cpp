/* [7 kyu] String ends with?

	Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

	Examples:

	solution('abc', 'bc') // returns true
	solution('abc', 'd') // returns false
*/

#include <iostream>

bool solution(std::string const &str, std::string const &ending) {
    std::cout << str << std::endl;
    std::cout << ending << std::endl;
  
    int i, j;
  
    for (i = ending.length() - 1, j = str.length() - 1; i > 0; i--, j--) {
      std::cout << str[j] << " == " << ending[i] << std::endl;
      if (str[j] != ending[i]) return false;
    }

	return true;
}

int main()
{
	std::cout << "Hello World" << std::endl;

	solution("abc", "bc");

	return 0;
}
