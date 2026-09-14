///////////////
// stuff.cpp //
///////////////

import std;

using namespace std;

// (C++20) [modules] You can import your modules line this:
import Beans;

// [Scope/lifetime] This binding is global (avoid).
constexpr auto pi{ 3.1416 };

// [functions] Declare a function ([qualifiers] return_value name([args]);).
constexpr double get_circle_area ( double radius );

constexpr double get_square_area ( double side );

// You can declare and define at the same time:
auto print_point ( int x, int y )
{
    println ( "Point at ({}, {})", x, y );
}

int main ()
{
    ////////////////////
    // Initialisation //
    ////////////////////

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

    // [modules] use your imported stuff like this:
    love_beans();

    auto b = Beans();
    println ( "(Beans)::{} is {}", b.x42(), b.x42() );

    return 0;
}

//

// [functions] Define a function:
constexpr double get_circle_area ( double radius )
{
    return radius * 2 * pi;
}

constexpr double get_square_area ( double side )
{
    return side * side;
}
