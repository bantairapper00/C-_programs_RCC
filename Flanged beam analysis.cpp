#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
	float d, Df, bf,bw, fck, fy, n, dia;
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
	cout<<"Number of bars = "<<flush;
	cin>>n;
	cout<<"Diameter of bars = "<<flush;
	cin>>dia;
	cout<<endl;
	float Ast = (n*M_PI*pow(dia, 2))/4;
	cout<<"Area of tensile steel Ast = "<<Ast<<endl<<endl;
	float Xu = (0.87*fy*Ast)/(0.36*fck*bf);
	cout<<"Case 1, Assuming Xu <= Df"<<endl<<"C = T"<<endl<<"0.36*fck*bf*Xu = 0.87*fy*Ast"<<endl;
	cout<<"Xu = (0.87*"<<fy<<"*"<<Ast<<")/(0.36*"<<fck<<"*"<<bf<<")"<<endl;
	cout<<"Xu = "<<Xu<<endl;
	if(Xu<=Df){
		cout<<"Xu < Df"<<endl;
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
			double MOR = 0.36*fck*bf*Xu*(d - (0.42*Xu));
			cout<<"Moment of resistance, Mu = C*LA"<<endl;
			cout<<"                         = 0.36*fck*bf*Xu*(d - 0.42*Xu)"<<endl;
			cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
			cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
	
		}
		else if(Xu > Xulim){
			cout<<"Since compression failures are to be avoided, so momemt of resistace = Mulim"<<endl;
			double MOR = 0.36*fck*bf*Xulim*(d - (0.42*Xulim));
			cout<<"Moment of resistance, Mu = Mulim"<<endl;
			cout<<"                         = 0.36*fck*b*Xulim*(d - 0.42*Xulim)"<<endl;
			cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
			cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
	
		}
	}
	else{
		cout<<"Xu > Df, so our assumption was wrong"<<endl<<endl;
		cout<<"Case 2, Assuming Xu > Df and (3/7)Xu < Df"<<endl<<"C1 + C2 = T"<<endl<<"0.36*fck*bw*Xu + 0.45*fck*(bf - bw)*(0.15Xu + 0.65*Df)= 0.87*fy*Ast"<<endl;
		cout<<"Xu = ((0.87*"<<fy<<"*"<<Ast<<") - (0.45*"<<fck<<"("<<bf<<"-"<<bw<<")*(0.15*"<<Xu<<"+0.65"<<Df<<")))"<<"/(0.36*"<<fck<<"*"<<bw<<")"<<endl;
		float Xu = ((0.87*fy*Ast) - (0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df)))/(0.36*fck*bw);
		cout<<"Xu = "<<Xu<<endl;
		float Xulim;
		float x = (float)(3*Xu)/7;
		cout<<x<<endl;
		if(Xu > Df &&  x < Df){
			cout<<"Xu > Df and (3/7)*Xu < Df"<<endl;	
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
				float yf = (0.15*Xu) + (0.65*Df);
				double MOR = 0.36*fck*bw*Xu*(d - (0.42*Xu)) + (0.45*fck*(bf - bw)*yf*(d-(yf/2)));
				cout<<"Moment of resistance, Mu = C1*Z1 + C2*Z2"<<endl;
				cout<<"                         = 0.36*fck*bw*Xu*(d - 0.42*Xu) + (0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df)*(d - (0.15*Xu + 0.65*Df)/2)"<<endl;
				cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
				cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
			
			}
			else if(Xu > Xulim){
				float yf = (0.15*Xu) + (0.65*Df);
				cout<<"Since compression failures are to be avoided, so momemt of resistace = Mulim"<<endl;
				double MOR = 0.36*fck*bw*Xulim*(d - (0.42*Xulim)) + (0.45*fck*(bf - bw)*yf*(d-(yf/2)));
				cout<<"Moment of resistance, Mu = Mulim"<<endl;
				cout<<"                         = 0.36*fck*bw*Xulim*(d - 0.42*Xulim) + (0.45*fck*(bf - bw)*(0.15*Xu + 0.65*Df)*(d - ((0.15*Xu + 0.65*Df)/2))"<<endl;
				cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
				cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
			
			}
		}
		
		else{
			cout<<"Our assumption was wrong"<<endl<<endl;
			cout<<"Case 3, Assuming Xu > Df and (3/7)Xu > Df"<<endl<<"C1 + C2 = T"<<endl<<"0.36*fck*bf*Xu + 0.45*fck*(bf - bw)*(Df)= 0.87*fy*Ast"<<endl;
			cout<<"Xu = ((0.87*"<<fy<<"*"<<Ast<<") - (0.45*"<<fck<<"("<<bf<<"-"<<bw<<")*("<<Df<<")))"<<"/(0.36*"<<fck<<"*"<<bw<<")"<<endl;
			Xu = ((0.87*fy*Ast) - (0.45*fck*(bf - bw)*(Df)))/(0.36*fck*bw);
			cout<<"Xu = "<<Xu<<endl;
			float Xulim;
			if(Xu > Df && ((3*Xu)/7) > Df){
				cout<<"Xu > Df and (3/7)*Xu > Df"<<endl;	
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
					double MOR = 0.36*fck*bw*Xu*(d - (0.42*Xu)) + (0.45*fck*(bf - bw)*Df*(d-(Df/2)));
					cout<<"Moment of resistance, Mu = C1*Z1 + C2*Z2"<<endl;
					cout<<"                         = 0.36*fck*bw*Xu*(d - 0.42*Xu) + (0.45*fck*(bf - bw)*(Df)*(d - Df/2)"<<endl;
					cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
					cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
				
				}
				else if(Xu > Xulim){
					cout<<"Since compression failures are to be avoided, so momemt of resistace = Mulim"<<endl;
					double MOR = 0.36*fck*bw*Xulim*(d - (0.42*Xulim)) + (0.45*fck*(bf - bw)*Df*(d-(Df/2)));
					cout<<"Moment of resistance, Mu = Mulim"<<endl;
					cout<<"                         = 0.36*fck*bw*Xulim*(d - 0.42*Xulim) + (0.45*fck*(bf - bw)*(Df)*(d - (Df/2))"<<endl;
					cout<<"                         = "<< fixed <<setprecision(2) << MOR<<"N-mm"<<endl;
					cout<<"                         = "<< fixed <<setprecision(2) << MOR/1000000<<"KN-m"<<endl;
				
				}
			}
		}
	}
	
}
