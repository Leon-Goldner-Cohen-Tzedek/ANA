#include <unistd.h>
#include <vector>
#include <ncurses.h>
#include <stdio.h>
#include "LinkedStack.h"

using namespace std;
int file_load(char *file);
void refresh_from_buffers();
void get_event();

int main(int argc, char *argv[])
{
  vector<char> edit_buffer;

  initscr();
  keypad(stdscr, TRUE);
  raw();
  int fd = file_load(argv[1]);

  bool quit = false;
  while (quit == true)
  {
    if (KEY_F(1))
    {
      quit = true;
    }
    else
    {

    }
    refresh();	/* Print it on to the real screen */
  }
  endwin();
  close(fd);
  return 0;
}

int file_load(char *file)
{
  vector<char> main_buffer;
  char fd = open(file, O_RDWR | O_CREAT);
  // checking for errors
  if (fd == -1)
  {
    cout << "There was an error while trying to open or create " << file << endl;
  }

  while (ssize_t read(fd, main_buffer, 1) != EOF)
    {
      read(fd, main_buffer, 1);
    }

  return fd;
}

void refresh_from_buffers()
{
  //for char in edit:
  // putc that char
}
