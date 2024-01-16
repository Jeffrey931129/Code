#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>
#include "scene_menu_object.h"
#include "scene_settings.h"
#include "scene_game.h"
#include "scene_menu.h"
#include "utility.h"
#include "shared.h"

/* Internal Variables*/
static ALLEGRO_BITMAP* gameTitle = NULL;
ALLEGRO_SAMPLE_ID menuBGM;
static int gameTitleW ;
static int gameTitleH ;
bool show_rank = false,edit_keyboard=false;
// [HACKATHON 3]
// TARGET : use a clickable button to enter setting scene.
// For `Button` struct(object) is defined in `scene_menu_object.h` and `scene_menu_object.c`
// STRONGLY recommend you trace both of them first. 

// TODO-HACKATHON 3-1: Declare variable for button
// Uncomment and fill the code below
static Button btnSettings,rank,end,keyboard_setting;
static Button up, down, left, right;
char go_up[2] = {'W'}, go_down[2] = { 'S' }, go_left[2] = { 'A' }, go_right[2] = { 'D' };
bool edit_up, edit_down, edit_left, edit_right;

static void init() {
	show_rank = false;
	edit_keyboard = false;
	edit_up = edit_down = edit_left = edit_right = false;
	// TODO-HACKATHON 3-2: Create button to settings
	// Uncomment and fill the code below
	btnSettings = button_create(730, 20, 50, 50, "Assets/settings.png", "Assets/settings2.png");
	rank = button_create(20, 20, 100, 50, "Assets/rank.png", "Assets/rank2.png");
	end = button_create(730, 730, 50, 50, "Assets/end.png", "Assets/end2.png");
	keyboard_setting = button_create(20, 730, 50, 50, "Assets/keyboard_setting.png", "Assets/keyboard_setting2.png");
	up = button_create(250, 250, 50, 50, "Assets/checkbox3.png", NULL);
	down = button_create(250, 350, 50, 50, "Assets/checkbox3.png", NULL);
	left = button_create(250, 450, 50, 50, "Assets/checkbox3.png", NULL);
	right = button_create(250, 550, 50, 50, "Assets/checkbox3.png", NULL);
	gameTitle = load_bitmap("Assets/title.png");
	gameTitleW = al_get_bitmap_width(gameTitle);
	gameTitleH = al_get_bitmap_height(gameTitle);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);

}


static void draw() {

	al_clear_to_color(al_map_rgb(0, 0, 0));

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameTitleH;

	//draw title image
	al_draw_scaled_bitmap(
		gameTitle,
		0, 0,
		gameTitleW, gameTitleH,
		offset_w, offset_h,
		gameTitleW * scale, gameTitleH * scale,
		0
	);
	
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS <ENTER>"
	);

		// TODO-HACKATHON 3-3: Draw button
		// Uncomment and fill the code below
	drawButton(btnSettings); drawButton(rank); drawButton(end); drawButton(keyboard_setting);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		30,
		30,
		ALLEGRO_ALIGN_LEFT,
		"Rank"
	);

	if (show_rank) {
		al_draw_filled_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 250, SCREEN_W / 2 + 200, SCREEN_H / 2 + 250, al_map_rgb(0, 0, 0));
		al_draw_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 250, SCREEN_W / 2 + 200, SCREEN_H / 2 + 250, al_map_rgb(255, 255, 255), 5);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 400, 200 , ALLEGRO_ALIGN_CENTER, "Rank");
		char whole_rank[20] = {0};
		FILE* open_rank = fopen("Assets/rank.txt", "r");
		for (int i = 0; i < 5; i++) {
			fscanf_s(open_rank, " %s", whole_rank, sizeof(whole_rank));
			al_draw_text(menuFont, al_map_rgb(255, 255, 255), 250, 300+i*50, ALLEGRO_ALIGN_LEFT, whole_rank);
			fscanf_s(open_rank, " %s", whole_rank, sizeof(whole_rank));
			al_draw_text(menuFont, al_map_rgb(255, 255, 255), 500, 300 + i * 50, ALLEGRO_ALIGN_LEFT, whole_rank);
		}
		fclose(open_rank);
	}
	if (edit_keyboard) {
		al_draw_filled_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 250, SCREEN_W / 2 + 200, SCREEN_H / 2 + 250, al_map_rgb(0, 0, 0));
		al_draw_rectangle(SCREEN_W / 2 - 200, SCREEN_H / 2 - 250, SCREEN_W / 2 + 200, SCREEN_H / 2 + 250, al_map_rgb(255, 255, 255), 5);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 400, 200, ALLEGRO_ALIGN_CENTER, "Keyboard");
		drawButton(up); drawButton(down); drawButton(left); drawButton(right);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 275, 265, ALLEGRO_ALIGN_CENTER, go_up);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 275, 365, ALLEGRO_ALIGN_CENTER, go_down);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 275, 465, ALLEGRO_ALIGN_CENTER, go_left);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 275, 565, ALLEGRO_ALIGN_CENTER, go_right);
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 375, 265, ALLEGRO_ALIGN_CENTER, "UP");
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 375, 365, ALLEGRO_ALIGN_CENTER, "DOWN");
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 375, 465, ALLEGRO_ALIGN_CENTER, "LEFT");
		al_draw_text(menuFont, al_map_rgb(255, 255, 255), 375, 565, ALLEGRO_ALIGN_CENTER, "RIGHT");
	}
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	TODO-HACKATHON 3-7: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	btnSettings.hovered = buttonHover(btnSettings, mouse_x, mouse_y);
	rank.hovered = buttonHover(rank, mouse_x, mouse_y);
	end.hovered = buttonHover(end, mouse_x, mouse_y);
	keyboard_setting.hovered = buttonHover(keyboard_setting, mouse_x, mouse_y);
	up.hovered = buttonHover(up, mouse_x, mouse_y);
	down.hovered = buttonHover(down, mouse_x, mouse_y);
	left.hovered = buttonHover(left, mouse_x, mouse_y);
	right.hovered = buttonHover(right, mouse_x, mouse_y);
}


//	TODO-HACKATHON 3-8: When btnSettings clicked, switch to settings scene
//  `game_change_scene` is defined in `game.h`.
//  You can check line 121 `scene_menu.c` to see how to use this function.
//  And find the corresponding function for `scene_setting`
// 	Utilize the member defined in struct `Button`.
//  The logic here is 
//  `if clicked the mouse` && `mouse position is in the area of button`
// 	      `Enter the setting scene`
//	Uncomment and fill the code below

static void on_mouse_down() {
	if (btnSettings.hovered)
		game_change_scene(scene_settings_create());
	if (rank.hovered) {
		show_rank = !show_rank;
		edit_keyboard = false;
	}
	if (end.hovered)
		gameDone=true;
	if (keyboard_setting.hovered) {
		edit_keyboard = !edit_keyboard;
		show_rank = false;
	}
	if (up.hovered&& edit_keyboard)
		edit_up = true,edit_down=edit_left=edit_right=false;
	if (down.hovered && edit_keyboard)
		edit_down = true, edit_up = edit_left = edit_right = false;
	if (left.hovered && edit_keyboard)
		edit_left = true, edit_down = edit_up = edit_right = false;
	if (right.hovered && edit_keyboard)
		edit_right = true, edit_down = edit_left = edit_up = false;
	if (!edit_keyboard)
		edit_up = edit_down = edit_left = edit_right = false;
}


static void destroy() {
	stop_bgm(menuBGM);
	al_destroy_bitmap(gameTitle);
	//	TODO-HACKATHON 3-10: Destroy button images
	//	Uncomment and fill the code below
	
	al_destroy_bitmap(btnSettings.default_img);
	al_destroy_bitmap(btnSettings.hovered_img);
	al_destroy_bitmap(rank.default_img);
	al_destroy_bitmap(rank.hovered_img);
	al_destroy_bitmap(end.default_img);
	al_destroy_bitmap(end.hovered_img);
	al_destroy_bitmap(keyboard_setting.default_img);
	al_destroy_bitmap(keyboard_setting.hovered_img);
}

static void on_key_down(int keycode) {
	if (edit_up&&keycode<=26) {
		go_up[0] = 'A' - 1 + keycode;
		edit_up = false;
	}
	if (edit_down && keycode <= 26) {
		go_down[0] = 'A' - 1 + keycode;
		edit_down = false;
	}
	if (edit_left && keycode <= 26) {
		go_left[0] = 'A' - 1 + keycode;
		edit_left = false;
	}
	if (edit_right && keycode <= 26) {
		go_right[0] = 'A' - 1 + keycode;
		edit_right = false;
	}
	switch (keycode) {
		case ALLEGRO_KEY_ENTER:
			game_change_scene(scene_main_create());
			break;
		default:
			break;
	}
}

// TODO-IF: Add more event callback functions such as update, ...

// Functions without 'static', 'extern' prefixes is just a normal
// function, they can be accessed by other files using 'extern'.
// Define your normal function prototypes below.

// The only function that is shared across files.
Scene scene_menu_create(void) {

	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Menu";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_move = &on_mouse_move;
	// TODO-HACKATHON 3-9: Register on_mouse_down.
	// Uncomment the code below.
	
	scene.on_mouse_down = &on_mouse_down;
	
	// -------------------------------------



	// TODO-IF: Register more event callback functions such as keyboard, mouse, ...
	game_log("Menu scene created");
	return scene;
}