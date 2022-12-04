#pragma once
#include <iostream>

template <typename T>
class MyList {
	struct Node
	{
		T val;
		Node* next;
		Node(const T& count) :val(count), next(nullptr){}
	};
	Node* first;
	Node* last;
	size_t size;
public:
	MyList() :first(nullptr), last(nullptr), size(0) {}
	explicit MyList(const T& val);
	explicit MyList(const size_t& count, const T& val);
	~MyList();
	bool is_empty()const;
	void push_back(const T& val);
	void push_front(const T& val);
	size_t get_size()const { return size; }
	void erase(const size_t& pos);
	void insert(const size_t& pos, size_t count, const T& val);
	void insert(const size_t& pos, const T& val);
	void print()const;
};


template <typename T>
MyList<T>::MyList(const T& val) :MyList() {
	first = last = new Node(val);
	size += 1;
}
template <typename T>
MyList<T>::MyList(const size_t& count, const T& val) :MyList() {
	if (count == 0)
		return;
	first = last = new Node(val);
	Node* temp = first;
	size = 1;
	while (size < count) {
		temp->next = new Node(val);
		temp = temp->next;
		size += 1;
	}
	last = temp;
}

template <typename T>
MyList<T>::~MyList() {
	Node* temp = first;
	Node* buf=nullptr;
	while (temp->next != nullptr) {
		buf = temp->next;
		delete temp;
		temp = buf;
	}
}

template <typename T>
bool MyList<T>::is_empty()const {
	return (first == nullptr);
}

template <typename T>
void MyList<T>::push_back(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		size += 1;
		return;
	}
	last->next = temp;
	last = temp;
	size += 1;
}

template <typename T>
void MyList<T>::push_front(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		return;
	}
	temp->next = first;
	first = temp;
	size += 1;
}

template <typename T>
void MyList<T>::erase(const size_t& pos) {
	Node* temp = first;
	Node* n=nullptr;
	size_t i = 2;
	while (i < pos) {
		temp = temp->next;
		i++;
	}
	n=temp->next;
	temp->next = n->next;
	delete n;
	size -= 1;
}

template <typename T>
void MyList<T>::insert(const size_t& pos, size_t count, const T& val) {
	Node* temp = nullptr;
	Node* n = nullptr;
	if (count == 0)
		return;
	if (is_empty()) {
		first = last = new Node(val);
		temp = first;
		size = 1;
		while (size < count) {
			temp->next = new Node(val);
			temp = temp->next;
			size += 1;
		}
		last = temp;
	}
	else {
		temp = first;
		size_t i = 2;	//отсчет со второго элемента
		while (i != pos) {
			temp = temp->next;
			i++;
		}
		n = temp->next;
		for (i = 0; i < count; ++i) {
			temp->next = new Node(val);
			temp = temp->next;
			size++;
		}
		temp->next = n;
	}
}

template <typename T>
void MyList<T>::insert(const size_t& pos, const T& val) {
	Node* temp = nullptr;
	Node* n = nullptr;
	if (is_empty() || pos == size)
		push_back(val);
	else {
		temp = first;
		size_t i = 2;	//отсчет со второго элемента
		while (i < pos) {
			temp = temp->next;
			i++;
		}
		n = new Node(val);
		n->next = temp->next;
		temp->next = n;
	}
	size += 1;
}

template <typename T>
void MyList<T>::print()const {
	Node* temp = first;
	do {
		std::cout << temp->val << " ";
		temp = temp->next;
	} while (temp != nullptr);
	std::cout << std::endl;
}
