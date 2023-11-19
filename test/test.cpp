#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "ctest.h"
#include "libapp/Functions.h"

CTEST(todo_list, test_add_note) {
  const std::string new_note = "New note";

  add_note(new_note);

  std::ifstream file("notes.txt");
  std::string line;
  bool found = false;
  while (std::getline(file, line)) {
    if (line == new_note) {
      found = true;
      break;
    }
  }
  file.close();

  ASSERT_TRUE(found);
}

CTEST(TodoListTest, RemoveAllNotes) {
  remove_all_notes();
  std::ifstream file("notes.txt");

  bool is_empty = file.peek() == std::ifstream::traits_type::eof();
  file.close();

  ASSERT_TRUE(is_empty);
}

CTEST(todo_list, test_remove_one_note) {
  std::string *all_notes_array;
  int count;
  all_notes_array = all_notes(count);

  remove_one_note(all_notes_array, count, 2);

  std::ifstream file("notes.txt");
  std::string line;
  bool found = false;
  while (std::getline(file, line)) {
    if (line == "Note 2") {
      found = true;
      break;
    }
  }
  file.close();

  ASSERT_FALSE(found);

  delete[] all_notes_array;
}