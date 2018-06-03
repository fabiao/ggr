#pragma once

#include <memory>
#include <list>
#include "include/AnimatedSprite.h" 

class Bat : AnimatedSprite {

};

class Bats : AnimatedSprites {
    protected:
        std::list<std::shared_ptr<Bat> > pool;

    public:
        const std::shared_ptr<Bat>& checkout(int startX, int startY);
        void checkin(const std::shared_ptr<Bat>& item);
};