#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    explicit LinkedList(int val) {
        value = val;
        next = nullptr;
    }

    // method to show the contents of the current Linked List
    void displayLinkedList() {
        LinkedList *current = this;
        while(current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
    }

    // method to generate a Linked List from an array of numbers
    void generateLinkedList(const vector<int>& array) {
        LinkedList *current = this;
        for(int element : array) {
            current->next = new LinkedList(element);
            current = current->next;
        }
    }
};

// THIS IS THE ALGORITHM
// O(n) time | O(1) space
LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
    LinkedList *current = linkedList;
    while(current != nullptr) {// O(n) time
        LinkedList *ptrNode = current->next;
        while(ptrNode != nullptr && ptrNode->value == current->value) {// O(n) time
            ptrNode = ptrNode->next;
        }
        current->next = ptrNode;
        current = current->next;
    }
    return linkedList;
}

int main() {
    LinkedList *input;
    input = new LinkedList(1);
    input->generateLinkedList(vector<int> {1, 3, 4, 4, 4, 5, 6, 6});
    input->displayLinkedList();
    cout << endl;
    removeDuplicatesFromLinkedList(input);
    input->displayLinkedList();
    return 0;
}
