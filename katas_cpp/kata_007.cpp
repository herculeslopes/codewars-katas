/* [8 kyu] Convert a string to an array

	Write a function to split a string and convert it into an array of words.

	Examples (Input -> Output):
	* "Robin Singh" ==> ["Robin", "Singh"]

	* "I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> string_to_array(const std::string& s)
{
	std::string word;
	std::vector<std::string> words;
	for (char c : s) {
		std::cout << c << " -> ";
		if (c == ' ') {
			std::cout << "This is a space" << std::endl;
			words.push_back(word);
			word = "";
		} else {
			word.append(std::string(1, c));
		}
	}
	words.push_back(word);

	return words;
}

int main()
{
	std::string str = "This is a phrase example";
	string_to_array(str);
	return 0;
}
