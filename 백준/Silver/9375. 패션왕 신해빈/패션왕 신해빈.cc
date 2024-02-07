#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int result = 1;
		int n;
		map<string, int>fashion;		//	사실상 key(의상종류)만 필요로 하게 된다.
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			string s1,s2;
			cin >> s1>>s2;
			if (fashion.find(s2) != fashion.end())
				fashion[s2]++;
			else
				fashion[s2] = 1;
		}

		auto iter = fashion.begin();
		for (; iter != fashion.end(); iter++)
		{
			result *= (iter->second)+1;
		}
		cout << result - 1<<'\n';
	}
	return 0;
}