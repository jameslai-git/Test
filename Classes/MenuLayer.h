//
//  MenuLayer.h
//  life
//
//  Created by James Lai on 13-12-30.
//
//

#ifndef life_MenuLayer_h
#define life_MenuLayer_h

#include "cocos2d.h"
#include "ScoreRecord.h"
#include "list.h"
using namespace cocos2d;


class MenuLayer :
public CCLayer, public CCTableViewDelegate, public CCTableViewDataSource
{
public:
    
    MenuLayer(void);
    
    ~MenuLayer(void);
    
    virtual bool init(int cityId, std::list<ScoreRecord> *pScoreRecordList);
    
    static MenuLayer* create(int cityId, std::list<ScoreRecord> *pScoreRecordList);
    
    void menuItemPressed(CCObject *sender);

};

#endif
