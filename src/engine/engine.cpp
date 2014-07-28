#include "../../inc/engine/engine.h"

Engine::Engine()
	: engine_state(STATE_SPLASH_SCREEN)
	, window(new sf::RenderWindow(sf::VideoMode(1024, 720), "RTS Test"))
	, world()
	, current_map(nullptr)
	, camera((float)window->getSize().x, (float)window->getSize().y)
{

}

Engine::~Engine()
{
	delete window;
	delete current_map;
}

void Engine::HandleEvents(sf::Event _evt)
{
	cout << "HandleEvents(): " << current_map  << endl;
	switch (engine_state)
	{
		case STATE_SPLASH_SCREEN:
			break;
		case STATE_MAIN_MENU:
			break;
		case STATE_START_PLAYING:
			break;
		case STATE_PLAYING:
			world.HandleEvents(_evt);
			break;
	}
}

void Engine::Update()
{
	cout << "Update(): " << current_map << endl;
	cout << "\tBefore Render: " << current_map << endl;
				if (current_map)current_map->Update();
				cout << "Done" << endl;
	switch (engine_state)
	{
		case STATE_SPLASH_SCREEN:
			engine_state = STATE_MAIN_MENU;
			break;
		case STATE_MAIN_MENU:
			engine_state = STATE_START_PLAYING;
			break;
		case STATE_START_PLAYING:
			current_map = world.LoadTilemap("test", "assets/maps/test1");
			//cout << "Current: " << current_map << endl;
			if (!current_map)
			{
 				cout << "Failed to load map: test_map" << endl;
 				window->close();
 			}
 			else
   				cout << "Tile map loaded" << endl;

 			camera.SetTrackMode(sftile::SF_TRACK_KEYS_PRESS);

   			engine_state = STATE_PLAYING;
			break;
		case STATE_PLAYING:
			world.Update();
			break;
	}
}

void Engine::Run()
{
	while (window->isOpen())
	{
		sf::Event evt;
		while (window->pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
				window->close();

			HandleEvents(evt);
		}

		Update();

		window->clear();

		cout << "Render()" << endl;
		switch (engine_state)
		{
			case STATE_SPLASH_SCREEN:
				break;
			case STATE_MAIN_MENU:
				break;
			case STATE_START_PLAYING:
				break;
			case STATE_PLAYING:
				cout << "\tBefore Render: " << current_map << endl;
				current_map->Render(*window);
				cout << "\t\tAfter Test" << endl;
				world.Render(*window);
				cout << "\tAfter Render" << current_map << endl;
				break;
		}

		window->display();

	}
}