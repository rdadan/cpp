#include "head.h"

/*����ģʽ��
* ���ģʽ��һ�֣���֤ĳ������Զֻ����һ������
* 1.����/��������˽�л�
* 2.��������˽�о�ָ̬�루private��ֻ֤�������ڲ����ʣ�static��֤ȫ��ֻ��һ�ݣ�
* 3.�ṩ�����ӿڣ����ڶ��徲̬���������������ָ�롣
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
		//����û���Ƕ��̰߳�ȫ��
		//���߳���ֻ�õ����һ��new�Ķ���ĵ�ַ������Ļ��˷�
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
			//deleteֻ�ǽ�ָ��ָ��Ķѿռ���գ�����ָ����Ȼ��ֵ��
			delete pSingle;
			pSingle = NULL;
		}
	}

	void Run()
	{
		cout << "Singleton::Run() " << endl;
	}
};
//��̬��Ա������ʼ��
Singleton* Singleton::pSingle = NULL;

void test8_1()
{	
	Singleton * p = Singleton::GetSingle();
	//Singleton::pSingle = p;//err, ˽�еľ�̬��Ա�����������ⲿ����
	p->Run();
	Singleton* p1 = Singleton::GetSingle();
	
	Singleton* p2 = p->GetSingle();

	cout << p << endl;// 00064B48 ������ַһ��
	cout << p1 << endl;// 00064B48
	cout << p2 << endl;// 00064B48
	
	Singleton::deletePsingle();
}

//���캯��˽�л�����Ϊ�˱�֤���������ⴴ������
//��������Ҳ˽�л�����Ϊ�˶���ط��õ�pSingleʱ����֤��ȫ
void test8_2()
{
	Singleton* p1 = Singleton::GetSingle();
	Singleton* p2 = p1->GetSingle();

	p1->Run();
	//��������˽�л�����ֹ�ⲿ��delete����
	//delete p1;//���ܻᵼ������� p2������
	p2->Run();

}
//int main()
//{
//	test7_2();
//	return 0;
//}