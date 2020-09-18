#include "head.h"



/* 友元包括友元函数和友元类
* 友元函数：
*	如果将函数A（A必须是非成员函数）声明为类C的友元函数，
	那么函数A就能直接访问类C对象的所有成员
* 友元类：
	如果将类A声明为类C的友元类，那么类A的所有成员都能直接访问类C对象的所有成员

*	友元破坏了面向对象的封装性，但在某些频繁访问成员变量的地方可以提高性能
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