#pragma once
#include <Windows.h>
#include <iostream>
#include <io.h>

//파일 관련 기능
//FILE래핑
//삭제,이동

const int MAXPATH = 250;//경로문자열 길이

class UEngineFile
{
public:
	UEngineFile();
	~UEngineFile();

	//인라인함수는 선언+구현 동시에, 컴파일러가 함수복붙처리 하므로, 함수호출비용 절약
	inline void SetPath(const char* _Path)
	{
		strcpy_s(Path, _Path);
	}

	//쓰기,읽기,파일열기,존재여부,파일닫기
	
	// Write- const void*로 받은 포인터(_Ptr)의 데이터를 size_t 타입의 크기(_Size)만큼 출력
	void Write(const void* _Ptr, size_t _Size);
	void Read(void* _Ptr, size_t _Size);
	void FileOpen(const char* _Mode);
	bool IsExists();
	void FileClose();




private:
	char Path[MAXPATH] = "";//경로문자열 선언
	FILE* file = nullptr;//파일
};