//
//  MyPariticle.h
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-22.
//
//

#ifndef __liuym_zongjie_project__MyPariticle__
#define __liuym_zongjie_project__MyPariticle__

#include "cocos2d.h"

class MyPariticle : public cocos2d::CCLayer {
protected:
    cocos2d::CCParticleSystem* m_emitter;
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void backMainScene();
    void backCallback(cocos2d::CCObject* pSender);
    void restartCallback(cocos2d::CCObject* pSender);
    void nextCallback(cocos2d::CCObject* pSender);
    
    virtual void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    
    void setEmitterPostion();
    
    CREATE_FUNC(MyPariticle);
};

class ParticleDemo : public MyPariticle {
public:
    virtual bool init();
    
    CREATE_FUNC(ParticleDemo)
};

#endif /* defined(__liuym_zongjie_project__MyPariticle__) */
