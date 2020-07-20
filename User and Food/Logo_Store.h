#pragma once
// АНІМОВАНИЙ ЛОГОТИП\ЗАСТАВКА

using namespace std;

void Space(size_t size);
bool ShowLogo(const size_t size);
void ShowAnimationLogo();

void ShowLogoStore(size_t sleep, size_t colors, size_t colorText);					// Кольорове з назвою магазину
void ShowLogoStoreBlackAndWhite(size_t sleep);										// Чорно - біле
void ShowLogoBasket();																// Лого корзини
void Loading(size_t time);