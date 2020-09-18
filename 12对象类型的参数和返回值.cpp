#include "head.h"

namespace space_12
{

/* 如果使用对象类型 作为函数的参数或返回值，
* 可能会产生一些不必要的中间对象
*/


class Car
{
public:
	Car()
	{
		cout << "Car::Car()  " << this  <<endl;
	}

	//禁止掉隐式构造
	//explicit Car(int price)
	Car(int price)
		:m_price(price)
	{
		cout << "Car::Car(int price)  " << this << endl;
	}

	Car(const Car & car)
		:m_price(car.m_price)
	{
		cout << "Car::Car(const Car & car)  " << this << endl;
	}

	void display()
	{
		cout << "display(): m_price = " << m_price << endl;
	}
	
	~Car()
	{
		cout << "Car::~Car()  " << this << endl;
	}

private:
	int m_price;

};

/*对象作为函数参数
* 实参对象给形参对象赋值时，会调用拷贝构造函数
* 所以可以改成引用或者指针必须多余的拷贝
*/
void test_1(Car  car) 
{
	
}



/*对象作为函数返回值
* 一般不要这样用
*/
Car test_2()
{
	Car car; //调用 Car::Car()
	//调用 Car::Car(const Car & car), 
	//将test2()栈空间中的car对象 拷贝到 main函数中的栈空间、
	//在调用test2()的时候就以及将对象返回值的空间预留好了
	return car; 

}


void test_3()
{

	Car car1(1); // Car::Car()
	Car car2(2);
	car1 = car2; //不调用构造函数
	cout << "---------------" << endl;

	//对象作为参数，调用拷贝构造
	test_1(car1); //Car::Car(const Car & car)，参数可以改成引用或者指针

	cout << "---------------" << endl;
	//对象作为返回值
	car1 = test_2(); //Car::Car()  0096F984
					 //Car::Car(const Car & car)  0096F9C0

	cout << "---------------" << endl;

	Car car3 = test_2(); //Car::Car()  008FFA28； 
						 //Car::Car(const Car & car)  008FFB28
}

/*匿名对象
* 没有变量名，没有被指针指向的对象，用完后马上调用析构
* 如果匿名对象作为返回值或者函数参数的话， 和普通对象不一样，编译器会做一下优化
*/
void test_4()
{
	Car(10); //匿名对象 Car::Car(int price)  0116FC74
	Car(20).display();

	cout << "匿名对象给其他对象赋值" << endl;
	Car car1 = Car(30); //Car::Car(int price)  010FF80C


	cout << "匿名对象作为参数： " << endl;;
	test_1(Car(40)); //Car::Car(int price)  010FF6F0  没有调拷贝构造

	cout << "匿名对象作为返回值case1: " << endl;
	Car car2 = test_2(); //Car::Car()  010FF6D0
					     //Car::Car(const Car & car)  010FF800

	cout << "匿名对象作为返回值case2: " << endl;
	car1 = test_2();  //Car::Car()  010FF6D0
					  //Car::Car(const Car & car)  010FF710

}

/*
*c++中存在隐式的构造现象，在某些情况下，
*会隐式的调用单参的构造函数
*可以通过关键字explicit 禁止掉隐式构造
*/
void test_5()
{
	Car car1 = 10; //Car(int price)

	Car car2(20);//Car(int price)
	car2 = 30;	//Car(int price)

	test_1(10); //Car(int price)

	Car car3 = test_2(); //Car(int price)
}

/*编译器提供的构造函数
*C++的编译器在某些特定的情况下，会给类自动生成无参的构造函数，比如
* 1.成员变量在声明的同时进行了初始化
* 2.有定义虚函数
* 3.虚继承了其他类
* 4.包含了对象类型的成员，且这个成员有构造函数（编译器生成或自定义）
* 5.父类有构造函数（编译器生成或自定义）
* 总结一下
* ->对象创建后，需要做一些额外操作时（比如内存操作、函数调用），编译器一般都会为其自动生成无参的构造函数 
*/

}//namespace



//using namespace space_12;
//int main()
//{
//	test_3();
//	return 0;
//}