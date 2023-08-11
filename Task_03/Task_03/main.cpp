#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#define PI 3.1415926
#define y 180

//std::function
void Sin(double x) {
	std::cout << "sin: " << sin(x) << " ";
}

void Cos(double x) {
	std::cout << "cos: " << cos(x) << " ";
}

//������� �� �������� � �������:
//������� * ��/180
double get_radian(int angle) {
	return angle * PI / y;
}

int main() {

	setlocale(LC_ALL, "ru");

	double angels[3]{ 30, 60, 90 };
	std::vector<std::function<void(double)>> functions = {Sin, Cos};
	std::cout << "[������� ������]: ";

	for (const auto& el : angels) {
		std::cout << el << "*" << PI << " / " << y << ", ";
	}
	std::cout << "// ������� �� �������� � �������" << std::endl;

	int i = 0;
	for (const auto& el : angels) {
		angels[i++] = get_radian(el);
		//std::cout << el << std::endl;
	}
	
	std::cout << "[�������� ������]:" << std::endl;

	auto res = [angels, functions]() {
		for (const auto& angle : angels) {
			std::cout << angle << ": ";
			for (const auto& function : functions)
				function(angle);
			std::cout << std::endl;
		}
	};

	res();
	
	return 0;
}