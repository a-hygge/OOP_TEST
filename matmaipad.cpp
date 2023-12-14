#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	map<char,char> m;
	char cnt = '0';
	for(int i = 1; i <= 26; i++)
	{
		m.insert({char('A' + i - 1),cnt});
		if(cnt == '9') cnt = '0';
		//cout << char('A' + i - 1) << " " << cnt << endl; 
		cnt++;
	}
	while(t--)
	{
		string s,s1, kq = "";
		cin >> s >> s1;
		int n = s1.size();
		for(int i = 0; i < n; i++)
		{
			if(!isdigit(s1[i]))
			{
				kq += m[s1[i]];
			}
		}
		cout << kq << endl;
		if(kq == s) cout << "YES\n";
		else cout << "NO\n";
	}
}
/*
3
1234 234DFAA4592
1234 234BC2DE4592
123152 35345AGDGKG

*/
