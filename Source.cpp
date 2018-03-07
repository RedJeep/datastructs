
#include<iostream>
#include<map>
#include<vector>
#include<fstream>
using namespace std;

/*
Jeffrey Garip
Hw problem 3
map pratice 
*/




void readIntoMap(ifstream& file, map<int, double>& items)
{
	int key;
	double value;
	while (file >> key >> value)
		items[key] = value;

		std::cout <<" size: "<< items.size() << endl;

}


double  shoping(std::map<int, double>&items, vector<double>cart)
{
	int item;
	int key;
	int num;
	double price;
	vector<int>Map_keys;
	
	for (auto const& key : items) {
		Map_keys.push_back(key.first);
	//get keys 
	}
	cout << " We carry items - "<<endl;
	// display what we sell by printing keys from map;
	for (auto i : Map_keys) {
		cout << i << endl;
	}


	cout << " how many items are you going to buy: " << endl;
	int count = 0;
	cin >> num;
	while (num > count) {
		cout << " Please Select an item to add to the cart: " << endl;
		cin >> key;
		if (key != 1 && key != 99 && key != 47 && key != 22) {
			cout << " sorry we dont carry that item!" << endl;
			break;
		}
		price = items[key];
		cart.push_back(price);
		cout << " the shoping cart has " << cart.size() << " items ";
		
		++count;
	}

	double total = 0;
	
	for (size_t i = 0; i < cart.size(); i++)
		total += cart[i];
	
	cout << " your total owed is : " <<total << endl;

	return total;





}















int main() 
{
	ifstream file("HW1data.txt");
	if (!file) {
		cerr << " cant open file\n", exit(3);
	}
	
	vector<double>cart;
	map<int, double>box;
	readIntoMap(file, box);
	shoping(box, cart);
	




}