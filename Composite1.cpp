#include "Composite1.h"
//test on github.com
// ÷ÓÐÏÍÏÇÁÔÅÌØÎÁÑ ÆÕÎËÃÉÑ ÄÌÑ ÓÏÚÄÁÎÉÑ ÌÅÇÉÏÎÁ
CompositeUnit* createLegion()
{
  // òÉÍÓËÉÊ ÌÅÇÉÏÎ ÓÏÄÅÒÖÉÔ:
  CompositeUnit* legion = new CompositeUnit;
  // 3000 ÔÑÖÅÌÙÈ ÐÅÈÏÔÉÎÃÅ×
  for (int i=0; i<3000; ++i)
    legion->addUnit(new Infantryman);
  // 1200 ÌÅÇËÉÈ ÐÅÈÏÔÉÎÃÅ×
  for (int i=0; i<1200; ++i)
    legion->addUnit(new Archer);
  // 300 ×ÓÁÄÎÉËÏ×
  for (int i=0; i<300; ++i)
    legion->addUnit(new Horseman);

  return legion;
}
