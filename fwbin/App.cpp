#include "App.h"
#include "RulesListGui.h"

IMPLEMENT_APP(App) ;
App::App()
{
    //ctor
}

App::~App()
{
    //dtor
}
bool App::OnInit()
{
	RulesListGui * gui = new RulesListGui(NULL);
	gui->Show(true);
    return true ;
}
