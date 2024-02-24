#pragma once

#include<iostream>
#include<cstring>
#include<clocale>

class Comp {
public:
	Comp();
	Comp(std::string brand) { this->brand = brand; };
	void Input();
	void Output() const;
	void Get_brand() const { std::cout << brand << std::endl; };


	~Comp() { };

	std::string brand;
private:
	int memorySize;


	friend std::ostream& operator << (std::ostream& os, const Comp* obj);
};