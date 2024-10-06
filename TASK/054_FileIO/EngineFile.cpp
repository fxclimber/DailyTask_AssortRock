#include "EngineFile.h"
#include "EngineDebug.h"
#include <io.h> // _access를 사용하기 위해 필요

UEngineFile::UEngineFile() : file(nullptr)
{
}

UEngineFile::~UEngineFile()
{
    FileClose();
}

void UEngineFile::Write(const void* _Ptr, size_t _Size)
{
    if (0 == _Size)
    {
        MSGASSERT("크기가 0인 데이터는 쓸 수 없다");
        return;
    }
    if (nullptr == _Ptr)
    {
        MSGASSERT("존재하지 않는 메모리를 사용하려 한다");
        return;
    }
    if (nullptr == file)
    {
        MSGASSERT("열지 않은 파일에 내용을 쓰려고 했다");
        return;
    }

    fwrite(_Ptr, _Size, 1, file);
}

void UEngineFile::Read(void* _Ptr, size_t _Size)
{
    if (0 == _Size)
    {
        MSGASSERT("크기 0인 데이터는 읽을 수 없다");
        return;
    }
    if (nullptr == _Ptr)
    {
        MSGASSERT("존재하지 않는 메모리를 읽으려 한다");
        return;
    }
    if (nullptr == file)
    {
        MSGASSERT("열지 않은 파일에 내용을 읽으려고 했다");
        return;
    }

    fread(_Ptr, _Size, 1, file);
}

void UEngineFile::FileOpen(const char* _Mode)
{
    fopen_s(&file, Path, _Mode);
    if (nullptr == file)
    {
        MSGASSERT(Path); // 파일이 열리지 않으면 경고 출력
    }
}

bool UEngineFile::IsExists()
{
    return 0 == _access(Path, 0);
}

void UEngineFile::FileClose()
{
    if (nullptr != file)
    {
        fclose(file);
        file = nullptr;
    }
}
