#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

void read(std::istream& in, std::vector<std::string>& text)
{
	std::string line;
	while (std::getline(in, line))
		text.push_back(line);
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}

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
