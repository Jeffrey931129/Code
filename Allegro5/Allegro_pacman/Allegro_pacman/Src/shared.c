// [shared.c]
// you should define the shared variable declared in the header here.

#include "shared.h"
#include "utility.h"
#include "game.h"
// #include "scene_menu.h"

ALLEGRO_FONT* font_pirulen_32;
ALLEGRO_FONT* font_pirulen_24;
ALLEGRO_SAMPLE* themeMusic = NULL;
ALLEGRO_SAMPLE* animeMusic = NULL;
ALLEGRO_SAMPLE* PACMAN_MOVESOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_DEATH_SOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_VICTORY_SOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_PB_SOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_EATGHOST = NULL;
ALLEGRO_SAMPLE* BOMB = NULL;
ALLEGRO_SAMPLE* TRAP = NULL;
ALLEGRO_SAMPLE* DISAPPEAR = NULL;
ALLEGRO_FONT* menuFont = NULL;
int fontSize = 30;
float music_volume = 0.5;
float effect_volume = 0.5;
bool gameDone = false;
extern int mode_pick;

/*
	A way to accelerate is load assets once.
	And delete them at the end.
	This method does provide you better management of memory.
	
*/
void shared_init(void) {
	
	menuFont = load_font("Assets/Minecraft.ttf", fontSize);
	themeMusic = load_audio("Assets/Music/original_theme.ogg");
	animeMusic = load_audio("Assets/Music/anime.ogg");
	PACMAN_MOVESOUND = load_audio("Assets/Music/pacman-chomp.ogg");
	PACMAN_DEATH_SOUND = load_audio("Assets/Music/pacman_death.ogg");
	PACMAN_VICTORY_SOUND = load_audio("Assets/Music/pacman_intermission.ogg");
	PACMAN_PB_SOUND = load_audio("Assets/Music/pacman_eatfruit.ogg");
	PACMAN_EATGHOST = load_audio("Assets/Music/pacman_eatghost.ogg");
	BOMB = load_audio("Assets/Music/bomb.ogg");
	TRAP = load_audio("Assets/Music/trap.ogg");
	DISAPPEAR = load_audio("Assets/Music/disappear.ogg");
}

void shared_destroy(void) {

	al_destroy_font(menuFont);
	al_destroy_sample(themeMusic);
	al_destroy_sample(PACMAN_MOVESOUND);
	al_destroy_sample(PACMAN_DEATH_SOUND);
}