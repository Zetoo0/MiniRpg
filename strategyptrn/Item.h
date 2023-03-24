#ifndef ITEM_H
#define ITEM_H
#pragma once
#include "Stats.h"

class Item {
public:
	Item() = default;
	~Item() = default;
	enum EquippableCharacter {WARRIOR, MAGE, DEFAULT};
	enum ItemType {WEAPON, HEAD_ARMOR, CHEST_ARMOR, SHOULDER_ARMOR, LEG_ARMOR};

	//Getters
	virtual EquippableCharacter GetEquippableChar() = 0;
	virtual ItemType GetItemType() = 0;
	//virtual void GetItemStat() = 0;
	virtual void* PrintItemInfo() = 0;


	Stats I_stat{};
protected:
	int I_minimumLevel = 0;
	EquippableCharacter I_equippableChar = DEFAULT;
	ItemType I_itemtype = WEAPON;
};





#endif