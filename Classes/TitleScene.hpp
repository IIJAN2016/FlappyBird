//
//  TitleScene.hpp
//  FlappyBird
//
//  Created by Yuki Kotani on 2016/05/13.
//
//

#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Character;
class Ground;

class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void onEnter() override;
    void update(float dt) override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
    
private:
    Character* character;
    Ground* ground;
    cocos2d::Node* background;
    
    void setupTouchHandling();
};

#endif // __TITLE_SCENE_H__
