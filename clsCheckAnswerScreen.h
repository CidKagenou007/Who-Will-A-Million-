#pragma once

#include <iostream>
#include "clsBasicRequirements.h"
#include "clsGlobal.h"

using namespace std ;

class clsCheckAnswerScreen : protected clsBasicRequirements {

private :

    short _Index ;
    bool _Result ;

public :

    clsCheckAnswerScreen(short Index) {

        _Index = Index ;
    }

    short Index() {

        return _Index ;
    }

    bool Result() {

        return _Result ;
    }

    void ShowCheckAnswerScreen() {

        system("cls") ;

        if (GetAnswers(Index() , AnswerChoice) == GetCorrectAnswer(Index())) {
            _Result = true ;

            system("Color 67") ;

            cout << "Good Job, You have now [$" << CurrentMoney << "]" << endl ;
        }

        else {
            _Result = false ;

            system("Color 47") ;
            
            cout << "Wrong Answer! The Right was [" << GetCorrectAnswer(Index()) << "]" << endl ;
        }
            
        cout << "\nPress Enter To Continue..." ;

        system("Pause>0") ;
    }
} ;