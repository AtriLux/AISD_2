#include "BST_tree.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    BST_tree<int> tree(6);

    cout << tree.getCounter() << endl << endl;

    tree.print(tree.getRoot());

    list<int> lst = tree.createList();
    cout << endl;
    copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
    _getch();
    system("cls");


    //TODO
    //1. деструктор
    //2. убрать повторки
    //3. доделать методы
    //4. reverseIterator, сравнение итераторов
    //5. опрос числа узлов в прошлой операции
    //6. меню (ФУ)
}
