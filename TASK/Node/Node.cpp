#include <iostream>

//단일 연결 자료구조의 노드 클래스
template <typename type>
class SingleLinkedNode
{
public:
	type data;				//노드가 저장하는 데이타
	SingleLinkedNode* next;	//다음 노드를 가리키는 포인터
	//생성자
	SingleLinkedNode(type value): data(value), next(nullptr){}
	void test(){}
};



//이중 연결 자료구조의 노드클래스
template<typename type>
class DoubleLinkedNode
{
public:
	type data;				//노드가 저장한 데이타
	DoubleLinkedNode* next;	//다음 노드
	DoubleLinkedNode* prev;	//이전 노드
	// initializer list 사용이유
	DoubleLinkedNode(type value) : data(value), next(nullptr), prev(nullptr){}
	// 빈객체를 생성하면, 포인터변수들이 초기화되지않아 nullptr가 아닌,임의의 값을 가리켜 오류
	DoubleLinkedNode() : next(nullptr), prev(nullptr) {}
	//DoubleLinkedNode() {}//빈 생성자 이거 추가하면 중복정의되니까 잠깐 주석 
};


int main()
{
	//템플릿 클래스 객체 생성
	//1.기본
	SingleLinkedNode<int> statics =SingleLinkedNode<int>(1);
	SingleLinkedNode<int>(1);
	statics.data;
	statics.test();

	//2.동적 new~delete
	SingleLinkedNode<int>* news= new SingleLinkedNode<int>(10);
	news->test();
	news->data;
	
	//3.속빈 생성자
	DoubleLinkedNode<int> staticd = DoubleLinkedNode<int>();
	staticd.data;
	staticd.next;

	//단일 노드
	SingleLinkedNode<int> nodes1(1);
	SingleLinkedNode<int> nodes2(10);
	nodes1.next = &nodes2;
	

	//이중 노드
	DoubleLinkedNode<int> noded1(2);
	DoubleLinkedNode<int> noded2(20);
	noded1.next = &noded2;
	noded2.prev = &noded1;//서로 연결됨 



	return 0;

}