#pragma once
#include <Windows.h>
#include <iostream>
#include <io.h>

//���� ���� ���
//FILE����
//����,�̵�

const int MAXPATH = 250;//��ι��ڿ� ����

class UEngineFile
{
public:
	UEngineFile();
	~UEngineFile();

	//�ζ����Լ��� ����+���� ���ÿ�, �����Ϸ��� �Լ�����ó�� �ϹǷ�, �Լ�ȣ���� ����
	inline void SetPath(const char* _Path)
	{
		strcpy_s(Path, _Path);
	}

	//����,�б�,���Ͽ���,���翩��,���ϴݱ�
	
	// Write- const void*�� ���� ������(_Ptr)�� �����͸� size_t Ÿ���� ũ��(_Size)��ŭ ���
	void Write(const void* _Ptr, size_t _Size);
	void Read(void* _Ptr, size_t _Size);
	void FileOpen(const char* _Mode);
	bool IsExists();
	void FileClose();




private:
	char Path[MAXPATH] = "";//��ι��ڿ� ����
	FILE* file = nullptr;//����
};