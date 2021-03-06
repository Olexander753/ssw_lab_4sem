#ifndef LAB2V2_FORWARD_LIST_H
# define LAB2V2_FORWARD_LIST_H

template< class T>
class my_double_linked_list {
private:

	class node {
	public:
		T value{ 0 };
		node* linkNext{ nullptr };
		node* linkPrev{ nullptr };

		explicit node(T data, node* linkN = nullptr, node* linkP = nullptr) {
			value = data;
			linkNext = linkN;
			linkPrev = linkP;
		}
		~node() = default;
	};

	node* head{ nullptr };
	size_t size{ 0 };

public:

	my_double_linked_list() = default;
	my_double_linked_list(const std::initializer_list<T>& list);
	~my_double_linked_list();
	void PushFront(T data);
	void PushBack(T data);
	T PopFront();
	T PopBack();
	void Insert(T data, int index);
	void Erase(int index);
	T* Begin();
	T* End();
	bool contains(my_double_linked_list<T>& list);
	my_double_linked_list<T>& maxMin();

	int Count() {
		return size;
	}

	friend std::ostream& operator<< (std::ostream& out, const my_double_linked_list<T>& m) {
		if (m.head == nullptr) throw std::out_of_range("List is empty");
		node* current = m.head;

		out << " ( ";
		while (current->linkNext != nullptr) {
			out << current->value << " , ";
			current = current->linkNext;
		}
		out << current->value << ") ";
		return out;
	};

	friend bool operator>(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
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

	friend bool operator==(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
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

	friend bool operator>=(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
		return ((m > m2) || (m == m2));
	}

	friend bool operator<=(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
		return!(m > m2);
	}

	friend bool operator!=(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
		return!(m == m2);
	}

	friend bool operator<(const my_double_linked_list<T>& m, const my_double_linked_list<T>& m2) {
		return!(m >= m2);
	}
};

template< class T>
my_double_linked_list<T>::~my_double_linked_list() {
	while (size) {
		PopFront();
	}
	head = nullptr;
}

template< class T>
void my_double_linked_list<T>::PushFront(T data) {
	if (head == nullptr) {
		head = new node(data);
	}
	else {
		node* current = new node(data, head);
		head->linkPrev = current;
		head = current;
	}
	size++;
}

template< class T>
void my_double_linked_list<T>::PushBack(T data) {
	if (head == nullptr) {
		head = new node(data);
	}
	else {
		node* current = head;

		while (current->linkNext != nullptr) {
			current = current->linkNext;
		}

		current->linkNext = new node(data, nullptr, current);
	}
	size++;
}

template< class T>
T my_double_linked_list<T>::PopFront() {
	if (head == nullptr) throw std::out_of_range("forward list is empty");
	node* del = head;
	T ret = head->value;
	head = head->linkNext;

	if (head != nullptr) {
		head->linkPrev = nullptr;
	}
	delete del;
	size--;
	if (size == 0) head = nullptr;

	return ret;
}

template< class T>
T my_double_linked_list<T>::PopBack() {
	if (head == nullptr) throw std::out_of_range("forward list is empty");
	node* current = head;

	while (current->linkNext != nullptr) {
		current = current->linkNext;
	}
	node* prev = current->linkPrev;
	T ret;
	ret = current->value;
	if (prev != nullptr) {
		prev->linkNext = nullptr;
	}
	delete current;
	size--;
	if (size == 0) head = nullptr;

	return ret;
}

template< class T>
void my_double_linked_list<T>::Insert(T data, int index) {
	if (index >= size) throw std::out_of_range("index more then size of structure");
	if (index < 0) throw std::out_of_range("index will be positive number");

	if (index == 0) {
		PushFront(data);
	}
	else {
		node* current = head;
		node* next = nullptr;

		for (int i = 0; i < index - 1; i++) {
			current = current->linkNext;
		}

		next = current->linkNext;
		node* insert = new node(data, next, current);
		current->linkNext = insert;
		next->linkPrev = insert;
	}

	size++;
}

template< class T>
void my_double_linked_list<T>::Erase(int index) {
	if (index >= size) throw std::out_of_range("index more then size of structure");
	if (index < 0) throw std::out_of_range("index will be positive number");

	if (index == 0) {
		PopFront();
	}
	else {
		node* current = head;
		node* next = nullptr;
		node* prev = nullptr;
		for (int i = 0; i < index; i++) {
			current = current->linkNext;
		}
		next = current->linkNext;
		prev = current->linkPrev;
		prev->linkNext = next;
		if (next)
			next->linkPrev = prev;
		delete current;
		size--;
	}

}

template< class T>
my_double_linked_list<T>::my_double_linked_list(const std::initializer_list<T>& list) {
	for (int i = 0; i < list.size(); i++) {
		PushBack(list.begin()[i]);
	}
}

template< class T>
T* my_double_linked_list<T>::Begin() {
	return &head->value;
}

template< class T>
T* my_double_linked_list<T>::End() {
	node* current = head;
	while (current->linkNext != nullptr) {
		current = current->linkNext;
	}
	return &current->value;
}

template<class T>
bool my_double_linked_list<T>::contains(my_double_linked_list<T>& list) {
	if (list.size == 0)
		return true;
	if (list.size > size)
		return false;

	node* f = head;
	node* s = list.head;

	for (int i = 0; i < size; i++) {
		if (f->value == s->value) {
			node* tmp = f;
			int k = 0;
			for (int j = 0; j < list.size; j++) {
				if (tmp->value != s->value)
					break;
				tmp = tmp->linkNext ? tmp->linkNext : head;
				s = s->linkNext;
				k++;
			}
			if (k == list.size) {
				return true;
			}
			s = list.head;
		}
		f = f->linkNext;
	}

	return false;
}

template<class T>
my_double_linked_list<T>& my_double_linked_list<T>::maxMin() {

	if (size < 2) {
		throw std::exception("Not enough elements");
	}

	my_double_linked_list<T>* res = new my_double_linked_list<T>();

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


# endif