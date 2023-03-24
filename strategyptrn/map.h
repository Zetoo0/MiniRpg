#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "randomMathStuffs.h"
#include "Enemy.h"

struct Map {
public:
	char map[5][5];
	void PrintMap();
	void CreateMap();
	void MoveOnTheMap(char& direction);
	bool IsCanMoveThere(int row, int column);
private:
	char WhatObjectShouldICreate(int percent);
	int initPlayerPosRow = 0;
	int initPlayerPosColumn = 0;
	int maxRow = 5;
	int maxCOl = 5;
};

void Map::PrintMap() {
	system("CLS");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Map::CreateMap() {//later create a linked list for better and more complex things
	map[0][2] = 'E';
	map[4][2] = 'P';
	initPlayerPosRow = 4;
	initPlayerPosColumn = 2;
	int normalObjPercent = 55;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] != 'E'&& map[i][j] != 'P') {
				map[i][j] = WhatObjectShouldICreate(normalObjPercent);
			}
		}
	}
}

char Map::WhatObjectShouldICreate(int percent) {
	int min = 0;
	int max = 100;
	int randika = rand(min, max);
	std::cout << randika;
	char ret = randika <= percent ? 'X' : 'O';
	//std::cout << ret << std::endl;
	return ret;
}

void Map::MoveOnTheMap(char& direction) {
	switch (direction) {
	case 'w':
		if (IsCanMoveThere(initPlayerPosRow - 1, initPlayerPosColumn)) {
			std::swap(map[initPlayerPosRow][initPlayerPosColumn], map[initPlayerPosRow - 1][initPlayerPosColumn]);
			initPlayerPosRow -= 1;
		}
		break;
	case 's':
		if (IsCanMoveThere(initPlayerPosRow + 1, initPlayerPosColumn)) {
			std::swap(map[initPlayerPosRow][initPlayerPosColumn], map[initPlayerPosRow + 1][initPlayerPosColumn]);
			initPlayerPosRow += 1;
		}
		break;
	case 'a':
		//std::cout << "balra lépnék BAZDMEG" << std::endl;
		std::cout << "PlayerCurrRow: " << initPlayerPosRow << " PlayerCurrCol: " << initPlayerPosColumn << std::endl;
		if (IsCanMoveThere(initPlayerPosRow, initPlayerPosColumn-1)) {
			std::swap(map[initPlayerPosRow][initPlayerPosColumn], map[initPlayerPosRow][initPlayerPosColumn - 1]);
			initPlayerPosColumn -= 1;
			std::cout << "PlayerNextCurrRow: " << initPlayerPosRow << " PlayerNextCurrCol: " << initPlayerPosColumn << std::endl;
		}
		break;
	case 'd':
		if (IsCanMoveThere(initPlayerPosRow, initPlayerPosColumn+1)) {
			std::swap(map[initPlayerPosRow][initPlayerPosColumn], map[initPlayerPosRow][initPlayerPosColumn+1]);
			initPlayerPosColumn += 1;
		}
		break;
	}
}

int GetEnemyPosition(&Enemy enemy) {

}


bool Map::IsCanMoveThere(int row, int column) {
	bool retu = map[row][column] == 'X'; //&& initPlayerPosRow != maxRow && initPlayerPosColumn != maxCOl ? true : false;
	//std::cout << retu << std::endl;
	return retu;

}

#endif // MAP_H
