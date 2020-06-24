#ifndef RING_BUFFER_H
#define RING_BUFFER_H

template<class T>
class my_ring_buffer {
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
	node* tail{ nullptr };
	size_t size{ 0 };
	size_t maxSize{ 0 };

public:
	explicit my_ring_buffer(int size);
	my_ring_buffer(const std::initializer_list<T>& list);
	~my_ring_buffer();
	void PushBack(T data);
	T PopFront();
	void Insert(T data, int index);
	T* Begin() { return &head->value; }
	T* End() { return &tail->value; }
	void Erase(int index);
	bool contains(my_ring_buffer<T>& list);
	my_ring_buffer<T>& maxMin();

	int Count() {
		return size;
	}

	friend std::ostream& operator<< (std::ostream& out, const my_ring_buffer<T>& m) {
		if (m.size == 0) throw std::out_of_range("Buffer is empty");
		node* current = m.head;
		int count = m.size;

		out << "( ";
		while (count != 0) {
			out << current->value << ", ";
			current = current->linkNext;
			count--;
		}
		out << " )";
		return out;
	}

	friend bool operator> (const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		node* cur1 = m.head;
		node* cur2 = m2.head;
		int count = m.size;

		while (((cur1 != m.tail) || (count != 0)) && ((cur2 != m2.tail) || (count != 0))) {
			if (cur1->value < cur2->value) return false;
			if (cur1->value > cur2->value) return true;

			cur1 = cur1->linkNext;
			cur2 = cur2->linkNext;
			count--;
		}
		if (cur1->value > cur2->value) return true;
		if (cur1->value < cur2->value) return false;

		return (m.size > m2.size);
	}

	friend bool operator== (const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		node* cur1 = m.head;
		node* cur2 = m2.head;
		int count = m.size;

		while (((cur1 != m.tail) || (count != 0)) && ((cur2 != m2.tail) || (count != 0))) {

			if (cur1->value != cur2->value) {
				return false;
			}

			cur1 = cur1->linkNext;
			cur2 = cur2->linkNext;
			count--;
		}
		if (cur1->value != cur2->value) {
			return false;
		}
		return (m.size == m2.size);
	}

	friend bool operator>= (const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		return ((m > m2) || (m == m2));
	}

	friend bool operator<= (const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		return !(m > m2);
	}

	friend bool operator!= (const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		return !(m == m2);
	}

	friend bool operator<(const my_ring_buffer<T>& m, const my_ring_buffer<T>& m2) {
		return !(m >= m2);
	}

};

template<class T>
my_ring_buffer<T>::my_ring_buffer(int size) {
	if (size <= 0) throw std::out_of_range("size will be positive number");

	this->maxSize = size;
	head = new node(0);
	node* current = head;
	for (int i = 1; i < maxSize; i++) {
		current->linkNext = new node(0);
		current = current->linkNext;
	}
	current->linkNext = head;
	tail = head;
}

template<class T>
my_ring_buffer<T>::~my_ring_buffer() {
	node* current = head;
	node* del = nullptr;
	while (size > 0) {
		del = current;
		current = current->linkNext;
		delete del;
		size--;
	}
	head = nullptr;
	tail = nullptr;
}

template<class T>
void my_ring_buffer<T>::PushBack(T data) {
	if (size == 0) {
		tail->value = data;
	}
	else {
		if (tail->linkNext == head) head = head->linkNext;
		tail = tail->linkNext;
		tail->value = data;
	}
	if (size != maxSize) size++;
}

template<class T>
T my_ring_buffer<T>::PopFront() {
	if (size == 0)
		throw std::out_of_range("the ring buffer is empty");

	size--;
	T ret = head->value;

	if (size == 0) {
		delete head;
		head = tail = nullptr;
	}
	else {
		node* toDel = head;
		head = head->linkNext;
		tail->linkNext = head;
		delete toDel;
	}
	return ret;
}

template<class T>
void my_ring_buffer<T>::Insert(T data, int index) {
	if (index >= size) throw std::out_of_range("Index is more the size of buffer");
	if (index < 0) throw std::out_of_range("index will be positive number");

	node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->linkNext;
	}
	current->value = data;
}

template<class T>
bool my_ring_buffer<T>::contains(my_ring_buffer<T>& list) {
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
inline my_ring_buffer<T>& my_ring_buffer<T>::maxMin() {

	if (size < 2) {
		throw std::exception("Not enough elements");
	}

	my_ring_buffer<T>* res = new my_ring_buffer<T>(2);

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

template<class T>
void my_ring_buffer<T>::Erase(int index) {
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
	if (size == 0)
		head = tail = nullptr;
}

template<class T>
my_ring_buffer<T>::my_ring_buffer(const std::initializer_list<T>& list) {
	if (list.size() == 0) throw std::out_of_range("initializer list is empty");

	this->maxSize = list.size();
	this->size = this->maxSize;
	head = new node(list.begin()[0]);
	node* current = head;
	for (int i = 1; i < maxSize; i++) {
		current->linkNext = new node(list.begin()[i]);
		current = current->linkNext;
	}
	tail = current;
	current->linkNext = head;
}
#endif