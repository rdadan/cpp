#include "head.h"

//关于字符串
void test11_1()
{
	const char* name1 = "bmw04"; //长度5，占6个字节
	char name2[] = { 'b', 'm', 'w', '0', '4', '\0' }; //长度4，占6个字节

	cout << strlen(name1) << endl; //5
	cout << sizeof(name1) << endl; //4

	cout << strlen(name2) << endl; //5
	cout << sizeof(name2) << endl; //6
}

/*
* 浅拷贝：指针类型的变量只会拷贝地址
* 深拷贝：将指针指向的内容拷贝到新的存储空间
*/

/*
* 编译器默认提供的拷贝是浅拷贝
* 将一个对象中所有成员变量的值拷贝到另一个对象
* 如果某个成员变量是指针， 只会拷贝指针中存储的地址值，而不会拷贝指针指向的内存空间
* 可能会导致堆空间多次free问题
* 堆空间指向栈空间很危险，因为栈空间随时可能被回收

* 如果需要实现深拷贝， 就需要自定义拷贝构造函数
* 将指针类型的成员变量所指向的内存空间，拷贝到新的内存空间
*/

class Car_11
{
public:

	//构造函数
	Car_11(int price, const char * name)
	: m_price(price)
	{
		if (name == NULL)
			return;
		//申请独立的堆空间, 并初始化
		int len = strlen(name) + 1;
		m_pname = new char[len]  {};

		//将内容拷贝到新的堆空间去
		strcpy_s(m_pname, len, name);
		cout << "构造 Car_11(int price, const char * name)" << endl;

	}

	//拷贝构造函数
	Car_11(const Car_11 & Car_11)
	{
		m_price = Car_11.m_price;

		//申请独立空间
		if (Car_11.m_pname == NULL)
			return;
		//申请独立的堆空间, 并初始化
		int len = strlen(Car_11.m_pname) + 1;
		m_pname = new char[len] {};

		//将内容拷贝到新的堆空间去
		strcpy_s(m_pname, len, Car_11.m_pname);

		cout << "拷贝构造 深拷贝 Car_11(const Car_11& Car_11)" << endl;
	}
	void display()
	{
		cout << "m_price: " << m_price << endl;
		cout << "m_pname: " << m_pname << endl;

	}
	//析构
	~Car_11()
	{
		if (m_pname)
		{ 
			delete[] m_pname;
			cout << "~Car_11()" << endl;
		}
	}
private:
	int m_price;
	char* m_pname;

};
void test11_2()
{
	string  str_name = "bmw04";
	//调用构造函数
	Car_11 Car_11(1, str_name.c_str());
	Car_11.display();
}

void test11_3()
{
	string  str_name = "bmw04";
	
	Car_11 Car1(1, str_name.c_str());

	/*如果没有拷贝构造，Car_11 Car_112 = Car_111 就调用默认的构造函数
	* 也就是直接将Car_111的所有成员变量赋值给Car_112，
	 *即浅拷贝，只拷贝内容，对于指针类型变量只拷贝地址
	* 这样Car_111 和 Car_112的 m_pname将指向同一个堆空间，很不安全
	* 用其中一个修改内存的值是，也会影响另外一个，或者出现多次 free 堆内存的情况
	* 所以，需要定义拷贝构造函数， 并且是深拷贝（产生新的存储空间）
	*/
	Car_11 Car2 = Car1;
	Car2.display();
}
//
//
//int main()
//{
//	test11_3();
//	return 0;
//}