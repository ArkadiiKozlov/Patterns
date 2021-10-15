#ifndef ITERATOR_H
#define ITERATOR_H
//07.07.2021, from home computer
class StackIter;

class Stack
{
        int items[10];
        int sp;
    public:
        friend class StackIter;
        Stack()
        {
            sp =  - 1;
        }
        void push(int in)
        {
            items[++sp] = in;
        }
        int pop()
        {
            return items[sp--];
        }
        bool isEmpty()
        {
            return (sp ==  - 1);
        }
        // 2. �������� ���� createIterator()
        StackIter *createIterator() const;
};

// 1. ������������� ����� "iterator"
class StackIter
{
        const Stack *stk;
        int index;
    public:
        StackIter(const Stack *s)
        {
            stk = s;
        }
        void first()
        {
            index = 0;
        }
        void next()
        {
            index++;
        }
        bool isDone()
        {
            return index == stk->sp + 1;
        }
        int currentItem()
        {
            return stk->items[index];
        }
};

inline StackIter *Stack::createIterator()const
{
    return new StackIter(this);
}

inline bool operator == (const Stack &l, const Stack &r)
{
    // 3. ������� ����������� �������� ������� StackIter � ������� Stack
    StackIter *itl = l.createIterator();
    StackIter *itr = r.createIterator();
    // 4. ������� ���������� first(), isDone(), next(), and currentItem()
    for (itl->first(), itr->first();
         !itl->isDone();
         itl->next(), itr->next() )
        if (itl->currentItem() != itr->currentItem())
            break;
    bool ans = itl->isDone() && itr->isDone();
    delete itl;
    delete itr;
    return ans;
}

#endif // ITERATOR_H

