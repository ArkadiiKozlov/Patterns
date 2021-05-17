#include <string>
#include "Logger.h"
#include "Composite1.h"
#include "Warriorfactory.h"

using namespace FactoryMethod1;

int main()
{
  cout << "Design Patterns" << endl;
  //////////////////////Factory Method/////////////////////////
  cout << "Factory Method Pattern 1" << endl;
  string s = "Infantryman"; // reading from the file, for example
  vector<Warrior*> v;
  v.push_back(m_f[s]-> createWarrior());
  s = "Archer";
  v.push_back(m_f[s]-> createWarrior());
  s = "Horseman";
  v.push_back(m_f[s]-> createWarrior());
  for(int i=0; i<v.size(); i++) {
       v[i]->info();
  }

  cout << endl << "Structural Patterns" << endl;
  ////////////////////////Adapter///////////////////////////////
  cout << "Adapter" << endl;
  cout << "...." << endl;

  ////////////////////////Bridge Patterns//////////////////////
  cout << endl << "Bridge" << endl;
  string s2 = "log.txt";
  //Logger * p = new FileLogger( string("log.txt"));
  Logger * p = new FileLogger(s2);
  string s1 = "message";
  //p->log(std::string("message"));
  //p->log("message");
  p->log(s1);
  delete p;

  ///////////////////////////Composite Pattern///////////////////
  cout << endl << "Composite Pattern" << endl;
  // Rome army has 4 legions;
  CompositeUnit* army = new CompositeUnit;
  for (int i=0; i<4; ++i)
  army->addUnit( createLegion());
  cout << "Roman army damaging strength is "<< army->getStrength() << endl;
  delete army;

  return 0;
}
