#include "main_menu.h"

MainMenu::MainMenu() {
    _fileMenu = new wxMenu;
    _fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");

    // TODO where to put the event handler for this?
    _gameMenu = new wxMenu;
    _gameMenu->Append(wxID_NEW, "New Game\tCtrl-N", "Start a new game");
    _gameMenu->AppendSeparator();
    _gameMenu->Append(wxID_UNDO, "Undo\tCtrl-Z", "Undo the last move");
    _gameMenu->Append(wxID_REDO, "Redo\tCtrl-Y", "Redo the last move");
    _gameMenu->AppendSeparator();
    _gameMenu->Append(wxID_SAVE, "Save\tCtrl-S", "Save the game");
    // gameMenu->Append(wxID_LOAD, "Load\tCtrl-L", "Load a game");

    _helpMenu = new wxMenu;
    _helpMenu->Append(wxID_ABOUT, "About...\tF1", "Show about dialog");

    Append(_fileMenu, wxT("&File"));
    Append(_gameMenu, wxT("&Game"));
    Append(_helpMenu, wxT("&Help"));
}