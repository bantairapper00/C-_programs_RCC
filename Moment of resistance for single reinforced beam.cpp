#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, b, fck, fy, n, dia;
	cout<<"Effective depth, d = "<<flush;
	cin>>d;
	cout<<"Width of beam = "<<flush;
	cin>>b;
	cout<<"fck = "<<flush;
	cin>>fck;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<"Number of bars = "<<flush;
	cin>>n;
	cout<<"Diameter of bars = "<<flush;
	cin>>dia;
	cout<<endl;
	float Ast = (n*M_PI*pow(dia, 2))/4;
	cout<<"Area of tensile steel Ast = "<<Ast<<endl;
	float Xu = (0.87*fy*Ast)/(0.36*fck*b);
	cout<<"C = T"<<endl;
	cout<<"0.36*fck*b*Xu = 0.87*fy*Ast"<<endl;
	cout<<"Xu = "<<Xu<<endl;
	
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
	if(Xu < Xulim){
		cout<<"Since Xu < Xulim, so the section is under-reinforced"<<endl;
	}
	else if(Xu == Xulim){
		cout<<"Since Xu == Xulim, so the section is balanced"<<endl;
	}
	else if(Xu > Xulim){
		cout<<"Since Xu > Xulim, so the section is over-reinforced"<<endl;
	}
	
	if(Xu <= Xulim){
		double MOR = 0.36*fck*b*Xu*(d - (0.42*Xu));
		cout<<"Moment of resistance, Mu = C*LA"<<endl;
		cout<<"                         = 0.36*fck*b*Xu*(d - 0.42*Xu)"<<endl;
		cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
		cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;

	}
	else if(Xu > Xulim){
		cout<<"stress in steel < 0.87*fy"<<endl;
		for(int i=0;i<n;i++){
		float Xu_new;
		cout<<"Assume Xu = ";
		cin>>Xu_new;
		float Esc = ((d - Xu_new)/(Xu))*0.0035;
		cout<<"Esc = ((d - Xu)/(Xu))*0.0035 = "<<Esc<<endl;
		float fsc;
		if(fy == 250){
			if(Esc < 0.00087){
				fsc = 2*pow(10, 5)*Esc;
				cout<<"fsc = 2*10^5*Esc = "<<fsc<<endl;
			}
			else if(0.00087 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 173.9;
				cout<<"fsc = 173.9"<<endl;
			}
			
			else if(0.00087 < Esc && Esc < 0.00093){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 173.9 + (((184.8-173.9)/(0.00093-0.00087))*("<<Esc<<" - 0.00087))"<<endl;
				fsc = 173.9 + (((184.8-173.9)/(0.00093-0.00087))*(Esc - 0.00087));
				cout<<"fsc = "<<fsc<<endl;
			}
			else if(0.00093 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 184.8;
				cout<<"fsc = 184.8"<<endl;
			}
			else if(0.00093 < Esc && Esc < 0.00098){
				cout<<"From steel table - "<<endl;
				cout<<"184.8 + (((195.7-184.8)/(0.00098-0.00093))*("<<Esc<<" - 0.00093))"<<endl;
				fsc = 184.8 + (((195.7-184.8)/(0.00098-0.00093))*(Esc - 0.00093));
				cout<<"fsc = "<<fsc<<endl;
			}
			else if(0.00098 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 195.7;
				cout<<"fsc = "<<fsc<<endl;
			}
			else if(0.00098 < Esc && Esc  < 0.00104){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 195.7 + (((206.5-195.7)/(0.00104-0.00098))*("<<Esc<<" - 0.00098))"<<endl;
				fsc = 195.7 + (((206.5-195.7)/(0.00104-0.00098))*(Esc - 0.00098));
				cout<<"fsc = "<<fsc<<endl;
			}
			else if(0.00104 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 206.5;
				cout<<"fsc = "<<fsc<<endl;
			}
			else if(0.00104 < Esc && Esc  < 0.00106){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 206.5 + (((212.0-206.5)/(0.00106-0.00104))*("<<Esc<<" - 0.00104))"<<endl;
				fsc = 206.5 + (((212.0-206.5)/(0.00106-0.00104))*(Esc - 0.00104));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	else if(0.00106 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 212.0;
				cout<<"fsc = "<<fsc<<endl;
			}
		 	else if(0.00106 < Esc && Esc  < 0.00109){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 206.5 + (((212.0-206.5)/(0.00106-0.00104))*("<<Esc<<" - 0.00106))"<<endl;
				fsc = 212.0 + (((217.4-212.0)/(0.00109-0.00106))*(Esc - 0.00106));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	else if(0.00109 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 217.4;
				cout<<"fsc = "<<fsc<<endl;
			}
		 	else if(Esc > 0.00109){
				cout<<"From steel table - "<<endl;
				cout<<"since Esc > 0.00109, so fsc = 217.4"<<endl;
				fsc = 217.4;
		 	}
		}
		
		else if(fy == 415){
	
			if(Esc < 0.00144){
				fsc = 2*pow(10, 5)*Esc;
				cout<<"fsc = 2*10^5*Esc = "<<fsc<<endl;
			}
			
			else if(0.00144 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 288.7;
				cout<<"fsc = 288.7"<<endl;
			}
			
			else if(0.00144 < Esc && Esc  < 0.00163){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 288.7 + (((306.7-288.7)/(0.00163-0.00144))*("<<Esc<<" - 0.00144))"<<endl;
				fsc = 288.7 + (((306.7-288.7)/(0.00163-0.00144))*(Esc - 0.00144));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00163 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 306.7;
				cout<<"fsc = 306.7"<<endl;
			}
			
			else if(0.00163 < Esc && Esc  < 0.00192){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 306.7 + (((324.8-306.7)/(0.00192-0.00163))*("<<Esc<<" - 0.00163))"<<endl;
				fsc = 306.7 + (((324.8-306.7)/(0.00192-0.00163))*(Esc - 0.00163));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00192 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 324.8;
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00192 < Esc && Esc  < 0.00241){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 324.8 + (((342.8-324.8)/(0.00241-0.00192))*("<<Esc<<" - 0.00192))"<<endl;
				fsc = 324.8 + (((342.8-324.8)/(0.00241-0.00192))*(Esc - 0.00192));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00241 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 342.8;
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00241 < Esc && Esc  < 0.00276){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 342.8 + (((351.8-342.8)/(0.00276-0.00241))*("<<Esc<<" - 0.00241))"<<endl;
				fsc = 342.8 + (((351.8-342.8)/(0.00276-0.00241))*(Esc - 0.00241));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	
		 	else if(0.00276 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 351.8;
				cout<<"fsc = "<<fsc<<endl;
			}
			
		 	else if(0.00276 < Esc && Esc  < 0.00380){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 351.8 + (((360.9-351.8)/(0.00380-0.00276))*("<<Esc<<" - 0.00276))"<<endl;
				fsc = 351.8 + (((360.9-351.8)/(0.00380-0.00276))*(Esc - 0.00276));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	
		 	else if(0.00380 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 360.9;
				cout<<"fsc = "<<fsc<<endl;
			}
			
		 	else if(Esc > 0.00380){
				cout<<"From steel table - "<<endl;
				cout<<"since Esc > 0.00380, so fsc = 360.9"<<endl;
				fsc = 360.9;
		 	}
		}
		
		else if(fy == 500){
			
			if(Esc < 0.00174){
				fsc = 2*pow(10, 5)*Esc;
				cout<<"fsc = 2*10^5*Esc = "<<fsc<<endl;
			}
			
			else if(0.00174 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 347.8;
				cout<<"fsc = 347.8"<<endl;
			}
			
			else if(0.00174 < Esc && Esc  < 0.00195){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 347.8 + (((369.6-347.8)/(0.00195-0.00174))*("<<Esc<<" - 0.00174))"<<endl;
				fsc = 347.8 + (((369.6-347.8)/(0.00195-0.00174))*(Esc - 0.00174));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00195 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 369.6;
				cout<<"fsc = 369.6"<<endl;
			}
			
			else if(0.00195 < Esc && Esc  < 0.00226){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 369.6 + (((391.3-369.6)/(0.00226-0.00195))*("<<Esc<<" - 0.00195))"<<endl;
				fsc = 369.6 + (((391.3-369.6)/(0.00226-0.00195))*(Esc - 0.00195));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00226 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 391.3;
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00226 < Esc && Esc  < 0.00277){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 391.3 + (((413.0-391.3)/(0.00277-0.00226))*("<<Esc<<" - 0.00226))"<<endl;
				fsc = 391.3 + (((413.0-391.3)/(0.00277-0.00226))*(Esc - 0.00226));
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00277 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 413.0;
				cout<<"fsc = "<<fsc<<endl;
			}
			
			else if(0.00277 < Esc && Esc  < 0.00312){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 342.8 + (((351.8-342.8)/(0.00276-0.00241))*("<<Esc<<" - 0.00277))"<<endl;
				fsc = 413.0 + (((423.9-413.0)/(0.00312-0.00277))*(Esc - 0.00277));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	
		 	else if(0.00312 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 423.9;
				cout<<"fsc = "<<fsc<<endl;
			}
			
		 	else if(0.00312 < Esc && Esc  < 0.00417){
				cout<<"From steel table - "<<endl;
				cout<<"fsc = 423.9 + (((434.8-423.9)/(0.00417-0.00312))*("<<Esc<<" - 0.00312))"<<endl;
				fsc = 423.9 + (((434.8-423.9)/(0.00417-0.00312))*(Esc - 0.00312));
				cout<<"fsc = "<<fsc<<endl;
		 	}
		 	
		 	else if(0.00417 == Esc){
				cout<<"From steel table - "<<endl;
				fsc = 434.8;
				cout<<"fsc = "<<fsc<<endl;
			}
			
		 	else if(Esc > 0.00417){
				cout<<"From steel table - "<<endl;
				cout<<"since Esc > 0.00417, so fsc = 434.8"<<endl;
				fsc = 434.8;
		 	}
		}
		float newXu;
		cout<<"Now,"<<endl;
		cout<<"C = T"<<endl;
		cout<<"0.36*fck*b*Xu + fsc*Asc = fst*Ast"<<endl;
		newXu = (fsc*Ast)/(0.36*fck*b);
		cout<<"Xu = "<<newXu<<endl;
		
	}
	
		cout<<"Since compression failures are to be avoided, so momemt of resistace = Mulim"<<endl;
		double MOR = 0.36*fck*b*Xulim*(d - (0.42*Xulim));
		cout<<"Moment of resistance, Mu = Mulim"<<endl;
		cout<<"                         = 0.36*fck*b*Xulim*(d - 0.42*Xulim)"<<endl;
		cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
		cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
	
	}
	
	 
}
