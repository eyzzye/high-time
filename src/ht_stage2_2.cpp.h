//
// stage2_2
//
struct stage2_2_static_data {
    bn::fixed_point enemy_pos_000 = { 24,80 };		// 0
    bn::fixed_point enemy_pos_001 = { 24,208 };		// 1
    bn::fixed_point enemy_pos_002 = { -24,80 };		// 2
    bn::fixed_point enemy_pos_003 = { -24,208 };		// 3
    bn::fixed_point enemy_pos_004 = { -200,-16 };		// 4

    #define ST2_2_TERRAIN_INIT_LIST_SIZE (20)
    struct terrain_init_data_t terrain_init_data[ST2_2_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-240.0,512.0,32.0)},
        {bn::fixed_rect(-240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(-48.0,-120.0,32.0,208.0)},
        {bn::fixed_rect(48.0,-192.0,32.0,64.0)},
        {bn::fixed_rect(240.0,16.0,32.0,480.0)},
        {bn::fixed_rect(-144.0,32.0,64.0,448.0)},
        {bn::fixed_rect(-24.0,-104.0,16.0,176.0)},
        {bn::fixed_rect(40.0,-176.0,48.0,32.0)},
        {bn::fixed_rect(144.0,-184.0,96.0,16.0)},
        {bn::fixed_rect(112.0,-128.0,32.0,96.0)},
        {bn::fixed_rect(176.0,-96.0,32.0,160.0)},
        {bn::fixed_rect(56.0,-104.0,144.0,48.0)},
        {bn::fixed_rect(24.0,-48.0,80.0,64.0)},
        {bn::fixed_rect(112.0,104.0,32.0,304.0)},
        {bn::fixed_rect(-120.0,32.0,208.0,32.0)},
        {bn::fixed_rect(136.0,32.0,240.0,32.0)},
        {bn::fixed_rect(-144.0,152.0,160.0,208.0)},
        {bn::fixed_rect(160.0,152.0,192.0,208.0)},
        {bn::fixed_rect(-40.0,248.0,48.0,16.0)},
        {bn::fixed_rect(136.0,248.0,240.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST2_2_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST2_2_BG_MAP_LIST_SIZE (16)
    struct ht::bg_map_manager::init_data_t bg_map_init_data[ST2_2_BG_MAP_LIST_SIZE] = {
        { 30,8,UP_GATE_CLOSE_TILE1 },
        { 31,8,UP_GATE_CLOSE_TILE2 },
        { 32,8,UP_GATE_CLOSE_TILE3 },
        { 33,8,UP_GATE_CLOSE_TILE4 },
        { 30,9,UP_GATE_CLOSE_TILE5 },
        { 31,9,UP_GATE_CLOSE_TILE6 },
        { 32,9,UP_GATE_CLOSE_TILE7 },
        { 33,9,UP_GATE_CLOSE_TILE8 },
        { 30,36,UP_GATE_CLOSE_TILE1 },
        { 31,36,UP_GATE_CLOSE_TILE2 },
        { 32,36,UP_GATE_CLOSE_TILE3 },
        { 33,36,UP_GATE_CLOSE_TILE4 },
        { 30,37,UP_GATE_CLOSE_TILE5 },
        { 31,37,UP_GATE_CLOSE_TILE6 },
        { 32,37,UP_GATE_CLOSE_TILE7 },
        { 33,37,UP_GATE_CLOSE_TILE8 },
    };
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST2_2_BG_MAP_LIST_SIZE,
        bg_map_init_data
    };

    #define ST2_2_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST2_2_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST2_2_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST2_2_TELEPORT_LIST_SIZE (1)
    struct ht::teleport_init_data_t teleport_init_data[ST2_2_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,248.0,32.0,16.0),1,bn::fixed_point(0,-224)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST2_2_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST2_2_GATE_LIST_SIZE (2)
    struct ht::gate_init_data_t gate_init_data[ST2_2_GATE_LIST_SIZE] = {
        {bn::fixed_rect(0,-184,32,16),ht::directions::UP},
        {bn::fixed_rect(0,40,32,16),ht::directions::UP},
    };
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST2_2_GATE_LIST_SIZE,
        gate_init_data
    };

    #define ST2_2_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST2_2_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(152,-168,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST2_2_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST2_2_TRACE_AREA_INIT_LIST_SIZE (17)
    struct trace_manager::area_init_data_t area_init_data[ST2_2_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,248.0,32.0,16.0)}, 	// 0
        {bn::fixed_rect(0.0,144.0,128.0,192.0)}, 	// 1
        {bn::fixed_rect(0.0,32.0,32.0,32.0)}, 	// 2
        {bn::fixed_rect(-8.0,0.0,208.0,32.0)}, 	// 3
        {bn::fixed_rect(-88.0,-120.0,48.0,208.0)}, 	// 4
        {bn::fixed_rect(-144.0,-208.0,64.0,32.0)}, 	// 5
        {bn::fixed_rect(-200.0,-104.0,48.0,240.0)}, 	// 6
        {bn::fixed_rect(80.0,-48.0,32.0,64.0)}, 	// 7
        {bn::fixed_rect(112.0,-64.0,32.0,32.0)}, 	// 8
        {bn::fixed_rect(144.0,-80.0,32.0,192.0)}, 	// 9
        {bn::fixed_rect(176.0,0.0,32.0,32.0)}, 	// 10
        {bn::fixed_rect(208.0,-104.0,32.0,240.0)}, 	// 11
        {bn::fixed_rect(144.0,-208.0,96.0,32.0)}, 	// 12
        {bn::fixed_rect(80.0,-176.0,32.0,96.0)}, 	// 13
        {bn::fixed_rect(40.0,-144.0,48.0,32.0)}, 	// 14
        {bn::fixed_rect(0.0,-160.0,32.0,64.0)}, 	// 15
        {bn::fixed_rect(0.0,-208.0,64.0,32.0)}, 	// 16
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST2_2_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST2_2_TRACE_CNN_INIT_LIST_SIZE (16)
    struct trace_manager::connection_init_data_t connection_init_data[ST2_2_TRACE_CNN_INIT_LIST_SIZE] = {
        {1,0,bn::fixed_point(8.0,224),bn::fixed_point(8.0,256)}, 	//1
        {2,1,bn::fixed_point(8.0,32),bn::fixed_point(8.0,64)}, 	//3
        {3,2,bn::fixed_point(8.0,0),bn::fixed_point(8.0,32)}, 	//5
        {4,3,bn::fixed_point(-72.0,-32),bn::fixed_point(-72.0,0)}, 	//7
        {5,4,bn::fixed_point(-120.0,-208),bn::fixed_point(-104.0,-208)}, 	//9
        {6,5,bn::fixed_point(-184.0,-208),bn::fixed_point(-168.0,-208)}, 	//11
        {7,3,bn::fixed_point(88.0,-32),bn::fixed_point(88.0,0)}, 	//13
        {7,8,bn::fixed_point(88.0,-64),bn::fixed_point(104.0,-64)}, 	//14
        {8,9,bn::fixed_point(120.0,-64),bn::fixed_point(136.0,-64)}, 	//16
        {9,10,bn::fixed_point(152.0,0),bn::fixed_point(168.0,0)}, 	//18
        {10,11,bn::fixed_point(184.0,0),bn::fixed_point(200.0,0)}, 	//20
        {12,11,bn::fixed_point(184.0,-208),bn::fixed_point(200.0,-208)}, 	//23
        {13,12,bn::fixed_point(88.0,-208),bn::fixed_point(104.0,-208)}, 	//25
        {14,13,bn::fixed_point(56.0,-144),bn::fixed_point(72.0,-144)}, 	//27
        {15,14,bn::fixed_point(8.0,-144),bn::fixed_point(24.0,-144)}, 	//29
        {16,15,bn::fixed_point(8.0,-208),bn::fixed_point(8.0,-176)}, 	//31
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST2_2_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST2_2_AI_LIST_NUM (3)
    #define ST2_2_AI_001_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_001_list[ST2_2_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_2_AI_002_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_002_list[ST2_2_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST2_2_AI_003_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_003_list[ST2_2_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage2_2_static_data stage2_2_data;

static bool get_stage2_2_enable(int type, int id) {
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

void stage2::_stage2_2_create_enemy() {
    for (int list_idx = 0; list_idx < ST2_2_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::NORMAL;

        if (list_idx == 0) {
            current_pos = stage2_2_data.enemy_pos_000;
            current_ai = stage2_2_data.ai_001_list;
            current_ai_size = ST2_2_AI_001_LIST_SIZE;
            grade = ht::enemy::grade::HARD;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage2_2_data.enemy_pos_002;
            current_ai = stage2_2_data.ai_002_list;
            current_ai_size = ST2_2_AI_002_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage2_2_data.enemy_pos_004;
            current_ai = stage2_2_data.ai_003_list;
            current_ai_size = ST2_2_AI_003_LIST_SIZE;
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

