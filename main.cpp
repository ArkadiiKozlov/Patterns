#include <string>
#include "Warriorfactory.h"
#include "Adapter.h"
#include "Logger.h"
#include "Composite1.h"


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
  std::cout << "Client: I can work just fine with the Target objects:\n";
  Target *target = new Target;
  ClientCode(target);
  std::cout << "\n\n";
  Adaptee *adaptee = new Adaptee;
  std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
  std::cout << "Adaptee: " << adaptee->SpecificRequest();
  std::cout << "\n\n";
  std::cout << "Client: But I can work with it via the Adapter:\n";
  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  delete adaptee;
  delete adapter;
  delete target;

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
