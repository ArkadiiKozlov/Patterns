#ifndef COMPOSITE1
#define COMPOSITE1
#include <iostream>
#include <vector>
#include <assert.h>
// git check 1
// Component
class Unit
{
  public:
    virtual int getStrength() = 0;
    virtual void addUnit(Unit* p) {
      assert( false);
    }
    virtual ~Unit() {}
};

// Primitives
class Archer: public Unit
{
  public:
    virtual int getStrength() {
      return 1;
    }
};

class Infantryman: public Unit
{
  public:
    virtual int getStrength() {
      return 2;
    }
};

class Horseman: public Unit
{
  public:
    virtual int getStrength() {
      return 3;
    }
};


// Composite
class CompositeUnit: public Unit
{
  public:
    int getStrength() {
      int total = 0;
      for(unsigned int i=0; i<c.size(); ++i)
        total += c[i]->getStrength();
      return total;
    }
    void addUnit(Unit* p) {
        c.push_back( p);
        printf1 ("I'am composite object\n");
    }
    void printf1 (const char *) {
        //printf ("I'am composite object\n");
    }
    ~CompositeUnit() {
      for(unsigned int i=0; i<c.size(); ++i)
        delete c[i];
    }
  private:
   std::vector<Unit*> c;
};


CompositeUnit* createLegion();

#endif // COMPOSITE1

