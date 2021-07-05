#ifndef ITERATOR2_H
#define ITERATOR2_H

class Stack2
{
    int items[10];
    int sp;
  public:
    friend class StackIter2;
    Stack2()
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
};

class StackIter2
{
    const Stack2 &stk;
    int index;
  public:
    StackIter2(const Stack2 &s): stk(s)
    {
        index = 0;
    }
    void operator++()
    {
        index++;
    }
    bool operator()()
    {
        return index != stk.sp + 1;
    }
    int operator *()
    {
        return stk.items[index];
    }
};

bool operator == (const Stack2 &l, const Stack2 &r)
{
  StackIter2 itl(l), itr(r);
  for (; itl(); ++itl, ++itr)
    if (*itl !=  *itr)
      break;
  return !itl() && !itr();
}

#endif // ITERATOR2_H

