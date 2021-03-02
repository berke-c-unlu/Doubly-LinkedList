#ifndef NODE_H

#define NODE_H

template <class T>
class Node {
public:
	Node() {
		next = nullptr;
		prev = nullptr;
	}
	Node(T val) {
		this->val = val;
		this->prev = nullptr;
		this->next = nullptr;
	}
	Node(T val, Node<T>* prev, Node<T>* next) {
		this->val = val;
		this->prev = prev;
		this->next = next;
	}

	T val;
	Node<T>* next;
	Node<T>* prev;
};
#endif // !NODE_H

