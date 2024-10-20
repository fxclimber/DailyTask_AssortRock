#pragma once
#include <assert.h>

//typedef size_t DataType;
// (��) �ڵ��� �������̸� ����, typedef�� �ߴٰ�, ���ø����� �ٲ���

template<typename DataType>
class UVector
{
public:
	~UVector()
	{
		delete[] UData;
	}

	UVector(){}

	//���������
	UVector(const UVector& other)
		: USize(other.USize),UCapacity(other.UCapacity)
	{
		if (nullptr != other.UData)
		{
			UData = new DataType[other.UCapacity];

			for (int i = 0; i < USize; ++i)
			{
				UData[i] = other.UData[i];
			}

		}
	}

	//�ε����� ��ҿ� ����
	DataType& operator[](int _index)
	{
		//assert(_index < USize);
		return UData[_index];
	}
	//����
	DataType& operator=(const UVector& other)
	{
		//�� üũ
		delete[] UData;

		//���޸��Ҵ�
		UCapacity = other.UCapacity;
		USize = other.USize;
		UData = new DataType[UCapacity];

		//����
		for (int i = 0; i < USize; ++i)
		{
			UData[i] = other.UData;
		}

		//UData = _newUData;
		return *this;
	}

	void reserve(int _capacity)//�޸��Ҵ�
	{
		if (UCapacity >= _capacity)
		{
			return;
		}
		DataType* new_capacity = new DataType[_capacity];

		for (int i = 0; i < USize; ++i) {
			new_capacity[i] = UData[i];
		}

		delete[] UData; // ���� �޸� ����
		UData = new_capacity;
		UCapacity = _capacity;
	}

	void push_back(DataType _Data)
	{
		if (USize >= UCapacity)
		{
			reserve(UCapacity == 0 ? 1 : UCapacity * 2);
		}
		UData[USize++] = _Data;
	}

	void clear()
	{
		USize = 0;
	}

	int getCapacity() const
	{
		return UCapacity;
	}
	int getSize() const
	{
		return USize;
	}




private:
	DataType* UData = nullptr;
	int UCapacity = 0;
	int USize = 0;

};
