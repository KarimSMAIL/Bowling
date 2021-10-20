#include "bowling.h"
#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{   
    string lineData;

    cout << "Enter the data line: ";
    cin >> lineData;
    //if(!cin) break;

    auto t = validLine(lineData);

    if(get<0>(t)) cout<< "The global is : " << calculateScore(get<1>(t))<< endl;
    
    return 0;
}
