#pragma once
#include <cstdint>

class Vector3 {
public:
	float x;
	float y;
	float z;
};


class Player
{
public:
	void* vtable;
	char pad_0000[40]; //0x0000
	Vector3 position; //0x0028
	Vector3 viewAngles; //0x0034
	char pad_0040[172]; //0x0040
	int32_t health; //0x00EC
	char pad_00F0[40]; //0x00F0
	int32_t magReserve; //0x0118
	char pad_011C[32]; //0x011C
	int32_t magPrimary; //0x013C
	char pad_0140[156]; //0x0140
	int32_t frags; //0x01DC
	char pad_01E0[3688]; //0x01E0
}; //Size: 0x1048

class EntityList {
public:
	Player* players[64];
};