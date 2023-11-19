#pragma once
#include <string>

//showw_menu - ������� ���� � ������� 
void show_menu();

////add_note �������� ������� 
void add_note(const std::string& new_note);

// see_all_notes - �������� ��� �������
void see_all_notes();

//���������� ��������� �� ������ ���� ������� 
std::string* all_notes(int & n_count);

//������� ���� ������� ��� ������� choice
void remove_one_note(std::string* all_notes_arr, int count, int choice);

//������� ��� ������� 
void remove_all_notes();
