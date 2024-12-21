#pragma once
#include "Functions.h"

const int get_size_enum_Transport() { return static_cast<int>(Transports::End); } //���-�� ������ enum
const int get_size_enum_Races() { return static_cast<int>(Races::End); } //���-�� ������ enum

string print_transport(int* i) // ����� �� ����� ���� ���������� enum
{
	switch (*i)
	{
	case 0: return "��������� �����������";
	case static_cast<int>(Transports::All_terrain_boots): { All_terrain_boots a; return (a.get_Name()); }
	case static_cast<int>(Transports::Broom): { Broom a; return a.get_Name(); }
	case static_cast<int>(Transports::Camel): { Camel a; return a.get_Name(); }
	case static_cast<int>(Transports::Centaur): { Centaur a; return a.get_Name(); }
	case static_cast<int>(Transports::Eagle): { Eagle a; return a.get_Name(); }
	case static_cast<int>(Transports::Speedy_Camel): { Speedy_Camel a; return a.get_Name(); }
	case static_cast<int>(Transports::Magic_Carpet): { Magic_Carpet a; return a.get_Name(); }
	default: return "";
	}
};
string print_type_of_race(int* i) // ����� �� ����� ����� ���������� �����
{
	switch (*i)
	{
	case static_cast<int>(Races::Ground): return "����� ��� ��������� ����������"; break;
	case static_cast<int>(Races::Air): return "����� ��� ���������� ����������"; break;
	case static_cast<int>(Races::Ground_Air): return "����� ��� ��������� � ���������� ����������"; break;
	default: return "";
	}
};

bool chek_race_transport(Transport t, int type_of_race) {

	switch (type_of_race)
	{
	case static_cast<int>(Races::Ground):
	{
		Ground a;
		if (t.get_Type_Transport() == a.get_Type_Transport()) { return true; }
		break;
	}
	case static_cast<int>(Races::Air):
	{
		Air a;
		if (t.get_Type_Transport() == a.get_Type_Transport()) { return true; }
		break;
	}
	case static_cast<int>(Races::Ground_Air): { return true; break; }
	}
	return false;
}

bool registration(Racers* r, int* choice, int* distance, int type_of_race) // ����������� ���������� �� �����
{
	switch (*choice)
	{
		//case 0: return 0;
	case static_cast<int>(Transports::All_terrain_boots): { All_terrain_boots a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Broom): { Broom a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Camel): { Camel a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Centaur): { Centaur a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Eagle): { Eagle a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; }break; }
	case static_cast<int>(Transports::Speedy_Camel): { Speedy_Camel a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Magic_Carpet): { Magic_Carpet a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	default: return 0;
	}
	return 0;
};

bool chek_registration(Racers* r, int size, int choice) //������� �������� ��� ������������������ ��
{
	for (int i = 1; i <= size; i++)
	{
		if (r[i].get_Name() == print_transport(&choice)) { return false; }
	}
	return true;
}
