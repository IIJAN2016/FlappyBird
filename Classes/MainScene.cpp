#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CharacterReader.h"
#include "Character.h"
#include "ObstacleReader.h"
#include "Constants.h"
#include "Ground.h"
#include "GroundReader.h"
#include "HighScoreManager.hpp"
#include "SimpleAudioEngine.h"

#include "MedalBoard.h"
#include "MedalReader.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace CocosDenshion;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.mp3");
    SimpleAudioEngine::getInstance()->setEffectsVolume(SOUND_VOLUME);
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance) CharacterReader::getInstance);
    instance->registReaderObject("ObstacleReader", (ObjectFactory::Instance) ObstacleReader::getInstance);
    instance->registReaderObject("GroundReader", (ObjectFactory::Instance) GroundReader::getInstance);
    instance->registReaderObject("MedalReader", (ObjectFactory::Instance) MedalReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    Size size = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(size);
    ui::Helper::doLayout(rootNode);
    
    this->background = rootNode->getChildByName("back");
    this->background2 = background->getChildByName("back2");
    this->character  = this->background->getChildByName<Character*>("character");
    this->character->setLocalZOrder(1);
    this->ground = this->background->getChildByName<Ground*>("ground");
    this->ground->setLocalZOrder(1);
    this->scoreLabel = this->background->getChildByName<ui::TextBMFont*>("scoreLabel");
    this->scoreLabel->setLocalZOrder(1);
    this->getReady = this->background->getChildByName<Node*>("getReady");
    this->getReady->setLocalZOrder(1);
    
    auto gameover = this->background->getChildByName("logo_game_over");
    gameover->setLocalZOrder(1);
    
    this->timeline = CSLoader::createTimeline("MainScene.csb");
    this->timeline->retain();
    
    this->medalboard = dynamic_cast<MedalBoard*>(CSLoader::createNode("Medal.csb"));
    this->medalboard->setLocalZOrder(3);
    this->background->addChild(this->medalboard);
    
    addChild(rootNode);

    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    this->scheduleUpdate();
    triggerReady();
}

void MainScene::update(float dt)
{
    switch (this->state) {
    case State::Ready:
        updateReady(dt);
        break;
    case State::Playing:
        updatePlaying(dt);
        break;
    case State::GameOver:
        updateGameOver(dt);
        break;
    }
}

void MainScene::updateReady(float dt)
{
    //床の移動
    this->ground->moveLeft(SCROLL_SPEED_X * dt);
}

void MainScene::updatePlaying(float dt)
{
    float moveDistance = SCROLL_SPEED_X * dt;

    //床の移動
    this->ground->moveLeft(moveDistance);

    // 障害物の移動
    for (auto obstacle : this->obstacles) {
        obstacle->moveLeft(moveDistance);
    }
    
    // 障害物とキャラの衝突判定
    Rect characterRect = this->character->getRect();
    for (auto obstacle : this->obstacles) {
        auto obstacleRects = obstacle->getRects();

        for (Rect obstacleRect : obstacleRects) {
            bool hit = characterRect.intersectsRect(obstacleRect);
            if (hit) {
                triggerGameOver();
            }
        }
    }
    
    // 床との衝突判定
    if (this->character->getBottomY() < this->ground->getPositionY()) {
        this->character->setBottomY(this->ground->getPositionY());
        this->character->stopFly();
        triggerGameOver();
    }
    
     // スコアの判定
    for (auto obstacle : this->obstacles) {
        float currentX = obstacle->getPositionX();
        float lastX    = currentX - moveDistance;
        if (lastX < this->character->getPositionX()
        && this->character->getPositionX() <= currentX) {
            this->setScore(this->score + 1);
            // 効果音を再生
            SimpleAudioEngine::getInstance()->playEffect("sfx_point.mp3");
        }
    }

}

void MainScene::updateGameOver(float dt)
{
    // 床との衝突判定
    if (this->character->getBottomY() < this->ground->getPositionY()) {
        this->character->setBottomY(this->ground->getPositionY());
        this->character->stopFly();
    }
}

void MainScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
         switch (this->state) {
         case State::Ready:
            this->triggerPlaying();
         case State::Playing:
            this->character->jump();
            break;
         case State::GameOver:
            break;
         }
        
        return true;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void MainScene::createObstacle(float dt)
{
    Obstacle* obstacle = dynamic_cast<Obstacle*>(CSLoader::createNode("Obstacle.csb"));
    this->obstacles.pushBack(obstacle);
    this->background->addChild(obstacle);
    float y = CCRANDOM_0_1() * (OBSTACLE_MAX_Y - OBSTACLE_MIN_Y) + OBSTACLE_MIN_Y;
    obstacle->setPosition(Vec2(OBSTACLE_INIT_X, y));
    
    if (this->obstacles.size() > OBSTACLE_LIMIT) {
        this->obstacles.front()->removeFromParent();
        this->obstacles.erase(this->obstacles.begin());
    }
}

void MainScene::triggerReady()
{
    this->state = State::Ready;
    if (CCRANDOM_0_1() >= 0.5)
        this->background2->setVisible(true);
    else
        this->background2->setVisible(false);
    
    this->character->getChildByName("bird")->setVisible(false);
    this->character->getChildByName("birdBlue")->setVisible(false);
    this->character->getChildByName("birdRed")->setVisible(false);
    if (CCRANDOM_0_1() <= 1.0/3.0)
        this->character->getChildByName("bird")->setVisible(true);
    else if (CCRANDOM_0_1() <= 2.0/3.0)
        this->character->getChildByName("birdBlue")->setVisible(true);
    else
        this->character->getChildByName("birdRed")->setVisible(true);
    this->character->stopFly();
    this->character->flyTillDeath();
    this->setScore(0);
    this->getReady->setVisible(true);
    
}

void MainScene::triggerPlaying()
{
    this->state = State::Playing;
    this->character->startFly();
    this->schedule(CC_SCHEDULE_SELECTOR(MainScene::createObstacle), OBSTACLE_TIME_SPAN);
    auto action = FadeOut::create(0.5);
    this->getReady->runAction(action);
}

void MainScene::triggerGameOver()
{
    
    this->state = State::GameOver;
    this->unschedule(CC_SCHEDULE_SELECTOR(MainScene::createObstacle));
    
    this->stopAllActions();
    this->runAction(this->timeline);
    this->timeline->play("gameover", false);
    
    // 効果音を再生
    SimpleAudioEngine::getInstance()->playEffect("sfx_hit.mp3");
    SimpleAudioEngine::getInstance()->playEffect("sfx_die.mp3");
    
    HighScoreManager* highScoreManager = new HighScoreManager();
    this->medalboard->displayMedalByScore(this->score, highScoreManager->getHighScore());
    highScoreManager->registerCurrentScore(this->score);
    
    delete highScoreManager;
}

void MainScene::setScore(int score)
{
    this->score = score;
    this->scoreLabel->setString(std::to_string(score));
}
