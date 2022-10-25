#include "BST_tree.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    BST_tree<int> tree(10);

    cout << tree.getCounter() << endl << endl;

    //tree.insert(tree.getRoot(), 20);

    tree.print(tree.getRoot());

    _getch();
    system("cls");

    //list<int> lst = tree.createList();
    //cout << endl;
    //copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));

    //tree.del(tree.getRoot(), 20);

    //tree = tree.changeRoot();

    tree.print(tree.getRoot());

    list<int> lstt = tree.createList();
    cout << endl;
    copy(lstt.begin(), lstt.end(), ostream_iterator<int>(cout, " "));

    _getch();
    system("cls");


    //TODO
    //3. доделать методы
    //5. опрос числа узлов в прошлой операции
    //6. меню (ФУ)
}
