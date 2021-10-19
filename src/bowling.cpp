#include "bowling.h"
#include <regex>

using namespace std;

#define EmptyFalseTuple make_tuple(false, vector<tuple<int, int>>(0))

tuple<bool, vector<tuple<int, int>>> validLine(string lineData)
{
    if (!((lineData.size() <= 21) && (lineData.size() >= 11)))
    {
        cout<< "input not valid in length, valid length 11<= len <=21"<<endl;
        return EmptyFalseTuple;
    }
    //X, /, -, 1->9
    regex exp_rex("(X|--|-/|-[1-9]|[1-9]-|[1-9][1-9]|[1-9]/){10}(X|-|[1-9])*");

    if (!(regex_match(lineData, exp_rex)))
    {
        cout<< "invalid input detected"<<endl;
        return EmptyFalseTuple;
    }
    
    vector<tuple<int, int>> rolls(11);
    int rollIndex(0);
    bool isSeconfThrow(false);

    for (auto i = lineData.begin(); i != lineData.end(); i++)
    {
        if (rollIndex > 10) // valid regex XXXXXXXXXXXXXXXXXXXX but invalid sequence
        {
            cout<< "invalid input detected"<<endl;
            return EmptyFalseTuple;
        }

        if(rollIndex < 10) // first ten rolls
        {
            switch(*i)
            {
                case 'X': 
                {
                    get<0>(rolls.at(rollIndex)) = 10;
                    get<1>(rolls.at(rollIndex)) = 0;
                    rollIndex++;
                    isSeconfThrow = false;
                    continue;
                }
                case '-':
                {
                    if(isSeconfThrow)
                    {
                        get<1>(rolls.at(rollIndex)) = 0;
                        rollIndex++;
                        isSeconfThrow = false;
                        continue;
                    }

                    get<0>(rolls.at(rollIndex)) = 0;
                    isSeconfThrow = true;
                    continue;
                }
                case '/':
                {
                    if(!isSeconfThrow){
                        cout<< "invalid input detected"<<endl;
                        return EmptyFalseTuple;
                    }

                    get<1>(rolls.at(rollIndex)) = 10 - get<0>(rolls.at(rollIndex));
                    rollIndex++;
                    isSeconfThrow = false;
                    continue;
                }
                default:
                {

                }
            }
                
        }
    }
    


    


    return EmptyFalseTuple;
}