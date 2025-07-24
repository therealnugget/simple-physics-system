#include "textures.hpp"
#include "main.hpp"
#include "winMgr.hpp"
static const std::string imagesPath = "images/";
const std::string Textures::playerStaticRight = imagesPath + "Top_Down_Adventure_Pack_v.1.0/Char_Sprites/char_shielded_static_right.bmp";
SDL_Texture *Images::LoadTexture(std::string path) {
	return LoadTexture(path.c_str());
}
SDL_Texture *Images::LoadTexture(const char* path) {
	auto throwImgErr = [&](const char* problem) {
		ThrowError(5, "couldn't load ", problem, " with path \"", path, "\". Error: ", SDL_GetError());
	};
	SDL_Surface* loadedSurface;
	std::unordered_map<const char*, SDL_Surface *>::const_iterator iter = loadedSurfaces.find(path);
	if (iter == loadedSurfaces.end()) {
		loadedSurface = SDL_LoadBMP(path);
		loadedSurfaces.emplace(path, loadedSurface);
		if (!loadedSurface) {
		err:
			throwImgErr("surface");
			return nullptr;
		}
	}
	else loadedSurface = iter->second;
	SDL_Texture* newTexture;
	std::unordered_map<const char*, SDL_Texture*>::const_iterator texIter = loadedTexs.find(path);
	if (texIter == loadedTexs.end()) {
		newTexture = SDL_CreateTextureFromSurface(Main::renderer, loadedSurface);
		loadedTexs.emplace(path, newTexture);
		if (!newTexture) {
			throwImgErr("texture");
			return nullptr;
		}
	}
	else {
		newTexture = texIter->second;
	}
	//SDL_FreeSurface(loadedSurface);
	return newTexture;
}