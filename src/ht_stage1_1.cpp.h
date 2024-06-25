//
// stage1_1
//
struct stage1_1_static_data {
    bn::fixed_point enemy_pos_000 = { 56,64 };		// 0
    bn::fixed_point enemy_pos_001 = { 56,-32 };		// 1
    bn::fixed_point enemy_pos_002 = { -40,-32 };		// 2
    bn::fixed_point enemy_pos_003 = { -40,64 };		// 3
    bn::fixed_point enemy_pos_004 = { 88,-96 };		// 4
    bn::fixed_point enemy_pos_005 = { -72,-96 };		// 5
    bn::fixed_point enemy_pos_006 = { -104,128 };		// 6
    bn::fixed_point enemy_pos_007 = { 120,128 };		// 7
    bn::fixed_point enemy_pos_008 = { 184,208 };		// 8
    bn::fixed_point enemy_pos_009 = { 184,-208 };		// 9
    bn::fixed_point enemy_pos_010 = { 200,208 };		// 10
    bn::fixed_point enemy_pos_011 = { 200,-208 };		// 11
    bn::fixed_point enemy_pos_012 = { -152,-16 };		// 12
    bn::fixed_point enemy_pos_013 = { -200,48 };		// 13
    bn::fixed_point enemy_pos_014 = { -152,112 };		// 14
    bn::fixed_point enemy_pos_015 = { -200,176 };		// 15

    #define ST1_1_TERRAIN_INIT_LIST_SIZE (18)
    struct terrain_init_data_t terrain_init_data[ST1_1_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-240.0,512.0,32.0)},
        {bn::fixed_rect(-240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(-120.0,-176.0,16.0,96.0)},
        {bn::fixed_rect(144.0,-56.0,32.0,336.0)},
        {bn::fixed_rect(-56.0,-160.0,16.0,64.0)},
        {bn::fixed_rect(240.0,40.0,32.0,432.0)},
        {bn::fixed_rect(-152.0,-136.0,80.0,16.0)},
        {bn::fixed_rect(56.0,-136.0,208.0,16.0)},
        {bn::fixed_rect(-168.0,-72.0,112.0,16.0)},
        {bn::fixed_rect(8.0,-72.0,144.0,16.0)},
        {bn::fixed_rect(-120.0,64.0,16.0,256.0)},
        {bn::fixed_rect(-56.0,-16.0,16.0,96.0)},
        {bn::fixed_rect(72.0,24.0,16.0,176.0)},
        {bn::fixed_rect(48.0,96.0,224.0,32.0)},
        {bn::fixed_rect(8.0,152.0,144.0,16.0)},
        {bn::fixed_rect(144.0,200.0,32.0,112.0)},
        {bn::fixed_rect(72.0,208.0,16.0,96.0)},
        {bn::fixed_rect(16.0,240.0,480.0,32.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST1_1_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST1_1_BG_MAP_LIST_SIZE (20)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST1_1_BG_MAP_LIST_SIZE] = {
        { 32,8,DOWN_STAIRS_TILE1 },
        { 33,8,DOWN_STAIRS_TILE2 },
        { 32,9,DOWN_STAIRS_TILE3 },
        { 33,9,DOWN_STAIRS_TILE4 },
        { 50,46,RIGHT_GATE_CLOSE_TILE1 },
        { 51,46,RIGHT_GATE_CLOSE_TILE2 },
        { 50,47,RIGHT_GATE_CLOSE_TILE3 },
        { 51,47,RIGHT_GATE_CLOSE_TILE4 },
        { 50,48,RIGHT_GATE_CLOSE_TILE5 },
        { 51,48,RIGHT_GATE_CLOSE_TILE6 },
        { 50,49,RIGHT_GATE_CLOSE_TILE7 },
        { 51,49,RIGHT_GATE_CLOSE_TILE8 },
        { 16,56,RIGHT_GATE_CLOSE_TILE1 },
        { 17,56,RIGHT_GATE_CLOSE_TILE2 },
        { 16,57,RIGHT_GATE_CLOSE_TILE3 },
        { 17,57,RIGHT_GATE_CLOSE_TILE4 },
        { 16,58,RIGHT_GATE_CLOSE_TILE5 },
        { 17,58,RIGHT_GATE_CLOSE_TILE6 },
        { 16,59,RIGHT_GATE_CLOSE_TILE7 },
        { 17,59,RIGHT_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST1_1_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST1_1_STAIRS_LIST_SIZE (1)
    struct ht::stairs_init_data_t stairs_init_data[ST1_1_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(8,-184),0,bn::fixed_point(-8,-184)},
    }; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST1_1_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST1_1_TELEPORT_LIST_SIZE (1)
    struct ht::teleport_init_data_t teleport_init_data[ST1_1_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(240.0,-200.0,32.0,48.0),2,bn::fixed_point(-216,-200)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST1_1_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST1_1_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST1_1_GATE_LIST_SIZE] = {
        {bn::fixed_rect(152,128,16,32),ht::directions::RIGHT},
        {bn::fixed_rect(-120,208,16,32),ht::directions::RIGHT},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST1_1_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST1_1_ITEM_KEY_LIST_SIZE (2)
    struct ht::item_key_init_data_t item_key_init_data[ST1_1_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(56,-56,16,16)},
        {bn::fixed_rect(-200,-40,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST1_1_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST1_1_TRACE_AREA_INIT_LIST_SIZE (17)
    struct trace_manager::area_init_data_t area_init_data[ST1_1_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(40.0,-184.0,176.0,80.0)}, 	// 0
        {bn::fixed_rect(-56.0,-208.0,16.0,32.0)}, 	// 1
        {bn::fixed_rect(-88.0,0.0,48.0,448.0)}, 	// 2
        {bn::fixed_rect(32.0,-104.0,192.0,48.0)}, 	// 3
        {bn::fixed_rect(-168.0,-104.0,112.0,48.0)}, 	// 4
        {bn::fixed_rect(104.0,0.0,48.0,160.0)}, 	// 5
        {bn::fixed_rect(-208.0,-136.0,32.0,16.0)}, 	// 6
        {bn::fixed_rect(-56.0,56.0,16.0,48.0)}, 	// 7
        {bn::fixed_rect(-120.0,208.0,16.0,32.0)}, 	// 8
        {bn::fixed_rect(48.0,128.0,224.0,32.0)}, 	// 9
        {bn::fixed_rect(-176.0,-184.0,96.0,80.0)}, 	// 10
        {bn::fixed_rect(8.0,8.0,112.0,144.0)}, 	// 11
        {bn::fixed_rect(-176.0,80.0,96.0,288.0)}, 	// 12
        {bn::fixed_rect(0.0,192.0,128.0,64.0)}, 	// 13
        {bn::fixed_rect(104.0,184.0,48.0,80.0)}, 	// 14
        {bn::fixed_rect(192.0,0.0,64.0,448.0)}, 	// 15
        {bn::fixed_rect(240.0,-200.0,32.0,48.0)}, 	// 16
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST1_1_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST1_1_TRACE_CNN_INIT_LIST_SIZE (16)
    struct trace_manager::connection_init_data_t connection_init_data[ST1_1_TRACE_CNN_INIT_LIST_SIZE] = {
        {1,0,bn::fixed_point(-56.0,-208),bn::fixed_point(-40.0,-208)}, 	//1
        {2,1,bn::fixed_point(-72.0,-208),bn::fixed_point(-56.0,-208)}, 	//2
        {2,3,bn::fixed_point(-72.0,-112),bn::fixed_point(-56.0,-112)}, 	//3
        {2,7,bn::fixed_point(-72.0,48),bn::fixed_point(-56.0,48)}, 	//14
        {2,9,bn::fixed_point(-72.0,128),bn::fixed_point(-56.0,128)}, 	//12
        {2,13,bn::fixed_point(-72.0,176),bn::fixed_point(-56.0,176)}, 	//10
        {3,5,bn::fixed_point(88.0,-96),bn::fixed_point(88.0,-64)}, 	//17
        {4,2,bn::fixed_point(-120.0,-112),bn::fixed_point(-104.0,-112)}, 	//6
        {6,4,bn::fixed_point(-200.0,-144),bn::fixed_point(-200.0,-112)}, 	//20
        {7,11,bn::fixed_point(-56.0,48),bn::fixed_point(-40.0,48)}, 	//15
        {8,2,bn::fixed_point(-120.0,208),bn::fixed_point(-104.0,208)}, 	//8
        {9,14,bn::fixed_point(88.0,128),bn::fixed_point(88.0,160)}, 	//24
        {9,15,bn::fixed_point(152.0,128),bn::fixed_point(168.0,128)}, 	//22
        {10,6,bn::fixed_point(-200.0,-160),bn::fixed_point(-200.0,-128)}, 	//21
        {12,8,bn::fixed_point(-136.0,208),bn::fixed_point(-120.0,208)}, 	//9
        {15,16,bn::fixed_point(216.0,-208),bn::fixed_point(232.0,-208)}, 	//26
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST1_1_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST1_1_AI_LIST_NUM (6)
    #define ST1_1_AI_001_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_001_list[ST1_1_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_1_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST1_1_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_1_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST1_1_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_1_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST1_1_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_1_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST1_1_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST1_1_AI_006_LIST_SIZE (12)
    struct ht::ai_scenario_t ai_006_list[ST1_1_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage1_1_static_data stage1_1_data;

static bool get_stage1_1_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage1::_stage1_1_create_enemy() {
    for (int list_idx = 0; list_idx < ST1_1_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage1_1_data.enemy_pos_000;
            current_ai = stage1_1_data.ai_001_list;
            current_ai_size = ST1_1_AI_001_LIST_SIZE;
        }
        else if (list_idx == 1) {
            current_pos = stage1_1_data.enemy_pos_004;
            current_ai = stage1_1_data.ai_002_list;
            current_ai_size = ST1_1_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        else if (list_idx == 2) {
            current_pos = stage1_1_data.enemy_pos_006;
            current_ai = stage1_1_data.ai_003_list;
            current_ai_size = ST1_1_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
        }
        else if (list_idx == 3) {
            current_pos = stage1_1_data.enemy_pos_008;
            current_ai = stage1_1_data.ai_004_list;
            current_ai_size = ST1_1_AI_004_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 4) {
            current_pos = stage1_1_data.enemy_pos_011;
            current_ai = stage1_1_data.ai_005_list;
            current_ai_size = ST1_1_AI_005_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        else if (list_idx == 5) {
            current_pos = stage1_1_data.enemy_pos_012;
            current_ai = stage1_1_data.ai_006_list;
            current_ai_size = ST1_1_AI_006_LIST_SIZE;
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

