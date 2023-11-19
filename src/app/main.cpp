#include "libapp/Functions.h"
#include <cstdlib>
#include <iostream>
#include <string>

enum CHOICE {
  ADD_NOTE = 1,
  SEE_ALL_NOTES = 2,
  REMOVE_ONE_NOTE = 3,
  REMOVE_ALL_NOTES = 4
};

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;

  while (true) {
    show_menu();
    cout << "Your choice:";
    int choice = 0;
    cin >> choice;
    if (choice == ADD_NOTE) {
      system("cls");

      string new_note;
      getline(cin, new_note); // npопуск переноса строки после cin
      cout << "Note to add: ";
      getline(cin, new_note);
      add_note(new_note);

      system("pause");
    } else if (choice == SEE_ALL_NOTES) {
      system("cls");
      see_all_notes();
      system("pause");
    }

    else if (choice == REMOVE_ONE_NOTE) {
      system("cls");
      // Получение заметок
      int count = 0;
      string *all_notes_arr = all_notes(count);
      // Вывод в консоль
      cout << "All_notes:" << endl;
      for (int i = 0; i < count; i++)
        cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;

      cout << "Number of note to remove: ";
      int choice = 0;
      cin >> choice;
      remove_one_note(all_notes_arr, count, choice);
      cout << "Your note was removed!" << endl;

      delete[] all_notes_arr;
      system("pause");
    }

    else if (choice == REMOVE_ALL_NOTES) {
      system("cls");
      remove_all_notes();
      cout << "All notes removed!" << endl;
      system("pause");
    }

    else
      break;
  }
  return 0;
}
