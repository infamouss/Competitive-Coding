#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

//#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, d, dd;
		cin >> n >> m >> d >> dd;

		vector<vector<int> > v(n, vector<int>(n, 0));

		int cnt = 0;
		vector<int> ec(n, 0);
		for (int i = 0;i<n;i++) {
			int e = 0;
			for (int j = 0;j<n;j++) {
				if (j<d) {
					int nncnt = 0;
					for (int k = 0;k<n;k++) {
						if (v[k][j] == 1) {
							nncnt++;
						}
					}
					if (v[i][j] == 0 && nncnt<dd) {
						v[i][j] = 1; e++;
					}
				}
			}
			ec[i] = e;
			cnt += e;
		}

		for (int i = 0;i<n;i++) {
			for (int j = 0;j<n;j++) {
				if (v[i][j] == 0 && ec[i]<dd && cnt<m) {

					int nncnt = 0;
					for (int k = 0;k<n;k++) {
						if (v[k][j] == 1) {
							nncnt++;
						}
					}
					if (nncnt<dd) {
						v[i][j] = 1;
						ec[i] += 1;
						cnt++;
					}
				}
			}
		}

		if (cnt == m) {
			for (int i = 0;i<n;i++) {
				for (int j = 0;j<n;j++) {
					if (v[i][j] == 1) {
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
			}
		}
		else {
			cout << -1 << endl;
		}

	}
	return 0;
}



