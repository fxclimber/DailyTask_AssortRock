#include <iostream>

class CopyElision
{
private:
	int _data;
public:
	CopyElision(int data) :_data(data)
		{
			std::cout << "�Ϲݻ�����" << std::endl;
		}

	CopyElision(const CopyElision& a) : _data(a._data)
	{
		std::cout << "���������" << std::endl;
	}
};








int main()
{
	CopyElision a(1);
	CopyElision b(a);

	CopyElision c(CopyElision(2));//�Ϲ�? ��?
	/*
	�����Ϸ��� ��������� ���� ���ϰ�, �ӽð�ü �� c�� ����������.��..->�������
	��������� �ϴ� ���� ,�Լ����ο��� ������ ��ü�� �����Ҷ�,(��������� �Ҽ��� �ִܴ�)
	*/



	int aa = 0;

	return 0;

}
