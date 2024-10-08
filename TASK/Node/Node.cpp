#include <iostream>

//-------------- 자료구조 구분 방식 -------------------- 
//2가지 메모리구분 - 노드형(트리형), 배열형(메모리에 각자를 붙여서,"갯수*자료형크기"의 메모리할당)
//3가지 컨테이너 - list, vector, map

// [1][2][0] 을 받아서
// [1][2][0] 그대로 배치 -> vector
// [0][1][2] 정렬해서 배치 -> sorted list


//연관 map
//시퀀스 list vector
//어댑터

//-------- 노드형 -------------------------------------
// 게임에서 가장 많이 사용된 데이타형태


class Node
{
	Node* LinkedNode[10];
};

//-------- 게임의 맵이 노드구조의 대표 ---------------------
class Zone
{
private:
	//정적 배열,정적배열,코드실행후 바꿀수 없는
	// 정적 바인딩경우, 문제 : 만약1개만 만들었고, 나머지4개는 낭비가 되고,객체도 바꾸고 싶다면? -> 동적 생성
	Zone* LinkZone[5] = {};
public:
	void Link(Zone* _Link)
	{

	}

};

class FightZone : public Zone
{

};

class Town : public FightZone
{

};
//---------------------------------------------------
class Sword
{

};
class Shop
{
	Sword* sword;
};

class Player
{
	Player* player;
	Sword* sword;
};

int main()
{
	//게임 시작할때 맵 생성 , 앞으로 더 생성되는것이 아니라, 그곳으로 이동하는것이다!
	// 이 개념은 다른 컨텐츠에도 동일 - 무기를 산다고 할때, 상점에서 무기를 가져오는것이지, 내 클래스에서 무기를 만드는것이 아니다.
	// 다른 객체를 포인터 또는 참조로 만드는 이유!
	Town town;
	FightZone fightZone;



}
