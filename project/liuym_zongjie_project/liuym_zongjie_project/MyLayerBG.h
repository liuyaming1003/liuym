//
//  MyLayerBG.h
//  liuym_zongjie_project
//
//  Created by liuym  on 13-3-21.
//
//

#ifndef __liuym_zongjie_project__MyLayerBG__
#define __liuym_zongjie_project__MyLayerBG__

#include "cocos2d.h"

class MyLayerBG : public cocos2d::CCLayer {
public:
    static cocos2d::CCScene* scene();
    
    virtual bool init();
    void backMainScene();
    CREATE_FUNC(MyLayerBG);
};

class BgLayer : public cocos2d::CCLayerColor {
public:
    virtual bool init();
    CREATE_FUNC(BgLayer);
};

class CloudLayer : public cocos2d::CCLayerColor {
public:
    virtual bool init();
    CREATE_FUNC(CloudLayer);
};

class HillLayer : public cocos2d::CCLayerColor {
public:
    virtual bool init();
    CREATE_FUNC(HillLayer);
};

#endif /* defined(__liuym_zongjie_project__MyLayerBG__) */
