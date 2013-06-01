#ifndef LIST_LINKEDLIST_H_
#define LIST_LINKEDLIST_H_

namespace list {

template <class T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void operator=(const LinkedList<T>& other) = delete;
  LinkedList(const LinkedList<T>& other) = delete;
  LinkedList(const LinkedList<T>&& other) = delete;

  void Add(T val);

  struct TNode {
    T val;
    TNode* next = nullptr;
  };

  TNode* GetHead();
  TNode* GetNext();

  void Reverse();

  void Clear();

  int GetSize() const { return m_dSize; }
 private:
  // The work horse for Add()
  void AddHelper(TNode* &node, T val);

  // The workhorse for Reverse()
  void ReverseHelper(TNode* current, TNode* prev);

  void ReleaseList(TNode* node);

  int m_dSize = 0;

  TNode* m_headNode = nullptr;
  TNode* m_conductor = nullptr;
};

// -------------------- Implementation ----------------------
template <class T>
LinkedList<T>::LinkedList() {
  m_headNode = nullptr;
  m_conductor = m_headNode;
}

template <class T>
LinkedList<T>::~LinkedList() {
  ReleaseList(m_headNode);
}

template <class T>
void LinkedList<T>::Add(T val) {
  AddHelper(m_headNode, val);
  m_dSize++;
}

template <class T>
typename LinkedList<T>::TNode* LinkedList<T>::GetHead() {
  return m_headNode;
}

template <class T>
typename LinkedList<T>::TNode* LinkedList<T>::GetNext() {
  if (!m_conductor) {
    m_conductor = m_headNode;
    return m_conductor;
  }

  m_conductor = m_conductor->next;

  return m_conductor;
}

template <class T>
void LinkedList<T>::Reverse() {
  ReverseHelper(m_headNode, nullptr);
}

template <class T>
void LinkedList<T>::Clear() {
  ReleaseList(m_headNode);
}

template <class T>
void LinkedList<T>::AddHelper(TNode* &node, T val) {
  if (node == nullptr) {
    node = new TNode;

    node->next = nullptr;
    node->val = val;
  } else {
    AddHelper(node->next, val);
  }
}

template <class T>
void LinkedList<T>::ReverseHelper(TNode* current, TNode* prev) {
  if (current == nullptr) {
    // Let's make sure that the LL will be deleted properly
    // by setting its head to its end

    // At this point we're outside of linked list, meaning that the
    // |prev| is the last element
    m_headNode = prev;

    return;
  }

  ReverseHelper(current->next, current);

  current->next = prev;
}


template <class T>
void LinkedList<T>::ReleaseList(TNode* node) {
  if (node == nullptr) {
    return;
  }

  ReleaseList(node->next);

  delete node;
  node = nullptr;
}

} // namespace list

#endif // LinkedList_H
