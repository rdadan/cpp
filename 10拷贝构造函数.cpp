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

	//�������캯��
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

/*һ���������캯��
* �������Ѵ��ڵĶ��󴴽���һ������ʱ��
* �ͻ�����¶���Ŀ������캯�����г�ʼ��
* ��ʽ�̶�������һ��const���õĲ��� Car(const Car& car) {}
* �������ĳ�Ա��ȫ����Ҫ�����ģ� �ǾͲ���Ҫ�������忽�����캯����,
* ��Ϊ���󿽱��ǻ�Ĭ�Ͽ���ȫ���ĳ�Ա
*/

void test10_1()
{
	Car car1(99,10);
	Car car2(car1);
}


/*�������ø���Ŀ������캯��
* ���໥����󿽱�ʱ�������Ҫ���Ƹ���ĳ�Ա��
* ��Ҫ������Ŀ������캯���У����ø���Ŀ������캯��
* 
*/

class Person
{
public:
	//���캯��
	Person(int age, int height)
	: m_age(age)
	, m_height(height)
	{
		cout << "���캯����Person::Person(int age, int height)" << endl;
	}

	//����Ŀ������캯��
	Person(const Person& person)
		:m_age(person.m_age)
		,m_height(person.m_height)
	{
		cout << "�������캯����Person(const Person& person)" << endl;
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
	//���캯��
	Student(int age, int height, int score)
	: m_score(score)
	, Person(age, height)
	{
		//m_height = height;
		display();
	}

	//����Ŀ������캯��
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
	Student stu1(1, 2, 3); //���ø���Ĺ��캯��
	Student stu2 = stu1; //���ø���Ŀ������캯��
}

/*����ע������
*���캯��ֻ���ڶ��󴴽�ʱ��ʼ���ŵ���
*/
void test10_3()
{
	Car car1(1, 2); // Car(int price = 0, int length = 0)
	Car car2 = car1; // Car(const Car& car)
	Car car3(car2); //Car(const Car& car)
	Car car4; // Car(int price = 0, int length = 0)
	// ��һ����ֵ������Ĭ����ǳ���ƣ�����������ÿ������캯��
	car4 = car3; 
}
//
//int main()
//{
//	test10_3();
//	return 0;
//}