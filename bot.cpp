#include "bot.h"
#include "world.h"

void bot::move(float time, entity* target)
{
        if (this->getSpeedX()>0)
            if (target->getX()<this->getX())
                this->setSpeedX(this->getSpeedX*=(-1));
        if (this->getSpeedX()<0)
            if (target->getX()>this->getX())
                this->setSpeedX(this->getSpeedX*=(-1));
        if (this->getSpeedY()>0)
            if (target->getY()<this->getY())
                this->setSpeedY(this->getSpeedY*=(-1));
        if (this->getSpeedY()<0)
            if (target->getY()>this->getY())
                this->setSpeedY(this->getSpeedY*=(-1));

        this->setX(this->getSpeedX()*time);
        this->setY(this->getSpeedY()*time);
}
