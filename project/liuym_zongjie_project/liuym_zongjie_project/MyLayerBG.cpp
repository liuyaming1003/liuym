//
//  MyLayerBG.cpp
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-21.
//
//

#include "MyLayerBG.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MyLayerBG::scene()
{
    CCScene* scene = CCScene::create();
    
    MyLayerBG* layer = MyLayerBG::create();
    
    scene->addChild(layer, 0);
    scene->addChild(BgLayer::create(), 1);
    scene->addChild(CloudLayer::create(), 2);
    scene->addChild(HillLayer::create(), 2);
    return scene;
}

bool MyLayerBG::init()
{
    if(!CCLayer::init()){
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
   // CCSprite* pSprite = CCSprite::create("background.png");
   // pSprite->setPosition(ccp(size.width/2, size.height/2));
   // pSprite->setScale(2);
   // addChild(pSprite, 0);
    
    CCLabelTTF* label = CCLabelTTF::create("MyLayerBG Scene", "Arial", 40);
    label->setPosition(ccp(size.width/2, size.height-40));
    addChild(label, 1);    

    
    CCLabelTTF* backLabel = CCLabelTTF::create("backMain", "Arial", 28);
    
    CCMenuItemLabel* backBtn = CCMenuItemLabel::create(backLabel, this, menu_selector(MyLayerBG::backMainScene));
    backBtn->setPosition(ccp(size.width - 80, 20));
    
    
    
    CCMenu* menu = CCMenu::create(backBtn, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
    return true;
}

void MyLayerBG::backMainScene()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

bool BgLayer::init()
{
    if(!CCLayerColor::init()){
        return false;
    }
    
    initWithColor(ccc4(0 , 0, 0, 0));
    
    
    return true;
}


bool CloudLayer::init()
{
    if(!CCLayerColor::init()){
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* pSprite = CCSprite::create("cloud.png");
    pSprite->setPosition(ccp(size.width/2, size.height/2));
    addChild(pSprite, 0);
    
    initWithColor(ccc4(0, 0, 0, 0));
    
    
    return true;
}

bool HillLayer::init()
{
    if(!CCLayerColor::init()){
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* pSprite = CCSprite::create("hill.png");
    pSprite->setPosition(ccp(size.width/2, size.height/2));
    addChild(pSprite, 0);
    
    initWithColor(ccc4(0, 0, 0, 0));
    
    
    return true;
}
