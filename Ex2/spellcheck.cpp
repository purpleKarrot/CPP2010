#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

typedef std::set<std::string> string_set;

void read_words(const char* filename, string_set& words)
{
	std::ifstream file(filename);

	std::copy(std::istream_iterator<std::string>(file), // begin
			std::istream_iterator<std::string>(), // end
			std::insert_iterator<string_set>(words, words.begin()));
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "incorrect number of arguments!" << std::endl;
		return 0;
	}

	string_set dict;
	string_set test;

	read_words(argv[1], dict);
	read_words(argv[2], test);

	std::set_difference(test.begin(), test.end(), dict.begin(), dict.end(),
			std::ostream_iterator<std::string>(std::cout, "\n"));
}
