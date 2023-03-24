#ifndef PLAYERSHEET_H
#define PLAYERSHEET_H
#pragma once
#include "Player.h"
#include "Item.h"
#include <iostream>

inline void PrintPlayerInfo(const Player& player) {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Player Name: " << player.Player_Name << std::endl;
	std::cout << "Class name: " << player.Player_Class->GetClassName() << std::endl;
	std::cout << "Max def:" << player.stats.MaxDef << std::endl;
	std::cout << "Max hp:" << player.stats.MaxHp << std::endl;
	std::cout << "Max resource:" << player.stats.MaxResource << std::endl;
	std::cout << "Mental Health: " << player.stats.MentalHealth << std::endl;
	std::cout << "Power Damage:" << player.stats.PowerDamage << std::endl;
	std::cout << "Player Level: " << player.Player_Level << std::endl;
	std::cout << "Player Experience: " << player.Player_Experience << "/" << player.ExpNeededForTheNextLevel << std::endl;
	std::cout << "Player HP: " << player.CurrentHP << "/" << player.stats.MaxHp << std::endl;
	std::cout << "Player current resource: " << player.CurrentResource << "/" << player.stats.MaxResource << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

inline void PrintItemInfo(const Item& item) {
	std::cout << "Damage bonus: " << item.I_stat.PowerDamage << std::endl;
	std::cout << "Mental health bonus: " << item.I_stat.MentalHealth << std::endl;
	std::cout << "Crit Chance bonus: " << item.I_stat.CritChance << std::endl;
	std::cout << "Class Resource bonus: " << item.I_stat.MaxResource << std::endl;
	std::cout << "Health bonus: " << item.I_stat.MaxHp << std::endl;
	std::cout << "Defense bonus: " << item.I_stat.MaxDef << std::endl;

}

#endif // !PLAYERSHEET_H
