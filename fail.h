#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>

void outArr(std::string fail, int** arr, int n, int m);
void overWriting(int* arr, int n, bool(*cond)(int));
bool cond(int i);
void number3();
void createBreakets();
const char* checkBreakets(const char* fail);
template <typename T1, typename T2>
void outMap(std::map<T1, T2> m)
{
	std::ofstream fout;
	fout.open("fail5.txt");
	for (auto it = m.begin(); it != m.end(); it++)
		fout << it->first << ' ' << it->second << '\n';
	fout.close();
}
std::map<std::string, int> createVoc();
bool isEntryWord(std::string file, std::string word);