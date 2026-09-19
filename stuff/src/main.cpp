///////////////
// stuff.cpp //
///////////////

#include <print>

#include "area.hpp"
#include "hello.hpp"
#include "initialisation.hpp"
#include "point.hpp"

using namespace std;

int main ()
{
    // Each example is on its own header/implementation package.
    // Call a package's functions to see if they're working and compiling properly.
    initialisation();

    /////////////////
    // Mutability. //
    /////////////////

    // These are mutable:
    auto x{ 0 };
    auto y{ 1 };

    // This is alright:
    x = 42;               // BTW this is called assignment iydk.
    print_point ( x, y ); // "Point at (42, 1)"

    // You can create constants in (at least) two ways:
    {
        // "I promise I won't change it" style.
        const auto x{ 17 };
        // "Compile time" enforced style (use this whenever possible).
        constexpr auto y{ 33 };

        // x = 42;  Wrong! You cannot change this binding!
        // y = 123;  Wrong! You cannot change this binding!

        print_point ( x, y );
    }

    // [#include] can still be used:

    x = 21;
    println ( "{} + {} is {}.", x, x, sum_some ( x, x ) );

    return 0;
}
