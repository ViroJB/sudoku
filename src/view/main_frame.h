#pragma once

#include <wx/aboutdlg.h>
#include <wx/wx.h>

#include "menu/main_menu.h"
#include "draw_board/draw_board.h"

class DrawBoard;

class MainFrame : public wxFrame {
   public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    DrawBoard* getDrawBoard();
    void showAboutPopup(wxCommandEvent& event);
    void onNewGame(wxCommandEvent& event);
    void setGame(Game* game);
    Game* getGame();

   private:
    MainMenu* _mainMenu;
    DrawBoard* _drawBoard;
    Game* _game;
};