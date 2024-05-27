#pragma once

#include <wx/wx.h>

#include "main_frame.h"

class InputNumberPopup : public wxFrame {
   public:
    InputNumberPopup(wxWindow* parent, int x, int y, int posX, int posY);
    void onOk(wxCommandEvent& event);
    void onCancel(wxCommandEvent& event);
    int getNumber() const;

   private:
    int _number;
    int _x;
    int _y;
    int const ID_INPUT = 0; 
};