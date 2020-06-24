#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

template<class T>
class my_list {
private:
	class node {
	public:
		T value{ 0 };
		node* linkNext{ nullptr };

		explicit node(T val, node* link = nullptr) {
			value = val;
			linkNext = link;
		}

		~node() = default;
	};

	node* head{ nullptr };
	size_t size{ 0 };

public:
	my_list() = default;
	my_list(const std::initializer_list<T>& list);
	~my_list();
	void PushBack(T data);
	void PushFront(T data);
	int Count();
	T PopBack();
	T PopFront();
	void Insert(T value, int index);
	void Erase(int index);
	bool contains(my_list<T>& list);
	my_list<T>& maxMin();

	T* Begin() {
		return &head->value;
	}

	T* End() {
		node* current = head;
		while (current->linkNext != nullptr) {
			current = current->linkNext;
		}
		return &current->value;
	}

	T& operator[] (int index);

	friend bool operator> (const my_list<T>& m, const my_list<T>& m2) {
		node* cur1 = m.head;
		node* cur2 = m2.head;

		while ((cur1->linkNext != nullptr) && (cur2->linkNext != nullptr)) {
			if (cur1->value < cur2->value) return false;
			if (cur1->value > cur2->value) return true;
			cur1 = cur1->linkNext;
			cur2 = cur2->linkNext;
		}

		if (cur1->value > cur2->value) return true;
		if (cur1->value < cur2->value) return false;
		return (m.size > m2.size);
	}

	friend bool operator== (const my_list<T>& m, const my_list<T>& m2) {
		node* cur1 = m.head;
		node* cur2 = m2.head;

		while ((cur1->linkNext != nullptr) && (cur2->linkNext != nullptr)) {

			if (cur1->value != cur2->value) {
				return false;
			}

			cur1 = cur1->linkNext;
			cur2 = cur2->linkNext;
		}
		if (cur1->value != cur2->value) {
			return false;
		}
		return (m.size == m2.size);
	}

	friend bool operator>= (const my_list<T>& m, const my_list<T>& m2) {
		return ((m > m2) || (m == m2));
	}

	friend bool operator<= (const my_list<T>& m, const my_list<T>& m2) {
		return !(m > m2);
	}

	friend bool operator!= (const my_list<T>& m, const my_list<T>& m2) {
		return !(m == m2);
	}

	friend bool operator<(const my_list<T>& m, const my_list<T>& m2) {
		return !(m >= m2);
	}

	friend std::ostream& operator<< (std::ostream& out, const my_list<T>& m) {
		if (m.head == nullptr) throw std::out_of_range("List is empty");
		node* current = m.head;

		out << "( ";
		while (current->linkNext != nullptr) {
			out << current->value << ", ";
			current = current->linkNext;
		}
		out << current->value << " )";

		return out;
	};

};


template<typename T>
my_list<T>::my_list(const std::initializer_list<T>& list) {
	for (int i = 0; i < list.size(); i++) {
		PushBack(list.begin()[i]);
	}
}

template<typename T>
my_list<T>::~my_list() {
	while (size) {
		PopFront();
	}
	head = nullptr;
}

template<class T>
void my_list<T>::PushBack(T data) {
	if (head == nullptr) {
		head = new node(data);
	}
	else {
		node* current = this->head;

		while (current->linkNext != nullptr) {
			current = current->linkNext;
		}
		current->linkNext = new node(data);
	}

	size++;
}

template<class T>
int my_list<T>::Count() {
	return size;
}

template<class T>
void my_list<T>::PushFront(T data) {
	if (head == nullptr) {
		head = new node(data);
	}
	else {
		node* current = new node(data, head);
		head = current;
	}
	size++;
}

template<class T>
T my_list<T>::PopBack() {
	if (head == nullptr) throw std::out_of_range("list is empty");

	node* del = nullptr;
	node* current = this->head;
	T ret;

	while (current->linkNext != nullptr) {
		del = current;
		current = current->linkNext;
	}

	if (del != nullptr) del->linkNext = nullptr;
	ret = current->value;
	delete current;
	size--;
	if (size == 0) head = nullptr;

	return ret;
}

template<class T>
T my_list<T>::PopFront() {
	if (head == nullptr) throw std::out_of_range("list is empty");
	node* del = head;
	T ret = head->value;
	head = head->linkNext;
	delete del;
	size--;
	if (size == 0) head = nullptr;

	return ret;
}

template<class T>
T& my_list<T>::operator[](int index) {
	if (index >= size) throw std::out_of_range("index is more then size of list");
	if (index < 0) throw std::out_of_range("index will be positive number");

	int count = 0;
	node* current = head;

	while (current != nullptr) {
		if (count == index) {
			return current->value;
		}
		current = current->linkNext;
		count++;
	}
	throw std::out_of_range("out of range");
}

template<class T>
void my_list<T>::Insert(T value, int index) {
	if (index >= size) throw std::out_of_range("index is more then size of list");
	if (index < 0) throw std::out_of_range("index will be positive number");

	if (index == 0) {
		PushFront(value);
	}
	else {
		node* prev = head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev->linkNext;
		}
		node* nextNode = new node(value, prev->linkNext);
		prev->linkNext = nextNode;

		size++;
	}

}

template<class T>
void my_list<T>::Erase(int index) {
	if (index >= size) throw std::out_of_range("index is more then size of list");
	if (index < 0) throw std::out_of_range("index will be positive number");

	if (index == 0) {
		PopFront();
	}
	else {
		node* prev = head;
		node* del = nullptr;
		for (int i = 0; i < index - 1; i++) {
			prev = prev->linkNext;
		}
		del = prev->linkNext;
		prev->linkNext = del->linkNext;
		delete del;
		size--;
	}
	if (size == 0) head = nullptr;

}

template<class T>
bool my_list<T>::contains(my_list<T>& list) {
	if (list.size == 0)
		return true;
	node* tNode = head;
	node* lNode = list.head;

	int k = 0;
	for (int i = 0; i < size; i++) {
		if (tNode->value == lNode->value) {
			k++;
			if (k == list.size) {
				return true;
			}

			lNode = lNode->linkNext;
		}
		else {
			k = 0;
			lNode = list.head;
		}

		tNode = tNode->linkNext;
	}

	return false;
}

template<class T>
my_list<T>& my_list<T>::maxMin() {

	if (size < 2) {
		throw std::exception("Not enough elements");
	}

	my_list<T>* res = new my_list<T>();

	size_t max_i = 0, min_i = 0;
	T max = std::numeric_limits<T>::min(), min = std::numeric_limits<T>::max();

	node* h = head;

	for (int i = 0; i < size; i++) {
		if (h->value > max) {
			max = h->value;
			max_i = i;
		}

		if (h->value < min) {
			min = h->value;
			min_i = i;
		}

		h = h->linkNext;
	}

	this->Erase(min_i);
	if (min_i != max_i) {
		this->Erase(max_i - (max_i > min_i ? 1 : 0));
	}

	res->PushBack(min);
	res->PushBack(max);

	return *res;
}
#endif