//
// stage3_2
//
struct stage3_2_static_data {
    bn::fixed_point enemy_pos_000 = { 184,192 };		// 0
    bn::fixed_point enemy_pos_001 = { -8,192 };		// 1
    bn::fixed_point enemy_pos_002 = { -8,0 };		// 2
    bn::fixed_point enemy_pos_003 = { 184,0 };		// 3
    bn::fixed_point enemy_pos_004 = { 184,-192 };		// 4
    bn::fixed_point enemy_pos_005 = { -184,-192 };		// 5
    bn::fixed_point enemy_pos_006 = { -184,192 };		// 6
    bn::fixed_point enemy_pos_007 = { 104,96 };		// 7

    #define ST3_2_TERRAIN_INIT_LIST_SIZE (11)
    struct terrain_init_data_t terrain_init_data[ST3_2_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-232.0,512.0,48.0)},
        {bn::fixed_rect(-232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(-72.0,0.0,16.0,352.0)},
        {bn::fixed_rect(72.0,-96.0,16.0,160.0)},
        {bn::fixed_rect(-96.0,-72.0,160.0,16.0)},
        {bn::fixed_rect(96.0,-72.0,160.0,16.0)},
        {bn::fixed_rect(72.0,96.0,16.0,160.0)},
        {bn::fixed_rect(-96.0,72.0,160.0,16.0)},
        {bn::fixed_rect(96.0,72.0,160.0,16.0)},
        {bn::fixed_rect(24.0,232.0,464.0,48.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST3_2_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST3_2_BG_MAP_LIST_SIZE (24)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST3_2_BG_MAP_LIST_SIZE] = {
        { 32,52,UP_STAIRS_TILE1 },
        { 33,52,UP_STAIRS_TILE2 },
        { 32,53,UP_STAIRS_TILE3 },
        { 33,53,UP_STAIRS_TILE4 },
        { 18,44,DOWN_STAIRS_TILE1 },
        { 19,44,DOWN_STAIRS_TILE2 },
        { 18,45,DOWN_STAIRS_TILE3 },
        { 19,45,DOWN_STAIRS_TILE4 },
        { 22,54,LEFT_GATE_CLOSE_TILE1 },
        { 23,54,LEFT_GATE_CLOSE_TILE2 },
        { 22,55,LEFT_GATE_CLOSE_TILE3 },
        { 23,55,LEFT_GATE_CLOSE_TILE4 },
        { 22,56,LEFT_GATE_CLOSE_TILE5 },
        { 23,56,LEFT_GATE_CLOSE_TILE6 },
        { 22,57,LEFT_GATE_CLOSE_TILE7 },
        { 23,57,LEFT_GATE_CLOSE_TILE8 },
        { 30,22,DOWN_GATE_CLOSE_TILE1 },
        { 31,22,DOWN_GATE_CLOSE_TILE2 },
        { 32,22,DOWN_GATE_CLOSE_TILE3 },
        { 33,22,DOWN_GATE_CLOSE_TILE4 },
        { 30,23,DOWN_GATE_CLOSE_TILE5 },
        { 31,23,DOWN_GATE_CLOSE_TILE6 },
        { 32,23,DOWN_GATE_CLOSE_TILE7 },
        { 33,23,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST3_2_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST3_2_STAIRS_LIST_SIZE (2)
    struct ht::stairs_init_data_t stairs_init_data[ST3_2_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(8,168),3,bn::fixed_point(24,168)},
        {bn::fixed_point(-104,104),1,bn::fixed_point(-120,104)},
    }; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST3_2_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST3_2_TELEPORT_LIST_SIZE (0)
    //struct ht::teleport_init_data_t teleport_init_data[ST3_2_TELEPORT_LIST_SIZE] = {
    //};
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST3_2_TELEPORT_LIST_SIZE,
        NULL
    };

    #define ST3_2_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST3_2_GATE_LIST_SIZE] = {
        {bn::fixed_rect(-72,192,16,32),ht::directions::LEFT},
        {bn::fixed_rect(0,-72,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST3_2_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST3_2_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST3_2_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(88,-88,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST3_2_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST3_2_TRACE_AREA_INIT_LIST_SIZE (20)
    struct trace_manager::area_init_data_t area_init_data[ST3_2_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,144.0,128.0,128.0)}, 	// 0
        {bn::fixed_rect(144.0,144.0,128.0,128.0)}, 	// 1
        {bn::fixed_rect(-144.0,144.0,128.0,128.0)}, 	// 2
        {bn::fixed_rect(144.0,0.0,128.0,128.0)}, 	// 3
        {bn::fixed_rect(0.0,0.0,128.0,128.0)}, 	// 4
        {bn::fixed_rect(-144.0,0.0,128.0,128.0)}, 	// 5
        {bn::fixed_rect(144.0,-144.0,128.0,128.0)}, 	// 6
        {bn::fixed_rect(0.0,-144.0,128.0,128.0)}, 	// 7
        {bn::fixed_rect(-144.0,-144.0,128.0,128.0)}, 	// 8
        {bn::fixed_rect(72.0,192.0,16.0,32.0)}, 	// 9
        {bn::fixed_rect(-72.0,192.0,16.0,32.0)}, 	// 10
        {bn::fixed_rect(0.0,72.0,32.0,16.0)}, 	// 11
        {bn::fixed_rect(192.0,72.0,32.0,16.0)}, 	// 12
        {bn::fixed_rect(-192.0,72.0,32.0,16.0)}, 	// 13
        {bn::fixed_rect(72.0,0.0,16.0,32.0)}, 	// 14
        {bn::fixed_rect(192.0,-72.0,32.0,16.0)}, 	// 15
        {bn::fixed_rect(0.0,-72.0,32.0,16.0)}, 	// 16
        {bn::fixed_rect(-192.0,-72.0,32.0,16.0)}, 	// 17
        {bn::fixed_rect(72.0,-192.0,16.0,32.0)}, 	// 18
        {bn::fixed_rect(-72.0,-192.0,16.0,32.0)}, 	// 19
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST3_2_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST3_2_TRACE_CNN_INIT_LIST_SIZE (22)
    struct trace_manager::connection_init_data_t connection_init_data[ST3_2_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,9,bn::fixed_point(56.0,192),bn::fixed_point(72.0,192)}, 	//0
        {2,10,bn::fixed_point(-88.0,192),bn::fixed_point(-72.0,192)}, 	//5
        {3,12,bn::fixed_point(200.0,48),bn::fixed_point(200.0,80)}, 	//11
        {4,11,bn::fixed_point(8.0,48),bn::fixed_point(8.0,80)}, 	//8
        {4,14,bn::fixed_point(56.0,0),bn::fixed_point(72.0,0)}, 	//20
        {5,13,bn::fixed_point(-200.0,48),bn::fixed_point(-200.0,80)}, 	//14
        {6,15,bn::fixed_point(200.0,-96),bn::fixed_point(200.0,-64)}, 	//17
        {7,16,bn::fixed_point(8.0,-96),bn::fixed_point(8.0,-64)}, 	//23
        {7,18,bn::fixed_point(56.0,-192),bn::fixed_point(72.0,-192)}, 	//29
        {8,17,bn::fixed_point(-200.0,-96),bn::fixed_point(-200.0,-64)}, 	//26
        {8,19,bn::fixed_point(-88.0,-192),bn::fixed_point(-72.0,-192)}, 	//32
        {9,1,bn::fixed_point(72.0,192),bn::fixed_point(88.0,192)}, 	//1
        {10,0,bn::fixed_point(-72.0,192),bn::fixed_point(-56.0,192)}, 	//4
        {11,0,bn::fixed_point(8.0,64),bn::fixed_point(8.0,96)}, 	//7
        {12,1,bn::fixed_point(200.0,64),bn::fixed_point(200.0,96)}, 	//10
        {13,2,bn::fixed_point(-200.0,64),bn::fixed_point(-200.0,96)}, 	//13
        {14,3,bn::fixed_point(72.0,0),bn::fixed_point(88.0,0)}, 	//19
        {15,3,bn::fixed_point(200.0,-80),bn::fixed_point(200.0,-48)}, 	//16
        {16,4,bn::fixed_point(8.0,-80),bn::fixed_point(8.0,-48)}, 	//22
        {17,5,bn::fixed_point(-200.0,-80),bn::fixed_point(-200.0,-48)}, 	//25
        {18,6,bn::fixed_point(72.0,-192),bn::fixed_point(88.0,-192)}, 	//28
        {19,7,bn::fixed_point(-72.0,-192),bn::fixed_point(-56.0,-192)}, 	//31
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST3_2_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST3_2_AI_LIST_NUM (8)
    #define ST3_2_AI_001_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_001_list[ST3_2_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST3_2_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST3_2_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST3_2_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST3_2_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_006_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_006_list[ST3_2_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_007_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_007_list[ST3_2_AI_007_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_2_AI_008_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_008_list[ST3_2_AI_008_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage3_2_static_data stage3_2_data;

static bool get_stage3_2_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::GOAL) return false;
        if (id == (int)ht::object::event_id::STAIRS) return true;
        if (id == (int)ht::object::event_id::TELEPORT) return false;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage3::_stage3_2_create_enemy() {
    for (int list_idx = 0; list_idx < ST3_2_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage3_2_data.enemy_pos_000;
            current_ai = stage3_2_data.ai_001_list;
            current_ai_size = ST3_2_AI_001_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage3_2_data.enemy_pos_001;
            current_ai = stage3_2_data.ai_002_list;
            current_ai_size = ST3_2_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage3_2_data.enemy_pos_002;
            current_ai = stage3_2_data.ai_003_list;
            current_ai_size = ST3_2_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 3) {
            current_pos = stage3_2_data.enemy_pos_003;
            current_ai = stage3_2_data.ai_004_list;
            current_ai_size = ST3_2_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 4) {
            current_pos = stage3_2_data.enemy_pos_004;
            current_ai = stage3_2_data.ai_005_list;
            current_ai_size = ST3_2_AI_005_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 5) {
            current_pos = stage3_2_data.enemy_pos_005;
            current_ai = stage3_2_data.ai_006_list;
            current_ai_size = ST3_2_AI_006_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 6) {
            current_pos = stage3_2_data.enemy_pos_006;
            current_ai = stage3_2_data.ai_007_list;
            current_ai_size = ST3_2_AI_007_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 7) {
            current_pos = stage3_2_data.enemy_pos_007;
            current_ai = stage3_2_data.ai_008_list;
            current_ai_size = ST3_2_AI_008_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
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
    }
}

