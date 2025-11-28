/*
COMSC-210 | Lab-36 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void Read(StringBinaryTree& tree, string filename);

int main() {
    StringBinaryTree tree;
    const string FILENAME = "codes.txt";
    Read(tree, FILENAME);
    tree.displayInOrder();
    return 0;
}

/**
 * Read data from a file into a BST
 * @param tree      String BST to fill
 * @param filename  File to retrieve data from. Each line is treated as a separate data point
 */
void Read(StringBinaryTree& tree, string filename){
    ifstream infile;
    string val;

    //Validate file opens properly
    infile.open(filename);
    if (!infile.is_open()) {
        cout << "Error opening file \"" << filename << "\"" << endl;
        throw ios_base::failure("File open error");
    }

    //Insert items from file to tree
    while(getline(infile, val)) {
        //Check that proper file values are read
        if (val == "" || val.size() <= 5) {
            cout << "Abnormal value: \"" << val << "\" not added" << endl;
        } else {
            tree.insertNode(val);
        }
    }
}