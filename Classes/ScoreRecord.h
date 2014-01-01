//
//  ScoreRecord.h
//  life
//
//  Created by James Lai on 13-12-30.
//
//

#ifndef life_ScoreRecord_h
#define life_ScoreRecord_h

class ScoreRecord{
public:
    int rid;
    int level;
    int stars;
    int score;
    ScoreRecord(int iRid, int iLevel, int iStars, int iScore);
};

#endif
