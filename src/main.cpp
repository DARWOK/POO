/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "iostream"
#include "raylib.h"
#include <string>
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "GameObject.h"
#include "Player.h"
#include "Sidekick.h"
#include <vector>

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	std::cout << "Initializing game system " << std::endl;

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Juego con Objetos");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Array or list fo gameobjects in the scene
	std::vector<GameObject*> gameObjects;

	// Crear nuestro objeto de prueba
	GameObject* myObj = new GameObject({ 200,200 }, "myObj", LoadTexture("wabbit_alpha.png"));
	myObj->displayName = true;
	// push_back agrega un elemento al final del arreglo
	gameObjects.push_back(myObj); // cast implicito a GameObject*

	//El jugador
	Player* playerCharacter = new Player({ 0, 0 }, "Player1", LoadTexture("wabbit_alpha.png"));
	playerCharacter->speed = 200;
	// agregando el player pero con un cast explicito estatico
	// estatico quiere decir que se realiza en tiempo de compilación
	//gameObjects.push_back(playerCharacter);
	gameObjects.push_back(static_cast<GameObject*>(playerCharacter));

	Sidekick* sidekick = new Sidekick({ 500,0 }, "Sidekick", LoadTexture("sidekick.png"));
	sidekick->owner = playerCharacter;
	sidekick->displayName = true;
	sidekick->speed = 199.0f;
	gameObjects.push_back(sidekick);

	Sidekick* sidekick2 = new Sidekick({ 800, 600 }, "Bar", LoadTexture("sidekick.png"));
	sidekick2->owner = playerCharacter;
	sidekick2->displayName = true;
	sidekick2->speed = 190.0f;
	gameObjects.push_back(sidekick2);

	// Example of dynamic_cast
	for (GameObject* obj : gameObjects)
	{
		Player* p = dynamic_cast<Player*>(obj);
		if (p)
		{
			p->attack();
		}
		Sidekick* sk = dynamic_cast<Sidekick*>(obj);
		if (sk != nullptr)
		{
			sk->flee();
		}
	}
	
	// game loop a 60 fps
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// aquí van los update
		//myObj->update();
		//playerCharacter->update();
		//sidekick->update();

		//actualizar todos los gameobjects
		for (GameObject* obj : gameObjects)
		{
			obj->update();
		}
		for (GameObject* obj : gameObjects)
		{
			obj->draw();
		}

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(DARKBLUE);

		// draw some text using the default font
		DrawText("Ejemplo de Juego con GameObjects", 10,10,24, YELLOW);

		DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, 30, RED);
		DrawCircle(GetScreenWidth() * .25, GetScreenHeight() * .25f, 30, GREEN);

		// draw our texture to the screen
		/*for (size_t i = 0; i < 20; i++)
		{
			//DrawTexture(wabbit, 20+(i*32), 20+(i*32), WHITE);
		}*/
		
		//myObj->draw();
		//playerCharacter->draw();
		//sidekick->draw();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
