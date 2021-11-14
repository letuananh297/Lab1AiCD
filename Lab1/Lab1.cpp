#include<iostream>
#include<fstream>
#include <iomanip>
#include"List.h"
using namespace std;

int main() {
	List list1, list2;

	//list1: 2 4 6 8 10 12 14 16 18
	for (int i = 1; i < 10; i++)
		list1.push_back(2 * i);
	cout << "The first list: " << list1 << endl;
	cout << "Size of the first list: " << list1.get_size() << endl << endl;

	//list2: 8 10 12 14
	for (int i = 14; i > 6; i = i - 2)
		list2.push_front(i);
	cout << "The second list: " << list2 << endl;
	cout << "Size of the second list: " << list2.get_size() << endl << endl;

	cout << "The second element of the first list is: " << list1.at(2) << endl;
	cout << "The last element of the second list is: " << list2.at(list2.get_size()) << endl << endl;

	//Checking for the contents of the second list in the first list 
	if (list1.contains(list2))
		cout << "The content of second list is in the first list.\n";
	else
		cout << "The content of second list is not in the first list.\n";

	list1.pop_back();
	cout << "\nThe first list after removing the last element: "<< list1 << endl;

	list1.pop_front();
	cout << "\nThe first list after removing the first element: " << list1 << endl;

	list1.insert(7, 2);
	cout << "\nThe first list after adding element 7 by index 2: " << list1 << endl;

	list1.remove(4);
	cout << "\nThe first list after removing the fourth element: " << list1 << endl;

	list1.set(5, 6);
	cout << "\nThe first list after replacing the fifth element by 6: " << list1 << endl;

	//Removing all elements of the second list
	list2.clear();

	//Checking if the lists is empty
	if (list1.isEmpty())
		cout << "\nThe first list is empty.\n";
	else
		cout << "\nThe first list is not empty.\n";

	if (list2.isEmpty())
		cout << "\nThe second list is empty.\n";
	else
		cout << "\nThe second list is not empty.\n";

	return 0;
}