#include <iostream>
#include <fstream>
#include <string>

void main()
{
	std::string filePath{ "Resources/Triangle.svg" };
	std::ifstream inStream{filePath};
	if (!inStream)
	{
		std::cout << "ERROR READING FILE" << std::endl;
		return;
	}

	std::string str{};
	std::string result{};
	while (inStream.good())
	{
		std::getline(inStream, str);
		result += str;
	}

	int idx{ int(result.find(" d=")) };
	do
	{
		++idx;
	} while (result.at(idx) != '"');
	++idx;

	while (size_t(idx) < result.size() && result.at(idx) != '"')
	{
		if (isalpha(result.at(idx)))
		{
			if (!isalpha(result.at(idx - 1)))
			{
				std::cout << '\n';
			}
			std::cout << '\n' << "Command: ";
		}

		if ((isdigit(result.at(idx)) || result.at(idx) == '-')&& !isdigit(result.at(idx - 1)) && !isalpha(result.at(idx)))
		{
			if (result.at(idx - 1) != ',' && result.at(idx - 1) != '.' && result.at(idx - 1) != '-')
			{
				std::cout << '[';
			}
		}
		if (result.at(idx) != ' ')
		{
			std::cout << result.at(idx);
		}
		if (isalpha(result.at(idx)))
		{
			std::cout << '\n';
		}
		if (isdigit(result.at(idx)) && !isdigit(result.at(idx + 1)) && !isalpha(result.at(idx)))
		{
			if (result.at(idx + 1) != ',' && result.at(idx + 1) != '.')
			{
				std::cout << ']' << '\n';
			}
		}
		++idx;
	}
	
	std::cin.get();
}