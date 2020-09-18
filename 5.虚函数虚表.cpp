#include "head.h"

/*
 * c++的多态通过虚函数 virtual function 来实现
 * 虚函数： 被virtual修饰的成员函数
 * 只要在父类中被声明位虚函数，子类中重写的函数也自动变成虚函数
 * 即子类中可以省略virtual关键字
 */

/*
 * 虚函数的实现原理是虚表，这个虚表里面存储着最终需要调用的虚函数地址
 * 所以虚表也叫虚函数表
 */
class Animal
{
public:
	Animal() {}
	~Animal() {}

	virtual void speak()
	{
		cout << "virtual Animal::Speak()" << endl;
	}

	virtual void run()
	{
		cout << "virtual Animal::Run()" << endl;
	}

	void testAnimal()
	{
		cout << "Animal::testAnimal()" << endl;
	}

public:
	int m_animal;
private:

};

class Cat : public Animal
{
public:
	Cat() {}
	~Cat() {}

	//void speak()
	//{
	//	cout << " Cat::Speak()" << endl;
	//}

	void run()
	{
		cout << " Cat::Run()" << endl;
	}

	void testCat()
	{
		cout << "Cat::testCat()" << endl;
	}
public:
	int m_cat;
};


//1.类中声明了虚函数后，其内存大小增加4，用来存储对象的地址
void test1()
{
	//有虚函数大小为8
	Animal anim;
	cout << sizeof(anim) << endl;

	//继承父类，有虚函数大小为12
	Cat cat;
	cout << sizeof(cat) << endl;
}

//2.所有的cat对象（不管在全局区，栈区，堆）公用一份虚表

//3.子类指针与父类指针
void test3()
{
	Cat* p1 = new Cat();
	p1->testAnimal(); /* Animal::testAnimal() */
	p1->testCat();    /* Cat::testCat()*/
	p1->speak();      /* Cat::Speak() */
	p1->m_animal = 10;
	p1->m_cat = 20;
	delete p1;

	cout << "---" << endl;

	//子类指针指向父类对象
	Cat* p2 = (Cat*) new Animal();
	p2->testAnimal();       //Animal::testAnimal()
	p2->testCat();          //Cat::testCat()
	
	p2->m_animal = 10;
	//p2->m_cat = 20;		//不安全，申请的堆空间没有m_cat内存

	p2->speak();			//virtual Animal::Speak()

	delete p2;
	cout << "---" << endl;
	//父类指针指向子类对象
	Animal* p3 =  new Cat();
	p3->testAnimal();
	//p3->testCat();		//err,在Animal类中找不到成员

	p3->m_animal = 10;
	//p3->m_cat = 20;		//err,在Animal类中找不到成员

	p3->speak();			//Cat::Speak()

	delete p3;
}

/*4.虚函数的实现原理是虚表，
*  这个虚表里面存储着最终需要调用的虚函数地址，虚表也叫虚函数表
*/
void test4()
{
	/*所有的Cat对象（不管在全局区、栈、堆）共用同一份虚表*/
	Animal* pCat = new Cat();
	pCat->m_animal = 20;
	
	/*
	* 虚表分析：
	* 1. 拿到pcat指针变量里面存储的地址值，即cat对象的地址值
	* 2. 取出cat对象的前面4个字节， 即虚表的地址
	*   （后面的地址依次是Cat类成员变量m_animal, m_cat的地址，值分别为20，0）
	* 3. 取出虚表中的前面4个字节，即Cat::speak()函数的地址
	* 4. 取出虚表中再之后的4字节，即Cat::run()函数的地址
	*/
	pCat->speak();	/* Cat::Speak() */
	pCat->run();	/* Cat::Run() */

	/* 假如在子类中只重写了父类的一个虚函数
	*  比如只重写了run(), 
	*  speak()的调用依然需要通过虚表来获取speak函数地址
	*  pCat->speak();	// virtual Animal::Speak() 
	*  pCat->run(); 	// Cat::Run() 
	*/

	delete pCat;
}

/*5. 子类调用父类成员函数
* 场景：子类的虚函数有重写父类函数，但是还想保留父类函数的功能
* 可以通过重写父类函数的同时，直接在函数里面调用父类的函数
*/
class A 
{
public:
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
};
class AB : public A
{
public:
	virtual void func()
	{
		A::func();
		cout << "AB::func()" << endl;
	}

};
void test5()
{
	A* p = new AB();
	p->func(); // A::func() 	AB::func()
}


//6.纯虚函数， 抽象类（含有纯虚函数的类）
/*
* 纯虚函数：没有函数体且初始化为0的虚函数，用来定义接口规范
* 抽象类（Abstract Class）
* 不可以实例化（不可以创建对象）
* 抽象类也可以包含非纯虚函数、成员变量
* 如果父类是抽象类，子类没有完全重写纯虚函数，那么这个子类依然是抽象类
*/
class Abstract
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};

class A_B : public Abstract
{
	void func1() {}
	//void func2() {}
};
void test6()
{
	//1.抽象类不能实例化
	//Abstract a; //err
	//Abstract* p = new Abstract(); //err
	//2.
	//A_B ab; //err， 子类只有全部重写父类的纯虚函数，自己才不是抽象类
}

/*7.虚析构函数
* 如果存在父类指针指向子类对象的情况，
* 应该将父类的析构函数声明为虚函数（虚析构函数）
* delete父类指针时，才会调用子类的析构函数，保证析构的完整性
*/
class Person
{
public:
	virtual void run()
	{
		cout << "Person::run()" << endl;
	}
	//虚析构函数，保证析构的完整性，
	//否则析构时候只会看指针的类型，不会去看赋值的对象
	 ~Person()
	{
		cout << "Person:: ~Person()" << endl;
	}
};
class Student: public Person
{
public:
	void run()
	{
		cout << "Student::run()" << endl;
	}

	~Student()
	{
		cout << "Student:: ~Student()" << endl;
	}
};

void test7()
{
	Person* p = new Student();
	p->run();
	delete p;
}
//
//int main()
//{
//	
//	test7(); //析构完全：Student::~Student(), Person::~Person()
//
//	return 0;
//}
