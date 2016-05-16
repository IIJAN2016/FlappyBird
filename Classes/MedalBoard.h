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


class MedalBoard : public cocos2d::Layer {
public:
    CREATE_FUNC(MedalBoard);
    bool init() override;
    void onEnter() override;
    void displayMedalByScore(int score, int highScore);
    void animateMedal(float dt);
    
    
protected:
    //cocos2d::Sprite* medal;
    cocostudio::timeline::ActionTimeline* timeline;
    Node* effect;
    cocos2d::Vec2 makeRandPoint();
    cocos2d::ui::TextBMFont* scoreLabel;
    cocos2d::ui::Button* playButton;
    
    void setScore(int score, int highScore);
};

#endif /* defined(__FlappyBird__Medal__) */
