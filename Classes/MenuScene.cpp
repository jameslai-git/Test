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
    _menuLayer=NULL;
}

MenuScene::~MenuScene(void)
{
}

bool MenuScene::init()
{
    bool bRet=false;
    do
    {
        std::list<ScoreRecord> ScoreRecordList;
        ScoreRecordList.push_back(ScoreRecord(1, 1, 2000, 2));
        ScoreRecordList.push_back(ScoreRecord(2, 2, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(3, 3, 2000, 1));
        ScoreRecordList.push_back(ScoreRecord(4, 4, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(5, 5, 2000, 2));
        ScoreRecordList.push_back(ScoreRecord(6, 6, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(7, 7, 2000, 1));
        ScoreRecordList.push_back(ScoreRecord(8, 8, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(9, 9, 2000, 2));
        ScoreRecordList.push_back(ScoreRecord(10, 10, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(11, 11, 2000, 1));
        ScoreRecordList.push_back(ScoreRecord(12, 12, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(13, 13, 2000, 2));
        ScoreRecordList.push_back(ScoreRecord(14, 14, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(15, 15, 2000, 1));
        ScoreRecordList.push_back(ScoreRecord(16, 16, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(17, 17, 2000, 2));
        ScoreRecordList.push_back(ScoreRecord(18, 18, 2000, 3));
        ScoreRecordList.push_back(ScoreRecord(19, 19, 2000, 1));
        ScoreRecordList.push_back(ScoreRecord(20, 20, 2000, 3));
        CC_BREAK_IF(!CCScene::init());
        _menuLayer=MenuTableViewLayer::create(1, &ScoreRecordList);
        CC_BREAK_IF(!_menuLayer);
        this->addChild(_menuLayer);
        bRet=true;
    } while (0);
    
    return bRet;
}
