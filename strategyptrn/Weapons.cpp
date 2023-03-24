#include "Weapons.h"
#include <iostream>
//LONGSWORD------------------------------------

LongSword::LongSword(int dmg, int mHealth, int maxHealth, int maxDef, int maxRes,
	int critChance, EquippableCharacter equippable, ItemType type, int minLevel) {
	I_stat.PowerDamage += dmg, I_stat.MentalHealth += mHealth; I_stat.MaxHp += maxHealth;
	I_stat.MaxDef += maxDef; I_stat.MaxResource += maxRes; I_stat.CritChance += critChance;
	I_equippableChar = equippable; I_itemtype = type; I_minimumLevel = minLevel;
}


	
Item::EquippableCharacter LongSword::GetEquippableChar() {
	return I_equippableChar;
}

Item::ItemType LongSword::GetItemType() {
	return I_itemtype;
}

void LongSword::KabbeFaszom() {
	std::cout << "Igen" << std::endl;
}

  void* LongSword::PrintItemInfo() {
	std::cout << "Damage bonus: " << I_stat.PowerDamage << std::endl;
	std::cout << "Mental health bonus: " << I_stat.MentalHealth << std::endl;
	std::cout << "Crit Chance bonus: " << I_stat.CritChance << std::endl;
	std::cout << "Class Resource bonus: " << I_stat.MaxResource << std::endl;
	std::cout << "Health bonus: " << I_stat.MaxHp << std::endl;
	std::cout << "Defense bonus: " << I_stat.MaxDef << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	return 0;
  }

//----------------------------------------------

ShortSword::ShortSword(int dmg, int mHealth, int maxHealth, int maxDef, int maxRes,
	int critChance, EquippableCharacter equippable, ItemType type,
	int minLevel, int doubleAtkChnc) {
	I_stat.PowerDamage += dmg, I_stat.MentalHealth += mHealth; I_stat.MaxHp += maxHealth;
	I_stat.MaxDef += maxDef; I_stat.MaxResource += maxRes; I_stat.CritChance += critChance;
	I_equippableChar = equippable; I_itemtype = type; I_minimumLevel = minLevel; P_DoubleAtkChance = doubleAtkChnc;
}


Item::EquippableCharacter ShortSword::GetEquippableChar() {
	return I_equippableChar;
}

Item::ItemType ShortSword::GetItemType() {
	return I_itemtype;
}

void ShortSword::KabbeFaszom() {
	std::cout << "Igen" << std::endl;
}

  void* ShortSword::PrintItemInfo() {
	std::cout << "Damage bonus: " << I_stat.PowerDamage << std::endl;
	std::cout << "Mental health bonus: " << I_stat.MentalHealth << std::endl;
	std::cout << "Crit Chance bonus: " << I_stat.CritChance << std::endl;
	std::cout << "Class Resource bonus: " << I_stat.MaxResource << std::endl;
	std::cout << "Health bonus: " << I_stat.MaxHp << std::endl;
	std::cout << "Defense bonus: " << I_stat.MaxDef << std::endl;
	std::cout << "Double attack chance:" << P_DoubleAtkChance << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	return 0;
}
