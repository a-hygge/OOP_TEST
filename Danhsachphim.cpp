#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string,string> mm;
class theloai
{
public:
	string mtl, ten;
public:
	theloai()
	{
		mtl = "TL";
		ten = "";
	}
	void nhap()
	{
		scanf("\n");
		getline(cin,ten);
	}
};
class bophim
{
public:
	string mp, ten, date, tl, d, m, y;
	int sotap;
public:
	bophim()
	{
		mp = "P";
		ten = "";
		date = "";
		tl = "";
		sotap = 0;
	}
	void nhap()
	{
		scanf("\n");
		getline(cin,tl);
		getline(cin,date);
		stringstream ss(date);
		getline(ss,d,'/');
		getline(ss,m,'/');
		getline(ss,y,'/');
		getline(cin,ten);
		cin >> sotap;
	}
	bool operator < (const bophim other)
	{
		if(other.date != date)
		{
			if(y == other.y)
			{
				if(m == other.m) return d < other.d;
				else return m < other.m;
			}
			return y < other.y;
		}
		else if(other.ten != ten) return ten < other.ten;
		return other.sotap < sotap; 
	}
};
signed main()
{
	int n, m;
	cin >> n >> m;
	theloai a[n];
	bophim b[m];
	string tmp = "";
	for(int i = 0; i < n; i++)
	{
		tmp = to_string(i + 1);
		while(tmp.size() < 3) tmp = '0' + tmp;
		a[i].mtl += tmp;
		a[i].nhap();
		mm.insert({a[i].mtl,a[i].ten});
	}
	for(int i = 0; i < m; i++)
	{
		tmp = to_string(i + 1);
		while(tmp.size() < 3) tmp = '0' + tmp;
		b[i].mp += tmp;
		b[i].nhap();
	}
	sort(b,b + m);
	for(int i = 0; i < m; i++)
	{
		cout << b[i].mp << " " << mm[b[i].tl] << " " << b[i].date << " " << b[i].ten << " " << b[i].sotap << endl;
	}
}
