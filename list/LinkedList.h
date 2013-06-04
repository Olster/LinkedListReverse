#ifndef LIST_LINKEDLIST_H_
#define LIST_LINKEDLIST_H_

// TODO(Olster): Read more on move semantics and perfect forwarding

namespace list {

namespace {

template <class T>
struct Node {
  T val;
  Node* next = nullptr;
};

} // namespace

template <class T>
class LinkedList {
 public:
  LinkedList() {}
  ~LinkedList();

  void operator=(const LinkedList<T>& other) = delete;
  LinkedList(const LinkedList<T>& other) = delete;
  void operator=(LinkedList<T>&& other) = delete;
  LinkedList(LinkedList<T>&& other) = delete;

  void Add(T val);

  void Reverse();

  void Clear();

  int GetSize() const { return m_dSize; }

  class Iterator;

  Iterator Begin() { return Iterator(m_headNode); }
  Iterator End() {
    // NOTE: The last node always points to null and End() returns
    // the position one past the end, hence it must be null

    return Iterator(nullptr);
  }
 private:
  // Called by Add()
  void AddHelper(Node<T>* &node, T val);

  // Called by Reverse()
  void ReverseHelper(Node<T>* current, Node<T>* prev);

  void ReleaseList(Node<T>* node);

  int m_dSize = 0;

  Node<T>* m_headNode = nullptr;
  Node<T>* m_conductor = nullptr;
};

template <class T>
class LinkedList<T>::Iterator {
 public:
  Iterator() {}
  Iterator(const Iterator& other)
   : m_currentNode(other.m_currentNode) {}

  Iterator(Iterator&& other)
   : m_currentNode(other.m_currentNode) {
    other.m_currentNode = nullptr;
  }

  explicit Iterator(Node<T>* node)
   : m_currentNode(node) {}

  Iterator& operator=(const Iterator& other) {
    if (&other == this) {
      return *this;
    }

    m_currentNode = other.m_currentNode;
    return *this;
  }

  Iterator& operator=(const Iterator&& other) {
    if (&other == this) {
      return *this;
    }

    m_currentNode = other.m_currentNode;
    other.m_currentNode = nullptr;

    return *this;
  }

  Iterator& operator++() {
    m_currentNode = m_currentNode->next;
    return *this;
  }

  T operator*() {
    return m_currentNode->val;
  }

  T& operator->() {
    return &m_currentNode->val;
  }

  bool operator==(const Iterator& other) {
    if (m_currentNode == other.m_currentNode) {
      return true;
    }

    return false;
  }

  bool operator!=(const Iterator& other) {
    return !(*this == other);
  }
 private:
  Node<T>* m_currentNode = nullptr;
};

// -------------------- Implementation --------------------

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
void LinkedList<T>::Reverse() {
  ReverseHelper(m_headNode, nullptr);
}

template <class T>
void LinkedList<T>::Clear() {
  ReleaseList(m_headNode);
}

template <class T>
void LinkedList<T>::AddHelper(Node<T>* &node, T val) {
  if (node == nullptr) {
    node = new Node<T>;

    node->next = nullptr;
    node->val = val;
  } else {
    AddHelper(node->next, val);
  }
}

template <class T>
void LinkedList<T>::ReverseHelper(Node<T>* current, Node<T>* prev) {
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
void LinkedList<T>::ReleaseList(Node<T>* node) {
  if (node == nullptr) {
    return;
  }

  ReleaseList(node->next);

  delete node;
  node = nullptr;
}

} // namespace list

#endif // LinkedList_H
