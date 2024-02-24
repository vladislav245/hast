#pragma once

#include "Comp.h"

template <typename T>
class List {

public:

	class Store;

	//����������� ��� ����������
	List() {
		store = new Store;
	}


	//��������� ������ �� ������� �������
	void InsertAt(T obj, int ind) {

		//��������� �� ������ ����������
		Store* ptr = store->Next;

		if (ind < 0) {
			std::cout << "������ �� ����� ���� ������ 0" << std::endl;
		}

		//���� ������� 1-�� ������
		if (ind == 0) {

			Store* tmp = new Store(obj);
			tmp->Next = ptr;
			tmp->Back = nullptr;

			if(ptr != nullptr && ptr->Back != nullptr) ptr->Back = tmp;

			store->Next = tmp;
			return;
		}

		//�����
		while (ind - 1 > 0) {
			if (ptr == nullptr) {
				std::cout << "������ ������ ��������� ������ �����" << std::endl;
				return; // ������� �� �������
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr) {
			std::cout << "������ ������ ��������� ������ �����" << std::endl;
			return; // ������� �� �������
		}

		Store* tmp = new Store(obj);

		//��������� ���� ��������
		if (ptr->Next != nullptr) {
			ptr->Next->Back = tmp;
		}
		tmp->Next = ptr->Next;
		tmp->Back = ptr;
		ptr->Next = tmp;

		//��� ��������� � ������
		step = store->Next;
	}

	//������� ������
	void DeleteAt(int ind) {

		if (ind < 0) {
			std::cout << "������ �� ����� ���� ������ 0" << std::endl;
		}

		if (store->Next == nullptr) {
			std::cout << "���� ����" << std::endl;
			return;
		}

		Store* ptr = store->Next;

		//���� ������� 1-�� ������
		if (ind == 0) {
			if(ptr->Next != nullptr) store->Next = ptr->Next;
			ptr->Back = nullptr;
			if(ptr->Next != nullptr) ptr->Next->Back = nullptr;
			
			return;
		}
		
		//�����
		while (ind - 1 > 0) {
			if (ptr->Next == nullptr) {
				std::cout << "������ ������ ��������� ������ �����" << std::endl;
				return; // ������� �� �������
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr || ptr->Next == nullptr) {
			std::cout << "������ ������ ��������� ������ �����" << std::endl;
			return; // ������� �� �������
		}


		if (ptr->Next->Next != nullptr) {
			ptr->Next->Next->Back = ptr;
		}
		ptr->Next = ptr->Next->Next;
	}

	//������� ������ ������
	T Get_First() {
		return step->obj;
	}

	//������� ��������� ������ ����� ����������, ���� �� ���� � ������
	T Get_Next(T obj) {
		if (step->Next == nullptr) {
			std::cout << "���� ����������" << std::endl;
			step = store->Next;
			return nullptr;
		}
		return (step = step->Next)->obj;
	}

	void Draw() {

		Store* tmp = store->Next;


		if (store->Next == nullptr) {
			std::cout << "���� ����" << std::endl;
			return;
		}

		while (1) {

			if (tmp == nullptr) break;

			std::cout << tmp->Get_obj() << std::endl;
			tmp = tmp->Next;
		}
	}

	~List() {

		while (store != nullptr && store->Next != nullptr) {
			delete store;
			store = nullptr;
			step = nullptr;
		}
	}





	class Store {
	public:
		T obj;
		Store* Next;
		Store* Back;

		//����������� ��� ����������
		Store() {
			Next = nullptr;
			Back = nullptr;
		}

		//����������� � ����������
		Store(T obj) {
			this->obj = obj;
			Next = nullptr;
			Back = nullptr;
		};

		~Store() {
			if (Back != nullptr) Back = nullptr;
			Next = nullptr;
		}

		T Get_obj() { return obj; };
	};


	Store* store; //��������� ����� ������
	Store* step;  //���������� ��� ������� GetNext (������ �������� �� �����)
};
