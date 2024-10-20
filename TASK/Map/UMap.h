#pragma once
#include <assert.h>
#include <iostream>

typedef int KeyType;
typedef int ValueType;

class UPair
{
public:
	KeyType first;
	ValueType second;
};

class less
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

//template <typename KeyType, typename ValueType>
class UMap
{
private:
	class UMapNode
	{
	public:
		UMapNode* Parent = nullptr;
		UMapNode* leftChild = nullptr;
		UMapNode* rightChild = nullptr;
		UPair Pair;

		void FirstOrder()
		{

		}
		void MidOrder()
		{

		}
		void LastOrder()
		{

		}
		void ChildRelease(UMapNode* _node)
		{

		}
		UMapNode* OverParent(const KeyType& _key)
		{

		}
		UMapNode* NextNode()
		{

		}
		UMapNode* MinNode()
		{
			if (nullptr == leftChild)
			{
				return this;
			}
			//꼬리재귀
			return leftChild->MinNode();
		}
		UMapNode* MaxNode()
		{

		}
		UMapNode* FindNode(const KeyType& _key)
		{
			if (this->Pair.first == _key)
			{
				return this;
			}

			if (Pair.first > _key)
			{
				return leftChild->FindNode(_key);
			}
			else
			{
				return rightChild->FindNode(_key);
			}
			return nullptr;
		}

		void insertNode(const UPair& _pair)
		{
			if (Pair.first == _pair.first)
			{
				return;//키값이 같으면 추가하지않음
			}
			less newLess;
			if (newLess(Pair.first, _pair.first))//내림차순
			{
				if (nullptr == leftChild)
				{
					leftChild = new UMapNode();
					leftChild->Parent = this;//왼자식포인터가 나를 가리키게
					leftChild->Pair = _pair;
					return;//리턴 꼭.여기서 완벽한 종료라면.
				}
				leftChild->insertNode(_pair);
			}
			else
			{
				if (nullptr == rightChild)
				{
					rightChild = new UMapNode();
					rightChild->Parent = this;
					rightChild->Pair = _pair;
					return;
				}
				rightChild->insertNode(_pair);
			}
		}

	};


public:
	class iterator
	{
		friend UMap;
	public:
		iterator& operator++()
		{

		}

		bool operator!=(const iterator& _other)
		{
			return CurrentNode != _other.CurrentNode;
		}

		UPair* operator->()
		{
			return &CurrentNode->Pair;
		}

		iterator(UMapNode* _node)
			:CurrentNode(_node)
		{

		}

	private:
		UMapNode* CurrentNode = nullptr;
	};

public:
	iterator beginMap()
	{
		if (nullptr == Root)
		{
			return iterator(nullptr);
		}
		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator findMap(const KeyType& _key)
	{
		if (nullptr == Root)
		{
			return iterator(nullptr);//트리가 비면 빈 이터 리턴
		}
		UMapNode* node = Root->FindNode(_key);
		return iterator(node);//키에 해당하는 노드의 이터 리턴
	}


	iterator erase(iterator& _iter)
	{
		// 미리 다음 노드를 계산
		iterator Return = _iter.CurrentNode->NextNode();
		UMapNode* CurNode = _iter.CurrentNode;
		UMapNode* ParentNode = CurNode->Parent;

		// 자식이 없을 때 (리프 노드)
		if (CurNode->leftChild == nullptr && CurNode->rightChild == nullptr)
		{
			if (ParentNode == nullptr)  // 루트 노드 삭제
			{
				Root = nullptr;
			}
			else
			{
				ParentNode->ChildRelease(CurNode); // 부모의 자식 관계 해제
			}

			delete CurNode;
			return Return;
		}

		// 자식이 하나 이상 있을 때
		UMapNode* ChangeNode = nullptr;

		// 대체할 노드 선택
		if (CurNode->leftChild != nullptr)
		{
			ChangeNode = CurNode->leftChild->MaxNode();  // 왼쪽 서브트리에서 최대값
		}
		else
		{
			ChangeNode = CurNode->rightChild->MinNode(); // 오른쪽 서브트리에서 최소값
		}

		if (ChangeNode->Parent != nullptr)
		{
			ChangeNode->Parent->ChildRelease(ChangeNode); // 대체 노드 부모와 자식 관계 해제
		}

		// CurNode 자식들의 부모 관계 끊기
		if (CurNode->leftChild != nullptr)
		{
			CurNode->leftChild->Parent = nullptr;
		}
		if (CurNode->rightChild != nullptr)
		{
			CurNode->rightChild->Parent = nullptr;
		}

		// 대체 노드에 자식 연결
		if (CurNode->leftChild != nullptr && CurNode->leftChild != ChangeNode)
		{
			ChangeNode->leftChild = CurNode->leftChild;
			CurNode->leftChild->Parent = ChangeNode;
		}
		if (CurNode->rightChild != nullptr && CurNode->rightChild != ChangeNode)
		{
			ChangeNode->rightChild = CurNode->rightChild;
			CurNode->rightChild->Parent = ChangeNode;
		}

		// 부모와의 연결 갱신
		if (CurNode->Parent != nullptr)
		{
			if (CurNode->Parent->rightChild == CurNode)
			{
				CurNode->Parent->rightChild = ChangeNode;
			}
			else
			{
				CurNode->Parent->leftChild = ChangeNode;
			}
		}
		else // 루트 노드였으면 새로운 루트로 변경
		{
			Root = ChangeNode;
		}

		ChangeNode->Parent = CurNode->Parent;

		delete CurNode;
		return Return;
	}

	void FirstOrder()
	{

	}
	void MidOrder()
	{

	}
	void LastOrder()
	{

	}

	void insertUMap(const UPair& _pair)
	{
		if (nullptr == Root)
		{
			Root = new UMapNode();
			Root->Pair = _pair;
			return;
		}//루트가 없으면만들고, 키-밸류를 넣는다(새값)

		if (true == isRotate())
		{
			//편향트리
			Rotate();
		}
		//루트에 인서트노드
		Root->insertNode(_pair);
	}


public:
	UMapNode* Root = nullptr;

	bool isRotate()
	{

	}
	void Rotate()
	{

	}
	void LeftRotate()
	{

	}
	void RightRotate()
	{

	}

};

