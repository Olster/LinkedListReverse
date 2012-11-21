#include <iostream>

#include "CLinkedList.h"

CLinkedList::CLinkedList() {
    m_headNode = 0;
}

CLinkedList::~CLinkedList() {
    Release(m_headNode);
}

void CLinkedList::Release(TNode* node) {
    if (node == 0) {
        return;
    }

    Release(node->next);

    delete node;
    node = 0;
}

void CLinkedList::Add(int val) {
    AddHelper(m_headNode, val);
}

void CLinkedList::AddHelper(TNode* &node, int val) {
    if (node == 0) {
        node = new TNode;

        node->next = 0;
        node->val = val;
    } else {
        AddHelper(node->next, val);
    }
}

void CLinkedList::Reverse() {
    ReverseHelper(m_headNode, 0);
}

void CLinkedList::ReverseHelper(TNode* current, TNode* prev) {
    if (current == 0) {

        // Let's make sure that the LL will be deleted properly
        m_headNode = prev;

        return;
    }

    ReverseHelper(current->next, current);

    current->next = prev;
}

void CLinkedList::Print() {
    PrintHelper(m_headNode);
}

void CLinkedList::PrintHelper(const TNode* node) {
    if (node == 0) {
        return;
    }

    std::cout << node->val << std::endl;

    PrintHelper(node->next);
}
