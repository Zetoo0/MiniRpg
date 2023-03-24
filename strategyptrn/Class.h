#ifndef CLASS_H
#define CLASS_H
#pragma once
#include <iostream>
#include <string>
#include "Stats.h"

class Class {
public:
	virtual ~Class() = default;

//	virtual int GetPhysicalDmg() = 0;
//	virtual int GetMagicalDmg() = 0;
	virtual int GetMentalHealth() = 0;
	virtual int GetDefense() = 0;

	//static add functions

	//virtual void SetPhysicalDmg(int val) = 0;
	//virtual void SetMagicalDmg(int val) = 0;
	//virtual void SetMentalHealth(int val) = 0;
	//virtual void SetDefense(int val) = 0;
	virtual std::string GetClassName() { return "no"; }
	virtual std::string GetDamageResourceName() { return "no"; }

	Stats stat{};
};


	//float PhysicalDmg = 0;
	//float MagicalDmg = 0;
	//float Mental_Health = 0;//mage classes can dmg more with better mental health
	//f//loat Defense = 0;
	



/*class Mage : public Class {
public:
	//Mage();
	Mage()
	~Mage(); 

private:
	float MagicalDmg;
	float Mental_Health;
	float Defense;
};*/
#endif // !CLASS_H
