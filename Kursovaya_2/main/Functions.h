#pragma once
#include <cstdlib>
#include"Racers.h"
#include"Transport.h"
#include"Ground.h"
#include"Air.h"
#include"Camel.h"
#include"Speedy_Camel.h"
#include"Centaur.h"
#include "All_terrain_boots.h"
#include"Magic_Carpet.h"
#include"Eagle.h"
#include"Broom.h"

using namespace std;

enum class Transports
{
	All_terrain_boots = 1, Broom, Camel, Centaur, Eagle, Speedy_Camel, Magic_Carpet, End
}; // ��������� �������� ��� ���-�� ������ � enum

const int get_size_enum_Transport(); //���-�� ������ enum

enum class Races
{
	Ground = 1, Air, Ground_Air, End
}; // ���� �����, ��������� ���� ��� ���������� ����� enum

const int get_size_enum_Races(); //���-�� ������ enum


string print_transport(int* i); // ����� �� ����� ���� ���������� enum
string print_type_of_race(int* i); // ����� �� ����� ����� ���������� �����
bool chek_race_transport(Transport t, int type_of_race);
bool registration(Racers* r, int* choice, int* distance, int type_of_race); // ����������� ���������� �� �����
bool chek_registration(Racers* r, int size, int choice); //������� �������� ��� ������������������ ��

