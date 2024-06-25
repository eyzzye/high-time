#include "ht_scene_game.h"

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_blending_actions.h"
#include "bn_bgs_mosaic_actions.h"
#include "bn_bgs.h"
#include "bn_music_actions.h"
#include "bn_log.h"

#include "ht_score.h"
#include "ht_stage1.h"
#include "ht_stage2.h"
#include "ht_stage3.h"
#include "ht_stage4.h"

extern ht::scene::type next_scene;
extern bn::fixed g_sound_effect_wait;
extern ht::score g_score;
extern int g_hero_item_count[(int)ht::object::item_id::ITEM_MAX];
extern ht::game* g_game_ptr;
extern ht::game_result g_game_result;
extern int g_game_next_floor;
extern bn::fixed_point g_game_next_floor_pos;
extern ht::gate_actions g_game_gate_action;
extern int g_game_gate_list_index;
extern bn::fixed_point* g_game_gate_bg_map_pos;
extern ht::directions g_game_gate_direction;
extern ht::object::item_stat g_game_item_key_stat;
extern int g_game_item_key_list_index;

namespace ht {

game::game():
    scene(scene::type::GAME),
    _mode(mode::INIT),
    _mc_stat(mode_change_stat::NONE),
    _game_stat(game_stat::INIT),
    _retry_stat(true),
    _bg_ptr(nullptr),
    _text_generator(common::variable_8x16_sprite_font,
                    bn::sprite_items::font_palette.palette_item()),
    _current_time(HT_UNINITIALIZED),
    _hud(),
    _camera(bn::camera_ptr::create(0, 0)),
    _hero(),
    _terrain(),
    _goal(),
    _stairs(),
    _teleport(),
    _gate(),
    _stage_ptr(nullptr),
    _current_stage(0),
    _mode_change_start_callback(NULL),
    _mode_change_done_callback(NULL)
{
    g_game_ptr = this;
    g_score.init();
    _reset_start();
}

game::~game()
{
    g_game_ptr = NULL;
}

void game::update() {
    switch (_mode) {
    case mode::GAME:
        _mode_game_update();
        break;
    case mode::INTRO:
        _mode_intro_update();
        break;
    case mode::OUTRO:
        _mode_outro_update();
        break;
    default:
        BN_ERROR("Invalid _mode: ", (int)_mode);
        break;
    }
}

void game::set_mode(ht::game::mode mode_val) {
    switch (mode_val) {
    case mode::INTRO:
        _mode_intro_init();
        break;
    case mode::GAME:
        _mode_game_init();
        break;
    case mode::OUTRO:
        _mode_outro_init();
        break;
    default:
        BN_ERROR("Invalid mode_val: ", (int)mode_val);
        break;
    }
    _mode = mode_val;
}

void game::set_mode_change_stat(ht::game::mode_change_stat mc_stat_val) {
#if 0
    switch (mc_stat_val) {
    case mode_change_stat::NONE:
        break;
    case mode_change_stat::ACTIVE:
       break;
    case mode_change_stat::DONE:
        break;
    default:
        BN_ERROR("Invalid mc_stat_val: ", (int)mc_stat_val);
        break;
    }
#endif

    _mc_stat = mc_stat_val;
}

void game::set_game_stat(ht::game::game_stat game_stat_val) {
#if 0
    switch (game_stat_val) {
    case game_stat::START:
        break;
    case game_stat::ACTIVE:
        break;
    case game_stat::LOSE:
        break;
    case game_stat::WIN:
        break;
    case game_stat::MOVE_FLOOR:
        break;
    case game_stat::SELECT_RETRY:
        break;
    case game_stat::DONE:
        break;
    default:
        BN_ERROR("Invalid game_stat_val: ", (int)game_stat_val);
        break;
    }
#endif

    _game_stat = game_stat_val;
}

bool game::on_closed_gate(bn::fixed_point& pos) {
    for (int i = 0; i < _gate.size(); i++) {
        if(_gate[i].on_gate(pos) && _gate[i].is_closed()) {
           return true; 
        }
    }

    return false;
}

//
// mode: INTRO
//
void game::_mode_intro_init() {
    _bg_ptr.reset(new bn::regular_bg_ptr(_stage_ptr->create_intro_bg()));

    // gen text
    _text_generator.set_center_alignment();
    _text_generator.generate(0, 48, _stage_ptr->get_intro_message(), _text_sprites);

    // set callback
    _mode_change_done_callback = &ht::game::_mode_intro_done_callback;
}

void game::_mode_intro_done_callback() {
    // change mode to "mode::GAME"
    _mode_intro_destroy();
    set_mode_change_stat(mode_change_stat::NONE);

    // init timer
    ht::time_manager::init();

    set_mode(mode::GAME);
}

void game::_mode_intro_update() {
    _mode_change_update();
    bn::core::update();
}

void game::_mode_intro_destroy() {
    _text_sprites.clear();
    _bg_ptr.reset();
}

//
// mode: GAME
//
void game::_mode_game_init() {
    _mode_change_done_callback = NULL;
    g_sound_effect_wait = 0;

    // init collision_manager
    bn::fixed scene_game_timestep = 0.016f;
    ht::collision_manager::init(scene_game_timestep);

    // create terrain
    _terrain.init(_stage_ptr->get_terrain_init_list());
    _bg_ptr.reset(new bn::regular_bg_ptr(_stage_ptr->create_terrain()));
    _bg_ptr->set_camera(_camera);

    // create bg_map
    ht::bg_map_manager::create_bg_map(_stage_ptr->get_bg_map_tiles().tiles_item(),
                                      _stage_ptr->get_bg_map_tiles().palette_item());
    ht::bg_map_manager::set_camera(_camera);
    ht::bg_map_manager::init_bg_map(_stage_ptr->get_bg_map_init_list());

    // init trace manager
    _stage_ptr->init_trace_manager();

    // set goal region
    if (_stage_ptr->get_enable((int)ht::object::type::EVENT,
                               (int)ht::object::event_id::GOAL)) {
        _goal.init(_stage_ptr->get_goal_region());
        _goal.set_camera(_camera);
    } 

    // create stairs
    if (_stage_ptr->get_enable((int)ht::object::type::EVENT,
                               (int)ht::object::event_id::STAIRS)) {
        struct array_t<struct ht::stairs_init_data_t>* stairs_init_list = _stage_ptr->get_stairs_init_list();
        for (int i = 0; i < (int)stairs_init_list->size; ++i) {
            _stairs.emplace_back(&stairs_init_list->data[i]);
        }
    }

    // create teleport
    if (_stage_ptr->get_enable((int)ht::object::type::EVENT,
                               (int)ht::object::event_id::TELEPORT)) {
        struct array_t<struct ht::teleport_init_data_t>* teleport_init_list = _stage_ptr->get_teleport_init_list();
        for (int i = 0; i < (int)teleport_init_list->size; ++i) {
            _teleport.emplace_back(&teleport_init_list->data[i]);
            _teleport[i].set_camera(_camera);
        }
    }

    // create gate
    if (_stage_ptr->get_enable((int)ht::object::type::EVENT,
                               (int)ht::object::event_id::GATE)) {
        struct array_t<struct ht::gate_init_data_t>* gate_init_list = _stage_ptr->get_gate_init_list();
        for (int i = 0; i < (int)gate_init_list->size; ++i) {
            _gate.emplace_back(&gate_init_list->data[i], i);
        }

        // reload open gate
        for (int gate_idx = 0; gate_idx < _gate.size(); gate_idx++) {
            if (_stage_ptr->get_gate_stat(gate_idx) == ht::gate_actions::OPEN) {
                _gate[gate_idx].open();
                bn::fixed_point* gate_bg_map_pos = _gate[gate_idx].get_bg_map_pos();
                for (int i = 0; i < 8; i++) {
                    int tile_index = _stage_ptr->get_gate_tile_index(_gate[gate_idx].get_direction(),
                                                                     ht::gate_actions::OPEN,
                                                                     i);
                    ht::bg_map_manager::set_tile(gate_bg_map_pos[i].x().right_shift_integer(),
                                                 gate_bg_map_pos[i].y().right_shift_integer(),
                                                 tile_index);
                }
            }
        }
    }

    // create item_key
    if (_stage_ptr->get_enable((int)ht::object::type::ITEM,
                               (int)ht::object::item_id::ITEM_KEY)) {
        struct array_t<struct ht::item_key_init_data_t>* item_key_init_list = _stage_ptr->get_item_key_init_list();
        for (int i = 0; i < (int)item_key_init_list->size; ++i) {
            _item_key.emplace_back(&item_key_init_list->data[i], i);
            auto i_key = _item_key.end() - 1;
            i_key->set_camera(_camera);
        }

        // reload disable
        for (int item_key_idx = 0; item_key_idx < _item_key.size(); item_key_idx++) {
            if (_stage_ptr->get_item_key_stat(item_key_idx) ==
                 ht::object::item_stat::DISABLE)
            {
                _item_key[item_key_idx].set_enable(false);
            }
        }
    }

    // create hero
    _hero.init();
    _hero.set_position(g_game_next_floor_pos);
    _hero.set_camera(_camera);

    // create enemy
    if (_stage_ptr->get_enable((int)ht::object::type::ENEMY)) {
        _stage_ptr->create_enemy();
        _stage_ptr->set_camera(_camera);
    }

    // set visible
    _hero.set_visible(true);
    _hud.set_enable(true);

    // play music
    if (!bn::music::playing()) {
        _stage_ptr->play_music();
    }

    set_game_stat(game_stat::ACTIVE);
}

void game::_mode_game_lose_start_callback() {
    bn::music_items::you_lose.play(0.5, false);
}

void game::_mode_game_lose_done_callback() {
    // display "You Lose"
    _mode_game_destroy();

    // disable objects
    _hud.set_enable(false);
    _goal.set_enable(false);
    for (int i = 0; i < _teleport.size(); i++) { _teleport[i].set_enable(false); }

    set_mode_change_stat(mode_change_stat::NONE);
    bn::blending::set_fade_alpha(0.0f);
    _bg_ptr.reset(new bn::regular_bg_ptr(bn::regular_bg_items::you_lose.create_bg(0, 0)));

    // set sprite message
    _retry_stat = true;
    bn::fixed msg_x0 = -16;
    bn::fixed msg_y0 = 49;
    bn::fixed_point msg_pos(msg_x0, msg_y0);

    // set sprite retry
    _text_sprites.push_back(bn::sprite_items::sprite_retry.create_sprite(msg_pos, 0));
    msg_pos.set_x(msg_x0 + 32);
    _text_sprites.push_back(bn::sprite_items::sprite_retry.create_sprite(msg_pos, 1));

    // set sprite yes/no
    msg_pos.set_y(msg_y0 + 16);
    msg_pos.set_x(msg_x0 + 8);
    _text_sprites.push_back(bn::sprite_items::sprite_yes_no.create_sprite(msg_pos, 0));
    msg_pos.set_x(msg_x0 + 8 + 32);
    _text_sprites.push_back(bn::sprite_items::sprite_yes_no.create_sprite(msg_pos, 1));

    // set sprite cursor
    msg_pos.set_x(msg_x0);
    _text_sprites.push_back(bn::sprite_items::sprite_yes_no.create_sprite(msg_pos, 2));

    set_game_stat(game_stat::SELECT_RETRY);
}

void game::_mode_game_win_start_callback() {
    bn::music_items::you_win.play(0.3, false);
}

void game::_mode_game_win_done_callback() {
    // display "Outro"
    _mode_game_destroy();

    _hud.set_enable(false);
    _goal.set_enable(false);
    for (int i = 0; i < _teleport.size(); i++) { _teleport[i].set_enable(false); }

    set_mode_change_stat(mode_change_stat::NONE);
    bn::blending::set_fade_alpha(0.0f);
    set_game_stat(game_stat::DONE);
    set_mode(mode::OUTRO);
}

void game::_mode_game_move_floor_done_callback() {
    // change floor
    _stage_ptr->set_floor_index(g_game_next_floor);
    g_game_next_floor = HT_UNINITIALIZED;

    _mode_game_destroy();
    set_mode_change_stat(mode_change_stat::NONE);
    bn::blending::set_fade_alpha(0.0f);

    _mode_game_init();
    ht::time_manager::start();
    set_game_stat(game_stat::ACTIVE);
}

void game::_mode_game_update() {
    if (_game_stat == game_stat::ACTIVE) {
        bn::core::update();
        _hero.key_event();
        ht::collision_manager::update();

        // current time
        ht::time_manager::update();
        int new_time = ht::time_manager::get_time();
        if (new_time != _current_time) {
            _current_time = new_time;
            _hud.set_time(_current_time);
        }

        // check game_result
        if (g_game_result == game_result::LOSE) {
            ht::time_manager::pause();
            set_game_stat(game_stat::LOSE);
            _mode_change_start_callback = &ht::game::_mode_game_lose_start_callback;
            _mode_change_done_callback = &ht::game::_mode_game_lose_done_callback;
        }
        else if (g_game_result == game_result::WIN) {
            ht::time_manager::pause();
            g_score.time[(_current_stage - 1)] = ht::time_manager::get_time();
            set_game_stat(game_stat::WIN);
            _mode_change_start_callback = &ht::game::_mode_game_win_start_callback;
            _mode_change_done_callback = &ht::game::_mode_game_win_done_callback;
        }

        // check next floor
        if (g_game_next_floor >= 0) {
            ht::time_manager::pause();
            set_game_stat(game_stat::MOVE_FLOOR);
            _mode_change_start_callback = NULL;
            _mode_change_done_callback = &ht::game::_mode_game_move_floor_done_callback;
        }

        // check gate
        if (g_game_gate_action == ht::gate_actions::OPEN) {
            for (int i = 0; i < 8; i++) {
                int tile_index = _stage_ptr->get_gate_tile_index(
                                    g_game_gate_direction,
                                    g_game_gate_action,
                                    i);
                ht::bg_map_manager::set_tile(g_game_gate_bg_map_pos[i].x().right_shift_integer(),
                                             g_game_gate_bg_map_pos[i].y().right_shift_integer(),
                                             tile_index);
            }

            // save gate_stat
            _stage_ptr->set_gate_stat(g_game_gate_list_index,
                                      ht::gate_actions::OPEN);

            // reset global gate stat
            g_game_gate_action = ht::gate_actions::NONE;
            g_game_gate_list_index = HT_UNINITIALIZED;
            g_game_gate_bg_map_pos = NULL;
        }

        // check item_key
        if (g_game_item_key_stat == ht::object::item_stat::DISABLE) {
            // save gate_stat
            _stage_ptr->set_item_key_stat(g_game_item_key_list_index,
                                          ht::object::item_stat::DISABLE);

            // reset global gate stat
            g_game_item_key_stat = ht::object::item_stat::NONE;
            g_game_item_key_list_index = HT_UNINITIALIZED;
        }

        // sound effect wait
        if (g_sound_effect_wait > 0) { g_sound_effect_wait -= 0.016f; } 

        // update objects
        _hero.update();
        _stage_ptr->update();
        ht::bg_map_manager::update();
        _goal.update();
        for (int i = 0; i < _teleport.size(); i++) { _teleport[i].update(); }
        _hud.update();

        // update camera position
        bn::fixed_point camera_pos = _hero.get_position();
        bn::fixed cx_min = -(512/2 - bn::display::width()/2);
        bn::fixed cx_max =  (512/2 - bn::display::width()/2);
        _camera.set_x( bn::min( bn::max(cx_min,camera_pos.x()), cx_max) );
        bn::fixed cy_min = -(512/2 - bn::display::height()/2);
        bn::fixed cy_max =  (512/2 - bn::display::height()/2);
        _camera.set_y( bn::min( bn::max(cy_min,camera_pos.y()), cy_max) );
    }
    else if (_game_stat == game_stat::LOSE) {
        bn::core::update();
        _mode_change_update_for_game();
    }
    else if (_game_stat == game_stat::WIN) {
        bn::core::update();
        _mode_change_update_for_game();
    }
    else if (_game_stat == game_stat::MOVE_FLOOR) {
        bn::core::update();
        _mode_change_update_for_game();
    }
    else if (_game_stat == game_stat::SELECT_RETRY) {
        bn::core::update();

        if (bn::keypad::left_pressed() || bn::keypad::right_pressed()) {
            _retry_stat = !_retry_stat;
            if (_retry_stat == true) { _text_sprites[4].set_x(-16); }
            else { _text_sprites[4].set_x(-16 + 32); }
            bn::sound_items::click1.play();
        }

        if (bn::keypad::a_released()) {
            _text_sprites.clear();
            if (_retry_stat == true) {
                _bg_ptr.reset();
                bn::music::stop();
                bn::sound_items::click1.play();

                g_score.died[(_current_stage - 1)] += 1;
                _current_stage -= 1;
                _reset_start();
            }
            else {
                // change scene to TOPMENU
                bn::music::stop();
                bn::sound_items::click1.play();

                next_scene = ht::scene::type::TOPMENU;
                set_stat(scene::stat::DONE);
            }
        }
    }
    else if (_game_stat == game_stat::DONE) {
        bn::core::update();

        if (bn::keypad::a_pressed()) {
            // change scene to TOPMENU
            bn::music::stop();
            next_scene = ht::scene::type::TOPMENU;
            set_stat(scene::stat::DONE);
        }
    }
}
 
void game::_mode_game_destroy() {
    _hero.set_visible(false);

    // delete goal
    _goal.destroy();

    // delete stairs
    _stairs.clear();

    // delete teleport
    _teleport.clear();

    // delete gate
    _gate.clear();

    // delete item_key
    _item_key.clear();

    // delete enemy
    _stage_ptr->destroy_enemy();

    // delete bg_map_ptr
    ht::bg_map_manager::destroy_bg_map();

    // delete bg_ptr
    _bg_ptr.reset();

    g_game_result = game_result::YET;
}

//
// mode: OUTRO
//
void game::_mode_outro_init() {
    _bg_ptr.reset(new bn::regular_bg_ptr(_stage_ptr->create_outro_bg()));

    // gen text
    _text_generator.generate(0, 48, _stage_ptr->get_outro_message(), _text_sprites);

    // mode change
    _mode_change_done_callback = &ht::game::_mode_outro_done_callback;
}

void game::_mode_outro_done_callback() {
    // load next stage
    _mode_outro_destroy();
    set_mode_change_stat(mode_change_stat::NONE);

    bn::music::stop();
    _set_next_stage();
}

void game::_mode_outro_update() {
    _mode_change_update();
    bn::core::update();
}

void game::_mode_outro_destroy() {
    _text_sprites.clear();
    _bg_ptr.reset();
}

void game::_mode_change_update() {
    if (_mc_stat == mode_change_stat::ACTIVE) {
        // fade and mosaic bgs
        bn::fixed fade_alpha = bn::blending::fade_alpha();

        if (fade_alpha == 1) {
            set_mode_change_stat(mode_change_stat::DONE);
        }
        else {
            bn::blending::set_fade_alpha(bn::min(fade_alpha + 0.01, bn::fixed(1)));

            bn::fixed horizontal_stretch = bn::bgs_mosaic::horizontal_stretch();
            bn::fixed vertical_stretch = bn::bgs_mosaic::vertical_stretch();
            if (horizontal_stretch != 1) {
                bn::bgs_mosaic::set_horizontal_stretch(bn::min(horizontal_stretch + 0.01, bn::fixed(1)));
            }
            if (vertical_stretch != 1) {
                bn::bgs_mosaic::set_vertical_stretch(bn::min(vertical_stretch + 0.01, bn::fixed(1)));
            }
        }
    }
    else if (_mc_stat == mode_change_stat::DONE) {
        if (_mode_change_done_callback) {
            (this->*_mode_change_done_callback)();
        }
    }
    else {
        // wait a key input
        if (bn::keypad::any_pressed()) {
            set_mode_change_stat(mode_change_stat::ACTIVE);
            _bg_ptr->set_mosaic_enabled(true);
            _bg_ptr->set_blending_enabled(true);
            bn::bgs_mosaic::set_stretch(0.0f);
            bn::blending::set_fade_alpha(0.0f);
        }
    }
}

void game::_mode_change_update_for_game() {
    if (_mc_stat == mode_change_stat::ACTIVE) {
        // fade and mosaic bgs
        bn::fixed fade_alpha = bn::blending::fade_alpha();

        if (fade_alpha == 1) {
            set_mode_change_stat(mode_change_stat::DONE);
        }
        else {
            bn::blending::set_fade_alpha(bn::min(fade_alpha + 0.01, bn::fixed(1)));
        }
    }
    else if (_mc_stat == mode_change_stat::DONE) {
        if (_mode_change_done_callback) {
            (this->*_mode_change_done_callback)();
        }
    }
    else {
        // start fade bg
        set_mode_change_stat(mode_change_stat::ACTIVE);
        _bg_ptr->set_blending_enabled(true);
        bn::blending::set_fade_alpha(0.0f);

        if (_mode_change_start_callback) {
            (this->*_mode_change_start_callback)();
        }
    }
}

void game::_set_next_stage()
{
    if (_current_stage <= (HT_STAGE_MAX - 1)) {
        _current_stage += 1;

        switch (_current_stage) {
#if 0
        // debug stage4
        case 1:
            _current_stage += 1;
        case 2:
            _current_stage += 1;
        case 3:
            _current_stage += 1;
        case 4:
            _stage_ptr.reset(new ht::stage4());
            break;
#else
        case 1:
            _stage_ptr.reset(new ht::stage1());
            break;
        case 2:
            _stage_ptr.reset(new ht::stage2());
            break;
        case 3:
            _stage_ptr.reset(new ht::stage3());
            break;
        case 4:
            _stage_ptr.reset(new ht::stage4());
            break;
#endif
         default:
            BN_ERROR("Invalid _current_stage: ", _current_stage);
            break;
        }

        if (_stage_ptr->get_enable((int)ht::object::type::HERO)) {
            g_game_next_floor_pos = _stage_ptr->get_hero_start_pos();
        }

        // set invisibles
        _hero.set_visible(false);

        set_mode(mode::INTRO);
        set_stat(scene::stat::ACTIVE);
    }
    else if (_current_stage == HT_STAGE_MAX) {
        next_scene = ht::scene::type::ENDING;
        set_stat(scene::stat::DONE);
    }
    else {
        next_scene = ht::scene::type::TOPMENU;
        set_stat(scene::stat::DONE);
    }
}

void game::_reset_start() {
    g_game_next_floor = HT_UNINITIALIZED;
    for (int i = 0; i < (int)ht::object::item_id::ITEM_MAX; i++) {
        g_hero_item_count[i] = 0;
    }

    _set_next_stage();
}

}

