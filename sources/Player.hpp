#pragma once
#include "Board.hpp"
#include <string>
#include <list>

namespace pandemic 
{
class Player{
    protected:
        Board &board; // Board For Game
        City city; // His City
        std::string job; // Profession
        std::list<City> cards; // His Deck

    public:
        Player(Board &b, City c, std::string roll = "Player") : job(roll), board(b), city(c){};
                       virtual Player& discover_cure(Color c);// Discover Cure Based on Traits
 virtual Player& drive(City c); // Drive Alo has Special traits based on Job
        virtual Player& fly_shuttle(City c);//Transport between Labs/stations 
               virtual Player& fly_direct(City c);// Drop Card of Current City and Fly to it 
 virtual Player& build(); //Build Station
        Player &remove_cards(); // Throw
        Player& take_card(City c); // Take
        virtual Player& fly_charter(City c);// Drop Curent City Card and Fly Whereever  

        //lower one block of ilnace from the city
        virtual Player& treat(City c);
        // FOR TESTS : 
        std::string role()
        {
            return job;
        }
        
};
}