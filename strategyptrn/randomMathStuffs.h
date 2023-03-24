#ifndef RANDOMMATHSTUFFS_H
#define RANDOMMATHSTUFFS_H

#include <random>
#include <iostream>

inline float Lerp(float& a, float& b, float& t)
{
	return a + (b - a) * t;
}

inline int Abs(int& a) {
	return a * (-1);
}

inline int MaxFromArr(int arr[], int& size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

inline float PI()
{
	return 3.14159265358979f;
}

inline int Pow2TwoInt(int& num)
{
	return num * num;
}

inline int Pow(int& powNum, int& toPower)
{
	return toPower * powNum;
}

inline int HypotLength(int& aSqrt, int& bSqrt)
{
	return aSqrt + bSqrt;
}

inline float Euler()
{
	return 2.71828f;
}

inline float Exp(int& num)
{
	return num * Euler();
}

inline int Sign(float& f)
{
	if (f >= 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

inline int rand(int min, int max)
{
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}



/*int Wrap(float& x, float min, float max)
{
	//rand num between the two?
	return rand(min, max);
}*/

/*void Wrapi(float& x, float min, float max) {
	x = rand(min, max);
}*/

inline bool IsWithInAllExclusive(int& a, int& b, int& val)
{
	if ((val > a) && (val < b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool IsWithInAllInclusive(int& a, int& b, int& val)
{
	if ((val >= a) && (val <= b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*bool RandBool()
{
	int randNum = rand(-1, 2);
	if (randNum == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}*/

 inline float Sin(float& opposite, float& hypotenuse) {
	return opposite / hypotenuse;
}

 inline float Cos(float& adjacent, float& hypotenuse) {
	return adjacent / hypotenuse;
}

 inline float Tan(float& sin, float& cos) {
	return sin / cos;
}

 inline int Ffloor(float& f) {
	int i = f;
	return i;
}

#endif
