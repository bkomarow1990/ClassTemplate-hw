#include <iostream>
#include "Array.h"
using namespace std;
int main() {
	Array<int>one(3,5);
	one.print();
	one.add(4);
	one.add(5);
	one.add(6);
	one.add(6);
	one.add(6);
	one.print();
	one.setSize(3, 3);
	cout << "test" << endl;
	one.print();
	cout << "getAt: " << endl;
	cout<<one.getAt(2)<<endl;
	one.setAt(2, 12);
	cout<<one.getAt(2)<<endl;
	cout << "operator[]: " << endl;
	cout << one[2] << endl;
	cout << "Concat: " << endl;
	Array<int> two(3,5);
	cout << "One: " << endl;
	one.print();
	cout << "Two: " << endl;
	two.add(3);
	two.add(6);
	two.add(8);
	two.print();
	cout << "After: " << endl;
	
	one.concat(two);
	one.print();
	cout << "Operator =" << endl;
	cout << "Before:" << endl;
	one.print();
	two.print();
	cout << "After: " << endl;
	two = one;
	one.print();
	two.print();
	one.showAdressOfArray();
	two.showAdressOfArray();
	cout << "Insert at: " << endl;
	one.insertAt(3, 228);
	one.print();
	cout << "Temove at: " << endl;
	one.removeAt(3);
	one.print();
	return 0;
}