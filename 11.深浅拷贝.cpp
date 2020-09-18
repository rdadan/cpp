#include "head.h"

//�����ַ���
void test11_1()
{
	const char* name1 = "bmw04"; //����5��ռ6���ֽ�
	char name2[] = { 'b', 'm', 'w', '0', '4', '\0' }; //����4��ռ6���ֽ�

	cout << strlen(name1) << endl; //5
	cout << sizeof(name1) << endl; //4

	cout << strlen(name2) << endl; //5
	cout << sizeof(name2) << endl; //6
}

/*
* ǳ������ָ�����͵ı���ֻ�´����ַ
* �������ָ��ָ������ݿ������µĴ洢�ռ�
*/

/*
* ������Ĭ���ṩ�Ŀ�����ǳ����
* ��һ�����������г�Ա������ֵ��������һ������
* ���ĳ����Ա������ָ�룬 ֻ�´��ָ���д洢�ĵ�ֵַ�������´��ָ��ָ����ڴ�ռ�
* ���ܻᵼ�¶ѿռ���free����
* �ѿռ�ָ��ջ�ռ��Σ�գ���Ϊջ�ռ���ʱ���ܱ�����

* �����Ҫʵ������� ����Ҫ�Զ��忽�����캯��
* ��ָ�����͵ĳ�Ա������ָ����ڴ�ռ䣬�������µ��ڴ�ռ�
*/

class Car_11
{
public:

	//���캯��
	Car_11(int price, const char * name)
	: m_price(price)
	{
		if (name == NULL)
			return;
		//��������Ķѿռ�, ����ʼ��
		int len = strlen(name) + 1;
		m_pname = new char[len]  {};

		//�����ݿ������µĶѿռ�ȥ
		strcpy_s(m_pname, len, name);
		cout << "���� Car_11(int price, const char * name)" << endl;

	}

	//�������캯��
	Car_11(const Car_11 & Car_11)
	{
		m_price = Car_11.m_price;

		//��������ռ�
		if (Car_11.m_pname == NULL)
			return;
		//��������Ķѿռ�, ����ʼ��
		int len = strlen(Car_11.m_pname) + 1;
		m_pname = new char[len] {};

		//�����ݿ������µĶѿռ�ȥ
		strcpy_s(m_pname, len, Car_11.m_pname);

		cout << "�������� ��� Car_11(const Car_11& Car_11)" << endl;
	}
	void display()
	{
		cout << "m_price: " << m_price << endl;
		cout << "m_pname: " << m_pname << endl;

	}
	//����
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
	//���ù��캯��
	Car_11 Car_11(1, str_name.c_str());
	Car_11.display();
}

void test11_3()
{
	string  str_name = "bmw04";
	
	Car_11 Car1(1, str_name.c_str());

	/*���û�п������죬Car_11 Car_112 = Car_111 �͵���Ĭ�ϵĹ��캯��
	* Ҳ����ֱ�ӽ�Car_111�����г�Ա������ֵ��Car_112��
	 *��ǳ������ֻ�������ݣ�����ָ�����ͱ���ֻ������ַ
	* ����Car_111 �� Car_112�� m_pname��ָ��ͬһ���ѿռ䣬�ܲ���ȫ
	* ������һ���޸��ڴ��ֵ�ǣ�Ҳ��Ӱ������һ�������߳��ֶ�� free ���ڴ�����
	* ���ԣ���Ҫ���忽�����캯���� ����������������µĴ洢�ռ䣩
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