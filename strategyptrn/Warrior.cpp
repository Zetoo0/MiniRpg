#include <iostream>
#include <string>
#include "Warrior.h"

	//Warrior();//WARRIOR
Warrior::Warrior() { /*PhysicalDmg = pDmg; Defense = def; Rage = 0;*/stat.PowerDamage += 5; stat.MaxDef += 20; stat.MentalHealth -= 5; std::cout << "created waru" << std::endl; }
	//Warrior::~Warrior() { std::cout << "deleteded warrior" << std::endl; }

Warrior::~Warrior() {
	std::cout << "destructed";
}

	int Warrior::GetPhysicalDmg() /*override*/ {
		return stat.PowerDamage;
		
	}

	int Warrior::GetMentalHealth() {
		return stat.MentalHealth;
	}

	int Warrior::GetDefense(){
		return stat.MaxDef;
	}

	int Warrior::GetRage() {
		return stat.MaxResource;
	}

	void Warrior::SetPhysicalDmg(int val){
		stat.PowerDamage = val;
	}

	void Warrior::SetDefense(int val){
		stat.MaxDef = val;
	}

	std::string Warrior::GetClassName() { return "Warrior"; }
	std::string Warrior::GetDamageResourceName()  { return "Rage"; }

	//sint Warrior::GetMagicalDmg()  { return -1; };
	//int Warrior::GetMentalHealth()  { return -1; };
	//void Warrior::SetMagicalDmg(int val)  {};
	//void Warrior::SetMentalHealth(int val)  {};
	

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