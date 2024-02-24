#include "comp.h"

Comp::Comp() {
	brand = "";
	memorySize = 0;
}

void Comp::Input() {
	std::cout << "----------------------------" << std::endl;
	std::cout << "������� ����� ����������:" << std::endl;
	std::cin >> brand;
	std::cout << "������� ������ ������:" << std::endl;
	std::cin >> memorySize;
}

void Comp::Output() const {
	std::cout << "����� ����������: " << brand << std::endl;
	std::cout << "������ ������: " << memorySize << std::endl;
}


std::ostream& operator << (std::ostream& os, const Comp* obj)
{
	return os << obj->brand;
}