/*
COMSC-210 | Lab-36 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

const int STREAM_IGNORE_CHARS = 100;

void Read(StringBinaryTree& tree, string filename);

int main() {
    StringBinaryTree tree;
    const string FILENAME = "codes.txt";
    Read(tree, FILENAME);

    enum MenuOption {ADD = 1, DELETE = 2, SEARCH = 3, QUIT = 4};
    int choice;
    string val;
    do {
        //Display menu
        cout << "BST Options:" << endl
             << " 1. Add"    << endl
             << " 2. Delete" << endl
             << " 3. Search" << endl
             << " 4. Quit"   << endl;

        //Validate input for menu choice
        cout << "Enter an option: > ";
        do {
            cin >> choice;
            if (cin.fail()) {
                cout << "\tOption must be an integer" << endl;
                choice = -1;
            } else if (choice < ADD || choice > QUIT) {
                cout << "\tOption must between" << ADD << "and" << QUIT << endl;
            }
            cin.clear();
            cin.ignore(STREAM_IGNORE_CHARS, '\n');
        } while (choice < ADD || choice > QUIT);

        //Run function based on choice
        switch (choice) {
            case ADD:
                cout << "Enter an item to add: " << endl;
                getline(cin, val);
                tree.insertNode(val);
                break;
            case DELETE:
            case SEARCH:

        }
    } while (choice != QUIT);
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