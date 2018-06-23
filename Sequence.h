#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
class Sequence
{
public:
	Sequence(string filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
	



private:
	vector<char> sq;
	int numofA;
	int numofG;
	int numofC;
	int numofT;
};
#endif // !SEQUENCE_H


