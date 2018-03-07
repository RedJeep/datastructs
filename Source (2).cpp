/*
Jeffrey Garip
CS2134

Hash_map class;



*/



#include<iostream>
#include<vector>
using namespace std;


template<class T>
class HashF
{
public:

	size_t operator()(T& key,int size) 
	{
		return key %size;
	}


};
template<class T>
class Notequals {
public:
	bool operator()(T&key,T&key1)
	{
		return(key != key1);
	}



};

typedef HashF<int> hasher;
typedef Notequals<int> comp;

template<class T, class S, class pred, class pred2>
class HashMap {
public:
	HashMap(S item, pred& val, pred2& val2) : hash1(val), Notequal(val2) { map.reserve(100); map.resize(100); }
	void insert( T &key ,S& val);
	void remove(T&key);
	void makeEmpty() { map.clear(); }
	int getcap()const { return map.capacity();}
	int getSize() const { return map.size(); }
	bool findkey(T key) 
	{
		bool flag = true;
		for (int i = 0; i < map.size(); i++) {
			if (key != map[key]->key)
				flag = false;
		}

		return key;

	}
	
	class Node;
	Node* operator[](T key) {
		size_t ndx = hash1(key, map.size());
		if (map[ndx] == nullptr)
		{
			map[ndx] = new Node(key, 0);
			return map[ndx];
		}
		else {
			return map[ndx];
		}

	}



private:
	
	pred hash1;
	pred2 Notequal;
	
	class Node {
	public:
		Node(T& key, S& data) : key(key), data(data), next(nullptr) {}

		T key;
		S data;
		Node*next;

};
	vector<Node*> map;
};
template<class T, class S, class pred, class pred2>
void HashMap<T, S,pred,pred2>::insert(T&  key, S& val)
{
	Node*first = new Node(key, val);
	size_t pos = hash1(key,getcap());
	if (map[pos] == nullptr)
	{
		map[pos] = first;

	}

	else {
		bool flag = true;
		Node*temp = map[pos];
		while (temp->next != nullptr) {
			if (!Notequal(temp->key, first->key)) 
			{
				flag = false;
				break;
			}

			temp = temp->next;
		}

		if (flag) {
			temp->next = first;
		}


	}
}

	



	

template<class T, class S, class pred, class pred2>
void HashMap<T, S,pred,pred2>::remove(T & key)
{

	size_t pos = hash1(key,getcap());
	Node* temp = map[pos];
	if (map[pos] == nullptr) return;
	if (!Notequal(temp->key, key) && map[pos]->next != nullptr)
	{
		map[pos] = map[pos]->next->next;
		delete temp;
		return;
	}
	else if (!Notequal(temp->key, key)) {
		map[pos] = nullptr;
		delete temp;
		return;
	}
	
	while (temp->next != nullptr) 
	{
		if (!Notequal(temp->next->key,key)) 
		{
			Node*firstNode = temp->next;
			temp->next = temp->next->next;
			delete firstNode;


		}
		temp = temp->next;

		
	}

}



int main()
{
	HashMap<int, int, hasher, comp> map1(42, hasher(), comp());
	int key;
	int val;
	int count;
	int keytoremove;
	cout << " how many item do you want to add?: " << endl;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cout << " please enter a key " << endl;
		cin >> key;
		cout << "please enter a value " << endl;
		cin >> val;

		map1.insert(key, val);
	}

	cout << " please enter a key to remove " << endl;
	cin >> keytoremove;
	 
	bool exist=map1.findkey(keytoremove);
	if (exist) {
		map1.remove(keytoremove);
	}
	else {
		cout << " Item dont exist pal";
	}





}


	



