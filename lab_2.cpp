#include "BST_tree.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    BST_tree<int> tree(6);

    //cout << tree.getCounter() << endl << endl;
    //BST_tree<int>::Node t = *tree.getRoot();
    //t = *tree.insert(tree.getRoot(), 20);

    //tree.insert(tree.getRoot(), 20);

    tree.resetPrevNodeCounter();
    tree.print(tree.getRoot());
    cout << endl << tree.getPrevNodeCounter() << endl;
    _getch();
    system("cls");

    //list<int> lst = tree.createList();
    //cout << endl;
    //copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));

    //tree.del(tree.getRoot(), 20);

    BST_tree<int> copy_tree(tree.changeRoot());
    cout << endl << copy_tree.getPrevNodeCounter() << endl;

    copy_tree.resetPrevNodeCounter();
    copy_tree.print(copy_tree.getRoot());
    cout << endl << copy_tree.getPrevNodeCounter() << endl;

    //list<int> lstt = tree.createList();
    //cout << endl;
    //copy(lstt.begin(), lstt.end(), ostream_iterator<int>(cout, " "));

    _getch();
    system("cls");


    //TODO
    //6. меню (ФУ)
    // трудоемкости
}
