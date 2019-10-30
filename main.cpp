#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_set>

int main() {
	std::string input;
	std::unordered_set<std::string> dictionary;
	std::cout << "Enter dicitionary file name: ";
	std::cin >> input;
	std::ifstream dictionaryInput;
	dictionaryInput.open(input);
	while(dictionaryInput >> input)
		dictionary.insert(input);
	dictionaryInput.close();
	while(true) {
		std::cout << "Enter encoded string: ";
		std::getline(std::cin, input);
		bool solution = false;
		for(int i = 0; !solution && i < 26; i++) {
			solution = true;
			std::string word = "";
			bool validWordOverride = false; //dictionary doesn't contain words with ' or - so ignore those words
			for(unsigned int j = 0; j < input.length(); j++) {
				if(input[j] >= 'a' && input[j] <= 'z') {
					input[j] = ((input[j] - 'a' + 1) % 26) + 'a';
					word += input[j];
				}
				else if(input[j] == '\'' || input[j] == '-') {
					validWordOverride = true;
				}
				else if(input[j] == ' ') {
					if((dictionary.find(word) == dictionary.end()) && !validWordOverride)
						solution = false;
					validWordOverride = false;
					word = "";
				}
			}

		}
		if(!solution)
			std::cout << "no solution found" << std::endl;
		else
			std::cout << input << std::endl;
	}

}