#pragma once
#include <map>
#include <string>
#include "Texture.h"
using std::map;
using std::string;

class Assets
{
public:
	static std::map<std::string, Texture> textures;

	//Load tex from file

	static Texture loadTexture(Renderer& renderer, const string& filename, const string& name);

	//Retrieves a stored texture
	static Texture& getTexture(const std::string& name);

	//De-allocates all load ressources

	static void clear();

private:
	Assets(){}

	//Single tex loading from file
	static Texture loadTextureFromFile(Renderer& renderer, const string& filename);

};

