#include "TDList.h"
#include "TList.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	TList<int> lst;

	lst.Add(0);
	lst.Add(1);
	lst.Add(2);
	lst.Add(3);

	cout << lst.GetAt(0) << '\t';
	cout << lst.GetAt(1) << '\t';
	cout << lst.GetAt(2) << '\t';
	cout << lst.GetAt(3) << endl << endl;

	cout << "Delete " << lst.GetAt(3) << endl << endl;

	lst.Delete(3);

	cout << lst.GetAt(0) << '\t';
	cout << lst.GetAt(1) << '\t';
	cout << lst.GetAt(2) << endl << endl;

	lst.Insert(2, 2);

	cout << lst.GetAt(0) << '\t';
	cout << lst.GetAt(1) << '\t';
	cout << lst.GetAt(2) << '\t';
	cout << lst.GetAt(3) << endl << endl;

	lst.SetAt(3, 3);

	cout << lst.GetAt(0) << '\t';
	cout << lst.GetAt(1) << '\t';
	cout << lst.GetAt(2) << '\t';
	cout << lst.GetAt(3) << endl;

	return 0;
}