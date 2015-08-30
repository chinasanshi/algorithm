#include <iostream>
#include <string>

using namespace std;

int table[100][100];
void LCS(string s1, string s2) {
	for (int i = 0; i <= s1.size(); ++i) {
		table[i][0] = 0;
	}
	for (int j = 0; j <= s2.size(); ++j) {
		table[0][j] = 0;
	}
	for (int i = 1; i <= s1.size(); ++i) {
		for (int j = 1; j <= s2.size(); ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else if (table[i - 1][j] > table[i][j - 1]) {
				table[i][j] = table[i - 1][j];
			}
			else {
				table[i][j] = table[i][j - 1];
			}
		}
	}
	cout << "LCS len is " << table[s1.size()][s2.size()] << endl;
}

void printLCS(string &s1, int i, int j) {
	if (0 == i || 0 == j) {
		return;
	}
	// 仅仅依据table[i][j]==table[i-1][j-1]+1无法判断是否存在相等的字符
	// 因为只有在table[i-1][j]和table[i][j-1]都小于table[i][j]时,才表示两个字符串的i和j位相等
	// (否则,若不存在相等的字符则table[i][j]必等于table[i-1][j]或table[i][j-1]之一);
	// 此时还有table[i][j]=table[i-1][j-1]+1,而table[i-1][j]和table[i][j-1]不会小于table[i-1][j-1],
	// 所以此时会有table[i-1][j-1]=table[i-1][j]=table[i][j-1]=table[i][j]-1;仅仅此时才表示存在相同的字符
	// 所以要先判断table[i][j]与table[i-1][j],table[i][j-1]的大小关系
	// 具体先与哪一个做比较要看当table[i-1][j]和table[i][j-1]相等时table[i][j]取的是哪个的值,就先与哪个做比较
	if (table[i][j] == table[i][j - 1]) {
		printLCS(s1, i, j - 1);
	}
	else if (table[i][j] == table[i - 1][j]) {
		printLCS(s1, i - 1, j);
	}
	else {
		printLCS(s1, i - 1, j - 1);
		cout << i << s1[i - 1] << ";";
	}
}

int main() {
	string s1, s2;
	while (1) {
		// s1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
		// s2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
		cout << "字符串s1=";
		cin >> s1;
		if ("-1" == s1) {
			break;
		}
		cout << "字符串s2=";
		cin >> s2;
		LCS(s1, s2);
		printLCS(s1, s1.size(), s2.size());
		cout << endl;
		for (int i = 0; i <= s1.size(); ++i) {
			cout << "line" << i << ":\t";
			for (int j = 0; j <= s2.size(); ++j) {
				cout << table[i][j];
				if (table[i][j] <= 9) {
					cout << "  ";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// //int table[100][100];
// void LCS(string s1, string s2, vector<vector<int> > &table, vector<vector<int> > &c) {
// 	/*for (int i = 0; i <= s1.size(); ++i) {
// 		table[i][0] = 0;
// 	}
// 	for (int j = 0; j <= s2.size(); ++j) {
// 		table[0][j] = 0;
// 	}*/
// 	for (int i = 1; i <= s1.size(); ++i) {
// 		for (int j = 1; j <= s2.size(); ++j) {
// 			if (s1[i - 1] == s2[j - 1]) {
// 				table[i][j] = table[i - 1][j - 1] + 1;
// 				c[i][j] = 0;
// 			}
// 			else
// 			{
// 				if (table[i - 1][j] > table[i][j - 1]) {
// 					table[i][j] = table[i - 1][j];
// 					c[i][j] = -1;
// 				}
// 				else {
// 					table[i][j] = table[i][j - 1];
// 					c[i][j] = 1;
// 				}
// 			}
// 		}
// 	}
// }

// void printLCS(string &s1, int i, int j, vector<vector<int> > &table, vector<vector<int> > &c) {
// 	if (0 == i || 0 == j) {
// 		return;
// 	}
// 	if (c[i][j] == 0) {
// 		printLCS(s1, i - 1, j - 1, table, c);
// 		cout <<i << " " << s1[i - 1] << ";";
// 	}
// 	if (c[i][j] == -1) {
// 		printLCS(s1, i - 1, j, table, c);
// 	}
// 	if (c[i][j] == 1) {
// 		printLCS(s1, i, j - 1, table, c);
// 	}
// }

// int main() {
// 	string s1, s2;
// 	// while (1) {
// 	s1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
// 	s2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

// 	int length1 = s1.size();
// 	int length2 = s2.size();
// 	vector<int> temp(length2 + 1, 0);
// 	vector<vector<int> > table(length1 + 1, temp);
// 	vector<vector<int> > b(table);
// 	// cout << "字符串s1=";
// 	// cin >> s1;
// 	// if ("-1" == s1) {
// 	// 	break;
// 	// }
// 	// cout << "字符串s2=";
// 	// cin >> s2;
// 	LCS(s1, s2, table, b);
// 	printLCS(s1, s1.size(), s2.size(), table, b);
// 	cout << endl;
// 	for (int i = 0; i <= s1.size(); ++i) {
// 		for (int j = 0; j <= s2.size(); ++j) {
// 			cout << table[i][j];
// 			if (table[i][j] <= 9) {
// 				cout << "  ";
// 			}
// 			else {
// 				cout << " ";
// 			}
// 		}
// 		cout << endl;
// 	}
// 	// }
// }
