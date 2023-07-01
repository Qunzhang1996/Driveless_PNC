#include<iostream>
#include<cstdlib>
using namespace std;
#include"speedManager.h"
#include<algorithm>

int main()
{
    SpeechManager sm;
    for(map<int,Speaker>::iterator it=sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++)
    {
        cout<<"member: "<<it->first<<"  name:  "<<it->second.m_Name<<endl;
    }
    

    int choice =0;
    while(true)
    {
        sm.show_Menu();
        cout<<"Please input your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            /* Start the speed competition*/
            sm.startSpeech();
            break;
        case 2:
            /*check the history*/
            break;
        case 3:
            /*clear all data*/
            break;
        case 0:
            /* exit */
            sm.exitSystem();
            break;
        default:
            system("clear");
            break;
        }
    }
    return 0;
}