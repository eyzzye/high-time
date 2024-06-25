//
// stage4_2
//
struct stage4_2_static_data {
    bn::fixed_point enemy_pos_000 = { -232,32 };		// 0
    bn::fixed_point enemy_pos_001 = { -232,-32 };		// 1
    bn::fixed_point enemy_pos_002 = { -24,-224 };		// 2
    bn::fixed_point enemy_pos_003 = { 24,-224 };		// 3
    bn::fixed_point enemy_pos_004 = { -184,0 };		// 4
    bn::fixed_point enemy_pos_005 = { -152,48 };		// 5
    bn::fixed_point enemy_pos_006 = { -120,-48 };		// 6
    bn::fixed_point enemy_pos_007 = { -88,16 };		// 7
    bn::fixed_point enemy_pos_008 = { 72,-64 };		// 8
    bn::fixed_point enemy_pos_009 = { -72,64 };		// 9
    bn::fixed_point enemy_pos_010 = { 72,64 };		// 10
    bn::fixed_point enemy_pos_011 = { -72,-64 };		// 11
    bn::fixed_point enemy_pos_012 = { 216,-16 };		// 12
    bn::fixed_point enemy_pos_013 = { 184,48 };		// 13
    bn::fixed_point enemy_pos_014 = { 152,-48 };		// 14
    bn::fixed_point enemy_pos_015 = { 104,32 };		// 15
    bn::fixed_point enemy_pos_016 = { 24,224 };		// 16
    bn::fixed_point enemy_pos_017 = { -56,160 };		// 17
    bn::fixed_point enemy_pos_018 = { 24,80 };		// 18
    bn::fixed_point enemy_pos_019 = { 72,144 };		// 19
    bn::fixed_point enemy_pos_020 = { -8,-80 };		// 20
    bn::fixed_point enemy_pos_021 = { 56,-112 };		// 21
    bn::fixed_point enemy_pos_022 = { -72,-144 };		// 22
    bn::fixed_point enemy_pos_023 = { 40,-176 };		// 23
    bn::fixed_point enemy_pos_024 = { 232,-48 };		// 24
    bn::fixed_point enemy_pos_025 = { 232,48 };		// 25
    bn::fixed_point enemy_pos_026 = { -72,224 };		// 26
    bn::fixed_point enemy_pos_027 = { 72,224 };		// 27
    bn::fixed_point enemy_pos_028 = { -72,-224 };		// 28
    bn::fixed_point enemy_pos_029 = { 72,-224 };		// 29

    #define ST4_2_TERRAIN_INIT_LIST_SIZE (14)
    struct terrain_init_data_t terrain_init_data[ST4_2_TERRAIN_INIT_LIST_SIZE] = {
        {bn::fixed_rect(-136.0,-248.0,240.0,16.0)},
        {bn::fixed_rect(136.0,-248.0,240.0,16.0)},
        {bn::fixed_rect(-248.0,-128.0,16.0,224.0)},
        {bn::fixed_rect(-88.0,-160.0,16.0,160.0)},
        {bn::fixed_rect(88.0,-160.0,16.0,160.0)},
        {bn::fixed_rect(248.0,8.0,16.0,496.0)},
        {bn::fixed_rect(-160.0,-88.0,160.0,16.0)},
        {bn::fixed_rect(176.0,-88.0,160.0,16.0)},
        {bn::fixed_rect(-248.0,136.0,16.0,240.0)},
        {bn::fixed_rect(-160.0,88.0,160.0,16.0)},
        {bn::fixed_rect(168.0,88.0,176.0,16.0)},
        {bn::fixed_rect(-88.0,176.0,16.0,160.0)},
        {bn::fixed_rect(88.0,176.0,16.0,160.0)},
        {bn::fixed_rect(8.0,248.0,496.0,16.0)},
    };
    struct ht::array_t<struct terrain_init_data_t> terrain_init_list = {
        ST4_2_TERRAIN_INIT_LIST_SIZE,
        terrain_init_data
    };

    #define ST4_2_BG_MAP_LIST_SIZE (0)
    //struct ht::bg_map_manager::init_data_t bg_map_init_data[ST4_2_BG_MAP_LIST_SIZE] = {
    //};
    struct ht::array_t<struct ht::bg_map_manager::init_data_t> bg_map_init_list = {
        ST4_2_BG_MAP_LIST_SIZE,
        NULL
    };

    #define ST4_2_STAIRS_LIST_SIZE (0)
    //struct ht::stairs_init_data_t stairs_init_data[ST4_2_STAIRS_LIST_SIZE] = {
    //}; 
    struct ht::array_t<struct ht::stairs_init_data_t> stairs_init_list = {
        ST4_2_STAIRS_LIST_SIZE,
        NULL
    };

    #define ST4_2_TELEPORT_LIST_SIZE (2)
    struct ht::teleport_init_data_t teleport_init_data[ST4_2_TELEPORT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,-248.0,32.0,16.0),3,bn::fixed_point(0,224)},
        {bn::fixed_rect(-248.0,0.0,16.0,32.0),0,bn::fixed_point(232,-176)},
    };
    struct ht::array_t<struct ht::teleport_init_data_t> teleport_init_list = {
        ST4_2_TELEPORT_LIST_SIZE,
        teleport_init_data
    };

    #define ST4_2_GATE_LIST_SIZE (0)
    //struct ht::gate_init_data_t gate_init_data[ST4_2_GATE_LIST_SIZE] = {
    //};
    struct array_t<struct ht::gate_init_data_t> gate_init_list = {
        ST4_2_GATE_LIST_SIZE,
        NULL
    };

    #define ST4_2_ITEM_KEY_LIST_SIZE (1)
    struct ht::item_key_init_data_t item_key_init_data[ST4_2_ITEM_KEY_LIST_SIZE] = {
        {bn::fixed_rect(56,-56,16,16)},
    };
    struct ht::array_t<struct ht::item_key_init_data_t> item_key_init_list = {
        ST4_2_ITEM_KEY_LIST_SIZE,
        item_key_init_data
    };

    #define ST4_2_TRACE_AREA_INIT_LIST_SIZE (5)
    struct trace_manager::area_init_data_t area_init_data[ST4_2_TRACE_AREA_INIT_LIST_SIZE] = {
        {bn::fixed_rect(0.0,0.0,480.0,160.0)}, 	// 0
        {bn::fixed_rect(0.0,-160.0,160.0,160.0)}, 	// 1
        {bn::fixed_rect(0.0,160.0,160.0,160.0)}, 	// 2
        {bn::fixed_rect(-248.0,0.0,16.0,32.0)}, 	// 3
        {bn::fixed_rect(0.0,-248.0,32.0,16.0)}, 	// 4
    };
    struct ht::array_t<struct trace_manager::area_init_data_t> area_init_list = {
        ST4_2_TRACE_AREA_INIT_LIST_SIZE,
        area_init_data
    };

    #define ST4_2_TRACE_CNN_INIT_LIST_SIZE (4)
    struct trace_manager::connection_init_data_t connection_init_data[ST4_2_TRACE_CNN_INIT_LIST_SIZE] = {
        {0,2,bn::fixed_point(8.0,64),bn::fixed_point(8.0,96)}, 	//2
        {1,0,bn::fixed_point(8.0,-96),bn::fixed_point(8.0,-64)}, 	//5
        {3,0,bn::fixed_point(-248.0,0),bn::fixed_point(-232.0,0)}, 	//0
        {4,1,bn::fixed_point(8.0,-256),bn::fixed_point(8.0,-224)}, 	//7
    };
    struct array_t<struct trace_manager::connection_init_data_t> connection_init_list = {
        ST4_2_TRACE_CNN_INIT_LIST_SIZE,
        connection_init_data
    };

    #define ST4_2_AI_LIST_NUM (13)
    #define ST4_2_AI_001_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_001_list[ST4_2_AI_001_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_000},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_001},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_002_LIST_SIZE (4)
    struct ht::ai_scenario_t ai_002_list[ST4_2_AI_002_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_002},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_003},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_003_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_003_list[ST4_2_AI_003_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_004},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_005},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_006},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_007},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_004_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_004_list[ST4_2_AI_004_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_008},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_009},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_010},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_011},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_005_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_005_list[ST4_2_AI_005_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_012},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_013},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_014},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_015},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_006_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_006_list[ST4_2_AI_006_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_016},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_017},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_018},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_019},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_007_LIST_SIZE (8)
    struct ht::ai_scenario_t ai_007_list[ST4_2_AI_007_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_020},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_021},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_022},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_023},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_008_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_008_list[ST4_2_AI_008_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_024},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_009_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_009_list[ST4_2_AI_009_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_025},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_010_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_010_list[ST4_2_AI_010_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_026},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_011_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_011_list[ST4_2_AI_011_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_027},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_012_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_012_list[ST4_2_AI_012_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_028},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
    #define ST4_2_AI_013_LIST_SIZE (2)
    struct ht::ai_scenario_t ai_013_list[ST4_2_AI_013_LIST_SIZE] = {
        {ht::ai_action_type::MOVE_TO, (void*)&enemy_pos_029},
        {ht::ai_action_type::WAIT,    (void*)&wait_time},
    };
};

BN_DATA_EWRAM stage4_2_static_data stage4_2_data;

static bool get_stage4_2_enable(int type, int id) {
    switch (type) {
    case ((int)ht::object::type::HERO):
        return false;
        break;
    case ((int)ht::object::type::ENEMY):
        return true;
        break;
    case ((int)ht::object::type::ITEM):
        if (id == (int)ht::object::item_id::ITEM_KEY) return false;
        break;
    case ((int)ht::object::type::EVENT):
        if (id == (int)ht::object::event_id::GOAL) return false;
        if (id == (int)ht::object::event_id::STAIRS) return false;
        if (id == (int)ht::object::event_id::TELEPORT) return true;
        if (id == (int)ht::object::event_id::GATE) return false;
        break;
    default:
        break;
    }
    return false;
}

void stage4::_stage4_2_create_enemy() {
    for (int list_idx = 0; list_idx < ST4_2_AI_LIST_NUM; list_idx++) {
        bn::fixed_point current_pos(0,0);
        struct ht::ai_scenario_t* current_ai = NULL;
        int current_ai_size = 0;
        ht::enemy::enemy_id e_id = ht::enemy::enemy_id::SECURITY_GUARD;
        ht::enemy::grade grade = ht::enemy::grade::HARD;

        if (list_idx == 0) {
            current_pos = stage4_2_data.enemy_pos_000;
            current_ai = stage4_2_data.ai_001_list;
            current_ai_size = ST4_2_AI_001_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 1) {
            current_pos = stage4_2_data.enemy_pos_002;
            current_ai = stage4_2_data.ai_002_list;
            current_ai_size = ST4_2_AI_002_LIST_SIZE;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 2) {
            current_pos = stage4_2_data.enemy_pos_004;
            current_ai = stage4_2_data.ai_003_list;
            current_ai_size = ST4_2_AI_003_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 3) {
            current_pos = stage4_2_data.enemy_pos_008;
            current_ai = stage4_2_data.ai_004_list;
            current_ai_size = ST4_2_AI_004_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 4) {
            current_pos = stage4_2_data.enemy_pos_012;
            current_ai = stage4_2_data.ai_005_list;
            current_ai_size = ST4_2_AI_005_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 5) {
            current_pos = stage4_2_data.enemy_pos_016;
            current_ai = stage4_2_data.ai_006_list;
            current_ai_size = ST4_2_AI_006_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 6) {
            current_pos = stage4_2_data.enemy_pos_020;
            current_ai = stage4_2_data.ai_007_list;
            current_ai_size = ST4_2_AI_007_LIST_SIZE;
            e_id = ht::enemy::enemy_id::DOG;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 7) {
            current_pos = stage4_2_data.enemy_pos_024;
            current_ai = stage4_2_data.ai_008_list;
            current_ai_size = ST4_2_AI_008_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 8) {
            current_pos = stage4_2_data.enemy_pos_025;
            current_ai = stage4_2_data.ai_009_list;
            current_ai_size = ST4_2_AI_009_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 9) {
            current_pos = stage4_2_data.enemy_pos_026;
            current_ai = stage4_2_data.ai_010_list;
            current_ai_size = ST4_2_AI_010_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 10) {
            current_pos = stage4_2_data.enemy_pos_027;
            current_ai = stage4_2_data.ai_011_list;
            current_ai_size = ST4_2_AI_011_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 11) {
            current_pos = stage4_2_data.enemy_pos_028;
            current_ai = stage4_2_data.ai_012_list;
            current_ai_size = ST4_2_AI_012_LIST_SIZE;
            e_id = ht::enemy::enemy_id::CHASER;
            grade = ht::enemy::grade::INSANE;
        }
        if (list_idx == 12) {
            current_pos = stage4_2_data.enemy_pos_029;
            current_ai = stage4_2_data.ai_013_list;
            current_ai_size = ST4_2_AI_013_LIST_SIZE;
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

