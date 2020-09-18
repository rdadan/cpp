#include "head.h"

//重载：函数名一样，参数不一样
//重写（覆盖override）：子类继承父类的函数，实现自己的功能
//					   函数名，返回值，参数都和父类一模一样


/* 多态：
 * 同一操作作用于不同的对象，可以有不同的解释，产生不同的效果
 * 在运行时，可以识别真正的对象类型，调用对应子类中的函数
 * 但是c++默认情况下不存在多态,只会根据指针的类型调用对应的函数

 * 多态的三个要素：
 * 子类重写父类的函数 override
 * 父类的指针指向子类的对象
 * 利用父类指针调用重写的函数
*/

/* 虚函数 virtual，来实现多态
 * 只要在父类中声明为虚函数，子类中重写的函数也自动变成虚函数
*/


class Animal
{
public:
	
	virtual void run() //virtual 实现多态
	{
		cout << "virtual Animal::run()" << endl;
	}
	void speak() //不能实现多态，指针类型根据自己的类型各自调用函数
	{
		cout << "Animal::speak()" << endl;
	}

	Animal()
	//: m_age(0) 
	{}
	~Animal() {}
public:
	int m_age;
};

class Dog : public Animal
{
public:
	void run()
	{
		cout << "virtual Dog::run()" << endl;
	}

	void speak()
	{
		cout << "Dog::speak()" << endl;
	}
};

class Cat : public Animal
{
public:
	void run()
	{
		cout << "virtual Cat::run()" << endl;
	}

	void speak()
	{
		cout << "Cat::speak()" << endl;
	}
};

void Play(Animal * p)
{
	p->run();
	p->speak();
}

#if 0
int main()
{
	//virtual void run() 
	//void speak() 
	Cat* p = (Cat*) new Dog(); //会将成员初始化为0
	p->run(); //virtual Dog::run()
	p->speak();//Cat::speak()
	cout << p->m_age << endl;
	delete p;
	p = NULL;

	Dog* pDog = new Dog();
	Cat* pCat = new Cat();

	Play(pDog);//Dog::run(), Animal::speak())  
	Play(pCat);//Cat::run(), Animal::speak()

	delete pDog;
	delete pCat;
	/*
	int arr_size = 5;
	//int* arr = new int [arr_size]();//5个全初始化为0
	int* arr = new int[arr_size] {6,5,4};//前三个分别初始化为6，5，4， 其余为0

	while (arr && arr_size--)
	{
		//cout << *arr << endl;
		//++arr;
		cout << *(arr++) << endl;
	}
	*/
	return 0;
}
#endif