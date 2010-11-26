#include "persistent.hpp"
#include <algorithm>

bool approve(const std::string& word)
{
	char c = 0;
	for (;;)
	{
		std::cout << "the word '" << word << "' "
			"does not exist in the dictionary. insert it? (y/n)";

		std::cin >> c;

		if (c == 'y')
			return true;

		if (c == 'n')
			return false;
	}
}

void adjust(std::string& word)
{
	std::cout << "please adjust the word: '" << word << "': ";
	std::cin >> word;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "incorrect number of arguments!" << std::endl;
		return 0;
	}

	pset<std::string> dict(argv[1]);
	pvector<std::string> test(argv[2]);

	typedef pvector<std::string>::iterator iterator;
	for (iterator i = test.begin(); i != test.end(); ++i)
	{
		if (dict.find(*i) != dict.end())
			continue;

		if (approve(*i))
		{
			dict.insert(*i);
		}
		else
		{
			adjust(*i);
			--i;
		}
	}
}
