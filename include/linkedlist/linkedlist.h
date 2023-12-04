#pragma once 
#include <iostream>
#include <random>


using namespace std;

namespace linkedlist {
	template <typename T>
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node<T>* next = nullptr) : value(value), next(next) {}
	};

	template <typename T>
	class LinkedList {
	private:
		Node<T>* _head;
	public:

		Node<T>* get_head() const {
			return _head;
		}

		LinkedList() : _head(nullptr) {}

		LinkedList(const LinkedList& lst) : _head(nullptr) {
			auto ptr = lst._head;
			while (ptr) {
				push_tail(ptr->value);
				ptr = ptr->next;
			}
		}

		LinkedList(size_t size) {};

		LinkedList<T>& operator=(const LinkedList<T>& lst) {
			LinkedList<T> a(lst);
			std::swap(a._head, _head);
			return a;
		}

		~LinkedList() {
			while (_head) {
				auto ptr = _head;
				_head = _head->next;
				delete ptr;
			}

			_head = nullptr;
		}

		void push_head(const T value) {
			_head = new Node<T>(value, _head);
		}

		void pop_head() {
			if (!_head) {
				throw out_of_range("List is empty");
			}
			auto ptr = _head;
			_head = _head->next;
			delete ptr;
			ptr = nullptr;

		}

		void push_tail(const T value) {
			if (_head == nullptr) {
				_head = new Node<T>(value, nullptr);
				return;
			}
			Node<T>*  ptr = _head;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = new Node<T>(value, nullptr);
		}

		void push_tail(const LinkedList<T>& lst) {
			auto ptr = lst._head;
			while (ptr) {
				this->push_tail(ptr->value);
				ptr = ptr->next;
			}
		}

		void push_head(const LinkedList<T>& lst) {
			LinkedList<T> copy(lst);
			copy.push_tail(*this);
			std::swap(_head, copy._head);
		}

		void pop_tail() {
			if (!_head) {
				throw out_of_range("List is empty");
			}
			auto ptr = _head;
			while (ptr->next->next) {
				ptr = ptr->next;
			}
			delete ptr->next;
			ptr->next = nullptr;
		}

		void print() const {

			auto ptr = _head;

			while (ptr) {
				cout << ptr->value << endl;
				ptr = ptr->next;
			}
		}

		size_t size() const {
			auto ptr = _head;
			size_t size = 0;
			while (ptr) {
				ptr = ptr->next;
				size++;
			}
			return size;
		}

		T operator[](size_t index) const {
			if (index < 0 || index >= this->size()) {
				throw out_of_range("Index it out of range");
			}
			auto ptr = _head;
			for (int i = 0; i < index; i++) {
				ptr = ptr->next;
			}
			return ptr->value;
		}

		T& operator[](size_t index) {
			if (index < 0 || index >= this->size()) {
				throw out_of_range("Index it out of range");
			}
			auto ptr = _head;
			for (int i = 0; i < index; i++) {
				ptr = ptr->next;
			}
			return ptr->value;
		}

		void delete_node(const T& value) {
			auto ptr = _head;
			while (_head && _head->value == value) {
				ptr = _head->next;
				delete _head;
				_head = ptr;
			}
			Node<T>* dop_ptr;
			while (ptr && ptr->next) {
				if (ptr->next->value == value) {
					dop_ptr = ptr->next;
					ptr->next = ptr->next->next;
					delete dop_ptr;
					dop_ptr = nullptr;
				}
				else {
					ptr = ptr->next;
				}
			}
		}
	};

	template <typename T>
	ostream& operator<<(ostream& a, const LinkedList<T>& lst) {
		Node<T>* ptr = lst.get_head();
		while (ptr) {
			a << ptr->value << " ";
			ptr = ptr->next;
		}
		return a;
	}

	template <>
	LinkedList<int>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand());
		}
	}

	template <>
	LinkedList<bool>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand()%2);
		}
	}

	template <>
	LinkedList<float>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand() + 0.00001 * rand());
		}
	}

	template <>
	LinkedList<double>::LinkedList(size_t size) : _head(nullptr) {
		for (int i = 0; i < size; i++) {
			this->push_tail(rand() + 0.00001 * rand());
		}
	}
}