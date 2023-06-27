#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void sortArray_of_names(std::string *array_of_names, int number_of_names)
{
	for (int startIndex = 0; startIndex < number_of_names; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < number_of_names;
			++currentIndex)
		{
			if (array_of_names[currentIndex] < array_of_names[smallestIndex])
				smallestIndex = currentIndex;
		}

			std::swap(array_of_names[startIndex], array_of_names[smallestIndex]);
	}
}



int main()
{
	int number_of_names;
	do
	{
		std::cout << "How many names would you like to enter? ";
		std::cin >> number_of_names;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}
	while (number_of_names < 1 || number_of_names > 1000000);

	std::string *array_of_names = new std::string[number_of_names];

	for (int i = 0; i < number_of_names; i++)
	{
		std::cout << "Enter name #" << (i + 1) << ": ";
		std::cin >> array_of_names[i];
	}

	sortArray_of_names(array_of_names, number_of_names);

	std::cout << "\nHere is your sorted list:\n";
	for (int i = 0; i < number_of_names; i++)
	{
		std::cout << "Name #" << (i + 1) << ": " << array_of_names[i] << "\n";
	}

	delete[] array_of_names;
	array_of_names = nullptr;

return 0;
}
