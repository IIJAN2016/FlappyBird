//
//  medalBoard.cpp
//  FlappyBird
//
//  Created by Eiji Ito on 2016/05/13.
//
//

#include "MedalBoard.h"
using namespace cocos2d;

bool MedalBoard::init() {
    if (!Node::init()) {
        return false;
    }
    
    //this->bronze = Sprite::create("Assets/medal/medal_bronze.png");
    
    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Medal.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();
    
    return true;
}

void MedalBoard::displayMedalByScore(int score)
{
    this->setPosition(Vec2(144, 0));
    
    auto board = this->getChildByName("board");
    
    auto visibleMedal = CallFunc::create([this, board, score]() {
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
    });
    
    this->runAction(
                    Sequence::create(
                                     EaseSineOut::create(MoveBy::create(0.6f, Vec2(0.0f, 316.0f))),
                                     CallFunc::create([this, score]() {
                        this->setScore(score);
                    }),
                                     visibleMedal,
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

void MedalBoard::setScore(int score)
{
    this->getChildByName("board")->getChildByName<cocos2d::ui::TextBMFont*>("scoreLabel")->setVisible(true);
    Vector<FiniteTimeAction*> actions;
    int drumCount = score;
    //ラベルにドラムロールさせるための動作をactionsにまとめてしまう
    for (int i = 0; i < drumCount; i++) {
        //ラベル更新アクション
        auto set_func = CallFunc::create([this, i]() {
            this->getChildByName("board")->getChildByName<cocos2d::ui::TextBMFont*>("scoreLabel")->setString(std::to_string(i));
        });
        actions.pushBack(set_func);
        //目に見えるように更新ごとに遅らせる
        actions.pushBack(EaseIn::create(DelayTime::create(1.0f / (float)drumCount), 4));
    }
    
    //ドラムロール開始
    this->getChildByName("board")->getChildByName("scoreLabel")->runAction(Sequence::create(actions));
}























