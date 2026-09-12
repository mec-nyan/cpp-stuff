// stuff.cpp
#include <print>
using namespace std;

// [Scope/lifetime] This binding is global (avoid).
constexpr auto pi{ 3.1416 };

// [functions] Declare a function (return_value name(args);).
constexpr double get_circle_area ( float radius );

int main ()
{
    // [initialisation]
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
    return 0;
}

//

// [functions] Define a function:
constexpr double get_circle_area ( float radius )
{
    return radius * 2 * pi;
}
