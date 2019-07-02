#include "hash.h"

int main(){
	setlocale(LC_ALL, "Russian");
	string path;
	cout << "Enter the path" << endl;
	getline(cin,path);

	int size;
	cout << "Enter the size of the table" << endl;
	cin >> size;
	HashTable table(size);
	table.form(path);
	cout << "Forming is done"<<endl;
	table.print();
	system("pause");
	return 0;
}