#include <iostream>
#include <vector> //vector is a collection of the objects
#include <algorithm>


int main() {
	setlocale(LC_ALL, "ru");

	//lambda
	std::vector<int> array = { 4, 7, 9, 14, 12};

	auto print{ [](const int& num) {
		std::cout << num << '\t';
		}
	};
	std::cout << "Входные данные: ";
	std::for_each(array.cbegin(), array.cend(), print);
	std::for_each(array.begin(), array.end(), [](auto& n) 
		{
			if (n% 2 != 0) 
				n *=3;		
		}
	);
	std::cout << "\nВыходные данные: ";
	std::for_each(array.cbegin(), array.cend(), print);
	return 0;
}