#include "initialisation.hpp"
#include "area.hpp"
#include <cstdint>
#include <print>
#include <string>
using namespace std;

////////////////////
// Initialisation //
////////////////////

// There are lots of ways to initialise a variable (or a constant) in C++.
// Prefer the universal, list initialisation (x = {...}).
auto initialisation () -> void
{
    // PREFERRED //
    // Universal "list" initialisation (prefer this one when possible):
    // The basic form is `type name { initialiser }`.
    string love{ "💖" };

    // "=" is optional in the list initialisation (Don't use it...).
    string cpp = { "C++" };

    {
        // NOTEs:
        // You can use `auto` to let the compiler deduce the variable's type.
        // Be aware that sometimes it won't be what you expect ...
        auto foo{ "foo" };            // Not a string! The deduced type will be 'const char*' ...
        auto bar{ string ( "bar" ) }; // OK, but what's the point.  You had to specify the type anyway.
        auto n{ 42 };                 // OK if you want an 'int'.
        int32_t m{ 42 };              // Otherwise, be specific with the type you need.

        println ( "{}, {}, {}, {}", foo, bar, n, m );
    }

    // Traditional (inherited from C, allows narrowing conversions) can also be used:
    string me = "I";

    println ( "{} {} {}!", me, love, cpp );

    // Beware of traditional initialisation ...
    int bad_rad = 12.5; // Will compile, but now 'bad_rad' is '12' ...
    auto rad{ 12.5 };   // Use list initialisation instead.
    auto area{ get_circle_area ( rad ) };

    println ( "The area of a circle of radius {} is {:.2f}.", rad, area );

    // [scope/lifetime]
    {
        // Each block defines a new lexical scope.
        //
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
