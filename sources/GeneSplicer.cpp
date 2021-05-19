#include "GeneSplicer.hpp"
using namespace pandemic;
const int Five = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    int i = 1;// Needed For EAch
    if (!board.check_if_station(city)||cards.size() < Five) // Need 5 cards regardless and a staion
    {
        throw std::invalid_argument{"No Station or Not Enough Cards"};
    }

    if (board.check_cure_discovered(c)) // if already has cure no need
    {
        return *this;
    }
    
    for(auto card = cards.begin(); card != cards.end()||i==Five; i++){ // Five Time Itterate 

         card=cards.erase(card);
    }
    
    board.set_cured_diseases(c);// Cure After Drop of 5 Cards
    return *this;
}
