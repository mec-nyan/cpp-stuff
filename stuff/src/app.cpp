#include "app.hpp"
#include <print>

// TODO: implement menu.
auto menu ()
{
    std::println ( "Menu ..." );
}

// TODO: implement usage.
auto usage ()
{
    std::println ( "Usage: ..." );
}

// TODO: implement "not implemented".
auto not_implemented ()
{
    std::println ( "Not implemented ..." );
}

namespace app
{

auto App::run ( int argc, char *argv[] ) -> int
{
    // Each example is on its own header/implementation package.
    // Call a package's functions to see if they're working and compiling properly.

    if (argc == 1)
    {
        menu();
        return 0;
    }

    if (argc != 2)
    {
        usage();
        return 1;
    }

    std::string_view arg{ argv[ 1 ] };

    if (arg == "initialisation")
        initialisation();
    else if (arg == "mutability")
        mutability();
    else
        not_implemented();

    return 0;
}
}  // namespace app
