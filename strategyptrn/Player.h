#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include<iostream>
#include "Class.h"
#include "Strategy.h"
#include "Stats.h"
#include "Item.h"
#include "Weapons.h"
#include <vector>
#include <map>


class Player {
public:
	Player(/*Strategy* strat,*/ Class* classie, std::string name);
	~Player();
	enum fightStates {HEAl,ATTACK,PASS, OUT_OF_MANA} typedef;
	//void SetStrat(Strategy* strat, int next);
	int shortDamage(int stati_bonus);

	

	int GetLevel();



	/*void ChangeStrat(CurrentStrat P_CurrStrat) {
		switch (P_CurrStrat) {
		LVL1:
			Level_Strat = ;
			currStrat = LVL5;
			break;

		}
	}*/

	//bool HaveToChangeStrat();

	std::string GetPlayerName();

	//int GetClassDmg();

	Stats& GetStat();

	std::string GetClassName();

	void MinusResource(int& val);

	void LoseHP(int& val);

	void Die();

	/*void GetPlayerStats() {
		std::cout << "Class name: " << Player_Class->GetClassName() << std::endl;
		std::cout << "Max def:" << stats.MaxDef << std::endl;
		std::cout << "Max hp:" << stats.MaxHp << std::endl;
		std::cout << "Max resource:" << stats.MaxResource << std::endl;
		std::cout << "Mental Health: " << stats.MentalHealth << std::endl;
		std::cout <<"Power Damage:" << stats.PowerDamage << std::endl;
		std::cout << "Player Level: " << GetLevel() << std::endl;

	}*/

	void GetPlayerStats();

	void AddExperience(int& xp);

	void LevelUp(int& modi);

	int AddItemToBackpack(Item* item_item);
	void RemoveItem(Item* item);//Create an item manager later
	void* PrintBackpackItems();
	int GetItemIndex(Item* item);
	void RemoveItemFromBackpackAtIndex(int& index);

	void RandomFunnyConversation();

	fightStates ShowUpFightSceneAndChoose();
	void Heal();
	int& GetCurrentHealth();
	int& GetCurrentResource();
	bool IsUsable(int& currRes, int& cost);
	/*void ChooseClass(float pDmg, float def) {
		Warrior chosenClass(pDmg, def);
		Player_Class = &chosenClass;
	}*/

private:
	friend void PrintPlayerInfo(const Player&);
 	std::string Player_Name = "not_set";
	Class* Player_Class = nullptr;
	//Strategy* Level_Strat = nullptr;
	int Player_Level = 0;
	int CurrentHP = 0;
	int CurrentResource = 0;
	int CurrentDef = 0;
	int Player_Experience = 0;
	int NextStrat = 0;
	double ExpNeededForTheNextLevel = 100;
	//CurrentStrat currStrat{};
	Stats stats{};
	int StratChange = 0;
	int Max_Backpack_Size = 5;
	int Curr_Backpack_Size = 0;
	int DmgResourceMinus = 0;
	int HealResourceMinus = 0;
	std::vector<Item*> P_Backpack{};

};
#endif // !PLAYER_H
