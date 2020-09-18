#include "head.h"



/* ��Ԫ������Ԫ��������Ԫ��
* ��Ԫ������
*	���������A��A�����Ƿǳ�Ա����������Ϊ��C����Ԫ������
	��ô����A����ֱ�ӷ�����C��������г�Ա
* ��Ԫ�ࣺ
	�������A����Ϊ��C����Ԫ�࣬��ô��A�����г�Ա����ֱ�ӷ�����C��������г�Ա

*	��Ԫ�ƻ����������ķ�װ�ԣ�����ĳЩƵ�����ʳ�Ա�����ĵط������������
*/

class Point
{

public:
	Point() {}
	Point(int x, int y)
		: m_x(x)
		, m_y(y)
	{}

	int GetX()
		return m_x;
	int GetY()
		return m_y;
private:
	int m_x;
	int m_y;
};

Point Add1(Point po1, Point po2)
{
	return Point(po1.m_x + po2.m_x, po1.m_y + po2.m_y);
}

int main()
{
	Point po1(10, 20);
	Point po2(20, 30);

	Add1(po1, po2);

	return 0;
}