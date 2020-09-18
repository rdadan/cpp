#include "head.h"
/*静态成员 static
* 静态成员变量
* 静态成员函数
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
 
/*一.静态成员变量
* 1.1.初始化：在类外初始化,类外不用再加static
* 1.2.存储空间： 存储在数据段（静态全局区，类似于全局变量，但是受类的限制），整个程序运行过程中只有一份内存
*			  对比全局变量，他可以设定访问权限（public，protected，private），达到局部共享目的
* 1.3.访问:可以通过对象,对象指针，类访问
*/

/*1.1 初始化*/
int Person7::s_age = 0;
int Person7::s_a = 0; //私有的也可以在类外初始化，但对象访问不到

/*1.3 访问*/
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

	cout << sizeof(obj) << endl; // x86,栈8字节，说明静态成员不存储栈区
}

/*二.静态成员函数*/

/*
*2.1 可以通过对象，对象指针，类名访问
*2.2 内部不能使用this指针，（this指针只能在非静态成员函数内部）
     因为this存储对象的地址值，而静态成员函数不属于某个具体的对象
	 this只能用在 非静态成员函数内部
*2.3 静态成员函数内部访问不能非静态成员变量或非静态成员函数
	 因为当创建对象的时候才会有成员变量，而静态成员函数可通过类名访问，根本就没有对象
	 另外，如果可以访问非静成员函数（通过对象调用，里面有this指针），
	 这样就可以变相访问非静态成员了

*2.4 不能是虚函数，虚函数只能是非静态成员函数
	  因为virtual用在多态， 父类指针指向子类对象，来调用虚函数
*2.5 相反，静态成员函数内部可以访问静态成员函数/变量
*2.6 构造，析构不能是静态
*2.7 实现可声明分离时，实现部分不能带static
*/

//int main()
//{
//	test7_1();
//	return 0;
//}