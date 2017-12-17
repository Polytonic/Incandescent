/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

#include <unordered_set>

bool has_cycle(Node* head) {
    if (head == nullptr)
        return false;

    // Create a slow and a fast iterator.
    auto tortoise = head;
    auto hare = head->next;

    // If there is a cycle, the fast iterator will encounter
    // the slow iterator at some point while traversing the list.
    while (tortoise != hare) {
        if (hare == nullptr || hare->next == nullptr)
            return false;
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    return true;



    // With sufficient memory, it may make more sense
    // to store a set of encountered nodes.
    std::unordered_set<Node*> nodes;
    while (head != nullptr) {
        if (nodes.find(head) != nodes.end()) {
            return true;
        }
        nodes.insert(head);
        head = head->next;
    }

    return false;
}
