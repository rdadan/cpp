//#include "head.h"
//
//namespace space13
//{
//
///* ��Ԫ������Ԫ��������Ԫ��
//* ��Ԫ������
//*	���������A��A�����Ƿǳ�Ա����������Ϊ��C����Ԫ������
//	��ô����A����ֱ�ӷ�����C��������г�Ա
//* ��Ԫ�ࣺ
//	�������A����Ϊ��C����Ԫ�࣬��ô��A�����г�Ա��������ֱ�ӷ�����C��������г�Ա
//
//*	��Ԫ�ƻ����������ķ�װ�ԣ�����ĳЩƵ�����ʳ�Ա�����ĵط������������
//*/
//
//class Point
//{
//
//	//������Ԫ����,ֱ�ӷ���˽�г�Ա
//	friend Point Add2(Point po1, Point po2);
//	friend int testfriend();
//
//	//������Ԫ�ֱ࣬�������ڲ�����Point�����г�Ա
//	//1.�������г�Ա������Ԫ
//	//friend class Math; 
//
//	//2.ֻ��Math::Add() Ϊ��Ԫ
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
////��Ԫ��
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
////����Ԫ����
////���Ƶ�����÷�װ�ķ��������ϵ���ջ�ռ����������٣�Ч�ʵ�
//Point Add1(Point po1, Point po2)
//{
//	return Point(po1.GetX() + po2.GetX(), po1.GetY() + po2.GetY());
//}
//
////��Ԫ����
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
//	Add1(po1, po2).display(); //Add1����Ԫ
//	Add2(po1, po2).display(); //Add2��Ԫ
//
//	Point po = Math().Add(po1, po2); //MathΪPoint����Ԫ��
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