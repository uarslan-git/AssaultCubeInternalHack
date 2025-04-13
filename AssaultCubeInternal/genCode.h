#pragma once
class Vector3 {
public:
	float x;
	float y;
	float z;
};

class Player
{
public:
	char pad_0004[24]; //0x0004
	Vector3 N00000478; //0x001C
	Vector3 N00000479; //0x0028
	Vector3 Velocity; //0x0034
	char pad_0040[8]; //0x0040
	Vector3 Position; //0x0048
	Vector3 Angle; //0x0054
	char pad_0060[28]; //0x0060
	UINT32 IsShooting; //0x007C
	char pad_0080[12]; //0x0080
	UINT32 IsMoving; //0x008C
	char pad_0090[4052]; //0x0090

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x1064