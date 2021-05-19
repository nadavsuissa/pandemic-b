#include "Player.hpp"
namespace pandemic {
class Medic : public Player {

    public:
        Medic(Board& b, City c): Player(b, c, "Medic") {}
        
        Player& treat(City c) override;// Special Trait - treat
        virtual Player& fly_direct(City c) override;// Special Trait - fly_direct
        virtual Player& fly_charter(City c) override;// Special Trait - fly_charter
        virtual Player& drive(City c) override; // Special Trait - Drive
        virtual Player& fly_shuttle(City c) override;// Special Trait - fly_shuttle
        
};
}