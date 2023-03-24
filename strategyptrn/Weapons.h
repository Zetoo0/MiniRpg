#ifndef WEAPONS_H
#define WEAPONS_H
#pragma once
#include "Item.h"
#include <iostream>

class Weapon : public Item {
	
	virtual void KabbeFaszom() = 0;
	
};


class LongSword : public Weapon {
public:
	LongSword(int dmg, int mHealth, int maxHealth, int maxDef, int maxRes,
		int critChance, EquippableCharacter equippable, ItemType type,
		int minLevel);
	 


	EquippableCharacter GetEquippableChar() override;
	ItemType GetItemType() override;
	//void GetItemStat() override;
	  void* PrintItemInfo() override;
	  void KabbeFaszom() override;
};	


class ShortSword : public Weapon {
public:
	ShortSword(int dmg = 0, int mHealth = 0, int maxHealth = 0, int maxDef = 0, int maxRes = 0,
		int critChance = 0, EquippableCharacter equippable = WARRIOR, ItemType type = WEAPON,
		int minLevel = 1, int doubleAtkChnc = 0);

	EquippableCharacter GetEquippableChar() override;
	ItemType GetItemType() override;
	//void gGetItemStat() override;
	 void* PrintItemInfo() override;
	 void KabbeFaszom() override;

private:
	int P_DoubleAtkChance = 0;
	bool isDoubleAttacked = false;
};




#endif // !WEAPONS_H
