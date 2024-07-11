// TODO-HACKATHON 3-9: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu_object.h"
// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.
ALLEGRO_BITMAP* slider;
bool mouse_downing = false;
int music_pick = 1,mode_pick=1;
Button volume,effect;
int music_position=400,effect_position=400;
/* Define your static vars / function prototypes below. */
Button music1, music2,mode1,mode2;
//Button volume0, volume1, volume2, volume3, volume4;
//Button effect0, effect1, effect2, effect3, effect4;
extern ALLEGRO_SAMPLE_ID menuBGM;
// TODO-IF: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.
static void init(void) {
	if (music_pick==1) {
		music1 = button_create(50, 100, 50, 50, "Assets/checkbox2.png", NULL);
		music2 = button_create(50, 200, 50, 50, "Assets/checkbox.png", NULL);
	}
	else {
		music1 = button_create(50, 100, 50, 50, "Assets/checkbox.png", NULL);
		music2 = button_create(50, 200, 50, 50, "Assets/checkbox2.png", NULL);
	}

	if (mode_pick == 1) {
		mode1 = button_create(450, 100, 50, 50, "Assets/checkbox2.png", NULL);
		mode2 = button_create(450, 200, 50, 50, "Assets/checkbox.png", NULL);
	}
	else {
		mode1 = button_create(450, 100, 50, 50, "Assets/checkbox.png", NULL);
		mode2 = button_create(450, 200, 50, 50, "Assets/checkbox2.png", NULL);
	}
	slider = load_bitmap("Assets/slider.png");
	/*
	volume0 = button_create(SCREEN_W / 2 - 250, 365, 10, 30, "Assets/volume.png", NULL);
	volume1 = button_create(SCREEN_W / 2 - 125, 365, 10, 30, "Assets/volume.png", NULL);
	volume2 = button_create(music_position , 365, 10, 30, "Assets/volume.png", NULL);
	volume3 = button_create(SCREEN_W / 2 + 125, 365, 10, 30, "Assets/volume.png", NULL);
	volume4 = button_create(SCREEN_W / 2 + 250, 365, 10, 30, "Assets/volume.png", NULL);
	effect0 = button_create(SCREEN_W / 2 - 250, 500, 10, 30, "Assets/volume.png", NULL);
	effect1 = button_create(SCREEN_W / 2 - 125, 500, 10, 30, "Assets/volume.png", NULL);
	effect2 = button_create(SCREEN_W / 2, 500, 10, 30, "Assets/volume.png", NULL);
	effect3 = button_create(SCREEN_W / 2 + 125, 500, 10, 30, "Assets/volume.png", NULL);
	effect4 = button_create(SCREEN_W / 2 + 250, 500, 10, 30, "Assets/volume.png", NULL);
	*/
	volume = button_create(music_position, 365, 10, 30, "Assets/volume.png", NULL);
	effect = button_create(effect_position, 500, 10, 30, "Assets/volume.png", NULL);

}

static void draw(void ){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"<ENTER> Back to menu"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 4,
		50,
		ALLEGRO_ALIGN_CENTER,
		"BGM Select"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 4*3,
		50,
		ALLEGRO_ALIGN_CENTER,
		"Mode Select"
	);
	
	
	drawButton(music1); drawButton(music2); drawButton(mode1); drawButton(mode2);
	
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		125,
		115,
		ALLEGRO_ALIGN_LEFT,
		"Default Music"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		125,
		215,
		ALLEGRO_ALIGN_LEFT,
		"Anime Music"
	);

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		525,
		115,
		ALLEGRO_ALIGN_LEFT,
		"Default Mode"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		525,
		215,
		ALLEGRO_ALIGN_LEFT,
		"Advance Mode"
	);

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		290,
		ALLEGRO_ALIGN_CENTER,
		"BGM Volume"
	);
	al_draw_scaled_bitmap(slider, 0, 0,
		500, 5,
		SCREEN_W / 2-250, 375,
		500, 5, 0
	);
	drawButton(volume);
	/*switch (volume) {
	case 0:
		drawButton(volume0); break;
	case 1:
		drawButton(volume1); break;
	case 2:
		drawButton(volume2); break;
	case 3:
		drawButton(volume3); break;
	case 4:
		drawButton(volume4); break;
	}*/
	
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		425,
		ALLEGRO_ALIGN_CENTER,
		"Effect Volume"
	);
	al_draw_scaled_bitmap(slider, 0, 0,
		500, 5,
		SCREEN_W / 2 - 250, 510,
		500, 5, 0
	);
	drawButton(effect);
	/*switch (effect) {
	case 0:
		drawButton(effect0); break;
	case 1:
		drawButton(effect1); break;
	case 2:
		drawButton(effect2); break;
	case 3:
		drawButton(effect3); break;
	case 4:
		drawButton(effect4); break;
	}*/
}

static void on_key_down(int keycode) {
	switch (keycode) {
		case ALLEGRO_KEY_ENTER:
			game_change_scene(scene_menu_create());
			break;
		default:
			break;
	}
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	music1.hovered = buttonHover(music1, mouse_x, mouse_y);
	music2.hovered = buttonHover(music2, mouse_x, mouse_y);
	mode1.hovered = buttonHover(mode1, mouse_x, mouse_y);
	mode2.hovered = buttonHover(mode2, mouse_x, mouse_y);
	/*
	volume0.hovered = buttonHover(volume0, mouse_x, mouse_y);
	volume1.hovered = buttonHover(volume1, mouse_x, mouse_y);
	volume2.hovered = buttonHover(volume2, mouse_x, mouse_y);
	volume3.hovered = buttonHover(volume3, mouse_x, mouse_y);
	volume4.hovered = buttonHover(volume4, mouse_x, mouse_y);
	if (volume0.hovered)
		volume = 0, music_volume= 0;
	if (volume1.hovered)
		volume = 1, music_volume = 0.25;
	if (volume2.hovered)
		volume = 2, music_volume = 0.5;
	if (volume3.hovered)
		volume = 3, music_volume = 0.75;
	if (volume4.hovered)
		volume = 4, music_volume = 1;
	*/
	/*
	effect0.hovered = buttonHover(effect0, mouse_x, mouse_y);
	effect1.hovered = buttonHover(effect1, mouse_x, mouse_y);
	effect2.hovered = buttonHover(effect2, mouse_x, mouse_y);
	effect3.hovered = buttonHover(effect3, mouse_x, mouse_y);
	effect4.hovered = buttonHover(effect4, mouse_x, mouse_y);
	if (effect0.hovered)
		effect = 0, effect_volume = 0;
	if (effect1.hovered)
		effect = 1, effect_volume = 0.25;
	if (effect2.hovered)
		effect = 2, effect_volume = 0.5;
	if (effect3.hovered)
		effect = 3, effect_volume = 0.75;
	if (effect4.hovered)
		effect = 4, effect_volume = 1;
	*/
	if (mouse_downing && mouse_x >= 50 && mouse_x <= 750 && mouse_y>=365 && mouse_y <= 395) {
		mouse_x=mouse_x < SCREEN_W / 2 - 250 ? SCREEN_W / 2 - 250 : mouse_x;
		mouse_x=mouse_x > SCREEN_W / 2 + 250 ? SCREEN_W / 2 + 250 : mouse_x;
		volume = button_create(mouse_x, 365, 10, 30, "Assets/volume.png", NULL); 
		music_volume = (mouse_x - SCREEN_W / 2 + 250) / 500.0; music_position = mouse_x;
	}
	if (mouse_downing && mouse_x >= 50 && mouse_x <= 750 && mouse_y >= 500 && mouse_y <= 530) {
		mouse_x = mouse_x < SCREEN_W / 2 - 250 ? SCREEN_W / 2 - 250 : mouse_x;
		mouse_x = mouse_x > SCREEN_W / 2 + 250 ? SCREEN_W / 2 + 250 : mouse_x;
		effect = button_create(mouse_x, 500, 10, 30, "Assets/volume.png", NULL);
		effect_volume = (mouse_x - SCREEN_W / 2 + 250) / 500.0; effect_position = mouse_x;
	}
}

static void on_mouse_up() {
	mouse_downing = false;
}

static void on_mouse_down() {
	if (music1.hovered) {
		music1 = button_create(50, 100, 50, 50, "Assets/checkbox2.png", NULL);
		music2 = button_create(50, 200, 50, 50, "Assets/checkbox.png", NULL);
		themeMusic = load_audio("Assets/Music/original_theme.ogg"); music_pick = 1;
	}
	if (music2.hovered) {
		music1 = button_create(50, 100, 50, 50, "Assets/checkbox.png", NULL);
		music2 = button_create(50, 200, 50, 50, "Assets/checkbox2.png", NULL);
		themeMusic = load_audio("Assets/Music/anime.ogg"); music_pick = 2;
	}

	if (mode1.hovered) {
		mode1 = button_create(450, 100, 50, 50, "Assets/checkbox2.png", NULL);
		mode2 = button_create(450, 200, 50, 50, "Assets/checkbox.png", NULL);
		mode_pick = 1;
	}
	if (mode2.hovered) {
		mode1 = button_create(450, 100, 50, 50, "Assets/checkbox.png", NULL);
		mode2 = button_create(450, 200, 50, 50, "Assets/checkbox2.png", NULL);
		mode_pick = 2;
	}
	mouse_downing = true;
}

static void destroy() {
	al_destroy_bitmap(music1.default_img);
	al_destroy_bitmap(music2.default_img);
	al_destroy_bitmap(mode1.default_img);
	al_destroy_bitmap(mode2.default_img);
	al_destroy_bitmap(slider);
	al_destroy_bitmap(volume.default_img);
	al_destroy_bitmap(effect.default_img);
}

// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_up = &on_mouse_up;
	scene.on_mouse_down = &on_mouse_down;
	// TODO-IF: Register more event callback functions such as keyboard, mouse, ...
	game_log("Settings scene created");
	return scene;
}

// TODO-Graphical_Widget:  完成slider
// Just suggestions, you can create your own usage.
	// Selecting BGM:
	// 1. Declare global variables for storing the BGM. (see `shared.h`, `shared.c`)
	// 2. Load the BGM in `shared.c`.
	// 3. Create dropdown menu for selecting BGM in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and play the BGM if the corresponding option is selected.

	// Adjusting Volume:
	// 1. Declare global variables for storing the volume. (see `shared.h`, `shared.c`)
	// 2. Create a slider for adjusting volume in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. You may use checkbox to switch between mute and unmute.
	// 3. Adjust the volume and play when the button is pressed.

	// Selecting Map:
	// 1. Preload the map to `shared.c`.
	// 2. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. For player experience, you may also create another scene between menu scene and game scene for selecting map.
	// 3. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and draw the map if the corresponding option is selected.
		// 4.1. Suggestions: You may use `al_draw_bitmap` to draw the map for previewing. 
							// But the map is too large to be drawn in original size. 
							// You might want to modify the function to allow scaling.