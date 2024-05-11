#include "system.hpp"

// void start_menu()
// {
//     while (window.isOpen()){

//     }
// }
int main()
{
    System system(IN_GAME);
    system.make_map();
    system.run();
}