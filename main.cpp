#include <stdio.h>
#include <ncurses.h>
#include "LinkedStack.h"

using namespace std;

int main(int argc, char *argv[])
{

  //open file at argv[1]
  //put it in a LinkedList new node = newline for loop or something
  //
  //
  //
  // init ncurses screen
  //
  // while true
  //
  // for i in LinkedList: print char on screen, if gap print cursor char
  //update ncurses screen
  // if backspace pressed: remove char from gap GapBuffer
  //
  //if up arrow or down arrow move past behind(for up)/next new line - distance of cursor from current newline
  //
  //
  // if C^-q pressed, save gap buffer to file, destruct gapbuffer quit
  //

  enum mode {read, write, quit}; //start the program on read to read the file in if it is not blank
  mode mode = read;

  FILE *file; // open the file to be edited

  if (mode == read)
  {
    file = fopen(argv[1], "r");
  }

  LinkedStack<char> main_buffer = LinkedStack<char>();
  initscr();			/* Start curses mode 		  */

  while (mode == quit)
  {

    main_buffer.Push(getch());			/* Wait for user input */
    putc(main_buffer.Pop(), file);
    refresh();			/* Print it on to the real screen */

    if (getch() == '?')
    {
      endwin();
      fclose(file);
      mode = quit;
    }

  }


  return 0;
}
