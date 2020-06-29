#include <iostream>
#include <variant>
#include <list>
#include <functional>
#include <optional>

template<typename T>
class BinaryTree {
public:
	struct Node {
		T value;
		Node* left, * right;

		Node() :left(nullptr), right(nullptr) {}
		Node(T value) :left(nullptr), right(nullptr), value(value) {}
		Node(T value, Node* l, Node* r) :left(l), right(r), value(value) {}
	};

	BinaryTree() {}
	BinaryTree(std::initializer_list<T> list);

	void add(T value);
	void remove(T value);
	void removeAll(T value);
	void merge(BinaryTree& tree);
	std::vector<BinaryTree*> split();
	std::optional<std::variant<T, std::list<T>>> findPath(T value);
	Node* find(T value);
	size_t height();

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, BinaryTree<T>& tree);
	inline size_t size() {
		return size_tree;
	}

	bool operator == (BinaryTree<T> const& m);
	bool operator != (BinaryTree<T> const& m) {
		return !(this->operator==(m));
	};
	bool operator > (BinaryTree<T> const& m);
	bool operator < (BinaryTree<T> const& m) {
		return !(this->operator>=(m));
	};
	bool operator >= (BinaryTree<T> const& m) {
		return (this->operator>(m) || this->operator==(m));
	};
	bool operator <= (BinaryTree<T> const& m) {
		return !(this->operator>(m));
	};

private:

	void recursiveWork(Node* n, std::function<void(Node*, size_t)> work, size_t height = 0);
	bool compareEqual(Node* f, Node* s);
	bool compareMore(Node* f, Node* s);

	Node* root{ nullptr };
	size_t size_tree{ 0 };
};

template<typename T>
class GenTree {

public:
	struct Node {
		T value;
		std::vector<Node*> list;

		Node() {}
		Node(T value) : value(value) {}
	};

	GenTree() {}
	GenTree(std::initializer_list<T> list);

	void add(T value);
	void remove(T value);
	void removeAll(T value);
	void merge(GenTree& tree);
	void merge(GenTree::Node* tree);
	std::vector<GenTree*> split();
	std::optional<std::variant<int, std::list<int>>> findPath(T value);
	Node* find(T value);
	size_t height();

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, GenTree<T>& tree);
	inline size_t size() {
		return size_tree;
	}

	bool operator == (GenTree<T> const& m);
	bool operator != (GenTree<T> const& m) {
		return !(this->operator==(m));
	};
	bool operator > (GenTree<T> const& m);
	bool operator < (GenTree<T> const& m) {
		return !(this->operator>=(m));
	};
	bool operator >= (GenTree<T> const& m) {
		return (this->operator>(m) || this->operator==(m));
	};
	bool operator <= (GenTree<T> const& m) {
		return !(this->operator>(m));
	};

private:

	void recursiveWork(Node* n, std::function<void(Node*, size_t)> work, size_t height = 0);
	bool recursiveRemove(Node* n, T value);
	Node* recursiveFind(Node* n, T value);
	void recursiveMode(Node* to, Node* from);
	std::optional<std::variant<T, std::list<T>>> recursiveFindPath(Node* n, T value, std::list<T> path);
	void recalcSize();
	bool compareEqual(Node* f, Node* s);
	bool compareMore(Node* f, Node* s);

	Node* root{ nullptr };
	size_t size_tree{ 0 };

};


void genTree() {
	GenTree<int> bt{ 1,1,2,3,4,-1 };
	GenTree<int> bt2{ 1,1 };

	std::cout << "First gen tree: " << bt << ", Height: " << bt.height() << std::endl;
	std::cout << "Second gen tree: " << bt2 << ", Height: " << bt2.height() << std::endl;
	bt.merge(bt2);
	std::cout << "Merge gen tree: " << bt << ", Height: " << bt.height() << std::endl;
	bt.remove(1);
	std::cout << "Remove 1 gen tree: " << bt << ", Height: " << bt.height() << std::endl;
	bt.removeAll(1);
	std::cout << "Remove all 1 gen tree: " << bt << ", Height: " << bt.height() << std::endl;
	auto split = bt.split();
	for (auto b : split) {
		std::cout << "Split tree gen tree: " << *b << ", Height: " << b->height() << std::endl;
	}

	bool res = bt > bt2 && bt == bt2;
}

void binTree() {
	BinaryTree<int> bt{ 1,1,2,3,4,-1 };
	BinaryTree<int> bt2{ 1,1 };

	std::cout << "First bin tree: " << bt << ", Height: " << bt.height() << std::endl;
	std::cout << "Second bin tree: " << bt2 << ", Height: " << bt2.height() << std::endl;
	bt.merge(bt2);
	std::cout << "Merge bin tree: " << bt << ", Height: " << bt.height() << std::endl;
	bt.remove(1);
	std::cout << "Remove 1 bin tree: " << bt << ", Height: " << bt.height() << std::endl;
	bt.removeAll(1);
	std::cout << "Remove all 1 bin tree: " << bt << ", Height: " << bt.height() << std::endl;
	auto split = bt.split();
	for (auto b : split) {
		std::cout << "Split tree bin tree: " << *b << ", Height: " << b->height() << std::endl;
	}

	bool res = bt > bt2 && bt == bt2;
}

int main() {
	binTree();
	std::cout << std::endl;
	genTree();
}

template<typename T>
BinaryTree<T>::BinaryTree(std::initializer_list<T> list) {
	for (auto& el : list) {
		add(el);
	}
}

template<typename T>
void BinaryTree<T>::add(T value) {

	if (!root) {
		root = new Node(value);
	}
	else {
		Node* tmpRoot = root, * tmpPrev = root;
		while (tmpRoot) {
			tmpPrev = tmpRoot;
			tmpRoot = tmpRoot->value > value ? tmpRoot->left : tmpRoot->right;
		}

		if (value < tmpPrev->value) {
			tmpPrev->left = new Node(value);
		}
		else {
			tmpPrev->right = new Node(value);
		}

	}

	size_tree++;

}

template<typename T>
void BinaryTree<T>::remove(T value) {
	Node* tmpRoot = root, * tmpPrev = root;
	while (tmpRoot && tmpRoot->value != value) {
		tmpPrev = tmpRoot;
		tmpRoot = tmpRoot->value > value ? tmpRoot->left : tmpRoot->right;
	}

	if (!tmpRoot)
		return;

	Node** direction = tmpRoot == tmpPrev->left ? &tmpPrev->left : &tmpPrev->right;
	if (tmpRoot == root)
		direction = &root;

	if (tmpRoot->left == tmpRoot->right) {
		delete* direction;
		*direction = nullptr;
	}
	else if ((tmpRoot->left && !tmpRoot->right) || (!tmpRoot->left && tmpRoot->right)) {
		Node* next = tmpRoot->left ? tmpRoot->left : tmpRoot->right;
		Node* toDelete = *direction;
		*direction = next;
		delete toDelete;
	}
	else {
		Node* nextLeft = tmpRoot->left;
		Node* nextRight = tmpRoot->right;

		Node* toDelete = *direction;
		*direction = nextLeft;
		while (nextLeft->right) {
			nextLeft = nextLeft->right;
		}
		nextLeft->right = nextRight;

		delete toDelete;
	}

	size_tree--;
}

template<typename T>
void BinaryTree<T>::removeAll(T value) {
	while (find(value)) {
		remove(value);
	}
}

template<typename T>
void BinaryTree<T>::merge(BinaryTree& tree) {
	tree.recursiveWork(tree.root, [this](Node* n, int) { add(n->value); });
}

template<typename T>
std::vector<BinaryTree<T>*> BinaryTree<T>::split() {
	if (!root)
		return {};
	std::vector<BinaryTree*> res{ new BinaryTree(), new BinaryTree() };
	res[0]->add(root->value);
	recursiveWork(root->left, [&res](Node* n, int) { res[0]->add(n->value); });
	recursiveWork(root->right, [&res](Node* n, int) { res[1]->add(n->value); });
	return res;
}

template<typename T>
std::optional<std::variant<T, std::list<T>>> BinaryTree<T>::findPath(T value) {
	Node* tmpRoot = root;
	std::list<int> path;
	while (tmpRoot && tmpRoot->value != value) {
		path.push_back(tmpRoot->value);
		tmpRoot = tmpRoot->value > value ? tmpRoot->left : tmpRoot->right;
	}

	if (!tmpRoot)
		return {};

	path.push_back(tmpRoot->value);
	if (path.size() == 1)
		return *path.begin();
	return path;
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find(T value) {
	Node* tmpRoot = root;
	while (tmpRoot && tmpRoot->value != value) {
		tmpRoot = tmpRoot->value > value ? tmpRoot->left : tmpRoot->right;
	}
	return tmpRoot;
}

template<typename T>
size_t BinaryTree<T>::height() {
	size_t height = 0;
	recursiveWork(root, [&height](Node*, size_t h) { if (h > height) height = h; }, 1);
	return height;
}

template<typename T>
bool BinaryTree<T>::operator==(BinaryTree<T> const& m) {
	return compareEqual(root, m.root);
}

template<typename T>
bool BinaryTree<T>::operator>(BinaryTree<T> const& m) {
	return compareMore(root, m.root);
}

template<typename T>
void BinaryTree<T>::recursiveWork(Node* n, std::function<void(Node*, size_t)> work, size_t height) {
	if (!n)
		return;

	work(n, height);
	if (n->left) {
		recursiveWork(n->left, work, height + 1);
	}
	if (n->right) {
		recursiveWork(n->right, work, height + 1);
	}
}

template<typename T>
bool BinaryTree<T>::compareEqual(Node* f, Node* s) {
	if (!f && !s) return true;
	if ((f && !s) || (!f && s)) return false;
	return f->value == s->value && compareEqual(f->left, s->left) && compareEqual(f->right, s->right);
}

template<typename T>
bool BinaryTree<T>::compareMore(Node* f, Node* s) {
	if ((!f && !s) || (!f && s)) return false;
	if (f && !s) return true;
	return f->value > s->value && compareMore(f->left, s->left) && compareMore(f->right, s->right);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, BinaryTree<T>& tree) {
	tree.recursiveWork(tree.root, [&out](typename BinaryTree<T>::Node* n, int h) { out << std::string(h, '.') << n->value << ' '; });
	return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, GenTree<T>& tree) {
	tree.recursiveWork(tree.root, [&out](typename GenTree<T>::Node* n, int h) { out << std::string(h, '.') << n->value << ' '; });
	return out;
}

template<typename T>
GenTree<T>::GenTree(std::initializer_list<T> list) {
	for (T n : list) {
		add(n);
	}
}

template<typename T>
void GenTree<T>::add(T value) {
	if (!root) {
		root = new Node(value);
	}
	else {
		root->list.push_back(new Node(value));
	}

	size_tree++;
}

template<typename T>
void GenTree<T>::remove(T value) {

	if (root->value == value) {
		Node* toDelete = root;
		if (root->list.size() > 0) {
			root = *(root->list.begin());
			for (auto it = (++toDelete->list.begin()); it != toDelete->list.end(); it++) {
				root->list.push_back(*it);
			}
		}
		else {
			root = nullptr;
		}
		delete toDelete;
		size_tree--;
	}
	else {
		recursiveRemove(root, value);
	}

}

template<typename T>
void GenTree<T>::removeAll(T value) {
	while (find(value)) {
		remove(value);
	}
}

template<typename T>
void GenTree<T>::merge(GenTree& tree) {
	merge(tree.root);
	size_tree += tree.size_tree;
}

template<typename T>
void GenTree<T>::merge(GenTree::Node* tree) {
	if (root) {
		recursiveMode(root, tree);
	}
	else {
		root = new Node();
		recursiveMode(root, tree);
		Node* toDelete = root;
		root = *(root->list.begin());
		delete toDelete;
	}
}

template<typename T>
std::vector<GenTree<T>*> GenTree<T>::split() {
	std::vector<GenTree*> res{ new GenTree(), new GenTree() };
	res[0]->add(root->value);

	int size = root->list.size();
	for (int i = 0; i < size; i++) {
		res[i > (size / 2)]->merge(root->list[i]);
		res[i > (size / 2)]->recalcSize();
	}

	return res;
}

template<typename T>
std::optional<std::variant<int, std::list<int>>> GenTree<T>::findPath(T value) {
	return recursiveFindPath(root, value, std::list<T>());
}

template<typename T>
typename GenTree<T>::Node* GenTree<T>::find(T value) {
	return recursiveFind(root, value);
}

template<typename T>
size_t GenTree<T>::height() {
	size_t height = 0;
	recursiveWork(root, [&height](Node*, size_t h) { if (h > height) height = h; }, 1);
	return height;
}

template<typename T>
bool GenTree<T>::operator==(GenTree<T> const& m) {
	return false;
}

template<typename T>
bool GenTree<T>::operator>(GenTree<T> const& m) {
	return false;
}

template<typename T>
void GenTree<T>::recursiveWork(Node* n, std::function<void(Node*, size_t)> work, size_t height) {

	if (!n)
		return;

	work(n, height);
	for (Node* node : n->list) {
		recursiveWork(node, work, height + 1);
	}

}

template<typename T>
bool GenTree<T>::recursiveRemove(Node* n, T value) {

	for (auto it = n->list.begin(); it != n->list.end(); it++) {
		Node* node = *it;
		if (node->value == value) {
			n->list.erase(it);
			if (node->list.size() > 0) {
				for (auto it_in = node->list.begin(); it_in != node->list.end(); it_in++) {
					n->list.push_back(*it_in);
				}
			}
			delete node;
			size_tree--;
			return true;
		}
		else {
			recursiveRemove(node, value);
		}
	}
	return false;
}

template<typename T>
typename GenTree<T>::Node* GenTree<T>::recursiveFind(Node* n, T value) {
	if (n->value == value)
		return n;
	for (Node* node : n->list) {
		Node* res = recursiveFind(node, value);
		if (res)
			return res;
	}
	return nullptr;
}

template<typename T>
void GenTree<T>::recursiveMode(Node* to, Node* from) {
	Node* newNode = new Node(from->value);
	for (Node* n : from->list) {
		recursiveMode(newNode, n);
	}
	to->list.push_back(newNode);
}

template<typename T>
std::optional<std::variant<T, std::list<T>>> GenTree<T>::recursiveFindPath(Node* n, T value, std::list<T> path) {

	path.push_back(n->value);

	if (n->value == value) {
		return path;
	}

	for (auto it = n->list.begin(); it != n->list.end(); it++) {
		auto res = recursiveFindPath(*it, value, path);
		if (res)
			return res;
	}

	return {};
}

template<typename T>
void GenTree<T>::recalcSize() {
	size_tree = 0;
	recursiveWork(root, [this](Node*, size_t) {size_tree++; });
}

template<typename T>
bool GenTree<T>::compareEqual(Node* f, Node* s) {
	if (!f && !s) return true;
	if ((f && !s) || (!f && s) || (f->list.size() != s->list.size())) return false;

	if (f->value != s->value)
		return false;

	for (int i = 0; i < f->list.size(); i++) {
		if (!compareEqual(f->list[i], s->list[i]))
			return false;
	}
	return true;
}

template<typename T>
bool GenTree<T>::compareMore(Node* f, Node* s) {
	if ((!f && !s) || (!f && s)) return false;
	if (f && !s) return true;

	if (f->value <= s->value)
		return false;

	for (int i = 0; i < f->list.size(); i++) {
		if (!compareMore(f->list[i], s->list[i]))
			return false;
	}
	return true;
}
