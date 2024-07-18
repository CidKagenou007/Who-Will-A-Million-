#pragma once

#include <iostream>
#include <string>
#include "Support/clsString.h"
#include "Support/clsUtility.h"
#include <windows.h>
#include "clsBasicRequirements.h"
#include <vector>
#include "clsCheckAnswerScreen.h"
#include <cctype>
#include "Support/clsInputValidate.h"
#include "clsGlobal.h"
#include <iomanip>

using namespace std ;

class clsNewGame : protected clsBasicRequirements {

private :

    enum enGameOptions {

        eAnswer = 1 , eFifty_Fifty = 5 , ePhone_a_Friend = 6,
        eAsk_the_Audience = 7
    } ;

    static void Row(string RowWords , short ColorRowWords) {

        short max = 61 - RowWords.length() - 1 ;

        SetConsoleTextAttribute(h , 2) ;

        cout << "|" ;

        SetConsoleTextAttribute(h , ColorRowWords) ;

        cout << RowWords  ;

        for (short i = 0 ; i < max ; i++)
            cout << " " ;

        SetConsoleTextAttribute(h , 2) ;

        cout << "|" << endl ;
    }

    static void EndRow() {

        SetConsoleTextAttribute(h , 1) ;

        cout << "+------------------------------------------------------------------+" << endl ;
    }

    static void Col() {

        SetConsoleTextAttribute(h , 2) ;

        cout << "| $" ;

        SetConsoleTextAttribute(h , 7) ;
    }

    static short ReadChoice() {

        short Choice = clsInputValidate::ReadNumberBetweenWithValidation <short> 
        (1 , 7 , "Enter your Chose 1/7: " , "Invalid Number Chose 1 or 7: ") ;

        if (clsInputValidate::IsNumberBetween <short> (Choice , 1 , 4)) {

            AnswerChoice = Choice ;
            return 1 ;
        }
        
        return Choice ;
    }

    static bool PerformGame(enGameOptions Choice , short Index) {

        clsCheckAnswerScreen CheckAnswerScreen = clsCheckAnswerScreen(Index) ;

        switch (Choice) {

            case enGameOptions::eAnswer :
                CheckAnswerScreen.ShowCheckAnswerScreen() ;
                break;
            /*case enGameOptions::eFifty_Fifty :
                clsFifty_FiftyScreen::ShowFifty_FiftyScreen() ;
                break;
            case enGameOptions::ePhone_a_Friend :
                clsPhone_a_FriendScreen::ShowPhone_a_FriendScreen() ;
                break;
            case enGameOptions::eAsk_the_Audience :
                clseAsk_the_AudienceScreen::ShoweAsk_the_AudienceScreen() ;
                break;
            */ 
        } 

        return CheckAnswerScreen.Result() ;
    }

    static bool IsAlreadyTaken(short Index , vector <short> vQuestionsTaken) {

        if (vQuestionsTaken.empty())
            return false ;

        for (short Question : vQuestionsTaken) {
            if (Question == Index)
                return true ;
        }

        return false ;
    }

    static void Print(string N1 , string N2 , string N3) {

        Col() ; cout << left << setw(14) << N1 ;
        Col() ; cout << left << setw(11) << N2 ;
        Col() ; cout << N3 << endl ;
    }

    static PrintWinScreen(short CurrentRound , short FinalRound) {

        if (CurrentRound == FinalRound) {

            cout << endl << endl ;
            EndRow() ;
            Row("\t" , 6) ;
            Row("\t         1,000,000" , 6 ) ;
            Row("\t" , 6) ;
            EndRow() ;
            Row("\t What a incredible achivement!!" , 6) ;
            EndRow() ;
            Row("\tCongratlation on making it to a million!" , 6) ;
            Row("\tYou should be so pround of yourself. Will Done :)" , 6) ;
            EndRow() ;

        }
    }

public :

    void NewGameScreen() {

        
        clsUtility::Srand() ;
        stAnswers Answer ;

        char PLayAgain = 'Y' ;

        do {

            vector <short> vQuestionsTaken ;
            short Index ;
            
            CurrentMoney = 0 ;
            
            short i = 0 ;

            for (i ; i < 15 ; i++) {

            system("cls") ;

            S[i] = S[i] + " <" ;

            EndRow() ;
            Row("\tThe LifeLines To Use" , 6) ;
            EndRow() ;
            Row("\t[5]:(Fifty-Fifty):" , 7 ) ;
            Row("\t[6]:(Phone-a-Friend):" , 7) ;
            Row("\t[5]:(Ask-the-Audience):" , 7) ;
            EndRow() ;
            Row("\tConstestant Prize $" , 6 ) ;
            EndRow() ;

            for (short j = 14 ; j >= 2 ; j -= 3)
            
                Print(S[j] , S[j - 1] , S[j - 2]) ;
            
            EndRow() ;
            Row("\tThe Question" , 6) ;
            EndRow() ;
            Index = clsUtility::RandomNumber(0 , 14) ;

            while (IsAlreadyTaken(Index , vQuestionsTaken)) {

                Index = clsUtility::RandomNumber(0 , 14) ;
            }
    
            vQuestionsTaken.push_back(Index) ;
            Row("\t" + Question(Index), 7) ;
            EndRow() ;
            Answer = GetAnswers(Index) ;

            for (short j = 0 ; j < 4 ; j++)
                Row("\t(" + to_string((j + 1)) + ") " + Answer.Answers[j] , 7) ;

            EndRow() ;

            SetConsoleTextAttribute(h , 7) ;

            CurrentMoney = M[i] ;

            S[i] = clsString::ReplaceWordInString(S[i] , " <" , "") ;            

            if (!(PerformGame((enGameOptions) ReadChoice() , Index)))
                break;

            system("Color 07") ;

            
            PrintWinScreen(i , 14) ;
            
            }
            

            system("Color 07") ;
            PLayAgain = clsInputValidate::ReadCharacter("\n\nDo You want to play again? y/n?  ") ;


        } while (toupper(PLayAgain) == 'Y') ;
        


    }
} ;