#include "iostream"
#include "ImplVector.h"
#include "ImplList.h"

namespace conteiners {
	template <typename T>
	void print(ImplVector <T>& v) {
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}


	void vector() {
		std::cout << "������ � ����������� vector" << std::endl;
		std::cout << "������������� ������� ������� � ���������� ����� push_back" << std::endl;
		ImplVector <int> vec1;
		ImplVector <int> vec2;
		for (int i = 0; i < 10; ++i) {
			vec1.push_back(i);
			vec2.push_back(i * 2);
		}
		print(vec1);
		std::cout << vec1.size() << std::endl;

		std::cout << "�������� ��������, ������ � �������� ��������" << std::endl;
		vec1.erase(3);
		std::cout << vec1.size() << std::endl;
		vec1.erase(4);
		std::cout << vec1.size() << std::endl;
		vec1.erase(5);
		std::cout << vec1.size() << std::endl;
		print(vec1);

		std::cout << "���������� �������� 10 � ������ �������" << std::endl;
		vec1.insert(1, 10);
		print(vec1);

		std::cout << "���������� ����� 20 � �������� ����������" << std::endl;
		vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
		print(vec1);

		std::cout << "���������� �������� 30 � ����� �������" << std::endl;
		vec1.push_back(30);
		print(vec1);
		std::cout << std::endl;

		std::cout << "��������� Vec1 " << std::endl;
		print(vec1);
		std::cout << "��������� Vec2 " << std::endl;
		print(vec2);
		std::cout << "����������� Vec1 �������� Vec2 � ������� ��������� Vec1" << std::endl;
		vec1 = vec2;
		print(vec1);
		print(vec2);
		std::cout << "����������� � Vec1 �������� Vec2 � ������� ��������� Vec1" << std::endl;
		vec1 = std::move(vec2);
		print(vec1);
		std::cout << "Size Vec2= " << vec2.size() << std::endl;

	}

	void listCont() {
		std::cout << "������ � ����������� list" << std::endl;
		std::cout << "������������� ������� ����������" << std::endl;
		ImplList <int> lst2;
		std::cout << lst2.get_size() << std::endl;
		std::cout << "������������� ������������ ��� �������� n int ����� �� ��������� 3" << std::endl;
		ImplList <int>lst(5, 3);
		std::cout << "������ ����������" << std::endl;
		std::cout << "Size = " << lst.get_size() << std::endl;
		lst.print();

		std::cout << "������������� ������� ���������� int � ���������� ����� push_back" << std::endl;
		ImplList <int>lst1;
		lst1.push_back(2);
		lst1.push_back(3);
		lst1.push_back(4);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� 2 � ������� 3" << std::endl;
		lst1.insert(3, 2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� � ������� 2 ������� ��������� 1" << std::endl;
		lst1.insert(2, 4, 1);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� � ������ ������" << std::endl;
		lst1.push_front(10);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "�������� 2-��� �������� �� ������" << std::endl;
		lst1.erase(2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();
		std::cout << std::endl;
	}


	void iterVec() {
		std::cout << "������ � ����������� ���������� vector" << std::endl;
		ImplVector <int> vec1;
		ImplVector <int>::Iterator it_ptr;
		for (int i = 0; i < 10; ++i)
			vec1.push_back(i);
		for (it_ptr = vec1.begin(); it_ptr != vec1.end(); ++it_ptr)
			std::cout << *it_ptr << " ";
	}

	void comparison() {
		ImplList <int>lst1;
		ImplList <int>lst2;
		for (int i = 0; i < 10; ++i) {
			lst1.push_back(i);
			lst2.push_back(i);
		}
		lst1.print();
		lst2.print();
		std::cout << (lst1 == lst2) << std::endl;
	}
}

int main() {
	system("chcp 1251>null");
	conteiners::vector();
	conteiners::listCont();
	conteiners::iterVec();
	//NEW
	conteiners::comparison();


	return 0;
}


