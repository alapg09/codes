#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double t, T, C, s1,s_final;
    double A = 0.1, B = 0.05, τ = 50, ω = 0.5, alpha = 1.5, β = 20, gamma = 1, δ = 100, t₀ = 30, T₀ = 1, C₀ = 400, pi = 3.1416;   
   
    cout<<"Enter time (in years) sice 2000: ";
    cin>>t;
    cout<<"Enter Golabal average temperature anomaly(in Celsius): ";
    cin>>T;
    cout<<"Atmospheric C02 CONCENTRATION( IN PPM ): ";
    cin>>C;
    

    s1 = (A)*log(1+(t/τ))*((sin(ω*T)+1)/2)*(pow((C/C₀), alpha));
    s_final = s1 + (B)*((atan((t-t₀))/β)+ (1/2))*((atan((T-T₀)/gamma) + (pi/2))/pi)*(exp((C-C₀)/δ));

    cout<<"The sea level rise ( in meters ) is: "<<s_final;



    return 0;
}