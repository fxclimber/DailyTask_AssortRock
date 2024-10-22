#include <iostream>

class CopyElision
{
private:
	int _data;
public:
	CopyElision(int data) :_data(data)
		{
			std::cout << "일반생성자" << std::endl;
		}

	CopyElision(const CopyElision& a) : _data(a._data)
	{
		std::cout << "복사생성자" << std::endl;
	}
};








int main()
{
	CopyElision a(1);
	CopyElision b(a);

	CopyElision c(CopyElision(2));//일반? 왜?
	/*
	컴파일러가 복사생성을 굳이 안하고, 임시객체 를 c로 만들어버린다.헐..->복사생략
	복사생략을 하는 경우는 ,함수내부에서 생성된 객체를 리턴할때,(복사생략을 할수도 있단다)
	*/



	int aa = 0;

	return 0;

}
