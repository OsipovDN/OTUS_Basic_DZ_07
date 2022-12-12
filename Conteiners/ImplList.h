#pragma once
#include <iostream>

template <typename T>
class ImplList {
	struct Node {
		T val;
		Node* next;
		Node(const T& count) :val(count), next(nullptr) {}
	};
	Node* first;
	Node* last;
	size_t size;
public:
	ImplList() :first(nullptr), last(nullptr), size(0) {}
	explicit ImplList(const T& val);
	ImplList(const size_t& count, const T& val);
	~ImplList();
	bool is_empty()const;
	void push_back(const T& val);
	void push_front(const T& val);
	size_t get_size()const { return size; }
	void erase(const size_t& pos);
	void insert(const size_t& pos, size_t count, const T& val);
	void insert(const size_t& pos, const T& val);
	//NEW
	bool operator ==(const ImplList& obj)const;
	void print()const;
	
};


template <typename T>
ImplList<T>::ImplList(const T& val) :ImplList() {
	first = last = new Node(val);
	size += 1;
}
template <typename T>
ImplList<T>::ImplList(const size_t& count, const T& val) : ImplList() {
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
ImplList<T>::~ImplList() {
	if (first != nullptr) {
		Node* temp = first;
		Node* buf = nullptr;
		while (temp->next != nullptr) {
			buf = temp->next;
			delete temp;
			temp = buf;
		}

		temp = nullptr;
	}
}

template <typename T>
bool ImplList<T>::is_empty()const {
	return (first == nullptr);
}

template <typename T>
void ImplList<T>::push_back(const T& val) {
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
void ImplList<T>::push_front(const T& val) {
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
void ImplList<T>::erase(const size_t& pos) {
		Node* temp = first;
		Node* n = nullptr;
		size_t i = 2;
		if (pos == 1) {
			first = temp->next;
			delete temp;
			size -= 1;
		}
		else {
			while (i < pos) {
				temp = temp->next;
				i++;
			}
			n = temp->next;
			temp->next = n->next;
			delete n;
			size -= 1;
		}
}

template <typename T>
void ImplList<T>::insert(const size_t& pos, size_t count, const T& val) {
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
		while (i <pos) {
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
void ImplList<T>::insert(const size_t& pos, const T& val) {
	Node* temp = nullptr;
	Node* n = nullptr;
	if (is_empty()) {
		push_back(val);
	}
	else if (pos == 1) {
		push_front(val);
	}
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
		size += 1;
	}
}

template <typename T>
bool ImplList<T> ::operator ==(const ImplList& obj)const {
	Node* comp1=first;
	Node* comp2=obj.first;
	if (get_size() != obj.get_size()) 
		return false;
	while (comp1 != nullptr && comp2 != nullptr) {
		if (comp1->val != comp2->val)
			return false;
		comp1 = comp1->next;
		comp2 = comp2->next;
	}
	return true;
}

template <typename T>
void ImplList<T>::print()const {
	Node* temp = first;
	do {
		std::cout << temp->val << " ";
		temp = temp->next;
	} while (temp != nullptr);
	std::cout << std::endl;
}
