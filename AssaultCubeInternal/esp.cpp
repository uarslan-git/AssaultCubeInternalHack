#include "esp.h"
#include "constant.h"
#include <stdio.h>
#include <iostream>
#include "geom.h"
const float FOV = 90;

void normalizeAngle(Vec3& angle) {
	if (angle.x > 360)
		angle.x -= 360;
	if (angle.x < 0)
		angle.x += 360;
	if (angle.y > 90)
		angle.y -= 90;
	if (angle.y < -90)
		angle.y += 90;
}

bool isInFov(Player* owner, Vec3 looking) {
	Vec3 angle = CalcAngle(owner->position, looking);
	//Vec3 playerAngle{ owner->viewAngles.y + 180, owner->viewAngles.x, 0 };

	//Vec3 angleDiff = playerAngle - angle;
	//normalizeAngle(angleDiff);
	//std::cout << fabs(angle.x) << std::endl;
	//return (fabs(angleDiff.x) <= FOV/2 && fabs(angleDiff.y) <= FOV/2);
	return true;
}

bool isValidTarget(Player* player) {
	if ((player->health > 100 || player->health <= 0 || !isInFov(localPlayerPtr, player->origin)))
		return false;
	return true;
}

Player* ESP::getNearestPlayer() {
	Player* nearestPlayer = nullptr;
	float nearestDistance = 9999999.0f;
	for (int i = 0; i < *numPlayers; i++) {
		Player* player = players->Players[i];
		if (player->health > 100 || player->health <= 0 || !isInFov(localPlayerPtr, player->origin) || player == nullptr)
			continue;
		float distance = localPlayerPtr->position.Distance(player->position);
		std::cout << "PLayer " << i << " distance: " << distance << std::endl;
		if (distance < nearestDistance) {
			nearestDistance = distance;
			nearestPlayer = player;
		}
	}
	return nearestPlayer;
}

Player* ESP::getNearestEntityAngle() {
	Vec3 playerAngle{ localPlayerPtr->viewAngles.y + 180, localPlayerPtr->viewAngles.x, 0 };
	normalizeAngle(playerAngle);
	Player* nearestPlayer = nullptr;
	float smallestAngle = 99999999.0f;

	for (int i = 1; i < *numPlayers + 1; i++) {
		Player* player = players->Players[i];
		if (!isValidTarget(player))
			continue;
		Vec3 targetAngle = CalcAngle(localPlayerPtr->position, player->position);
		Vec3 angleDiff = playerAngle - targetAngle;
		float angleMagnitue = angleDiff.Length();
		if (angleMagnitue < smallestAngle) {
			smallestAngle = angleMagnitue;
			nearestPlayer = player;
		}
	}
	return nearestPlayer;
}

void ESP::aimbot() {
	if (!GetAsyncKeyState(VK_SHIFT))
		return;
	Player* target = getNearestPlayer();
	if (!target)
		return;
	Vec3 angle = CalcAngle(localPlayerPtr->position, target->position);
	angle.x += 90;
	localPlayerPtr->viewAngles.x = angle.x;
	localPlayerPtr->viewAngles.y = angle.y;
}