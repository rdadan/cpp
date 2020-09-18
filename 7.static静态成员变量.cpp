#include "head.h"
/*��̬��Ա static
* ��̬��Ա����
* ��̬��Ա����
*
*/


class Person7
{
public:
	Person7() {}
	~Person7() {}

	static int s_age;
	int m_height;
	char* name;

	void display()
	{
		this->m_height = 0;
		m_height = 0;
		cout << "static s_age: " << s_age << endl;
		//cout << "static s_a: " << s_a << endl;
	}

	

	static void run()
	{
		//this->m_height = 0; //err 2.1
		//m_height = 0; // err 2.2
		//display(); //err 2.3
		cout << "static void run()" << endl;
	}
	static void run2();
	//virtual static void run() {} //err 2.4
private:
	static int s_a;
};
//static void Person7::run2() {}  //err 2.7
 
/*һ.��̬��Ա����
* 1.1.��ʼ�����������ʼ��,���ⲻ���ټ�static
* 1.2.�洢�ռ䣺 �洢�����ݶΣ���̬ȫ������������ȫ�ֱ�����������������ƣ��������������й�����ֻ��һ���ڴ�
*			  �Ա�ȫ�ֱ������������趨����Ȩ�ޣ�public��protected��private�����ﵽ�ֲ�����Ŀ��
* 1.3.����:����ͨ������,����ָ�룬�����
*/

/*1.1 ��ʼ��*/
int Person7::s_age = 0;
int Person7::s_a = 0; //˽�е�Ҳ�����������ʼ������������ʲ���

/*1.3 ����*/
void test7_1()
{
	Person7 obj;
	obj.s_age = 5;
	//obj.s_a = 3;  //err
	obj.display();

	Person7* p = new Person7();
	p->s_age = 6;
	p->display();
	cout << "Person::s_age : " << Person7::s_age << endl;

	cout << sizeof(obj) << endl; // x86,ջ8�ֽڣ�˵����̬��Ա���洢ջ��
}

/*��.��̬��Ա����*/

/*
*2.1 ����ͨ�����󣬶���ָ�룬��������
*2.2 �ڲ�����ʹ��thisָ�룬��thisָ��ֻ���ڷǾ�̬��Ա�����ڲ���
     ��Ϊthis�洢����ĵ�ֵַ������̬��Ա����������ĳ������Ķ���
	 thisֻ������ �Ǿ�̬��Ա�����ڲ�
*2.3 ��̬��Ա�����ڲ����ʲ��ܷǾ�̬��Ա������Ǿ�̬��Ա����
	 ��Ϊ�����������ʱ��Ż��г�Ա����������̬��Ա������ͨ���������ʣ�������û�ж���
	 ���⣬������Է��ʷǾ���Ա������ͨ��������ã�������thisָ�룩��
	 �����Ϳ��Ա�����ʷǾ�̬��Ա��

*2.4 �������麯�����麯��ֻ���ǷǾ�̬��Ա����
	  ��Ϊvirtual���ڶ�̬�� ����ָ��ָ����������������麯��
*2.5 �෴����̬��Ա�����ڲ����Է��ʾ�̬��Ա����/����
*2.6 ���죬���������Ǿ�̬
*2.7 ʵ�ֿ���������ʱ��ʵ�ֲ��ֲ��ܴ�static
*/

//int main()
//{
//	test7_1();
//	return 0;
//}