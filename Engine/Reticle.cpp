#include "Reticle.h"

Reticle::Reticle(float xPos, float yPos, float xVel, float yVel, int r, int g, int b)
	:
	mXPos(xPos),
	mYPos(yPos),
    xVel(xVel),
    yVel(yVel),
	mR(r),
	mG(g),
	mB(b)
{}

void Reticle::Draw(Graphics& gfx) const
{
    gfx.PutPixel(mXPos - 6, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 5, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 4, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 3, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos - 5, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos - 4, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos - 3, mR, mG, mB);

    gfx.PutPixel(mXPos + 6, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 5, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 4, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 3, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos + 5, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos + 4, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos + 3, mR, mG, mB);

    gfx.PutPixel(mXPos - 6, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 5, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 4, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 3, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos + 6, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos + 5, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos + 4, mR, mG, mB);
    gfx.PutPixel(mXPos - 6, mYPos + 3, mR, mG, mB);

    gfx.PutPixel(mXPos + 6, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 5, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 4, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 3, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos - 6, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos - 5, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos - 4, mR, mG, mB);
    gfx.PutPixel(mXPos + 6, mYPos - 3, mR, mG, mB);
}

void Reticle::Update(Keyboard& kbd)
{
    if (kbd.KeyIsPressed(VK_LEFT))
    {
        xVel -= 0.001;
    }
    else if (kbd.KeyIsPressed(VK_RIGHT))
    {
        xVel += 0.001;
    }

    if (kbd.KeyIsPressed(VK_UP))
    {
        yVel -= 0.001;
    }
    else if (kbd.KeyIsPressed(VK_DOWN))
    {
        yVel += 0.001;
    }

    mXPos += xVel;
    mYPos += yVel;
}

bool Reticle::WallCollision(Graphics& gfx)
{
    if (mXPos + 6 >= gfx.ScreenWidth - 1)
    {
        mXPos = gfx.ScreenWidth - 7;
        xVel = 0.0f;

        return true;
    }

    if (mXPos - 6 <= 0)
    {
        mXPos = 6;
        xVel = 0.0f;

        return true;
    }

    if (mYPos + 6 >= gfx.ScreenHeight - 1)
    {
        mYPos = gfx.ScreenHeight - 7;
        yVel = 0.0f;

        return true;
    }

    if (mYPos - 6 <= 0)
    {
        mYPos = 6;
        yVel = 0.0f;

        return true;
    }

    return false;
}

bool Reticle::Collision(float x, float y) const
{
    float leftMobile = mXPos - 6;
    float rightMobile = mXPos + 6;
    float leftFixed = x - 6;
    float rightFixed = x + 6;

    float topMobile = mYPos - 6;
    float bottomtMobile = mYPos + 6;
    float topFixed = y - 6;
    float bottomFixed = y + 6;

    return leftMobile <= rightFixed && rightMobile >= leftFixed &&
        topMobile <= bottomFixed && bottomtMobile >= topFixed;
}

float Reticle::GetXPos() const
{
    return mXPos;
}

float Reticle::GetYPos() const
{
    return mYPos;
}

void Reticle::SetR(int r)
{
    mR = r;
}
