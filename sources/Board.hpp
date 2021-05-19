#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
#include <list>

namespace pandemic
{
    class Board
    {
    private:
        static std::map<pandemic::City, std::set<pandemic::City>> graphcity;
            // Basic and needed map - map at city will output color...
        std::map<City, Color> citytocolor =
            {
                {Algiers, Color::Black},
                {Atlanta, Color::Blue},
                {Baghdad, Color::Black},
                {Bangkok, Color::Red},
                {Beijing, Color::Red},
                {Bogota, Color::Yellow},
                {BuenosAires, Color::Yellow},
                {Cairo, Color::Black},
                {Chennai, Color::Black},
                {Chicago, Color::Blue},
                {Delhi, Color::Black},
                {Essen, Color::Blue},
                {HoChiMinhCity, Color::Red},
                {HongKong, Color::Red},
                {Istanbul, Color::Black},
                {Jakarta, Color::Red},
                {Johannesburg, Color::Yellow},
                {Karachi, Color::Black},
                {Khartoum, Color::Yellow},
                {Kinshasa, Color::Yellow},
                {Kolkata, Color::Black},
                {Lagos, Color::Yellow},
                {Lima, Color::Yellow},
                {London, Color::Blue},
                {LosAngeles, Color::Yellow},
                {Madrid, Color::Blue},
                {Manila, Color::Red},
                {MexicoCity, Color::Yellow},
                {Miami, Color::Yellow},
                {Milan, Color::Blue},
                {Montreal, Color::Blue},
                {Moscow, Color::Black},
                {Mumbai, Color::Black},
                {NewYork, Color::Blue},
                {Osaka, Color::Red},
                {Paris, Color::Blue},
                {Riyadh, Color::Black},
                {SanFrancisco,Color::Blue},
                {Santiago, Color::Yellow},
                {SaoPaulo, Color::Yellow},
                {Seoul, Color::Red},
                {Shanghai, Color::Red},
                {StPetersburg, Color::Blue},
                {Sydney, Color::Red},
                {Taipei, Color::Red},
                {Tehran, Color::Black},
                {Tokyo, Color::Red},
                {Washington, Color::Blue}
            };
            // Maps And Lists 
        std::map<pandemic::City, int> diseaseLevels; // Map of City and It's Disease Levels 
        std::list<pandemic::City> stations; // Changed this to a list ! 
        std::list<pandemic::Color> treateddiseases; // Changed this to a list !
    public:
        Board() {}
        Color check_color(City c);// GET COLOR OF CITY c 
        
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
        // Void
        void add_station(City c);// ADD STATION
        void remove_cures();
        void set_cured_diseases(Color c);
        bool check_if_station(City c); // If has STATION
// Bool
        bool check_cure_discovered(City c); // Bool if Cure Discoverd In SPECIFIC city
        static bool check_if_connected(City a, City b); // If Two Cities are Connected
        bool check_cure_discovered(Color c); // Like Above Just Per Color
        bool is_clean(); // Check if Board is clean of disease
        
        int &operator[](City c);
    };
}