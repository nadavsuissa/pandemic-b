#include "Medic.hpp"
#include <list>
#include <algorithm>
using namespace pandemic;

Player &Medic::drive(City c) // Implemented Drive With Medic Traits
{
    if (!board.check_cure_discovered(c)) // May Still Drive...
    {
        return Player::drive(c);
    }

    if (city == c||!Board::check_if_connected(city, c))
    {
        throw std::invalid_argument{"Error - Already Here or Not Connected"};
    }
    // After Passed Check, Update relevent parammeters 
    city = c;// update city
    board[c] = 0;// update Cubes
    return *this; // Return
}

Player &Medic::fly_direct(City c) // Implemented with Special Traits 
{
    if (!board.check_cure_discovered(c)) // May still fly
    {
        return Player::fly_direct(c);
    }

    if (city == c||!(std::find(cards.begin(), cards.end(), c) != cards.end()))
    {
        throw std::invalid_argument{"Error - Already Here or Dont have Required Card"};
    }
// After check and got here now update parameters 

    city = c;// Update
    board[c] = 0; // Update Cubes based oon given medic traits
    cards.remove(c);// Throw Card
    return *this;// REturn
}

Player &Medic::fly_charter(City c)// Fly Implement With Medic Traits
{
    // Help Tidy Validity Check
    bool help = std::find(cards.begin(), cards.end(), city) != cards.end();
    if (!board.check_cure_discovered(c))// No Cure but may
    {
        return Player::fly_charter(c);
    }
    // Error check
    if (city == c||!help)
    {
        throw std::invalid_argument{"Location or Card Error"};
    }
    // Got To HERE no ERROR - Execute

    city = c;// Update City
    board[c] = 0;// Update Cubes
    cards.remove(city);// Throw
    return *this;// Return
}

Player &Medic::fly_shuttle(City c)// Implemented fly_shuttle
{
    if (!board.check_cure_discovered(c)) // If not Discovered yet
    {
        return Player::fly_shuttle(c);
    }
    // Error Check(City and Station Requirment)
    if (city == c||!(board.check_if_station(city) && board.check_if_station(c)))
    {
        throw std::invalid_argument{"Card or Station Error"};
    }
    //Passed Checks then:

        city = c;// Update City
        board[c] = 0;// Update Cubes
        return *this;//return
}

Player &Medic::treat(City c)
{
    // Error Check(City and Cube Requirment)
    if (city != c||board[c] == 0)
    {
        throw std::invalid_argument{"Error: Not Here or No Cubes"};
    }
    // If Here Then Valid and Execute
    board[c] = 0;// Update Cube and Return
    return *this;
}