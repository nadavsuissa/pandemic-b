#include<list>
#include<algorithm>
#include "Researcher.hpp"
#include<iterator>
using namespace pandemic;
const int Five = 5; // Tidy Required

Player &Researcher::discover_cure(Color c) //Discover Func
{
    int count=0; // Count of how many cards...
    if (board.check_cure_discovered(c)) // If already Found then Return Obviously
    {
        return *this;
    }


    std::list<City>::iterator it; // List ITERATOR for TempCards
    std::list<City> temp_cards; // Deck of Temp Cards
    // Begin Iterating
    // Break at End or when got to 5 match
    for (it = cards.begin(); it != cards.end()||temp_cards.size() == Five; it++)
    {
        if (board.check_color(*it) == c)
        {
            temp_cards.push_front(*it);
            count++;
        }

    }

    if (count < Five) // Must check(Either Finished iterate without 5 or before finish reached 5)
    {
        throw std::invalid_argument{"Not Enough of Same Color"};
    }
    // Start Actions - SetCure and Throw Cards
    board.set_cured_diseases(c);
    for (const auto &card : temp_cards)
    {
        cards.remove(card);
    }
    return *this; // Return
}