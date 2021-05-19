
#include "Board.hpp"
#include <list>
#include <algorithm>
using namespace pandemic;



bool Board::check_if_station(City c) // Changed
{
    bool found = (std::find(stations.begin(), stations.end(), c) != stations.end());
    return found;
}
bool Board::check_cure_discovered(Color c) // Changed
{
    bool found = (std::find(treateddiseases.begin(), treateddiseases.end(), c) != treateddiseases.end());
    return found;
}
void Board::add_station(City c)
{
    if (!check_if_station(c)) // If Doesn't exist 
    {
        stations.push_back(c); // Add!
    }
}

Color Board::check_color(City c)
{
    return citytocolor.at(c); // Simple Return
}

void Board::set_cured_diseases(Color c) // Changed
{
    treateddiseases.push_back(c);
}

bool Board::check_cure_discovered(City c) // Changed
{
    bool found = (std::find(treateddiseases.begin(), treateddiseases.end(), check_color(c)) != treateddiseases.end());
    return found;
}



void Board::remove_cures()
{
    treateddiseases.clear(); // Clear the List...
}
std::map<pandemic::City, std::set<pandemic::City>> Board::graphcity = // Somewhat of Graph of Connected Cities, Based of EREL CITY FILE
    {
        {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing, {Shanghai, Seoul}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg, {Kinshasa, Khartoum}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
        {Milan, {Essen, Paris, Istanbul}},
        {Montreal, {Chicago, Washington, NewYork}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Karachi, Delhi, Chennai}},
        {NewYork, {Montreal, Washington, London, Madrid}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago, {Lima}},
        {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, Manila, LosAngeles}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
        {Washington, {Atlanta, NewYork, Montreal, Miami}}
        };
bool Board::is_clean()
{   // Needed bool for Tidy
    bool helpbool = true;
    for (auto &disobj : diseaseLevels) // Iterate Map and if Meet more than one disease - False....
    {
        if (disobj.second != 0)
        {
            helpbool = false;
        }
    }
    return helpbool;
}
bool Board::check_if_connected(City a, City b) // Check if Connection is Valid beween Cities 
{
    bool helpbool = false; // Needed for tidy
    if (graphcity.at(a).find(b) != graphcity.at(a).end())
    {
        helpbool = true;
    }

    return helpbool;
}
// [] override
int &Board::operator[](City c)
{
    return diseaseLevels[c];
}
// OutPut Override

std::ostream &pandemic::operator<<(std::ostream &out, const Board &b)
{
    out << "The Board:" << std::endl;

    out << "Cubes on Each City:" << std::endl;

    for (auto const &levanddis : b.diseaseLevels)
    {
        out << citystring(levanddis.first) << " Has " << levanddis.second << " Cubes" << std::endl;
    }

    out << "Colors With Cure : " << std::endl;

    for (auto const &c : b.treateddiseases)
    {
        out << colortostring(c) << std::endl;
    }

    out << "Stations : " << std::endl;

    for (auto const &city : b.stations)
    {
        out << citystring(city) << std::endl;
    }

    return out;
}


