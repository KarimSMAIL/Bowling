#include "bowling.h"
#include <regex>

using namespace std;

#define EmptyFalseTuple make_tuple(false, vector<tuple<int, int>>(0))

tuple<bool, vector<tuple<int, int>>> validLine(string lineData)
{
    int len = lineData.length(); 

    if (!((len >= 11) && (len <= 21)))
    {
        cout<< "input not valid in length, valid length 11<= len <=21"<<endl;
        return EmptyFalseTuple;
    }
      
    //X, -, /, 1->9  
    regex reg_exp("(X|--|-/|-[1-9]|[1-9]-|[1-9][1-9]|[1-9]/){10}(X|-|[1-9])*");

    if (!regex_match(lineData, reg_exp))
    {
        cout<< "invalid input detected"<<endl;
        return EmptyFalseTuple;
    }
    
    vector<tuple<int, int>> rolls(11);
    int rollIndex(0);
    bool isSecondThrow(false);

    for (auto i = lineData.begin(); i != lineData.end(); ++i)
    {
        if (rollIndex > 10) // valid regex XXXXXXXXXXXXXXXXXXXX but invalid sequence
        {
            cout<< "invalid input detected"<<endl;
            return EmptyFalseTuple;
        }

        if (rollIndex < 10) // first ten rolls
        {
            switch (*i)
            {
                case 'X':
                {
                    get<0>(rolls.at(rollIndex)) = 10; 
                    get<1>(rolls.at(rollIndex)) = 0; 
                    rollIndex++;
                    isSecondThrow = false;
                    continue;
                }
                case '-':
                {
                    if (isSecondThrow)
                    {
                        get<1>(rolls.at(rollIndex)) = 0;
                        rollIndex++;
                        isSecondThrow = false;
                        continue;
                    }                
                    get<0>(rolls.at(rollIndex)) = 0; 
                     
                    isSecondThrow = true;
                    continue;
                }
                case '/':
                {
                    if (!isSecondThrow) // just incase the regex went crazy
                    {
                        cout<< "invalid input detected"<<endl;
                        return EmptyFalseTuple;
                    }

                    get<1>(rolls.at(rollIndex)) = 10 - get<0>(rolls.at(rollIndex));    
                    rollIndex++;
                    isSecondThrow = false;
                    continue;
                }  
                default:
                {
                    if ((*i >= '1') && (*i <= '9'))
                    {
                        if (isSecondThrow)
                        {
                            get<1>(rolls.at(rollIndex)) += *i - '0';
                            
                            if (get<0>(rolls.at(rollIndex)) + get<1>(rolls.at(rollIndex)) > 10)// invalid sequance
                            {
                                cout<< "invalid input detected"<<endl;
                                return EmptyFalseTuple; 
                            }

                            rollIndex++;
                            isSecondThrow = false;
                            continue;
                        }
                        
                        get<0>(rolls.at(rollIndex)) = *i - '0';
                        isSecondThrow = true;
                        continue;
                    }
                    else // just incase the regex went crazy
                    {
                        cout<< "invalid input detected"<<endl;
                        return EmptyFalseTuple; 
                    }
                } 
            }
        }
        else // bonus balls
        {
            if (get<0>(rolls.at(rollIndex - 1)) + get<1>(rolls.at(rollIndex - 1)) != 10) // invalid bouns balls
            {
                cout<< "invalid bouns balls"<<endl;
                return EmptyFalseTuple;
            }

            if (isSecondThrow)
            {
                if (!((get<0>(rolls.at(rollIndex - 1)) == 10) &&
                      (get<1>(rolls.at(rollIndex - 1)) == 0))) // invalid bouns balls
                {
                    cout<< "invalid bouns balls"<<endl;
                    return EmptyFalseTuple; 
                }
            }

            switch (*i)
            {
                case 'X':
                {
                    if (isSecondThrow)
                    {
                        get<1>(rolls.at(rollIndex)) = 10; 
                        rollIndex++;
                        isSecondThrow = false;
                        continue;
                    }

                    get<0>(rolls.at(rollIndex)) = 10; 
                    get<1>(rolls.at(rollIndex)) = 0; 
                    isSecondThrow = true;
                    continue;
                }
                case '-':
                {
                    if (isSecondThrow)
                    {
                        get<1>(rolls.at(rollIndex)) = 0; 
                        rollIndex++;
                        isSecondThrow = false;
                        continue;
                    }
                    
                    get<0>(rolls.at(rollIndex)) = 0; 
                    get<1>(rolls.at(rollIndex)) = 0;  
                    isSecondThrow = true;
                    continue;
                } 
                default:
                {
                    if ((*i >= '1') && (*i <= '9'))
                    {
                        if (isSecondThrow)
                        {
                            get<1>(rolls.at(rollIndex)) += *i - '0';
                            rollIndex++;
                            isSecondThrow = false;
                            continue;
                        }
                        
                        get<0>(rolls.at(rollIndex)) = *i - '0'; 
                        get<1>(rolls.at(rollIndex)) = 0; 
                        isSecondThrow = true;
                        continue;
                    }
                    else // just incase the regex went crazy
                    {
                        cout<< "invalid input detected"<<endl;
                        return EmptyFalseTuple; 
                    }
                } 
            }
        }    
    }

    return make_tuple(true, rolls);
}

int calculateScore(vector<tuple<int, int>> rolls)
{
    int score(0);
    int rollIndex(0);

    for (auto roll = rolls.begin(); roll != rolls.end(); ++roll)
    {
        auto item = *roll;

        if(rollIndex < 9)
        {
            score += get<0>(item) + get<1>(item);
            if((get<0>(item) == 10) && (get<1>(item) == 0))
            {
                score += get<0>(rolls.at(rollIndex + 1));
                if ((get<0>(rolls.at(rollIndex + 1)) == 10) && (get<1>(rolls.at(rollIndex + 1)) == 0)) // strike in next roll
                {
                    score += get<0>(rolls.at(rollIndex + 2)); // add second next roll first throw
                }
                else
                {
                   score += get<1>(rolls.at(rollIndex + 1)); // add first next roll second throw
                }
            }
            else 
            {
                if (get<0>(item) + get<1>(item) == 10) // spare in current roll
                {
                    score += get<0>(rolls.at(rollIndex + 1)); // add first next roll first throw    
                }
            }
        }
        else 
        {
            score += get<0>(item) + get<1>(item);
        }
        rollIndex++;
    }
    
    return score;
}