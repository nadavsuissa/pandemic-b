#include "OperationsExpert.hpp"


using namespace pandemic;

Player &OperationsExpert::build() // Has Ability To Build Without Throw at ANY city
{
    board.add_station(city);
    return *this;
}