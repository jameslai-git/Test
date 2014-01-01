//
//  MenuTableViewLayer.h
//  life
//
//  Created by James Lai on 14-1-1.
//
//

#ifndef life_MenuTableViewLayer_h
#define life_MenuTableViewLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ScoreRecord.h"

class MenuTableViewLayer : public cocos2d::CCLayer, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
    
    std::list<ScoreRecord> *pScoreRecordList;
    int cityId;
    
    static MenuTableViewLayer* create(int cityId, std::list<ScoreRecord> *pScoreRecordList);
    virtual bool init();

    
	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view){}
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view){}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
};


#endif
