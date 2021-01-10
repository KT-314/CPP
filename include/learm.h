#ifndef LEARM_MENU_H
#define LEARM_MENU_H

#include "menu.h"

class learm : public menu {

public:
   ~learm();
   void debug()                  const;
   std::string to_string()       const;
   void select_menu()            const;
   void select_load()            const;
   bool confirm_retry()          const;
   bool retry_file()             const;
   void lines(int size)          const;
   void repeat(void(*fit)(void)) const;
};

#endif
