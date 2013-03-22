//
//  MyEffect.cpp
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-22.
//
//

#include "MyEffect.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
static int indexLayer = 0;
const int MAX_INDEX = 21;

static std::string effectsList[] =
{
    "Shaky3D",
    "Waves3D",
    "FlipX3D",
    "FlipY3D",
    "Lens3D",
    "Ripple3D",
    "Liquid",
    "Waves",
    "Twirl",
    "ShakyTiles3D",
    "ShatteredTiles3D",
    "ShuffleTiles",
    "FadeOutTRTiles",
    "FadeOutBLTiles",
    "FadeOutUpTiles",
    "FadeOutDownTiles",
    "TurnOffTiles",
    "WavesTiles3D",
    "JumpTiles3D",
    "SplitRows",
    "SplitCols",
    "PageTurn3D"
};//用于标识特效

using namespace cocos2d;
using namespace CocosDenshion;

CCActionInterval* createEffect(float t)
{
    CCDirector::sharedDirector()->setDepthTest(false);
    switch (indexLayer) {
        case 0: return Shaky3DDemo::actionWithDuration(t);
            break;
        case 1: return Waves3DDemo::actionWithDuration(t);
        case 2: return FlipX3DDemo::actionWithDuration(t);
        case 3: return FlipY3DDemo::actionWithDuration(t);
        case 4: return Lens3DDemo::actionWithDuration(t);
        case 5: return Ripple3DDemo::actionWithDuration(t);
        case 6: return LiquidDemo::actionWithDuration(t);
        case 7: return WavesDemo::actionWithDuration(t);
        case 8: return TwirlDemo::actionWithDuration(t);
        case 9: return ShakyTiles3DDemo::actionWithDuration(t);
        case 10: return ShatteredTiles3DDemo::actionWithDuration(t);
        case 11: return ShuffleTilesDemo::actionWithDuration(t);
        case 12: return FadeOutTRTilesDemo::actionWithDuration(t);
        case 13: return FadeOutBLTilesDemo::actionWithDuration(t);
        case 14: return FadeOutUpTilesDemo::actionWithDuration(t);
        case 15: return FadeOutDownTilesDemo::actionWithDuration(t);
        case 16: return TurnOffTilesDemo::actionWithDuration(t);
        case 17: return WavesTiles3DDemo::actionWithDuration(t);
        case 18: return JumpTiles3DDemo::actionWithDuration(t);
        case 19: return SplitRowsDemo::actionWithDuration(t);
        case 20: return SplitColsDemo::actionWithDuration(t);
        case 21: return PageTurn3DDemo::actionWithDuration(t);
        default:
            break;
    }
    return NULL;
}

CCScene* MyEffect::scene()
{
    CCScene* scene = CCScene::create();
    
    MyEffect* layer = MyEffect::create();
    scene->addChild(layer, 0);
    indexLayer = 0;
    
    return scene;
}

bool MyEffect::init()
{
    if(!CCLayer::init()){
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCNode* node = CCNode::create();
    CCActionInterval* effect = createEffect(3);
    node->runAction(effect);
    addChild(node, 0);
    CCSprite* pBG = CCSprite::create("background.png");
    pBG->setPosition(ccp(size.width/2, size.height/2));
    pBG->setScale(2);
    node->addChild(pBG, 0);
    
    CCSprite* pLayer = CCSprite::create("friend.png");
    pLayer->setPosition(ccp(size.width/2, size.height/2));
    node->addChild(pLayer, 1);
    
    CCLabelTTF* label = CCLabelTTF::create(effectsList[indexLayer].c_str(), "Arial", 28);
    label->setPosition(ccp(size.width/2, size.height - 30));
    addChild(label);
    //添加基本按钮
    
    CCLabelTTF* backLabel = CCLabelTTF::create("backMain", "Arial", 28);
    
    CCMenuItemLabel* backBtn = CCMenuItemLabel::create(backLabel, this, menu_selector(MyEffect::backMainScene));
    backBtn->setPosition(ccp(size.width - 80, 20));
    
    
    CCLabelTTF* pNextLabel  = CCLabelTTF::create("Next ", "Arial", 28);
    CCLabelTTF*pBackLabel = CCLabelTTF::create("Back ", "Arial", 28);
    CCLabelTTF*pRestartLabel = CCLabelTTF::create("Restart ", "Arial", 28);
    
    CCMenuItemLabel* pNextItem  = CCMenuItemLabel::create(pNextLabel, this, menu_selector(MyEffect::nextCallback));
    CCMenuItemLabel* pBackItem = CCMenuItemLabel::create(pBackLabel, this, menu_selector(MyEffect::backCallback));
    CCMenuItemLabel* pRestartItem = CCMenuItemLabel::create(pRestartLabel, this, menu_selector(MyEffect::restartCallback));
    
    CCMenu* pNextMenu = CCMenu::create(pNextItem, pBackItem, pRestartItem ,backBtn, NULL);
  //  CCMenu* pBackMenu = CCMenu::create(pBackItem, NULL);
 //   CCMenu* pRestartMenu = CCMenu::create(pRestartItem, NULL);
    
    pNextItem->setPosition(ccp(size.width/2 +150, 50));
    pBackItem->setPosition(ccp(size.width/2 - 150, 50));
    pRestartItem->setPosition(ccp(size.width/2 , 50));
    
    pNextMenu->setPosition(CCPointZero);
   // pBackMenu->setPosition(CCPointZero);
   // pRestartMenu->setPosition(CCPointZero);
    
    addChild(pNextMenu,1);
   // addChild(pBackMenu, 1);
  //  addChild(pRestartMenu,1);
    
    return true;
}

void MyEffect::backMainScene()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

std::string MyEffect::title()
{
    return effectsList[indexLayer].c_str();
}

void MyEffect::backCallback(cocos2d::CCObject *pSender)
{
    if(indexLayer == 0)
        return;
    indexLayer--;
    CCScene* scene = new CCScene();
    scene->addChild(MyEffect::create());
    CCDirector::sharedDirector()->replaceScene(scene);
    scene->release();
}

void MyEffect::nextCallback(cocos2d::CCObject *pSender)
{
    if(indexLayer == MAX_INDEX)
        return;
    indexLayer++;
    CCScene* scene = new CCScene();
    scene->addChild(MyEffect::create());
    CCDirector::sharedDirector()->replaceScene(scene);
    scene->release();
}

void MyEffect::restartCallback(cocos2d::CCObject *pSender)
{
    CCScene* scene = new CCScene();
    scene->addChild(MyEffect::create());
    CCDirector::sharedDirector()->replaceScene(scene);
    scene->release();
}

