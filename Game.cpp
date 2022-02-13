#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "AnimSpriteComponent.h"
#include "Timer.h"
#include "Assets.h"
#include "BackgroundSpriteComponent.h"
#include "Astroid.h"
#include "Character.h"

using namespace std;

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);
	return isWindowInit && isRendererInit;
}

void Game::load()
{
	// Load textures
	Assets::loadTexture(renderer, "Res\\Charac01.png", "Charac01");
	Assets::loadTexture(renderer, "Res\\Charac02.png", "Charac02");
	Assets::loadTexture(renderer, "Res\\Charac03.png", "Charac03");
	Assets::loadTexture(renderer, "Res\\Charac04.png", "Charac04");
	Assets::loadTexture(renderer, "Res\\Farback01.png", "Farback01");
	Assets::loadTexture(renderer, "Res\\Farback02.png", "Farback02");
	Assets::loadTexture(renderer, "Res\\Stars.png", "Stars");
	Assets::loadTexture(renderer, "Res\\Astroid.png", "Astroid");
	Assets::loadTexture(renderer, "Res\\Ship.png", "Ship");
	Assets::loadTexture(renderer, "Res\\Laser.png", "Laser");
	Assets::loadTexture(renderer, "Res\\Trophy.png", "Trophy");

	Assets::loadTexture(renderer, "Res\\Character.png", "Character");

	
	//Character
	Character* character = new Character();
	character->setPosition(Vector2{ 100, 300 });
	vector<Texture*> animTextures{
		&Assets::getTexture("Charac01"),
		&Assets::getTexture("Charac02"),
		&Assets::getTexture("Charac03"),
		&Assets::getTexture("Charac04"),
	};
	AnimSpriteComponent* animatedSprite = new AnimSpriteComponent(character, animTextures);

	vector<Texture*> bgTexsFar{
		&Assets::getTexture("Farback01"),
		&Assets::getTexture("Farback02")
	};
	Actor* bgFar = new Actor();
	BackgroundSpriteComponent* bgSpritesFar = new BackgroundSpriteComponent(bgFar, bgTexsFar);
	bgSpritesFar->setScrollSpeed(-100.0f);


	Actor* bgClose = new Actor();
	vector<Texture*> bgTexsClose{
		&Assets::getTexture("Stars"),
		&Assets::getTexture("Stars")

	};



	
	


	
	
	
	BackgroundSpriteComponent* bgSpritesClose = new BackgroundSpriteComponent(bgClose, bgTexsClose, 50);

	bgSpritesClose->setScrollSpeed(-200.0f);

	const int astroidNumber = 30;
	for (int i = 0; i < astroidNumber; ++i)
	{
		Astroid* dt = new Astroid();
	}
}

void Game::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}

	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->processInput(keyboardState);
		
		
		

	}
	isUpdatingActors = false;
}

void Game::update(float dt)
{

	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->update(dt);
	}
	isUpdatingActors = false;

	for (auto pendingActor : pendingActors)
	{
		actors.emplace_back(pendingActor);
	}
	pendingActors.clear();
	vector<Actor*> deadActors;
	for (auto actor : actors)
	{
		if (actor->getState() == Actor::ActorState::Dead)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto deadActor : deadActors)
	{
		delete deadActor;
	}
}

void Game::render()
{
	renderer.beginDraw();
	renderer.draw();
	renderer.endDraw();
}

vector<Astroid*>& Game::getAstroids()
{
	return astroids;
}

void Game::addAstroid(Astroid* astroid)
{
	astroids.emplace_back(astroid);
}

void Game::removeAstroid(Astroid* astroid)
{
	auto iter = find(begin(astroids), end(astroids), astroid);
	if (iter != astroids.end())
	{
		astroids.erase(iter);
		
		
	}
}

void Game::loop()
{
	Timer timer;
	float dt = 0;
	while (isRunning)
	{
		float dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::unload()
{

	while (!actors.empty())
	{
		delete actors.back();
	}

	Assets::clear();
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::addActor(Actor* actor)
{
	if (isUpdatingActors)
	{
		pendingActors.emplace_back(actor);
	}
	else
	{
		actors.emplace_back(actor);
	}
}

void Game::removeActor(Actor* actor)
{
	auto iter = std::find(begin(pendingActors), end(pendingActors), actor);
	if (iter != end(pendingActors))
	{
		std::iter_swap(iter, end(pendingActors) - 1);
		pendingActors.pop_back();
	}
	iter = std::find(begin(actors), end(actors), actor);
	if (iter != end(actors))
	{
		std::iter_swap(iter, end(actors) - 1);
		actors.pop_back();
	}
}