#include "comp.h"

Comp::Comp() {
	brand = "";
	memorySize = 0;
}

void Comp::Input() {
	std::cout << "----------------------------" << std::endl;
	std::cout << "Введите марку компьютера:" << std::endl;
	std::cin >> brand;
	std::cout << "Введите размер памяти:" << std::endl;
	std::cin >> memorySize;
}

void Comp::Output() const {
	std::cout << "Марка компьютера: " << brand << std::endl;
	std::cout << "Размер памяти: " << memorySize << std::endl;
}


std::ostream& operator << (std::ostream& os, const Comp* obj)
{
	return os << obj->brand;
}