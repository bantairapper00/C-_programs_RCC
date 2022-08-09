#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, b, fck, fy, n_c, dia_c, n_t, dia_t, d_dash;
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
	cout<<"Number of bars in compression = "<<flush;
	cin>>n_c;
	cout<<"Diameter of bars in compression = "<<flush;
	cin>>dia_c;
	cout<<"Number of bars in tension = "<<flush;
	cin>>n_t;
	cout<<"Diameter of bars in tension = "<<flush;
	cin>>dia_t;
	cout<<endl;
	float Asc = (n_c*M_PI*pow(dia_c, 2))/4;
	cout<<"Area of steel in compression Asc = "<<Asc<<endl;
	float Ast = (n_t*M_PI*pow(dia_t, 2))/4;
	cout<<"Area of tensile steel Ast = "<<Ast<<endl;
	float newXu, fsc;
	
	for(int i=0;i<4;i++){
		float Xu;
		if(i==0){
			cout<<endl;
			cout<<"Assume, Xu = Xulim"<<endl;
			if(fy == 250){
				Xu = 0.53*d;
				cout<<"Xu = 0.53*d"<<" = "<<Xu<<endl;
			} 
			else if(fy == 415){
				Xu = 0.48*d;
				cout<<"Xu = 0.48*d"<<" = "<<Xu<<endl;
			}
			else if(fy == 500){
				Xu = 0.46*d;
				cout<<"Xu = 0.46*d"<<" = "<<Xu<<endl;
			}
		}
		
		else{
			cout<<endl;
			cout<<i+1<<" assumptiom"<<endl;
			cout<<"Assume, Xu = "<<newXu<<endl;
			Xu = newXu;
		}
		
		cout<<"Strain in compression steel = "<<endl;
		float Esc = ((Xu - d_dash)/(Xu))*0.0035;
		cout<<"Esc = ((Xu - d')/(Xu))*0.0035 = "<<Esc<<endl;
		
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
		
		cout<<"Now,"<<endl;
		cout<<"C = T"<<endl;
		cout<<"0.36*fck*b*Xu + fsc*Asc = 0.87*fy*Ast"<<endl;
		newXu = ((0.87*fy*Ast) - (fsc*Asc))/(0.36*fck*b);
		cout<<"Xu = "<<newXu<<endl;
		
	}
	
	cout<<endl;
	float newxu,Mu,newfsc;
	cout<<"Xu = ";
	cin>>newxu;
	cout<<"fsc = ";
	cin>>newfsc;
	cout<<"Moment of resistance, Mu"<<endl;
	cout<<"Mu = 0.36*fck*Xu*b*(d - 0.42*Xu) + Asc*fsc*(d-d')"<<endl;
	cout<<"Mu = 0.36*"<<fck<<"*"<<newxu<<"*"<<b<<"*("<<d<<" - 0.42*"<<newxu<<") + "<<Asc<<"*"<<newfsc<<"*"<<"("<<d<<"-"<<d_dash<<")"<<endl;
	Mu = 0.36*fck*newxu*b*(d - (0.42*newxu)) + Asc*newfsc*(d - d_dash);
	cout<<"Mu = "<<fixed<<setprecision(2)<<Mu<<"N-mm"<<endl;
	cout<<"Mu = "<<fixed<<setprecision(2)<<Mu/1000000<<"kN-m"<<endl;
	
	
}
