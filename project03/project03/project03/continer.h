#pragma once
#include<vector>
#include<array>

// �洢��λ�ã����Ŵ�С
typedef std::array<double, 3> point_posi_t, scalef_t;
// �洢һ���λ�� ���ڴ洢ģ�͵�������Ϣ
typedef std::vector<point_posi_t> positions_t;

// �洢һ�����λ������
typedef std::vector<int> surface_t;
// �洢����ģ�ͣ���һ�������
typedef std::vector<surface_t> surfaces_t;
