#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float y, B, m;
	cout<<"Enter B = ";
	cin>>B;
	cout<<"Enter m = ";
	cin>>m;
	cout<<endl;
	
	
	while(true){
		cout<<"Enter y = ";
		cin>>y;
		float LHS = (y*(B + m*y))/(float)(pow(B + 2*y*pow((1 + m*m), 0.5), 0.4));
		cout<<"LHS = "<<LHS<<endl<<endl;
	}
}
