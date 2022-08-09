#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, b, fck, fy, d_dash, BM;
	cout<<"Effective depth, d = "<<flush;
	cin>>d;
	cout<<"d' = "<<flush;
	cin>>d_dash;
	cout<<"Width of beam = "<<flush;
	cin>>b;
	cout<<"fck = "<<flush;
	cin>>fck;
	cout<<"fy = "<<flush;
	cin>>fy;
	cout<<"Factored BM = "<<flush;
	cin>>BM;
	cout<<endl;
	
	cout<<"Step 3, Limiting moment of resistance"<<endl;
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
	Mulim = Mulim/1000000;
		if(BM > Mulim){
			cout<<"UBM > Mulim, so we go for doubly reinforced section"<<endl;
			cout<<"Step 4, Calculate Ast1 for singly reinforced section"<<endl;
			float Ast1 = (Mulim*1000000)/(0.87*fy*(d-(0.42*Xulim)));
			cout<<"Mulim= 0.87*fy*Ast1*(d - 0.42*Xulim)"<<endl;
			cout<<"Ast1 = "<<Mulim<<"*10^6/(0.87*"<<fy<<"*("<<d<<" - 0.42*"<<Xulim<<")"<<endl;
			cout<<"Ast1 = "<<Ast1<<"mm"<<endl<<endl;
			
			cout<<"Step 4, For remaining moment"<<endl;
			float MR = (BM - Mulim);
			cout<<"Moment(remaining) = (BM - Mulim)"<<endl;
			cout<<"MR = "<<BM<<" - "<<Mulim<<endl;
			cout<<"MR = "<<MR<<endl<<endl;
			
			cout<<"For Ast2"<<endl;
			float Ast2 = MR*pow(10, 6)/(0.87*fy*(d-d_dash));
			cout<<"MR = 0.87*10^6*fy*Ast*(d-d_dash)"<<endl;
			cout<<"Ast2 = "<<MR<<"10^6/(0.87*"<<fy<<"*("<<d<<"-"<<d_dash<<"))"<<endl;
			cout<<"Ast2 = "<<Ast2<<endl<<endl;
			
			cout<<"And for Asc"<<endl;
			cout<<"C = T"<<endl<<"Asc*fsc = 0.87*fy*Ast2"<<endl;
			cout<<"We have to find fsc"<<endl;
			
		float Esc = ((Xulim - d_dash)/(Xulim))*0.0035;
		cout<<"Esc = ((Xulim - d')/(Xulim))*0.0035 = "<<fixed<<setprecision(6)<<Esc<<endl;
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
				cout<<"fsc = 173.9 + (((184.8-173.9)/(0.00093-0.00087))*("<<fixed<<setprecision(6)<<Esc<<" - 0.00087))"<<endl;
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
		cout<<"Now"<<endl<<"Asc*fsc = 0.87*fy*Ast2"<<endl;
		float Asc = 0.87*fy*Ast2/fsc;
		cout<<"Asc = 0.87*"<<fy<<"*"<<Ast2<<"/"<<fsc<<endl;
		cout<<"Asc = "<<Asc<<endl;
		
		cout<<endl<<"Reinforcement"<<endl;
		cout<<"for Tension"<<endl;
		float fi_t, Ast_p, Ast;
		Ast = Ast1 + Ast2;
		cout<<"Ast = "<<Ast1<<"+"<<Ast2<<endl;
		cout<<"Ast = "<<Ast<<endl;
		cout<<"0 = ";
		cin>>fi_t;
		Ast_p = (M_PI*pow(fi_t, 2))/4;
		cout<<"No. of bars in tension = "<<Ast/Ast_p<<endl;
		
		cout<<"for compression"<<endl;
		float fi_c, Asc_p;
		cout<<"Asc = "<<Asc<<endl;
		cout<<"0 = ";
		cin>>fi_c;
		Asc_p = (M_PI*pow(fi_c, 2))/4;
		cout<<"No. of bars compression = "<<Asc/Asc_p<<endl;
		
			
			
			
		}
}
