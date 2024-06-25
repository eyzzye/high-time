//
// stage4_0
//
struct stage4_0_static_data {
    bn::fixed_point enemy_pos_000 = { 136,-32 };		// 0
    bn::fixed_point enemy_pos_001 = { 168,-32 };		// 1
    bn::fixed_point enemy_pos_002 = { -232,-224 };		// 2
    bn::fixed_point enemy_pos_003 = { -232,-128 };		// 3
    bn::fixed_point enemy_pos_004 = { 232,-224 };		// 4
    bn::fixed_point enemy_pos_005 = { 232,-128 };		// 5
    bn::fixed_point enemy_pos_006 = { -232,-32 };		// 6
    bn::fixed_point enemy_pos_007 = { -216,-32 };		// 7
    bn::fixed_point enemy_pos_008 = { 232,-32 };		// 8
    bn::fixed_point enemy_pos_009 = { 216,-32 };		// 9
    bn::fixed_point enemy_pos_010 = { -216,-64 };		// 10
    bn::fixed_point enemy_pos_011 = { 216,-64 };		// 11
    bn::fixed_point enemy_pos_012 = { -216,-128 };		// 12
    bn::fixed_point enemy_pos_013 = { 216,-128 };		// 13

    #define ST4_0_TERRAIN_INIT_LIST_SIZE (14)
    struct terrain_init_data_t terrain_init_data[ST4_0_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-248.0,512.0,16.0)},
        {bn::fixed_rect(-248.0,-224.0,16.0,32.0)},
        {bn::fixed_rect(248.0,-224.0,16.0,32.0)},
        {bn::fixed_rect(-248.0,56.0,16.0,400.0)},
        {bn::fixed_rect(248.0,56.0,16.0,400.0)},
        {bn::fixed_rect(0.0,0.0,448.0,32.0)},
        {bn::fixed_rect(-96.0,72.0,256.0,16.0)},
        {bn::fixed_rect(144.0,72.0,160.0,16.0)},
        {bn::fixed_rect(-216.0,144.0,16.0,128.0)},
        {bn::fixed_rect(-72.0,120.0,16.0,80.0)},
        {bn::fixed_rect(216.0,144.0,16.0,128.0)},
        {bn::fixed_rect(72.0,160.0,16.0,96.0)},
        {bn::fixed_rect(24.0,200.0,400.0,16.0)},
        {bn::fixed_rect(8.0,248.0,496.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST4_0_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST4_0_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST4_0_BG_MAP_LIST_SIZE] = {
        { 36,40,UP_GATE_CLOSE_TILE1 },
        { 37,40,UP_GATE_CLOSE_TILE2 },
        { 38,40,UP_GATE_CLOSE_TILE3 },
        { 39,40,UP_GATE_CLOSE_TILE4 },
        { 36,41,UP_GATE_CLOSE_TILE5 },
        { 37,41,UP_GATE_CLOSE_TILE6 },
        { 38,41,UP_GATE_CLOSE_TILE7 },
        { 39,41,UP_GATE_CLOSE_TILE8 },
        { 6,56,DOWN_GATE_CLOSE_TILE1 },
        { 7,56,DOWN_GATE_CLOSE_TILE2 },
        { 8,56,DOWN_GATE_CLOSE_TILE3 },
        { 9,56,DOWN_GATE_CLOSE_TILE4 },
        { 6,57,DOWN_GATE_CLOSE_TILE5 },
        { 7,57,DOWN_GATE_CLOSE_TILE6 },
        { 8,57,DOWN_GATE_CLOSE_TILE7 },
        { 9,57,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST4_0_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST4_0_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST4_0_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST4_0_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST4_0_TELEPORT_LIST_SIZE (2)
    struct ht::teleport_init_data_t teleport_init_data[ST4_0_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(-248.0,-176.0,16.0,64.0),1,bn::fixed_point(232,0)},
        {bn::fixed_rect(248.0,-176.0,16.0,64.0),2,bn::fixed_point(-232,0)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST4_0_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST4_0_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST4_0_GATE_LIST_SIZE] = {
        {bn::fixed_rect(48,72,32,16),ht::directions::UP},
        {bn::fixed_rect(-192,200,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST4_0_GATE_LIST_SIZE,
        gate_init_data
    };

#if 0
    #define ST4_0_ITEM_KEY_LIST_SIZE (3)
    struct ht::item_key_init_data_t item_key_init_data[ST4_0_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(184,184,16,16)},
        {bn::fixed_rect(184,168,16,16)},
        {bn::fixed_rect(184,152,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST4_0_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };
#else
    #define ST4_0_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST4_0_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(184,184,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST4_0_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };
#endif

    #define ST4_0_TRACE_AREA_INIT_LIST_SIZE (16)
    struct trace_manager::area_init_data_t area_init_data[ST4_0_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(144.0,136.0,128.0,112.0)}, 	// 0
        {bn::fixed_rect(0.0,136.0,128.0,112.0)}, 	// 1
        {bn::fixed_rect(-144.0,136.0,128.0,112.0)}, 	// 2
        {bn::fixed_rect(72.0,96.0,16.0,32.0)}, 	// 3
        {bn::fixed_rect(-72.0,176.0,16.0,32.0)}, 	// 4
        {bn::fixed_rect(48.0,72.0,32.0,16.0)}, 	// 5
        {bn::fixed_rect(-192.0,200.0,32.0,16.0)}, 	// 6
        {bn::fixed_rect(0.0,224.0,480.0,32.0)}, 	// 7
        {bn::fixed_rect(232.0,136.0,16.0,144.0)}, 	// 8
        {bn::fixed_rect(-232.0,136.0,16.0,144.0)}, 	// 9
        {bn::fixed_rect(0.0,32.0,480.0,64.0)}, 	// 10
        {bn::fixed_rect(232.0,-8.0,16.0,16.0)}, 	// 11
        {bn::fixed_rect(-232.0,-8.0,16.0,16.0)}, 	// 12
        {bn::fixed_rect(0.0,-128.0,480.0,224.0)}, 	// 13
        {bn::fixed_rect(248.0,-176.0,16.0,64.0)}, 	// 14
        {bn::fixed_rect(-248.0,-176.0,16.0,64.0)}, 	// 15
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST4_0_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST4_0_TRACE_CNN_INIT_LIST_SIZE (18)
    struct trace_manager::connection_init_data_t connection_init_data[ST4_0_TRACE_CNN_INIT_LIST_SIZE] = {
        {1,3,bn::fixed_point(56.0,96),bn::fixed_point(72.0,96)}, 	//2
        {2,4,bn::fixed_point(-88.0,176),bn::fixed_point(-72.0,176)}, 	//7
        {2,6,bn::fixed_point(-184.0,176),bn::fixed_point(-184.0,208)}, 	//8
        {3,0,bn::fixed_point(72.0,96),bn::fixed_point(88.0,96)}, 	//1
        {4,1,bn::fixed_point(-72.0,176),bn::fixed_point(-56.0,176)}, 	//6
        {5,1,bn::fixed_point(56.0,64),bn::fixed_point(56.0,96)}, 	//3
        {6,7,bn::fixed_point(-184.0,192),bn::fixed_point(-184.0,224)}, 	//9
        {8,7,bn::fixed_point(232.0,192),bn::fixed_point(232.0,224)}, 	//12
        {9,7,bn::fixed_point(-232.0,192),bn::fixed_point(-232.0,224)}, 	//14
        {10,5,bn::fixed_point(56.0,48),bn::fixed_point(56.0,80)}, 	//4
        {10,8,bn::fixed_point(232.0,48),bn::fixed_point(232.0,80)}, 	//16
        {10,9,bn::fixed_point(-232.0,48),bn::fixed_point(-232.0,80)}, 	//18
        {11,10,bn::fixed_point(232.0,-16),bn::fixed_point(232.0,16)}, 	//20
        {12,10,bn::fixed_point(-232.0,-16),bn::fixed_point(-232.0,16)}, 	//23
        {13,11,bn::fixed_point(232.0,-32),bn::fixed_point(232.0,0)}, 	//21
        {13,12,bn::fixed_point(-232.0,-32),bn::fixed_point(-232.0,0)}, 	//24
        {13,14,bn::fixed_point(232.0,-192),bn::fixed_point(248.0,-192)}, 	//25
        {15,13,bn::fixed_point(-248.0,-192),bn::fixed_point(-232.0,-192)}, 	//28
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST4_0_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST4_0_AI_LIST_NUM (8)
    #define ST4_0_AI_001_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_001_list[ST4_0_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_002_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_002_list[ST4_0_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_003_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_003_list[ST4_0_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_004_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_004_list[ST4_0_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_005_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_005_list[ST4_0_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_006_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_006_list[ST4_0_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_007_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_007_list[ST4_0_AI_007_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_0_AI_008_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_008_list[ST4_0_AI_008_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage4_0_static_data stage4_0_data;

static bool get_stage4_0_enable(int type, int id) {
    switch (type) {
    case ((int)ht::object::type::HERO):
        return true;
        break;
    case ((int)ht::object::type::ENEMY):
        return true;
        break;
    case ((int)ht::object::type::ITEM):
        if (id == (int)ht::object::item_id::ITEM_KEY) return true;
        break;
    case ((int)ht::object::type::EVENT):
        if (id == (int)ht::object::event_id::GOAL) return false;
        if (id == (int)ht::object::event_id::STAIRS) return false;
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage4::_stage4_0_create_enemy() {
    for (int list_idx = 0; list_idx < ST4_0_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::HARD;

        if (list_idx == 0) {
            current_pos = stage4_0_data.enemy_pos_000;
            current_ai = stage4_0_data.ai_001_list;
            current_ai_size = ST4_0_AI_001_LIST_SIZE;
            e_id = ht::enemy::enemy_id::ASSASSIN;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage4_0_data.enemy_pos_001;
            current_ai = stage4_0_data.ai_002_list;
            current_ai_size = ST4_0_AI_002_LIST_SIZE;
            e_id = ht::enemy::enemy_id::ASSASSIN;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage4_0_data.enemy_pos_002;
            current_ai = stage4_0_data.ai_003_list;
            current_ai_size = ST4_0_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 3) {
            current_pos = stage4_0_data.enemy_pos_004;
            current_ai = stage4_0_data.ai_004_list;
            current_ai_size = ST4_0_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 4) {
            current_pos = stage4_0_data.enemy_pos_006;
            current_ai = stage4_0_data.ai_005_list;
            current_ai_size = ST4_0_AI_005_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 5) {
            current_pos = stage4_0_data.enemy_pos_008;
            current_ai = stage4_0_data.ai_006_list;
            current_ai_size = ST4_0_AI_006_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 6) {
            current_pos = stage4_0_data.enemy_pos_010;
            current_ai = stage4_0_data.ai_007_list;
            current_ai_size = ST4_0_AI_007_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 7) {
            current_pos = stage4_0_data.enemy_pos_013;
            current_ai = stage4_0_data.ai_008_list;
            current_ai_size = ST4_0_AI_008_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::HARD;
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

