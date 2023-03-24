
#ifndef STATS_H
#define STATS_H
#pragma once
//#include "Class.h"

struct Stats {
	 int PowerDamage = 0;
	 int MentalHealth = 0;

	 int MaxHp = 0;
	int MaxDef = 0;

	int MaxResource = 0;

	int CritChance = 0;
};
typedef struct Stats Stats;

inline Stats& operator+=(Stats& ns, Stats& sos) {
	ns.PowerDamage += sos.PowerDamage;
	ns.MentalHealth += sos.MentalHealth;
	ns.MaxHp += sos.MaxHp;
	ns.MaxDef += sos.MaxDef;
	ns.MaxResource += sos.MaxResource;
	ns.CritChance += sos.CritChance;

	return ns;
}

inline Stats& operator-=(Stats& ns, Stats& sos) {
	ns.PowerDamage -= sos.PowerDamage;
	ns.MentalHealth -= sos.MentalHealth;
	ns.MaxHp -= sos.MaxHp;
	ns.MaxDef -= sos.MaxDef;
	ns.MaxResource -= sos.MaxResource;
	ns.CritChance -= sos.CritChance;

	return ns;
}

inline void _Init_Da_Stats(Stats& stati) {
	stati.PowerDamage = 10;
	stati.MaxResource = stati.MaxHp = 100;
	stati.MaxDef = 10;
	stati.MentalHealth = 10;
}

inline void Init_Base_Enemy_Stat(Stats& statt) {
	statt.MaxHp = 55; 
	statt.MaxDef = 15; 
	statt.MentalHealth = 40; 
	statt.PowerDamage = 11; 
	statt.MaxResource = 44; 
	statt.CritChance = 24;
}
#endif // !STATS_H
