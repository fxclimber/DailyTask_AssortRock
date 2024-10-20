#pragma once
#include "assert.h"

typedef int DataType;

//template<typename DataType>
class UList
{
public:
	//���: ���� ,���� ,����Ÿ
	class UListNode//inner class
	{
	public:
		UListNode* prev = nullptr;
		UListNode* next = nullptr;
		DataType Data;

		void Release()
		{
			//��������� ���� next������ ����
			if (nullptr != next)
			{
				next->Release();
			}
			delete this;
		}
	};

public:
	// ���ͷ�����
	class iterator
	{
		friend UList;//UList ���� �ڽ��� private,protected����
	public:
		iterator()
		{

		}

		bool operator!=(const iterator& _other)
		{
			return CurrentNodeIt != _other.CurrentNodeIt;
		}
		//* �� ���ϱ⵵ �ǰ�, �������� �������� �ȴ�
		DataType& operator*()
		{
			return CurrentNodeIt->Data;
		}

		iterator operator++(DataType)//��������
		{
			iterator temp = *this;//���� ���ͷ����� ����
			CurrentNodeIt = CurrentNodeIt->next;//�����带 �������� �̵�
			return temp;//�������ͷ����� ����
		}


		iterator& operator++()//��������
		{
			CurrentNodeIt = CurrentNodeIt->next;
			return *this;//������ ���ͷ����� ��ȯ
		}


	private:
		UListNode* CurrentNodeIt = nullptr;

		//������������, �ܺο� �˸��� �ȴ�
		iterator(UListNode* _node)
			:CurrentNodeIt(_node) {}
	};


public:
	//UList �� �Լ���!
	UList()
	{
		// ���� ����Ÿ�� ���� ����-���� �Ǵ� ����//�Ҽ��ִ�!
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

	void Clear()//��� ��� ��������,����Ʈ�� �ʱ���·�.
	{
		//���۳�� ���������� ���������� ..��� ��� ����
		UListNode* CurrentNode = BeginNode->next;
		while (EndNode != CurrentNode)
		{	//����� �����Ҷ����� "������"�� �������� �����ϸ鼭 �����ݺ� 
			UListNode* nextNode = CurrentNode->next;
			delete CurrentNode;
			CurrentNode = nextNode;
		}
		BeginNode->next = EndNode;
		EndNode->prev = BeginNode;
	}

	//�������, ��Ȯ�� �޸� �׸��鼭 Ȯ���ϱ�
	void push_front(const DataType& _data)
	{
		UListNode* listnode = new UListNode();
		listnode->Data = _data;

		listnode->prev = BeginNode;// ������� ������ ���۳��
		listnode->next = BeginNode->next; // ?

		BeginNode->next->prev = listnode; // ������� ������ ??
		BeginNode->next = listnode;// ���۳���� ������ �����
	}

	void push_back(const DataType& _data)//�Ҽ��ִ�
	{
		UListNode* listnode = new UListNode();
		listnode->Data = _data;

		listnode->next = EndNode;
		listnode->prev = EndNode->prev;

		EndNode->prev->next = listnode;
		EndNode->prev = listnode;
	}


	iterator erase(iterator& _data)//prev,next�� ���������� ������
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
		return iterator(EndNode);//	iterator(UListNode* _node)������

	}


private:
	//UListNode�� �����ͺ���
	UListNode* BeginNode = nullptr;
	UListNode* EndNode = nullptr;

};

