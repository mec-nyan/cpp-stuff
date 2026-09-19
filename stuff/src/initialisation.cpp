#include "initialisation.hpp"
#include "area.hpp"
#include <print>
#include <string>
using namespace std;

////////////////////
// Initialisation //
////////////////////

auto initialisation () -> void
{

    // Traditional (Inherited from C. Allows narrowing conversions):
    string me = "I";
    // Universal "list" initialisation (prefer this one when possible):
    string love{ "💖" };
    // "=" is optional in the list initialisation (Don't use it...).
    string cpp = { "C++" };
    println ( "{} {} {}!", me, love, cpp );

    // [initialisation]
    // int rad = 12.5; // Oops! rad is now "12" (probably not what you wanted).
    auto rad{ 12.5 }; // Use list initialisation instead.
    auto area{ get_circle_area ( rad ) };

    println ( "The area of a circle of radius {} is {:.2f}.", rad, area );

    // [scope/lifetime]
    {
        // 'side' starts its life here.
        auto side{ 10 };
        // NOT the same 'area' than before!
        // This is a new variable!
        auto area{ get_square_area ( side ) };

        println ( "The area of a square of side {} is {:.2f}.", side, area );

        // side's liftime ends here.
        // So this inner block's "area"'s lifetime.
    }

    // !!! "side" don't exist here!
    // !!! "area" is the other "area" ...
    // println ( "The area of a square of side {} is {:.2f}.", side, area );
}
