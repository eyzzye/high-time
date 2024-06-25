void HT_THIS_CLASS_NAME::_set_direction() {
    switch (_current_direction) {
    case ht::directions::DOWN:
        _set_tiles(0);
        break;
    case ht::directions::UP:
        _set_tiles(3);
        break;
    case ht::directions::RIGHT:
        _set_tiles(6);
        break;
    case ht::directions::LEFT:
        _set_tiles(9);
        break;
    default:
        BN_ERROR("Invalid _current_direction: ", (int)_current_direction);
        break;
    }
}

void HT_THIS_CLASS_NAME::_init_animation() {
    switch (_current_direction) {
    case ht::directions::DOWN:
        _anim.frame_data = anim_run_down_data;
        _anim.frame_data_size = sizeof(anim_run_down_data)/sizeof(anim_run_down_data[0]);
        break;
    case ht::directions::UP:
        _anim.frame_data = anim_run_up_data;
        _anim.frame_data_size = sizeof(anim_run_up_data)/sizeof(anim_run_up_data[0]);
        break;
    case ht::directions::RIGHT:
        _anim.frame_data = anim_run_right_data;
        _anim.frame_data_size = sizeof(anim_run_right_data)/sizeof(anim_run_right_data[0]);
        break;
    case ht::directions::LEFT:
        _anim.frame_data = anim_run_left_data;
        _anim.frame_data_size = sizeof(anim_run_left_data)/sizeof(anim_run_left_data[0]);
        break;
    default:
        BN_ERROR("Invalid _current_direction: ", (int)_current_direction);
        break;
    }

    _anim.list_index = 0;
    _anim.tile_index = _anim.frame_data[_anim.list_index].tile_index;
    _anim.wait_time = _anim.frame_data[_anim.list_index].wait_updates;
}

void HT_THIS_CLASS_NAME::_update_animation() {
    if (_anim.wait_time > 0) {
        _anim.wait_time -= 1;
    }
    else {
        _anim.list_index += 1;
        if (_anim.list_index >= _anim.frame_data_size) _anim.list_index = 0;

        _anim.tile_index = _anim.frame_data[_anim.list_index].tile_index;
        _set_tiles(_anim.tile_index);

        _anim.wait_time = _anim.frame_data[_anim.list_index].wait_updates;
    }
}
