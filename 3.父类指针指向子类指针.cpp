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
	//1.����ָ�� ָ�� ����ָ�룬�̳еķ�ʽ������public
	Person* p = new Student();
	p->m_age = 10;


	//����������ָ��ָ�������
	Student* p1 = (Student*)new Person();//���Ա���ͨ�������ǲ���ȫ,��Ϊֻ�������ĸ��ռ�
	p1->m_age = 10;
	p1->m_score = 100;//����ط�����m_age�ĸ��ֽں󣬿��ܻὫ��ĵ�ַ��ֵ����

	return 0;
}
*/