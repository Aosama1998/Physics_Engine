#include <iostream>
using namespace std;
/*In this case, our function template sum() accepts two parameters of different types 
and returns an object of the same type as the second parameter (T2) that is passed.
*/
template<class t1 , typename t2> 
t2 sum(t1 x , t2 y){

    return x+y;
}

int main(){

float x{8.9};
int y{8};
float c{6.786};
float Z{0};

Z = sum(x , c);

cout<<Z; 









}


