#include "system.hpp"

int main()
{
    System system(IN_GAME);
    system.make_map();
    system.run();
}