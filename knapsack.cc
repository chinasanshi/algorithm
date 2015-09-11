// #include <iostream>
// #include <string.h>


// using namespace std;
// // 目标：在不超过背包容量的情况下，最多能获得多少价值
// // 子问题状态:f[i][j]:表示前i件物品放入容量为j的背包得到的最大价值
// // 状态转移方程:f[i][j] = max{f[i - 1][j],f[i - 1][j - weight[i]] + value[i]}
// int knapsack(int *weight, int N, int *value, int V) {
// 	int table[N + 1][V + 1];
// 	memset(table, 0, (N + 1) * (N + 1)*sizeof(int));
// 	for (int i = 1; i <= N; ++i) {
// 		for (int j = 0; j <= V; ++j) {
// 			if (j < weight[i - 1]) {
// 				table[i][j] = table[i - 1][j];
// 			}
// 			else {
// 				if (table[i - 1][j - weight[i - 1]] + value[i - 1] > table[i - 1][j]) {
// 					table[i][j] = table[i - 1][j - weight[i - 1]] + value[i - 1];
// 				}
// 				else {
// 					table[i][j] = table[i - 1][j];
// 				}
// 			}
// 		}
// 	}
// 	return table[N][V];
// }

// int main() {
// 	int weight[] = {3, 2, 2};
// 	int value[] = {5, 10, 20};
// 	cout << knapsack(weight, 3, value, 5) << endl;
// 	return 0;
// }



#include <cstdlib>
#include <iostream>
#define M 105
#define V 10005
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, bot, top, ans = 0;
		cin >> n >> bot >> top;
		while (n--) {
			int m, c, v, dp[V] = {0};
			for (int j = 0; j <= top; j++) {
				dp[j] = -INF;
			}
			dp[0] = 0;      //装满背包

			cin >> m;
			for (int i = 0; i < m; i++) {
				cin >> c >> v;
				for (int j = top; j >= c; j--) {
					dp[j] = max(dp[j], dp[j - c] + v);
				}
			}

			for (int j = bot; j <= top; j++) {
				ans = max(ans, dp[j]);
			}

		}
		cout << ans << endl;
	}

	return 0;
}