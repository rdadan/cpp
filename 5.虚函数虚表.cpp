#include "head.h"

/*
 * c++�Ķ�̬ͨ���麯�� virtual function ��ʵ��
 * �麯���� ��virtual���εĳ�Ա����
 * ֻҪ�ڸ����б�����λ�麯������������д�ĺ���Ҳ�Զ�����麯��
 * �������п���ʡ��virtual�ؼ���
 */

/*
 * �麯����ʵ��ԭ�����������������洢��������Ҫ���õ��麯����ַ
 * �������Ҳ���麯����
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


//1.�����������麯�������ڴ��С����4�������洢����ĵ�ַ
void test1()
{
	//���麯����СΪ8
	Animal anim;
	cout << sizeof(anim) << endl;

	//�̳и��࣬���麯����СΪ12
	Cat cat;
	cout << sizeof(cat) << endl;
}

//2.���е�cat���󣨲�����ȫ������ջ�����ѣ�����һ�����

//3.����ָ���븸��ָ��
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

	//����ָ��ָ�������
	Cat* p2 = (Cat*) new Animal();
	p2->testAnimal();       //Animal::testAnimal()
	p2->testCat();          //Cat::testCat()
	
	p2->m_animal = 10;
	//p2->m_cat = 20;		//����ȫ������Ķѿռ�û��m_cat�ڴ�

	p2->speak();			//virtual Animal::Speak()

	delete p2;
	cout << "---" << endl;
	//����ָ��ָ���������
	Animal* p3 =  new Cat();
	p3->testAnimal();
	//p3->testCat();		//err,��Animal�����Ҳ�����Ա

	p3->m_animal = 10;
	//p3->m_cat = 20;		//err,��Animal�����Ҳ�����Ա

	p3->speak();			//Cat::Speak()

	delete p3;
}

/*4.�麯����ʵ��ԭ�������
*  ����������洢��������Ҫ���õ��麯����ַ�����Ҳ���麯����
*/
void test4()
{
	/*���е�Cat���󣨲�����ȫ������ջ���ѣ�����ͬһ�����*/
	Animal* pCat = new Cat();
	pCat->m_animal = 20;
	
	/*
	* ��������
	* 1. �õ�pcatָ���������洢�ĵ�ֵַ����cat����ĵ�ֵַ
	* 2. ȡ��cat�����ǰ��4���ֽڣ� �����ĵ�ַ
	*   ������ĵ�ַ������Cat���Ա����m_animal, m_cat�ĵ�ַ��ֵ�ֱ�Ϊ20��0��
	* 3. ȡ������е�ǰ��4���ֽڣ���Cat::speak()�����ĵ�ַ
	* 4. ȡ���������֮���4�ֽڣ���Cat::run()�����ĵ�ַ
	*/
	pCat->speak();	/* Cat::Speak() */
	pCat->run();	/* Cat::Run() */

	/* ������������ֻ��д�˸����һ���麯��
	*  ����ֻ��д��run(), 
	*  speak()�ĵ�����Ȼ��Ҫͨ���������ȡspeak������ַ
	*  pCat->speak();	// virtual Animal::Speak() 
	*  pCat->run(); 	// Cat::Run() 
	*/

	delete pCat;
}

/*5. ������ø����Ա����
* ������������麯������д���ຯ�������ǻ��뱣�����ຯ���Ĺ���
* ����ͨ����д���ຯ����ͬʱ��ֱ���ں���������ø���ĺ���
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


//6.���麯���� �����ࣨ���д��麯�����ࣩ
/*
* ���麯����û�к������ҳ�ʼ��Ϊ0���麯������������ӿڹ淶
* �����ࣨAbstract Class��
* ������ʵ�����������Դ�������
* ������Ҳ���԰����Ǵ��麯������Ա����
* ��������ǳ����࣬����û����ȫ��д���麯������ô���������Ȼ�ǳ�����
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
	//1.�����಻��ʵ����
	//Abstract a; //err
	//Abstract* p = new Abstract(); //err
	//2.
	//A_B ab; //err�� ����ֻ��ȫ����д����Ĵ��麯�����Լ��Ų��ǳ�����
}

/*7.����������
* ������ڸ���ָ��ָ���������������
* Ӧ�ý������������������Ϊ�麯����������������
* delete����ָ��ʱ���Ż���������������������֤������������
*/
class Person
{
public:
	virtual void run()
	{
		cout << "Person::run()" << endl;
	}
	//��������������֤�����������ԣ�
	//��������ʱ��ֻ�ῴָ������ͣ�����ȥ����ֵ�Ķ���
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
//	test7(); //������ȫ��Student::~Student(), Person::~Person()
//
//	return 0;
//}
