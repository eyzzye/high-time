//
// stage3_1
//
struct stage3_1_static_data {
    bn::fixed_point enemy_pos_000 = { 56,0 };		// 0
    bn::fixed_point enemy_pos_001 = { -8,48 };		// 1
    bn::fixed_point enemy_pos_002 = { 184,176 };		// 2
    bn::fixed_point enemy_pos_003 = { 184,96 };		// 3
    bn::fixed_point enemy_pos_004 = { 104,96 };		// 4
    bn::fixed_point enemy_pos_005 = { 104,176 };		// 5
    bn::fixed_point enemy_pos_006 = { 184,-192 };		// 6
    bn::fixed_point enemy_pos_007 = { 184,-96 };		// 7
    bn::fixed_point enemy_pos_008 = { 104,-96 };		// 8
    bn::fixed_point enemy_pos_009 = { 104,-192 };		// 9
    bn::fixed_point enemy_pos_010 = { -184,-192 };		// 10
    bn::fixed_point enemy_pos_011 = { -104,-192 };		// 11
    bn::fixed_point enemy_pos_012 = { -104,-96 };		// 12
    bn::fixed_point enemy_pos_013 = { -184,-96 };		// 13
    bn::fixed_point enemy_pos_014 = { 8,176 };		// 14
    bn::fixed_point enemy_pos_015 = { 8,0 };		// 15
    bn::fixed_point enemy_pos_016 = { 184,0 };		// 16
    bn::fixed_point enemy_pos_017 = { -184,176 };		// 17

    #define ST3_1_TERRAIN_INIT_LIST_SIZE (10)
    struct terrain_init_data_t terrain_init_data[ST3_1_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-232.0,512.0,48.0)},
        {bn::fixed_rect(-232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(-72.0,40.0,16.0,432.0)},
        {bn::fixed_rect(72.0,-96.0,16.0,160.0)},
        {bn::fixed_rect(0.0,-72.0,352.0,16.0)},
        {bn::fixed_rect(72.0,96.0,16.0,160.0)},
        {bn::fixed_rect(-96.0,72.0,160.0,16.0)},
        {bn::fixed_rect(96.0,72.0,160.0,16.0)},
        {bn::fixed_rect(24.0,232.0,464.0,48.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST3_1_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST3_1_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST3_1_BG_MAP_LIST_SIZE] = {
        { 18,44,UP_STAIRS_TILE1 },
        { 19,44,UP_STAIRS_TILE2 },
        { 18,45,UP_STAIRS_TILE3 },
        { 19,45,UP_STAIRS_TILE4 },
        { 36,26,DOWN_STAIRS_TILE1 },
        { 37,26,DOWN_STAIRS_TILE2 },
        { 36,27,DOWN_STAIRS_TILE3 },
        { 37,27,DOWN_STAIRS_TILE4 },
        { 6,40,DOWN_GATE_CLOSE_TILE1 },
        { 7,40,DOWN_GATE_CLOSE_TILE2 },
        { 8,40,DOWN_GATE_CLOSE_TILE3 },
        { 9,40,DOWN_GATE_CLOSE_TILE4 },
        { 6,41,DOWN_GATE_CLOSE_TILE5 },
        { 7,41,DOWN_GATE_CLOSE_TILE6 },
        { 8,41,DOWN_GATE_CLOSE_TILE7 },
        { 9,41,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST3_1_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST3_1_STAIRS_LIST_SIZE (2)
    struct ht::stairs_init_data_t stairs_init_data[ST3_1_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(-104,104),2,bn::fixed_point(-88,104)},
        {bn::fixed_point(40,-40),0,bn::fixed_point(24,-40)},
    }; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST3_1_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST3_1_TELEPORT_LIST_SIZE (0)
    //struct ht::teleport_init_data_t teleport_init_data[ST3_1_TELEPORT_LIST_SIZE] = {
    //};
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST3_1_TELEPORT_LIST_SIZE,
        NULL
    };

    #define ST3_1_GATE_LIST_SIZE (1)
    struct ht::gate_init_data_t gate_init_data[ST3_1_GATE_LIST_SIZE] = {
        {bn::fixed_rect(-192,72,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST3_1_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST3_1_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST3_1_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(168,168,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST3_1_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST3_1_TRACE_AREA_INIT_LIST_SIZE (18)
    struct trace_manager::area_init_data_t area_init_data[ST3_1_TRACE_AREA_INIT_LIST_SIZE] = {
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
        {bn::fixed_rect(0.0,72.0,32.0,16.0)}, 	// 10
        {bn::fixed_rect(192.0,72.0,32.0,16.0)}, 	// 11
        {bn::fixed_rect(-192.0,72.0,32.0,16.0)}, 	// 12
        {bn::fixed_rect(72.0,0.0,16.0,32.0)}, 	// 13
        {bn::fixed_rect(192.0,-72.0,32.0,16.0)}, 	// 14
        {bn::fixed_rect(-192.0,-72.0,32.0,16.0)}, 	// 15
        {bn::fixed_rect(72.0,-192.0,16.0,32.0)}, 	// 16
        {bn::fixed_rect(-72.0,-192.0,16.0,32.0)}, 	// 17
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST3_1_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST3_1_TRACE_CNN_INIT_LIST_SIZE (18)
    struct trace_manager::connection_init_data_t connection_init_data[ST3_1_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,9,bn::fixed_point(56.0,192),bn::fixed_point(72.0,192)}, 	//0
        {3,11,bn::fixed_point(200.0,48),bn::fixed_point(200.0,80)}, 	//8
        {4,10,bn::fixed_point(8.0,48),bn::fixed_point(8.0,80)}, 	//5
        {4,13,bn::fixed_point(56.0,0),bn::fixed_point(72.0,0)}, 	//12
        {5,12,bn::fixed_point(-200.0,48),bn::fixed_point(-200.0,80)}, 	//11
        {6,14,bn::fixed_point(200.0,-96),bn::fixed_point(200.0,-64)}, 	//17
        {7,16,bn::fixed_point(56.0,-192),bn::fixed_point(72.0,-192)}, 	//23
        {8,15,bn::fixed_point(-200.0,-96),bn::fixed_point(-200.0,-64)}, 	//20
        {8,17,bn::fixed_point(-88.0,-192),bn::fixed_point(-72.0,-192)}, 	//26
        {9,1,bn::fixed_point(72.0,192),bn::fixed_point(88.0,192)}, 	//1
        {10,0,bn::fixed_point(8.0,64),bn::fixed_point(8.0,96)}, 	//4
        {11,1,bn::fixed_point(200.0,64),bn::fixed_point(200.0,96)}, 	//7
        {12,2,bn::fixed_point(-200.0,64),bn::fixed_point(-200.0,96)}, 	//10
        {13,3,bn::fixed_point(72.0,0),bn::fixed_point(88.0,0)}, 	//13
        {14,3,bn::fixed_point(200.0,-80),bn::fixed_point(200.0,-48)}, 	//16
        {15,5,bn::fixed_point(-200.0,-80),bn::fixed_point(-200.0,-48)}, 	//19
        {16,6,bn::fixed_point(72.0,-192),bn::fixed_point(88.0,-192)}, 	//22
        {17,7,bn::fixed_point(-72.0,-192),bn::fixed_point(-56.0,-192)}, 	//25
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST3_1_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST3_1_AI_LIST_NUM (6)
    #define ST3_1_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST3_1_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_1_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST3_1_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_1_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST3_1_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_1_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST3_1_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_1_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST3_1_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_016},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_1_AI_006_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_006_list[ST3_1_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_017},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage3_1_static_data stage3_1_data;

static bool get_stage3_1_enable(int type, int id) {
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

void stage3::_stage3_1_create_enemy() {
    for (int list_idx = 0; list_idx < ST3_1_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage3_1_data.enemy_pos_000;
            current_ai = stage3_1_data.ai_001_list;
            current_ai_size = ST3_1_AI_001_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
        }
        if (list_idx == 1) {
            current_pos = stage3_1_data.enemy_pos_002;
            current_ai = stage3_1_data.ai_002_list;
            current_ai_size = ST3_1_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 2) {
            current_pos = stage3_1_data.enemy_pos_006;
            current_ai = stage3_1_data.ai_003_list;
            current_ai_size = ST3_1_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 3) {
            current_pos = stage3_1_data.enemy_pos_010;
            current_ai = stage3_1_data.ai_004_list;
            current_ai_size = ST3_1_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 4) {
            current_pos = stage3_1_data.enemy_pos_014;
            current_ai = stage3_1_data.ai_005_list;
            current_ai_size = ST3_1_AI_005_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 5) {
            current_pos = stage3_1_data.enemy_pos_017;
            current_ai = stage3_1_data.ai_006_list;
            current_ai_size = ST3_1_AI_006_LIST_SIZE;
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

