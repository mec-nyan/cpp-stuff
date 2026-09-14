export module Beans;

import std;

export auto love_beans ()
{
    using namespace std;
    println ( "I love beans!" );
    return 1;
}

export class Beans
{
  public:
    Beans ()
    {
    }
    auto x42 ()
    {
        return 42;
    }
};
