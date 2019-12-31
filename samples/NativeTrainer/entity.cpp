#include "Main.h"

#include "MAIN.h"

// CONTROL
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		//NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1); shit idk
	}
}
void RequestControl(Entity input)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);

	int tick = 0;
	while (tick <= 50)
	{
		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(input))
			WAIT(0);
		else
			return;
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);
		tick++;
	}
}
//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
	{
		RequestControlOfEnt(e);
	}

	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);

}
void set_ObjectStraight(Entity entity)
{
	if (ENTITY::DOES_ENTITY_EXIST(entity))
	{
		RequestControlOfEnt(entity);
		float Yaw = ENTITY::GET_ENTITY_HEADING(entity);
		float Pitch = 0;
		float Roll = 0;
		RequestControlOfEnt(entity);
		ENTITY::SET_ENTITY_HEADING(entity, Yaw + 0.1f);
	}
}

void set_entity_invincible(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_INVINCIBLE(entity, toggle);
}
void set_entity_invincible(Entity entity)
{
	ENTITY::SET_ENTITY_INVINCIBLE(entity, true);
}
void set_entity_pos_dead(Entity entity, bool toggle)
{
	ENTITY::FREEZE_ENTITY_POSITION(entity, toggle);
}
void set_entity_dynamic(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_DYNAMIC(entity, toggle);
}
void set_entity_health(Entity entity, int health)
{
	health = ENTITY::GET_ENTITY_HEALTH(entity);
	ENTITY::SET_ENTITY_HEALTH(entity, health, NULL);
}
void set_entity_alpha(Entity entity, int Alpha)
{
	ENTITY::SET_ENTITY_ALPHA(entity, Alpha, false);
}
void set_entity_collision(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_COLLISION(entity, toggle, toggle);
}
void set_entity_lod(Entity entity, int LOD)
{
	RequestControlOfEnt(entity);
	LOD = ENTITY::GET_ENTITY_LOD_DIST(entity);
	ENTITY::SET_ENTITY_LOD_DIST(entity, LOD);

}
void set_entity_as_mission(Entity entity, bool toggle)
{
	RequestControlOfEnt(entity);
	if (toggle)
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, NULL, NULL);
	else
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&entity);

}
void set_entity_as_visible(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(entity, toggle);
}
void set_entity_as_velocity(Entity entity, Vector3 velocity)
{
	RequestControlOfEnt(entity);
	velocity = ENTITY::GET_ENTITY_VELOCITY(entity, NULL);
	ENTITY::SET_ENTITY_VELOCITY(entity, velocity.x, velocity.y, velocity.z);
}
void set_entity_gravity(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_HAS_GRAVITY(entity, toggle);
}
bool does_it_exist(Entity entity)
{
	if (ENTITY::DOES_ENTITY_EXIST(entity))
		return true;
}
bool alive = false;
Vector3 Get_Position(Entity entity)
{
	if (ENTITY::IS_ENTITY_A_PED(entity)) alive = true; else alive = false;
	return ENTITY::GET_ENTITY_COORDS(entity, alive, NULL);
}
Vector3 GetOffsetInWorldCoords(Entity entity, Vector3 offset)
{
	return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, offset.x, offset.y, offset.z);
}
Vector3 GetOffsetInWorldCoords(Entity entity, float X, float Y, float Z)
{
	return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z);
}
bool isplayerinwater()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (ENTITY::IS_ENTITY_IN_WATER(playerPed))
		return true;
	else
		return false;

}
bool isentityinwater(Entity entity)
{
	if (ENTITY::IS_ENTITY_IN_WATER(entity))
		return true;
	else
		return false;

}
Vector3 playerPosition()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	return ENTITY::GET_ENTITY_COORDS(playerPed, true, NULL);
}
Hash key(char* key)
{
	return GAMEPLAY::GET_HASH_KEY(key);
}
