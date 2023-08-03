#include"speedManager.h"
    //constructor
    SpeechManager::SpeechManager()
    {
        this->initSpeech();
        this->createSpeaker();
    }
    //menu
    void SpeechManager::show_Menu()
    {
        cout<<"welcome to the speed competition"<<endl;
        cout<<"1.Start the speed competition"<<endl;
        cout<<"2.Check the history"<<endl;
        cout<<"3.Clear all data"<<endl;
        cout<<"0.EXit!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
    }
    //exit system
    void SpeechManager::exitSystem()
    {
        cout<<"____________________"<<endl;
        cout<<"welcome to use it next time"<<endl;
        system("pause");
        exit(0);

    }
    void SpeechManager::initSpeech()
    {
        //set container empty
        this->v1.clear();
        this->v2.clear();
        this->vVictory.clear();
        this->m_Speaker.clear();
        //init number of competition
        this->m_Index=1;

    }
    //create 12 member
    void SpeechManager::createSpeaker(){
        string nameSeed="ABCDEFGHIJKL";
        for(int i=0;i<nameSeed.size();i++)
        {
            string name="member: ";
            name+=nameSeed[i];

            Speaker sp;
            sp.m_Name=name;
            for(int j=0;j<2;j++)
            {
                sp.m_Score[j]=0;
            }
            //create number and put it into vector container
        this->v1.push_back(i+10001);
        //put into map
        this->m_Speaker.insert(make_pair(i+10001, sp));
        }
    }
    void SpeechManager::startSpeech()
    {
        //1.Draw lot
        this->speedDraw();
        //contest
        this->speechContest();


    }
    //draw lots
    void SpeechManager::speedDraw()
    {
        cout<<"The <<"<<this->m_Index<<">> Draw lot is starting"<<endl;
        cout<<"____________________________________"<<endl;
        cout<<"the sequence is shown below:  "<<endl;
        if (this->m_Index==1)
        {
            for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
            {
                cout<<*it<<"  ";
            }
            random_shuffle(v1.begin(),v1.end());
        }else
        {
            random_shuffle(v2.begin(),v2.end());
            for (vector<int>::iterator it=v2.begin();it!=v2.end();it++)
            {
                cout<<*it<<"  ";
            }
            cout<<"____________________________________"<<endl;
        }
    }
    //contest
    void SpeechManager::speechContest()
    {
        cout<<"________________The  "<<this->m_Index<<" competition started!___________________ "<<endl;
        vector<int>v_Src; //container to save player
        if(this->m_Index ==1)
        {
            v_Src=v1;
        }else
        {
            v_Src=v2;
        }
        for (vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++)
        {
            //judges score
            deque<double>d;
            for(int i=0;i<10;i++)
            {
                double score =(rand()%401+600)/10.f;
                cout<<score<<"  ";
                d.push_back(score);
            }
            cout<<endl;
            sort(d.begin(),d.end(),greater<double>());
            d.pop_front();
            d.pop_back();
            double sum=accumulate(d.begin(),d.end(),0.0f);//sum
            double avg=sum/(double)d.size();//avg
            
            this->m_Speaker[*it].m_Score[this->m_Index-1]=avg;
        }
        cout<<endl;
    }
    //destructor
    SpeechManager::~SpeechManager()
    {

    }
    
