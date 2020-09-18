#include "head.h"

/*单例模式：
* 设计模式的一种，保证某个类永远只创建一个对象
* 1.构造/析构函数私有化
* 2.类内声明私有静态指针（private保证只能在类内部访问，static保证全程只有一份）
* 3.提供公共接口，类内定义静态函数，返回上面的指针。
*/

class Singleton
{
private:
	Singleton() {}
	~Singleton() {}
	static Singleton* pSingle;
public:
	static Singleton* GetSingle()
	{
		//这里没考虑多线程安全，
		//多线程下只拿到最后一个new的对象的地址，其余的会浪费
		if (pSingle == NULL)
		{
			pSingle = new Singleton();
		}
		return pSingle;
	}

	static void deletePsingle()
	{
		if (pSingle != NULL)
		{
			//delete只是将指针指向的堆空间回收，但是指针依然有值；
			delete pSingle;
			pSingle = NULL;
		}
	}

	void Run()
	{
		cout << "Singleton::Run() " << endl;
	}
};
//静态成员变量初始化
Singleton* Singleton::pSingle = NULL;

void test8_1()
{	
	Singleton * p = Singleton::GetSingle();
	//Singleton::pSingle = p;//err, 私有的静态成员变量不能在外部访问
	p->Run();
	Singleton* p1 = Singleton::GetSingle();
	
	Singleton* p2 = p->GetSingle();

	cout << p << endl;// 00064B48 三个地址一样
	cout << p1 << endl;// 00064B48
	cout << p2 << endl;// 00064B48
	
	Singleton::deletePsingle();
}

//构造函数私有化，是为了保证不能在类外创建对象
//析构函数也私有化，是为了多个地方用到pSingle时，保证安全
void test8_2()
{
	Singleton* p1 = Singleton::GetSingle();
	Singleton* p2 = p1->GetSingle();

	p1->Run();
	//析构函数私有化，禁止外部做delete操作
	//delete p1;//可能会导致下面的 p2出问题
	p2->Run();

}
//int main()
//{
//	test7_2();
//	return 0;
//}