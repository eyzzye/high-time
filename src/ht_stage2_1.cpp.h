//
// stage2_1
//
struct stage2_1_static_data {
    bn::fixed_point enemy_pos_000 = { -120,-208 };		// 0
    bn::fixed_point enemy_pos_001 = { -216,-208 };		// 1
    bn::fixed_point enemy_pos_002 = { -216,112 };		// 2
    bn::fixed_point enemy_pos_003 = { -120,112 };		// 3
    bn::fixed_point enemy_pos_004 = { -168,128 };		// 4
    bn::fixed_point enemy_pos_005 = { -168,208 };		// 5
    bn::fixed_point enemy_pos_006 = { 168,208 };		// 6
    bn::fixed_point enemy_pos_007 = { 168,128 };		// 7
    bn::fixed_point enemy_pos_008 = { 216,112 };		// 8
    bn::fixed_point enemy_pos_009 = { 216,-208 };		// 9
    bn::fixed_point enemy_pos_010 = { 120,-208 };		// 10
    bn::fixed_point enemy_pos_011 = { 120,112 };		// 11
    bn::fixed_point enemy_pos_012 = { -40,-208 };		// 12
    bn::fixed_point enemy_pos_013 = { 40,-160 };		// 13
    bn::fixed_point enemy_pos_014 = { -40,-112 };		// 14
    bn::fixed_point enemy_pos_015 = { 40,-64 };		// 15
    bn::fixed_point enemy_pos_016 = { -40,-16 };		// 16
    bn::fixed_point enemy_pos_017 = { 40,32 };		// 17

    #define ST2_1_TERRAIN_INIT_LIST_SIZE (16)
    struct terrain_init_data_t terrain_init_data[ST2_1_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(-136.0,-248.0,240.0,16.0)},
        {bn::fixed_rect(136.0,-248.0,240.0,16.0)},
        {bn::fixed_rect(-248.0,-232.0,16.0,16.0)},
        {bn::fixed_rect(-80.0,-72.0,32.0,336.0)},
        {bn::fixed_rect(80.0,-72.0,32.0,336.0)},
        {bn::fixed_rect(248.0,8.0,16.0,496.0)},
        {bn::fixed_rect(-248.0,32.0,16.0,448.0)},
        {bn::fixed_rect(-168.0,-168.0,48.0,16.0)},
        {bn::fixed_rect(168.0,-168.0,48.0,16.0)},
        {bn::fixed_rect(-40.0,80.0,48.0,32.0)},
        {bn::fixed_rect(56.0,80.0,80.0,32.0)},
        {bn::fixed_rect(-168.0,88.0,48.0,16.0)},
        {bn::fixed_rect(168.0,88.0,48.0,16.0)},
        {bn::fixed_rect(-88.0,168.0,16.0,48.0)},
        {bn::fixed_rect(88.0,168.0,16.0,48.0)},
        {bn::fixed_rect(8.0,248.0,496.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST2_1_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST2_1_BG_MAP_LIST_SIZE (8)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST2_1_BG_MAP_LIST_SIZE] = {
        { 30,42,UP_GATE_CLOSE_TILE1 },
        { 31,42,UP_GATE_CLOSE_TILE2 },
        { 32,42,UP_GATE_CLOSE_TILE3 },
        { 33,42,UP_GATE_CLOSE_TILE4 },
        { 30,43,UP_GATE_CLOSE_TILE5 },
        { 31,43,UP_GATE_CLOSE_TILE6 },
        { 32,43,UP_GATE_CLOSE_TILE7 },
        { 33,43,UP_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST2_1_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST2_1_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST2_1_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST2_1_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST2_1_TELEPORT_LIST_SIZE (2)
    struct ht::teleport_init_data_t teleport_init_data[ST2_1_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-248.0,32.0,16.0),2,bn::fixed_point(0,224)},
        {bn::fixed_rect(-248.0,-208.0,16.0,32.0),0,bn::fixed_point(232,-208)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST2_1_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST2_1_GATE_LIST_SIZE (1)
    struct ht::gate_init_data_t gate_init_data[ST2_1_GATE_LIST_SIZE] = {
        {bn::fixed_rect(0,88,32,16),ht::directions::UP},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST2_1_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST2_1_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST2_1_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(168,-200,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST2_1_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST2_1_TRACE_AREA_INIT_LIST_SIZE (23)
    struct trace_manager::area_init_data_t area_init_data[ST2_1_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(-248.0,-208.0,16.0,32.0)}, 	// 0
        {bn::fixed_rect(-168.0,-208.0,144.0,64.0)}, 	// 1
        {bn::fixed_rect(-216.0,-168.0,48.0,16.0)}, 	// 2
        {bn::fixed_rect(-120.0,-168.0,48.0,16.0)}, 	// 3
        {bn::fixed_rect(-168.0,-40.0,144.0,240.0)}, 	// 4
        {bn::fixed_rect(-216.0,88.0,48.0,16.0)}, 	// 5
        {bn::fixed_rect(-120.0,88.0,48.0,16.0)}, 	// 6
        {bn::fixed_rect(-168.0,168.0,144.0,144.0)}, 	// 7
        {bn::fixed_rect(-88.0,120.0,16.0,48.0)}, 	// 8
        {bn::fixed_rect(-88.0,216.0,16.0,48.0)}, 	// 9
        {bn::fixed_rect(0.0,168.0,160.0,144.0)}, 	// 10
        {bn::fixed_rect(88.0,120.0,16.0,48.0)}, 	// 11
        {bn::fixed_rect(88.0,216.0,16.0,48.0)}, 	// 12
        {bn::fixed_rect(168.0,168.0,144.0,144.0)}, 	// 13
        {bn::fixed_rect(120.0,88.0,48.0,16.0)}, 	// 14
        {bn::fixed_rect(216.0,88.0,48.0,16.0)}, 	// 15
        {bn::fixed_rect(168.0,-40.0,144.0,240.0)}, 	// 16
        {bn::fixed_rect(120.0,-168.0,48.0,16.0)}, 	// 17
        {bn::fixed_rect(216.0,-168.0,48.0,16.0)}, 	// 18
        {bn::fixed_rect(168.0,-208.0,144.0,64.0)}, 	// 19
        {bn::fixed_rect(0.0,80.0,32.0,32.0)}, 	// 20
        {bn::fixed_rect(0.0,-88.0,128.0,304.0)}, 	// 21
        {bn::fixed_rect(0.0,-248.0,32.0,16.0)}, 	// 22
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST2_1_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST2_1_TRACE_CNN_INIT_LIST_SIZE (28)
    struct trace_manager::connection_init_data_t connection_init_data[ST2_1_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,1,bn::fixed_point(-248.0,-208),bn::fixed_point(-232.0,-208)}, 	//0
        {1,2,bn::fixed_point(-200.0,-192),bn::fixed_point(-200.0,-160)}, 	//2
        {1,3,bn::fixed_point(-104.0,-192),bn::fixed_point(-104.0,-160)}, 	//5
        {2,4,bn::fixed_point(-200.0,-176),bn::fixed_point(-200.0,-144)}, 	//3
        {3,4,bn::fixed_point(-104.0,-176),bn::fixed_point(-104.0,-144)}, 	//6
        {4,5,bn::fixed_point(-200.0,64),bn::fixed_point(-200.0,96)}, 	//8
        {4,6,bn::fixed_point(-104.0,64),bn::fixed_point(-104.0,96)}, 	//11
        {5,7,bn::fixed_point(-200.0,80),bn::fixed_point(-200.0,112)}, 	//9
        {6,7,bn::fixed_point(-104.0,80),bn::fixed_point(-104.0,112)}, 	//12
        {7,8,bn::fixed_point(-104.0,112),bn::fixed_point(-88.0,112)}, 	//13
        {7,9,bn::fixed_point(-104.0,208),bn::fixed_point(-88.0,208)}, 	//16
        {8,10,bn::fixed_point(-88.0,112),bn::fixed_point(-72.0,112)}, 	//14
        {9,10,bn::fixed_point(-88.0,208),bn::fixed_point(-72.0,208)}, 	//17
        {10,11,bn::fixed_point(72.0,112),bn::fixed_point(88.0,112)}, 	//22
        {10,12,bn::fixed_point(72.0,208),bn::fixed_point(88.0,208)}, 	//19
        {11,13,bn::fixed_point(88.0,112),bn::fixed_point(104.0,112)}, 	//23
        {12,13,bn::fixed_point(88.0,208),bn::fixed_point(104.0,208)}, 	//20
        {14,13,bn::fixed_point(136.0,80),bn::fixed_point(136.0,112)}, 	//26
        {15,13,bn::fixed_point(232.0,80),bn::fixed_point(232.0,112)}, 	//29
        {16,14,bn::fixed_point(136.0,64),bn::fixed_point(136.0,96)}, 	//27
        {16,15,bn::fixed_point(232.0,64),bn::fixed_point(232.0,96)}, 	//30
        {17,16,bn::fixed_point(136.0,-176),bn::fixed_point(136.0,-144)}, 	//32
        {18,16,bn::fixed_point(232.0,-176),bn::fixed_point(232.0,-144)}, 	//35
        {19,17,bn::fixed_point(136.0,-192),bn::fixed_point(136.0,-160)}, 	//33
        {19,18,bn::fixed_point(232.0,-192),bn::fixed_point(232.0,-160)}, 	//36
        {20,10,bn::fixed_point(8.0,80),bn::fixed_point(8.0,112)}, 	//38
        {21,20,bn::fixed_point(8.0,48),bn::fixed_point(8.0,80)}, 	//40
        {22,21,bn::fixed_point(8.0,-256),bn::fixed_point(8.0,-224)}, 	//42
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST2_1_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST2_1_AI_LIST_NUM (6)
    #define ST2_1_AI_001_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_001_list[ST2_1_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_1_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST2_1_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_1_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST2_1_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_1_AI_004_LIST_SIZE (6)
    struct ht::ai_scenario_t ai_004_list[ST2_1_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_1_AI_005_LIST_SIZE (6)
    struct ht::ai_scenario_t ai_005_list[ST2_1_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_017},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_016},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_1_AI_006_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_006_list[ST2_1_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage2_1_static_data stage2_1_data;

static bool get_stage2_1_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::STAIRS) return false;
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage2::_stage2_1_create_enemy() {
    for (int list_idx = 0; list_idx < ST2_1_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage2_1_data.enemy_pos_000;
            current_ai = stage2_1_data.ai_001_list;
            current_ai_size = ST2_1_AI_001_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
        }
        if (list_idx == 1) {
            current_pos = stage2_1_data.enemy_pos_004;
            current_ai = stage2_1_data.ai_002_list;
            current_ai_size = ST2_1_AI_002_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 2) {
            current_pos = stage2_1_data.enemy_pos_011;
            current_ai = stage2_1_data.ai_003_list;
            current_ai_size = ST2_1_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 3) {
            current_pos = stage2_1_data.enemy_pos_012;
            current_ai = stage2_1_data.ai_004_list;
            current_ai_size = ST2_1_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 4) {
            current_pos = stage2_1_data.enemy_pos_017;
            current_ai = stage2_1_data.ai_005_list;
            current_ai_size = ST2_1_AI_005_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 5) {
            current_pos = stage2_1_data.enemy_pos_010;
            current_ai = stage2_1_data.ai_006_list;
            current_ai_size = ST2_1_AI_006_LIST_SIZE;
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
    }
}

