//////////////////////Factory Method Pattern/////////////////////////
#ifndef WARRIORFACTORY_H
#define WARRIORFACTORY_H
#include <iostream>
#include <vector>
#include <map>
namespace FactoryMethod1 {

class Factory;

map <string, Factory *> m_f;
// Иерархия классов игровых персонажей
class Warrior
{
  public:

    virtual void info() = 0;
    virtual ~Warrior() {}
};

class Infantryman: public Warrior
{
  public:
    Infantryman () {
         cout << "ctor Infantryman2"<< endl;
         a = 1;
    }

    int a;

    void info() {
      cout << "Infantryman lives, a: "<<  a << endl;
    };

};

class Archer: public Warrior
{
  public:
    Archer () {
      cout << "ctor Archer"<< endl;
      b = 2;
    }

   int b;

   void info() {
      cout << "Archer lives, b: "<< b << endl;

    };

};

class Horseman: public Warrior
{
  public:
    Horseman () {
      cout << "ctor Horseman" << endl;
      c = 3;
    }

    int c;

    void info() {
      cout << "Horseman lives, c: "<< c << endl;
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
      m_f["Infantryman"] = this;

    }

    Warrior* createWarrior() {
      return new Infantryman;
    }
};

//create factory
InfantryFactory infanty_factory;

class ArchersFactory: public Factory
{
  public:
    ArchersFactory () {
      m_f["Archer"] = this;
    }
    Warrior* createWarrior() {
      return new Archer;
    }
};
ArchersFactory archersFactory1;

class CavalryFactory: public Factory
{
  public:
    CavalryFactory () {
      m_f["Horseman"] = this;
    }

    Warrior* createWarrior() {
      return new Horseman;
    }
};
CavalryFactory cavalryFactory;
};
#endif // WARRIORFACTORY_H

