#include<iostream>
#include<fstream>
#include<string>

#include"continer.h"

extern positions_t vertices;
extern surfaces_t surfaces;

void load_off(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::string off;
	std::getline(fin, off);//读入首行字符串"OFF"
	int nFaces, nVertices, nEdges;
	fin >> nVertices >> nFaces >> nEdges; //读入点、面、边数目
	point_posi_t posi;
	for (int i = 0; i < nVertices; i++)
	{
		fin >> posi[0] >> posi[1] >> posi[2];    //逐行读入顶点坐标;
		vertices.push_back(posi);
	}
	int n, vid1, vid2, vid3;
	for (int i = 0; i < nFaces; i++)
	{
		fin >> n >> vid1 >> vid2 >> vid3;  //逐行读入面的顶点序列;
		surfaces.push_back({ vid1, vid2, vid3 });
	}
	fin.close();
}
