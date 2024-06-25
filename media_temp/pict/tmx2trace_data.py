import sys

g_area_data = []
g_connection_data = []

def tmx2area_data(filename):
    found_area_layer_flg = False
    y_idx = 0
    with open(filename) as file:
        for line in file:
            if found_area_layer_flg == False:
                if "name=\"area_layer\"" in line:
                    found_area_layer_flg = True
                    print("found area_layer")
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
                        g_area_data.append(data_list)
                        y_idx += 1

def tmx2connection_data(filename):
    found_area_layer_flg = False
    y_idx = 0
    with open(filename) as file:
        for line in file:
            if found_area_layer_flg == False:
                if "name=\"connect_layer\"" in line:
                    found_area_layer_flg = True
                    print("found connect_layer")
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
                        g_connection_data.append(data_list)
                        y_idx += 1

# tile A0-A31: val=257...288
def extract_area():
    result = [] # area_id,TopLeft,BottomRight =
                #  [[area_id,x1,y1,x2,y2], [area_id,x1,y1,x2,y2], ....]
    
    y_idx = 0
    for line in g_area_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            else:
                area_id = int(cell)
                if (area_id >= 257) and (area_id <= 288):
                    # already set
                    skip_flg = False
                    for rect_data in result:
                        if (rect_data[1] <= x_idx) and (x_idx <= rect_data[3]):
                            if ((rect_data[2] <= y_idx) and (y_idx <= rect_data[4])):
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
                            if ((search_x < 32) and (int(g_area_data[y_idx][search_x]) == area_id)):
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
                                    if (int(g_area_data[search_y][search_x]) == area_id):
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
                            result.append([area_id,top_left[0],top_left[1],bottom_right[0],bottom_right[1]])
            x_idx += 1
        y_idx += 1
    
    # finish
    if len(result) > 0:
        print("area: found. num={}".format(len(result)))
        for r_data in sorted(result):
            ret_width  = (r_data[3] - r_data[1] + 1) * 16.0
            ret_height = (r_data[4] - r_data[2] + 1) * 16.0
            ret_x = (r_data[1] - 32/2) * 16 + (ret_width  / 2.0)
            ret_y = (r_data[2] - 32/2) * 16 + (ret_height / 2.0)
            print("        {{bn::fixed_rect({},{},{},{})}}, \t// {}".format( \
                  ret_x,ret_y,ret_width,ret_height,r_data[0]-257))
    else:
        print("area: not found.")


# tile P0-P63: val=321...384
def extract_connection():
    result = [] # area_a,area_b,connecter_a,connecter_b =
                #  [[area_a,area_b,x1,y1,x2,y2], [area_a,area_b,x1,y1,x2,y2], ....]
    
    y_idx = 0
    for line in g_connection_data:
        x_idx = 0
        for cell in line:
            if len(cell) <= 0:
                pass
            else:
                connect_id = int(cell)
                if (connect_id >= 321) and (connect_id <= 384):
                    pair_found_flg = False
                    connect_a = [x_idx, y_idx]
                    area_a = int(g_area_data[y_idx][x_idx])
                    
                    # search down
                    if ((y_idx+1) <= 31) and (g_connection_data[y_idx+1][x_idx] != "0"):
                        area_b = int(g_area_data[y_idx+1][x_idx])
                        if (area_a != area_b):
                            connect_b = [x_idx,y_idx+1]
                            pair_found_flg = True
                            ret_x1 = (connect_a[0] - 32/2) * 16 + (16 / 2.0)
                            ret_y1 = (connect_a[1] - 32/2) * 16 
                            ret_x2 = (connect_b[0] - 32/2) * 16 + (16 / 2.0)
                            ret_y2 = (connect_b[1] - 32/2) * 16 + 16
                            result.append([area_a,area_b, connect_a[0],connect_a[1],connect_b[0],connect_b[1], \
                                          ret_x1,ret_y1,ret_x2,ret_y2, connect_id])
                    # search right
                    if ((x_idx+1) <= 31) and (g_connection_data[y_idx][x_idx+1] != "0"):
                        area_b = int(g_area_data[y_idx][x_idx+1])
                        if (area_a != area_b):
                            connect_b = [x_idx+1,y_idx]
                            pair_found_flg = True
                            ret_x1 = (connect_a[0] - 32/2) * 16 + (16 / 2.0)
                            ret_y1 = (connect_a[1] - 32/2) * 16 + (16) 
                            ret_x2 = (connect_b[0] - 32/2) * 16 + (16 / 2.0)
                            ret_y2 = (connect_b[1] - 32/2) * 16 + (16)
                            result.append([area_a,area_b, connect_a[0],connect_a[1],connect_b[0],connect_b[1], \
                                          ret_x1,ret_y1,ret_x2,ret_y2, connect_id])
            x_idx += 1
        y_idx += 1
    
    # finish
    if len(result) > 0:
        print("connection: found. num={}".format(len(result)))
        for r_data in sorted(result):
            print("        {{{},{},bn::fixed_point({},{}),bn::fixed_point({},{})}}, \t//{}".format( \
                  r_data[0]-257,r_data[1]-257,r_data[6],r_data[7],r_data[8],r_data[9],r_data[10]-321))
    else:
        print("connection: not found.")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("USAGE: python tmx2trace_data.py FILENAME")
    else:
        #print(sys.argv[1])
        tmx2area_data(sys.argv[1])
        tmx2connection_data(sys.argv[1])
        if (len(g_area_data) > 0) and (len(g_connection_data) > 0):
            extract_area()
            extract_connection()

