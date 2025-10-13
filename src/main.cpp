#include <raylib.h>

int main()
{
	int screenWidth = 1280;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "A Class About Classes");
	SetTargetFPS(60);

	// TEXTURE LOADING {Do not touch}
	Texture2D africanWildDogImage = LoadTexture("resources/AfricanWildDog.png");
	Texture2D ArcanDogImage = LoadTexture("resources/ArcanDog.png");
	Texture2D mlpDogImage = LoadTexture("resources/mlpDog.png");
	Texture2D ThepixDogImage = LoadTexture("resources/ThepixDog.png");
	//////////////////////////////////////////////////////////////////

	// Dog Variables
	Vector2 dogPosition = { screenWidth / 2, screenHeight / 2 };

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		// TEXTURE DRAWING {Do not touch}
		Rectangle africanWildDogRect = { 0, 0, africanWildDogImage.width, africanWildDogImage.height };
		DrawTextureRec(africanWildDogImage, africanWildDogRect, dogPosition, WHITE);
		////////////////////////////////////////////////////////////////

		EndDrawing();
	}

	// TEXTURE UNLOADING {Do not touch}
	UnloadTexture(africanWildDogImage);
	UnloadTexture(ArcanDogImage);
	UnloadTexture(mlpDogImage);
	UnloadTexture(ThepixDogImage);

	CloseWindow();
}