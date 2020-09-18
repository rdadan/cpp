#include "head.h"

//���أ�������һ����������һ��
//��д������override��������̳и���ĺ�����ʵ���Լ��Ĺ���
//					   ������������ֵ���������͸���һģһ��


/* ��̬��
 * ͬһ���������ڲ�ͬ�Ķ��󣬿����в�ͬ�Ľ��ͣ�������ͬ��Ч��
 * ������ʱ������ʶ�������Ķ������ͣ����ö�Ӧ�����еĺ���
 * ����c++Ĭ������²����ڶ�̬,ֻ�����ָ������͵��ö�Ӧ�ĺ���

 * ��̬������Ҫ�أ�
 * ������д����ĺ��� override
 * �����ָ��ָ������Ķ���
 * ���ø���ָ�������д�ĺ���
*/

/* �麯�� virtual����ʵ�ֶ�̬
 * ֻҪ�ڸ���������Ϊ�麯������������д�ĺ���Ҳ�Զ�����麯��
*/


class Animal
{
public:
	
	virtual void run() //virtual ʵ�ֶ�̬
	{
		cout << "virtual Animal::run()" << endl;
	}
	void speak() //����ʵ�ֶ�̬��ָ�����͸����Լ������͸��Ե��ú���
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
	Cat* p = (Cat*) new Dog(); //�Ὣ��Ա��ʼ��Ϊ0
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
	//int* arr = new int [arr_size]();//5��ȫ��ʼ��Ϊ0
	int* arr = new int[arr_size] {6,5,4};//ǰ�����ֱ��ʼ��Ϊ6��5��4�� ����Ϊ0

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