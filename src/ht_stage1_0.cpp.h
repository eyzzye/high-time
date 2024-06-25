//
// stage1_0
//
struct stage1_0_static_data {
    bn::fixed_point enemy_pos_000 = { 40,32 };		// 0
    bn::fixed_point enemy_pos_001 = { 40,-16 };		// 1
    bn::fixed_point enemy_pos_002 = { -24,-16 };		// 2
    bn::fixed_point enemy_pos_003 = { -24,32 };		// 3
    bn::fixed_point enemy_pos_004 = { -56,80 };		// 4
    bn::fixed_point enemy_pos_005 = { 72,80 };		// 5
    bn::fixed_point enemy_pos_006 = { 72,-64 };		// 6
    bn::fixed_point enemy_pos_007 = { -56,-64 };		// 7
    bn::fixed_point enemy_pos_008 = { -104,128 };		// 8
    bn::fixed_point enemy_pos_009 = { 120,128 };		// 9
    bn::fixed_point enemy_pos_010 = { 120,-112 };		// 10
    bn::fixed_point enemy_pos_011 = { -104,-112 };		// 11
    bn::fixed_point enemy_pos_012 = { -168,192 };		// 12
    bn::fixed_point enemy_pos_013 = { 184,192 };		// 13
    bn::fixed_point enemy_pos_014 = { 184,-176 };		// 14
    bn::fixed_point enemy_pos_015 = { -168,-176 };		// 15

    #define ST1_0_TERRAIN_INIT_LIST_SIZE (19)
    struct terrain_init_data_t terrain_init_data[ST1_0_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-240.0,512.0,32.0)},
        {bn::fixed_rect(-240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(8.0,-144.0,336.0,32.0)},
        {bn::fixed_rect(-144.0,24.0,32.0,304.0)},
        {bn::fixed_rect(160.0,24.0,32.0,304.0)},
        {bn::fixed_rect(-48.0,-88.0,96.0,16.0)},
        {bn::fixed_rect(72.0,-88.0,80.0,16.0)},
        {bn::fixed_rect(-88.0,16.0,16.0,192.0)},
        {bn::fixed_rect(104.0,16.0,16.0,192.0)},
        {bn::fixed_rect(8.0,-40.0,112.0,16.0)},
        {bn::fixed_rect(-40.0,16.0,16.0,96.0)},
        {bn::fixed_rect(56.0,16.0,16.0,96.0)},
        {bn::fixed_rect(-16.0,56.0,32.0,16.0)},
        {bn::fixed_rect(48.0,56.0,32.0,16.0)},
        {bn::fixed_rect(16.0,104.0,192.0,16.0)},
        {bn::fixed_rect(-64.0,160.0,128.0,32.0)},
        {bn::fixed_rect(104.0,160.0,144.0,32.0)},
        {bn::fixed_rect(16.0,240.0,480.0,32.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST1_0_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST1_0_BG_MAP_LIST_SIZE (12)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST1_0_BG_MAP_LIST_SIZE] = {
        { 32,8,UP_STAIRS_TILE1 },
        { 33,8,UP_STAIRS_TILE2 },
        { 32,9,UP_STAIRS_TILE3 },
        { 33,9,UP_STAIRS_TILE4 },
        { 32,38,DOWN_GATE_CLOSE_TILE1 },
        { 33,38,DOWN_GATE_CLOSE_TILE2 },
        { 34,38,DOWN_GATE_CLOSE_TILE3 },
        { 35,38,DOWN_GATE_CLOSE_TILE4 },
        { 32,39,DOWN_GATE_CLOSE_TILE5 },
        { 33,39,DOWN_GATE_CLOSE_TILE6 },
        { 34,39,DOWN_GATE_CLOSE_TILE7 },
        { 35,39,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST1_0_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST1_0_STAIRS_LIST_SIZE (1)
    struct ht::stairs_init_data_t stairs_init_data[ST1_0_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(8,-184),1,bn::fixed_point(24,-184)},
    };
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST1_0_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST1_0_GATE_LIST_SIZE (1)
    struct ht::gate_init_data_t gate_init_data[ST1_0_GATE_LIST_SIZE] = {
        {bn::fixed_rect(16,56,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST1_0_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST1_0_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST1_0_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(-24,-24,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST1_0_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST1_0_TRACE_AREA_INIT_LIST_SIZE (16)
    struct trace_manager::area_init_data_t area_init_data[ST1_0_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(8.0,8.0,80.0,80.0)}, 	// 0
        {bn::fixed_rect(16.0,56.0,32.0,16.0)}, 	// 1
        {bn::fixed_rect(8.0,80.0,176.0,32.0)}, 	// 2
        {bn::fixed_rect(80.0,8.0,32.0,112.0)}, 	// 3
        {bn::fixed_rect(-64.0,8.0,32.0,112.0)}, 	// 4
        {bn::fixed_rect(8.0,-64.0,176.0,32.0)}, 	// 5
        {bn::fixed_rect(16.0,-88.0,32.0,16.0)}, 	// 6
        {bn::fixed_rect(8.0,-112.0,272.0,32.0)}, 	// 7
        {bn::fixed_rect(128.0,8.0,32.0,208.0)}, 	// 8
        {bn::fixed_rect(-112.0,8.0,32.0,208.0)}, 	// 9
        {bn::fixed_rect(8.0,128.0,272.0,32.0)}, 	// 10
        {bn::fixed_rect(16.0,160.0,32.0,32.0)}, 	// 11
        {bn::fixed_rect(0.0,200.0,448.0,48.0)}, 	// 12
        {bn::fixed_rect(200.0,8.0,48.0,336.0)}, 	// 13
        {bn::fixed_rect(-192.0,8.0,64.0,336.0)}, 	// 14
        {bn::fixed_rect(0.0,-192.0,448.0,64.0)}, 	// 15
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST1_0_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST1_0_TRACE_CNN_INIT_LIST_SIZE (18)
    struct trace_manager::connection_init_data_t connection_init_data[ST1_0_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,1,bn::fixed_point(24.0,32),bn::fixed_point(24.0,64)}, 	//0
        {1,2,bn::fixed_point(24.0,48),bn::fixed_point(24.0,80)}, 	//1
        {3,2,bn::fixed_point(72.0,48),bn::fixed_point(72.0,80)}, 	//4
        {4,2,bn::fixed_point(-56.0,48),bn::fixed_point(-56.0,80)}, 	//6
        {5,3,bn::fixed_point(72.0,-64),bn::fixed_point(72.0,-32)}, 	//8
        {5,4,bn::fixed_point(-56.0,-64),bn::fixed_point(-56.0,-32)}, 	//10
        {6,5,bn::fixed_point(24.0,-96),bn::fixed_point(24.0,-64)}, 	//12
        {7,6,bn::fixed_point(24.0,-112),bn::fixed_point(24.0,-80)}, 	//13
        {7,8,bn::fixed_point(120.0,-112),bn::fixed_point(120.0,-80)}, 	//14
        {7,9,bn::fixed_point(-104.0,-112),bn::fixed_point(-104.0,-80)}, 	//16
        {8,10,bn::fixed_point(120.0,96),bn::fixed_point(120.0,128)}, 	//18
        {9,10,bn::fixed_point(-104.0,96),bn::fixed_point(-104.0,128)}, 	//20
        {10,11,bn::fixed_point(24.0,128),bn::fixed_point(24.0,160)}, 	//22
        {11,12,bn::fixed_point(24.0,160),bn::fixed_point(24.0,192)}, 	//24
        {13,12,bn::fixed_point(184.0,160),bn::fixed_point(184.0,192)}, 	//27
        {14,12,bn::fixed_point(-168.0,160),bn::fixed_point(-168.0,192)}, 	//29
        {15,13,bn::fixed_point(184.0,-176),bn::fixed_point(184.0,-144)}, 	//31
        {15,14,bn::fixed_point(-168.0,-176),bn::fixed_point(-168.0,-144)}, 	//33
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST1_0_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST1_0_AI_LIST_NUM (5) 
    #define ST1_0_AI_001_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_001_list[ST1_0_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_0_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST1_0_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_0_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST1_0_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_0_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST1_0_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_0_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST1_0_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };

};

BN_DATA_EWRAM stage1_0_static_data stage1_0_data;

static bool get_stage1_0_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::STAIRS) return true;
        if (id == (int)ht::object::event_id::TELEPORT) return false;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage1::_stage1_0_create_enemy() {
    for (int list_idx = 0; list_idx < ST1_0_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage1_0_data.enemy_pos_000;
            current_ai = stage1_0_data.ai_001_list;
            current_ai_size = ST1_0_AI_001_LIST_SIZE;
        }
        else if (list_idx == 1) {
            current_pos = stage1_0_data.enemy_pos_004;
            current_ai = stage1_0_data.ai_002_list;
            current_ai_size = ST1_0_AI_002_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
        }
        else if (list_idx == 2) {
            current_pos = stage1_0_data.enemy_pos_008;
            current_ai = stage1_0_data.ai_003_list;
            current_ai_size = ST1_0_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        else if (list_idx == 3) {
            current_pos = stage1_0_data.enemy_pos_012;
            current_ai = stage1_0_data.ai_004_list;
            current_ai_size = ST1_0_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 4) {
            current_pos = stage1_0_data.enemy_pos_015;
            current_ai = stage1_0_data.ai_005_list;
            current_ai_size = ST1_0_AI_005_LIST_SIZE;
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

