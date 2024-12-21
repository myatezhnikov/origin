#pragma once
#include <cstdlib>
#include"..\lib_racers\Racers.h"
#include"..\lib1\Transport.h"
#include"..\lib1.1\Air.h"
#include"..\lib1.1.1\Broom.h"
#include"..\lib1.1.2\Eagle.h"
#include"..\lib1.1.3\Magic_Carpet.h"
#include"..\lib1.2\Ground.h"
#include"..\lib1.2.1\All_terrain_boots.h"
#include"..\lib1.2.2\Camel.h"
#include"..\lib1.2.3\Centaur.h"
#include"..\lib1.2.4\Speedy_Camel.h"

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

