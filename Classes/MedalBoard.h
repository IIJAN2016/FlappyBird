//
//  Medal.h
//  FlappyBird
//
//  Created by Eiji Ito on 2016/05/13.
//
//

#ifndef __FlappyBird__MedalBoard__
#define __FlappyBird__MedalBoard__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class MedalBoard : public cocos2d::Node {
public:
    CREATE_FUNC(MedalBoard);
    bool init() override;
    void displayMedalByScore(int score);
    void animateMedal(float dt);
    
    
protected:
    //cocos2d::Sprite* medal;
    cocostudio::timeline::ActionTimeline* timeline;
    Node* effect;
    cocos2d::Vec2 makeRandPoint();
    cocos2d::ui::TextBMFont* scoreLabel;
    
    void setScore(int score);
};

#endif /* defined(__FlappyBird__Medal__) */
