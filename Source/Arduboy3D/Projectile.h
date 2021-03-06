#pragma once

#include <stdint.h>
#include "Entity.h"

class Projectile : public Entity
{
public:
	uint8_t angle;
	uint8_t life;
	uint8_t ownerId;

	static constexpr uint8_t player1OwnerId = 0xff;
	static constexpr uint8_t player2OwnerId = 0xfe;
	static uint8_t GetLocalPlayerOwnerId();

	Entity* GetOwner() const;
};

class ProjectileManager
{
public:
	static constexpr int MAX_PROJECTILES = 4;
	static Projectile projectiles[MAX_PROJECTILES];

	static Projectile* FireProjectile(Entity* owner, int16_t x, int16_t y, uint8_t angle);
	static void Init();
	static void Draw();
	static void Update();
};
