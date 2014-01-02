//
//  MenuScene.cpp
//  life
//
//  Created by James Lai on 13-12-30.
//
//

#include "MenuScene.h"



MenuScene::MenuScene(void)
{
    _menuTableViewLayer=NULL;
}

MenuScene::~MenuScene(void)
{
}

bool MenuScene::init()
{
    bool bRet=false;
    do
    {
        std::vector<ScoreRecord> ScoreRecordVector;
        ScoreRecordVector.push_back(ScoreRecord(1, 1, 5000, 2));
        ScoreRecordVector.push_back(ScoreRecord(2, 2, 10000, 3));
        ScoreRecordVector.push_back(ScoreRecord(3, 3, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(4, 4, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(5, 5, 4000, 2));
        ScoreRecordVector.push_back(ScoreRecord(6, 6, 9000, 3));
        ScoreRecordVector.push_back(ScoreRecord(7, 7, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(8, 8, 12000, 3));
        ScoreRecordVector.push_back(ScoreRecord(9, 9, 6000, 2));
        ScoreRecordVector.push_back(ScoreRecord(10, 10, 11000, 3));
        /*
        ScoreRecordVector.push_back(ScoreRecord(11, 11, 1000, 1));
        ScoreRecordVector.push_back(ScoreRecord(12, 12, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(13, 13, 5000, 2));
        ScoreRecordVector.push_back(ScoreRecord(14, 14, 10000, 3));
        ScoreRecordVector.push_back(ScoreRecord(15, 15, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(16, 16, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(17, 17, 4000, 2));
        ScoreRecordVector.push_back(ScoreRecord(18, 18, 9000, 3));
        ScoreRecordVector.push_back(ScoreRecord(19, 19, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(20, 20, 12000, 3));

        ScoreRecordVector.push_back(ScoreRecord(1, 1, 5000, 2));
        ScoreRecordVector.push_back(ScoreRecord(2, 2, 10000, 3));
        ScoreRecordVector.push_back(ScoreRecord(3, 3, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(4, 4, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(5, 5, 4000, 2));
        ScoreRecordVector.push_back(ScoreRecord(6, 6, 9000, 3));
        ScoreRecordVector.push_back(ScoreRecord(7, 7, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(8, 8, 12000, 3));
        ScoreRecordVector.push_back(ScoreRecord(9, 9, 6000, 2));
        ScoreRecordVector.push_back(ScoreRecord(10, 10, 11000, 3));
        ScoreRecordVector.push_back(ScoreRecord(11, 11, 1000, 1));
        ScoreRecordVector.push_back(ScoreRecord(12, 12, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(13, 13, 5000, 2));
        ScoreRecordVector.push_back(ScoreRecord(14, 14, 10000, 3));
        ScoreRecordVector.push_back(ScoreRecord(15, 15, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(16, 16, 8000, 3));
        ScoreRecordVector.push_back(ScoreRecord(17, 17, 4000, 2));
        ScoreRecordVector.push_back(ScoreRecord(18, 18, 9000, 3));
        ScoreRecordVector.push_back(ScoreRecord(19, 19, 2000, 1));
        ScoreRecordVector.push_back(ScoreRecord(20, 20, 12000, 3));
*/
        CC_BREAK_IF(!CCScene::init());
        _menuTableViewLayer=MenuTableViewLayer::create(3, &ScoreRecordVector);
        CC_BREAK_IF(!_menuTableViewLayer);
        this->addChild(_menuTableViewLayer);
        
        CCString *city = CCString::create("");
        if(_menuTableViewLayer->cityId == 1)
        {
            city = CCString::create("广州");
        }else if(_menuTableViewLayer->cityId == 2)
        {
            city = CCString::create("上海");
        }else if(_menuTableViewLayer->cityId == 3)

        {
            city = CCString::create("北京");
        }
        
        CCLabelTTF *label = CCLabelTTF::create(city->getCString(), "Helvetica", 40.0);
        label->setPosition(ccp(250,900));
        label->setAnchorPoint(ccp(0, 0));
        this->addChild(label);
        
        
        
        bRet=true;
    } while (0);
    
    return bRet;
}
