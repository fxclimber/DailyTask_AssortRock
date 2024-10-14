#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // �����δ�.
	// void Move(); // �����δ�.
public:
	static void Start();

	static FIntPoint GetWindowsize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}
	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	Player& GetPlayer()
	{
		return MainPlayer;
	}

private:
	//�����ڸ� ��������, �ڽ��� ����°Ϳܿ� �ܺο��� ��������->�̱��� 
	ConsoleEngine();

	static FIntPoint WindowSize;
	static UConsoleWindow Window;
	//�ڽ��� ����ƽ������,����ƽ�����Լ���, �ܺ������� ����Ѵ�.
	static ConsoleEngine* MainEngine;




	Player MainPlayer;




	// 2�� ������� �ʽ��ϴ�.
	void BeginPlay(); // �����δ�.

	void Tick(); // �����δ�.
	void Render(); // �׸���.
};

