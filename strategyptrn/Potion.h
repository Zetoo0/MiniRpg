#include "Item.h"


class Potion : Item {
public:
	Potion();
	~Potion();
	enum PotionType{HEAL, BUFF};

	virtual void UsePotion();

protected:

private:


};