#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct userInfo {
	string name;
	int count;
};

struct cellInfo {
	userInfo info;
	bool taken;
};

class HashTable {
private:
	const int c = 5;
	const int d = 7;
	int maxSize;
	int curSize;
	cellInfo* cell;
public:
	HashTable(int HmaxSize) {
		if (HmaxSize > 0)
			maxSize = HmaxSize;
		else maxSize = 100000;
		curSize = 0;
		cell = new cellInfo[maxSize];
		for (int i = 0; i < maxSize; ++i) cell[i].taken = false;
	}
	int hashKey(string name);
	bool hashFind(string name, userInfo &info);
	bool hashAdd(userInfo info);
	bool form(string path);
	void print();
};