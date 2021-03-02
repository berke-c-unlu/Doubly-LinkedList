#ifndef D_LINKED_LIST_H

#define D_LINKED_LIST_H

#include <vector>
#include <iostream>
#include "Node.h"

template <class T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& rhs);
	DoublyLinkedList(const std::vector<T>& data);


	~DoublyLinkedList();

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);

	void insertFront(const T& val);
	void insertBack(const T& val);
	
	void remove(const T& val);
	void removeAll();

	Node<T>* getFront() const;
	Node<T>* getBack() const;
	Node<T>* get(const T& val) const;

	int numberOfNodes() const;
	bool isEmpty() const;
	bool contains(const T& val);
	void print() const;

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};




//basic constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) {
	*this = rhs; // needs operator = overloading
}

//takes data from vector and constructs linked list
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& data) {
	head = nullptr;
	tail = nullptr;
	size = 0;

	for (T elem : data) {
		insertBack(elem); // works like push_back()
	}
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	removeAll();
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
	if (this != &rhs) { // if lhs not equal to rhs

		removeAll(); // clear the lhs

		if (!rhs.head) {// if rhs is empty list
			this->head = nullptr;
			this->tail = nullptr;
			this->size = 0;
		}

		else {
			Node<T>* ptr = rhs.head;

			while (ptr) { // traverse rhs and insert items into lhs
				insertBack(ptr->val);
				ptr = ptr->next;
			}
		}
	}
	return *this;
}

template <class T>
void DoublyLinkedList<T>::insertFront(const T& val) {
	if (!head) {
		Node<T>* tmp = new Node<T>(val, nullptr, tail);
		head = tail = tmp;
		size++;
	}
	else {
		Node<T>* tmp = new Node<T>(val, nullptr, head);
		head->prev = tmp;
		head = tmp;
		size++;
	}
}

template <class T>
void DoublyLinkedList<T>::insertBack(const T& val) {
	if (!tail) {
		Node<T>* tmp = new Node<T>(val, head, nullptr);
		head = tail = tmp;
		size++;
	}
	else {
		Node<T>* tmp = new Node<T>(val, tail, nullptr);
		tail->next = tmp;
		tail = tmp;
		size++;
	}
}

template <class T>
void DoublyLinkedList<T>::remove(const T& val) {
	if (!head) return;

	if (size == 1 && head->val == val) {
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
	}
	else if (head->val == val) {
		Node<T>* tmp = head;
		head->next->prev = nullptr;
		head = head->next;
		delete tmp;
	}
	else if (tail->val == val) {
		Node<T>* tmp = tail;
		tail->prev->next = nullptr;
		tail = tail->prev;
		delete tmp;
	}
	else {
		Node<T>* ptr = head;
		while (ptr) {
			if (ptr->val == val) {
				Node<T>* tmp = ptr;
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				delete tmp;
				break;
			}
			ptr = ptr->next;
		}
	}
}

template <class T>
void DoublyLinkedList<T>::removeAll() {
	Node<T>* prev = head;
	Node<T>* curr = head;

	while (curr) {
		curr = curr->next;
		delete prev;
		prev = curr;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
Node<T>* DoublyLinkedList<T>::getFront() const {
	return head;
}

template <class T>
Node<T>* DoublyLinkedList<T>::getBack() const {
	return tail;
}

template <class T>
Node<T>* DoublyLinkedList<T>::get(const T& val) const {
	if (!head) return nullptr;

	Node<T>* ptr = head;

	while (ptr) { // traverse list
		if (ptr->val == val) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr; // not founded
}
template <class T>
int DoublyLinkedList<T>::numberOfNodes() const {
	return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const {
	return head == nullptr;
}

template <class T>
bool DoublyLinkedList<T>::contains(const T& val) {
	if (!head) return false; // if list is empty

	Node<T>* ptr = head;

	while (ptr) { // traverse whole list
		if (ptr->val == val) // if found return true
			return true;
		ptr = ptr->next;
	}
	return false; // else return false
}

template <class T>
void DoublyLinkedList<T>::print() const {
	if (!head) {
		std::cout << "Empty list." << std::endl;
	}

	Node<T>* ptr = head;

	while (ptr) {
		std::cout << ptr->val << ' ';

		ptr = ptr->next;
	}
	std::cout << std::endl;
}



#endif // !D_LINKED_LIST_H

