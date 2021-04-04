#include "GameWindows.h"
#include"GGraphic.h"
#include "GInput.h"
#include"GameStateManager.h"
#include <dinput.h>
#include "physic.h"

//	use int main if you want to have a console to print out message
int main()
//	use WinMain if you don't want the console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{


	GameWindows* gWin = GameWindows::getInstance();
	gWin->init();
	GGraphic* gGraphic = GGraphic::getInstance();
	GInput* gInput = GInput::getInstance();
	GameStateManager* gameStateManager = GameStateManager::getInstance();


	while (gWin->isWindowsRunning())
	{
		gInput->update();
		gameStateManager->update();
		gGraphic->begin();
		gameStateManager->draw();
		gGraphic->end();
		
	}

	gameStateManager->releaseInstance();
	gWin->releaseInstance();
	gGraphic->releaseInstance();
	gInput->releaseInstance();
	

	return 0;
}
//--------------------------------------------------------------------

