#include "head.h"

class Person
{
public:

	Person()
	{	cout << "Person::Person()" << endl;	}

	Person(int age)
	: m_age(age)
	{	cout << "Person::Person(int age)" << endl;	
		cout << "m_age: " << m_age << endl;
	}


private:
	int m_age;
};

class Student : public Person
{
public:
	
	//1.
	//Student()
	//{
	//	cout << "Student::Student()" << endl;
	//}

	//2.
	Student()
	{
		cout << "Student::Student()" << endl;
	}

	//4.
	Student(int age, int no)
	: m_no(no),
	  Person(age) 
	{
		cout << "Student::Student(int age, int no)" << endl;
		cout << "m_no: " << no << endl;
	}
private:
	int m_no;


};


//int main()
//{
//
//	//1.子类的构造函数会默认调用父类的无参构造函数
//	Student student; //会调用Person::Person()
//
//	//2.如果子类的构造函数显示的调用父类的有参构造函数，
//	//就不会再去默认调用父类的无参构造函数
//
//	//3.如果父类没有无参（默认）构造函数，
//	//子类的构造函数必须显示调用父类的有参构造函数
//
//	//4.调用父类的构造函数来初始化父类的私有成员
//	Student student1(1, 23);
//	return 0;
//}

