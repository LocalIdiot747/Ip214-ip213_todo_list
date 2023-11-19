#pragma once
#include <string>

//showw_menu - выводит меню в консоль 
void show_menu();

////add_note добавить заметку 
void add_note(const std::string& new_note);

// see_all_notes - показать все заметки
void see_all_notes();

//возвращает указатель на массив всех заметок 
std::string* all_notes(int & n_count);

//Удаляет одну заметку под номером choice
void remove_one_note(std::string* all_notes_arr, int count, int choice);

//удаляет все заметки 
void remove_all_notes();
