#pragma once

//모든 이넘은 여기에
class Enums
{

	//접근제한 지정자는 반드시 public, <- 디폴트
public:
	enum class MAXS
	{
		NAMEMAX = 256,
		ACTORNAMEMAX = 10,
		ZONELINKMAX = 5,
		LINECOUNT = 50
	};


	enum class MONSTERTYPE
	{
		//실수여지를 확인위해 NONE
		NONE = 0,
		GOBLIN = 1,
		ORC =2
	};
};


