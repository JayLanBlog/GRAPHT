#include "app/app.h"
#include "app/win/WinApp.h"
#include "module/loader/MaterialManager.h"
// Main code
int main(int, char**)
{
    GRAPHT::MaterailManager * manan = GRAPHT::MaterailManager::getManager();


    GRAPHT::WinApp* app = new GRAPHT::WinApp(GRAPHT::OPENGL);
    
    // Main loop
    app->launch();



    return 0;
}
