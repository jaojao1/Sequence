#include<iostream>
#include"Sequence.h"
using namespace std;
int main()
{
	Sequence S("dna.txt");
	cout << endl;
	cout<<S.length()<<endl;
	cout << S.numberOf('A') << endl << S.numberOf('G') << endl << S.numberOf('T') << endl << S.numberOf('C')<<endl;
	cout<<S.longestConsecutive();
}
