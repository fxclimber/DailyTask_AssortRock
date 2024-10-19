#pragma once
#include <assert.h>

//typedef size_t DataType;
// (팁) 코딩중 디버깅용이를 위해, typedef로 했다가, 템플릿으로 바꾸자

template<typename DataType>
class UVector
{
public:
	~UVector()
	{
		delete[] UData;
	}

	UVector(){}

	//복사생성자
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

	//인덱스로 요소에 접근
	DataType& operator[](int _index)
	{
		//assert(_index < USize);
		return UData[_index];
	}
	//대입
	DataType& operator=(const UVector& other)
	{
		//나 체크
		delete[] UData;

		//새메모리할당
		UCapacity = other.UCapacity;
		USize = other.USize;
		UData = new DataType[UCapacity];

		//복사
		for (int i = 0; i < USize; ++i)
		{
			UData[i] = other.UData;
		}

		//UData = _newUData;
		return *this;
	}

	void reserve(int _capacity)//메모리할당
	{
		if (UCapacity >= _capacity)
		{
			return;
		}
		DataType* new_capacity = new DataType[_capacity];

		for (int i = 0; i < USize; ++i) {
			new_capacity[i] = UData[i];
		}

		delete[] UData; // 기존 메모리 해제
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

