#include <stdio.h>
#include <ncurses.h>
#include "gap_buffer.cpp"

using namespace std;

int main(int argc, char *argv[])
{

  //open file at argv[1]
  //put it in a gap GapBuffer for loop or something
  //
  //
  //
  // init ncurses screen
  //
  // while true
  //
  // for i in GapBuffer: print char on screen, if gap print cursor char
  //update ncurses screen
  // if backspace pressed: remove char from gap GapBuffer
  //
  //if up arrow or down arrow move past behind(for up)/next new line - distance of cursor from current newline
  //
  //
  // if C^-q pressed, save gap buffer to file, destruct gapbuffer quit
  //

  initscr();			/* Start curses mode 		  */

  FILE *file; // open the file to be edited
  file = fopen(argv[1], "r");

  GapBuffer main_buffer(file);

  bool quit = false;
  while (quit == false)
  {
    printw("");	/* Print Hello World		  */
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();
  }
  return 0;
}
