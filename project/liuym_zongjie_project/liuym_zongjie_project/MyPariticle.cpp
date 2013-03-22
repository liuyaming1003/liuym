//
//  MyPariticle.cpp
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-22.
//
//

#include "MyPariticle.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
using namespace cocos2d;
using namespace CocosDenshion;

int indexPlist = 0;
int MAX_INDEX = 13;

const char* plist(int index)
{
    CCLog("index = %d", index);
    switch (index) {
        case 0:
            return "Phoenix.plist";
            break;
        case 1:
            return "BoilingFoam.plist";
            break;
        case 2:
            return "BurstPipe.plist";
            break;
        case 3:
            return "Comet.plist";
            break;
        case 4:
            return "debian.plist";
            break;
        case 5:
            return "default.plist";
            break;
        case 6:
            return "ExplodingRing.plist";
            break;
        case 7:
            return "LavaFlow.plist";
            break;
        case 8:
            return "SpinningPeas.plist";
            break;
        case 9:
            return "SpookyPeas.plist";
            break;
        case 10:
            return "Upsidedown.plist";
            break;
        case 11:
            return "snow.plist";
            break;
        case 12:
            return "demo1.plist";
            break;
        case 13:
            return "demo2.plist";
            break;
        default:
            break;
    }
    return NULL;
}

CCScene* MyPariticle::scene()
{
    CCScene* scene = CCScene::create();
    
    //MyPariticle* layer = MyPariticle::create();
    
    //scene->addChild(layer, 0);
    indexPlist = 0;
    ParticleDemo* layer = ParticleDemo::create();
    scene->addChild(layer, 0);
    
    return scene;
}

bool MyPariticle::init()
{
    if(!CCLayer::init()){
        return false;
    }
    setTouchEnabled(true);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    

    CCSprite* pBG = CCSprite::create("background.png");
    pBG->setPosition(ccp(size.width/2, size.height/2));
    pBG->setScale(2);
   // CCActionInterval* move = CCMoveBy::create(4, ccp(300, 0));
   // CCActionInterval* move_back = move->reverse();
   // pBG->runAction(CCRepeatForever::create((CCActionInterval*)(CCSequence::create(move, move_back, NULL))));
    addChild(pBG, 1);
    //添加基本按钮
    
    CCLabelTTF* backLabel = CCLabelTTF::create("backMain", "Arial", 28);
    
    CCMenuItemLabel* backBtn = CCMenuItemLabel::create(backLabel, this, menu_selector(MyPariticle::backMainScene));
    backBtn->setPosition(ccp(size.width - 80, 20));
    
    
    CCLabelTTF* pNextLabel  = CCLabelTTF::create("Next ", "Arial", 28);
    CCLabelTTF* pBackLabel = CCLabelTTF::create("Back ", "Arial", 28);
    CCLabelTTF* pRestartLabel = CCLabelTTF::create("Restart ", "Arial", 28);
    
    CCMenuItemLabel* pNextItem  = CCMenuItemLabel::create(pNextLabel, this, menu_selector(MyPariticle::nextCallback));
    CCMenuItemLabel* pBackItem = CCMenuItemLabel::create(pBackLabel, this, menu_selector(MyPariticle::backCallback));
    CCMenuItemLabel* pRestartItem = CCMenuItemLabel::create(pRestartLabel, this, menu_selector(MyPariticle::restartCallback));
    
    CCMenu* pNextMenu = CCMenu::create(pNextItem, pBackItem, pRestartItem ,backBtn, NULL);
    
    pNextItem->setPosition(ccp(size.width/2 +150, 50));
    pBackItem->setPosition(ccp(size.width/2 - 150, 50));
    pRestartItem->setPosition(ccp(size.width/2 , 50));
    
    pNextMenu->setPosition(CCPointZero);
    
    addChild(pNextMenu,1);
//    char str[] = "Phoenix.plist";
//    m_emitter = CCParticleSystemQuad::create(str);
//    m_emitter->setScale(2);
//    m_emitter->setEmitterMode(300);
// //   m_emitter->stopSystem();
//    m_emitter->setPosition(ccp(size.width/2, size.height/2));
//    addChild(m_emitter, 10);
    
    return true;
}

void MyPariticle::backCallback(cocos2d::CCObject *pSender)
{
    if(indexPlist == 0)
        return ;
    indexPlist--;
    CCScene* scene = CCScene::create();
    ParticleDemo* layer = ParticleDemo::create();
    scene->addChild(layer, 0);
    CCDirector::sharedDirector()->replaceScene(scene);
}

void MyPariticle::nextCallback(cocos2d::CCObject *pSender)
{
    if(indexPlist == MAX_INDEX)
        return ;
    indexPlist++;
    CCScene* scene = CCScene::create();
    ParticleDemo* layer = ParticleDemo::create();
    scene->addChild(layer, 0);
    CCDirector::sharedDirector()->replaceScene(scene);
}

void MyPariticle::restartCallback(cocos2d::CCObject *pSender)
{
    CCScene* scene = CCScene::create();
    ParticleDemo* layer = ParticleDemo::create();
    scene->addChild(layer, 0);
    CCDirector::sharedDirector()->replaceScene(scene);
}

void MyPariticle::backMainScene()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void MyPariticle::setEmitterPostion()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    m_emitter->setPosition(ccp(size.width/2, size.height/2));
}

void MyPariticle::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCLog("touch began");
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*) (*it);
    
    CCPoint location = touch->getLocationInView();
    
    CCPoint convertedLocation = CCDirector::sharedDirector()->convertToGL(location);
    
    m_emitter->setPosition(convertedLocation);
}

void MyPariticle::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCLog("touch moved");
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*) (*it);
    
    CCPoint location = touch->getLocationInView();
    
    CCPoint convertedLocation = CCDirector::sharedDirector()->convertToGL(location);
    
    m_emitter->setPosition(convertedLocation);
}

void MyPariticle::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCLog("touch ended");
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*) (*it);
    
    CCPoint location = touch->getLocationInView();
    
    CCPoint convertedLocation = CCDirector::sharedDirector()->convertToGL(location);
    
    m_emitter->setPosition(convertedLocation);
}

bool ParticleDemo::init()
{
    if(!MyPariticle::init()){
        return false;
    }

    m_emitter = CCParticleSystemQuad::create(plist(indexPlist));
    m_emitter->setBlendAdditive(true);
    if(indexPlist == 12)
        m_emitter->setEmissionRate(20000);
    setEmitterPostion();
    addChild(m_emitter, 1);
    return true;
}


