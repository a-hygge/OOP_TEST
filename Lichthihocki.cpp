#include <bits/stdc++.h>

using namespace std;
map<string, string> mp;
class monhoc
{
public:
	string mmh, ten;
public:
	void nhap()
	{
		getline(cin,mmh);
		getline(cin,ten);
		mp.insert({mmh,ten});
	}
};
class lichthi
{
public:
	string mct, mmh, ngay, gio, nhom, d, m, y;
public:
	lichthi()
	{
		mct = "T";
		mmh = "";
		ngay = "";
		gio = "";
		nhom = "";
		d = ""; m = ""; y = "";
	}
	void nhap()
	{
		cin >> mmh >> ngay >> gio >> nhom;
		stringstream ss(ngay);
		getline(ss,d,'/');
		getline(ss,m,'/');
		getline(ss,y,'/');
	}
	bool operator < (const lichthi other)
	{
		if(ngay == other.ngay)
		{
			if(gio == other.gio)
			{
				return mmh < other.mmh;
			}
			else return gio < other.gio;
		}
		else
		{
			if(y == other.y)
			{
				if(m == other.m) return d < other.d;
				else return m < other.m;
			}
		}
		return y < other.y;
	}
};
int main()
{
	int n, m;
	cin >> n >> m;
	scanf("\n");
	monhoc a[n];
	for(int i = 0; i < n; i++)
	{
		a[i].nhap();
	}
	lichthi b[m];
	for(int i = 0; i < m; i++)
	{
		string tmp = to_string(i + 1);
		while(tmp.size() < 3) tmp = '0' + tmp;
		b[i].mct += tmp;
		b[i].nhap();
	}
	sort(b,b+m);
	for(int i = 0; i < m; i++)
	{
		cout << b[i].mct << " " << b[i].mmh << " " << mp[b[i].mmh] << " " << b[i].ngay << " " << b[i].gio << " " << b[i].nhom << endl;
	}
}
/*
2 10
INT1155
Tin hoc co so 2
INT1339
Ngon ngu lap trinh C++
INT1155 25/11/2021 08:00 01
INT1155 04/12/2021 08:00 02
INT1155 04/12/2021 13:30 03
INT1155 25/11/2021 13:30 04
INT1155 25/11/2021 15:00 05
INT1339 25/11/2021 08:00 01
INT1339 25/11/2021 08:00 02
INT1339 04/12/2021 13:30 03
INT1339 04/12/2021 13:30 04
INT1339 04/12/2021 15:00 05
*/
