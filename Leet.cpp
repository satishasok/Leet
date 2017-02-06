#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

#include "Input.h"
#include "LeetGenerator.h"

using namespace std;

int main (int argc, char *argv[])
{
	// Part 1. Read the entire input of digits in to text. If the command line names a file,
	// read that file. Otherwise, read the Standard input.
	std::vector<std::string> digits; /// < Store the lines of text here;
	if (argc < 2) {
		read(std::cin, digits);
	}
	else
	{
		std::ifstream in(argv[1]);
		if (not in) {
			std::perror(argv[1]);
			return EXIT_FAILURE;
		}
		read(in, digits);
	}

	for(int i=0; i < digits.size(); i++) {
		cout << "Words possible For Digits: " << digits[i] << endl;

		vector<string> result = letterCombinations(digits[i]);

		std::copy(result.begin(), result.end(),
			std::ostream_iterator<std::string>(std::cout, "\n"));
	}

}
