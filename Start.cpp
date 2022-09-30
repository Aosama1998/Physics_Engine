#include <iostream>
using namespace std;

template<class t> 
t sum(t x , t y){

    return x+y;
}

int main(){

float x{6.6} ,y{8.7} ,Z{0};

Z = sum <float> (x , y);

cout<<Z; 


}


