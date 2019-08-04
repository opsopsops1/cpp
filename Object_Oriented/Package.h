
#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string>
using std::string;using std::cout;using std::endl;
class Package
{
private:
	string senderName;
 	string senderCity;
 	string recipientName;
	string recipientCity;
 	double weight;
	double costPerWeight;
public:
	Package(string a, string b, string c, string d, double e, double f){
		senderName=a;senderCity=b;recipientName=c;recipientCity=d;weight=e;costPerWeight=f;
	}
	double calculateCost(){
		return weight*costPerWeight;
	}
	void print(){	//polymorphism
		cout<< "Sender:\n" << senderName << " / " << senderCity << endl;
		cout<< "Recipient:\n" << recipientName << " / " << recipientCity << endl;
		cout<< "Cost:  " << calculateCost();
	}
	double getWeight(){
		return weight;
	}
	void plus(double a){
		costPerWeight+=a;
	}
};
class TwoDayPackage : public Package
{
private:
 	double flatFee; // flat fee for two-day-delivery service
public:
	TwoDayPackage(string a, string b, string c, string d, double e, double f, double g):Package(a,b,c,d,e,f){
		flatFee = g;
	}
 	print(){
 		
 		plus((flatFee/getWeight()));
 		Package::print();
	}
};
class OvernightPackage : public Package
{
private:
 	double overnightFreePerWeight; // flat fee weight for overnight delivery
public:
 	OvernightPackage(string a, string b, string c, string d, double e, double f, double g):Package(a,b,c,d,e,f){
		overnightFreePerWeight = g;
	}
	print(){
		plus(overnightFreePerWeight);
 		Package::print();
	}
};
#endif
