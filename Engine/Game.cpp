/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    x(400.0f),
    y(300.0f),
    x2(200.0f),
    y2(400.0f),
    velX(0.0f),
    velY(0.0f)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        velX -= 0.1f;
    }
    else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        velX += 0.1f;
    }

    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        velY -= 0.1f;
    }
    else if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        velY += 0.1f;
    }

    if (CollisionDetection())
    {
        colorIsChaged = true;
    }
    else
    {
        colorIsChaged = false;
    }

    x += velX;
    y += velY;

    WallCollision();
    shapeIschanged = wnd.kbd.KeyIsPressed(VK_SPACE);
    //colorIsChaged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
    Reticle();
}

void Game::Reticle()
{
    FirstBox();
    SecondBox();

    if (colorIsChaged)
    {
        r = 0;
    }
    else
    {
        r = 255;
    }

   /* if(shapeIschanged)
    { 
        gfx.PutPixel(x - 6, y - 6, r, g, b);
        gfx.PutPixel(x - 5, y - 6, r, g, b);
        gfx.PutPixel(x - 4, y - 6, r, g, b);
        gfx.PutPixel(x - 3, y - 6, r, g, b);
        gfx.PutPixel(x - 6, y - 6, r, g, b);
        gfx.PutPixel(x - 6, y - 5, r, g, b);
        gfx.PutPixel(x - 6, y - 4, r, g, b);
        gfx.PutPixel(x - 6, y - 3, r, g, b);

        gfx.PutPixel(x + 6, y + 6, r, g, b);
        gfx.PutPixel(x + 5, y + 6, r, g, b);
        gfx.PutPixel(x + 4, y + 6, r, g, b);
        gfx.PutPixel(x + 3, y + 6, r, g, b);
        gfx.PutPixel(x + 6, y + 6, r, g, b);
        gfx.PutPixel(x + 6, y + 5, r, g, b);
        gfx.PutPixel(x + 6, y + 4, r, g, b);
        gfx.PutPixel(x + 6, y + 3, r, g, b);

        gfx.PutPixel(x - 6, y + 6, r, g, b);
        gfx.PutPixel(x - 5, y + 6, r, g, b);
        gfx.PutPixel(x - 4, y + 6, r, g, b);
        gfx.PutPixel(x - 3, y + 6, r, g, b);
        gfx.PutPixel(x - 6, y + 6, r, g, b);
        gfx.PutPixel(x - 6, y + 5, r, g, b);
        gfx.PutPixel(x - 6, y + 4, r, g, b);
        gfx.PutPixel(x - 6, y + 3, r, g, b);

        gfx.PutPixel(x + 6, y - 6, r, g, b);
        gfx.PutPixel(x + 5, y - 6, r, g, b);
        gfx.PutPixel(x + 4, y - 6, r, g, b);
        gfx.PutPixel(x + 3, y - 6, r, g, b);
        gfx.PutPixel(x + 6, y - 6, r, g, b);
        gfx.PutPixel(x + 6, y - 5, r, g, b);
        gfx.PutPixel(x + 6, y - 4, r, g, b);
        gfx.PutPixel(x + 6, y - 3, r, g, b);
       
    }
    else
    {
        gfx.PutPixel(x - 5, y, r, g, b);
        gfx.PutPixel(x - 4, y, r, g, b);
        gfx.PutPixel(x - 3, y, r, g, b);

        gfx.PutPixel(x + 2, y, r, g, b);
        gfx.PutPixel(x + 3, y, r, g, b);
        gfx.PutPixel(x + 4, y, r, g, b);

        gfx.PutPixel(x, y - 5, r, g, b);
        gfx.PutPixel(x, y - 4, r, g, b);
        gfx.PutPixel(x, y - 3, r, g, b);

        gfx.PutPixel(x, y + 2, r, g, b);
        gfx.PutPixel(x, y + 3, r, g, b);
        gfx.PutPixel(x, y + 4, r, g, b);
    }*/
}

void Game::WallCollision() 
{
    if (x + 6 >= gfx.ScreenWidth - 1)
    {
        x = gfx.ScreenWidth - 7;
        velX = 0.0f;
    }

    if (x - 6 <= 0)
    {
        x = 6;
        velX = 0.0f;
    }

    if (y + 6 >= gfx.ScreenHeight - 1)
    {
        y = gfx.ScreenHeight - 7;
        velY = 0.0f;
    }

    if (y - 6 <= 0)
    {
        y = 6;
        velY = 0.0f;
    }
}

void Game::FirstBox()
{
    gfx.PutPixel(x - 6, y - 6, r, g, b);
    gfx.PutPixel(x - 5, y - 6, r, g, b);
    gfx.PutPixel(x - 4, y - 6, r, g, b);
    gfx.PutPixel(x - 3, y - 6, r, g, b);
    gfx.PutPixel(x - 6, y - 6, r, g, b);
    gfx.PutPixel(x - 6, y - 5, r, g, b);
    gfx.PutPixel(x - 6, y - 4, r, g, b);
    gfx.PutPixel(x - 6, y - 3, r, g, b);

    gfx.PutPixel(x + 6, y + 6, r, g, b);
    gfx.PutPixel(x + 5, y + 6, r, g, b);
    gfx.PutPixel(x + 4, y + 6, r, g, b);
    gfx.PutPixel(x + 3, y + 6, r, g, b);
    gfx.PutPixel(x + 6, y + 6, r, g, b);
    gfx.PutPixel(x + 6, y + 5, r, g, b);
    gfx.PutPixel(x + 6, y + 4, r, g, b);
    gfx.PutPixel(x + 6, y + 3, r, g, b);

    gfx.PutPixel(x - 6, y + 6, r, g, b);
    gfx.PutPixel(x - 5, y + 6, r, g, b);
    gfx.PutPixel(x - 4, y + 6, r, g, b);
    gfx.PutPixel(x - 3, y + 6, r, g, b);
    gfx.PutPixel(x - 6, y + 6, r, g, b);
    gfx.PutPixel(x - 6, y + 5, r, g, b);
    gfx.PutPixel(x - 6, y + 4, r, g, b);
    gfx.PutPixel(x - 6, y + 3, r, g, b);

    gfx.PutPixel(x + 6, y - 6, r, g, b);
    gfx.PutPixel(x + 5, y - 6, r, g, b);
    gfx.PutPixel(x + 4, y - 6, r, g, b);
    gfx.PutPixel(x + 3, y - 6, r, g, b);
    gfx.PutPixel(x + 6, y - 6, r, g, b);
    gfx.PutPixel(x + 6, y - 5, r, g, b);
    gfx.PutPixel(x + 6, y - 4, r, g, b);
    gfx.PutPixel(x + 6, y - 3, r, g, b);
}

void Game::SecondBox()
{
    gfx.PutPixel(x2 - 6, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 - 5, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 - 4, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 - 3, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 - 5, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 - 4, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 - 3, r2, g2, b2);

    gfx.PutPixel(x2 + 6, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 + 5, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 + 4, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 + 3, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 + 5, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 + 4, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 + 3, r2, g2, b2);

    gfx.PutPixel(x2 - 6, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 - 5, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 - 4, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 - 3, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 + 6, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 + 5, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 + 4, r2, g2, b2);
    gfx.PutPixel(x2 - 6, y2 + 3, r2, g2, b2);

    gfx.PutPixel(x2 + 6, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 + 5, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 + 4, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 + 3, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 - 6, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 - 5, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 - 4, r2, g2, b2);
    gfx.PutPixel(x2 + 6, y2 - 3, r2, g2, b2);
}

bool Game::CollisionDetection() const
{
    return x <= x2 + 6 && x + 6 >= x2 &&
        y <= y2 + 6 && y + 6 >= y2;
}
