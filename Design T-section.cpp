#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, Df, bf,bw, fck, fy,BM ;
	cout<<"Effective depth, d = "<<flush;
	cin>>d;
	cout<<"Depth of flange, Df = "<<flush;
	cin>>Df;
	cout<<"Width of flange, bf = "<<flush;
	cin>>bf;
	cout<<"Width of web, bw = "<<flush;
	cin>>bw;
	cout<<"fck = "<<flush;
	cin>>fck;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<"Factored BM = ";
	cin>>BM;
	cout<<endl;
	
	cout<<"step 2, Find M1 corresponding to Xu = Df"<<endl;
	cout<<"M1 = 0.36*fck*bf*Df*(d - 0.42Df)"<<endl;
	float M1 = (0.36*fck*bf*Df*(d - (0.42*Df)))/1000000;
	cout<<"M1 = 0.36"<<fck<<"*"<<bf<<"*"<<Df<<"*("<<d<<" - 0.42"<<Df<<")"<<endl;
	cout<<"M1 = "<<M1<<"KN-m"<<endl<<endl;
	
	cout<<"Step 3, Find M2 at Xu = (7/3)Df"<<endl;
	cout<<"M2 = 0.36*fck*bw*((7/3)*Df)*(d - (0.42*((7/3)*Df))) + 0.45*fck*(bf - bw)*Df*(d - (Df/2))"<<endl;	
	float M2 = (0.36*fck*bw*(((7*Df)/3))*(d - (0.42*((7*Df)/3))) + 0.45*fck*(bf - bw)*Df*(d - (Df/2)))/1000000;
	cout<<"M2 = "<<M2<<"KN-m"<<endl<<endl;
	
	cout<<"Step 4, Find Xu"<<endl;
	if(BM<M1){
		float Xu, Ast;
		cout<<" Mu = C*LA"<<endl;
		cout<<" Mu*10^6   = 0.36*fck*bf*Xu*(d - 0.42*Xu)"<<endl;
		cout<<"Xu = ";
		cin>>Xu;
		cout<<endl;
		cout<<"Find Ast"<<endl<<"C = T";
		Ast = 0.36*fck*bf*Xu/(0.87*fy);
		cout<<"0.36*fck*bf*Xu = 0.87*fy*Ast"<<endl;
		cout<<"Ast = "<<Ast<<"mm2"<<endl;
			
	}
	else if(M1<BM && BM<M2){
		float Xu, Ast;
		cout<<"Mu = C1*Z1 + C2*Z2"<<endl;
		cout<<"Mu = 0.36*fck*bw*Xu*(d - 0.42*Xu) + (0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df)*(d - (0.15*Xu + 0.65*Df)/2)"<<endl;
		cout<<"Xu = ";
		cin>>Xu;
		cout<<"Find Ast"<<endl<<"C1 +c2 = T";
		Ast = (0.36*fck*bw*Xu + (0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df)))/(0.87*fy);
		cout<<"0.36*fck*bw*Xu + 0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df) = 0.87*fy*Ast"<<endl;
		cout<<"Ast = "<<Ast<<"mm2"<<endl;
	}
	else if(BM > M2){
		float Xu,Ast;
		cout<<"Mu = C1*Z1 + C2*Z2"<<endl;
		cout<<"Mu = 0.36*fck*bw*Xu*(d - 0.42*Xu) + (0.45*fck*(bf - bw)*(Df)*(d - Df/2)"<<endl;
		cout<<"Xu = ";
		cin>>Xu;
		cout<<"Find Ast"<<endl<<"C1 +c2 = T";
		Ast = (0.36*fck*bw*Xu + (0.45*fck*(bf - bw)*(Df)))/(0.87*fy);
		cout<<"0.36*fck*bw*Xu + 0.45*fck*(bf - bw)*Df = 0.87*fy*Ast"<<endl;
		cout<<"Ast = "<<Ast<<"mm2"<<endl;
	}
	
}
	
	
