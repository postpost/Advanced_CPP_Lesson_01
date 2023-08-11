#include <iostream>
#include <vector> //vector is a collection of the objects
#include <algorithm>
//auto

struct Str {
	int uno;
	int dos;
	int tres;
};

int add(int a, int b) {
	return a + b;
}

int main() {
	//lambda
	std::vector<int> array = { 4, 7, 9, 14, 12};

	auto print{ [](const int& num) {
		std::cout << num << '\t';
		}
	};
	std::cout << "before: ";
	std::for_each(array.cbegin(), array.cend(), print);
	
	std::cout << "\nafter: ";
	int ind = 0;
	std::for_each(array.begin(), array.end(), [array, ind](auto& n) mutable
		{
			if (ind % 2 != 0) //ind - index in vector
				n *=3;		  //n - element value of the vector
			ind++;
		}
	);

	std::for_each(array.cbegin(), array.cend(), print);
	return 0;
}