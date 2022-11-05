#pragma once
#include "BST_tree.h"
#include "Test.h"

void menu();

template <typename T>
BST_tree<T> create() {
	system("cls");
	cout << "Введите кол-во элементов в дереве:" << endl;
	int size = 0;
	while (size <= 0)
		cin >> size;

	BST_tree<int> tree;
	BST_tree<int> randTree(size);

	system("cls");
	cout << "1. Заполнить рандомно" << endl;
	cout << "2. Заполнить вручную" << endl;
	cout << "3. Вернуться в меню" << endl;

	char choice = _getch();
	switch (choice) {
	case '1':
		return randTree;
	case '2':
		system("cls");
		cout << "Введите элементы дерева:" << endl;
		T item;
		for (int i = 0; i < size; i++) {
			cin >> item;
			tree.insert(tree.getRoot(), item);
		}
		break;
	case '3':
		menu();
		break;
	default:
		cout << "Введено неверное значение. Нажмите любую клавишу, чтобы совершить возврат к предыдущему шагу..." << endl;
		_getch();
		create<T>();
		break;
	}

	return tree;
}

template <typename T>
BST_tree<T> add(BST_tree<T> tree) {
	system("cls");

	cout << "Введите элемент, который хотите добавить в дерево: " << endl << endl;
	T item;
	cin >> item;
	tree.insert(tree.getRoot(), item);

	return tree;
}

template <typename T>
BST_tree<T> remove(BST_tree<T> tree) {
	system("cls");

	cout << "1. Удалить заданное значение" << endl;
	cout << "2. Очистить дерево" << endl;
	cout << "3. Вернуться в меню" << endl << endl;

	char choice = _getch();
	T item;

	switch (choice) {
	case '1':
		while (true) {
			system("cls");
			cout << "Введите значение удаляемого элемента: " << endl;
			cin >> item;
			if (!cin) {
				cout << endl << "Введено некорректное удаляемое значение элемента. Нажмите любую клавишу для продолжения..." << endl;
				_getch();
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		tree.del(tree.getRoot(), item);
		break;
	case '2':
		tree.clear(tree.getRoot());
		break;
	case '3':
		menu();
		break;
	default:
		cout << "Введено неверное значение. Нажмите любую клавишу, чтобы совершить возврат к предыдущему шагу..." << endl;
		_getch();
		remove<T>(tree);
	}

	return tree;
}

template<typename T>
BST_tree<T> find(BST_tree<T> tree) {
	T item;
	while (true) {
		system("cls");
		cout << "Введите значение элемента массива, которое хотите найти: " << endl;
		cin >> item;
		if (!cin) {
			cout << endl << "Введено некорректно значение индекса. Нажмите любую клавишу для продолжения..." << endl << endl;
			_getch();
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	if (tree.search(tree.getRoot(), item))
		cout << endl << "Данный элемент пристутствует в дереве. \n\n Нажмите любую клавишу для продолжения...";
	else
		cout << endl << "Данный элемент отсутствует в дереве. \n\n Нажмите любую клавишу для продолжения...";
	_getch();

	return tree;
}

template<typename T>
BST_tree<T> print(BST_tree<T> tree) {
	system("cls");

	cout << "1. Форматированный вывод" << endl;
	cout << "2. Вывод списка L->t->R" << endl;
	cout << "3. Вернуться в меню" << endl << endl;

	char choice = _getch();
	T item;
	list<int> lst;

	switch (choice) {
	case '1':
		system("cls");
		tree.print(tree.getRoot());
		cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
		_getch();
		return tree;
	case '2':
		system("cls");
		lst = tree.createList();
		copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
		cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
		_getch();
		return tree;
	case '3':
		menu();
		break;
	default:
		cout << "Введено неверное значение. Нажмите любую клавишу, чтобы совершить возврат к предыдущему шагу..." << endl;
		_getch();
		print<T>(tree);
	}
}

void menu() {
	bool exit = false;
	BST_tree<int> tree;

	while (!exit) {
		system("cls");

		cout << "1. Создать дерево" << endl;
		cout << "2. Вывод дерева на экран" << endl;
		cout << "3. Узнать размер дерева" << endl;
		cout << "4. Добавить элемент" << endl;
		cout << "5. Очистить/удалить" << endl;
		cout << "6. Найти элемент" << endl;
		cout << "7. Поиск и подъем в корень дерева узла с ближайшим ключом, большим заданного значения" << endl;
		cout << "8. Опрос числа узлов дерева, просмотренных предыдущей операцией" << endl;
		cout << "9. Провести тест трудоемкости" << endl;
		cout << "0. Выход" << endl << endl;

		int size = 0;
		char choice = _getch();

		switch (choice) {
		case '1':
			tree.resetPrevNodeCounter();
			tree = create<int>();
			break;
		case '2':
			system("cls");
			tree.resetPrevNodeCounter();
			if (tree.isEmpty()) {
				cout << "Дерево пусто!" << endl << endl << "Нажмите любую клавишу для продолжения..." << endl;;
				_getch();
			}
			else
				tree = print<int>(tree);
			break;
		case '3':
			system("cls");
			tree.resetPrevNodeCounter();
			if (tree.isEmpty())
				cout << "Дерево пусто!" << endl;
			else
				cout << "Количество элементов: " << tree.getCounter() << endl << endl;
			cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
			_getch();
			break;
		case '4':
			tree.resetPrevNodeCounter();
			tree = add<int>(tree);
			break;
		case '5':
			system("cls");
			tree.resetPrevNodeCounter();
			if (tree.isEmpty()) {
				cout << "Дерево пусто!" << endl << endl << "Нажмите любую клавишу для продолжения..." << endl;;
				_getch();
			}
			else
				tree = remove<int>(tree);
			break;
		case '6':
			system("cls");
			tree.resetPrevNodeCounter();
			if (tree.isEmpty()) {
				cout << "Дерево пусто!" << endl << endl << "Нажмите любую клавишу для продолжения..." << endl;;
				_getch();
			}
			else
				tree = find<int>(tree);
			break;
		case '7':
			system("cls");
			tree.resetPrevNodeCounter();
			if (tree.isEmpty()) {
				cout << "Дерево пусто!" << endl << endl << "Нажмите любую клавишу для продолжения..." << endl;;
				_getch();
			}
			else
				tree = tree.changeRoot();
			break;
		case '8':
			system("cls");
			if (tree.isEmpty())
				cout << "Дерево пусто!" << endl << endl << "Нажмите любую клавишу для продолжения..." << endl;
			else
				cout << "Количество узлов дерева, просмотренных предыдущей операцией: " << tree.getPrevNodeCounter() << endl << endl
					 << "Нажмите любую клавишу для продолжения...";
			_getch();
			break;
		case '9':
			system("cls");
			cout << "Введите кол-во элементов в дереве:" << endl;
			while (size <= 0)
				cin >> size;

			system("cls");
			cout << "Расчет трудоемкости для рандомизированного дерева" << endl;
			test_rand(size);
			cout << endl << "Расчет трудоемкости для вырожденного дерева" << endl;;
			test_ord(size);
			cout << endl << "Нажмите любую клавишу для продолжения...";
			_getch();
			break;
		case '0':
			exit = true;
		}
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
	menu();
}
