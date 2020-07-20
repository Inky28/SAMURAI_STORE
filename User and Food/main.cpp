// SAMURAI STORE
#include <Windows.h>

#include "Database.h"
#include "Logo_Store.h"
#include "Color.h"

int main()
{
	for (size_t i = 0; i < 7; i++)
	{
		ShowLogoStore(500, FuchsiaFore, LimeFore);
		ShowLogoStore(500, LimeFore, FuchsiaFore);
		//ShowLogoStore(500, BlueFore, AquaFore);
		//ShowLogoStore(500, AquaFore, BlueFore);
	}

	//ShowLogoStoreBlackAndWhite(3500);  // ×îðíîá³ëå ëîãî

	Database data;
	data.Enter();

	ShowAnimationLogo();  // ÏÎÊÀÇ "ÀÍ²ÌÎÂÀÍÎÃÎ" ËÎÃÎÒÈÏÀ

	return 0;
}