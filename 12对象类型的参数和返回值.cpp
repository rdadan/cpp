#include "head.h"

namespace space_12
{

/* ���ʹ�ö������� ��Ϊ�����Ĳ����򷵻�ֵ��
* ���ܻ����һЩ����Ҫ���м����
*/


class Car
{
public:
	Car()
	{
		cout << "Car::Car()  " << this  <<endl;
	}

	//��ֹ����ʽ����
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

/*������Ϊ��������
* ʵ�ζ�����βζ���ֵʱ������ÿ������캯��
* ���Կ��Ըĳ����û���ָ��������Ŀ���
*/
void test_1(Car  car) 
{
	
}



/*������Ϊ��������ֵ
* һ�㲻Ҫ������
*/
Car test_2()
{
	Car car; //���� Car::Car()
	//���� Car::Car(const Car & car), 
	//��test2()ջ�ռ��е�car���� ������ main�����е�ջ�ռ䡢
	//�ڵ���test2()��ʱ����Լ������󷵻�ֵ�Ŀռ�Ԥ������
	return car; 

}


void test_3()
{

	Car car1(1); // Car::Car()
	Car car2(2);
	car1 = car2; //�����ù��캯��
	cout << "---------------" << endl;

	//������Ϊ���������ÿ�������
	test_1(car1); //Car::Car(const Car & car)���������Ըĳ����û���ָ��

	cout << "---------------" << endl;
	//������Ϊ����ֵ
	car1 = test_2(); //Car::Car()  0096F984
					 //Car::Car(const Car & car)  0096F9C0

	cout << "---------------" << endl;

	Car car3 = test_2(); //Car::Car()  008FFA28�� 
						 //Car::Car(const Car & car)  008FFB28
}

/*��������
* û�б�������û�б�ָ��ָ��Ķ�����������ϵ�������
* �������������Ϊ����ֵ���ߺ��������Ļ��� ����ͨ����һ��������������һ���Ż�
*/
void test_4()
{
	Car(10); //�������� Car::Car(int price)  0116FC74
	Car(20).display();

	cout << "�����������������ֵ" << endl;
	Car car1 = Car(30); //Car::Car(int price)  010FF80C


	cout << "����������Ϊ������ " << endl;;
	test_1(Car(40)); //Car::Car(int price)  010FF6F0  û�е���������

	cout << "����������Ϊ����ֵcase1: " << endl;
	Car car2 = test_2(); //Car::Car()  010FF6D0
					     //Car::Car(const Car & car)  010FF800

	cout << "����������Ϊ����ֵcase2: " << endl;
	car1 = test_2();  //Car::Car()  010FF6D0
					  //Car::Car(const Car & car)  010FF710

}

/*
*c++�д�����ʽ�Ĺ���������ĳЩ����£�
*����ʽ�ĵ��õ��εĹ��캯��
*����ͨ���ؼ���explicit ��ֹ����ʽ����
*/
void test_5()
{
	Car car1 = 10; //Car(int price)

	Car car2(20);//Car(int price)
	car2 = 30;	//Car(int price)

	test_1(10); //Car(int price)

	Car car3 = test_2(); //Car(int price)
}

/*�������ṩ�Ĺ��캯��
*C++�ı�������ĳЩ�ض�������£�������Զ������޲εĹ��캯��������
* 1.��Ա������������ͬʱ�����˳�ʼ��
* 2.�ж����麯��
* 3.��̳���������
* 4.�����˶������͵ĳ�Ա���������Ա�й��캯�������������ɻ��Զ��壩
* 5.�����й��캯�������������ɻ��Զ��壩
* �ܽ�һ��
* ->���󴴽�����Ҫ��һЩ�������ʱ�������ڴ�������������ã���������һ�㶼��Ϊ���Զ������޲εĹ��캯�� 
*/

}//namespace



//using namespace space_12;
//int main()
//{
//	test_3();
//	return 0;
//}