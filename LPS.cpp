#include <bits/stdc++.h>
using namespace std;


/*
****************Observed output**********

--Input--

theracecars

--Output--

length of LPS : 7
LPS is : racecar
total time taken to find LPS : 0s


*/



int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	string x, y;
	cin >> x;
	y = x;
	clock_t start, end;
	start = clock();
	reverse(y.begin(), y.end());

	int a = x.length();
	int b = y.length();

	int dp[a + 1][b + 1] = {0};


	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}


	cout << "length of LPS : ";
	cout << dp[a][b] << endl;
	vector<char> lcs;
	int m = a, n = b;
	while (true) {
		if (m <= 0 || n <= 0)
			break;
		if (x[m - 1] == y[n - 1]) {
			lcs.push_back(x[m - 1]);
			m--;
			n--;
		}
		else if (dp[m - 1][n] > dp[m][n - 1])
			m--;
		else
			n--;
	}


	reverse(lcs.begin(), lcs.end());
	cout << "LPS is : ";
	for (int i = 0; i < lcs.size(); ++i)
	{
		/* code */
		cout << lcs[i];
	}
	cout << endl;
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "total time taken to find LPS : " << time_taken << "s" << endl;

	return 0;

}



