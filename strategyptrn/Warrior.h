#ifndef WARRIOR_H
#define WARRIOR_H
#pragma once
#include "Class.h"
#include <string>
//#include <iostream>

class Warrior : public Class {
public:
	//Warrior();
	Warrior();
	~Warrior() override;

	int GetPhysicalDmg();
	int GetMentalHealth() override;

	int GetDefense() override;

	virtual int GetRage();

	void SetPhysicalDmg(int val);

	void SetDefense(int val);

	std::string GetClassName() override;
	std::string GetDamageResourceName() override;

//	int GetMagicalDmg() override { return -1; }
//	int GetMentalHealth() override { return -1; }
//	void SetMagicalDmg(int val) override {}
//	void SetMentalHealth(int val) override {}

};


#endif // !WARRIOR_H
