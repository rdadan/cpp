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
//	//1.����Ĺ��캯����Ĭ�ϵ��ø�����޲ι��캯��
//	Student student; //�����Person::Person()
//
//	//2.�������Ĺ��캯����ʾ�ĵ��ø�����вι��캯����
//	//�Ͳ�����ȥĬ�ϵ��ø�����޲ι��캯��
//
//	//3.�������û���޲Σ�Ĭ�ϣ����캯����
//	//����Ĺ��캯��������ʾ���ø�����вι��캯��
//
//	//4.���ø���Ĺ��캯������ʼ�������˽�г�Ա
//	Student student1(1, 23);
//	return 0;
//}

