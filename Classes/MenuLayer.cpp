//
//  MenuLayer.cpp
//  life
//
//  Created by James Lai on 13-12-30.
//
//

#include "MenuLayer.h"

MenuLayer::MenuLayer(void)
{
}

MenuLayer::~MenuLayer(void)
{
}

MenuLayer* MenuLayer::create(int cityId, std::list<ScoreRecord> *pScoreRecordList)
{
    
    MenuLayer* pRet = new MenuLayer();
    if(pRet && pRet->init(cityId, pScoreRecordList))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
    
}

bool MenuLayer::init(int cityId, std::list<ScoreRecord> *pScoreRecordList)
{
    bool bRet=false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        
        
        // Place the sprite on the center of the screen
		CCSize size = CCDirector::sharedDirector()->getWinSize();
        //行间距
		int gapLine = 20;
        //一个菜单子项和行间距高度的和
		int heightItem = 50 + gapLine;
		//菜单的起始纵坐标
		int yStart = 800;
        
        CCLOG ("size is: %f, %f\n", size.width,size.height);
        
        CCArray *menuArray = CCArray::create();
        
        for(int i=0; i<pScoreRecordList->size(); i++)
        {
            CCMenuItemImage *menuItem = CCMenuItemImage::create("Image/button_new_game.png", "Image/button_new_game_pressed.png", this, menu_selector(MenuLayer::menuItemPressed));
            //menuItem->setTag(10000+cityId*100+pScoreRecordList[i].level);
//            int heightItem = menuItem->getContentSize().height + gapLine;
            menuItem->setTag(10000+cityId*100+i);
            menuItem->setPosition(ccp(0, -50*i));
            
            menuArray->addObject(menuItem);
        }
        
        //创建菜单
		CCMenu *menu = CCMenu::createWithArray(menuArray);
		menu->setPosition(size.width/2, yStart);
		this->addChild(menu);
        
        this->setKeypadEnabled(true);
        
        bRet=true;
    } while (0);
    
    return bRet;
}

void MenuLayer::menuItemPressed(CCObject *sender)
{
    CCLOG ("id is: %d\n", (static_cast<CCNode*>(sender))->getTag());
}
