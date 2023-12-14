#include <bits/stdc++.h>

using namespace std;

class sotay
{
public:
	string hoten, sdt, ngay, dem, ten;
public:
	sotay()
	{
		hoten = "";
		sdt = "";
		ngay = "";
		ten = "";
		dem = "";
	}
	void nhap(ifstream& inp)
	{
		getline(inp, hoten);getline(inp, sdt);
		
	}
	bool operator < (const sotay other)
	{
		if(other.ten == ten)
		{
			return dem < other.dem;
		}
		return ten < other.ten;
	}
};
int main()
{
	ifstream inp("SOTAY.txt");
	ofstream out("DIENTHOAI.txt");
	/*if (!inp)
    {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    if (!out)
    {
        cout << "Failed to open output file." << endl;
        return 1;
    }*/
	string s;
	int cnt = 0;
	sotay a[1000];
	while(getline(inp,s))
	{
		string tmp = s.substr(0,4);
		//out << tmp << endl;
		if(tmp == "Ngay")
		{
			a[cnt].ngay = s.substr(5,10);
			a[cnt].nhap(inp);
		}
		else
		{
			a[cnt].ngay = a[cnt - 1].ngay;
			a[cnt].hoten = s;
			getline(inp,a[cnt].sdt);
		}
		stringstream ss(a[cnt].hoten);
		vector<string> ans;
		string s;
		while(ss >> s)
		{
			ans.push_back(s);
		}
		a[cnt].ten = ans[ans.size() - 1];
		a[cnt].dem = ans[ans.size() - 2];
		cnt++;
	}
	sort(a, a + cnt);
	for(int i = 0; i < cnt; i++)
	{
		out << a[i].hoten << ": " << a[i].sdt << " " << a[i].ngay << endl;
	}
}
