//
//  TitleScene.cpp
//  FlappyBird
//
//  Created by Yuki Kotani on 2016/05/13.
//
//

#include "MainScene.h"
#include "TitleScene.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CharacterReader.h"
#include "Character.h"
#include "Constants.h"
#include "Ground.h"
#include "GroundReader.h"

USING_NS_CC;

using namespace cocostudio::timeline;


Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TitleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance) CharacterReader::getInstance);
    instance->registReaderObject("GroundReader", (ObjectFactory::Instance) GroundReader::getInstance);
    
    auto rootNode = CSLoader::createNode("TitleScene.csb");
    Size size = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(size);
    ui::Helper::doLayout(rootNode);
    
    this->background = rootNode->getChildByName("back");
    
    this->character  = this->background->getChildByName<Character*>("character");
    this->character->setLocalZOrder(1);
    //this->character->flyTillDeath();
    
    this->ground = this->background->getChildByName<Ground*>("ground");
    this->ground->setLocalZOrder(1);
    
    
    
    
    auto playButton = this->background->getChildByName<ui::Button*>("playButton");
    float moveDistance = 5;
    playButton->addTouchEventListener([this, playButton, moveDistance](Ref* sender, ui::Widget::TouchEventType type) {
        
        switch(type) {
            case ui::Widget::TouchEventType::BEGAN:
                playButton->setPositionY(playButton->getPositionY() - moveDistance);
                break;
            case ui::Widget::TouchEventType::CANCELED:
                playButton->setPositionY(playButton->getPositionY() + moveDistance);
                break;
            case ui::Widget::TouchEventType::ENDED:
                playButton->setPositionY(playButton->getPositionY() + moveDistance);
                // ボタンがタップされたときの処理を実装する
                auto nextGameScene = MainScene::createScene();
                auto transition = TransitionFade::create(1.0f, nextGameScene);
                Director::getInstance()->replaceScene(transition);
                break;
        }
        
    });
    
    addChild(rootNode);
    
    return true;
}

void TitleScene::onEnter()
{
    Layer::onEnter();
    
    this->scheduleUpdate();
}

void TitleScene::update(float dt)
{
    this->ground->moveLeft(SCROLL_SPEED_X * dt);
}
