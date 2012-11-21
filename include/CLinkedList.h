#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#define DISALLOW_COPY_AND_ASSIGN(type) \
    type(const type& var);             \
    void operator=(const type& type)

class CLinkedList {
    public:
        CLinkedList();
        ~CLinkedList();

        struct TNode {
            int val;
            TNode* next;
        };

        void Add(int val);
        void AddHelper(TNode* &node, int val);

        void Reverse();
        void ReverseHelper(TNode* current, TNode* prev);

        void Release(TNode* node);

        void Print();
        void PrintHelper(const TNode* node);

    private:
        TNode* m_headNode;

        DISALLOW_COPY_AND_ASSIGN(CLinkedList);
};

#endif // CLINKEDLIST_H
