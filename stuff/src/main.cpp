///////////////
// stuff.cpp //
///////////////

#include "app.hpp"

auto main ( int argc, char *argv[] ) -> int
{
    auto p{ app::App() };

    return p.run ( argc, argv );
}
