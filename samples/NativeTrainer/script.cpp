/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#include "Main.h"

using namespace std;
int RDR2selectedPlayer;
bool tpgun = false;
void Update()
{
	Self();
	Menu::Checks::Controlls();

}
void test()
{
	if (tpgun)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (bPlayerExists && PED::IS_PED_SHOOTING)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &iCoord))
			{
				ENTITY::SET_ENTITY_COORDS(playerPed, iCoord.x, iCoord.y, iCoord.z + 1, 0, 0, 1, 1);
				WAIT(0);

			}
		}
	}
}
//run loop here
void main()
{
	while (true)
	{
		Update();//Loopy
		switch (Menu::Settings::currentMenu) 
		{

			case mainmenu:
			{
				Menu::Title("BooOOooOO");
				Menu::MenuOption("Self", sub);
				Menu::MenuOption("Player List", plist);
				Menu::Toggle("TPgun", tpgun);
				Menu::Break("Font Test");
			}
			break;
	#pragma region Self Menu
			case plist:
			{
				Menu::Title("Player List");
				for (int i = 0; i < 32; ++i) {
					if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), pmenu) ? RDR2selectedPlayer = i : NULL; // OG forloop
					}
				}
			}
			break;
			case pmenu:
			{
				Menu::Title(PLAYER::GET_PLAYER_NAME(RDR2selectedPlayer));

			}
			break;
			case sub:
			{
				Menu::Toggle("GodMode", godmode);
				if (Menu::Option("Clone ped")) clone(); 	
				if (Menu::Option("Save Entity")) savebrowndoggy();
			}
			break;

		}
		WAIT(0);

	}
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}