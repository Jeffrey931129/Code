#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "shared.h"
#include "utility.h"
#include "scene_game.h"
#include "scene_menu.h"
#include "pacman_obj.h"
#include "ghost.h"
#include "map.h"


// TODO-HACKATHON 2-0: Create one ghost
// Just modify the GHOST_NUM to 1
int GHOST_NUM = 4;
// TODO-GC-ghost: create a least FOUR ghost! 完成
/* global variables*/
extern const uint32_t GAME_TICK_CD;
extern uint32_t GAME_TICK;
extern ALLEGRO_TIMER* game_tick_timer;
extern ALLEGRO_SAMPLE_ID PACMAN_MOVESOUND_ID;
extern ALLEGRO_SAMPLE_ID EATGHOST_MUSIC;
extern char go_up[2], go_down[2], go_left[2], go_right[2];
ALLEGRO_SAMPLE_ID BOMB_MUSIC;
ALLEGRO_SAMPLE_ID TRAP_MUSIC;
ALLEGRO_SAMPLE_ID DISAPPEAR_MUSIC;
extern int mode_pick;
char name[20];
int game_main_Score = 0;
bool game_over = false;
bool victory = false;
bool cheat_victory = false;
bool enter_name = false;
Trap trap;
Bomb bomb;
Explosion explosion;
ALLEGRO_SAMPLE_ID gameMusic;
/* Internal variables*/
ALLEGRO_TIMER* power_up_timer;
ALLEGRO_TIMER* move_timer;
ALLEGRO_TIMER* victory_timer;

ALLEGRO_BITMAP* bomb_picture;
ALLEGRO_BITMAP* explosion_picture;
ALLEGRO_BITMAP* smallfire_picture;
static const int power_up_duration = 10;
static Pacman* pman;
static Map* basic_map;
static Ghost** ghosts;
static int x = 0;
bool debug_mode = false;
bool cheat_mode = false;
bool ctrl = false;
bool break_wall = false;
/* Declare static function prototypes */
static void init(void);
static void step(void);
static void checkItem(void);
static void status_update(void);
static void update(void);
static void draw(void);
static void printinfo(void);
static void destroy(void);
static void on_key_up(int key_code);
static void on_key_down(int key_code);
static void on_mouse_down(int btn, int x, int y, int dz);
static void render_init_screen(void);
static void draw_hitboxes(void);
static void clean_rank(void);

static void init(void) {
	game_over = false;
	victory = false;
	cheat_victory = false;
	game_main_Score = 0;
	bomb_picture = load_bitmap("Assets/bomb.png");
	explosion_picture = load_bitmap("Assets/pacman_tile.png");
	smallfire_picture = load_bitmap("Assets/advance_die.png");
	bomb.x = 14, bomb.y = 7; bomb.exist = false;
	bomb.timer = al_create_timer(1.0f); al_set_timer_count(bomb.timer, 20);        // bomb
	explosion.timer = al_create_timer(1.0f); al_set_timer_count(explosion.timer, 2);
	victory_timer = al_create_timer(1.0f);
	move_timer = al_create_timer(1.0f / 8.0f);  // 我自己控制
	al_stop_timer(move_timer); al_set_timer_count(move_timer, 0); al_start_timer(move_timer);
	trap.time = al_create_timer(1.0f); al_set_timer_count(trap.time, 20);
	trap.picture = load_bitmap("Assets/trap.png");
	// create map
	//basic_map = create_map(NULL);
	// TODO-GC-read_txt: Create map from .txt file so that you can design your own map!!  完成
	basic_map = create_map("Assets/map_nthu.txt");
	if (!basic_map) {
		game_abort("error on creating map");
	}	
	// create pacman
	pman = pacman_create();
	if (!pman) {
		game_abort("error on creating pacamn\n");
	}
	
	// allocate ghost memory
	// TODO-HACKATHON 2-1: Allocate dynamic memory for ghosts array.
	memset(name, 0, sizeof(name)); x = 0;
	ghosts = (Ghost**)malloc(sizeof(Ghost*) * GHOST_NUM);
	
	if(!ghosts){
		game_log("We haven't create any ghosts!\n");
	}
	else {
		// TODO-HACKATHON 2-2: create a ghost.
		// Try to look the definition of ghost_create in ghost.h and figure out what should be placed here.
		for (int i = 0; i < GHOST_NUM; i++) {
			
			game_log("creating ghost %d\n", i);
			ghosts[i] = ghost_create(i);  
			if (!ghosts[i])
				game_abort("error creating ghost\n");
			
		}
	}
	GAME_TICK = 0;

	render_init_screen();
	power_up_timer = al_create_timer(1.0f); // 1 tick per second
	if (!power_up_timer)
		game_abort("Error on create timer\n");
	stop_bgm(gameMusic);
	gameMusic = play_bgm(themeMusic, music_volume);
	
	return ;
	
}

static void step(void) {
	if (pman->objData.moveCD > 0)
		pman->objData.moveCD -= pman->speed;
	for (int i = 0; i < GHOST_NUM; i++) {
		// important for movement
		if (ghosts[i]->objData.moveCD > 0)
			ghosts[i]->objData.moveCD -= ghosts[i]->speed;
	}
}
static void checkItem(void) {
	int Grid_x = pman->objData.Coord.x, Grid_y = pman->objData.Coord.y;
	static int pre_x, pre_y,temp;
	if (Grid_y >= basic_map->row_num - 1 || Grid_y <= 0 || Grid_x >= basic_map->col_num - 1 || Grid_x <= 0)
		return;
	// TODO-HACKATHON 1-3: check which item you are going to eat and use `pacman_eatItem` to deal with it.
	
	switch (basic_map->map[Grid_y][Grid_x])
	{
	case '.':
		pacman_eatItem(pman, basic_map->map[Grid_y][Grid_x]); game_main_Score += 20; 
		basic_map->map[Grid_y][Grid_x] = ' ';
		if (!(rand() % 30)&& al_get_timer_count(bomb.timer) >= 20) {    // 做炸彈
			al_stop_timer(bomb.timer); al_set_timer_count(bomb.timer, 0); al_start_timer(bomb.timer);
			bomb.x = Grid_x, bomb.y = Grid_y, bomb.exist=true;
		}
		break;
	case 'P':
		// TODO-GC-PB: ease power bean  完成
		// pacman_eatItem(...);
		// stop and reset power_up_timer value
		// start the timer
		pacman_eatItem(pman, basic_map->map[Grid_y][Grid_x]);
		al_stop_timer(power_up_timer);  al_set_timer_count(power_up_timer, 0);
		al_start_timer(power_up_timer); basic_map->map[Grid_y][Grid_x] = ' ';
		break;
	case 'X':
		temp = rand() % 4;
		ghosts[temp]->status = GO_IN,ghosts[temp]->speed = 4 ; basic_map->map[Grid_y][Grid_x] = ' ';
		explosion.area = getDrawArea((object*)ghosts[temp], GAME_TICK_CD);
		al_stop_timer(explosion.timer); al_set_timer_count(explosion.timer, 0); al_start_timer(explosion.timer);
		al_stop_timer(bomb.timer); al_set_timer_count(bomb.timer, 20); bomb.exist = false;
		stop_bgm(BOMB_MUSIC);
		BOMB_MUSIC = play_audio(BOMB, effect_volume);
		break;
	default:
		break;
	}

	if (pre_x != Grid_x || pre_y != Grid_y) {
		stop_bgm(PACMAN_MOVESOUND_ID);
		PACMAN_MOVESOUND_ID = play_audio(PACMAN_MOVESOUND, effect_volume);
		pre_x = Grid_x, pre_y = Grid_y;
	}

	if (game_main_Score / 20 == basic_map->beansNum || cheat_victory) {
		victory = true;
		stop_bgm(PACMAN_MOVESOUND_ID); stop_bgm(gameMusic);
		PACMAN_MOVESOUND_ID = play_audio(PACMAN_VICTORY_SOUND, effect_volume);
	}
	// TODO-HACKATHON 1-4: erase the item you eat from map
	// Be careful, don't erase the wall block.
}
static void status_update(void) {
	// TODO-PB: check powerUp duration  完成
	
	if (pman->powerUp)
	{
		// Check the value of power_up_timer
		// If runs out of time reset all relevant variables and ghost's status
		// hint: ghost_toggle_FLEE
		if (al_get_timer_count(power_up_timer) < 10) {
			for (int i = 0; i < GHOST_NUM; i++) {
				if (ghosts[i]->status != GO_IN) {
					ghosts[i]->status = FLEE; ghosts[i]->speed = 1;
				}
				  
			}
		}
		else {
			pman->powerUp = false;
			for (int i = 0; i < GHOST_NUM; i++) {
				ghosts[i]->status = GO_OUT;
				ghosts[i]->speed = 2;
			}	
			al_stop_timer(power_up_timer);  al_set_timer_count(power_up_timer,0);
			pman->speed = 2;
		}
	}
	


	for (int i = 0; i < GHOST_NUM; i++) {
		if (ghosts[i]->status == GO_IN){
			continue;
		}
		else if (ghosts[i]->status == FREEDOM)
		{
			// TODO-GC-game_over 完成
			// Use `getDrawArea(..., GAME_TICK_CD)` and `RecAreaOverlap(..., GAME_TICK_CD)` functions to detect if pacman and ghosts collide with each other.
			// And perform corresponding operations.
			// [NOTE] You should have some if-else branch here if you want to implement power bean mode.
			// Uncomment Following Code
			RecArea x = getDrawArea(&pman->objData, GAME_TICK_CD), y = getDrawArea(&ghosts[i]->objData, GAME_TICK_CD);
			if(!cheat_mode && RecAreaOverlap(&x,&y))
			{
					game_log("collide with ghost\n");
					al_rest(1.0);
					pacman_die();
					game_over = true;
					break; // animation shouldn't be trigger twice.
			}
			
		}
		else if (ghosts[i]->status == FLEE)
		{
			// TODO-GC-PB: 吃鬼  完成
			// If ghost is collided by pacman, it should go back to the room immediately and come out after a period.
			RecArea x = getDrawArea(&pman->objData, GAME_TICK_CD), y = getDrawArea(&ghosts[i]->objData, GAME_TICK_CD);
			if (RecAreaOverlap(&x, &y))
			{
				ghost_collided(ghosts[i]);
				stop_bgm(EATGHOST_MUSIC);
				EATGHOST_MUSIC = play_audio(PACMAN_EATGHOST, effect_volume);
			}
			
		}
	}

	if (al_get_timer_count(trap.time) < 10) {
		RecArea x = getDrawArea(&pman->objData, GAME_TICK_CD), y = trap.area;
		if (!cheat_mode && RecAreaOverlap(&x, &y))
		{
			game_log("collide with trap\n");
			al_rest(1.0);
			pacman_die();
			game_over = true;
			 // animation shouldn't be trigger twice.
		}
	}
}

static void update(void) {
	if (al_get_timer_count(move_timer) > 100000000000000)
		al_set_timer_count(move_timer, 0);
	if (victory) {
		al_start_timer(victory_timer);
		if (al_get_timer_count(victory_timer) >= 6) {
			al_stop_timer(victory_timer); al_set_timer_count(victory_timer, 0);
			enter_name=true;
		}
		return;
	}
	if (game_over) {
		// TODO-GC-game_over  完成
		// Start pman->death_anim_counter and schedule a game-over event (e.g change scene to menu) after Pacman's death animation finished
		// hint: refer al_get_timer_started(...), al_get_timer_count(...), al_stop_timer(...), al_rest(...)
		
			// start the timer if it hasn't been started.
		al_start_timer(pman->death_anim_counter);
			// check timer counter.
		if (al_get_timer_count(pman->death_anim_counter) >= 12) {
			al_stop_timer(pman->death_anim_counter);
			enter_name = true;
		}
			
		//printf("success end\n");
		
			// stop the timer if counter reach desired time.
		
		
		return;
	}

	step();
	checkItem();
	status_update();
	pacman_move(pman, basic_map);
	for (int i = 0; i < GHOST_NUM; i++) 
		ghosts[i]->move_script(ghosts[i], basic_map, pman);

	if (al_get_timer_count(bomb.timer) >= 10&& al_get_timer_count(bomb.timer) < 20&&bomb.exist) {   // 控制炸彈
		basic_map->map[bomb.y][bomb.x] = 'X';
	}
	else if (al_get_timer_count(bomb.timer) >= 20&&bomb.exist) {
		basic_map->map[bomb.y][bomb.x] = ' ', bomb.exist=false;
		al_stop_timer(bomb.timer);
	}

	if ((al_get_timer_count(move_timer)%120 == 104 || al_get_timer_count(move_timer)%120 == 118)&&
		mode_pick == 2 && ghosts[3]->status == FREEDOM) {
		stop_bgm(DISAPPEAR_MUSIC);
		DISAPPEAR_MUSIC = play_audio(DISAPPEAR, effect_volume);
	}

	if (mode_pick==2&&ghosts[2]->status==FREEDOM && !(rand() % 20) && al_get_timer_count(trap.time) >= 20) {    

		trap.area = getDrawArea(&ghosts[2]->objData, GAME_TICK_CD);
		stop_bgm(TRAP_MUSIC);
		TRAP_MUSIC = play_audio(TRAP, effect_volume);
		al_stop_timer(trap.time); al_set_timer_count(trap.time, 0); al_start_timer(trap.time);
	}
}

static void draw(void) {

	al_clear_to_color(al_map_rgb(0, 0, 0));

	
	// TODO-GC-scoring: Draw scoreboard, something your may need is sprinf();  完成
	char temp[20] = { 0 };
	sprintf_s(temp, 19,"%d", game_main_Score);
	al_draw_text(menuFont, al_map_rgb(255, 255, 255),400,20,ALLEGRO_ALIGN_CENTRE,temp);
	
	if (al_get_timer_count(trap.time) < 10) {                       // 畫陷阱
		al_draw_scaled_bitmap(trap.picture, 0, 0,
			600, 600,
			trap.area.x -3, trap.area.y -3,
			30, 30, 0
		);
	}

	draw_map(basic_map);
	if (enter_name) {
		al_draw_filled_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 100, SCREEN_W / 2 + 200, SCREEN_H / 2 + 100, al_map_rgb(0, 0, 0));
		al_draw_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 100, SCREEN_W / 2 + 200, SCREEN_H / 2 + 100, al_map_rgb(255, 255, 255), 5);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 400, SCREEN_W / 2 - 50, ALLEGRO_ALIGN_CENTRE, "ENTER YOUR NAME:");
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 400, SCREEN_W / 2 , ALLEGRO_ALIGN_CENTRE, name);
		return;
	}
	pacman_draw(pman);
	
	// no drawing below when game over
	for (int i = 0; i < GHOST_NUM; i++)
		ghost_draw(ghosts[i]);
	if (al_get_timer_count(explosion.timer) < 2) {
		al_draw_scaled_bitmap(explosion_picture, 8 * 16, 11 * 16,
			16, 16,
			explosion.area.x - 3, explosion.area.y - 3,
			30, 30, 0
		);
	}
	else
		al_stop_timer(explosion.timer);
	
	if (game_over)
		return;
	//debugging mode
	if (debug_mode) {
		draw_hitboxes();
	}

}

static void draw_hitboxes(void) {
	RecArea pmanHB = getDrawArea((object *)pman, GAME_TICK_CD);
	al_draw_rectangle(
		pmanHB.x, pmanHB.y,
		pmanHB.x + pmanHB.w, pmanHB.y + pmanHB.h,
		al_map_rgb_f(1.0, 0.0, 0.0), 2
	);

	for (int i = 0; i < GHOST_NUM; i++) {
		RecArea ghostHB = getDrawArea((object *)ghosts[i], GAME_TICK_CD);
		al_draw_rectangle(
			ghostHB.x, ghostHB.y,
			ghostHB.x + ghostHB.w, ghostHB.y + ghostHB.h,
			al_map_rgb_f(1.0, 0.0, 0.0), 2
		);
	}

}

static void printinfo(void) {
	game_log("pacman:\n");
	game_log("coord: %d, %d\n", pman->objData.Coord.x, pman->objData.Coord.y);
	game_log("PreMove: %d\n", pman->objData.preMove);
	game_log("NextTryMove: %d\n", pman->objData.nextTryMove);
	game_log("Speed: %f\n", pman->speed);
}


static void destroy(void) {
	// TODO-GC-memory: free map array, Pacman and ghosts  完成
	for (int i = 0; i < GHOST_NUM; i++)
		ghost_destory(ghosts[i]);
	free(ghosts);
	pacman_destroy(pman);
	delete_map(basic_map);
	
}

static void on_key_up(int key_code) {
	switch (key_code){
	case ALLEGRO_KEY_LCTRL:
		ctrl = false;
		break;
	default:
		break;
	}
}

static void on_key_down(int key_code) {
	if (enter_name) {
		
		if (key_code >= 1 && key_code <= 26&&x<10) {
			name[x++] = 'A' + key_code - 1;
		}
		else if (key_code == 67) {
			enter_name = false; clean_rank();
			game_change_scene(scene_menu_create());
		}
		else if (key_code == 63&&x>0) {
			name[--x] = 0;
		}
		return;
	}
	//printf("%d\n", key_code);
	if(key_code==go_up[0]-64)
		pacman_NextMove(pman, UP);
	else if(key_code==go_down[0]-64)
		pacman_NextMove(pman, DOWN);
	else if (key_code == go_left[0] - 64)
		pacman_NextMove(pman, LEFT);
	else if (key_code == go_right[0] - 64)
		pacman_NextMove(pman, RIGHT);
	switch (key_code)
	{
		// TODO-HACKATHON 1-1: Use allegro pre-defined enum ALLEGRO_KEY_<KEYNAME> to controll pacman movement
		// we provided you a function `pacman_NextMove` to set the pacman's next move direction.
		
		case ALLEGRO_KEY_W:
			
			break;
		case ALLEGRO_KEY_A:
			//pacman_NextMove(pman, LEFT);
			break;
		case ALLEGRO_KEY_S:  //cheat mode ctrl+S 鬼停止
			if (ctrl && cheat_mode) {
				for (int i = 0; i < GHOST_NUM; i++) {
					if (ghosts[i]->status == STOP)
						ghosts[i]->status = FREEDOM;
					else
						ghosts[i]->status = STOP;
				}
				break;
			}
			
			break;
		case ALLEGRO_KEY_D:
			//pacman_NextMove(pman, RIGHT);
			break;
		case ALLEGRO_KEY_C:
			cheat_mode = !cheat_mode;
			if (cheat_mode)
				printf("cheat mode on\n");
			else 
				printf("cheat mode off\n");
			break;
		case ALLEGRO_KEY_K:  //cheat mode K 鬼 GO_IN
			if (cheat_mode)
				for (int i = 0; i < GHOST_NUM; i++) {
					ghosts[i]->status = GO_IN;
				}
			break;
		case ALLEGRO_KEY_LCTRL:
			if (cheat_mode)
				ctrl = true;
			break;
		case ALLEGRO_KEY_L:  //cheat mode ctrl+L 完美達成
			if (ctrl && cheat_mode) {
				break_wall = !break_wall;
				ctrl = false;
			}
			break;
		case ALLEGRO_KEY_G:
			debug_mode = !debug_mode;
			break;
		case ALLEGRO_KEY_V:
			if (cheat_mode)
				cheat_victory = true;
			break;
	default:
		break;
	}

}
static void clean_rank() {
	char rank_name[6][20] = { 0 }; int rank_point[6] = { 0 };
	FILE* open_rank = fopen("Assets/rank.txt", "r");
	for (int i = 0; i < 5; i++)
		fscanf_s(open_rank, "%s %d", rank_name[i],sizeof(rank_name[i]), &rank_point[i]);
	strcpy_s(rank_name[5], sizeof(rank_name[5]), name); rank_point[5] = game_main_Score;
	if (!rank_name[5][0])
		strcpy_s(rank_name[5], sizeof(rank_name[5]), "UNKNOWN");
	for (int i = 5; i > 0; i--) {
		if (rank_point[i] > rank_point[i - 1]) {
			int temp_point = rank_point[i]; char temp_name[20] = {0};
			rank_point[i] = rank_point[i - 1]; rank_point[i - 1] = temp_point;
			strcpy_s(temp_name, sizeof(temp_name), rank_name[i]); strcpy_s(rank_name[i],sizeof(rank_name[i]), rank_name[i - 1]); strcpy_s(rank_name[i - 1], sizeof(rank_name[i-1]), temp_name);
		}
		else
			break;
	}
	FILE* write_rank = fopen("Assets/rank.txt", "w");
	for (int i = 0; i < 5; i++)
		fprintf(write_rank, "%s %d\n", rank_name[i], rank_point[i]);
	fclose(open_rank); fclose(write_rank);
}

static void on_mouse_down(int btn, int x, int y, int dz) {

	// nothing here

}

static void render_init_screen(void) {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	draw_map(basic_map);
	pacman_draw(pman);
	for (int i = 0; i < GHOST_NUM; i++) {
		ghost_draw(ghosts[i]);
	}

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		400, 400,
		ALLEGRO_ALIGN_CENTER,
		"READY!"
	);

	al_flip_display();
	al_rest(2.0);

}
// Functions without 'static', 'extern' prefixes is just a normal
// function, they can be accessed by other files using 'extern'.
// Define your normal function prototypes below.

// The only function that is shared across files.
Scene scene_main_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Start";
	scene.initialize = &init;
	scene.update = &update;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_up = &on_key_up;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_down = &on_mouse_down;
	// TODO-IF: Register more event callback functions such as keyboard, mouse, ...
	game_log("Start scene created");
	return scene;
}
