#include"Sequence.h"
#include<string.h>
#include"stdlib.h"
#define MAXCHAR 1200000
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
		//cout << v;
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
	int a[4];
	a[0] = Repeated('A').length();
	a[1] = Repeated('T').length();
	a[2] = Repeated('G').length();
	a[3] = Repeated('C').length();
	int max = a[0];
	string str[4];
	str[0] = Repeated('A');
	str[1] = Repeated('T');
	str[2] = Repeated('G');
	str[3] = Repeated('C');
	if (a[1] > max)max = a[1];
	if (a[2] > max)max = a[2];
	if (a[3] > max)max = a[3];
	for(int i=0;i<4;i++)
	cout<<endl<<a[i];
	for (int i = 0; i < 4; i++)
	{
		if (max == a[i])
		{
			return str[i];
		}
	}


}



string Sequence::Repeated(char letter)
{
	string str;
	int max = 0;
	int now = 0;
	int mark = 0;
	for (int i = 0; i<sq.size(); i++)
	{
		if (i == 0)
		{
			if (sq[i] == letter)now++;
		}

		else
		{
			if (sq[i - 1] == letter&&sq[i] == letter)
			{
				now++;
			}

			if (sq[i - 1] == letter &&sq[i] != letter)
			{
				if (now > max)
				{
					max = now;
					mark = i - 1;
				}
				now = 0;
			}
		}
	}

	for (int j = mark - max; j <= mark; j++)
	{
		str += sq[j];
	}



	return str;
}


int comlen(char *p, char *q)

{
	int len = 0;
	while (*p++ == *q++)
		++len;
	return len;

}

int pstrcmp(const void *p, const void *q)

{
	return strcmp(*(char* const *)p, *(char* const*)q);
}


string Sequence::longestRepeated()
{

		char *C = new char[MAXCHAR];
		char**A = new char*[MAXCHAR];
		ifstream fin("dna.txt", ios::in);
		if (!fin)
			cout << "have no file" << endl;
		int n = 0,index = 0,len,longestlen = 0;
		while (!fin.eof())
		{

			A[n] = &C[n];
			if (fin.peek() != '\n')
				C[n++] = fin.peek();
			
			fin.get();
		}

		C[n] = '\0';
		fin.close();
		qsort(A, n, sizeof(char*), pstrcmp);
		for (int i = 0; i<n - 1; i++)
		{
			len = comlen(A[i], A[i + 1]);
			if (len>longestlen)
			{
				longestlen = len;
				index = i;
			}
		}

		string longestrepeated = A[index];
		return longestrepeated.substr(0, longestlen);

		
}
