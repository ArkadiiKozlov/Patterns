#include <string>
#include "Logger.h"
#include "Composite1.h"
#include "Warriorfactory.h"

int main()
{
  cout << "under git now" << endl;
  ///////////////////////////Bridge Pattern///////////////////
  string s2 = "log.txt";
  //Logger * p = new FileLogger( string("log.txt"));
  Logger * p = new FileLogger(s2);
  string s1 = "message";
  //p->log(std::string("message"));
  //p->log("message");
  p->log(s1);
  delete p;
  ///////////////////////////Composite Pattern///////////////////
  // Римская армия состоит из 4-х легионов
    CompositeUnit* army = new CompositeUnit;
    for (int i=0; i<4; ++i)
      army->addUnit( createLegion());

    cout << "Roman army damaging strength is "
         << army->getStrength() << endl;
    // ?
    delete army;
    /////////////////////////Factory Method Pattern////////////////
    cout << "Factory2" << endl;
    string s = "Infantryman2"; // reading from file, for example
    vector<Warrior*> v;
    v.push_back(m_f[s]-> createWarrior());
    s = "Archer2";
    v.push_back(m_f[s]-> createWarrior());
    s = "Horseman2";
    v.push_back(m_f[s]-> createWarrior());
    for(int i=0; i<v.size(); i++) {
         v[i]->info();
    }
    cout << ((Infantryman2*)v[0])->a << endl;

  return 0;
}
