void HT_THIS_CLASS_NAME::_update_move_to(bn::fixed_point& new_pos, bool& vel_zero_flg) {
    bn::fixed_point* pos_ptr = (bn::fixed_point*)_ai_stat.param;
    ht::collision_manager::velocity vel(0.0f, 0.0f);

    bn::fixed diff_x(pos_ptr->x() - new_pos.x());
    bn::fixed diff_y(pos_ptr->y() - new_pos.y());

    if ((diff_x.right_shift_integer() == 0) &&
        (diff_y.right_shift_integer() == 0)) {
        vel_zero_flg = true;
        return;
    }

    bn::fixed vel_x = 0.0f;
    bn::fixed vel_y = 0.0f;
    bn::fixed vel_len_square = (diff_x * diff_x) + (diff_y * diff_y);
    if (vel_len_square.right_shift_integer() == 0) {
        vel_zero_flg = true;
        return;
    }

    bn::fixed_t<6> diff_vel_ratio_p6 = sqrt((_speed * _speed) / vel_len_square);
    bn::fixed diff_vel_ratio = diff_vel_ratio_p6;

    vel_x = diff_x * diff_vel_ratio;
    vel.set_vx(vel_x);

    vel_y = diff_y * diff_vel_ratio;
    vel.set_vy(vel_y);

    if ((vel_x.right_shift_integer() == 0) &&
        (vel_y.right_shift_integer() == 0)) {
        vel_zero_flg = true;
        return;
    }

    _rect_ptr->set_velocity(vel);
    _stat = ht::enemy_stat::RUN;

    ht::directions old_direction = _current_direction;
    if (abs<bn::fixed>(diff_x) > abs<bn::fixed>(diff_y)) {
        if (diff_x > 0) {
            _current_direction = ht::directions::RIGHT; 
        } else {
            _current_direction = ht::directions::LEFT; 
        }
    }
    else {
        if (diff_y > 0) {
            _current_direction = ht::directions::DOWN; 
        } else {
            _current_direction = ht::directions::UP; 
        }
    }

    if (old_direction != _current_direction) {
        _init_animation();
    }
}
