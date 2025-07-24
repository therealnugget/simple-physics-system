#pragma once
#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
class Images {
private:
	static std::unordered_map<const char*, SDL_Texture*> loadedTexs;
	static std::unordered_map<const char*, SDL_Surface*> loadedSurfaces;
	template<typename ValueType = SDL_Texture *>
	static inline void FinalizeMap(std::unordered_map<const char *, ValueType> map) {
		std::for_each(map.begin(), map.end(), [](std::pair<const char *, ValueType> pair) {
			free(pair.second);
			});
	}
public:
	static SDL_Texture* LoadTexture(std::string path);
	static SDL_Texture* LoadTexture(const char* path);
	static inline void Finalize() {
		FinalizeMap<SDL_Texture*>(loadedTexs);
		FinalizeMap<SDL_Surface*>(loadedSurfaces);
	}
};
class Textures {
public:
	const static std::string playerStaticRight;
};