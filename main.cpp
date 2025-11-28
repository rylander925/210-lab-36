/*
COMSC-210 | Lab-36 | Rylan Der
IDE Used: Visual Studio Code 
*/

#include <iostream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    tree.insertNode("hi");
    tree.insertNode("salutations");
    tree.insertNode("hello");
    tree.insertNode("high");
    tree.displayInOrder();
    tree.remove("hello");
    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();

    return 0;
}