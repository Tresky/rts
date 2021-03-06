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

#include "../../inc/tile_engine/object_layer.h"

/// Library namespace
namespace sftile
{

/// Private library namespace
namespace priv
{

////////////////////////////////////////////////////////////
ObjectLayer::ObjectLayer()
  : objects()
  , layer_dimensions(-1, -1)
{}


////////////////////////////////////////////////////////////
ObjectLayer::ObjectLayer(const ObjectLayer& _copy)
  : objects(_copy.objects)
  , layer_dimensions(_copy.layer_dimensions)
{}


////////////////////////////////////////////////////////////
ObjectLayer& ObjectLayer::operator=(const ObjectLayer& _copy)
{
  if (this != &_copy)
  {
    ObjectLayer temp(_copy);

    std::swap(objects, temp.objects);
    std::swap(layer_dimensions, temp.layer_dimensions);
  }

  return *this;
}


////////////////////////////////////////////////////////////
Object* ObjectLayer::GetObject(unsigned int _index)
{
  return &objects.at(_index);
}


////////////////////////////////////////////////////////////
int ObjectLayer::GetNumObjects()
{
	return objects.size();
}


////////////////////////////////////////////////////////////
string ObjectLayer::GetName()
{
	return name;
}


////////////////////////////////////////////////////////////
string ObjectLayer::GetType()
{
	return "object";
}


////////////////////////////////////////////////////////////
sf::Vector2i ObjectLayer::GetDimensions()
{
	return layer_dimensions;
}

}

}