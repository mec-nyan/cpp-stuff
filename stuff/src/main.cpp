///////////////
// stuff.cpp //
///////////////

#include <print>

#include "area.hpp"
#include "hello.hpp"
#include "initialisation.hpp"
#include "mutability.hpp"

using namespace std;

int main ()
{
    // Each example is on its own header/implementation package.
    // Call a package's functions to see if they're working and compiling properly.

    // How to initialise variables, constants, etc.
    initialisation();

    // Mutability
    mutability();

    // Use of "#include"d function/symbol:
    auto x = 21;
    println ( "{} + {} is {}.", x, x, sum_some ( x, x ) );

    return 0;
}
