#pragma once
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

#define SET_LENGTH 100

class Conjunto
{
public:

	Conjunto();
	void print();
	void create(string);

	int setArray[SET_LENGTH];
	int setLength = 0;

};

