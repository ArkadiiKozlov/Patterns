#include "Composite1.h"

// Вспомогательная функция для создания легиона
CompositeUnit* createLegion()
{
  // Римский легион содержит:
  CompositeUnit* legion = new CompositeUnit;
  // 3000 тяжелых пехотинцев
  for (int i=0; i<3000; ++i)
    legion->addUnit(new Infantryman);
  // 1200 легких пехотинцев
  for (int i=0; i<1200; ++i)
    legion->addUnit(new Archer);
  // 300 всадников
  for (int i=0; i<300; ++i)
    legion->addUnit(new Horseman);

  return legion;
}
