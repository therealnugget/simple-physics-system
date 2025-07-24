#pragma once
#include "main.hpp"
#include "physics.hpp"
#include <SDL.h>
//static
class Player : public Behaviour {
private:
	static float accel, speed;
public:
	static void Init();
	static void Finalize();
	static void Update();
	friend class Main;
};