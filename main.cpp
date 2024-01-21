#include <iostream>
#include "CasualLibrary.hpp"
#include "offsets.h"


int main()
{
	Memory::External memory = Memory::External("Mir4G.exe",true);

	Address clientAddr = memory.getModule("Mir4G.exe");

	Address GNamesAddr = clientAddr.get() + offsets::GNames;
	Address GObjectsAddr = clientAddr.get() + offsets::GObjects;
	Address GWorldAddr = clientAddr.get() + offsets::GWorld;

	Address vSyncAdd = memory.getAddress(GObjectsAddr, { 0x90 });
	int32_t screen = memory.read<int32_t>(vSyncAdd);


	//UWorld* GWorld = UWorld::GetInstance();
	//if ((!GWorld))
	//	return;
	// 
	//PersistentLevel* PerLevel = GWorld->m_Persistent;
	//if ((!PerLevel))
	//	return;

	//GameInstance* gInstance = GWorld->m_pGInstance;
	//if ((!gInstance))
	//	return;

	//ULocalPlayer* getLocalPlayer = gInstance->m_pULocal;
	//if ((!getLocalPlayer))
	//	return;

	//PlayerController* getPlayerController = getLocalPlayer->p_Local->m_pCTRL;
	//if ((!getPlayerController))
	//	return;

	//CameraManager* getCameraManager = getPlayerController->m_CameraMgr;
	//if ((!getCameraManager))
	//	return;

	//gWorldPtr->m_pGInstance->m_pULocal->p_Local->m_pViewport->p_Scr->width;

	std::cout << screen << std::endl;

	std::cin.get();
}