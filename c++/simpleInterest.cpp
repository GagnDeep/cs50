#include<iostream>
using namespace std;

class interest{
     private:
         double principal, Rate, Time;

     public:
         void input(double, double, double);

         double simpleInterest(){
             return principal*(Rate/100)*Time;
         }
};

int main(){
    interest s;

    s.input(10000 /*principal*/, 10 /*Rate in Percent*/, 5/*time in years*/);
    cout<<s.simpleInterest();

    return 0;
}

 void interest::input(double p, double R, double t){
     principal = p;
     Rate = R;
     Time = t;
 }