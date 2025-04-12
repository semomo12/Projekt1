#include <iostream>
#include "system.h"
using namespace std;

int main() {
  
    // Debugging för minnesläckor
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    System system;
    system.start();

    return 0;

}
