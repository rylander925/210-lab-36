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

    //Read data from file to tree
    Read(tree, FILENAME);

    //Execute menu functionality
    enum MenuOption {ADD = 1, DELETE = 2, SEARCH = 3, MODIFY = 4, QUIT = 5};
    int choice;
    string val;
    do {
        //Display menu
        cout << "BST Options:" << endl
             << " 1. Add"    << endl
             << " 2. Delete" << endl
             << " 3. Search" << endl
             << " 4. Modify"   << endl
             << " 5. Quit"   << endl;

        //Validate input for menu choice
        cout << "Enter an option > ";
        do {
            cin >> choice;
            if (cin.fail()) {
                cout << "\tOption must be an integer" << endl;
                choice = -1;
            } else if (choice < ADD || choice > QUIT) {
                cout << "\tOption must between " << ADD << " and " << QUIT << endl;
            }
            cin.clear();
            cin.ignore(STREAM_IGNORE_CHARS, '\n');
        } while (choice < ADD || choice > QUIT);

        //Run function based on choice
        switch (choice) {
            case ADD: //Add inputted string to BST
                cout << "Enter an item to add > ";
                getline(cin, val);
                tree.insertNode(val);

                break;
            case DELETE: //Removes inputted string from BST
                cout << "Enter an item to delete > ";
                getline(cin, val);

                //Outputs an error message if node is not in the tree before deleting
                if (!tree.searchNode(val)) {
                    cout << "Node \"" << val << "\" is not in tree" << endl;
                } else {
                    tree.remove(val);
                    cout << "One instance of node \"" << val << "\" successfully removed" << endl;
                }

                break;
            case SEARCH: //Checks whether inputted string is in BST
                cout << "Enter an item to search for > ";
                getline(cin, val);
                cout << "Node \"" << val << "\" was " << (tree.searchNode(val) ? "found" : "not found") << endl;

                break;
            case MODIFY: //Checks for an inputted value in the BST, then modifies it if found
                cout << "Enter item to modify > ";
                getline(cin, val);
                if (tree.searchNode(val)) {
                    tree.remove(val);
                    cout << "Node \"" << val << "\" found. Enter replacement value > ";
                    getline(cin, val);
                    tree.insertNode(val);
                } else {
                    cout << "Node \"" << val << "\" not found." << endl;
                }
        }
        cout << endl;
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