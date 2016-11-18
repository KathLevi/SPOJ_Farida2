#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//RECURSIVE
long long recurs(long long, int);

vector<long long> coins;
vector<long long> dp;

int main() {
	long long t, m, coin;
	//vector<long long> coins;
	cin >> t;	//t - number of test cases
	cin.ignore();	//dump newline character left by cin
	int C = 1;		//test case number

	while (t--) {

		cin >> m;		//number of monsters
		coins.push_back(0);
		long long M = m;
		while (M--) {
			cin >> coin;
			coins.push_back(coin);
		}
		
		int n = coins.size();
		dp.resize(n, 0);

		if (m > 0) {
			dp[1] = coins[1];
			//Print 'Case C: X'		starting with 1 NOT 0
			cout << "Case " << C << ": " << recurs(m, 2) << endl;	//prints the max to collect
		}

		else
			cout << "Case " << C << ": 0" << endl;
		
		C++;		//increment test case number

		coins.clear();		//clear coins vector
		dp.clear();
	}

	return 0;
}
long long recurs(long long i, int n) {

	if (i <= 1)
		return dp[n - 1];
	else
	{
		dp[n] = max(coins[n] + dp[n - 2], dp[n - 1]);
		recurs(i - 1, n + 1);
	}
}