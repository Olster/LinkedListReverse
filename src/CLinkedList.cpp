#include "CLinkedList.h"

CLinkedList::CLinkedList() {
    m_headNode = 0;
}

CLinkedList::~CLinkedList() {
    release(m_headNode);
}

void CLinkedList::release(TNode* node) {
    if (node == 0) {
        return;
    }

    release(node->next);

    delete node;
    node = 0;
}

void CLinkedList::add(int val) {
    add(m_headNode, val);
}

void CLinkedList::add(TNode* &node, int val) {
    if (node == 0) {
        node = new TNode;

        node->next = 0;
        node->val = val;
    } else {
        add(node->next, val);
    }
}

void CLinkedList::reverse() {
    reverse(m_headNode, 0);
}

void CLinkedList::reverse(TNode* current, TNode* prev) {
    if (current == 0) {

        // Let's make sure that the LL will be deleted properly
        m_headNode = prev;

        return;
    }

    reverse(current->next, current);

    current->next = prev;
}

void CLinkedList::print() {
    print(m_headNode);
}

void CLinkedList::print(const TNode* node) {
    if (node == 0) {
        return;
    }

    cout << node->val << endl;

    print(node->next);
}
