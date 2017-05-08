#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;
void getSuffix( int num)
{
	map<string,int> wordMap;
	map<string, int>::iterator it;
	string filename = "EnglishWords.txt";
	ifstream fin(filename.c_str());
	string s;
	while (getline(fin, s))
	{
		int size = s.size();
		if (size < num){}
		else
		{
			string suffix = s.substr(s.size() - num, num);
			int count;
			while (getline(fin, s))
			{
				int tempsize = s.size();
				if (tempsize < num) {}
				else
				{
					if (s.substr(s.size() - num, num) == suffix)
					{
						count=count+1;
					}
				}
			}
			wordMap["suffix"] = count;
		}
	}
	it = wordMap.end();
	while (it != wordMap.end()-10)
	{
		cout << it->first << ":" << it->second << " ";
		it--;
	}
}
int main()
{
	int num;
	cout << "Input the number you want to index:";
	cin >> num;
	getSuffix(num);
	string suffix;
	cout << "Input the suffix you want to index:";
	cin >> suffix;
	if (suffix.size() == num)
	{
		string filename = "EnglishWords.txt";
		ifstream fin(filename.c_str());
		string s;
		vector <string> wordsVector;
		while (getline(fin, s))
		{
			int size = s.size();
			if (size < num) {}
			else
			{
				if (s.substr(s.size() - num, num) == suffix)
				{
					wordsVector.push_back(s);
				}
			}
		}
		int vector_size = wordsVector.size();
		cout << "Number of words for requirement is:" << vector_size << "; ";
		for (int i = vector_size - 1; i >= 0; i--)
		{
			cout << wordsVector[i] << " ";
		}
	}
	else
	{
		cout << "error" << endl;
	}
}
