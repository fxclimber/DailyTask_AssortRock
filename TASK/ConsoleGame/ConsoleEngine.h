#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // �����δ�.
	// void Move(); // �����δ�.
public:
	static void Start();
	static UConsoleWindow Window;

private:
	ConsoleEngine();

	Player NewPlayer;

	// 2�� ������� �ʽ��ϴ�.
	void BeginPlay(); // �����δ�.

	void Tick(); // �����δ�.
	void Render(); // �׸���.
};

