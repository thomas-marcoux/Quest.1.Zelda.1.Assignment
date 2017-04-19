#include <iostream>
#include "AssetLibrary.h"
#include "GraphicsDevice.h"
#include "Texture.h"

//Make texture object from object file
bool AssetLibrary::AddAsset(std::string name, std::string path)
{
	std::shared_ptr<Texture>	t(new Texture());

	if (!t->load(gDevice->getRenderer(), path))
		return false;
	library[name] = t;
	return true;
}

//Return an instance of the requested Texture if it is in the library, NULL otherwise.
std::shared_ptr<Texture> AssetLibrary::Search(std::string name)
{
	std::map<std::string, std::shared_ptr<Texture>>::iterator it = library.find(name);
	return (it == library.end()) ? NULL : it->second;
}