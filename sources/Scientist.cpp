#include "Scientist.hpp"
#include <list>
#include <algorithm>
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    // First for this to be valid we must check if there is a station and if it already has a cure
    bool check = board.check_if_station(city);
    if (!check) // if Turned out False Throw Because no Station
    {
        throw std::invalid_argument{"City Without Station"};
    }

    if (board.check_cure_discovered(c)) // Already Has Cure... Just Return
    {
        return *this;
    }

    std::list<City>::iterator it; // List ITERATOR
    std::list<City> temp_cards;

    for (it = cards.begin(); it != cards.end(); it++)
    {
        if (board.check_color(*it) == c)
        {
            temp_cards.push_back(*it);
        }
        if (temp_cards.size() == number)
        {
            break;
        }
    }
    if (temp_cards.size() != number)
    {
        throw std::invalid_argument{"Not Enought of Color"};
    } 
    board.set_cured_diseases(c); // Set Cure
    std::list<City>::iterator itt; // Iterate Remove Cards After Set Cure(Part of Game)
    for (itt = temp_cards.begin(); itt != temp_cards.end(); itt++)
    {
        cards.remove(*itt);
    }
   
    return *this; // Return
}
