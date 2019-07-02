#include "hash.h"

int HashTable::hashKey(string name) {
	int k = 0;
	for (int i = 0; i < name.length(); ++i) {
		k = (k*unsigned(name[i]) + unsigned(name[i])) % maxSize;
	}
	return k;
}

bool HashTable::hashFind(string name, userInfo &info) {
	int i = hashKey(name);
	if (!cell[i].taken) return 0;
	else {
		while (cell[i].taken&&cell[i].info.name != name)
			i = (i + c + d * d) % maxSize;
		if (cell[i].taken) {
			info = cell[i].info;
			return 1;
		}
		return 0;
	}
}

bool HashTable::hashAdd(userInfo info) {
	userInfo inf;
	int i;
	if (curSize == maxSize || hashFind(info.name, inf)) return 0;
	else {
		int i = hashKey(info.name);
		while (cell[i].taken) i = (i + c + d * d) % maxSize;
		cell[i].taken = true;
		cell[i].info = info;
		curSize++;
		return 1;
	}
}

bool HashTable::form(string path) {
	ifstream base(path);
	if (!base) {
		cout << "Can't find file with that name. Try again.\n";
		return 0;
	}
	else {
		userInfo newel;
		newel.count = 0;
		int i = 0;
		while (getline(base, newel.name)) {
			hashAdd(newel);
			cout << i++ << " ";}
		base.close();
		return 1;
	}
}

void HashTable::print() {
	cout << endl <<
		"   Hash Table   " << endl;
	for (int i = 0; i < maxSize; ++i)
		if (cell[i].taken)
			cout << i << " " << cell[i].info.name << " " << cell[i].info.count << endl;
	cout << "-----------" << endl;
}