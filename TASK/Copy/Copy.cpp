#include <iostream>
#include <vector>

class Copy
{
public:
	int* Ptr;
	Copy()
	{
		Ptr = new int();
	}
	Copy(const Copy& _other)
	{
		//ptr ����
		if (nullptr == Ptr)
		{
			this->Ptr = new int();
		}
		//*ptr�� ������ *ptr�� �����ض�
		*this->Ptr = *_other.Ptr;


	}
	~Copy()
	{
		if (nullptr != Ptr)
		{
			delete Ptr;
			Ptr = nullptr;
		}
	}
	//���� ����,�ڽ� ������ �����ϴ°� �����̶���
	Copy& operator=(const Copy& _other)
	{
		//���� �ƴϸ�
		if (this != &_other)
		{
			//��üũ
			if (nullptr != Ptr)
			{
				delete Ptr;
			}
			// �������� ���� ����, �ٸ� ��ü�� ������ ����
			Ptr = new int();
			*Ptr = *_other.Ptr;
		}
		return *this;
	}

};

class CopyTest
{
public:
	Copy value;
};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int a0 = 10;
	int a2 = 12;

	CopyTest CT;
	Copy C0= Copy();
	*C0.Ptr = a0;
	
	Copy C2= Copy();
	Copy C3 = C0;
	*C2.Ptr = a2;

	C2 = C0;

	CT.value = C0;


	int a = 0;


	return 0;
}
