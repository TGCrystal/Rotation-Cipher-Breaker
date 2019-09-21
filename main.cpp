#include <iostream>
#include <iomanip>
#include <string>

int main() {
	std::string input;
	while(true) {
		char letters[26];
		std::cout << "Enter encoded string: ";
		std::cin >> input;
		for(unsigned int i = 0; i < input.length(); i++) {
			char letter = input[i];
			if(letter >= 'a' && letter <= 'z') {
				letters[letter-'a']++;
			}
		}
	}

}