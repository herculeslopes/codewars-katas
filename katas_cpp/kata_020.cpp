/* [7 kyu] String ends with?

	Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

	Examples:

	solution('abc', 'bc') // returns true
	solution('abc', 'd') // returns false
*/

#include <iostream>

bool solution(std::string const &str, std::string const &ending) {
    int i, j = 0;

    for (i = ending.length() - 1, j = str.length() - 1; i >= 0; i--, j--) {
      if (str[j] != ending[i]) return false;
    }

	return true;
}

int main()
{
	std::cout << "Does it end with: " << solution("abc", "abc") << std::endl;

	return 0;
}
