#include <list>
#include "Comp.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	

	list<Comp*>* a;

	int number = 0;

	cout << "������� ������� ��������" << endl;
	cin >> number;

	a = new list<Comp*>;

	while (number > 0) {

		cout << "�����" << endl;
		string author;
		cin >> author;

		a->insert(a->begin(), new Comp(author));

		--number;
	}


	number = a->size();

	cout << "������� ������� ��������" << endl;

	cin >> number;

	while (number > 0) {
		a->erase(a->begin());
		--number;
	}


	for (auto it = a->begin(); it != a->end(); ++it) {
		(*it)->Get_brand();
	}




	return 0;
}