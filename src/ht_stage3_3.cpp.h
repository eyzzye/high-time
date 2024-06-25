//
// stage3_3
//
struct stage3_3_static_data {
    bn::fixed_point enemy_pos_000 = { -24,48 };		// 0
    bn::fixed_point enemy_pos_001 = { 24,48 };		// 1
    bn::fixed_point enemy_pos_002 = { -56,32 };		// 2
    bn::fixed_point enemy_pos_003 = { -56,-32 };		// 3
    bn::fixed_point enemy_pos_004 = { 56,32 };		// 4
    bn::fixed_point enemy_pos_005 = { 56,-32 };		// 5
    bn::fixed_point enemy_pos_006 = { -88,32 };		// 6
    bn::fixed_point enemy_pos_007 = { -88,-32 };		// 7
    bn::fixed_point enemy_pos_008 = { 88,32 };		// 8
    bn::fixed_point enemy_pos_009 = { 88,-32 };		// 9
    bn::fixed_point enemy_pos_010 = { -200,-96 };		// 10
    bn::fixed_point enemy_pos_011 = { -168,-96 };		// 11
    bn::fixed_point enemy_pos_012 = { 200,-96 };		// 12
    bn::fixed_point enemy_pos_013 = { 168,-96 };		// 13
    bn::fixed_point enemy_pos_014 = { -88,-160 };		// 14
    bn::fixed_point enemy_pos_015 = { -88,-192 };		// 15
    bn::fixed_point enemy_pos_016 = { 88,-160 };		// 16
    bn::fixed_point enemy_pos_017 = { 88,-192 };		// 17
    bn::fixed_point enemy_pos_018 = { -8,-48 };		// 18

    #define ST3_3_TERRAIN_INIT_LIST_SIZE (13)
    struct terrain_init_data_t terrain_init_data[ST3_3_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-232.0,512.0,48.0)},
        {bn::fixed_rect(-232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(232.0,24.0,48.0,464.0)},
        {bn::fixed_rect(-72.0,-96.0,16.0,160.0)},
        {bn::fixed_rect(72.0,-96.0,16.0,160.0)},
        {bn::fixed_rect(0.0,-72.0,352.0,16.0)},
        {bn::fixed_rect(-72.0,136.0,16.0,240.0)},
        {bn::fixed_rect(72.0,136.0,16.0,240.0)},
        {bn::fixed_rect(-112.0,72.0,192.0,16.0)},
        {bn::fixed_rect(136.0,72.0,240.0,16.0)},
        {bn::fixed_rect(-136.0,168.0,144.0,176.0)},
        {bn::fixed_rect(168.0,168.0,176.0,176.0)},
        {bn::fixed_rect(96.0,232.0,320.0,48.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST3_3_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST3_3_BG_MAP_LIST_SIZE (20)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST3_3_BG_MAP_LIST_SIZE] = {
        { 32,52,DOWN_STAIRS_TILE1 },
        { 33,52,DOWN_STAIRS_TILE2 },
        { 32,53,DOWN_STAIRS_TILE3 },
        { 33,53,DOWN_STAIRS_TILE4 },
        { 22,6,LEFT_GATE_CLOSE_TILE1 },
        { 23,6,LEFT_GATE_CLOSE_TILE2 },
        { 22,7,LEFT_GATE_CLOSE_TILE3 },
        { 23,7,LEFT_GATE_CLOSE_TILE4 },
        { 22,8,LEFT_GATE_CLOSE_TILE5 },
        { 23,8,LEFT_GATE_CLOSE_TILE6 },
        { 22,9,LEFT_GATE_CLOSE_TILE7 },
        { 23,9,LEFT_GATE_CLOSE_TILE8 },
        { 40,6,RIGHT_GATE_CLOSE_TILE1 },
        { 41,6,RIGHT_GATE_CLOSE_TILE2 },
        { 40,7,RIGHT_GATE_CLOSE_TILE3 },
        { 41,7,RIGHT_GATE_CLOSE_TILE4 },
        { 40,8,RIGHT_GATE_CLOSE_TILE5 },
        { 41,8,RIGHT_GATE_CLOSE_TILE6 },
        { 40,9,RIGHT_GATE_CLOSE_TILE7 },
        { 41,9,RIGHT_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST3_3_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST3_3_STAIRS_LIST_SIZE (1)
    struct ht::stairs_init_data_t stairs_init_data[ST3_3_STAIRS_LIST_SIZE] = {
        {bn::fixed_point(8,168),2,bn::fixed_point(-8,168)},
    }; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST3_3_STAIRS_LIST_SIZE,
        stairs_init_data
    };

    #define ST3_3_TELEPORT_LIST_SIZE (0)
    //struct ht::teleport_init_data_t teleport_init_data[ST3_3_TELEPORT_LIST_SIZE] = {
    //};
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST3_3_TELEPORT_LIST_SIZE,
        NULL
    };

    #define ST3_3_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST3_3_GATE_LIST_SIZE] = {
        {bn::fixed_rect(-72,-192,16,32),ht::directions::LEFT},
        {bn::fixed_rect(72,-192,16,32),ht::directions::RIGHT},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST3_3_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST3_3_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST3_3_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(8,-40,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST3_3_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST3_3_TRACE_AREA_INIT_LIST_SIZE (14)
    struct trace_manager::area_init_data_t area_init_data[ST3_3_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,144.0,128.0,128.0)}, 	// 0
        {bn::fixed_rect(0.0,0.0,128.0,128.0)}, 	// 1
        {bn::fixed_rect(144.0,0.0,128.0,128.0)}, 	// 2
        {bn::fixed_rect(-144.0,0.0,128.0,128.0)}, 	// 3
        {bn::fixed_rect(144.0,-144.0,128.0,128.0)}, 	// 4
        {bn::fixed_rect(0.0,-144.0,128.0,128.0)}, 	// 5
        {bn::fixed_rect(-144.0,-144.0,128.0,128.0)}, 	// 6
        {bn::fixed_rect(0.0,72.0,32.0,16.0)}, 	// 7
        {bn::fixed_rect(72.0,0.0,16.0,32.0)}, 	// 8
        {bn::fixed_rect(-72.0,0.0,16.0,32.0)}, 	// 9
        {bn::fixed_rect(192.0,-72.0,32.0,16.0)}, 	// 10
        {bn::fixed_rect(-192.0,-72.0,32.0,16.0)}, 	// 11
        {bn::fixed_rect(72.0,-192.0,16.0,32.0)}, 	// 12
        {bn::fixed_rect(-72.0,-192.0,16.0,32.0)}, 	// 13
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST3_3_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST3_3_TRACE_CNN_INIT_LIST_SIZE (14)
    struct trace_manager::connection_init_data_t connection_init_data[ST3_3_TRACE_CNN_INIT_LIST_SIZE] = {
        {1,7,bn::fixed_point(8.0,48),bn::fixed_point(8.0,80)}, 	//2
        {1,8,bn::fixed_point(56.0,0),bn::fixed_point(72.0,0)}, 	//3
        {3,9,bn::fixed_point(-88.0,0),bn::fixed_point(-72.0,0)}, 	//8
        {4,10,bn::fixed_point(200.0,-96),bn::fixed_point(200.0,-64)}, 	//11
        {5,12,bn::fixed_point(56.0,-192),bn::fixed_point(72.0,-192)}, 	//17
        {6,11,bn::fixed_point(-200.0,-96),bn::fixed_point(-200.0,-64)}, 	//14
        {6,13,bn::fixed_point(-88.0,-192),bn::fixed_point(-72.0,-192)}, 	//18
        {7,0,bn::fixed_point(8.0,64),bn::fixed_point(8.0,96)}, 	//1
        {8,2,bn::fixed_point(72.0,0),bn::fixed_point(88.0,0)}, 	//4
        {9,1,bn::fixed_point(-72.0,0),bn::fixed_point(-56.0,0)}, 	//7
        {10,2,bn::fixed_point(200.0,-80),bn::fixed_point(200.0,-48)}, 	//10
        {11,3,bn::fixed_point(-200.0,-80),bn::fixed_point(-200.0,-48)}, 	//13
        {12,4,bn::fixed_point(72.0,-192),bn::fixed_point(88.0,-192)}, 	//16
        {13,5,bn::fixed_point(-72.0,-192),bn::fixed_point(-56.0,-192)}, 	//19
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST3_3_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST3_3_AI_LIST_NUM (10)
    #define ST3_3_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST3_3_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_002_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_002_list[ST3_3_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_003_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_003_list[ST3_3_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_004_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_004_list[ST3_3_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_005_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_005_list[ST3_3_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_006_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_006_list[ST3_3_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_007_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_007_list[ST3_3_AI_007_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_008_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_008_list[ST3_3_AI_008_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_009_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_009_list[ST3_3_AI_009_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_016},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_017},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST3_3_AI_010_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_010_list[ST3_3_AI_010_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_018},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage3_3_static_data stage3_3_data;

static bool get_stage3_3_enable(int type, int id) {
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
        if (id == (int)ht::object::event_id::TELEPORT) return false;
        if (id == (int)ht::object::event_id::GATE) return true;
        break;
    default:
        break;
    }
    return false;
}

void stage3::_stage3_3_create_enemy() {
    for (int list_idx = 0; list_idx < ST3_3_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage3_3_data.enemy_pos_000;
            current_ai = stage3_3_data.ai_001_list;
            current_ai_size = ST3_3_AI_001_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage3_3_data.enemy_pos_002;
            current_ai = stage3_3_data.ai_002_list;
            current_ai_size = ST3_3_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage3_3_data.enemy_pos_004;
            current_ai = stage3_3_data.ai_003_list;
            current_ai_size = ST3_3_AI_003_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 3) {
            current_pos = stage3_3_data.enemy_pos_006;
            current_ai = stage3_3_data.ai_004_list;
            current_ai_size = ST3_3_AI_004_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 4) {
            current_pos = stage3_3_data.enemy_pos_008;
            current_ai = stage3_3_data.ai_005_list;
            current_ai_size = ST3_3_AI_005_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 5) {
            current_pos = stage3_3_data.enemy_pos_010;
            current_ai = stage3_3_data.ai_006_list;
            current_ai_size = ST3_3_AI_006_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 6) {
            current_pos = stage3_3_data.enemy_pos_012;
            current_ai = stage3_3_data.ai_007_list;
            current_ai_size = ST3_3_AI_007_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 7) {
            current_pos = stage3_3_data.enemy_pos_014;
            current_ai = stage3_3_data.ai_008_list;
            current_ai_size = ST3_3_AI_008_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 8) {
            current_pos = stage3_3_data.enemy_pos_016;
            current_ai = stage3_3_data.ai_009_list;
            current_ai_size = ST3_3_AI_009_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 9) {
            current_pos = stage3_3_data.enemy_pos_018;
            current_ai = stage3_3_data.ai_010_list;
            current_ai_size = ST3_3_AI_010_LIST_SIZE;
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

