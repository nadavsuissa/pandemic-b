#include "Virologist.hpp"
#include <list>
#include <algorithm>
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (city == c) // REgular Treat without the special Virologist Charactaristics
    {
        return Player::treat(c);
    }

    // Virologist Treat Checks:

    bool cardcheck = (std::find(cards.begin(), cards.end(), c) != cards.end());
    if (cards.empty() || !cardcheck||board[c] == 0)
    {
        throw std::invalid_argument{"Card Error - Either you don't have any cards | This one specific | No Cubes"};
    }
    // At this point Valid because no need to be(but to have it) on city thus passed the tests above
    if (!board.check_cure_discovered(c))
    {
        board[c]=board[c]-1;
    }
    else
    {
        board[c] = 0;
    }
    cards.remove(c);// Throw Card
    return *this;// Return
}