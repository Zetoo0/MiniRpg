#ifndef STRATEGY_H
#define STRATEGY_H

#pragma once



class Strategy {
public:
	virtual ~Strategy() = default;
	virtual int ShortDamage(int baseAtk, int bonusAtk) = 0;
	virtual int LongDamage(int baseAtk, int bonusAtk) = 0;
};

class Level1Strat : public Strategy {
public:
	//~Level1Strat();
	int ShortDamage(int baseAtk, int bonusAtk) override;

	int LongDamage(int baseAtk, int bonusAtk) override;

};

class Level5Strat : public Strategy {
public:
	//~Level5Strat();

	int ShortDamage(int baseAtk, int bonusAtk) override;

	int LongDamage(int baseAtk, int bonusAtk) override;
};

class Level10Strat : public Strategy {
public:
	//~Level10Strat();

	int ShortDamage(int baseAtk, int bonusAtk) override;

	int LongDamage(int baseAtk, int bonusAtk) override;
};

#endif // !STRATEGY_H
