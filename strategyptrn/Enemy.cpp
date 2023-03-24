#include "Enemy.h"
#include "randomMathStuffs.h"
#include <iostream>

Enemy::Enemy() {
	Init_Base_Enemy_Stat(stat);
	InitCurrStats();
}

Enemy::Enemy(int hp, int def, int mentalH, int dmg, int dmgResource, int critCh, int reactionper) {
	stat.MaxHp = hp; stat.MaxDef = def; stat.MentalHealth = mentalH; stat.PowerDamage = dmg; stat.MaxResource = dmgResource; stat.CritChance = critCh; ReactionPercent = reactionper;
	InitCurrStats();
}

 bool Enemy::IsCanReact() {
	int min = 0;
	int max = 100;
	float randed = rand(0, 100);
	std::cout << ReactionPercent << "-" << randed << std::endl;
	if (randed <= ReactionPercent) {
		return true;
	}
	return false;
}

 void Enemy::RandomFunnyConversation() {
	int min = 0;
	int max = 2;
	int randomed = rand(0, 2);
	std::cout << "Random funi: " << funniConversations[randomed];
}

 void Enemy::InitCurrStats() {
	CurrHp = stat.MaxHp;
	currDef = stat.MaxDef;
	CurrDmgRes = stat.MaxResource;
	CurrMentalH = stat.MentalHealth;
}

 Enemy::states Enemy::WhatShouldIDoInFight(int& P_hp, int& P_res, int& EnemyAtkWhatICurrentlyKnow) {
	if (ShouldIHeal(healRes, EnemyAtkWhatICurrentlyKnow, P_hp)) {
		std::cout << "Heal" << std::endl;
		return Enemy::HEAL;
		//Heal
	}
	else if (CanIDamage(dmgRes)) {
		std::cout << "Damage" << std::endl;
		return Enemy::ATTACK;
		//Damage
	}
	else {
		std::cout << "What da hell" << std::endl;
		return Enemy::BASE;
	}
	return Enemy::BASE;
}

 bool Enemy::CanIDamage(int& dmgRes) {
	if (CurrDmgRes - dmgRes >= 0) {
		return true;
	}
	return false;
}
 void Enemy::Heal(int& val) {
	CurrHp += val;
	CurrDmgRes -= healRes;
}

 bool Enemy::ShouldIHeal(int& healRes, int& P_CurrKnownAtk, int& P_currHp) {
	int PlayerNextHp = P_currHp - stat.PowerDamage;
	if (PlayerNextHp <= 0) return false;
	int OwnNextHp = CurrHp - P_CurrKnownAtk;
	if (OwnNextHp <= 0 && (CurrDmgRes - healRes) >= 0) return true;
	if ((CurrDmgRes - healRes) >= 0 /*OwnNextHp <= 0*/ && PlayerNextHp >= stat.PowerDamage) { //Szétszedni késõbb vagyokkal
		return true;
	}
	return false;
}

 void Enemy::LoseHealth(int& val) {
	CurrHp -= val;
	if (CurrHp <= 0) {
		std::cout << "I'm Dead" << std::endl;
	}
}

 int Enemy::GetCurrentHealth() {
	return CurrHp;
}

 int Enemy::GetDamage() {
	return stat.PowerDamage;
}
 

 void Enemy::GetCurrEnemyInfo() {
	std::cout << "------------------------------" << std::endl;
	std::cout << "Enemy info" << std::endl;
	std::cout << "Health: " << stat.MaxHp << "/" << CurrHp << std::endl;
	std::cout << "Defense: " << stat.MaxDef << "/" << CurrHp << std::endl;
	std::cout << "Damage: " << stat.PowerDamage<< std::endl;
	std::cout << "Critical Chance: " << stat.CritChance << std::endl;
	std::cout << "Damage Resource: " << stat.MaxResource << "/" << CurrDmgRes << std::endl;
	std::cout << "Mental Health: " << stat.MentalHealth << "/" << CurrMentalH << std::endl;
	std::cout << "------------------------------" << std::endl;


}

 Enemy& Enemy::GetEnemy() {
	 return *this;
 }