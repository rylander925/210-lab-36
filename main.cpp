/*
COMSC-210 | Lab-36 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    const int NUMS = 10;
    //test an int tree
    IntBinaryTree tree;
    int num;
    for (int i = 0; i < NUMS; i++) {
        num = rand() % NUMS;
        cout << num << " ";
        tree.insertNode(num);
    }
    cout << endl;
    tree.displayInOrder();

    return 0;
}