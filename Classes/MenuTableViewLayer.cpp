//
//  MenuTableViewLayer.cpp
//  life
//
//  Created by James Lai on 14-1-1.
//
//

#include "MenuTableViewLayer.h"
#include "ScoreRecord.h"

USING_NS_CC;
USING_NS_CC_EXT;

MenuTableViewLayer* MenuTableViewLayer::create(int iCityId, std::list<ScoreRecord> *ipScoreRecordList)
{
    MenuTableViewLayer* pRet = new MenuTableViewLayer();
    if(pRet)
    {
        pRet->pScoreRecordList = ipScoreRecordList;
        pRet->cityId = iCityId;
        if(pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
    }

    delete pRet;
    pRet = NULL;
    return NULL;
}


// on "init" you need to initialize your instance
bool MenuTableViewLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCLOG("winsize=(%f,%f)", winSize.width,winSize.height);
    CCTableView* tableView = CCTableView::create(this, winSize);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setPosition(ccp(winSize.width/2,0));
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    return true;
}

void MenuTableViewLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLOG("cell touched at index: %i", cell->getIdx());
}

CCSize MenuTableViewLayer::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    //if (idx == 2) {
    //    return CCSizeMake(100, 100);
    //}
    return CCSizeMake(300, 60);
}

CCTableViewCell* MenuTableViewLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCString *string = CCString::createWithFormat("%d", idx);
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        CCSprite *sprite = CCSprite::create("Image/button_new_game.png");
		//sprite->setScale(0.2f);
        sprite->setPosition(ccp(0, 0));
        sprite->setAnchorPoint(ccp(0.5,0.5));
		sprite->setTag(123);
        cell->addChild(sprite);
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(ccp(160,0));
        label->setTag(456);
        cell->addChild(label);
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(456);
        label->setString(string->getCString());
    }
    return cell;
}

unsigned int MenuTableViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return pScoreRecordList->size();
}