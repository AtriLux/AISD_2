#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <list>
#include <iterator>

using namespace std;

void GoToXY(int x, int y) {
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(StdOut, coord);
}

template <typename T>
class BST_tree {
public:
	BST_tree();
	BST_tree(int size);
	BST_tree(const BST_tree<T>& other);
	~BST_tree();

	class Node {
	public:
		T key;
		Node* left;
		Node* right;
		Node* parent;
	};

	Node* getRoot() {
		return root;
	};
	int getCounter();
	void clear();
	bool isEmpty();
	void del(Node node, T key);
	Node* search(Node node, T key);
	T changeRoot();
	void print(Node* root, int a = 100, int x = 50, int y = 0, int c = 0);
	list<T> createList();

	Node* insert(Node* node, T key) {
		if (!node) {
			node = (Node*)malloc(sizeof(Node));
			node->key = key;
			node->left = nullptr;
			node->right = nullptr;
			counter++;
			return node;
		}
		else {
			if (key < node->key) {
				node->left = insert(node->left, key);
				Node* left = node->left;
				left->parent = node;
			}
			else {
				node->right = insert(node->right, key);
				Node* right = node->right;
				right->parent = node;
			}
		}
		return node;
	};

	class Iterator // внутренний класс - итератор
	{
	private:
		Node* cur = nullptr;	// текущий индекс
		BST_tree<T>* tree;
		int counter = 1;
	public:
		Iterator(BST_tree* tree) { // конструктор итератора
			this->tree = tree;
		};
		Iterator begin(Node* node) { // установка на первое значение в массиве
			if (node->left)
				begin(node->left);
			else
				cur = node;
			counter = 1;
			return *this;
		}
		Iterator end(Node* node) { // установка на последнее значение в массиве
			if (node->right)
				end(node->right);
			else
				cur = node;
			counter = tree->counter;
			return *this;
		}
		Iterator& operator++(int) { // перегрузка перемещения вперед
			if (tree->counter != counter) {
				if (cur->right) {
					cur = cur->right;
					while (cur->left)
						cur = cur->left;
				}
				else {
					Node* parent = cur->parent;
					while (cur->key > parent->key) {
						cur = parent;
						parent = cur->parent;
						if (cur == tree->root) break;
					}
					cur = cur->parent;
				}
				counter++;
			}
			else
				begin(tree->root);
			return *this;
		};

		Iterator& operator--(int) { // перегрузка перемещения назад
			if (counter != 1) {
				if (cur->left) {
					cur = cur->left;
					while (cur->right)
						cur = cur->right;
				}
				else {
					Node* parent = cur->parent;
					while (cur->key < parent->key) {
						cur = parent;
						parent = cur->parent;
						if (cur == tree->root) break;
					}
					cur = cur->parent;
				}
				counter--;
			}
			else
				end(tree->root);
			return *this;
		};
		T& operator*() { // перегрузка доступа по чтению/записи
			return cur->key;
		}
		
		/*bool operator==(const Iterator&); // перегрузка равенства
		bool operator!=(const Iterator&); // перегрузка неравенства*/
	};

protected:
	int counter = 0;
	Node* root = nullptr;
};

template<typename T>
BST_tree<T>::BST_tree() {
	counter = 0;
	root = nullptr;
}

template<typename T>
BST_tree<T>::BST_tree(int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		T elem = rand() % 100;
		root = insert(root, elem);
	}
}

template<typename T>
BST_tree<T>::~BST_tree() {

}

template<typename T>
int BST_tree<T>::getCounter() {
	return counter;
}

template<typename T>
bool BST_tree<T>::isEmpty() {
	return counter == 0;
}

template<typename T>
list<T> BST_tree<T>::createList() {
	list<T> lst;
	Iterator it(this);
	it.begin(root);
	for (int i = 0; i++ < counter; it++) {
		lst.push_back(*it);
	}
	return lst;
}

template<typename T>
void BST_tree<T>::print(Node* root, int a, int x, int y,int c) {// c = 0 - корень, c = 1 - левый, c = 2 - правый
	if (root)
	{
		if (a > 0 && c != 0)
		{
			if (c == 1)
				x -= 10;
			else
				x += 10;
		}
		else if (c != 0)
			if (c == 1)
				x -= 4;
			else
				x += 4;

		GoToXY(x, y++);
		if (c == 1) printf("      /");
		if (c == 2) printf("\\");

		GoToXY(x, y++);
		printf("%5d", root->key);

		a--;
		print(root->left, a, x, y, 1);
		print(root->right, a, x, y, 2);
	}
}