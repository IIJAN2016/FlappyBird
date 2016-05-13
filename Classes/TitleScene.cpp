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

#include "SimpleAudioEngine.h"


USING_NS_CC;

using namespace cocostudio::timeline;
using namespace CocosDenshion;

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
    
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.mp3");
    SimpleAudioEngine::getInstance()->setEffectsVolume(SOUND_VOLUME);
    
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
                // 効果音を再生
                SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.mp3");
                // ボタンがタップされたときの処理を実装する
                auto nextGameScene = MainScene::createScene();
                auto transition = TransitionFade::create(1.0f, nextGameScene);
                Director::getInstance()->replaceScene(transition);
                break;
        }
        
    });
    
    auto rateButton = this->background->getChildByName<ui::Button*>("rateButton");
    rateButton->addTouchEventListener([this, rateButton, moveDistance](Ref* sender, ui::Widget::TouchEventType type) {
        
        switch(type) {
            case ui::Widget::TouchEventType::BEGAN:
                rateButton->setPositionY(rateButton->getPositionY() - moveDistance);
                break;
            case ui::Widget::TouchEventType::CANCELED:
                rateButton->setPositionY(rateButton->getPositionY() + moveDistance);
                break;
            case ui::Widget::TouchEventType::ENDED:
                rateButton->setPositionY(rateButton->getPositionY() + moveDistance);
                break;
        }
        
        
        
    });
    
    
    auto rankingButton = this->background->getChildByName<ui::Button*>("rankingButton");
    rankingButton->addTouchEventListener([this, rankingButton, moveDistance](Ref* sender, ui::Widget::TouchEventType type) {
        
        switch(type) {
            case ui::Widget::TouchEventType::BEGAN:
                rankingButton->setPositionY(rankingButton->getPositionY() - moveDistance);
                break;
            case ui::Widget::TouchEventType::CANCELED:
                rankingButton->setPositionY(rankingButton->getPositionY() + moveDistance);
                break;
            case ui::Widget::TouchEventType::ENDED:
                rankingButton->setPositionY(rankingButton->getPositionY() + moveDistance);
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
