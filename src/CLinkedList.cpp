#include <iostream>

#include "CLinkedList.h"

CLinkedList::CLinkedList() {
  head_node_ = 0;
  conductor_ = head_node_;
}

CLinkedList::~CLinkedList() {
  Release(head_node_);
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
  AddHelper(head_node_, val);
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

CLinkedList::TNode* CLinkedList::GetHead() {
  return head_node_;
}

CLinkedList::TNode* CLinkedList::GetNext() {
  conductor_ = conductor_->next;

  return conductor_;
}

void CLinkedList::Reverse() {
  ReverseHelper(head_node_, 0);
}

void CLinkedList::ReverseHelper(TNode* current, TNode* prev) {
  if (current == 0) {

    // Let's make sure that the LL will be deleted properly
    head_node_ = prev;

    return;
  }

  ReverseHelper(current->next, current);

  current->next = prev;
}

void CLinkedList::Print() {
  PrintHelper(head_node_);
}

void CLinkedList::PrintHelper(const TNode* node) {
  if (node == 0) {
    return;
  }

  std::cout << node->val << std::endl;

  PrintHelper(node->next);
}
