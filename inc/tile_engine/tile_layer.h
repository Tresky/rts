////////////////////////////////////////////////////////////
/// SfTileEngine: C++/SFML Tile Engine
/// Copyright (C) 2014 Tyler Petresky
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////

#ifndef SF_TILE_LAYER_H
#define SF_TILE_LAYER_H

#include <iostream>
	using std::cout;
	using std::endl;
#include <string>
	using std::string;
#include <vector>
	using std::vector;

#include <SFML/Graphics.hpp>

#include "layer.h"

/// Engine namespace
namespace sftile
{

/// Private engine namespace
namespace priv
{
class TilemapLoader;

class TileLayer : public Layer
{
friend class TilemapLoader;
public:
	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	/// Creates an empty tile layer object.
	///
	////////////////////////////////////////////////////////////
	explicit TileLayer();


	////////////////////////////////////////////////////////////
	/// \brief Copy constructor
	///
	/// Copies an existing tile layer.
	///
	////////////////////////////////////////////////////////////
	TileLayer(const TileLayer& _copy);


	////////////////////////////////////////////////////////////
	/// \brief Move constructor
	///
	/// Move an existing tile layer.
	///
	////////////////////////////////////////////////////////////
	TileLayer(TileLayer&& _copy);


	////////////////////////////////////////////////////////////
	/// \brief Assignment operator
	///
	/// Copies an existing tile layer.
	///
	////////////////////////////////////////////////////////////
	TileLayer& operator=(const TileLayer& _copy);


	////////////////////////////////////////////////////////////
	/// \brief Move assignment operator
	///
	/// Moves an existing tile layer.
	///
	////////////////////////////////////////////////////////////
	TileLayer& operator=(TileLayer&& _copy);


	////////////////////////////////////////////////////////////
	/// \brief Gets the tile GID at a specific location in the
	///        layer.
	///
	/// \param _x X coordinate of the tile
	/// \param _y Y coordinate of the tile
	/// \return GID of the tile in question
	///
	////////////////////////////////////////////////////////////
	int GetTileGID(const int _x, const int _y);


	////////////////////////////////////////////////////////////
	/// \brief Returns the name of the layer.
	///
	/// \return String name of the layer
	///
	////////////////////////////////////////////////////////////
	string GetName();


	////////////////////////////////////////////////////////////
	/// \brief Returns the type of the layer.
	///
	/// \return String type of the layer
	///
	////////////////////////////////////////////////////////////
	string GetType();


	////////////////////////////////////////////////////////////
	/// \brief Returns the size of the layer.
	///
	/// \return Dimensions of the layer.
	///
	////////////////////////////////////////////////////////////
	sf::Vector2i GetDimensions();

protected:
	/// Name of layer
	string name;


	/// Vector of the tile GIDs in the layer
	vector< vector<int> > tile_gids;


	/// Tile dimensions in pixels
	sf::Vector2i layer_dimensions;

};

}

}

#endif /// SF_TILE_LAYER_H