#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;


TEST_CASE("OperationsExpert")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    OperationsExpert player {board,City::NewYork}; //can build withow card 
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.build()); 
    CHECK_NOTHROW(player.drive(Montreal));
    CHECK_NOTHROW(player.treat(Montreal));
    // CHECK_THROWS(player.treat(Montreal)); //Montreal =0 now
    CHECK_NOTHROW(player.fly_direct(London));
    CHECK_NOTHROW(player.drive(Paris));
    CHECK_NOTHROW(player.build()); 
}

TEST_CASE("Dispatcher")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    Dispatcher player {board,City::NewYork}; //when he is in a City with research lab can fly where he wants
    player.take_card(Montreal);
    player.take_card(HongKong);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.drive(Montreal));
    CHECK_NOTHROW(player.build()); 
    CHECK_NOTHROW(player.fly_direct(HongKong));
    CHECK_NOTHROW(player.build()); 
    CHECK_NOTHROW(player.fly_direct(London));
    CHECK_NOTHROW(player.treat(London));
    CHECK_NOTHROW(player.treat(London));

}


TEST_CASE("Scientist")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    Scientist player {board,City::NewYork,4}; //can discover_cure with only n cards 
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.drive(Montreal));
    CHECK_NOTHROW(player.build()); 
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    // CHECK_THROWS(player.discover_cure(Color::Blue)); //can discover_cure only once

}

TEST_CASE("Researcher")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    Researcher player {board,City::NewYork}; //can discover_cure without lab
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.drive(Montreal)); 
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    // CHECK_THROWS(player.discover_cure(Color::Blue)); //can discover_cure only once

}

TEST_CASE("Medic")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=3;
    board[City::London]=2;

    Medic player {board,City::NewYork}; //when using treat lowers all the cubs
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.drive(Montreal));
    CHECK_NOTHROW(player.treat(Montreal)); 
}

TEST_CASE("Virologist")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    FieldDoctor player {board,City::NewYork}; //can treat all Cites if he has their card
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.treat(Montreal));
    CHECK_NOTHROW(player.treat(London));
    CHECK_NOTHROW(player.treat(Delhi));
}

TEST_CASE("FieldDoctor")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    FieldDoctor player {board,City::NewYork}; //can treat neighbour CIty
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.treat(Montreal));
    CHECK_NOTHROW(player.treat(London));
    CHECK_NOTHROW(player.treat(London));
    CHECK_NOTHROW(player.fly_direct(Delhi));
}

TEST_CASE("GeneSplicer")
{
    Board board;
    board[City::NewYork]=3;
    board[City::Montreal]=1;
    board[City::London]=2;

    GeneSplicer player {board,City::NewYork}; //can discover_cure with 5 cards no mater the color
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(NewYork);
    player.take_card(NewYork);
    player.take_card(Delhi);
    player.take_card(HongKong);

    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.discover_cure(Color::Blue)); //Montreal =0 now
    CHECK_NOTHROW(player.fly_direct(Delhi));
}