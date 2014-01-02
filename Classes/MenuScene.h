//
//  MenuScene.h
//  life
//
//  Created by James Lai on 13-12-30.
//
//

#ifndef __life__MenuScene__
#define __life__MenuScene__



#include "cocos2d.h"
#include "MenuTableViewLayer.h"

USING_NS_CC;

class MenuScene :
public CCScene
{
public:
    MenuScene(void);
    
    ~MenuScene(void);
    
    virtual bool init();
    
    CREATE_FUNC(MenuScene);

    
public:
    MenuTableViewLayer* _menuTableViewLayer;
};


#endif /* defined(__life__MenuScene__) */
