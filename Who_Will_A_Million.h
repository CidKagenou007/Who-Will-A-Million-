#pragma once

#include <iostream>
#include "Support/clsInputValidate.h"
#include "clsExitScreen.h"
#include "clsNewGame.h"

using namespace std ;

class Who_Will_A_Million {

private :

    enum enStartOptions {

        eNewGame = 1 , eExit = 2
    } ;

    static short ReadChoice() {

        return clsInputValidate::ReadNumberBetweenWithValidation <short> (1 , 2 , "Your Chose 1/2: " ,
        "Invalid Number Chose 1 or 2: ") ;
    }

    static void ShowNewGameScreen() {

        clsNewGame Game ;
        Game.NewGameScreen() ;
    }

    static void ShowExitScreen() {

        clsExitScreen::ExitScreen() ;
    }

    static void PerformGame(enStartOptions Choice) {

        switch (Choice) {

            case enStartOptions::eNewGame :
                ShowNewGameScreen() ;
            case enStartOptions::eExit :
                ShowExitScreen() ;
                break;
        }
    }

public :

    static void Start() {

        system("cls") ;

        cout << "+-------------------------------------------------------+" << endl ;
        cout << "|\t\t\t Game Menu                      |" << endl ;
        cout << "+-------------------------------------------------------+" << endl ;

        cout << "|\t [1] New Game                                   |" << endl ;
        cout << "|\t [2] Exit                                       |" << endl ;

        cout << "+-------------------------------------------------------+" << endl ;

        PerformGame((enStartOptions)ReadChoice()) ;
    }
} ;