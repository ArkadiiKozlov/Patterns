#include "Composite1.h"

// ��������������� ������� ��� �������� �������
CompositeUnit* createLegion()
{
  // ������� ������ ��������:
  CompositeUnit* legion = new CompositeUnit;
  // 3000 ������� ����������
  for (int i=0; i<3000; ++i)
    legion->addUnit(new Infantryman);
  // 1200 ������ ����������
  for (int i=0; i<1200; ++i)
    legion->addUnit(new Archer);
  // 300 ���������
  for (int i=0; i<300; ++i)
    legion->addUnit(new Horseman);

  return legion;
}
