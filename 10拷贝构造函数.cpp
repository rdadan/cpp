#include "head.h"


class Car
{
public:
	Car(int price = 0, int length = 0)
		: m_price(price)
		, m_length(length)
	{
		//display();
		cout << "Car(int price = 0, int length = 0)" << endl;
	}

	//拷贝构造函数
	Car(const Car& car)
	: m_price(car.m_price)
	, m_length(car.m_length)
	{
		/*m_price = car.m_price;
		m_length = car.m_length;*/
		//display();
		cout << "Car(const Car& car)" << endl;
	}

	void display()
	{
		cout << "m_price: " << m_price << endl;
		cout << "m_length: " << m_length << endl;
	}

private:
	int m_price;
	int m_length;
};

/*一。拷贝构造函数
* 当利用已存在的对象创建另一个对象时，
* 就会调用新对象的拷贝构造函数进行初始化
* 格式固定，就收一个const引用的参数 Car(const Car& car) {}
* 如果对象的成员是全部都要拷贝的， 那就不需要单独定义拷贝构造函数了,
* 因为对象拷贝是会默认拷贝全部的成员
*/

void test10_1()
{
	Car car1(99,10);
	Car car2(car1);
}


/*二。调用父类的拷贝构造函数
* 子类互相对象拷贝时，如果需要复制父类的成员，
* 需要在子类的拷贝构造函数中，调用父类的拷贝构造函数
* 
*/

class Person
{
public:
	//构造函数
	Person(int age, int height)
	: m_age(age)
	, m_height(height)
	{
		cout << "构造函数，Person::Person(int age, int height)" << endl;
	}

	//父类的拷贝构造函数
	Person(const Person& person)
		:m_age(person.m_age)
		,m_height(person.m_height)
	{
		cout << "拷贝构造函数，Person(const Person& person)" << endl;
	}

	int getAge()
	{
		return m_age;
	}
public:
	int m_height;
private:
	int m_age;
};

class Student :public Person
{
public:
	//构造函数
	Student(int age, int height, int score)
	: m_score(score)
	, Person(age, height)
	{
		//m_height = height;
		display();
	}

	//子类的拷贝构造函数
	Student(const Student& stu)
		: Person(stu)
		, m_score(stu.m_score)
	{
		display();
	}

	void display()
	{
		cout << "m_age: " << getAge() << endl;
		cout << "m_height: " << m_height << endl;
		cout << "m_score: " << m_score << endl;
	}
private:
	int m_score;
};

void test10_2()
{
	Student stu1(1, 2, 3); //调用父类的构造函数
	Student stu2 = stu1; //调用父类的拷贝构造函数
}

/*三。注意事项
*构造函数只有在对象创建时初始化才调用
*/
void test10_3()
{
	Car car1(1, 2); // Car(int price = 0, int length = 0)
	Car car2 = car1; // Car(const Car& car)
	Car car3(car2); //Car(const Car& car)
	Car car4; // Car(int price = 0, int length = 0)
	// 是一个赋值操作（默认是浅复制），并不会调用拷贝构造函数
	car4 = car3; 
}
//
//int main()
//{
//	test10_3();
//	return 0;
//}