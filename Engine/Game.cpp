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
#include "Star.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ct( gfx ),
	cam( ct ),
	camCtrl( wnd.mouse,cam )
{
	entities.emplace_back( Star::Make( 100.0f,50.0f ),Vec2{ 460.0f,0.0f } );
	entities.emplace_back( Star::Make( 150.0f,50.0f ),Vec2{ 150.0f,300.0f } );
	entities.emplace_back( Star::Make( 100.0f,50.0f ),Vec2{ 250.0f,-200.0f } );
	entities.emplace_back( Star::Make( 150.0f,50.0f ),Vec2{ -250.0f,200.0f } );
	entities.emplace_back( Star::Make( 100.0f,50.0f ),Vec2{ 0.0f,0.0f } );
	entities.emplace_back( Star::Make( 200.0f,50.0f ),Vec2{ -150.0f,-300.0f } );
	entities.emplace_back( Star::Make( 100.0f,50.0f ),Vec2{ 400.0f,300.0f } );
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
	camCtrl.Update();
}

void Game::ComposeFrame()
{
	for( const auto& entity : entities )
	{
		cam.Draw( entity.GetDrawable() );
	}
}
