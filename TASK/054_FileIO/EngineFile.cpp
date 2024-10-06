#include "EngineFile.h"
#include "EngineDebug.h"
#include <io.h> // _access�� ����ϱ� ���� �ʿ�

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
        MSGASSERT("ũ�Ⱑ 0�� �����ʹ� �� �� ����");
        return;
    }
    if (nullptr == _Ptr)
    {
        MSGASSERT("�������� �ʴ� �޸𸮸� ����Ϸ� �Ѵ�");
        return;
    }
    if (nullptr == file)
    {
        MSGASSERT("���� ���� ���Ͽ� ������ ������ �ߴ�");
        return;
    }

    fwrite(_Ptr, _Size, 1, file);
}

void UEngineFile::Read(void* _Ptr, size_t _Size)
{
    if (0 == _Size)
    {
        MSGASSERT("ũ�� 0�� �����ʹ� ���� �� ����");
        return;
    }
    if (nullptr == _Ptr)
    {
        MSGASSERT("�������� �ʴ� �޸𸮸� ������ �Ѵ�");
        return;
    }
    if (nullptr == file)
    {
        MSGASSERT("���� ���� ���Ͽ� ������ �������� �ߴ�");
        return;
    }

    fread(_Ptr, _Size, 1, file);
}

void UEngineFile::FileOpen(const char* _Mode)
{
    fopen_s(&file, Path, _Mode);
    if (nullptr == file)
    {
        MSGASSERT(Path); // ������ ������ ������ ��� ���
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
