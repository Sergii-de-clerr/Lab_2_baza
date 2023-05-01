#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum gender
{
	male,
	female
};

map<string, gender> persons =
{
	{"Sergii", male},
	{"Igor", male},
	{"Vlad", male},
	{"Volodimyr", male},
	{"Oleksandr", male},
	{"Oleksiy", male},
	{"Nastya", female},
	{"Tanya", female},
	{"Luda", female},
	{"Oksana", female},
	{"Daryna", female}
};

map<string, vector<string>> relationships =
{
	{"Sergii", {"Tanya", "Daryna"}},
	{"Tanya", {"Vlad", "Luda"}},
	{"Nastya", {"Sergii"}},
	{"Volodimyr", {"Oksana"}},
	{"Igor", {"Vlad", "Luda"}},
	{"Oksana", {"Oleksiy"}},
	{"Luda", {"Oleksandr", "Oksana"}}
};

void is_son(string parent, string son)
{
	if (persons[son] == female)
	{
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < relationships[parent].size(); i++)
	{
		if (relationships[parent][i] == son)
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

void is_daughter(string parent, string daughter)
{
	if (persons[daughter] == male)
	{
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < relationships[parent].size(); i++)
	{
		if (relationships[parent][i] == daughter)
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

void is_dad(string dad, string child)
{
	if (persons[dad] == female)
	{
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < relationships[dad].size(); i++)
	{
		if (relationships[dad][i] == child)
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

void is_mam(string mam, string child)
{
	if (persons[mam] == male)
	{
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < relationships[mam].size(); i++)
	{
		if (relationships[mam][i] == child)
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

void is_dencendant(string parent, string child)
{
	vector<string> parents;
	parents.push_back(parent);
	int j = 0;
	while (parents.size() > j)
	{
		for (int i = 0; i < relationships[parents[j]].size(); i++)
		{
			if (relationships[parents[j]][i] == child)
			{
				cout << "Yes" << endl;
				return;
			}
			parents.push_back(relationships[parents[j]][i]);
		}
		j++;
	}
	cout << "No" << endl;
}

int main()
{
	//is_son("Sergii", "Tanya");
	//is_son("Igor", "Vlad");
	//is_daughter("Sergii", "Tanya");
	//is_daughter("Igor", "Vlad");
	is_dencendant("Igor", "Oleksiy");
	system("pause");
}