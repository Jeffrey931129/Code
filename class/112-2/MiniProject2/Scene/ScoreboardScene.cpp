#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "ScoreboardScene.hpp"
using namespace std;

struct Rank{
    int score;
    string name;
    Rank(int x,string y):score(x),name(y){
    }
};

vector<Rank> scoreboard; 
int w,h,halfW,halfH,lenth;
static int page=0;

void ScoreboardScene::Initialize() {
    w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    halfW = w / 2;
    halfH = h / 2;
    Engine::ImageButton* btn;
    
    // Title
    AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 48, halfW, 100, 255, 255, 255, 255, 0.5, 0.5));
    
    // Back
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::BackOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    
    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
	bgmInstance = AudioHelper::PlaySample("select.ogg", true, 0.0);

    // .txt
    ifstream file("C:/Code/class/112-2/MiniProject2/Resource/scoreboard.txt");
    string name; int score;
    scoreboard.clear();
    while(file>>name&&file>>score){
        scoreboard.push_back(Rank(score,name));
    }
    file.close(); lenth=scoreboard.size();
    for(int i=0;i<5&&i+page*5<lenth;i++){
        AddNewObject(new Engine::Label(scoreboard[i+page*5].name, "pirulen.ttf", 48, halfW-250, halfH * 1 / 2+50*i, 255, 255, 255, 255, 0.5, 0.5));
        AddNewObject(new Engine::Label(to_string(scoreboard[i+page*5].score), "pirulen.ttf", 48, halfW+250, halfH * 1 / 2+50*i, 255, 255, 255, 255, 0.5, 0.5));
    }

    // switch page
    if(page){
        btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 650, halfH * 3 / 2 - 50, 400, 100);
        btn->SetOnClickCallback(std::bind(&ScoreboardScene::PrevOnClick, this, 1));
        AddNewControlObject(btn);
        AddNewObject(new Engine::Label("Prev", "pirulen.ttf", 48, halfW-450, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    }

    if((page+1)*5<lenth){
        btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW +250, halfH * 3 / 2 - 50, 400, 100);
        btn->SetOnClickCallback(std::bind(&ScoreboardScene::NextOnClick, this, 1));
        AddNewControlObject(btn);
        AddNewObject(new Engine::Label("Next", "pirulen.ttf", 48, halfW+450, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    }
}
void ScoreboardScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void ScoreboardScene::BackOnClick(int stage) {
    page=0;
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void ScoreboardScene::PrevOnClick(int stage) {
    if(!page) return;
    page--;
    Engine::GameEngine::GetInstance().ChangeScene("scoreboard");
}
void ScoreboardScene::NextOnClick(int stage) {
    if((page+1)*5>=lenth) return;
    page++;
    Engine::GameEngine::GetInstance().ChangeScene("scoreboard");
}
