#pragma once 

#include <iostream>

using namespace std ;

class clsBasicRequirements {

protected :

    struct stAnswers {

        string Answers[4] ;
    } ;

    static string GetCorrectAnswer(short Index) {

        string Correct[15] = {
        "Paris",
        "Oxygen",
        "George Orwell",
        "Jupiter",
        "Japan",
        "Leonardo da Vinci",
        "1",
        "Avocado",
        "Alexander Fleming",
        "Mars",
        "Pacific Ocean",
        "Yen",
        "Nile River",
        "1912",
        "Diamond"
        };

        return Correct[Index] ;
    }

    static string Question(short Index) {

        string arrQuestion[15] = {"** What is the capital of France? **" , 
        "** Which element has the chemical symbol 'O'? **" , "** Who wrote \"1984\"? **" , 
        "** What is the largest planet in our solar system? **" ,
        "** Which country is known as the Land of the Rising Sun? **" ,
        "** Who painted the Mona Lisa? **" , "** What is the smallest prime number? **" , 
        "** What is the main ingredient in guacamole? **" , "** Who discovered penicillin? **" , 
        "** Which planet is known as the Red Planet? **" , "** Which ocean is the largest? **" , 
        "** What is the currency of Japan? **" , "** Which is the longest river in the world? **" , 
        "** In which year did the Titanic sink? **" , "** What is the hardest natural substance on Earth? **"} ;

        

        return arrQuestion[Index] ;
    }

    static stAnswers GetAnswers(short Index) {

        stAnswers Answer[15] = {
        {"Berlin", "Madrid", "Rome", "Paris"},
        {"Gold", "Oxygen", "Osmium", "Oganesson"},
        {"George Orwell", "J.K. Rowling", "Mark Twain", "Jane Austen"},
        {"Earth", "Mars", "Jupiter", "Saturn"},
        {"China", "Japan", "India", "South Korea"},
        {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"},
        {"0", "1", "2", "3"},
        {"Tomato", "Onion", "Avocado", "Cilantro"},
        {"Marie Curie", "Alexander Fleming", "Albert Einstein", "Isaac Newton"},
        {"Venus", "Mars", "Jupiter", "Mercury"},
        {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
        {"Yen", "Dollar", "Euro", "Pound"},
        {"Amazon River", "Nile River", "Yangtze River", "Mississippi River"},
        {"1905", "1912", "1918", "1923"},
        {"Gold", "Iron", "Diamond", "Platinum"}
        };

        return Answer[Index] ;
    }

    static string GetAnswers(short Index , short AnswerChoice) {

        return GetAnswers(Index).Answers[AnswerChoice - 1] ;
    }

    static void StopScreen() {

        cout << "\nPress Enter To Continue..." ;

        system("Pause>0") ;
    }
} ;