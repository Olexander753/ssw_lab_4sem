#include <iostream>
#include <vector>
#include <string>
#include <fstream>

template<typename K, typename V>
class Dictionary;

namespace std {
	template<typename K, typename V>
	void swap(Dictionary<K, V>& f, Dictionary<K, V>& s) noexcept {
		f.keyPairs.swap(s.keyPairs);
	}
}

template<typename K, typename V>
class Dictionary {

	struct KeyValuePair;
	std::vector<KeyValuePair*> keyPairs;

public:

	struct KeyValuePair {
		K key;
		V value;

		KeyValuePair() {}
		KeyValuePair(K key, V value) : key(key), value(value) {}
	};

	template<typename K, typename V>
	friend std::ostream& operator<<(std::ostream& out, Dictionary<K, V>& dict);

	V& operator[](K index);
	void add(K k, V v);
	void remove(K k);
	void merge(Dictionary dict);
	KeyValuePair* find(V v);
	bool isExists(K k);
	inline size_t size() const {
		return keyPairs.size();
	}

	template<typename K, typename V>
	friend void std::swap(Dictionary<K, V>& f, Dictionary<K, V>& s) noexcept;

	bool operator == (Dictionary const& m);
	bool operator != (Dictionary const& m) {
		return !(this->operator==(m));
	};
	bool operator > (Dictionary const& m);
	bool operator < (Dictionary const& m) {
		return !(this->operator>=(m));
	};
	bool operator >= (Dictionary const& m) {
		return (this->operator>(m) || this->operator==(m));
	};
	bool operator <= (Dictionary const& m) {
		return !(this->operator>(m));
	};

};

int main() {
	Dictionary<std::string, std::string> dict;
	std::ifstream in("name.txt");
	while (!in.eof()) {
		std::string tmp;
		std::getline(in, tmp);
		auto posDelim = tmp.find_last_of(',');
		dict[tmp.substr(0, posDelim)] = tmp.substr(posDelim + 1);
	}
	in.close();
	std::cout << dict << "\nSize: " << dict.size() << std::endl;
	dict["New"] = "Element";
	std::cout << "New Element: " << dict << std::endl;
	dict.remove("Aaaaaaa Bbb C");
	std::cout << "Remove Element: " << dict << std::endl;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, Dictionary<K, V>& dict) {
	for (auto& kv : dict.keyPairs) {
		out << "{" << kv->key << ":" << kv->value << "}";
	}
	return out;
}

template<typename K, typename V>
V& Dictionary<K, V>::operator[](K index) {
	for (auto& kv : keyPairs) {
		if (kv->key == index) {
			return kv->value;
		}
	}
	KeyValuePair* kv = new KeyValuePair(index, V());
	keyPairs.push_back(kv);
	return kv->value;
}

template<typename K, typename V>
void Dictionary<K, V>::add(K k, V v) {
	(*this)[k] = v;
}

template<typename K, typename V>
void Dictionary<K, V>::remove(K k) {
	keyPairs.erase(std::find_if(keyPairs.begin(), keyPairs.end(), [&k](KeyValuePair* kv) { return kv->key == k; }), keyPairs.end());
}

template<typename K, typename V>
void Dictionary<K, V>::merge(Dictionary dict) {
	for (auto& kv : dict.keyPairs) {
		if (!isExists(kv->key)) {
			add(kv->key, kv->value);
		}
	}
}

template<typename K, typename V>
typename Dictionary<K, V>::KeyValuePair* Dictionary<K, V>::find(V v) {
	for (auto& kv : keyPairs) {
		if (kv->value == v) {
			return kv;
		}
	}
	return nullptr;
}

template<typename K, typename V>
bool Dictionary<K, V>::isExists(K k) {
	for (auto& kv : keyPairs) {
		if (kv->key == k) {
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
bool Dictionary<K, V>::operator==(Dictionary const& m) {
	if (size() != m.size()) return false;

	for (int i = 0; i < size(); i++) {
		if (keyPairs[i]->key != m.keyPairs[i]->key || keyPairs[i]->value != m.keyPairs[i]->value)
			return false;
	}

	return true;
}

template<typename K, typename V>
bool Dictionary<K, V>::operator>(Dictionary const& m) {

	if (size() != m.size()) return false;

	for (int i = 0; i < size(); i++) {
		if (keyPairs[i]->key != m.keyPairs[i]->key || keyPairs[i]->value <= m.keyPairs[i]->value)
			return false;
	}

	return true;
}
