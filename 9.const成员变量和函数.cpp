#include "head.h"

//常量指针与指针常量
void test9_1()
{
	int a = 10;
	int b = 20;
	//const 修饰的是右边的值  *p不可以改
	const int* p1 = &a; //常量指针（指向常量的指针，常量不能修改，指针可以修改指向
	//*p1 = 90; //err,
	p1 = &b;//ok
	int const* p2 = &a; //常量指针
	//*p2 = 90; //err
	p2 = &b;

	//p3不可以改
	int* const p3 = &a; //指针常量，常量值可以修改
	*p3 = 90;
	//p3 = &b;//err

}

class Car
{
public:
	const int m_price = 0; //1.1
	static const int m_price1 = 0; //即使static、又是const
	int color;
	static int s_length;
	Car()
		: m_price(0)
		//, m_price1(0) //1.2
	{}

	//static void run() const {} //err
	void run() const
	{
		//color = 0; //err 2.2
		s_length = 0;
		cout << " Car::run() " << endl;
	}
	
};
int Car::s_length = 0;

/*一. cosnt成员变量
* 1.1 必须初始化， 且在内部初始化，声明的时候可以直接初始化
* 1.2 非static的const成员变量还可以在初始化列表里初始化
*/

void test9_2()
{
	Car car; //1.1 不初始化这里报错
}
/*二. const成员（非静态）
* 2.1 const 关键字写在参数列表后面，函数的声明和实现都必须带const
* 2.2 内部不能修改非静态成员变量, 只能调用const成员函数，static成员函数
* 2.3 非const成员函数可调用const成员函数
* 2.4 const成员函数和非const成员函数构成重载
* 2.5 非cosnt对象（指针） 优先调用非const成员函数
* 2.6 const对象（指针）只能调用const成员函数，static成员函数
*/
