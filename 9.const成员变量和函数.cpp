#include "head.h"

//����ָ����ָ�볣��
void test9_1()
{
	int a = 10;
	int b = 20;
	//const ���ε����ұߵ�ֵ  *p�����Ը�
	const int* p1 = &a; //����ָ�루ָ������ָ�룬���������޸ģ�ָ������޸�ָ��
	//*p1 = 90; //err,
	p1 = &b;//ok
	int const* p2 = &a; //����ָ��
	//*p2 = 90; //err
	p2 = &b;

	//p3�����Ը�
	int* const p3 = &a; //ָ�볣��������ֵ�����޸�
	*p3 = 90;
	//p3 = &b;//err

}

class Car
{
public:
	const int m_price = 0; //1.1
	static const int m_price1 = 0; //��ʹstatic������const
	int color;
	static int s_length;
	Car()
		: m_price(0)
		//, m_price1(0) //1.2
	{}

	//static void run() const {} //err
	void run() const
	{
		//color = 0; //err 2.2
		s_length = 0;
		cout << " Car::run() " << endl;
	}
	
};
int Car::s_length = 0;

/*һ. cosnt��Ա����
* 1.1 �����ʼ���� �����ڲ���ʼ����������ʱ�����ֱ�ӳ�ʼ��
* 1.2 ��static��const��Ա�����������ڳ�ʼ���б����ʼ��
*/

void test9_2()
{
	Car car; //1.1 ����ʼ�����ﱨ��
}
/*��. const��Ա���Ǿ�̬��
* 2.1 const �ؼ���д�ڲ����б���棬������������ʵ�ֶ������const
* 2.2 �ڲ������޸ķǾ�̬��Ա����, ֻ�ܵ���const��Ա������static��Ա����
* 2.3 ��const��Ա�����ɵ���const��Ա����
* 2.4 const��Ա�����ͷ�const��Ա������������
* 2.5 ��cosnt����ָ�룩 ���ȵ��÷�const��Ա����
* 2.6 const����ָ�룩ֻ�ܵ���const��Ա������static��Ա����
*/
