#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    // Test out your linked list code

    Node* first = new Node(5, nullptr);
    Node* n2 = new Node(4, first);
    Node* n3 = new Node(3, n2);
    Node* n4 = new Node(2, n3);
    Node* n5 = new Node(1, n4);
    Node* n6 = new Node(0, n5);

    struct filterMe {
        // returns true for even numbers
        bool operator() (int i) {
            if (i % 2 == 0) {
                return true;
            } else {
                return false;
            }
        }
    };
    filterMe f1;
    Node* newHead = nullptr;
    newHead = llfilter(n6, f1);
    std::cout << "filtered list: ";
    print(newHead);
    std::cout << std::endl << std::endl;

    /*
    if (!n6) {
        std::cout << "n6 successfully deallocated" << std::endl;
    } else {
        std::cout << "n6 val: " << n6->val << std::endl;
        
    }

    if (!n4) {
        std::cout << "n4 successfully deallocated" << std::endl;
    } else {
        std::cout << "n4 val: " << n4->val << std::endl;
        
    }

    if (!n2) {
        std::cout << "n2 successfully deallocated" << std::endl;
    } else {
        std::cout << "n2 val: " << n2->val << std::endl;   
    }*/

    dealloc(newHead);

    Node* m1 = new Node(5, nullptr);
    Node* m2 = new Node(4, m1);
    Node* m3 = new Node(3, m2);
    Node* m4 = new Node(2, m3);
    Node* m5 = new Node(1, m4);
    Node* m6 = new Node(0, m5);

    Node* small = nullptr;
    Node* large = nullptr;

    llpivot(m6, small, large, 2);
    std::cout << "smaller list: ";
    print(small);
    std::cout << std::endl << "larger list: ";
    print(large);
    std::cout << std::endl;
    if (!m6) {
        std::cout << "original head is nullptr" << std::endl;
    }

    dealloc(small);
    dealloc(large);

    return 0;

}
