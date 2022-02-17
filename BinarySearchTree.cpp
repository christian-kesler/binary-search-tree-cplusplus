//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Christian Kesler
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;



//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Forward method declarations
double strToDouble(string str, char ch);


// Bid struct to hold bid information
struct Bid {
    string bidId;   // unique identifier for the entry
    string title;   
    string fund;    
    double amount;  
    Bid() {
        amount = 0.0;
    }
};


// Node struct, which contains a single entry along with a pointer to two other nodes
struct Node {
    Bid bid;
    Node* left;
    Node* right;

    // Default constructor for Node
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Initialize with a bid constructor
    Node(Bid aBid) : Node() {
        this->bid = aBid;
    }
};


// Binary Search Tree class definition
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void PrintInOrderFromNode(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void DestroyBinarySearchTreeFromNode(Node* node);
    void PrintInOrderFromRoot();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};


// BST default constructor 
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}


// BST Destructor
BinarySearchTree::~BinarySearchTree() {
    this->DestroyBinarySearchTreeFromNode(root);
}


/**
 * Delete all data in tree below node
 *
 * @param node Node to be treated as cap for deletion
 */
void BinarySearchTree::DestroyBinarySearchTreeFromNode(Node* node) {
    if (node != nullptr) {
        DestroyBinarySearchTreeFromNode(node->left);
        DestroyBinarySearchTreeFromNode(node->right);
        delete node;
    }
}


/**
 * Print all bids in tree in order from root
 */
void BinarySearchTree::PrintInOrderFromRoot() {
    this->PrintInOrderFromNode(root);
}


/**
 * Print all bids in tree in order from given node (recursive)
 *
 * @param node Node to be treated as the cap for printing
 */
void BinarySearchTree::PrintInOrderFromNode(Node* node) {
    if (node != nullptr) {
        PrintInOrderFromNode(node->left);
        cout << node->bid.bidId << ": "
            << node->bid.title << " | "
            << node->bid.amount << " | "
            << node->bid.fund << endl;
        PrintInOrderFromNode(node->right);
    }
}


/**
 * Insert a bid into the tree
 *
 * @param bid Bid to be inserted
 */
void BinarySearchTree::Insert(Bid bid) {
    if (root == nullptr) {
        root = new Node(bid);
    }
    else {
        this->addNode(root, bid);
    }
}


/**
 * Remove bid from tree
 *
 * @param bidId key that matches node we are removing
 */
void BinarySearchTree::Remove(string bidId) {
    this->removeNode(root, bidId);

}


/**
 * Search for bid and print result
 *
 * @param bidId key that matches node we are searching for
 */
Bid BinarySearchTree::Search(string bidId) {

    // start searching from the root
    Node* current = root;

    // keep looping downwards until bottom reached or bid is found
    while (current != nullptr) {

        // if current node matches, return it
        if (current->bid.bidId.compare(bidId) == 0) {
            return current->bid;
        }

        // if bid is smaller than current then traverse left
        if (bidId.compare(current->bid.bidId) < 0) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    Bid bid;
    return bid;
}


/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {

    // if node is larger than the bid, add to left subtree
    if (node->bid.bidId.compare(bid.bidId) > 0) {
        if (node->left == nullptr) {
            node->left = new Node(bid);
        }
        else {
            this->addNode(node->left, bid);
        }
    }

    // add to right subtree
    else {
        if (node->right == nullptr) {
            node->right = new Node(bid);
        }
        else {
            this->addNode(node->right, bid);
        }
    }
}


/**
 * Remove node and restructure tree (recursive)
 *
 * @param node node in tree to be examined
 * @param bidId key that matches node to be removed
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
    // if this node is null then return (avoid crashing)
    if (node == nullptr) {
        return node;
    }

    // recurse down left subtree
    if (bidId.compare(node->bid.bidId) < 0) {
        node->left = removeNode(node->left, bidId);
    }
    else if (bidId.compare(node->bid.bidId) > 0) {
        node->right = removeNode(node->right, bidId);
    }
    else {

        // no children so this a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }

        // one child to the left
        else if (node->left != nullptr && node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }

        // one child to the right
        else if (node->left == nullptr && node->right != nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }

        // two children
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->bid = temp->bid;
            node->right = removeNode(node->right, temp->bid.bidId);
        }
    }
    return node;
}



//============================================================================
// Static methods used for testing
//============================================================================


/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
    return;
}


/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            // push this bid to the end
            bst->Insert(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}


/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method, which reads execution arguments and populates defaults if empty
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Sample Bids from CSV file into Binary Search Tree" << endl;
        cout << "  2. Print All Bids in Binary Search Tree in ascending order" << endl;
        cout << "  3. Find and Print Bid with ID: 98109 within Binary Search Tree" << endl;
        cout << "  4. Remove Bid with ID: 98109 from Binary Search Tree" << endl;
        cout << "  5. Delete Binary Search Tree and All Bids within it" << endl;
        cout << "  9. Exit Program" << endl;
        cout << "Enter menu selection as a single integer followed by the Enter key: ";
        cin >> choice;

        if (choice > 0 && choice < 10) {
            switch (choice) {


            case 1:
                // Initialize a timer variable before performing computations
                ticks = clock();

                // Create a new BST and load data from the designated file
                bst = new BinarySearchTree();
                loadBids(csvPath, bst);

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "TIME: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds OR " << ticks << " clock ticks " << endl;

                break;

            case 2:
                // Initialize a timer variable before performing computations
                ticks = clock();

                // Print the BST in order from the root
                bst->PrintInOrderFromRoot();

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "TIME: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds OR " << ticks << " clock ticks " << endl;

                break;

            case 3:
                // Initialize a timer variable before performing computations
                ticks = clock();

                // Search BST based on designated key and print based on findings
                bid = bst->Search(bidKey);
                if (!bid.bidId.empty()) {
                    displayBid(bid);
                }
                else {
                    cout << "Bid Id " << bidKey << " not found." << endl;
                }

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "TIME: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds OR " << ticks << " clock ticks " << endl;

                break;

            case 4:
                // Initialize a timer variable before performing computations
                ticks = clock();

                // Search the BST for a bid based on designated key and remove it
                bst->Remove(bidKey);

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "TIME: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds OR " << ticks << " clock ticks " << endl;

                break;

            case 5:
                // Initialize a timer variable before performing computations
                ticks = clock();

                // Call the destructor and create a new empty BST 
                bst->~BinarySearchTree();
                bst = new BinarySearchTree();

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "TIME: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds OR " << ticks << " clock ticks " << endl;

                break;
            }
        }
        int choice = 0;
    }

    cout << "*/n*Good bye!     ( ^_^)/" << endl;

    return 0;
}
