#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float D, d, b, Vu, Tu, Mu, fck, fy;
	cout<<"depth, D = "<<flush;
	cin>>D;
	cout<<"Effective depth, d = "<<flush;
	cin>>d;
	cout<<"Width of beam = "<<flush;
	cin>>b;
	cout<<"Factored shear force, Vu = ";
	cin>>Vu;
	cout<<"Torsional moment, Tu = ";
	cin>>Tu;
	cout<<"Mu = ";
	cin>>Mu;
	cout<<"fck = "<<flush;
	cin>>fck;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<endl;
	
	cout<<"Step 1 "<<endl;
	float Xulim;
	if(fy == 250){
		Xulim = 0.53*d;
		cout<<"Xulim = 0.53*d"<<" = "<<Xulim<<endl;
	} 
	else if(fy == 415){
		Xulim = 0.48*d;
		cout<<"Xulim = 0.48*d"<<" = "<<Xulim<<endl;
	}
	else if(fy == 500){
		Xulim = 0.46*d;
		cout<<"Xulim = 0.46*d"<<" = "<<Xulim<<endl;
	}
	double Mulim = 0.36*fck*b*Xulim*(d - (0.42*Xulim));
	cout<<"Mulim = 0.36*fck*b*Xulim*(d - 0.42*Xulim)"<<endl;
	cout<<"      = "<< fixed <<setprecision(2) << Mulim<<"N-mm"<<endl;
	cout<<"      = "<< fixed <<setprecision(2) << Mulim/1000000<<"KN-m"<<endl;
	
	cout<<"step 2 Equilavent moment"<<endl;
	float Mt = (Tu/1.7)*(1+(D/b));
	cout<<"Mt = (Tu/1.7)*(1+(D/b)) = "<<Mt<<endl;
	float Me1  = Mu +(Tu/1.7)*(1+(D/b));
	cout<<"Me1 = Me1  = Mu +(Tu/1.7)*(1+(D/b)) = "<<Me1<<endl<<endl;
	cout<<"step 3 Longitudnal rein"<<endl;
	if(Mu > Mt){
		cout<<"since, Mu>Mt, Bottom r/f designed"<<endl;
		float a = 1-(4.6*Me1*pow(10,6)/(fck*d*d*b));
		float Ast = ((0.5*fck*b*d)/fy)*(1-(pow(a, 0.5)));
		cout<<"Ast = ((0.5*fck*b*d)/fy)*(1-(pow(1-(4.6Me1/fck*d*d*b), 0.5)))"<<endl;
		cout<<"Ast = "<<Ast;
		cout<<"Provide ---bars and calculate n"<<endl<<endl;
		cout<<"For top r/f provide 2#10mm fi holder bars"<<endl<<endl;
		
	}
	else if(Mu<Mt){
		cout<<"since, Mu<Mt, Bottom and top r/f designed"<<endl;
		float a = 1-(4.6*Me1*pow(10,6)/(fck*d*d*b));
		float Ast = ((0.5*fck*b*d)/fy)*(1-(pow(a, 0.5)));
		cout<<"Ast = ((0.5*fck*b*d)/fy)*(1-(pow(1-(4.6Me1/fck*d*d*b), 0.5)))"<<endl;
		cout<<"Ast = "<<Ast;
		cout<<"Provide ---bars and calculate n"<<endl<<endl;
		cout<<"for top r/f"<<endl;
		float Me2 = Mt- Mu;
		cout<<"Me2 = Mt- Mu = "<<Me2<<endl;
		float Asc = Me2*pow(10,6)/(0.87*fy*(d - (D-d)));
		cout<<"Asc = Me2/(0.87*fy*(d - (D-d))) = "<<Asc<<endl;
		cout<<"Provide ---bars and calculate n"<<endl<<endl;
	}
	
	cout<<"Transverse r/f"<<endl;
	float Sv, n_s, fy_s, dia_s, Vue, Tue;
		cout<<"n_s = ";
		cin>>n_s;
		cout<<"fy_s = ";
		cin>>fy_s;
		cout<<"dia_s = ";
		cin>>dia_s;
	Vue = Vu + (1.6*Tu*1000/b);
	cout<<"Vue = Vu + (1.6*Tu*1000/b) = "<<Vue<<"Kn"<<endl;
	Tue = Vue*1000/(b*d);
	cout<<"Tue = Vue*1000/(b*d) = "<<Tue<<"N-mm"<<endl;
}
