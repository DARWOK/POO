#pragma once
#include "raylib.h"
#include "string"

class GameObject
{
public:
	Vector2 position;
	std::string name;
	/// imgaen del objeto
	Texture texture;
	bool displayName = false;

	// constructor
	GameObject(Vector2 pos, std::string _name, Texture tex) :
		position(pos), name(_name), texture(texture) {}

	// update position
	virtual void update();
	// render object
	void draw();
};

