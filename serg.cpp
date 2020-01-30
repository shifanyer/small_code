#include <bits/stdc++.h>

using namespace std;

long int l, a, b, ab[15], c[15], d[15], n, m, p[1005][1005], res, tmp;
vector <long int> ans;

void findAns(long int k, long int s)
{
	//cout << "*" << k << "\n";
	//cout << "op|" << p[k][s] << "\n";
	if (p[k][s] == 0 )
	{
		return ;
	}
	//cout << "op$" << p[k][s] << "\n";
	
	if (p[k-1][s] == p[k][s])
	{
		//cout << "1\n";
		findAns(k - 1, s);
	}
	else
	{
		//cout << "2\n";
		findAns(k-1, s-c[k]);
		ans.push_back(k);
	}
}

int main()
{
	//freopen("multimap.txt", "w", stdout);

	cin >> n >> m >> c[1] >> d[1];
	
	ab[1]=100000;
	m++;
	n++;
	for (int i=2; i<=m; i++)
	{
		cin >> a >> b;
		ab[i]=a/b;
		cin >> c[i] >> d[i];
	}
		
	//cout << "*\n";
	
	for (int j=0; j<=n; j++)
		p[0][j]=0;
	//cout << "*\n";
	
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<n; j++)
		{
			//cout << "#" << p[i-1][j] <<"&\n";
			tmp=p[i-1][j];
			p[i][j]=tmp;
			l = min(ab[i], j/c[i]);
			//cout << l << "\n";
			for (int q=l; q>=0; q--)
			{
				tmp=p[i-1][j - q * c[i]];
				tmp+= d[i] * q;
				if (tmp>p[i][j])
				{
					p[i][j]=tmp;
				}
				//cout << p[i-1][j] << " "<< p[i][j] << " "<<  p[i-1][j - q * c[i]]  << " "<< d[i] * q << "\n";
			}
			//cout << "\n*\n" << i << "*" << j << "\n*\n";
		}
	}
	//cout << "#\n";
	//cout << "/|" << p[m][n] << "\n";
	//findAns(m, n);
	//cout << "Y";
	cout << p[m][n-1] << "\n";
	
	/*
	
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i=0; i<ans.size(); i++)
	{
		res+=ans[i]*d[i];
		cout << ans[i] << " ";
	}
	cout << "\n";
	cout << res << "\n";
	*/
}
