#pragma once

#include <wx/wx.h>

class MainMenu : public wxMenuBar {
   public:
    MainMenu();

   private:
    wxMenu* _fileMenu;
    wxMenu* _helpMenu;
    wxMenu* _gameMenu;
};