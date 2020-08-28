#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Reticle
{
public:
	Reticle() = default;
	Reticle(float xPos, float yPos, float xVel, float yVel, int r, int g, int b);
	void Draw(Graphics& gfx) const;
	void Update(Keyboard& kbd);
	bool WallCollision(Graphics& gfx);
	bool Collision(float x, float y) const;
	float GetXPos() const;
	float GetYPos() const;
	void SetR(int r);
private:
	float mXPos;
	float mYPos;
	float xVel;
	float yVel;
	static constexpr int width = 6;
	static constexpr int Height = 6;
	int mR;
	int mG;
	int mB;
};