//
//  MyEffect.h
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-22.
//
//

#ifndef __liuym_zongjie_project__MyEffect__
#define __liuym_zongjie_project__MyEffect__

#include "cocos2d.h"

class MyEffect : public cocos2d::CCLayer {
protected:
    cocos2d::CCSprite* m_sprite;
public:
    virtual bool init();
    virtual std::string title();
    void backMainScene();
    static cocos2d::CCScene* scene();
    
public:
    void backCallback(cocos2d::CCObject* pSender);
    void nextCallback(cocos2d::CCObject* pSender);
    void restartCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(MyEffect);
};

//以下的类都是特效类
class Shaky3DDemo : public cocos2d::CCShaky3D
{
public:
    static cocos2d::CCActionInterval* actionWithDuration(float t)
    {
        return CCShaky3D::create(t, cocos2d::CCSizeMake(15, 10), 10, true);
    }
    
};

class Waves3DDemo : public cocos2d::CCWaves3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCWaves3D::create(t, cocos2d::CCSizeMake(15,10), 5,  40);
    }
};

class FlipX3DDemo : public cocos2d::CCFlipX3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFlipX3D* flipx  = CCFlipX3D::create(t);
        CCActionInterval* flipx_back = flipx->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(2);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(flipx, delay, flipx_back, NULL));
    }
};

class FlipY3DDemo : public cocos2d::CCFlipY3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFlipY3D* flipy  = CCFlipY3D::create(t);
        CCActionInterval* flipy_back = flipy->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(2);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(flipy, delay, flipy_back, NULL));
    }
};

class Lens3DDemo : public cocos2d::CCLens3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        return CCLens3D::create(t, cocos2d::CCSizeMake(15,10), cocos2d::CCPointMake(size.width/2,size.height/2), 440);
    }
};


class Ripple3DDemo : public cocos2d::CCRipple3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        return CCRipple3D::create(t, cocos2d::CCSizeMake(32,24), cocos2d::CCPointMake(size.width/2,size.height/2), 880, 4, 40);
    }
};


class LiquidDemo : public cocos2d::CCLiquid
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCLiquid::create(t, cocos2d::CCSizeMake(16,12), 4 , 20);
    }
};


class WavesDemo : public cocos2d::CCWaves
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCWaves::create(t, cocos2d::CCSizeMake(16,12), 6, 20, true, true);
    }
};


class TwirlDemo : public cocos2d::CCTwirl
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        return CCTwirl::create(t , cocos2d::CCSizeMake(12,8), cocos2d::CCPointMake(size.width/2, size.height/2),  1.5f,  20);
    }
};


class ShakyTiles3DDemo : public cocos2d::CCShakyTiles3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCShakyTiles3D::create(t, cocos2d::CCSizeMake(16,12), 20 , true) ;
    }
};


class ShatteredTiles3DDemo : public cocos2d::CCShatteredTiles3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCShatteredTiles3D::create(t, cocos2d::CCSizeMake(16,12), 5, true);
    }
};


class ShuffleTilesDemo : public cocos2d::CCShuffleTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCShuffleTiles* shuffle = CCShuffleTiles::create(t, cocos2d::CCSizeMake(16,12), 25);
        CCActionInterval* shuffle_back = shuffle->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(2);
        
        return (cocos2d::CCActionInterval*)(cocos2d::CCSequence::create(shuffle, delay, shuffle_back, NULL));
    }
};


class FadeOutTRTilesDemo : public cocos2d::CCFadeOutTRTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFadeOutTRTiles* fadeout = CCFadeOutTRTiles::create(t, cocos2d::CCSizeMake(16,12));
        CCActionInterval* back = fadeout->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.5f);
        
        return (cocos2d::CCActionInterval*)(cocos2d::CCSequence::create(fadeout, delay, back, NULL));
    }
};


class FadeOutBLTilesDemo : public cocos2d::CCFadeOutBLTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFadeOutBLTiles* fadeout = CCFadeOutBLTiles::create(t, cocos2d::CCSizeMake(16,12));
        CCActionInterval* back = fadeout->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.5f);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(fadeout, delay, back, NULL));
    }
};


class FadeOutUpTilesDemo : public cocos2d::CCFadeOutUpTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFadeOutUpTiles* fadeout = CCFadeOutUpTiles::create(t, cocos2d::CCSizeMake(16,12));
        CCActionInterval* back = fadeout->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.5f);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(fadeout, delay, back, NULL));
    }
};

class FadeOutDownTilesDemo : public cocos2d::CCFadeOutDownTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCFadeOutDownTiles* fadeout = CCFadeOutDownTiles::create(t, cocos2d::CCSizeMake(16,12));
        CCActionInterval* back = fadeout->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.5f);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(fadeout, delay, back, NULL));
    }
};

class TurnOffTilesDemo : public cocos2d::CCTurnOffTiles
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        CCTurnOffTiles* fadeout = CCTurnOffTiles::create(t, cocos2d::CCSizeMake(48,32) , 25);
        CCActionInterval* back = fadeout->reverse();
        cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.5f);
        
        return (CCActionInterval*)(cocos2d::CCSequence::create(fadeout, delay, back, NULL));
    }
};

class WavesTiles3DDemo : public cocos2d::CCWavesTiles3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCWavesTiles3D::create(t, cocos2d::CCSizeMake(15,10), 4, 40);
    }
};

class JumpTiles3DDemo : public cocos2d::CCJumpTiles3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
       // cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        return CCJumpTiles3D::create(t, cocos2d::CCSizeMake(15,10), 4, 30);
    }
};

class SplitRowsDemo : public cocos2d::CCSplitRows
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCSplitRows::create(t, 9);
    }
};

class SplitColsDemo : public cocos2d::CCSplitCols
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        return CCSplitCols::create(t, 9);
    }
};

class PageTurn3DDemo : public cocos2d::CCPageTurn3D
{
public:
    static CCActionInterval* actionWithDuration(float t)
    {
        cocos2d::CCDirector::sharedDirector()->setDepthTest(true);
        return CCPageTurn3D::create(t, cocos2d::CCSizeMake(15,10));
    }
};

#endif /* defined(__liuym_zongjie_project__MyEffect__) */
