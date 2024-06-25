//
// stage2_0
//
struct stage2_0_static_data {
    bn::fixed_point enemy_pos_000 = { -120,-224 };		// 0
    bn::fixed_point enemy_pos_001 = { -120,80 };		// 1
    bn::fixed_point enemy_pos_002 = { 216,128 };		// 2
    bn::fixed_point enemy_pos_003 = { -88,128 };		// 3
    bn::fixed_point enemy_pos_004 = { 216,0 };		// 4
    bn::fixed_point enemy_pos_005 = { 8,0 };		// 5
    bn::fixed_point enemy_pos_006 = { 8,-208 };		// 6
    bn::fixed_point enemy_pos_007 = { 216,-208 };		// 7
    bn::fixed_point enemy_pos_008 = { 120,-48 };		// 8
    bn::fixed_point enemy_pos_009 = { 120,-160 };		// 9

    #define ST2_0_TERRAIN_INIT_LIST_SIZE (15)
    struct terrain_init_data_t terrain_init_data[ST2_0_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-248.0,512.0,16.0)},
        {bn::fixed_rect(-248.0,8.0,16.0,496.0)},
        {bn::fixed_rect(248.0,-232.0,16.0,16.0)},
        {bn::fixed_rect(-80.0,-56.0,32.0,304.0)},
        {bn::fixed_rect(248.0,32.0,16.0,448.0)},
        {bn::fixed_rect(-48.0,-168.0,32.0,16.0)},
        {bn::fixed_rect(88.0,-152.0,16.0,48.0)},
        {bn::fixed_rect(168.0,-152.0,16.0,48.0)},
        {bn::fixed_rect(88.0,-56.0,16.0,48.0)},
        {bn::fixed_rect(168.0,-56.0,16.0,48.0)},
        {bn::fixed_rect(-48.0,-40.0,32.0,16.0)},
        {bn::fixed_rect(88.0,64.0,16.0,64.0)},
        {bn::fixed_rect(168.0,64.0,16.0,64.0)},
        {bn::fixed_rect(72.0,80.0,272.0,32.0)},
        {bn::fixed_rect(8.0,248.0,496.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST2_0_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST2_0_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST2_0_BG_MAP_LIST_SIZE] = {
        { 20,2,LEFT_GATE_CLOSE_TILE1 },
        { 21,2,LEFT_GATE_CLOSE_TILE2 },
        { 20,3,LEFT_GATE_CLOSE_TILE3 },
        { 21,3,LEFT_GATE_CLOSE_TILE4 },
        { 20,4,LEFT_GATE_CLOSE_TILE5 },
        { 21,4,LEFT_GATE_CLOSE_TILE6 },
        { 20,5,LEFT_GATE_CLOSE_TILE7 },
        { 21,5,LEFT_GATE_CLOSE_TILE8 },
        { 58,42,DOWN_GATE_CLOSE_TILE1 },
        { 59,42,DOWN_GATE_CLOSE_TILE2 },
        { 60,42,DOWN_GATE_CLOSE_TILE3 },
        { 61,42,DOWN_GATE_CLOSE_TILE4 },
        { 58,43,DOWN_GATE_CLOSE_TILE5 },
        { 59,43,DOWN_GATE_CLOSE_TILE6 },
        { 60,43,DOWN_GATE_CLOSE_TILE7 },
        { 61,43,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST2_0_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST2_0_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST2_0_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST2_0_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST2_0_TELEPORT_LIST_SIZE (1)
    struct ht::teleport_init_data_t teleport_init_data[ST2_0_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(248.0,-208.0,16.0,32.0),1,bn::fixed_point(-232,-208)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST2_0_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST2_0_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST2_0_GATE_LIST_SIZE] = {
        {bn::fixed_rect(-88,-224,16,32),ht::directions::LEFT},
        {bn::fixed_rect(224,88,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST2_0_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST2_0_ITEM_KEY_LIST_SIZE (2)
    struct ht::item_key_init_data_t item_key_init_data[ST2_0_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(-200,-216,16,16)},
        {bn::fixed_rect(200,-152,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST2_0_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST2_0_TRACE_AREA_INIT_LIST_SIZE (15)
    struct trace_manager::area_init_data_t area_init_data[ST2_0_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,168.0,480.0,144.0)}, 	// 0
        {bn::fixed_rect(-168.0,-72.0,144.0,336.0)}, 	// 1
        {bn::fixed_rect(224.0,80.0,32.0,32.0)}, 	// 2
        {bn::fixed_rect(-80.0,-224.0,32.0,32.0)}, 	// 3
        {bn::fixed_rect(88.0,-208.0,304.0,64.0)}, 	// 4
        {bn::fixed_rect(24.0,-56.0,112.0,240.0)}, 	// 5
        {bn::fixed_rect(128.0,-56.0,64.0,240.0)}, 	// 6
        {bn::fixed_rect(208.0,-56.0,64.0,240.0)}, 	// 7
        {bn::fixed_rect(-48.0,-104.0,32.0,112.0)}, 	// 8
        {bn::fixed_rect(-48.0,16.0,32.0,96.0)}, 	// 9
        {bn::fixed_rect(88.0,-104.0,16.0,48.0)}, 	// 10
        {bn::fixed_rect(88.0,0.0,16.0,64.0)}, 	// 11
        {bn::fixed_rect(168.0,-104.0,16.0,48.0)}, 	// 12
        {bn::fixed_rect(168.0,0.0,16.0,64.0)}, 	// 13
        {bn::fixed_rect(248.0,-208.0,16.0,32.0)}, 	// 14
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST2_0_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST2_0_TRACE_CNN_INIT_LIST_SIZE (19)
    struct trace_manager::connection_init_data_t connection_init_data[ST2_0_TRACE_CNN_INIT_LIST_SIZE] = {
        {1,0,bn::fixed_point(-104.0,80),bn::fixed_point(-104.0,112)}, 	//1
        {1,3,bn::fixed_point(-104.0,-224),bn::fixed_point(-88.0,-224)}, 	//4
        {2,0,bn::fixed_point(232.0,80),bn::fixed_point(232.0,112)}, 	//3
        {3,4,bn::fixed_point(-72.0,-224),bn::fixed_point(-56.0,-224)}, 	//6
        {4,5,bn::fixed_point(72.0,-192),bn::fixed_point(72.0,-160)}, 	//12
        {4,6,bn::fixed_point(152.0,-192),bn::fixed_point(152.0,-160)}, 	//14
        {4,7,bn::fixed_point(232.0,-192),bn::fixed_point(232.0,-160)}, 	//16
        {4,14,bn::fixed_point(232.0,-208),bn::fixed_point(248.0,-208)}, 	//10
        {5,10,bn::fixed_point(72.0,-112),bn::fixed_point(88.0,-112)}, 	//22
        {5,11,bn::fixed_point(72.0,-16),bn::fixed_point(88.0,-16)}, 	//25
        {6,12,bn::fixed_point(152.0,-112),bn::fixed_point(168.0,-112)}, 	//28
        {6,13,bn::fixed_point(152.0,-16),bn::fixed_point(168.0,-16)}, 	//31
        {7,2,bn::fixed_point(232.0,48),bn::fixed_point(232.0,80)}, 	//9
        {8,5,bn::fixed_point(-40.0,-144),bn::fixed_point(-24.0,-144)}, 	//19
        {9,5,bn::fixed_point(-40.0,-16),bn::fixed_point(-24.0,-16)}, 	//21
        {10,6,bn::fixed_point(88.0,-112),bn::fixed_point(104.0,-112)}, 	//23
        {11,6,bn::fixed_point(88.0,-16),bn::fixed_point(104.0,-16)}, 	//26
        {12,7,bn::fixed_point(168.0,-112),bn::fixed_point(184.0,-112)}, 	//29
        {13,7,bn::fixed_point(168.0,-16),bn::fixed_point(184.0,-16)}, 	//32
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST2_0_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST2_0_AI_LIST_NUM (5)
    #define ST2_0_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST2_0_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_0_AI_002_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_002_list[ST2_0_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_0_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST2_0_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_0_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST2_0_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_0_AI_005_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_005_list[ST2_0_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage2_0_static_data stage2_0_data;

static bool get_stage2_0_enable(int type, int id) {
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

void stage2::_stage2_0_create_enemy() {
    for (int list_idx = 0; list_idx < ST2_0_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage2_0_data.enemy_pos_000;
            current_ai = stage2_0_data.ai_001_list;
            current_ai_size = ST2_0_AI_001_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage2_0_data.enemy_pos_002;
            current_ai = stage2_0_data.ai_002_list;
            current_ai_size = ST2_0_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage2_0_data.enemy_pos_004;
            current_ai = stage2_0_data.ai_003_list;
            current_ai_size = ST2_0_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 3) {
            current_pos = stage2_0_data.enemy_pos_007;
            current_ai = stage2_0_data.ai_004_list;
            current_ai_size = ST2_0_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        if (list_idx == 4) {
            current_pos = stage2_0_data.enemy_pos_008;
            current_ai = stage2_0_data.ai_005_list;
            current_ai_size = ST2_0_AI_005_LIST_SIZE;
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
    }
}

