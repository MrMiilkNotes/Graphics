#pragma once
#include<vector>
#include<array>

// 存储点位置，缩放大小
typedef std::array<double, 3> point_posi_t, scalef_t;
// 存储一组点位置 用于存储模型的坐标信息
typedef std::vector<point_posi_t> positions_t;

// 存储一个面的位置索引
typedef std::vector<int> surface_t;
// 存储整个模型，由一组面组成
typedef std::vector<surface_t> surfaces_t;
