//
//  Character.cpp
//  FlappyBird
//
//  Created by Ken Watanabe on 2016/05/11.
//
//

#include "Character.h"
#include "Constants.h"
#include <math.h>
using namespace cocos2d;

bool Character::init() {
    if (!Node::init()) {
        return false;
    }

    this->timeline = CSLoader::createTimeline("Character.csb");
    this->timeline->retain();
    this->velocity = 0;
    this->accel    = GRAVITY_ACCEL;
    this->isFlying = false;

    this->degreeSpeed = 0;
    this->degree = 0;

    return true;
}

void Character::onEnter(){
    Node::onEnter();
    
    this->scheduleUpdate();
}

void Character::update(float dt){
    if (isFlying) {
        this->velocity += accel * dt;
        this->setPosition(this->getPosition() + Vec2(0, this->velocity * dt));

        if (this->velocity > ROTATION_THRESHOLD_VELOCITY) {
            this->setRotation(ROTATION_MIN_DEGREE);
        }else{
            this->degreeSpeed += ROTATION_DEGREE_ACCEL * dt;
            this->degree += degreeSpeed * dt;
            this->setRotation(MIN(degree, ROTATION_MAX_DEGREE));
        }
    }
}

void Character::jump(){
    this->velocity = JUMP_SPEED;
    
    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play("fly", false);

    this->degree = ROTATION_MIN_DEGREE;
    this->degreeSpeed = 0;
}

Rect Character::getRect()
{
    auto bird = this->getChildByName<Sprite*>("bird");
    Size size = bird->getContentSize() * 0.8f;
    return Rect(this->getPosition() - size/2, size);
}

void Character::startFly()
{
    this->isFlying = true;
}

void Character::stopFly()
{
    this->isFlying = false;
}

float Character::getBottomY()
{
    return this->getRect().origin.y;
}

void Character::setBottomY(float y)
{
    this->setPositionY(y + this->getRect().size.height / 2);
}
