#include <string>
#include "Warriorfactory.h"
#include "Prototype1.h"
#include "Adapter.h"
#include "Logger.h"
#include "Composite1.h"
#include "Command.h"
#include "Iterator.h"
#include "Iterator2.h"

int main()
{

  cout << "Design Patterns" << endl;
  //////////////////////Factory Method/////////////////////////
  cout << "Factory Method Pattern 1" << endl;  
  string s = "Infantryman"; // reading from the file, for example
  //using namespace FactoryMethod1;
  vector<FactoryMethod1::Warrior*> v;
  v.push_back(FactoryMethod1::m_f[s]-> createWarrior());
  s = "Archer";
  v.push_back(FactoryMethod1::m_f[s]-> createWarrior());
  s = "Horseman";
  v.push_back(FactoryMethod1::m_f[s]-> createWarrior());
  for(int i=0; i<v.size(); i++) {
       v[i]->info();
  }

  //////////////////////Prototype/////////////////////////
  cout<< endl << "Prototype" << endl;
  //using namespace PrototypePattern;
  PrototypePattern::PrototypeFactory factory;
  std::vector< PrototypePattern::Warrior* > v2;
  v2.push_back( factory.createInfantrman());
  v2.push_back( factory.createArcher());
  v2.push_back( factory.createHorseman());
  for(int i=0; i<v2.size(); i++)
      v2[i]->info();

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
  string str2 = "log.txt";
  //Logger * p = new FileLogger( string("log.txt"));
  Logger * p = new FileLogger(str2);
  string str1 = "message";
  //p->log(std::string("message"));
  //p->log("message");
  p->log(str1);
  delete p;

  ///////////////////////////Composite Pattern///////////////////
  cout << endl << "Composite Pattern" << endl;
  // Rome army has 4 legions;
  CompositeUnit* army = new CompositeUnit;
  for (int i=0; i<4; ++i)
  army->addUnit( createLegion());
  cout << "Roman army damaging strength is "<< army->getStrength() << endl;
  delete army;

  cout << endl << "Behavior Patterns" << endl;
  //////////////////////////Command///////////////////////////////
  cout << "Command" << endl;
  //Клиентский код может параметризовать отправителя любыми командами.
  Invoker *invoker = new Invoker;
  invoker->SetOnStart(new SimpleCommand("Say Hi!"));
  Receiver *receiver = new Receiver;
  invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
  invoker->DoSomethingImportant();
  delete invoker;
  delete receiver;

  //////////////////////////Iterator/////////////////////////////
  cout << "Iterator" << endl;
  Stack s1;
  for (int i = 1; i < 5; i++)
    s1.push(i);
  Stack s2(s1), s3(s1), s4(s1), s5(s1);
  s3.pop();
  s5.pop();
  s4.push(2);
  s5.push(9);
  cout << "1 == 2 is " << (s1 == s2) << endl;
  cout << "1 == 3 is " << (s1 == s3) << endl;
  cout << "1 == 4 is " << (s1 == s4) << endl;
  cout << "1 == 5 is " << (s1 == s5) << endl;

  cout << "Iterator2" << endl;
  Stack2 s1_2;
  int i;
  for (i = 1; i < 5; i++)
    s1_2.push(i);
  Stack2 s2_2(s1_2), s3_2(s1_2), s4_2(s1_2), s5_2(s1_2);
  s3_2.pop();
  s5_2.pop();
  s4_2.push(2);
  s5_2.push(9);
  cout << "1 == 2 is " << (s1_2 == s2_2) << endl;
  cout << "1 == 3 is " << (s1_2 == s3_2) << endl;
  cout << "1 == 4 is " << (s1_2 == s4_2) << endl;
  cout << "1 == 5 is " << (s1_2 == s5_2) << endl;
   
  // branch stdying, vega4k, 2 commit

  // branch stdying, vega4k, 3 commit
  return 0;
}
