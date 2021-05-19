#include "Player.hpp"
#include <list>
#include <iterator>
#include <algorithm>
const int Five = 5; // Tidy Magic - Must Name

using namespace pandemic;
//Simple Drive To Connected City

Player &Player::drive(City c)
{
    // Cant Drive To The City you are In
    if (city == c || !(Board::check_if_connected(city, c)))
    {
        throw std::invalid_argument{"Flight Error - You are already in the city or you are not connected"};
    }

    city = c; // Change City
    return *this;
}
Player &Player::take_card(City c)
{
    cards.push_back(c);
    return *this; // return player
} //If the player has the card of the city he is in - May Throw And Fly Wherever

Player &Player::fly_charter(City c)
{
    // Validity Check
    if (city == c || !(std::find(cards.begin(), cards.end(), city) != cards.end()))
    {
        throw std::invalid_argument{"Flight Error - You are already here or you dont have the required card"};
    }

    cards.remove(city); // Throw Card
    city = c;           // Update City
    return *this;       // Return
}
//If Player has Card of Current City, Throw and Build Station

Player &Player::build()
{
    // Error Check (Card Requierment)
    if (!(std::find(cards.begin(), cards.end(), city) != cards.end()))
    {
        throw std::invalid_argument{"You don't have the Required card To build th Station"};
    }
    // If not thrown then Valid:
    cards.remove(city);
    board.add_station(city); // Build
          // remove
    return *this;            // Return
}
Player &Player::remove_cards()
{
    cards.clear();
    return *this; // return player
}

//Throw City Card And Fly to that city

Player &Player::fly_direct(City c)
{
    // Validity Check...
    if (city == c || !(std::find(cards.begin(), cards.end(), c) != cards.end()))
    {
        throw std::invalid_argument{"Flight Error - You are already in the city or you dont have the required card"};
    }
    // After passing Test.... Fly:

    city = c;        // Update City
    cards.remove(c); // Throw Card
    return *this;    // Return
}

// Fly From City With Station to Other City with Station

Player &Player::fly_shuttle(City c)
{
    // Check that is Valid
    if (city == c || !board.check_if_station(city) || !board.check_if_station(c))
    {
        throw std::invalid_argument{"Flight Error - You are already here or One of the Cities Doesnt Have a Station"};
    }
    // If Valid and not Thrown then -

    city = c; // Update City
    return *this;
}

// If In City With Station and Has 5 cards with same color as diesis then able to cure
Player &Player::discover_cure(Color c)
{
    int count = 0; // Help Count
    // Error Check
    if (!board.check_if_station(city))
    {
        throw std::invalid_argument{"the city- " + citystring(city) + " dosent have a station"};
    }

    if (board.check_cure_discovered(c)) // Cure already Exists
    {
        return *this;
    }
    std::list<City>::iterator it;
    std::list<City> temp_cards; // Temp Help Deck
    // Since list Then Iterate with Iterator
    // Stop When Iterated over Deck or I have 5 cards of same color -
    for (it = cards.begin(); it != cards.end() || temp_cards.size() == Five; it++)
    {
        if (board.check_color(*it) == c && *it != city)
        {
            temp_cards.push_back(*it);
            count++;
        }
    }
    // Since I don't know what happened (got 5 same color or iterated over whole deck) I must Check
    if (count < Five)
    {
        throw std::invalid_argument{"Not Enough Cards with Same Color"};
    }
    std::list<City>::iterator itt;
    // Throw Cards Part... via Iterator
    for (itt = temp_cards.begin(); itt != temp_cards.end(); itt++)
    {
        cards.remove(*itt);
    }

    board.set_cured_diseases(c); // Discover Cure
    return *this;                // Return
}

// If Player in City Can Treat if Give 1 Cube

Player &Player::treat(City c)
{
    // Validity Check (On City and Have Cubes)
    if (city != c || board[c] == 0)
    {
        throw std::invalid_argument{"Error -Not in City or # of Cubes = 0"};
    }
    // Passed Checks and Execute
    if (board.check_cure_discovered(c)) // Even Better, If Cure then Cubes == 0
    {
        board[c] = 0;
    }
    else // Treat
    {
        board[c] = board[c] - 1;
    }
    return *this;
}
