/*
Student: Jeffrey Garip(Jeff)
class: CS 2134
HW3
Fun assignment,made me sweat at times.

*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Flight {
public:
		
		int fnum, landtime;
		string  departure, landing;
		friend ostream& operator<<(ostream&os, const Flight&rhs);
		

};
class equalbyDeparture
{
public:
	bool operator()(Flight&plane, const string&depart) {
		return(plane.departure == depart);
	}
};

class equalbyDestination
{
public:
	bool operator()(Flight&plane, const string&Terminal)
	{
		return (plane.landing == Terminal);

	}


};



void storeData(ifstream& fdata, vector<Flight>& fstatus)
{
	int flightnum, time;
	string depart, arrival;
		
	Flight plane;
	while (fdata >> flightnum >> depart >> arrival >> time) 
	{
	
		plane.fnum = flightnum;
		plane.departure = depart;
		plane.landing = arrival;
		plane.landtime = time;
		fstatus.push_back(plane);
	}

	

	


}


template<class object,class T>
vector<object>myFind(vector<object>&airport, object token, T comparator)
{
	
	vector<object>retval;
	for (object plane : airport)
		if (plane.departure==token.departure)
			retval.push_back(plane);
	return retval;
}

template <class comp>
void outdegree(vector<Flight>&airport) 
{
	
	vector<vector<Flight>>planeStatus;
	for (int i = 0; i<airport.size(); i++) 
	{
		
		planeStatus.push_back(myFind(airport, airport[i], equalbyDeparture()));
		
	}
	string citydepart = " ";
	int max = 0;
	for (int i = 0; i<planeStatus.size(); i++)
	{
	
		if (planeStatus[i].size() > max) {
			max = planeStatus[i].size();
			citydepart = planeStatus[i][0].departure;
		}

	
	}

	cout << " departure city : " << citydepart << "  number of outgoing planes: " << max;
	







}


void displayFlightStatus(const vector<Flight>&PlaneData) 
{

	for (int i = 0; i < PlaneData.size(); i++)
		cout << PlaneData[i]<< endl;





}







int main() 
{
	ifstream data("HW3Data.txt");
	if (!data)cout << "I can't open " << endl;
	vector<Flight> airport;
	storeData(data, airport);
	Flight Delta;
	Delta.departure = "KJFK";
	equalbyDeparture DStatus;
	//cout<< DStatus(Delta, "KLAX");
	Delta.landing = "KLGK";
	equalbyDestination AStatus;
	AStatus(Delta, "KJFK");
	//cout<< myFind(airport, Delta, equalbyDestination()).size();
	outdegree<Flight>(airport);
	cout << endl;







}


ostream & operator<<(ostream & os, const Flight & rhs)
{
	os << rhs.fnum <<" "<< rhs.departure <<" "<< rhs.landing <<" "<< rhs.landtime << endl;
	return os;
}




