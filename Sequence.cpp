#include"Sequence.h"
using namespace std;
Sequence::Sequence(string filename)
{
	numofA = 0;
	numofC = 0;
	numofG = 0;
	numofT = 0;
	char data;
	ifstream infile;
	infile.open(filename);
	if (!infile) cout << "error" << endl;
	while (!infile.eof())
	{
		infile.get(data);
		if (data=='A'||data=='T'||data=='G'||data=='C')
		sq.push_back(data);
	}
	for (auto v : sq)
	{
		if (v == 'A')
		{
			numofA++;
		}

		if (v == 'G')
		{
			numofG++;
		}

		if (v == 'C')
		{
			numofC++;
		}

		if (v == 'T')
		{
			numofT++;
		}
	//	cout << v;
	}

}



int Sequence::length()
{
	return sq.size();
}

int Sequence::numberOf(char base)
{
	if (base == 'A') return numofA;
	if (base == 'G')  return numofG;
	if (base == 'C')return  numofC;
	if (base == 'T') return numofT;
}


string Sequence::longestConsecutive()
{
	string str;
	int maxG=0;
	int nowG = 0;
	int mark = 0;
	for (int i=0;i<sq.size();i++)
	{
		if (i == 0)
		{
			if (sq[i] == 'G')nowG++;
		}

		else
		{
			if (sq[i - 1] == 'G'&&sq[i] == 'G')
			{
				nowG++;
			}

			if (sq[i-1]=='G'&&sq[i] != 'G')
			{
				if (nowG > maxG)
				{
					maxG = nowG;
					mark = i-1;
				}
				nowG = 0;
			}
		}
	}

	for (int j = mark - maxG; j <= mark; j++)
	{
		str += sq[j];
	}



	return str;
}
