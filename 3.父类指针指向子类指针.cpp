#include "head.h"

class Person
{
public:
	int m_age;
};

class Student : public Person
{
public:
	int m_score;
};

/*
int main()
{
	//1.父类指针 指向 子类指针，继承的方式必须是public
	Person* p = new Student();
	p->m_age = 10;


	//不允许子类指针指向父类对象
	Student* p1 = (Student*)new Person();//可以编译通过，但是不安全,因为只申请了四个空间
	p1->m_age = 10;
	p1->m_score = 100;//这个地方调过m_age四个字节后，可能会将别的地址的值覆盖

	return 0;
}
*/