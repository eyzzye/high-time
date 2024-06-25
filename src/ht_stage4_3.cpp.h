//
// stage4_3
//
struct stage4_3_static_data {
    bn::fixed_point enemy_pos_000 = { -24,224 };		// 0
    bn::fixed_point enemy_pos_001 = { 24,224 };		// 1
    bn::fixed_point enemy_pos_002 = { 24,-64 };		// 2
    bn::fixed_point enemy_pos_003 = { -24,-64 };		// 3
    bn::fixed_point enemy_pos_004 = { -24,-112 };		// 4
    bn::fixed_point enemy_pos_005 = { 24,-112 };		// 5
    bn::fixed_point enemy_pos_006 = { 88,-224 };		// 6
    bn::fixed_point enemy_pos_007 = { -88,-224 };		// 7
    bn::fixed_point enemy_pos_008 = { -88,-112 };		// 8
    bn::fixed_point enemy_pos_009 = { 88,-112 };		// 9
    bn::fixed_point enemy_pos_010 = { 8,176 };		// 10
    bn::fixed_point enemy_pos_011 = { 24,80 };		// 11
    bn::fixed_point enemy_pos_012 = { -40,144 };		// 12
    bn::fixed_point enemy_pos_013 = { 56,128 };		// 13
    bn::fixed_point enemy_pos_014 = { -72,64 };		// 14
    bn::fixed_point enemy_pos_015 = { 8,96 };		// 15
    bn::fixed_point enemy_pos_016 = { -8,16 };		// 16
    bn::fixed_point enemy_pos_017 = { -40,112 };		// 17
    bn::fixed_point enemy_pos_018 = { 24,-32 };		// 18
    bn::fixed_point enemy_pos_019 = { 8,64 };		// 19
    bn::fixed_point enemy_pos_020 = { -40,0 };		// 20
    bn::fixed_point enemy_pos_021 = { 72,32 };		// 21
    bn::fixed_point enemy_pos_022 = { 232,-208 };		// 22
    bn::fixed_point enemy_pos_023 = { 232,-128 };		// 23
    bn::fixed_point enemy_pos_024 = { -24,-224 };		// 24
    bn::fixed_point enemy_pos_025 = { 24,-224 };		// 25

    #define ST4_3_TERRAIN_INIT_LIST_SIZE (9)
    struct terrain_init_data_t terrain_init_data[ST4_3_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-248.0,512.0,16.0)},
        {bn::fixed_rect(-248.0,8.0,16.0,496.0)},
        {bn::fixed_rect(248.0,8.0,16.0,496.0)},
        {bn::fixed_rect(-128.0,-88.0,224.0,16.0)},
        {bn::fixed_rect(136.0,-88.0,240.0,16.0)},
        {bn::fixed_rect(-88.0,88.0,16.0,336.0)},
        {bn::fixed_rect(88.0,88.0,16.0,336.0)},
        {bn::fixed_rect(-128.0,248.0,224.0,16.0)},
        {bn::fixed_rect(136.0,248.0,240.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST4_3_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST4_3_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST4_3_BG_MAP_LIST_SIZE] = {
        { 54,12,UP_STAIRS_TILE1 },
        { 55,12,UP_STAIRS_TILE2 },
        { 54,13,UP_STAIRS_TILE3 },
        { 55,13,UP_STAIRS_TILE4 },
        { 54,8,DOWN_STAIRS_TILE1 },
        { 55,8,DOWN_STAIRS_TILE2 },
        { 54,9,DOWN_STAIRS_TILE3 },
        { 55,9,DOWN_STAIRS_TILE4 },
        { 30,20,DOWN_GATE_CLOSE_TILE1 },
        { 31,20,DOWN_GATE_CLOSE_TILE2 },
        { 32,20,DOWN_GATE_CLOSE_TILE3 },
        { 33,20,DOWN_GATE_CLOSE_TILE4 },
        { 30,21,DOWN_GATE_CLOSE_TILE5 },
        { 31,21,DOWN_GATE_CLOSE_TILE6 },
        { 32,21,DOWN_GATE_CLOSE_TILE7 },
        { 33,21,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST4_3_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST4_3_STAIRS_LIST_SIZE (2)
    struct ht::stairs_init_data_t stairs_init_data[ST4_3_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(184,-152),3,bn::fixed_point(168,-184)},
        {bn::fixed_point(184,-184),3,bn::fixed_point(200,-152)},
    }; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST4_3_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST4_3_TELEPORT_LIST_SIZE (1)
    struct ht::teleport_init_data_t teleport_init_data[ST4_3_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,248.0,32.0,16.0),2,bn::fixed_point(0,-224)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST4_3_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST4_3_GATE_LIST_SIZE (1)
    struct ht::gate_init_data_t gate_init_data[ST4_3_GATE_LIST_SIZE] = {
        {bn::fixed_rect(0,-88,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST4_3_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST4_3_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST4_3_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(232,-168,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST4_3_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST4_3_TRACE_AREA_INIT_LIST_SIZE (4)
    struct trace_manager::area_init_data_t area_init_data[ST4_3_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,80.0,160.0,320.0)}, 	// 0
        {bn::fixed_rect(0.0,-168.0,480.0,144.0)}, 	// 1
        {bn::fixed_rect(0.0,248.0,32.0,16.0)}, 	// 2
        {bn::fixed_rect(0.0,-88.0,32.0,16.0)}, 	// 3
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST4_3_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST4_3_TRACE_CNN_INIT_LIST_SIZE (3)
    struct trace_manager::connection_init_data_t connection_init_data[ST4_3_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,2,bn::fixed_point(8.0,224),bn::fixed_point(8.0,256)}, 	//1
        {1,3,bn::fixed_point(8.0,-112),bn::fixed_point(8.0,-80)}, 	//4
        {3,0,bn::fixed_point(8.0,-96),bn::fixed_point(8.0,-64)}, 	//3
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST4_3_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST4_3_AI_LIST_NUM (14)
    #define ST4_3_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST4_3_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_002_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_002_list[ST4_3_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_003_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_003_list[ST4_3_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST4_3_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST4_3_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_006_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_006_list[ST4_3_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_007_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_007_list[ST4_3_AI_007_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_008_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_008_list[ST4_3_AI_008_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_009_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_009_list[ST4_3_AI_009_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_016},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_017},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_010_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_010_list[ST4_3_AI_010_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_018},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_019},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_020},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_021},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_011_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_011_list[ST4_3_AI_011_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_022},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_012_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_012_list[ST4_3_AI_012_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_023},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_013_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_013_list[ST4_3_AI_013_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_024},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_3_AI_014_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_014_list[ST4_3_AI_014_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_025},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage4_3_static_data stage4_3_data;

static bool get_stage4_3_enable(int type, int id) {
    switch (type) {
    case ((int)ht::object::type::HERO):
        return false;
        break;
    case ((int)ht::object::type::ENEMY):
        return true;
        break;
    case ((int)ht::object::type::ITEM):
        if (id == (int)ht::object::item_id::ITEM_KEY) return true;
        break;
    case ((int)ht::object::type::EVENT):
        if (id == (int)ht::object::event_id::GOAL) return true;
        if (id == (int)ht::object::event_id::STAIRS) return true;
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage4::_stage4_3_create_enemy() {
    for (int list_idx = 0; list_idx < ST4_3_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::HARD;

        if (list_idx == 0) {
            current_pos = stage4_3_data.enemy_pos_000;
            current_ai = stage4_3_data.ai_001_list;
            current_ai_size = ST4_3_AI_001_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage4_3_data.enemy_pos_002;
            current_ai = stage4_3_data.ai_002_list;
            current_ai_size = ST4_3_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage4_3_data.enemy_pos_004;
            current_ai = stage4_3_data.ai_003_list;
            current_ai_size = ST4_3_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 3) {
            current_pos = stage4_3_data.enemy_pos_006;
            current_ai = stage4_3_data.ai_004_list;
            current_ai_size = ST4_3_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 4) {
            current_pos = stage4_3_data.enemy_pos_007;
            current_ai = stage4_3_data.ai_005_list;
            current_ai_size = ST4_3_AI_005_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 5) {
            current_pos = stage4_3_data.enemy_pos_008;
            current_ai = stage4_3_data.ai_006_list;
            current_ai_size = ST4_3_AI_006_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 6) {
            current_pos = stage4_3_data.enemy_pos_009;
            current_ai = stage4_3_data.ai_007_list;
            current_ai_size = ST4_3_AI_007_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 7) {
            current_pos = stage4_3_data.enemy_pos_010;
            current_ai = stage4_3_data.ai_008_list;
            current_ai_size = ST4_3_AI_008_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 8) {
            current_pos = stage4_3_data.enemy_pos_014;
            current_ai = stage4_3_data.ai_009_list;
            current_ai_size = ST4_3_AI_009_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 9) {
            current_pos = stage4_3_data.enemy_pos_018;
            current_ai = stage4_3_data.ai_010_list;
            current_ai_size = ST4_3_AI_010_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 10) {
            current_pos = stage4_3_data.enemy_pos_022;
            current_ai = stage4_3_data.ai_011_list;
            current_ai_size = ST4_3_AI_011_LIST_SIZE;
            e_id = ht::enemy::enemy_id::ASSASSIN;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 11) {
            current_pos = stage4_3_data.enemy_pos_023;
            current_ai = stage4_3_data.ai_012_list;
            current_ai_size = ST4_3_AI_012_LIST_SIZE;
            e_id = ht::enemy::enemy_id::ASSASSIN;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 12) {
            current_pos = stage4_3_data.enemy_pos_024;
            current_ai = stage4_3_data.ai_013_list;
            current_ai_size = ST4_3_AI_013_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 13) {
            current_pos = stage4_3_data.enemy_pos_025;
            current_ai = stage4_3_data.ai_014_list;
            current_ai_size = ST4_3_AI_014_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }

        if(e_id == ht::enemy::enemy_id::SECURITY_GUARD) {
            _e_security_guard.emplace_back(grade, current_pos, current_ai, current_ai_size);
            auto sg = _e_security_guard.end() - 1;
            _enemy_list.push_back(sg);
        }
        else if(e_id == ht::enemy::enemy_id::DOG) {
            _e_dog.emplace_back(grade, current_pos, current_ai, current_ai_size);
            auto dog = _e_dog.end() - 1;
            _enemy_list.push_back(dog);
        }
        else if(e_id == ht::enemy::enemy_id::CHASER) {
            _e_chaser.emplace_back(grade, current_pos, current_ai, current_ai_size);
            auto chaser = _e_chaser.end() - 1;
            _enemy_list.push_back(chaser);
        }
        else if(e_id == ht::enemy::enemy_id::ASSASSIN) {
            _e_assassin.emplace_back(grade, current_pos, current_ai, current_ai_size);
            auto assassin = _e_assassin.end() - 1;
            _enemy_list.push_back(assassin);
        }
    }
}

