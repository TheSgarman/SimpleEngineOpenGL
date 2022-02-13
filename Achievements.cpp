#pragma once

#include "SpriteComponent.h"
#include "BackgroundSpriteComponent.h"
#include "Assets.h"
#include "Actor.h"
#include "Achievements.h"


Achievements::Achievements()
{
    
}

   Achievements:: ~Achievements(){}

  
   
   void Achievements::onNotify(int event)
    {
        switch (event)
        {
        case 0:
            std::cout << "Debug";

            vector<Texture*> bgTexsAchievements{
     &Assets::getTexture("Trophy"),
            };
            Actor* bgTexTrophy = new Actor();
            BackgroundSpriteComponent* bgSpritesUI = new BackgroundSpriteComponent(bgTexTrophy, bgTexsAchievements, 20);
            bgSpritesUI->setScrollSpeed(0.0f);

               break;
          
         


            // Handle other events, and update heroIsOnBridge_...
        }
    
   
    
}

   void Achievements::unlock(Achievements* achievements)
   {

   }



