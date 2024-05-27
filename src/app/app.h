#pragma once

#include <wx/wx.h>

#include "../config/config.h"
#include "../view/main_frame.h"
#include "../view/menu/main_menu.h"
#include "../game/game.h"
#include "../game/generator/generator.h"

class App : public wxApp {
   public:
    bool OnInit();

   private:
    MainFrame *_mainFrame;
    MainMenu *_mainMenu;
    Game *_game;
};