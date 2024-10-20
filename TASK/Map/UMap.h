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
			//�������
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
				return;//Ű���� ������ �߰���������
			}
			less newLess;
			if (newLess(Pair.first, _pair.first))//��������
			{
				if (nullptr == leftChild)
				{
					leftChild = new UMapNode();
					leftChild->Parent = this;//���ڽ������Ͱ� ���� ����Ű��
					leftChild->Pair = _pair;
					return;//���� ��.���⼭ �Ϻ��� ������.
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
			return iterator(nullptr);//Ʈ���� ��� �� ���� ����
		}
		UMapNode* node = Root->FindNode(_key);
		return iterator(node);//Ű�� �ش��ϴ� ����� ���� ����
	}


	iterator erase(iterator& _iter)
	{
		// �̸� ���� ��带 ���
		iterator Return = _iter.CurrentNode->NextNode();
		UMapNode* CurNode = _iter.CurrentNode;
		UMapNode* ParentNode = CurNode->Parent;

		// �ڽ��� ���� �� (���� ���)
		if (CurNode->leftChild == nullptr && CurNode->rightChild == nullptr)
		{
			if (ParentNode == nullptr)  // ��Ʈ ��� ����
			{
				Root = nullptr;
			}
			else
			{
				ParentNode->ChildRelease(CurNode); // �θ��� �ڽ� ���� ����
			}

			delete CurNode;
			return Return;
		}

		// �ڽ��� �ϳ� �̻� ���� ��
		UMapNode* ChangeNode = nullptr;

		// ��ü�� ��� ����
		if (CurNode->leftChild != nullptr)
		{
			ChangeNode = CurNode->leftChild->MaxNode();  // ���� ����Ʈ������ �ִ밪
		}
		else
		{
			ChangeNode = CurNode->rightChild->MinNode(); // ������ ����Ʈ������ �ּҰ�
		}

		if (ChangeNode->Parent != nullptr)
		{
			ChangeNode->Parent->ChildRelease(ChangeNode); // ��ü ��� �θ�� �ڽ� ���� ����
		}

		// CurNode �ڽĵ��� �θ� ���� ����
		if (CurNode->leftChild != nullptr)
		{
			CurNode->leftChild->Parent = nullptr;
		}
		if (CurNode->rightChild != nullptr)
		{
			CurNode->rightChild->Parent = nullptr;
		}

		// ��ü ��忡 �ڽ� ����
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

		// �θ���� ���� ����
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
		else // ��Ʈ ��忴���� ���ο� ��Ʈ�� ����
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
		}//��Ʈ�� �����鸸���, Ű-����� �ִ´�(����)

		if (true == isRotate())
		{
			//����Ʈ��
			Rotate();
		}
		//��Ʈ�� �μ�Ʈ���
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

