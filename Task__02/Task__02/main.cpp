#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable) 
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main() {
	 
	auto result = get_variant();

	if (std::holds_alternative<int>(result)) {
		std:: cout << std::get<int>(result) * 2;
	}
	else if (std::holds_alternative<std::string>(result)) {
		std::cout << std::get<std::string>(result);
	}
	else if (std::holds_alternative<std::vector<int>>(result)) 
	{
		auto print = [](const int& n) {std::cout << n << '\t'; };
		auto res = std::get<std::vector<int>>(result);
		std::for_each(res.begin(), res.end(), print);
	}
	//std::variant <std::string> x("abc");
	return 0;
}