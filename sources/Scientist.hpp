#include "Player.hpp"
namespace pandemic {
class Scientist : public Player {
    private:
        int number;
    public:
        Scientist(Board& b, City c, int n): Player(b, c, "Scientist") // Inherited From Player - Special Trait Can Discover Cure - N Turns
        {
            number = n; // The Special Trait
        }
        Player& discover_cure(Color c) override;
};
}