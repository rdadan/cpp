//#include "head.h"
//
//namespace space13
//{
//
///* 友元包括友元函数和友元类
//* 友元函数：
//*	如果将函数A（A必须是非成员函数）声明为类C的友元函数，
//	那么函数A就能直接访问类C对象的所有成员
//* 友元类：
//	如果将类A声明为类C的友元类，那么类A的所有成员函数都能直接访问类C对象的所有成员
//
//*	友元破坏了面向对象的封装性，但在某些频繁访问成员变量的地方可以提高性能
//*/
//
//class Point
//{
//
//	//声明友元函数,直接访问私有成员
//	friend Point Add2(Point po1, Point po2);
//	friend int testfriend();
//
//	//声明友元类，直接在类内部访问Point的所有成员
//	//1.类中所有成员都是友元
//	//friend class Math; 
//
//	//2.只有Math::Add() 为友元
//	friend Point Math::Add(Point po1, Point po2);
//
//public:
//	Point() {}
//
//	Point(int x, int y)
//		: m_x(x)
//		, m_y(y)
//	{}
//
//	int GetX()
//	{
//		return m_x;
//	}
//		
//	int GetY()
//	{
//		return m_y;
//	}
//		
//	void display()
//	{
//		cout << "x: " << m_x << "  y: " << m_y << endl;
//	}
//private:
//	int m_x;
//	int m_y;
//};
// int testfriend()
//{
//	Point p;
//	p.m_x = 10;
//}
////友元类
//class Math
//{
//public:
//	Point Add(Point po1, Point po2)
//	{
//		return Point(po1.m_x + po2.m_x, po1.m_y + po2.m_y);
//	}
//	Point AddTest()
//	{
//		//Point po;
//		//po.m_x = 1;
//	}
//};
//
////非友元函数
////如果频繁调用封装的方法，不断的有栈空间的申请和销毁，效率低
//Point Add1(Point po1, Point po2)
//{
//	return Point(po1.GetX() + po2.GetX(), po1.GetY() + po2.GetY());
//}
//
////友元函数
//Point Add2(Point po1, Point po2)
//{
//	return Point(po1.m_x + po2.m_x, po1.m_y + po2.m_y);
//}
//
//void test1()
//{
//	Point po1(10, 20);
//	Point po2(20, 30);
//
//	Add1(po1, po2).display(); //Add1非友元
//	Add2(po1, po2).display(); //Add2友元
//
//	Point po = Math().Add(po1, po2); //Math为Point的友元类
//	po.display();
//}
//
//
//}//end space
//using namespace space13;
//
////int main()
////{
////	test1();
////	return 0;
////}