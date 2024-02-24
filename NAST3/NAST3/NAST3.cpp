#include "Comp.h"
#include "List.cpp"


using namespace std;

template <typename T>
bool func_more(T* obj1, T* obj2) {
	return obj1->brand > obj2->brand;
}

template <typename T>
bool func_less(T* obj1, T* obj2) {
	return obj1->brand <= obj2->brand;
}


int main() {
	setlocale(LC_ALL, "Russian");

	/*Comp* t[6];

	t[0] = new Derived1();
	t[0]->Input();

	t[1] = new Derived1();
	t[1]->Input();

	t[2] = new Derived2();
	t[2]->Input();

	t[3] = new Derived2();
	t[3]->Input();

	t[4] = new Derived3();
	t[4]->Input();

	t[5] = new Derived3();
	t[5]->Input();

	for (int i = 0; i < 6; i++) {
		t[i]->Output();
		delete t[i];
	}*/


	Comp* a = new Comp("Nastya");
	Comp* b = new Comp("Dasha");
	Comp* c = new Comp("Katya");

	cout << "a <= b = " << func_less(a, b) << endl;
	cout << "b <= a = " << func_less(b, a) << endl;
	cout << "b <= c = " << func_less(b, c) << endl;
	cout << "c <= b = " << func_less(c, b) << endl;

	cout << "c > b = " << func_more(c, b) << endl;
	cout << "a > c = " << func_more(a, c) << endl;
	cout << "b > a = " << func_more(b, a) << endl;
	cout << "a > b = " << func_more(a, b) << endl << endl;


	// // // // //


	List<char*>* list = new List<char*>;

	char* aa = new char[] {"Nastya"};
	char* bb = new char[] {"Katya"};
	char* cc = new char[] {"Dasha"};
	char* dd = new char[] {"Oleg"};
	list->InsertAt(aa, 0);
	list->InsertAt(bb, 1);
	list->InsertAt(cc, 2);
	list->InsertAt(dd, 3);
	list->DeleteAt(2);
	list->DeleteAt(0);

	list->Draw();
	std::cout << std::endl;
	delete list;

	// // // // //


	List<int>* list2 = new List<int>;

	int* aaa = new int(0);
	int* bbb = new int(1);
	int* ccc = new int(2);
	int* ddd = new int(3);
	list2->InsertAt(*aaa, 0);
	list2->InsertAt(*bbb, 1);
	list2->InsertAt(*ccc, 1);
	list2->InsertAt(*ddd, 0);

	list2->Draw();
	std::cout << std::endl;
	delete list2;

	// // // // //

	Comp* aaaa = new Comp("Nastya");
	Comp* bbbb = new Comp("Katya");
	Comp* cccc = new Comp("Dasha");
	Comp* dddd = new Comp("Oleg");

	List<Comp>* list3 = new List<Comp>;
	list3->InsertAt(*aaaa, 0);
	list3->InsertAt(*bbbb, 1);
	list3->InsertAt(*cccc, 2);
	list3->InsertAt(*dddd, 3);

	list3->Draw();
	std::cout << std::endl;

	list3->DeleteAt(0);
	list3->DeleteAt(2);

	list3->Draw();
	std::cout << std::endl;

	delete list3;

	getchar();
	getchar();
	return 0;
}
