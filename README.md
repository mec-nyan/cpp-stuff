# C++ Stuff

Kind of a modern **C++** tutorial.

[![cpp](https://img.shields.io/badge/C%2B%2B-%3E%3D20-blue?style=for-the-badge)]()
[![meson](https://img.shields.io/badge/Meson-1.10.1-mediumpurple?style=for-the-badge)]()


> [!NOTE]
> _You may be thinking if that means a "(modern C++) tutorial" or a "modern (C++ tutorial)".
> Hopefully both ... Be my guest, take a look and decide for yourself._

> [!IMPORTANT]
> Early stages of development. _(There's not much here yet. It also may not work properly.)_

>[!NOTE]
> **AI Disclosure:**
> None of the contents of this repo was generated with **AI** (not that there's anything wrong with that).


## Intention

This repo tries to be an _example oriented_ C++ (>=20) tutorial.  By "example(s)" I mean **code**.
I'll try to include as many features as I can.  Yet C++ is big.  But you don't need to know
everything to be able to write good C++ programs.

I also intent to keep the examples as "up to date" as possible, within reason (i.e. I've tried to
use C++20 modules for, well, modularizing the examples but the tools are not there yet (especially
trying to get **clangd** to work well with modules is not an easy task (and considering that
tutorials are to be consumed mostly by beginners I think that writing and compiling should be
straightforward (that's why I continue to use "#include" (and yes I like eLisp))))).


## Structure

Each example should be on its own module/package (I'll use a header-implementation pair for each
with a few **std::exception**s) (look for ("xxx.hpp", "xxx.cpp") pairs) and then imported in
**main.cpp** with (hopefully) some useful comments.  That way we can keep examples short and clean.


## Usage

Clone the repo:

```sh
~$ git clone https://github.com/mec-nyan/cpp-stuff.git
~$ cd cpp-stuff
```

Go to `stuff` and open `main.cpp` in your editor of choice.
Find the thing you're interested in.  Read the comments ...
Find the definitions, hover for documentation, etc.

```sh
~ $ cd stuff
~/stuf $ emacs src/main.cpp
```

Make changes, try things out.  You can rebuild afterwards with `meson`.
If you add files, don't forget to reconfigure.  (You may need to delete the `build/` directory.)

```sh
~/stuff $ meson compile -C stuff
```

You can switch to your favourite tool (GNU make, CMake, etc) if you want.
Or simply use the command line.

---

The examples have been compiled with GCC 16 and the `-std=c++23` flag (for `<print>`).

