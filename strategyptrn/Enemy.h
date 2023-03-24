#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "Stats.h"
#include <iostream>
#include "randomMathStuffs.h"
extern class Enemy {
public:
	/// <summary>
	/// Make a base enemy(like a minion)
	/// </summary>
	Enemy();
	/// <summary>
	/// Create customized enemy;
	/// </summary>
	Enemy(int hp, int def, int mentalH, int dmg, int dmgResource, int critCh, int reactionper);
	~Enemy();
	enum states {HEAL,ATTACK,DEFENSE, BASE} typedef states;

	states WhatShouldIDoInFight(int& P_hp, int& P_res, int& EnemyAtkWhatICurrentlyKnow);
	 void RandomFunnyConversation();
	 void PrintEnemyCurrStat();
	 void InitCurrStats();

	 void GetEnemyStat();
	  void GetCurrEnemyInfo();
	 bool IsCanReact();
	 void LoseHealth(int& val);
	  int GetCurrentHealth();
	 void Heal(int& val);
	 int GetDamage();
	 Enemy& GetEnemy();
	

	Stats stat;
	int HealAmount = 22;
private:
	inline bool ShouldIHeal(int& healRes, int& P_CurrKnownAtk, int& P_currHp);
	inline bool CanIDamage(int& dmgRes);
	int CurrHp = 0;
	int CurrDmgRes = 0;
	int CurrMentalH = 0;
	int currDef = 0;
	int healCost;
	int dmgCost;
	int ReactionPercent = 0;
	states matchState = Enemy::BASE;
	int healRes = 5;
	int dmgRes = 4;
	int rowPos = 0;
	int colPos = 0;
	const char* funniConversations[3] = {"hehe", "hihi", "huhu"};

};

#endif // !ENEMY_H
