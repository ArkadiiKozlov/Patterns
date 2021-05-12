#ifndef WARRIORFACTORY_H
#define WARRIORFACTORY_H
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Factory;

map <string, Factory *> m_f;

// Иерархия классов игровых персонажей

class Warrior
{
  public:

    virtual void info() = 0;
    virtual ~Warrior() {}
};

class Infantryman2: public Warrior
{
  public:
    Infantryman2 () {
         cout << "ctor Infantryman2"<< endl;
         a = 1;
    }

    int a;

    void info() {
      cout << "Infantryman2 lives, a: "<<  a << endl;
    };

};

class Archer2: public Warrior
{
  public:
    Archer2 () {
      cout << "ctor Archer2"<< endl;
      b = 2;
    }

   int b;

   void info() {
      cout << "Archer2 lives, b: "<< b << endl;

    };

};

class Horseman2: public Warrior
{
  public:
    Horseman2 () {
      cout << "ctor Horseman2" << endl;
      c = 3;
    }

    int c;

    void info() {
      cout << "Horseman2 lives, c: "<< c << endl;
    };
};


// Фабрики объектов
class Factory
{
  public:
    virtual Warrior* createWarrior() = 0;
    virtual ~Factory() {}
};

class InfantryFactory: public Factory
{
  public:
    InfantryFactory () {
      cout << "ctor InfantryFactory was called" << endl;
      m_f["Infantryman2"] = this;

    }

    Warrior* createWarrior() {
      return new Infantryman2;
    }
};

//create factory
InfantryFactory infanty_factory1;

class ArchersFactory: public Factory
{
  public:
    ArchersFactory () {
      m_f["Archer2"] = this;
    }
    Warrior* createWarrior() {
      return new Archer2;
    }
};
ArchersFactory archersFactory1;

class CavalryFactory: public Factory
{
  public:
    CavalryFactory () {
      m_f["Horseman2"] = this;
    }

    Warrior* createWarrior() {
      return new Horseman2;
    }
};
CavalryFactory cavalryFactory1;

#endif // WARRIORFACTORY_H

