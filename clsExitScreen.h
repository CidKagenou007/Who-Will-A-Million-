#pragma once

#include <iostream>

using namespace std ;

class clsExitScreen {

public :

    static void ExitScreen() {

        system("cls") ;

        cout << "\t\t...Game Ending...\n" << endl ;
    }
} ;