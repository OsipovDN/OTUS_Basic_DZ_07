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
		std::cout << "Работа с контейнером vector" << std::endl;
		std::cout << "Инициализация пустого вектора и заполнение через push_back" << std::endl;
		ImplVector <int> vec1;
		ImplVector <int> vec2;
		for (int i = 0; i < 10; ++i) {
			vec1.push_back(i);
			vec2.push_back(i * 2);
		}
		print(vec1);
		std::cout << vec1.size() << std::endl;

		std::cout << "Удаление третьего, пятого и седьмого элемента" << std::endl;
		vec1.erase(3);
		std::cout << vec1.size() << std::endl;
		vec1.erase(4);
		std::cout << vec1.size() << std::endl;
		vec1.erase(5);
		std::cout << vec1.size() << std::endl;
		print(vec1);

		std::cout << "Добавление элемента 10 в начало вектора" << std::endl;
		vec1.insert(1, 10);
		print(vec1);

		std::cout << "Добавление числа 20 в середину контейнера" << std::endl;
		vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
		print(vec1);

		std::cout << "Добавление элемента 30 в конец вектора" << std::endl;
		vec1.push_back(30);
		print(vec1);
		std::cout << std::endl;

		std::cout << "Контейнер Vec1 " << std::endl;
		print(vec1);
		std::cout << "Контейнер Vec2 " << std::endl;
		print(vec2);
		std::cout << "Присваиваем Vec1 значения Vec2 и выводим контейнер Vec1" << std::endl;
		vec1 = vec2;
		print(vec1);
		print(vec2);
		std::cout << "Перемещение в Vec1 значений Vec2 и выводим контейнер Vec1" << std::endl;
		vec1 = std::move(vec2);
		print(vec1);
		std::cout << "Size Vec2= " << vec2.size() << std::endl;

	}

	void listCont() {
		std::cout << "Работа с контейнером list" << std::endl;
		std::cout << "Инициализация пустого контейнера" << std::endl;
		ImplList <int> lst2;
		std::cout << lst2.get_size() << std::endl;
		std::cout << "Инициализация конструктора для создания n int узлов со значением 3" << std::endl;
		ImplList <int>lst(5, 3);
		std::cout << "Размер контейнера" << std::endl;
		std::cout << "Size = " << lst.get_size() << std::endl;
		lst.print();

		std::cout << "Инициализация пустого контейнера int и заполнение через push_back" << std::endl;
		ImplList <int>lst1;
		lst1.push_back(2);
		lst1.push_back(3);
		lst1.push_back(4);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "Добавление элемента 2 в позицию 3" << std::endl;
		lst1.insert(3, 2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "Добавление в позицию 2 четырех элементов 1" << std::endl;
		lst1.insert(2, 4, 1);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "Добавление элемента в начало списка" << std::endl;
		lst1.push_front(10);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "Удаление 2-ого элемента из списка" << std::endl;
		lst1.erase(2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();
		std::cout << std::endl;
	}


	void iterVec() {
		std::cout << "Работа с итераторами контейнера vector" << std::endl;
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


