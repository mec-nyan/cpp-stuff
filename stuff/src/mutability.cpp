#include "mutability.hpp"
#include "point.hpp"

/////////////////
// Mutability. //
/////////////////

// Variables are mutable by default.
// You can create constants with either `const` or `constexpr` (Not the same thing!).
auto mutability () -> void
{
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
}
