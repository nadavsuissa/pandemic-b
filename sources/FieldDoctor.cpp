#include "FieldDoctor.hpp"
using namespace pandemic ;

Player& FieldDoctor::treat(City c) 
{
    // Can Treat Neighbor Without Throw --
    if ((city != c && !Board::check_if_connected(city,c))||board[c]==0) 
    {
        throw std::invalid_argument{"Either You have No Cubes or Location Requierment not met"};       
    }


    if(board.check_cure_discovered(c))
    {
        board[c]= 0;
    }
    else{
        board[c]=board[c]-1;
    }
    return *this;
}