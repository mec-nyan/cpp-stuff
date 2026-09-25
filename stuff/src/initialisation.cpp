#include "initialisation.hpp"
#include "area.hpp"
#include <cstdint>
#include <print>
#include <string>

using namespace std::literals;

/*----------------*
 * Initialisation *
 *----------------*/

//! Initialising objects.

//! This example show a few ways (there's a lot more) of initialising objects.
//! No.  Not that kind of "objects".  An object in the sense of something referring
//! to some space in memory (i.e. what we poorly call "variables").
auto initialisation () -> void
{
    // ✨ PREFERRED ✨ //
    //
    // Use these unless you have a good reason not to (IMHO).
    //
    // The basic form is:
    //
    //    auto name { value };
    //    type name { value };
    //
    // The "{ ... }" this is called "universal" list initialisation. Use that
    // instead of the old:
    //
    //     auto name = value;
    //     type name = value;
    //
    // The "{ ... }" form avoids narrowing conversions.  You're welcome.

    // Here, we're using a User Defined Literal.
    // So we get a "string" instead of "const char*".
    auto me{ "I"s };

    // You can specify the type.  Both "auto name" and "type name" are useful in different
    // scenarios.
    std::string love{ "💖" };

    // With the list initialiser, the "=" is optional.  Avoid it.  (It can have surprising effects.)
    auto cpp = { "C++"s };

    // Traditional (inherited from C, allows narrowing conversions) can also be used:
    std::string excl = "!✨✨✨";

    std::println ( "{} {} {}{}", me, love, cpp, excl );

    {
        // NOTE:
        // When using "auto", sometimes it's what you want.  Sometimes you need to be a little bit
        // more specific. I.e.:

        // Not a string! The deduced type will be 'const char*' ...
        auto this_{ "This" };
        // If you want a string, you can use a "string_literal":
        auto gets{ "getting"s };
        // Or say the type explicitly:
        std::string comp{ "complicated" };

        // The same goes for other types:

        // OK if you want an 'int'.
        auto n{ 42 };
        // Otherwise, be specific with the type you need.
        int32_t m{ 42 };

        std::println ( "{} is {} a little bit {}", this_, gets, comp );
        std::println ( "The answer is {} (or is it {}?)", n, m );
    }

    // Beware of traditional initialisation ...
    // int bad_rad = 12.5; // Will compile, but now 'bad_rad' is '12' ...
    auto rad{ 12.5 };  // Use list initialisation instead.
    auto area{ get_circle_area ( rad ) };

    std::println ( "The area of a circle of radius {} is {:.2f}.", rad, area );

    // TODO: Move this example to "scope.cpp".
    // [scope/lifetime]
    {
        // Each block defines a new lexical scope.
        //
        // 'side' starts its life here.
        auto side{ 10 };
        // NOT the same 'area' than before!
        // This is a new variable!
        auto area{ get_square_area ( side ) };

        std::println ( "The area of a square of side {} is {:.2f}.", side, area );

        // side's lifetime ends here.
        // So this inner block's "area"'s lifetime.
    }

    // !!! "side" don't exist here!
    // !!! "area" is the other "area" ...
    // std::println ( "The area of a square of side {} is {:.2f}.", side, area );
}
