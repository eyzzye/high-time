import sys

obj_tiles_list = []
obj_map_data = []

def tmx2obj_map_data(filename):
    found_object_layer_flg = False
    y_idx = 0
    with open(filename) as file:
        for line in file:
            if found_object_layer_flg == False:
                if "name=\"object_layer\"" in line:
                    found_object_layer_flg = True
                    print("found object_layer")
            else:
                if "<data" in line:
                    pass
                elif "</data>" in line:
                    break
                else:
                    line_no_newline = line.rstrip()
                    data_list = line_no_newline.split(",")
                    if len(data_list) < 32:
                        print("y={} invalid width!".format(y_idx))
                        break;
                    else:
                        obj_map_data.append(data_list)
                        y_idx += 1
 
# val=256
def tmx2hero_pos():
    result = [] # position = [x1,y1]
    x_idx = 0
    y_idx = 0
    
    found_hero_pos_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == "256":
                result = [x_idx,y_idx]
                found_hero_pos_flg = True
                break
            
            x_idx += 1
        if found_hero_pos_flg:
            break
        
        y_idx += 1
    
    #print result
    if found_hero_pos_flg:
        ret_x = (result[0] - 32/2) * 16 + 16/2
        ret_y = (result[1] - 32/2) * 16 + 16/2
        print("hero_pos: found.")
        print("        bn::fixed_point pos({},{});".format(ret_x,ret_y))
        
        #obj_tiles_list.append([result[0],result[1],"HERO"])
    else:
        print("hero_pos: not found.")

# val=255
def tmx2goal_region():
    result = [] # region = [[x1,y1,x2,y2]]
    x_idx = 0
    y_idx = 0
    
    found_goal_region_flg = False
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == "255":
                top_left = [x_idx, y_idx]
                
                # search connected x_area
                area_width = 1 
                for search_x in range((x_idx + 1), 32):
                    if ((search_x < 32) and (obj_map_data[y_idx][search_x] == "255")):
                        #continue
                        area_width += 1
                    else:
                        break
                
                # search connected y_area
                not_connected = False
                area_height = 1
                for search_y in range((y_idx + 1), 32):
                    if (search_y < 32):
                        # search connected x_area
                        for search_x in range(x_idx, (x_idx + area_width)):
                            if (obj_map_data[search_y][search_x] == "255"):
                                #continue
                                pass
                            else:
                                # not connected area
                                not_connected = True
                                break
                        if not_connected == False:
                            area_height += 1    
                    else:
                        break
                    
                    if not_connected:
                        break
                if area_width > 0:
                    bottom_right = [x_idx+area_width-1, y_idx+area_height-1]
                    result.append([top_left[0],top_left[1],bottom_right[0],bottom_right[1]])
                    found_goal_region_flg = True
                    break
            
            x_idx += 1
        
        if found_goal_region_flg:
            break
        y_idx += 1
    
    # finish
    if len(result) > 0:
        print("goal_region: found.")
        for r_data in result:
            ret_width  = (r_data[2] - r_data[0] + 1) * 16.0
            ret_height = (r_data[3] - r_data[1] + 1) * 16.0
            ret_x = (r_data[0] - 32/2) * 16 + (ret_width  / 2.0)
            ret_y = (r_data[1] - 32/2) * 16 + (ret_height / 2.0)
            print("        bn::fixed_rect rect({},{},{},{});".format(ret_x,ret_y,ret_width,ret_height))
            
            #for y_idx in range(r_data[1], r_data[3]+1):
            #    for x_idx in range(r_data[0], r_data[2]+1):
            #        obj_tiles_list.append([x_idx,y_idx,"GOAL"])
    else:
        print("goal_region: not found.")

# up stairs   : val = 253 
# down stairs : val = 252
def tmx2stairs_pos():
    result_up = []   # position = [[x1,y1],[x2,y2], ...]
    result_down = [] # position = [[x1,y1],[x2,y2], ...]
    x_idx = 0
    y_idx = 0
    
    found_up_flg = False
    found_down_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == "253":
                result_up.append([x_idx,y_idx])
                found_up_flg = True
            elif cell == "252":
                result_down.append([x_idx,y_idx])
                found_down_flg = True
            
            x_idx += 1
        y_idx += 1
    
    #print result
    if found_up_flg:
        print("up stairs: found.")
        for up_pos in result_up:
            ret_x = (up_pos[0] - 32/2) * 16 + 16/2
            ret_y = (up_pos[1] - 32/2) * 16 + 16/2
            print("        {{bn::fixed_point({},{}),FLOOR,bn::fixed_point({},{})}},".format(ret_x,ret_y,ret_x+16,ret_y))
            obj_tiles_list.append([up_pos[0],up_pos[1],"UP_STAIRS"])
    else:
        print("up stairs: not found.")

    if found_down_flg:
        print("down stairs: found.")
        for down_pos in result_down:
            ret_x = (down_pos[0] - 32/2) * 16 + 16/2
            ret_y = (down_pos[1] - 32/2) * 16 + 16/2
            print("        {{bn::fixed_point({},{}),FLOOR,bn::fixed_point({},{})}},".format(ret_x,ret_y,ret_x-16,ret_y))
            obj_tiles_list.append([down_pos[0],down_pos[1],"DOWN_STAIRS"])
    else:
        print("down stairs: not found.")

#
# teleport : val = 254
#
def tmx2teleport():
    result = [] # TopLeft,BottomRight = [[x1,y1,x2,y2], [x1,y1,x2,y2], ....]
    
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == "254":
                # already set
                skip_flg = False
                for rect_data in result:
                    if (rect_data[0] <= x_idx) and (x_idx <= rect_data[2]):
                        if ((rect_data[1] <= y_idx) and (y_idx <= rect_data[3])):
                            #skip
                            skip_flg = True
                            break
                if skip_flg:
                    # do nothing
                    pass
                else:
                    top_left = [x_idx, y_idx]
                    
                    # search connected x_area
                    area_width = 1 
                    for search_x in range((x_idx + 1), 32):
                        if ((search_x < 32) and (obj_map_data[y_idx][search_x] == "254")):
                            #continue
                            area_width += 1
                        else:
                            break
                    
                    # search connected y_area
                    not_connected = False
                    area_height = 1
                    for search_y in range((y_idx + 1), 32):
                        if (not_connected == False) and (search_y < 32):
                            # search connected x_area
                            for search_x in range(x_idx, (x_idx + area_width)):
                                if (obj_map_data[search_y][search_x] == "254"):
                                    #continue
                                    pass
                                else:
                                    # not connected area
                                    not_connected = True
                                    break
                            if not_connected == False:
                                area_height += 1    
                        else:
                            break
                    
                    if area_width > 0:
                        bottom_right = [x_idx+area_width-1, y_idx+area_height-1]
                        result.append([top_left[0],top_left[1],bottom_right[0],bottom_right[1]])
            x_idx += 1
        y_idx += 1
    
    # finish
    if len(result) > 0:
        print("teleport: found.")
        for r_data in result:
            ret_width  = (r_data[2] - r_data[0] + 1) * 16.0
            ret_height = (r_data[3] - r_data[1] + 1) * 16.0
            ret_x = (r_data[0] - 32/2) * 16 + (ret_width  / 2.0)
            ret_y = (r_data[1] - 32/2) * 16 + (ret_height / 2.0)
            print("        {{bn::fixed_rect({},{},{},{}),FLOOR,bn::fixed_point(X,Y)}},".format(ret_x,ret_y,ret_width,ret_height))
            
            #for y_idx in range(r_data[1], r_data[3]+1):
            #    for x_idx in range(r_data[0], r_data[2]+1) :
            #        obj_tiles_list.append([x_idx,y_idx,"TELEPORT"])
    else:
        print("teleport: not found.")

def tmx2gate_left_right_pos(tile1,tile2,left_right):
    result = []   # position = [[x1,y1],[x2,y2], ...]
    x_idx = 0
    y_idx = 0
    
    found_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == tile1:
                if obj_map_data[y_idx+1][x_idx] == tile2:
                    result.append([x_idx,y_idx])
                    found_flg = True
            x_idx += 1
        y_idx += 1
    
    if found_flg:
        if left_right == "left":
            print("left gate: found.")
        else:
            print("right gate: found.")
        
        for pos in result:
            ret_x = (pos[0] - 32/2) * 16 + 16/2
            ret_y = (pos[1] - 32/2) * 16 + 32/2
            width = 16
            height = 32
            if left_right == "left":
                print("        {{bn::fixed_rect({},{},{},{}),ht::directions::LEFT}},".format(ret_x,ret_y,width,height))
                obj_tiles_list.append([pos[0],pos[1],"LEFT_GATE"])
            else:
                print("        {{bn::fixed_rect({},{},{},{}),ht::directions::RIGHT}},".format(ret_x,ret_y,width,height))
                obj_tiles_list.append([pos[0],pos[1],"RIGHT_GATE"])
    else:
        if left_right == "left":
            print("left gate: not found.")
        else:
            print("right gate: not found.")

def tmx2gate_up_down_pos(tile1,tile2,up_down):
    result = []   # position = [[x1,y1],[x2,y2], ...]
    x_idx = 0
    y_idx = 0
    
    found_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == tile1:
                if obj_map_data[y_idx][x_idx + 1] == tile2:
                    result.append([x_idx,y_idx])
                    found_flg = True
            x_idx += 1
        y_idx += 1
    
    if found_flg:
        if up_down == "up":
            print("up gate: found.")
        else:
            print("down gate: found.")
        
        for pos in result:
            ret_x = (pos[0] - 32/2) * 16 + 32/2
            ret_y = (pos[1] - 32/2) * 16 + 16/2
            width = 32
            height = 16
            if up_down == "up":
                print("        {{bn::fixed_rect({},{},{},{}),ht::directions::UP}},".format(ret_x,ret_y,width,height))
                obj_tiles_list.append([pos[0],pos[1],"UP_GATE"])
            else:
                print("        {{bn::fixed_rect({},{},{},{}),ht::directions::DOWN}},".format(ret_x,ret_y,width,height))
                obj_tiles_list.append([pos[0],pos[1],"DOWN_GATE"])
    else:
        if up_down == "up":
            print("up gate: not found.")
        else:
            print("down gate: not found.")

# left  : val = 225, 241
# right : val = 227, 243
# up    : val = 229, 230
# down  : val = 231, 232
def tmx2gate_pos():
    tmx2gate_left_right_pos("225","241","left")
    tmx2gate_left_right_pos("227","243","right")
    tmx2gate_up_down_pos("229","230","up")
    tmx2gate_up_down_pos("231","232","down")

# key   : val = 177
def tmx2item_pos():
    result_key = []   # position = [[x1,y1],[x2,y2], ...]
    x_idx = 0
    y_idx = 0

    found_key_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell == "177":
                result_key.append([x_idx,y_idx])
                found_key_flg = True
            
            x_idx += 1
        y_idx += 1
    
    #print result
    if found_key_flg:
        print("item key: found.")
        for key_pos in result_key:
            ret_x = (key_pos[0] - 32/2) * 16 + 16/2
            ret_y = (key_pos[1] - 32/2) * 16 + 16/2
            print("        {{bn::fixed_rect({},{},16,16)}},".format(ret_x,ret_y))
            
            #obj_tiles_list.append([key_pos[0],key_pos[1],"ITEM_KEY"])
    else:
        print("item key: not found.")

# enemy : val = 193 ... 224
def tmx2enemy_pos():
    result = []   # enemy_id,position = [[enemy_id,x1,y1],[enemy_id,x2,y2], ...]
    x_idx = 0
    y_idx = 0

    found_flg = False
    y_idx = 0
    for line in obj_map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            else:
                enemy_id = int(cell)
                if (enemy_id >= 193) and (enemy_id <= 224):
                    result.append([enemy_id,x_idx,y_idx])
                    found_flg = True
            
            x_idx += 1
        y_idx += 1
    
    #print result
    if found_flg:
        print("enemy: found. num={}".format(len(result)))
        
        enemy_data_cnt = 0
        for enemy_data in sorted(result):
            enemy_id = enemy_data[0] - 193
            ret_x = (enemy_data[1] - 32/2) * 16 + 16/2
            ret_y = (enemy_data[2] - 32/2) * 16
            print("    bn::fixed_point enemy_pos_{:03d} = {{ {},{} }};\t\t// {}".format(enemy_data_cnt,ret_x,ret_y,enemy_id))
            enemy_data_cnt += 1
    else:
        print("enemy: not found.")
    pass

def tmx2terrain(filename):
    result = [] # TopLeft,BottomRight = [[x1,y1,x2,y2], [x1,y1,x2,y2], ....]
    found_front_layer_flg = False
    map_data = []
    x_idx = 0
    y_idx = 0
    
    with open(filename) as file:
        for line in file:
            if found_front_layer_flg == False:
                if "name=\"front_layer\"" in line:
                    found_front_layer_flg = True
                    print("found front_layer")
            else:
                if "<data" in line:
                    pass
                elif "</data>" in line:
                    break
                else:
                    line_no_newline = line.rstrip()
                    data_list = line_no_newline.split(",")
                    if len(data_list) < 32:
                        print("y={} invalid width!".format(y_idx))
                        break;
                    else:
                        map_data.append(data_list)
                        y_idx += 1

    y_idx = 0
    for line in map_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            elif cell != "0":
                # already set
                skip_flg = False
                for rect_data in result:
                    if (rect_data[0] <= x_idx) and (x_idx <= rect_data[2]):
                        if ((rect_data[1] <= y_idx) and (y_idx <= rect_data[3])):
                            #skip
                            skip_flg = True
                            break
                if skip_flg:
                    # do nothing
                    pass
                else:
                    top_left = [x_idx, y_idx]
                    
                    # search connected x_area
                    area_width = 1 
                    for search_x in range((x_idx + 1), 32):
                        if ((search_x < 32) and (map_data[y_idx][search_x] != "0")):
                            #continue
                            area_width += 1
                        else:
                            break
                    
                    # search connected y_area
                    not_connected = False
                    area_height = 1
                    for search_y in range((y_idx + 1), 32):
                        if (not_connected == False) and (search_y < 32):
                            # search connected x_area
                            for search_x in range(x_idx, (x_idx + area_width)):
                                if (map_data[search_y][search_x] != "0"):
                                    #continue
                                    pass
                                else:
                                    # not connected area
                                    not_connected = True
                                    break
                            if not_connected == False:
                                area_height += 1    
                        else:
                            break
                    
                    if area_width > 0:
                        bottom_right = [x_idx+area_width-1, y_idx+area_height-1]
                        result.append([top_left[0],top_left[1],bottom_right[0],bottom_right[1]])
            x_idx += 1
        y_idx += 1
    
    # finish
    if len(result) > 0:
        print("terrain: found. num={}".format(len(result)))
        for r_data in result:
            ret_width  = (r_data[2] - r_data[0] + 1) * 16.0
            ret_height = (r_data[3] - r_data[1] + 1) * 16.0
            ret_x = (r_data[0] - 32/2) * 16 + (ret_width  / 2.0)
            ret_y = (r_data[1] - 32/2) * 16 + (ret_height / 2.0)
            print("        {{bn::fixed_rect({},{},{},{})}},".format(ret_x,ret_y,ret_width,ret_height))
    else:
        print("terrain: not found.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("USAGE: python tmx2init_data.py FILENAME")
    else:
        #print(sys.argv[1])
        tmx2obj_map_data(sys.argv[1])
        if len(obj_map_data) > 0:
            tmx2hero_pos()
            tmx2goal_region()
            tmx2stairs_pos()
            tmx2teleport()
            tmx2gate_pos()
            tmx2item_pos()
            tmx2enemy_pos()
        if len(obj_tiles_list) > 0:
            print("object tile indexes. -> bg_map_init_data")
            obj_tiles_count = 0
            for obj_tile_info in obj_tiles_list:
                if ("UP_GATE" == obj_tile_info[2]) or ("DOWN_GATE" == obj_tile_info[2]):
                    print("        {{ {},{},{}_CLOSE_TILE1 }},".format(obj_tile_info[0]       * 2    , obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE2 }},".format(obj_tile_info[0]       * 2 + 1, obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE3 }},".format((obj_tile_info[0] + 1) * 2    , obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE4 }},".format((obj_tile_info[0] + 1) * 2 + 1, obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE5 }},".format(obj_tile_info[0]       * 2    , obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE6 }},".format(obj_tile_info[0]       * 2 + 1, obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE7 }},".format((obj_tile_info[0] + 1) * 2    , obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE8 }},".format((obj_tile_info[0] + 1) * 2 + 1, obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    obj_tiles_count += 8
                elif ("LEFT_GATE" == obj_tile_info[2]) or ("RIGHT_GATE" == obj_tile_info[2]):
                    print("        {{ {},{},{}_CLOSE_TILE1 }},".format(obj_tile_info[0] * 2    , obj_tile_info[1]       * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE2 }},".format(obj_tile_info[0] * 2 + 1, obj_tile_info[1]       * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE3 }},".format(obj_tile_info[0] * 2    , obj_tile_info[1]       * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE4 }},".format(obj_tile_info[0] * 2 + 1, obj_tile_info[1]       * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE5 }},".format(obj_tile_info[0] * 2    , (obj_tile_info[1] + 1) * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE6 }},".format(obj_tile_info[0] * 2 + 1, (obj_tile_info[1] + 1) * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE7 }},".format(obj_tile_info[0] * 2    , (obj_tile_info[1] + 1) * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_CLOSE_TILE8 }},".format(obj_tile_info[0] * 2 + 1, (obj_tile_info[1] + 1) * 2 +1, obj_tile_info[2]))
                    obj_tiles_count += 8
                else:
                    print("        {{ {},{},{}_TILE1 }},".format(obj_tile_info[0] * 2    , obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_TILE2 }},".format(obj_tile_info[0] * 2 + 1, obj_tile_info[1] * 2   , obj_tile_info[2]))
                    print("        {{ {},{},{}_TILE3 }},".format(obj_tile_info[0] * 2    , obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    print("        {{ {},{},{}_TILE4 }},".format(obj_tile_info[0] * 2 + 1, obj_tile_info[1] * 2 +1, obj_tile_info[2]))
                    obj_tiles_count += 4
            print("obj_tiles num={}".format(obj_tiles_count))
        
        tmx2terrain(sys.argv[1])

