#pragma once
#include <cstdint>
#include "geom.h"

class Player
{
public:
	char pad_0000[4]; //0x0000
	Vec3 origin; //0x0004
	char pad_0010[24]; //0x0010
	Vec3 position; //0x0028
	Vec3 viewAngles; //0x0034
	char pad_0040[172]; //0x0040
	int32_t health; //0x00EC
	char pad_00F0[44]; //0x00F0
	int32_t magReserve; //0x011C
	char pad_0120[32]; //0x0120
	int32_t magPrimary; //0x0140
	char pad_0144[200]; //0x0144
	int32_t frags; //0x020C
	char pad_0210[3688]; //0x0210
}; //Size: 0x1078

class EntityList
{
public:
	class Player* Players[32]; //0x0000
	char pad_0080[4184]; //0x0080
}; //Size: 0x10D8