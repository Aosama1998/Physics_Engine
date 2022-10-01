#include <iostream>
#include <map>
#include <vector>
#include<utility>

/*
                                          Templates  |  |  |    |   |   |   |   |   |   |   |                                                                                         

In this case, our function template sum() accepts two parameters of different types 
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

std::cout<<Z; 

//  |  |  |    |   |   |   |   |   |   |   |     Maps  |  |  |    |   |   |   |   |   |   |   | 

struct cityRecord{

std::string cityname;
uint64_t Population;
float latitude, longitude; 

};

std::vector<cityRecord> cities;

//First way to create a map, not recommended 

std::map< std::string , cityRecord> Citymap;
Citymap["Cairo"]= {"Cairo", 5000000, 2.4, 9.6};
Citymap["Giza"]= {"Giza", 5000000, 2.4, 9.6};
Citymap["Minya"]= {"Minya", 5000000, 2.4, 9.6};
Citymap["Assiut"]= {"Assiut", 5000000, 2.4, 9.6};
Citymap["Alex"]= {"Alex", 5000000, 2.4, 9.6 };

//Another way to create and initialize map. Most recommended

 std::map<int, std::string> sample_map { { 1, "one"}, { 2, "two" } };

//Another way to create a map, utilizing pair function. Not supported I guess ?? because pair function is not working

//std::map<int, std::string> sample_map2;
//sample_map2.insert(pair<int, string>(1, "one"));

//Pair is used to combine together two values that may be of different data types. Pair provides a way to store two heterogeneous objects as a single unit. 
//It is basically used if we want to store tuples.
// The pair container is a simple container defined in <utility> header consisting of two data elements or objects. 

}

////////////////////////////////////////////////////Assert function///////////////////////////////////////////////////
/*In my print_number function I assume that always the pointer coming is not null.
 I would be very very surprised if this is null. I don't care to handle this scenario at all in my code.
 
 Syntax : #include <assert.h>

 assert (SomeCondition);
 */


