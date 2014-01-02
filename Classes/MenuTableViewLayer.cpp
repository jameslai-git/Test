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

MenuTableViewLayer* MenuTableViewLayer::create(int iCityId, std::vector<ScoreRecord> *ipScoreRecordVector)
{
    MenuTableViewLayer* pRet = new MenuTableViewLayer();
    if(pRet)
    {
        pRet->pScoreRecordVector = ipScoreRecordVector;
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
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setPosition(ccp(20,-80));
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
    return CCSizeMake(600, 60);
}

CCTableViewCell* MenuTableViewLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCString *string = CCString::createWithFormat("LEVEL %d     score: %d", idx+1, pScoreRecordVector->at(idx).score);

    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        CCSprite *sprite = CCSprite::create("Image/bg_table_cell.png");
		//sprite->setScale(0.2f);
        sprite->setPosition(ccp(0, 0));
        sprite->setAnchorPoint(ccp(0,0));
		sprite->setTag(123);
        cell->addChild(sprite);
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(ccp(10,20));
        label->setAnchorPoint(ccp(0, 0));
        label->setTag(456);
        cell->addChild(label);
    
        CCSprite *stars;
        CCLOG("star = %i", pScoreRecordVector->at(idx).stars);
        
        if(pScoreRecordVector->at(idx).stars == 1)
        {
            stars = CCSprite::create("Image/star1.png");
        }
        else if(pScoreRecordVector->at(idx).stars == 2)
        {
            stars = CCSprite::create("Image/star2.png");
        }
        else //(pScoreRecordVector->at(idx).stars == 3)
        {
            stars = CCSprite::create("Image/star3.png");
        }

        stars->setPosition(ccp(400, 10));
        stars->setAnchorPoint(ccp(0,0));
        cell->addChild(stars);
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
    return 10;//pScoreRecordVector->size();
}