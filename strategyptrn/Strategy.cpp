#include "Strategy.h"


	//~Level1Strat();
	int Level1Strat::ShortDamage(int baseAtk, int bonusAtk)  {
		return baseAtk + bonusAtk;
	}

	int Level1Strat::LongDamage(int baseAtk, int bonusAtk)  {
		return baseAtk * bonusAtk;
	}




	//~Level5Strat();

	int Level5Strat::ShortDamage(int baseAtk, int bonusAtk)  {
		return baseAtk + bonusAtk + 5;
	}

	int Level5Strat::LongDamage(int baseAtk, int bonusAtk)  {
		return baseAtk * bonusAtk + 5;
	}


	//~Level10Strat();

	int Level10Strat::ShortDamage(int baseAtk, int bonusAtk)  {
		return baseAtk + bonusAtk + 10;
	}

	int Level10Strat::LongDamage(int baseAtk, int bonusAtk)  {
		return baseAtk * bonusAtk + 10;
	}
