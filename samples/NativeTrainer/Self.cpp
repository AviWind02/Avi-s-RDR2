#include "Main.h"

bool godmode = false;

void Self() {
	if(godmode)
	ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), godmode);


	
}
void clone()
{
	PED::CLONE_PED(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 0, 1);
}
void savebrowndoggy()
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	set_entity_as_mission(veh, TRUE);// makes the game things its needed
}