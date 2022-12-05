#pragma once

template <typename T>
class ImplVector {
public:
	
	class Iterator {
	private:
		ImplVector<T>* cont;
		size_t index;
	public:
		
		Iterator() {
			cont = nullptr;
			index = 0;
		}
		T& operator*();
		bool operator==(const Iterator obj)const;
		bool operator!=(const Iterator obj)const;
		Iterator operator +(int val);
		Iterator operator-(int val);
		Iterator operator++();
		Iterator operator--();
		friend Iterator ImplVector<T>::begin();
		friend Iterator ImplVector<T>::end();
	};

	ImplVector();
	ImplVector(size_t count, const T& val);
	explicit ImplVector(const ImplVector <T>& obj);
	~ImplVector() {
		delete[]v_ptr;
	}
	void insert(size_t pos, int count, const T& val);
	void insert(size_t pos, const T& val);
	void push_back(const T& val);
	void erase(size_t pos);
	size_t size()const { return size_vec; }
	T& operator [](const size_t pos)const { return v_ptr[pos]; }
	ImplVector <T>& operator =(const  ImplVector <T>& obj);
	bool operator ==(const ImplVector <T>& obj)const;

	Iterator begin();
	Iterator end();
private:
	T* v_ptr;
	size_t size_vec;
};

template <typename T>
ImplVector<T>::ImplVector() :v_ptr(nullptr), size_vec(0) {}

template <typename T>
ImplVector<T>::ImplVector(size_t count, const T& val) : ImplVector() {
	size_vec = count;
	v_ptr = new T[size_vec];
	for (size_t i = 0; i < size_vec; ++i) {
		v_ptr[i] = val;
	}
}
template <typename T>
ImplVector<T>::ImplVector(const ImplVector <T>& obj) {
	delete[]v_ptr;
	v_ptr = new T[obj.size()];
	size_vec = obj.size();
	for (size_t i = 0; i < size_vec; ++i) {
		v_ptr[i] = obj[i];
	}
}

template <typename T>
void  ImplVector<T>::insert(size_t pos, int count, const T& val) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	T* res_v = new T[size_vec + count];
	for (size_t i = 0; i < pos; ++i) {
		res_v[i] = v_ptr[i];
	}
	for (size_t i = pos; i < (pos+ count); ++i) {
		res_v[i] = val;
	}
	for (size_t i = (pos + count); i < (size_vec + count); ++i) {
		res_v[i] = v_ptr[i - count];
	}
	delete[]v_ptr;
	v_ptr = res_v;
	size_vec += count;
}

template <typename T>
void  ImplVector<T>::insert(size_t pos, const T& val) {
	insert((pos-1), 1, val);
}

template <typename T>
void  ImplVector<T>::push_back(const T& val) {
	insert(size_vec, 1, val);
}
template <typename T>
void  ImplVector<T>::erase(size_t pos) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	T* res_v = new T[size_vec - 1];
	for (size_t i = 0; i < pos; ++i) {
		res_v[i] = v_ptr[i];
	}
	for (size_t i = (pos-1); i < size_vec; ++i) {
		res_v[i] = v_ptr[i + 1];
	}
	delete[]v_ptr;
	v_ptr = res_v;
	size_vec--;
}

template <typename T>
typename ImplVector<T>::Iterator ImplVector<T>::begin() {
	ImplVector<T>::Iterator p;
	p.index = 0;
	p.cont = this;
	return p;
}
template <typename T>
typename ImplVector< T>::Iterator ImplVector<T>::end() {
	ImplVector<T>::Iterator p;
	p.index = size();
	p.cont = this;
	return p;
}
template <typename T>
typename ImplVector <T>& ImplVector<T>::operator =(const  ImplVector <T>& obj) {
	delete[]v_ptr;
	v_ptr = new T[obj.size()];
	size_vec = obj.size();
	for (size_t i = 0; i < size_vec; ++i) {
		v_ptr[i] = obj[i];
	}
	return *this;
}

template <typename T>
bool ImplVector<T>::operator ==(const ImplVector <T>& obj)const {
	if (size_vec != obj.size_vec)
		retrn false;
	for (size_t i = 0; i < size_vec; ++i) {
		if (v_ptr[i] != obj[i])
			return false;
	}
	return true;
}

template <typename T>
T& ImplVector<T>::Iterator::operator*() {
	return (*cont)[index];
}
template <typename T>
bool ImplVector<T>::Iterator::operator==(const Iterator obj)const {
	if ((index == obj.index) || (cont == obj.cont)) 
		return true;
	return false;
}
template <typename T>
bool ImplVector<T>::Iterator::operator!=(const Iterator obj)const {
	if (index != obj.index || cont != obj.cont) 
		return true;
	return false;
}
template <typename T>
typename ImplVector<T>::Iterator ImplVector<T>::Iterator::operator +(int val) {
	int ind = index + val;
	Iterator p;
	p.cont = cont;
	if (ind > cont->size())
		ind = cont->size();
	p.index = ind;
	return p;
}
template <typename T>
typename ImplVector<T>::Iterator ImplVector<T>::Iterator::operator-(int val) {
	int ind = index - val;
	Iterator p;
	p.cont = cont;
	if (ind < 0)
		ind = 0;
	p.index = ind;
	return p;
}
template <typename T>
typename ImplVector<T>::Iterator ImplVector<T>::Iterator::operator++() {
	index++;
	if (index > cont->size())
		index = cont->size();
	return *this;
}

template <typename T>
typename ImplVector<T>::Iterator ImplVector<T>::Iterator::operator--() {
	index--;
	if (index < 0)
		index = 0;
	return *this;
}

