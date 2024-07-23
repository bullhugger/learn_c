
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#define FIELD_WIDTH   (10)
#define FIELD_HEIGHT  (20)

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else 
    system("clear");
#endif
}

void DrawScreen() {
  for(int y = 0; y < FIELD_HEIGHT; y++) {
    printf("□");
    for(int x = 0; x < FIELD_WIDTH; x++) {
      printf(" ");
    }
    printf("□");
    printf("\n");
  }
  for(int x = 0; x < FIELD_WIDTH + 2; x++) {
    printf("□");
  }
}

char GetChar() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Set new attributes
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old attributes
    return ch;
#endif
}

int main() {
    ClearScreen();
    DrawScreen();
    printf("Press any key to continue...\n");
    GetChar();
    return 0;
}
