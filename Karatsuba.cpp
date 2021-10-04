#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef long long ll;
typedef long double ld;
typedef unsigned long long Ull;

#define endl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


ll maxSubArraySum(vector<ll>v, ll n) {

	ll ans = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		temp = temp + v[i];
		ans = max(ans , temp);
		if (temp <= 0) {
			temp = 0;
		}
	}
	return ans;
}

ll maxCrossingSum(vector<ll> arr, ll l, ll m, ll h)
{

	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}


	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m + 1; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}


	return max(max(left_sum + right_sum, left_sum), right_sum);
}

ll maxSubArraySum(vector <ll> arr, int l, int h)
{
	// Base Case: Only one element
	if (l == h)
		return arr[l];

	// Find middle point
	ll m = (l + h) / 2;


	return max(max(maxSubArraySum(arr, l, m),
	               maxSubArraySum(arr, m + 1, h)),
	           maxCrossingSum(arr, l, m, h));
}



vector<ll> karatsuba_multiply(vector<ll> &v1, vector<ll> &v2) {
	if (v1.size() == 1 && v2.size() == 1) {
		vector<ll> base;
		base.pb(v1[0] * v2[0]);
		return base;
	}
	if (v1.size() % 2) {
		reverse(all(v1));
		v1.pb(0);
		reverse(all(v1));
		reverse(all(v2));
		v2.pb(0);
		reverse(all(v2));
	}
	vector<ll> first_half_a, second_half_a, first_half_b, second_half_b;
	for (int i = 0; i < v1.size() / 2; i++) {
		first_half_a.pb(v1[i]);
		second_half_a.pb(v1[i + v1.size() / 2]);
		first_half_b.pb(v2[i]);
		second_half_b.pb(v2[i + v1.size() / 2]);
	}

	vector<ll> D0D1, E0E1;
	for (int i = 0; i < v1.size() / 2; i++) {
		D0D1.pb(first_half_a[i] + second_half_a[i]);
		E0E1.pb(first_half_b[i] + second_half_b[i]);
	}

	vector<ll> D1E1 = karatsuba_multiply(first_half_a, first_half_b);
	vector<ll> D0E0 = karatsuba_multiply(second_half_a, second_half_b);
	vector<ll> D0D1_E0E1 = karatsuba_multiply(D0D1, E0E1);
	for (int i = 0; i < D0D1_E0E1.size(); i++) {
		D0D1_E0E1[i] -= D1E1[i], D0D1_E0E1[i] -= D0E0[i];
	}

	vector<ll> cur_ans(2 * v1.size() - 1, 0);
	for (int i = 0; i < D0E0.size(); i++) {
		if (i < D1E1.size()) {
			cur_ans[i + v1.size()] += D1E1[i];
		}
		if (i < D0D1_E0E1.size()) {
			cur_ans[i + (v1.size() / 2)] += D0D1_E0E1[i];
		}
		cur_ans[i] += D0E0[i];
	}
	return cur_ans;
}

vector<ll> brute_multiply(vector<ll> &v1, vector<ll> &v2) {
	int n = v1.size(), m = v2.size();
	vector<ll> ans(n + m - 1, 0);
	vector<ll> a = v1, b = v2;
	reverse(all(a)), reverse(all(b));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i + j] += a[i] * b[j];
		}
	}
	return ans;
}

void solve() {
	cout << fixed << setprecision(5) << endl;
	vector<ll> a, b;
	int n = 1000;
	for (int i = 0; i < n; i++) {
		ll x = rng() % 10;
		a.pb(x);
	}
	for (int i = 0; i < n; i++) {
		ll x = rng() % 10;
		b.pb(x);
	}
	bool f = 0;
	clock_t start, end;
	start = clock();
	vector<ll> brute_ans = brute_multiply(a, b);
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	double total_time = time_taken;
	cout << "Time using brute force O(n^2) = " << total_time << endl << endl;

	start = clock();
	vector<ll> karatsuba = karatsuba_multiply(a, b);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	total_time = time_taken;

	cout << "Time using Karatsuba O(n^1.59) = " << total_time << endl << endl;
	f = 0;
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	int t = 1;
	//read(t);
	while (t--)
	{
		solve();
	}
}
