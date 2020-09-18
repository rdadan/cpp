#include "head.h"

class Person
{
public:
	Person()
	{
		cout << "Person::Person()" << endl;
	}

	~Person()
	{
		cout << "Person::~Person()" << endl;
	}

};

class Student : public Person
{
public:
	Student()
	{
		cout << "Student::Student()" << endl;
	}
	~Student()
	{
		cout << "Student::~Student()" << endl;
	}
};

//int main()
//{
//	Student s;
//	return 0;
//	//µ÷ÓÃË³Ðò£º
//	//  Person::Person()
//	//	Student::Student()
//	//	Student::~Student()
//	//	Person::~Person()
//
//}