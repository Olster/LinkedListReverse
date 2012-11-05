#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>

#define DISALLOW_COPY_AND_ASSIGN(type) \
    type(const type& var);             \
    void operator=(const type& type)

using std::cout;
using std::endl;

class CLinkedList {
    public:
        CLinkedList();
        ~CLinkedList();

        struct TNode {
            int val;
            TNode* next;
        };

        void add(int val);
        void add(TNode* &node, int val);

        void reverse();
        void reverse(TNode* current, TNode* prev);

        void release(TNode* node);

        void print();
        void print(const TNode* node);

    private:
        DISALLOW_COPY_AND_ASSIGN(CLinkedList);

        TNode* m_headNode;
};

#endif // CLINKEDLIST_H
