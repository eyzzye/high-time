//
// stage1_2
//
struct stage1_2_static_data {
    bn::fixed_point enemy_pos_000 = { -200,48 };		// 0
    bn::fixed_point enemy_pos_001 = { 88,48 };		// 1
    bn::fixed_point enemy_pos_002 = { 88,-176 };		// 2
    bn::fixed_point enemy_pos_003 = { 8,-16 };		// 3
    bn::fixed_point enemy_pos_004 = { -104,-16 };		// 4
    bn::fixed_point enemy_pos_005 = { -200,-176 };		// 5
    bn::fixed_point enemy_pos_006 = { -200,128 };		// 6
    bn::fixed_point enemy_pos_007 = { 120,128 };		// 7
    bn::fixed_point enemy_pos_008 = { -200,176 };		// 8
    bn::fixed_point enemy_pos_009 = { 120,176 };		// 9
    bn::fixed_point enemy_pos_010 = { 184,-176 };		// 10
    bn::fixed_point enemy_pos_011 = { 184,80 };		// 11

    #define ST1_2_TERRAIN_INIT_LIST_SIZE (9)
    struct terrain_init_data_t terrain_init_data[ST1_2_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-240.0,512.0,32.0)},
        {bn::fixed_rect(-48.0,-128.0,32.0,192.0)},
        {bn::fixed_rect(128.0,-64.0,32.0,320.0)},
        {bn::fixed_rect(240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(-240.0,40.0,32.0,432.0)},
        {bn::fixed_rect(-48.0,16.0,96.0,32.0)},
        {bn::fixed_rect(-144.0,80.0,160.0,32.0)},
        {bn::fixed_rect(56.0,80.0,176.0,32.0)},
        {bn::fixed_rect(16.0,240.0,480.0,32.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST1_2_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST1_2_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST1_2_BG_MAP_LIST_SIZE] = {
        { 26,28,RIGHT_GATE_CLOSE_TILE1 },
        { 27,28,RIGHT_GATE_CLOSE_TILE2 },
        { 26,29,RIGHT_GATE_CLOSE_TILE3 },
        { 27,29,RIGHT_GATE_CLOSE_TILE4 },
        { 26,30,RIGHT_GATE_CLOSE_TILE5 },
        { 27,30,RIGHT_GATE_CLOSE_TILE6 },
        { 26,31,RIGHT_GATE_CLOSE_TILE7 },
        { 27,31,RIGHT_GATE_CLOSE_TILE8 },
        { 24,42,DOWN_GATE_CLOSE_TILE1 },
        { 25,42,DOWN_GATE_CLOSE_TILE2 },
        { 26,42,DOWN_GATE_CLOSE_TILE3 },
        { 27,42,DOWN_GATE_CLOSE_TILE4 },
        { 24,43,DOWN_GATE_CLOSE_TILE5 },
        { 25,43,DOWN_GATE_CLOSE_TILE6 },
        { 26,43,DOWN_GATE_CLOSE_TILE7 },
        { 27,43,DOWN_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST1_2_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST1_2_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST1_2_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST1_2_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST1_2_TELEPORT_LIST_SIZE (1)
    struct ht::teleport_init_data_t teleport_init_data[ST1_2_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(-240.0,-200.0,32.0,48.0),1,bn::fixed_point(216,-200)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST1_2_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST1_2_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST1_2_GATE_LIST_SIZE] = {
        {bn::fixed_rect(-40,-16,16,32),ht::directions::RIGHT},
        {bn::fixed_rect(-48,88,32,16),ht::directions::DOWN},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST1_2_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST1_2_ITEM_KEY_LIST_SIZE (2)
    struct ht::item_key_init_data_t item_key_init_data[ST1_2_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(88,-200,16,16)},
        {bn::fixed_rect(184,-200,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST1_2_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST1_2_TRACE_AREA_INIT_LIST_SIZE (10)
    struct trace_manager::area_init_data_t area_init_data[ST1_2_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(-240.0,-200.0,32.0,48.0)}, 	// 0
        {bn::fixed_rect(-144.0,-112.0,160.0,224.0)}, 	// 1
        {bn::fixed_rect(-160.0,32.0,128.0,64.0)}, 	// 2
        {bn::fixed_rect(-48.0,48.0,96.0,32.0)}, 	// 3
        {bn::fixed_rect(-48.0,-16.0,32.0,32.0)}, 	// 4
        {bn::fixed_rect(40.0,-112.0,144.0,224.0)}, 	// 5
        {bn::fixed_rect(56.0,32.0,112.0,64.0)}, 	// 6
        {bn::fixed_rect(-48.0,80.0,32.0,32.0)}, 	// 7
        {bn::fixed_rect(0.0,160.0,448.0,128.0)}, 	// 8
        {bn::fixed_rect(184.0,-64.0,80.0,320.0)}, 	// 9
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST1_2_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST1_2_TRACE_CNN_INIT_LIST_SIZE (10)
    struct trace_manager::connection_init_data_t connection_init_data[ST1_2_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,1,bn::fixed_point(-232.0,-208),bn::fixed_point(-216.0,-208)}, 	//0
        {1,2,bn::fixed_point(-104.0,-16),bn::fixed_point(-104.0,16)}, 	//13
        {1,4,bn::fixed_point(-72.0,-16),bn::fixed_point(-56.0,-16)}, 	//2
        {2,3,bn::fixed_point(-104.0,48),bn::fixed_point(-88.0,48)}, 	//11
        {3,6,bn::fixed_point(-8.0,48),bn::fixed_point(8.0,48)}, 	//9
        {3,7,bn::fixed_point(-40.0,48),bn::fixed_point(-40.0,80)}, 	//14
        {4,5,bn::fixed_point(-40.0,-16),bn::fixed_point(-24.0,-16)}, 	//4
        {5,6,bn::fixed_point(8.0,-16),bn::fixed_point(8.0,16)}, 	//6
        {7,8,bn::fixed_point(-40.0,80),bn::fixed_point(-40.0,112)}, 	//16
        {9,8,bn::fixed_point(152.0,80),bn::fixed_point(152.0,112)}, 	//19
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST1_2_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST1_2_AI_LIST_NUM (6)
    #define ST1_2_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST1_2_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_2_AI_002_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_002_list[ST1_2_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_2_AI_003_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_003_list[ST1_2_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_2_AI_004_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_004_list[ST1_2_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_2_AI_005_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_005_list[ST1_2_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_2_AI_006_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_006_list[ST1_2_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };

};

BN_DATA_EWRAM stage1_2_static_data stage1_2_data;

static bool get_stage1_2_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::STAIRS) return false;
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage1::_stage1_2_create_enemy() {
    for (int list_idx = 0; list_idx < ST1_2_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage1_2_data.enemy_pos_000;
            current_ai = stage1_2_data.ai_001_list;
            current_ai_size = ST1_2_AI_001_LIST_SIZE;
        }
        else if (list_idx == 1) {
            current_pos = stage1_2_data.enemy_pos_002;
            current_ai = stage1_2_data.ai_002_list;
            current_ai_size = ST1_2_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        else if (list_idx == 2) {
            current_pos = stage1_2_data.enemy_pos_004;
            current_ai = stage1_2_data.ai_003_list;
            current_ai_size = ST1_2_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 3) {
            current_pos = stage1_2_data.enemy_pos_006;
            current_ai = stage1_2_data.ai_004_list;
            current_ai_size = ST1_2_AI_004_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 4) {
            current_pos = stage1_2_data.enemy_pos_009;
            current_ai = stage1_2_data.ai_005_list;
            current_ai_size = ST1_2_AI_005_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 5) {
            current_pos = stage1_2_data.enemy_pos_010;
            current_ai = stage1_2_data.ai_006_list;
            current_ai_size = ST1_2_AI_006_LIST_SIZE;
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

