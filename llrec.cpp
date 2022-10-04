#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // base case, reached end of the list
    if (!head) {
        return;
    }
    
    llpivot(head->next, smaller, larger, pivot);
    
    // put the input node in the appropriate list
    if (head->val <= pivot) { // executes if smaller
        head->next = smaller; // add to front of list
        smaller = head;
        head = nullptr;
    } else { 
        head->next = larger; // add to front of list
        larger = head;
        head = nullptr;
    }
}
