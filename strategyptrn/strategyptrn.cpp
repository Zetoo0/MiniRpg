// strategyptrn.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "player.h"
#include "Warrior.h"
#include "Strategy.h"
#include <memory>
#include "PlayerSheet.h"
#include "Weapons.h"
#include "Item.h"
#include "enemy.h"
#include "map.h"
#include <Windows.h>
 //Warrior* wari = new Warrior();
//Item* ls = new LongSword(30, 0,0, 0, 0, 15, Item::WARRIOR, Item::WEAPON, 1);
//Item* shs = new ShortSword(19,0,0,0,0,27,Item::WARRIOR,Item::WEAPON,1,35);
//L//evel1Strat lvl1Strat{};
//Level5Strat lvl5Strat{};
//Level10Strat lvl10Strat{};

Player* player = nullptr;
Enemy* enemicske = nullptr;


//Player::fightStates PlayerFightState;


int isAnyoneDead(int playerHealth, int enemyHealth) {
	int retNum = playerHealth <= 0 ? 1 : enemyHealth <= 0 ? 2 : 0;
	std::cout << retNum << std::endl;
	return retNum;
}


//TODO-befejezni rendesen a fightrendszert, bothoz hozz�nyulni kicsit, resource ad�s k�r v�g�n, resource balance(t�bb legyen a heal)
void StartDaFight(/*Player* player, Enemy* enemy*/ Player* player, Enemy* enemy) {
	bool IsFightShouldEnd = false;
	int P_Dmg = player->GetStat().PowerDamage;
	int P_CurrHp = player->GetCurrentHealth();
	int P_CurrRes = player->GetCurrentResource();
	int E_CurrHp = enemy->GetCurrentHealth();
	int E_Dmg = enemy->GetDamage();
	short whoIsDead = 0;//ha 1 akkor player ha 2 akkor enemy, ha 0 akkor senki
	int currKnownPlayerAtkForAI = 0;
	while (!IsFightShouldEnd) {
		//Els� k�r legyen a player�
		switch (player->ShowUpFightSceneAndChoose()) {
		case Player::ATTACK:
			enemy->LoseHealth(P_Dmg);
			currKnownPlayerAtkForAI = (P_Dmg);
			//Damage
			break;
		case Player::HEAl:
			player->Heal();
			//heal
			break;
		case Player::PASS:
			//Pass the turn
			break;
		}
		std::cout << "Enemy" << std::endl;
		enemy->GetCurrEnemyInfo();
		//Checker, hogy v�ge-e a harcnak?
		whoIsDead = isAnyoneDead(P_CurrHp, E_CurrHp);
		switch (whoIsDead)
		{
		case 1:
			std::cout << "Player dead, Enemy won" << std::endl;
			IsFightShouldEnd = true;
			break;
		case 2:
			std::cout << "Enemy dead, Player won" << std::endl;
			break;
		default:
			break;
		}

		//Azt�n j�het a daEnemy
		switch (enemy->WhatShouldIDoInFight(P_CurrHp, P_CurrRes, currKnownPlayerAtkForAI)) {
		case Enemy::ATTACK:
			std::cout << "Damazs" << std::endl;
			player->LoseHP(E_Dmg);
			break;
		case Enemy::HEAL:
			enemy->Heal(enemy->HealAmount);
			std::cout << "Heal, new hp: " << E_CurrHp << std::endl;
			break;
		case Enemy::BASE:
			std::cout << "Base" << std::endl;
		}

		//Azt�n megint check?
		switch (whoIsDead)
		{
		case 1:
			std::cout << "Player dead, Enemy won" << std::endl;
			IsFightShouldEnd = true;
			break;
		case 2:
			std::cout << "Enemy dead, Player won" << std::endl;
			break;
		default:
			break;
		}
	}
}

bool IsCanMove(char& d){
	bool ize = d == 'w' || d == 's' || d == 'a' || d == 'd' ? true : false;
	//std::cout << "Iz�: " << ize << std::endl;
	return ize;

}

/*int UpdateMovement(Map& mapika) {
	int retKey = GetKeyState('a') < 0 ? 1 : GetKeyState('d') <0 ? 2 : GetKeyState('w') < 0 ? 3 : GetKeyState('s') < 0 ? 4 : 0;
	if (retKey != 0) {
		mapika.MoveOnTheMap(retKey);
		mapika.PrintMap();
	} 
	return -1;
}*/



int main()
{

	
	//	bool stratChange = false;
	player = new Player(new Warrior(), "Jancsicska");
	 int a = 100;
	 int b = 100;
	 int c = 100;
	 int d = 10;
	 int g = 100;
	 int h = 100;
	 int j = 23;
	 char direction;
	 enemicske = new Enemy(a, b, c, d, g, h, j);
	 Map mapika;
	 mapika.CreateMap();
	 mapika.PrintMap();


	 std::cout << "Direction: ";
	 std::cin >> direction;
	 while (IsCanMove(direction)) {
		 mapika.MoveOnTheMap(direction);
		 mapika.PrintMap();
		 std::cout << "Direction: ";
		 std::cin >> direction;
	 }
	 //while (UpdateMovement(mapika) != 9) {
		// UpdateMovement(mapika);
	 //}
	 //mapika.PrintMap();
	 //mapika.MoveOnTheMap('c');
	 //std::cout << enemicske->GetCurrentHealth() << std::endl;
	 //enemicske->GetCurrEnemyInfo();
	 //StartDaFight(player, enemicske);
	 // enemicske->GetCurrEnemyInfo();
	//Player *playerPtr = &player;
	//std::cout << player.GetStat().MaxHp << std::endl;
//	PrintPlayerInfo(player);
	//player->LoseHP(30);
	//player.AddExperience(115);
//	PrintPlayerInfo(player);
	//ls->PrintItemInfo();
	///player.AddItemToBackpack(ls);
	///player.AddItemToBackpack(shs);
	//player.PrintBackpackItems();
	//player.RemoveItemFromBackpackAtIndex(1);
	//player.PrintBackpackItems();
	//player.RemoveItemFromBackpackAtIndex(1);
	//player.PrintBackpackItems();
	//player.PrintBackpackItems();
	//enemicske->GetCurrEnemyInfo();
	//enemicske->IsCanReact();
	///enemicske->RandomFunnyConversation();
	//enemicske->WhatShouldIDoInFight(2, 25);
	//StartDaFight(&player, enemicske);
	//player.ShowUpFightSceneAndChoose();
	//ls->PrintItemInfo();
//	shs->PrintItemInfo();
	//wari->~Warrior();
	//delete ls;
	//delete shs;
	return 0;
}

//TODO item, backpack, refactorin k�l�nv�lasztani a headert �s a cppt, m�rmint yeah megcsin�lni, �t�ni �gy
//TODO folyt, cpp-k megvannak k�l�n m�r csak majd a headerekbe kell kivenni a met�dusok megold�s�t Pipa
//T�mad�sok, dmg?
// Amikor tudok, �j classok, de az m�r bonus �gy, mondjuk legal�bb 2 kell, hogy lehessen v�lasztnai
// esetleges TODO: shopping system vagy valami hasonl�
// very big TODO alapok ut�n, "Stand" system
// TODO Ability sys????????
// Backpack t�rl�s �j m�d: 1.ki�rjuk a backpackben lev� itemeket, indexekkel ell�tva(index+1) -> a user be�rja, hogy hanyas index� itemet szeretn� t�r�lni -> t�rli az itemet jeeee -> eddig elvileg sikeres, mert csak 1 itemet adott vissza a kett�b�l yeee
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
 