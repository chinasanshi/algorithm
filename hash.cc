#include <iostream>

using namespace std;

class Hash {
public:
	Hash() {
		null_key = -1;
		hash_size = 12;
		hash_table = new int[hash_size];
		for (int i = 0; i < hash_size; ++i) {
			hash_table[i] = null_key;
		}

	}
	~Hash() {
		delete [] hash_table;
	}

	int getHash(int key) {
		return key % hash_size;
	}

	void insertHash(int key) {
		int dir = getHash(key);
		if (hash_table[dir] != null_key) {
			dir = (dir + 1) % hash_size;
		}
		hash_table[dir] = key;
	}

	bool searchHash(int key, int &addr) {
		addr = getHash(key);
		while (hash_table[addr] != key) {
			addr = (addr + 1) % hash_size;
			if (hash_table[addr] == null_key || addr == getHash(key)) {
				return false;
			}
		}
		return true;
	}


private:
	int* hash_table;
	int hash_size;
	int null_key;


};




int main() {
	Hash test_hash;
	test_hash.insertHash(12);
	test_hash.insertHash(67);
	test_hash.insertHash(56);
	test_hash.insertHash(16);
	test_hash.insertHash(25);
	test_hash.insertHash(37);
	test_hash.insertHash(22);
	test_hash.insertHash(29);
	test_hash.insertHash(15);
	test_hash.insertHash(47);
	test_hash.insertHash(48);
	test_hash.insertHash(34);
	int addr = -1;
	cout << test_hash.searchHash(12, addr) << " " << addr << endl;
	cout << test_hash.searchHash(67, addr) << " " << addr << endl;
	cout << test_hash.searchHash(56, addr) << " " << addr << endl;
	cout << test_hash.searchHash(16, addr) << " " << addr << endl;
	cout << test_hash.searchHash(25, addr) << " " << addr << endl;
	cout << test_hash.searchHash(37, addr) << " " << addr << endl;
	cout << test_hash.searchHash(22, addr) << " " << addr << endl;
	cout << test_hash.searchHash(29, addr) << " " << addr << endl;
	cout << test_hash.searchHash(15, addr) << " " << addr << endl;
	cout << test_hash.searchHash(47, addr) << " " << addr << endl;
	cout << test_hash.searchHash(48, addr) << " " << addr << endl;
	cout << test_hash.searchHash(34, addr) << " " << addr << endl;



	return 0;
}
