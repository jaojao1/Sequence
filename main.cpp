#include<iostream>
#include<string>
#include<vector>
#include"Sequence.h"
using namespace std;
int main()
{
	Sequence S("dna.txt");
	cout << endl;
	cout<<S.length()<<endl;
	cout << S.numberOf('A') << endl << S.numberOf('G') << endl << S.numberOf('T') << endl << S.numberOf('C');
	string str2;
	cout << S.longestConsecutive()<<endl;
	cout<<S.longestRepeated();
	
}
