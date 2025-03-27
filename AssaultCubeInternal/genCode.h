#pragma once
// Created with ReClass.NET 1.2 by KN4CK3R
class Vector3 {
public:
	float x;
	float y;
	float z;
};

class Player
{
public:
	Vector3 N000007BF; //0x0004
	Vector3 velocity; //0x0010
	Vector3 N000007C1; //0x001C
	Vector3 pos; //0x0028
	char pad_0034[8]; //0x0034
	Vector3 angles; //0x003C
	char pad_0048[20]; //0x0048
	Vector3 N000007CB; //0x005C
	char pad_0068[8]; //0x0068


}; //Size: 0x0070