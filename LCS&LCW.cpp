#include <bits/stdc++.h>
using namespace std;


/*
****************Observed output**********

--Input--

ramesh
ramus

--Output--

length of LCS : 4
LCS is : rams
Memo table
0 0 0 0 0 0
0 1 1 1 1 1
0 1 2 2 2 2
0 1 2 3 3 3
0 1 2 3 3 3
0 1 2 3 3 4
0 1 2 3 3 4
total time taken to find LCS : 0.001s


length of LCW : 3
LCW is : ram
Memo table
0 0 0 0 0 0
0 1 0 0 0 0
0 0 2 0 0 0
0 0 0 3 0 0
0 0 0 0 0 0
0 0 0 0 0 1
0 0 0 0 0 0
total time taken to find LCW : 0.001s


*/


int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	string x, y;
	cin >> x >> y;
	int a = x.length();
	int b = y.length();

	int dp[a + 1][b + 1] = {0};


	clock_t start, end;


	start = clock();
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



	cout << "length of LCS : ";
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
	cout << "LCS is : ";
	for (int i = 0; i < lcs.size(); ++i)
	{
		/* code */
		cout << lcs[i];
	}
	cout << endl;

	cout << "Memo table \n";
	for (int i = 0; i <= a; ++i)
	{
		/* code */
		for (int j = 0; j <= b; ++j)
		{
			/* code */
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "total time taken to find LCS : " << time_taken << "s" << endl;
	cout << "\n\n";

	// *********LCW ****************
	int len = 0, row, col;
	start = clock();
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (len < dp[i][j]) {
					len = dp[i][j];
					row = i;
					col = j;
				}
			}
			else
				dp[i][j] = 0;

		}
	}

	vector<char> lcw;
	while (dp[row][col] != 0) {
		lcw.push_back(x[row - 1]);
		row--;
		col--;
	}
	if (len == 0) {
		cout << "NO substring Found\n";
	}
	else {
		cout << "length of LCW : " << len << endl;
		cout << "LCW is : ";
		reverse(lcw.begin(), lcw.end());

		for (int i = 0; i < lcw.size(); ++i)
		{
			/* code */
			cout << lcw[i];
		}
		cout << endl;
		cout << "Memo table \n";
		for (int i = 0; i <= a; ++i)
		{
			/* code */
			for (int j = 0; j <= b; ++j)
			{
				/* code */
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

	}
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "total time taken to find LCW : " << time_taken << "s" << endl;

	return 0;

}



