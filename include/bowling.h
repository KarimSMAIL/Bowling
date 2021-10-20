#ifndef __BOWLING_H__
#define __BOWLING_H__

#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

//validate the input data and return true or false
tuple<bool, vector<tuple<int, int>>> validLine(string lineData);

//calculate the finale score of the game based on the rolls score
int calculateScore(vector<tuple<int, int>> rolls);

#endif