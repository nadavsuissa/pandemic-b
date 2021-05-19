#include "Dispatcher.hpp"

using namespace pandemic;

Player &Dispatcher::fly_direct(City c) // Implementation of Special Trait
{
    // Obvious no need to fly....
    if (city == c){
        throw std::invalid_argument{"ALready Here"};
    }

    if (!board.check_if_station(city))
    {
        return Player::fly_direct(c);    
    }
    city = c;// Update City
    return *this; // Return
}
