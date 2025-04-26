#include "app/app.h"
#include "app/win/WinApp.h"
// Main code
int main(int, char**)
{
    
    GRAPHT::WinApp* app = new GRAPHT::WinApp(GRAPHT::OPENGL);
    
    // Main loop
    app->launch();



    return 0;
}
