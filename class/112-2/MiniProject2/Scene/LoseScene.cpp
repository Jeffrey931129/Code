#include <functional>
#include <string>
#include <fstream>
#include <set>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "LoseScene.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/LOG.hpp"
using namespace std;

struct Rank{
    int score;
    string name;
    Rank(int x,string y):score(x),name(y){}
};
struct compare{
	bool operator()(const Rank& x,const Rank& y)const{
		if(x.score==y.score){
			return x.name<y.name;
		}
		else return x.score>y.score;
	}
};

string new_name;
extern int w,h,halfW,halfH;

void LoseScene::Initialize() {
	// TODO: [HACKATHON-1-SCENE] (1/4): You can imitate the 2 files: 'LoseScene.hpp', 'LoseScene.cpp' to implement your start scene.
	w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	halfW = w / 2;
	halfH = h / 2;
	AddNewObject(new Engine::Image("lose/benjamin-happy.png", halfW, halfH, 0, 0, 0.5, 0.5));
	AddNewObject(new Engine::Label("You Lose :(", "pirulen.ttf", 48, halfW, halfH / 4 + 10, 255, 255, 255, 255, 0.5, 0.5));
	
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW +300, halfH * 7 / 4 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&LoseScene::BackOnClick, this, 2));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Enter", "pirulen.ttf", 48, halfW+500, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));
    
	bgmInstance = AudioHelper::PlaySample("astronomia.ogg", false, AudioHelper::BGMVolume, PlayScene::DangerTime);
	
	AddNewObject(new Engine::Label("Name:", "pirulen.ttf", 48, halfW-450, halfH * 7 / 4, 255, 255, 255, 255, 0.5, 0.5));
	new_name.clear();
	AddNewObject(new Engine::Label(new_name, "pirulen.ttf", 48, halfW, halfH * 7 / 4, 255, 255, 255, 255, 0.5, 0.5));
}
void LoseScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void LoseScene::BackOnClick(int stage) {
	ifstream fin("C:/Code/class/112-2/MiniProject2/Resource/scoreboard.txt");
	multiset<Rank,compare> scoreboard;
	int score; string name;
	while(fin>>name&&fin>>score){
		scoreboard.insert(Rank(score,name));
	}
	if(!new_name.size()) new_name="Unknown";
	// std::cout<<final_score<<std::endl;
	scoreboard.insert(Rank(final_score,new_name));
	// for(auto i:scoreboard){
	// 	std::cout<<i.name<<" "<<i.score<<std::endl;
	// }
	fin.close();
	ofstream fout("C:/Code/class/112-2/MiniProject2/Resource/scoreboard.txt");
	for(auto i:scoreboard){
		fout<<i.name<<" "<<i.score<<endl;
	}
	fout.close();
	// Change to select scene.
	Engine::GameEngine::GetInstance().ChangeScene("start");
}
void LoseScene::Draw() const{
	IScene::Draw();
}
void LoseScene::OnKeyDown(int keyCode){
	IScene::OnKeyDown(keyCode);
	if(keyCode>=ALLEGRO_KEY_A&&keyCode<=ALLEGRO_KEY_Z){
		if(new_name.size()<10){
			new_name.push_back(keyCode+'A'-1);
		}
	}
	else if(keyCode==ALLEGRO_KEY_BACKSPACE){
		if(new_name.size()){
			new_name.pop_back();
		}
	}
	else if(keyCode==ALLEGRO_KEY_ENTER){
		BackOnClick(1);
	}
	RemoveObject(prev(objects.end()));
	AddNewObject(new Engine::Label(new_name, "pirulen.ttf", 48, halfW, halfH * 7 / 4, 255, 255, 255, 255, 0.5, 0.5));
}
