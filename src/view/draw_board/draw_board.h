#pragma once

#include <wx/wx.h>

#include "../../game/game.h"
#include "../input_number_popup.h"

class InputNumberPopup;

class DrawBoard : public wxPanel {
   public:
    DrawBoard(wxFrame* parent);

    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void render(wxDC& dc);
    void drawGrid(wxDC& dc);
    void setGame(Game *game); 
    void onSize(wxSizeEvent& event);
    void onBoardClick(wxMouseEvent& event);
    void setInputNumberPopupOpen(bool isOpen);

    
    wxPoint getCenterOfNode(int x, int y);

   private:
    Game *_game;
    InputNumberPopup* _inputNumberPopup = nullptr;
    bool _isInputNumberPopupOpen = false;
};