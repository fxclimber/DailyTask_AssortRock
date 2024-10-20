#pragma once
#include "assert.h"

typedef int DataType;

//template<typename DataType>
class UList
{
public:
	//노드: 이전 ,이후 ,데이타
	class UListNode//inner class
	{
	public:
		UListNode* prev = nullptr;
		UListNode* next = nullptr;
		DataType Data;

		void Release()
		{
			//재귀적으로 다음 next노드들을 삭제
			if (nullptr != next)
			{
				next->Release();
			}
			delete this;
		}
	};

public:
	// 이터레이터
	class iterator
	{
		friend UList;//UList 에게 자신의 private,protected공유
	public:
		iterator()
		{

		}

		bool operator!=(const iterator& _other)
		{
			return CurrentNodeIt != _other.CurrentNodeIt;
		}
		//* 는 곱하기도 되고, 포인터의 역참조도 된다
		DataType& operator*()
		{
			return CurrentNodeIt->Data;
		}

		iterator operator++(DataType)//후위증감
		{
			iterator temp = *this;//현재 이터레이터 복사
			CurrentNodeIt = CurrentNodeIt->next;//현재노드를 다음으로 이동
			return temp;//원래이터레이터 리턴
		}


		iterator& operator++()//전위증감
		{
			CurrentNodeIt = CurrentNodeIt->next;
			return *this;//증가된 이터레이터 반환
		}


	private:
		UListNode* CurrentNodeIt = nullptr;

		//생성자이지만, 외부에 알리기 싫다
		iterator(UListNode* _node)
			:CurrentNodeIt(_node) {}
	};


public:
	//UList 의 함수들!
	UList()
	{
		// 실제 데이타가 없는 시작-끝이 되는 노드들//할수있다!
		BeginNode = new UListNode();
		EndNode = new UListNode();
		BeginNode->Data = -1;
		EndNode->Data = -1;

		BeginNode->next = EndNode;
		EndNode->prev = BeginNode;
	}

	~UList()
	{
		Clear();
	}

	void Clear()//모든 노드 안전삭제,리스트를 초기상태로.
	{
		//시작노드 다음노드부터 순차적으로 ..모든 노드 삭제
		UListNode* CurrentNode = BeginNode->next;
		while (EndNode != CurrentNode)
		{	//끝노드 도달할때까지 "현재노드"를 다음노드로 갱신하면서 삭제반복 
			UListNode* nextNode = CurrentNode->next;
			delete CurrentNode;
			CurrentNode = nextNode;
		}
		BeginNode->next = EndNode;
		EndNode->prev = BeginNode;
	}

	//여기부턴, 정확히 메모리 그리면서 확인하기
	void push_front(const DataType& _data)
	{
		UListNode* listnode = new UListNode();
		listnode->Data = _data;

		listnode->prev = BeginNode;// 새노드의 이전은 시작노드
		listnode->next = BeginNode->next; // ?

		BeginNode->next->prev = listnode; // 새노드의 다음의 ??
		BeginNode->next = listnode;// 시작노드의 다음은 새노드
	}

	void push_back(const DataType& _data)//할수있다
	{
		UListNode* listnode = new UListNode();
		listnode->Data = _data;

		listnode->next = EndNode;
		listnode->prev = EndNode->prev;

		EndNode->prev->next = listnode;
		EndNode->prev = listnode;
	}


	iterator erase(iterator& _data)//prev,next를 직접연결후 노드삭제
	{
		UListNode* curNode = _data.CurrentNodeIt;
		if (curNode == nullptr || curNode == BeginNode || curNode == EndNode)
		{
			assert(false);
			return iterator();
		}
		UListNode* returnNode = curNode->next;

		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;

		delete curNode;
		return iterator(returnNode);
	}

	iterator begin()
	{
		return iterator(BeginNode->next);
	}

	iterator end()
	{
		return iterator(EndNode);//	iterator(UListNode* _node)생성자

	}


private:
	//UListNode의 포인터변수
	UListNode* BeginNode = nullptr;
	UListNode* EndNode = nullptr;

};

