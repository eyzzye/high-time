#ifndef HT_SCENE_GAME_H
#define HT_SCENE_GAME_H

#include "bn_fixed.h"
#include "bn_memory.h"
#include "bn_display.h"
#include "bn_sprite_text_generator.h"
#include "bn_camera_actions.h"
#include "bn_music_actions.h"
#include "bn_log.h"

#include "bn_regular_bg_items_you_lose.h"
#include "bn_sprite_items_sprite_retry.h"
#include "bn_sprite_items_sprite_yes_no.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_font_palette.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"

#include "ht_common.h"
#include "ht_scene.h"
#include "ht_time_manager.h"
#include "ht_heads_up_disp.h"
#include "ht_collision_manager.h"
#include "ht_hero.h"
#include "ht_terrain.h"
#include "ht_goal.h"
#include "ht_stage.h"

namespace ht {

class game : public scene {
public:
    enum class mode {
        INIT,
        INTRO,
        GAME,
        OUTRO
    };

    enum class mode_change_stat {
        NONE,
        ACTIVE,
        DONE
    };

    enum class game_stat {
        INIT,
        START,
        ACTIVE,
        LOSE,
        WIN,
        MOVE_FLOOR,
        SELECT_RETRY,
        DONE
    };

    game();
    ~game();
    void update();

    void set_mode(ht::game::mode mode_val);
    void set_mode_change_stat(ht::game::mode_change_stat mc_stat_val);
    void set_game_stat(ht::game::game_stat game_stat_val);

    bool on_closed_gate(bn::fixed_point& pos);

private:
    ht::game::mode _mode;
    ht::game::mode_change_stat _mc_stat;
    ht::game::game_stat _game_stat;
    bool _retry_stat;

    // mode::INTRO/OUTRO
    bn::unique_ptr<bn::regular_bg_ptr> _bg_ptr;
    bn::sprite_text_generator _text_generator;
    bn::vector<bn::sprite_ptr, 32> _text_sprites;

    // mode::GAME
    int _current_time;
    ht::hud _hud;
    bn::camera_ptr _camera;
    ht::hero _hero;
    ht::terrain _terrain;
    ht::goal _goal;
    bn::vector<ht::stairs, HT_STAIRS_MAX> _stairs;
    bn::vector<ht::teleport, HT_TELEPORT_MAX> _teleport;
    bn::vector<ht::gate, HT_GATE_MAX> _gate;
    bn::vector<ht::item_key, HT_ITEM_KEY_MAX> _item_key;
    bn::unique_ptr<ht::stage> _stage_ptr;
    int _current_stage;

    // mode_change
    void (ht::game::*_mode_change_start_callback)(void);
    void (ht::game::*_mode_change_done_callback)(void);

    // mode::INTRO method
    void _mode_intro_init();
    void _mode_intro_done_callback();
    void _mode_intro_update();
    void _mode_intro_destroy();

    // mode::GAME method
    void _mode_game_init();
    void _mode_game_lose_start_callback();
    void _mode_game_lose_done_callback();
    void _mode_game_win_start_callback();
    void _mode_game_win_done_callback();
    void _mode_game_move_floor_done_callback();
    void _mode_game_update();
    void _mode_game_destroy();

    // mode::OUTRO method
    void _mode_outro_init();
    void _mode_outro_done_callback();
    void _mode_outro_update();
    void _mode_outro_destroy();

    // common method
    void _mode_change_update();
    void _mode_change_update_for_game();
    void _set_next_stage();
    void _reset_start();
};

}

#endif
