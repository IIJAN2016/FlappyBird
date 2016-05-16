//
//  medalBoard.cpp
//  FlappyBird
//
//  Created by Eiji Ito on 2016/05/13.
//
//

#include "MedalBoard.h"
#include "MainScene.h"
using namespace cocos2d;

bool MedalBoard::init() {
    if (!Node::init()) {
        return false;
    }
    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Medal.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();
    
    return true;
}

void MedalBoard::onEnter()
{
    Layer::onEnter();
    //this->setupTouchHandling();
    
    
    //auto rootNode = CSLoader::createNode("Medal.csb");
    float moveDistance = 5;
    this->playButton = this->getChildByName<ui::Button*>("playButton");
    this->playButton->addTouchEventListener([this, moveDistance](Ref* sender, ui::Widget::TouchEventType type) {
     
     switch(type) {
     case ui::Widget::TouchEventType::BEGAN:
     case ui::Widget::TouchEventType::MOVED:
     playButton->setPositionY(playButton->getPositionY() - moveDistance);
     break;
     case ui::Widget::TouchEventType::CANCELED:
     playButton->setPositionY(playButton->getPositionY() + moveDistance);
     break;
     case ui::Widget::TouchEventType::ENDED:
     playButton->setPositionY(playButton->getPositionY() + moveDistance);
     // 効果音を再生
     //SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.mp3");
     // ボタンがタップされたときの処理を実装する
     auto nextGameScene = MainScene::createScene();
     auto transition = TransitionFade::create(1.0f, nextGameScene);
     Director::getInstance()->replaceScene(transition);
     break;
     }
     
     });
}


void MedalBoard::displayMedalByScore(int score, int highScore)
{
    this->setPosition(Vec2(144, 0));
    
    this->runAction(
                    Sequence::create(
                                     EaseSineOut::create(MoveBy::create(0.6f, Vec2(0.0f, 316.0f))),
                                     CallFunc::create([this, score, highScore]() {
                                     this->setScore(score, highScore);
                                     }),
                                     NULL
                                     )
                    );
}

void MedalBoard::animateMedal(float dt)
{
    this->effect = getChildByName("effect");
    
    cocostudio::timeline::ActionTimeline* effectTimeline =  CSLoader::createTimeline("Medal.csb");
    std::string animationName = std::string("effect");
    effect->runAction(effectTimeline);
    
    auto pika = CallFunc::create([this, effectTimeline]()
                                 {
                                     auto vec = this->makeRandPoint();
                                     this->effect->setPosition(vec);
                                     effectTimeline->play("effect", false);
                                 });
    
    auto action =Sequence::create(pika,
                                  MoveBy::create(1.0f, Vec2(0.0f,0.0f)), NULL);
    this->effect->runAction(Repeat::create(action, -1));
}

Vec2 MedalBoard::makeRandPoint()
{
    Vec2 medalCenter = Vec2(-65, -65);
    int medalRadius = 22;
    Vec2 randMin = medalCenter - Vec2(medalRadius, medalRadius);
    Vec2 randMax = medalCenter + Vec2(medalRadius, medalRadius);
    
    float randX = (CCRANDOM_0_1() * (randMax.x - randMin.x)) + randMin.x;
    float randY = (CCRANDOM_0_1() * (randMax.y - randMin.y)) + randMin.y;
    
    auto vec = Vec2(Vec2(randX, randY));
    return vec;
}

void MedalBoard::setScore(int score, int highScore)
{
    
    
    auto highScoreLabel = this->getChildByName("board")->getChildByName<cocos2d::ui::TextBMFont*>("highScore");
    highScoreLabel->setVisible(true);
    highScoreLabel->setString(std::to_string(highScore));
    
    
    auto scoreLabel = this->getChildByName("board")->getChildByName<cocos2d::ui::TextBMFont*>("scoreLabel");
    scoreLabel->setVisible(true);
    Vector<FiniteTimeAction*> actions;
    
    //ラベルにドラムロールさせるための動作をactionsにまとめてしまう
    for (int i = 0; i <= score; i++) {
        //ラベル更新アクション
        auto set_func = CallFunc::create([this, scoreLabel, highScoreLabel, i, score, highScore]() {
            scoreLabel->setString(std::to_string(i));
            
            
            if(i == score)
            {
                if(highScore < score)
                {
                    highScoreLabel->setString(std::to_string(score));
                    this->getChildByName<Node*>("new")->setVisible(true);
                }
                this->playButton->setVisible(true);
                this->getChildByName<Node*>("rankButton")->setVisible(true);
                
                
                auto board = this->getChildByName("board");
                
                if(score < 10)
                {
                    return;
                } else if(score < 20)
                {
                    board->getChildByName("medal_bronze")->setVisible(true);
                } else if(score < 30)
                {
                    board->getChildByName("metal_silver")->setVisible(true);
                } else if(score < 40)
                {
                    board->getChildByName("medal_gold")->setVisible(true);
                } else {
                    board->getChildByName("metal_platium")->setVisible(true);
                }
                this->animateMedal(0.0f);
            }
        });
        actions.pushBack(set_func);
        //目に見えるように更新ごとに遅らせる
        actions.pushBack(EaseIn::create(DelayTime::create(1.0f / static_cast<float>(score)), 4));
    }
    
    //ドラムロール開始
    scoreLabel->runAction(Sequence::create(actions));
}























