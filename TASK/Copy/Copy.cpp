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
		//ptr 생성
		if (nullptr == Ptr)
		{
			this->Ptr = new int();
		}
		//*ptr에 인자의 *ptr을 대입해라
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
	//복사 대입,자신 참조를 리턴하는게 관행이란다
	Copy& operator=(const Copy& _other)
	{
		//내가 아니면
		if (this != &_other)
		{
			//널체크
			if (nullptr != Ptr)
			{
				delete Ptr;
			}
			// 지웠으니 새로 만들어서, 다른 객체의 변수를 대입
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
