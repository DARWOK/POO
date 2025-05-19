#pragma once
#include "GameObject.h"
#include "IAttacker.h"
#include <iostream>

namespace LoW
{
    class Player :
        public GameObject, public IAttacker
    {
    public:
        float speed = 10.0f;

        //constructor
        Player(Vector2 pos, std::string _name, Texture tex):
            GameObject(pos, _name, tex){}

        void update() override;

        void attack()
        {
            std::cout << name << "Atacando" << std::endl;
        }
        void Fire() override
        {
            std::cout << "fuego!" << std::endl;
        }
    };
}


