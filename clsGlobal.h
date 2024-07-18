#pragma once

#include <iostream>

using namespace std ;

bool Check[3] = {false , false , false} ;
bool Result ;

int CurrentMoney ;
short AnswerChoice , Index ;

string S[15] = {"100" , "200" , "300" , "500" , "1,000" , "2,000",
"4,000" , "8,000" , "16,000" , "32,000"  , "64,000" , "125,000",
"250,000" ,  "500,000" , "1,000,000"} ;

int M[15] = {100 , 200 , 300 , 500 , 1000 , 2000,
4000 , 8000 , 16000 , 32000 , 64000 , 125000,
250000 ,  500000 , 1000000} ;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE) ;