#pragma once//compile only once
#include<iostream>
using namespace std;
#include<vector>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
//speech manage class
class SpeechManager
{
    public:
    //constructor
    SpeechManager();
    //menu
    void show_Menu();
    //exit system
    void exitSystem();
    //destructor
    ~SpeechManager();
    //initial container and characters
    void initSpeech();
    //create 12 member
    void createSpeaker();
    //begin competition, process control func
    void startSpeech();
    //draw lots
    void speedDraw();
    //contest
    void speechContest();
    //charaters of member
    vector<int>v1;
    vector<int>v2;
    vector<int>vVictory;
    //save number and member
    map<int, Speaker>m_Speaker;
    //save times of competition
    int m_Index;

};
