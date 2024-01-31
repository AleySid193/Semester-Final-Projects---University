#include <iostream>
#include <string>
#include<fstream>
using namespace std;
//////class package
//////{
//////	string name;
//////	string city;
//////	string state;
//////	double cost;
//////	int zipcode;
//////	int weight;
//////	int pperweight;
//////public:
//////
//////	package()
//////				string a ,string b ,string c ,int d,int w,int num)
//////	{
//////					name=a;
//////					city=b;
//////					state=c;
//////					zipcode=d;
//////					weight=w;
//////					pperweight=num; 
//////	}
//////	void setpackage()
//////	{
//////		cout << "enter the name  city state and zip code respectively " << endl;
//////		cin >> name >> city >> state >> zipcode;
//////		cout << "enter the weight per ounce and price " << endl;
//////		cin >> weight >> pperweight;
//////
//////
//////	}
//////	double  calculatecost()
//////	{
//////		double cost;
//////		return  (pperweight * weight);
//////		return cost;
//////	}
//////
//////};
//////class twodaypackage :public package
//////{
//////	int fee;
//////	double cost2;
//////public:
//////	twodaypackage()
//////					int f,string a,string b,string c,int d,int w,int num):package(a,b,c,d,w,num)
//////	{
//////					fee=f;
//////	}
//////	double settwodaypackage()
//////	{
//////		cout << "enter the delivery charges " << endl;
//////		cin >> fee;
//////	}
//////	int getfee()
//////	{
//////		return fee;
//////	}
//////
//////
//////	double  calculatecost1()
//////	{
//////		calculatecost();
//////		double cost2;
//////		cost2 = getfee() + calculatecost();
//////		return cost2;
//////	}
//////
//////
//////};
//////class overnightpackage :public package
//////{
//////	int overnight;
//////public:
//////	overnightpackage()
//////					int o,string a,string b,string c,int d,int w,int num):package(a,b,c,d,w,num)
//////	{
//////					overnight=o;
//////	}
//////	void setovernight()
//////	{
//////		cout << "enter the overnight delivery charges " << endl;
//////		cin >> overnight;
//////	}
//////	void setovernightpackage()
//////	{
//////		cout << "enter the overnight charges " << endl;
//////		cin >> overnight;
//////	}
//////
//////	double calculatecost2()
//////	{
//////		double cost3;
//////		cost3 = overnight + calculatecost();
//////		return cost3;
//////	}
//////};
//////int main()
//////{
//////	package obj;
//////		("abc","abc","abc",1,1,1);
//////	obj.setpackage();
//////	obj.calculatecost();
//////	cout << "the basic price is " << obj.calculatecost() << endl;
//////	twodaypackage obj1;
//////		(1,"abc","abc","abc",1,1,1);
//////	obj1.settwodaypackage();
//////	obj1.getfee();
//////	cout << "the price after delivery fee is " << endl << obj1.calculatecost1();
//////	overnightpackage obj2;
//////		(2,"abc","abc","abc",1,1,1);
//////	obj2.setovernight();
//////	cout << "the prices with charges are " << endl << obj2.calculatecost2();
//////
//////
//////	return 0;
//////}
//////
//////
//////
