#pragma once

#include <iostream>
#include "clsBasicRequirements.h"
#include "clsGlobal.h"

using namespace std ;

class clsCheckAnswerScreen : protected clsBasicRequirements {

public :

    static void ShowCheckAnswerScreen() {

        system("cls") ;

        if (GetAnswers(Index , AnswerChoice) == GetCorrectAnswer(Index)) {
            Result = true ;

            system("Color 67") ;

            cout << "Good Job, You have now [$" << CurrentMoney << "]" << endl ;
        }

        else {
            
            Result = false ;

            system("Color 47") ;
            
            cout << "Wrong Answer! The Right was [" << GetCorrectAnswer(Index) << "]" << endl ;
        }
            
        StopScreen() ;
    }
} ;