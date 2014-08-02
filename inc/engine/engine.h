/*
 * engine.h
 *
 * Author: Tyler Petresky
 * Date: 
 */

#include <iostream>
	using std::cout;
 	using std::endl;

#include <SFML/Graphics.hpp>

#include "../tile_engine/world.h"
#include "../tile_engine/tilemap.h"
#include "../tile_engine/smart_camera.h"

class Engine
{
public:
	explicit Engine();

	~Engine();

	void HandleEvents(sf::Event _evt);

	void Update();

	void Run();

private:
	enum {
		STATE_SPLASH_SCREEN = 0,
		STATE_MAIN_MENU,
		STATE_START_PLAYING,
		STATE_PLAYING
	} engine_state;

	sf::RenderWindow* window;

	sftile::World world;

	sftile::Tilemap* current_map;

	sftile::SmartCamera* camera;
};