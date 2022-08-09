#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, b, Vu, fck, fy, n, dia;
	cout<<"Effective depth, d = "<<flush;
	cin>>d;
	cout<<"Width of beam = "<<flush;
	cin>>b;
	cout<<"Factored shear force, Vu = ";
	cin>>Vu;
	cout<<"fck = "<<flush;
	cin>>fck;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<"Number of bars = "<<flush;
	cin>>n;
	cout<<"Diameter of bars = "<<flush;
	cin>>dia;
	cout<<endl;
	cout<<"1. Calculate the nominal shear stress"<<endl;
	cout<<"Vu = "<<Vu<<endl;
	float Tv;
	cout<<"Tv = Vu/(b*d)"<<endl;
	Tv = Vu*1000/(b*d);
	cout<<"Tv = "<<Vu<<"*10^3/("<<b<<"*"<<d<<")"<<endl;
	cout<<"Tv = "<<Tv<<"N/mm2"<<endl;
	float Tcmax = 0.62*pow(fck, 0.5);
	cout<<"Tcmax = 0.62*root(fck)"<<" = 0.62*root"<<fck<<" = "<<Tcmax<<"N/mm2"<<endl;
	if(Tv<Tcmax){
		cout<<"Tv < Tcmax, So ok"<<endl;
	}
	cout<<endl;
	cout<<"2. Shear resisted by concrete, Tc"<<endl;
	float Pt, Tc;
	Pt = (((n*M_PI*pow(dia, 2))/4)*100)/(b*d);
	cout<<"Pt = Ast*100/(b*d)"<<endl;
	cout<<"Pt = "<<n<<"*Pi/4*"<<dia<<"^2/("<<b<<"*"<<d<<")"<<endl;
	cout<<"Pt = "<<Pt<<endl;
	cout<<"Find Tc from table 19 page 73 for fck = "<<fck<<"and Pt = "<<Pt<<endl;
	cout<<"Tc = ";
	cin>>Tc;
	if(Tv<=Tc){
		cout<<"Tv < Tc"<<"So As per IS456 - 2000, minimum shear reinforcement will be provided"<<endl;
		float Sv, n_s, fy_s, dia_s ;
		cout<<"n_s = ";
		cin>>n_s;
		cout<<"fy_s = ";
		cin>>fy_s;
		cout<<"dia_s = ";
		cin>>dia_s;
		cout<<"Maximum spacing, Sv<=(0.87*fy*Asv)/(0.4*b) = "<<"0.87*"<<fy_s<<"*"<<n_s<<"(pi/4)*"<<dia_s<<"^2"<<"/0.4*"<<b<<" = "<<((0.87*fy_s*n_s*M_PI*pow(dia_s, 2))/4)/(0.4*b)<<endl;
		cout<<"                 Sv<=0.75*d"<<0.75*d<<endl;
		cout<<"                 Sv<=300mm"<<endl;
		float a = ((0.87*fy_s*n_s*M_PI*pow(dia_s, 2))/4)/(0.4*b);
		float b = 0.75*d;
		float c = 300;
		cout<<"Sv = min("<<a<<", "<<b<<", 300)"<<endl;
		cout<<"Sv = "<<min(a, min(b, c))<<endl;
		cout<<"Provide --- ---------- at "<<Sv<<endl;

	}
	else if(Tv > Tc){
		cout<<"Tv > Tc"<<"So As per IS456 - 2000, Provide shear reinforcement"<<endl;
		
		float Sv, n_s, fy_s, dia_s, Vus;
		cout<<"n_s = ";
		cin>>n_s;
		cout<<"fy_s = ";
		cin>>fy_s;
		cout<<"dia_s = ";
		cin>>dia_s;
		Vus = (Tv - Tc)*b*d;
		cout<<"Shear resisted by shear r/f, Vus = (Tv - Tc)*b*d"<<" = "<<Vus<<endl;
		cout<<"Sv = (0.87*fy*Asv*d)/Vus"<<endl;
		cout<<"Sv = "<<"0.87*"<<fy_s<<"*"<<n_s<<"(pi/4)*"<<dia_s<<"^2*"<<d<<"/"<<Vus<<endl;
		cout<<"Sv = "<<(0.87*fy*((n_s*M_PI*pow(dia_s, 2))/4)*d)/Vus<<endl;
		cout<<"Minimum criteria, Sv<=(0.87*fy*Asv)/(0.4*b) = "<<"0.87*"<<fy_s<<"*"<<n_s<<"(pi/4)*"<<dia_s<<"^2"<<"/0.4*"<<b<<" = "<<((0.87*fy_s*n_s*M_PI*pow(dia_s, 2))/4)/(0.4*b)<<endl;
		cout<<"                 Sv<=0.75*d = "<<0.75*d<<endl;
		cout<<"                 Sv<=300mm"<<endl;
		float a = ((0.87*fy_s*n_s*M_PI*pow(dia_s, 2))/4)/(0.4*b);
		float b = 0.75*d;
		float c = 300;
		float e = (0.87*fy*((n_s*M_PI*pow(dia_s, 2))/4)*d)/Vus;
		cout<<"Sv = min("<<a<<", "<<b<<", "<<e<<", 300)"<<endl;
		cout<<"Sv = "<<min(a, min(b, min(c, e)))<<"mm"<<endl;
		cout<<"Provide --- ---------- at "<<Sv<<endl;
	}
	
	
	
	

}
