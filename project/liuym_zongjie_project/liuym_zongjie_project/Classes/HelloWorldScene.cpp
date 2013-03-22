#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MyLayerBG.h"
#include "MyEffect.h"
#include "MyPariticle.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* switchScene(CCScene *scene)
{
    void *transScene = NULL;
    srand(time(0));
    int indexCase = rand() % 34;
    CCLog("index = %d", indexCase);
    switch (indexCase) {
        case 0:
            transScene = CCTransitionTurnOffTiles::create(1, scene);
            break;
        case 1:
            transScene = CCTransitionShrinkGrow::create(1, scene);
            break;
        case 2:
            transScene = CCTransitionSlideInL::create(1, scene);
            break;
        case 3:
            transScene = CCTransitionSlideInR::create(1, scene);
            break;
        case 4:
            transScene = CCTransitionSlideInT::create(1, scene);
            break;
        case 5:
            transScene = CCTransitionSlideInB::create(1, scene);
            break;
        case 6:
            transScene = CCTransitionSplitCols::create(1, scene);
            break;
        case 7:
            transScene = CCTransitionSplitRows::create(1, scene);
            break;
        case 8:
            transScene = CCTransitionRotoZoom::create(1, scene);
            break;
        case 9:
            transScene = CCTransitionJumpZoom::create(1, scene);
            break;
        case 10:
            transScene = CCTransitionZoomFlipX::create(1, scene);
            break;
        case 11:
            transScene = CCTransitionZoomFlipY::create(1, scene);
            break;
        case 12:
            transScene = CCTransitionZoomFlipAngular::create(1, scene);
            break;
        case 13:
            transScene = CCTransitionMoveInL::create(1, scene);
            break;
        case 14:
            transScene = CCTransitionMoveInR::create(1, scene);
            break;
        case 15:
            transScene = CCTransitionMoveInT::create(1, scene);
            break;
        case 16:
            transScene = CCTransitionMoveInB::create(1, scene);
            break;
        case 17:
            transScene = CCTransitionFlipX::create(1, scene);
            break;
        case 18:
            transScene = CCTransitionFlipY::create(1, scene);
            break;
        case 19:
            transScene = CCTransitionFlipAngular::create(1, scene);
            break;
        case 20:
            transScene = CCTransitionFade::create(1, scene);
            break;
        case 21:
            transScene = CCTransitionFadeTR::create(1, scene);
            break;
        case 22:
            transScene = CCTransitionFadeBL::create(1, scene);
            break;
        case 23:
            transScene = CCTransitionFadeDown::create(1, scene);
            break;
        case 24:
            transScene = CCTransitionFadeUp::create(1, scene);
            break;
        case 25:
            transScene = CCTransitionCrossFade::create(1, scene);
            break;
        case 26:
            transScene = CCTransitionPageTurn::create(1, scene, true);
            break;
        case 27:
            //transScene = CCTransitionProgress::create(1, scene);
            transScene = CCTransitionProgressVertical::create(1, scene);
            break;
        case 28:
            transScene = CCTransitionProgressHorizontal::create(1, scene);
            break;
        case 29:
            transScene = CCTransitionProgressInOut::create(1, scene);
            break;
        case 30:
            transScene = CCTransitionProgressOutIn::create(1, scene);
            break;
        case 31:
            transScene = CCTransitionProgressRadialCCW::create(1, scene);
            break;
        case 32:
            transScene = CCTransitionProgressRadialCW::create(1, scene);
            break;
        case 33:
            transScene = CCTransitionProgressVertical::create(1, scene);
            break;
        default:
            break;
    }
  //  if(++indexCase >= 34)
   //     indexCase = 0;
    
    return (CCScene*)transScene;
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Liuym Program", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    //add button
    CCLabelTTF* label1 = CCLabelTTF::create("切换场景", "Arial", 40);
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label1, this, menu_selector(HelloWorld::item1));
    
    
    CCLabelTTF* label2 = CCLabelTTF::create("特效", "Arial", 40);
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label2, this, menu_selector(HelloWorld::item2));
    
    CCLabelTTF* label3 = CCLabelTTF::create("粒子效果", "Arial", 40);
    CCMenuItemLabel* item3 = CCMenuItemLabel::create(label3, this, menu_selector(HelloWorld::item3));
    
    CCMenu* menu = CCMenu::create(item1, item2, item3, NULL);
    item1->setPosition(ccp(size.width / 2, size.height - 100));
    item2->setPosition(ccp(size.width / 2, size.height - 150));
    item3->setPosition(ccp(size.width / 2, size.height - 200));
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
    
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::item1(cocos2d::CCObject *pSender)
{
    CCLog("item1 press");
    CCDirector::sharedDirector()->replaceScene(switchScene(MyLayerBG::scene()));
}

void HelloWorld::item2(cocos2d::CCObject *pSender)
{
    CCLog("item2 press");
    CCDirector::sharedDirector()->replaceScene(switchScene(MyEffect::scene()));
}

void HelloWorld::item3(cocos2d::CCObject *pSender)
{
    CCLog("item3 press");
    CCDirector::sharedDirector()->replaceScene(switchScene(MyPariticle::scene()));
}
