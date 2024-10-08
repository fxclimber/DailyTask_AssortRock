#include <iostream>

//2024.10.08

//1. 부모클래스를 만든다
class UStatusUnit
{
public:
	//2. virtual 을 붙인 함수를 만든다
	virtual void StatusRender()
	{
		//구현은 하되,내용이 없어도 된다.
		std::cout << "나는 부모" << std::endl;
	}
};

class UPlayer : public UStatusUnit
{
public:
	//3. 자식에서 완전히 동일한 함수를 만든다.
	//virtual 제거, override 추가
	void StatusRender()override
	{
		//4. 자식함수의 로직
		std::cout << "나는 자식" << std::endl;
	}
private:
	bool size = true;
};

int main()
{
	// 5. main함수에서 가상함수 호출시
	// 5-1.자식객체
	UPlayer newPlayer;
	// 5-2. 자식을 가리키는 부모포인터(중요!)
	UStatusUnit* StatusUnitPtr = &newPlayer;
	// 5-3. 부모포인터로 자식함수 호출(중요-이것이 목적)
	StatusUnitPtr->StatusRender();
	std::cout <<"자식 클래스 크기는 : " << sizeof(UPlayer) << std::endl;
	std::cout <<"부모 클래스 크기는 : " << sizeof(UStatusUnit) << std::endl;
	/*
	1. 자식의 함수가 호출될때,플레이어는 온전히 부모포인터 상태이며,
	2. 이때 가상함수가 있으면 _vfptr(8바이트)를 만드는 코드가 삽입된다
	3. 부모의 생성자가 호출될때 가상함수의 함수포인터를 _vfptr에 세팅하고
	_vfptr[0] = &UStatusUnit::StatusRender ; 의 형식이 된다
	4. 자식의 생성자가 호출되고
		_vfptr[0] = &UPlayer::StatusRender ; 의 형식이 된다
	5. _vfptr실제 사용과 호출은
		void* _vfptr = reinterpret_cast<void*>(&__vfptr[0]);
	*/
}
