#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>

	Player::Player(/*Strategy* strat,*/ Class* classie,std::string name) { /*Level_Strat = strat;*/ Player_Class = classie; Player_Level = 1, Player_Experience = 0; _Init_Da_Stats(stats); stats += classie->stat; Player_Name = name; CurrentHP = stats.MaxHp; CurrentResource = stats.MaxResource; }
	Player::~Player() { std::cout << "deleted player" << std::endl; }
	//void Player::SetStrat(Strategy* strat, int next) { Level_Strat = strat; NextStrat = next; /*currStrat = LVL1;*/ }
	/*int Player::shortDamage(int stati_bonus) {
		return Level_Strat->ShortDamage(Player_Class->GetPhysicalDmg(), stati_bonus);
	}*/



	int Player::GetLevel() {
		return Player_Level;
	}



	/*void ChangeStrat(CurrentStrat P_CurrStrat) {
		switch (P_CurrStrat) {
		LVL1:
			Level_Strat = ;
			currStrat = LVL5;
			break;

		}
	}*/

	/*bool Player::HaveToChangeStrat() {
		return Player_Level == NextStrat ? true : false;
	}*/

	std::string Player::GetPlayerName() {
		return Player_Name;
	}

	//int Player::GetClassDmg() {
		//return Player_Class->G;
	//}

	Stats& Player::GetStat() {
		return stats;
	}

	std::string Player::GetClassName() {
		return Player_Class->GetClassName();
	}

	void Player::MinusResource(int& val) {
		CurrentResource -= val;
	}

	void Player::LoseHP(int& val) {
		CurrentHP -= val;
		if (CurrentHP <= 0) {
			Die();
		}
	}

	Player::fightStates Player::ShowUpFightSceneAndChoose() {
		char chosenState;
		std::cout << "Player round" << std::endl;
		GetPlayerStats();
		std::cout << "Press Q to Attack\tPress H to Heal\tPress P to Pass the round" << std::endl;
		std::cin >> chosenState;
		switch (chosenState){
		case 'q':
			if (IsUsable(CurrentResource, DmgResourceMinus)) {
				std::cout << "atk" << std::endl;
				CurrentResource -= DmgResourceMinus;
				return Player::ATTACK;
			}
			else {
				return Player::OUT_OF_MANA;
			}

			break;
		case 'h':
			if (IsUsable(HealResourceMinus, DmgResourceMinus)) {
				std::cout << "hööl" << std::endl;
				CurrentResource -= HealResourceMinus;
				return Player::HEAl;
			}
			else {
				return Player::OUT_OF_MANA;
			}
			break;
		case 'p':
			return Player::PASS;
			break;
		default:
			std::cout << "BreakDown" << std::endl;
			return Player::PASS;
			break;
		}
	}

	bool Player::IsUsable(int& currRes, int& cost) {
		if (currRes >= cost) {
			return true;
		}
		else {
			return false;
		}
		return false;
	}

	void Player::Heal() {
		CurrentHP += 12;//Kijavítani rendes változóra
		std::cout << "Healed, new hp:" << CurrentHP;
	}

	void Player::Die() {
		std::cout << "Player Dead!" << std::endl;
	}

	void Player::GetPlayerStats() {
		//std::cout << "Class name: " << Player_Class->GetClassName() << std::endl;
		std::cout << "Current def:" << CurrentDef  <<"/" << stats.MaxDef<< std::endl;
		std::cout << "Current hp:" << CurrentHP << "/"<< stats.MaxHp<< std::endl;
		std::cout << "Current resource:" << CurrentResource <<"/" <<stats.MaxResource<< std::endl;
		std::cout << "Current Mental Health: " << stats.MentalHealth << std::endl;
		std::cout <<"Power Damage:" << stats.PowerDamage << std::endl;
		std::cout << "Player Level: " << GetLevel() << std::endl;

	}


	void Player::AddExperience(int& xp) {
		Player_Experience += xp;
		if (Player_Experience >= ExpNeededForTheNextLevel) {
			int nextL = Player_Experience - ExpNeededForTheNextLevel;
			LevelUp(nextL);
		}
	}

	void Player::LevelUp(int& modi) {
		std::cout << "Level up" << std::endl;
		Player_Experience = modi;
		Player_Level++;
		switch (Player_Level) {
		case 5:
			ExpNeededForTheNextLevel = ExpNeededForTheNextLevel * 1.3;
			break;
		case 10:
			ExpNeededForTheNextLevel = ExpNeededForTheNextLevel * 1.6;
			break;
		default:
			ExpNeededForTheNextLevel = ExpNeededForTheNextLevel * 1.15;
		}
		//if(Have1ToChangeStrat());
	}

	int Player::AddItemToBackpack(Item* item_item) {
		//Átírni hogy majd a mainbe checkelje valahogy??emlékeztetõ!!
		if (Curr_Backpack_Size == Max_Backpack_Size) {
			std::cout << "Backpack is full!";
			return -1;
		}
		P_Backpack.push_back(item_item);
		Curr_Backpack_Size++;
		return 0;
	}

	void* Player::PrintBackpackItems() {
		if (Curr_Backpack_Size == 0) {
			std::string booze = "There are no items in here!";
			//for (char t : booze) {
				//std::cout << t;
			//}
			//std::endl;
			std::cout << "There are no items in here" << std::endl;
			return 0;
		}
		else {
			int i = 0;
			for (Item* item : P_Backpack) {
				std::cout << "-----------------------------------" << std::endl;
				std::cout << "Index: " << i + 1 << std::endl;
				item->PrintItemInfo();
				i++;
			}
		}
		return 0;
	}

	/*int Player::GetItemIndex(Item* item) {
		auto ind = std::find(P_Backpack.begin(), P_Backpack.end(), item);
		if (ind != P_Backpack.end()) {
			int indexKecske = ind - P_Backpack.begin();
			return indexKecske;
		}
		else {
			return -1;
		}
	}*/

	void Player::RemoveItemFromBackpackAtIndex(int& index) {
		RemoveItem(P_Backpack[index - 1]);
		P_Backpack.erase(P_Backpack.begin() + (index - 1));
		std::cout << "Successfully deleted da item!" << std::endl;;
		Curr_Backpack_Size--;
	}

	void Player::RemoveItem(Item* item) {
		delete item;
		item = nullptr;
		
	}

	int& Player::GetCurrentHealth() {
		return CurrentHP;
	}

	int& Player::GetCurrentResource() {
		return CurrentResource;
	}
	

	/*void ChooseClass(float pDmg, float def) {
		Warrior chosenClass(pDmg, def);
		Player_Class = &chosenClass;
	}*/