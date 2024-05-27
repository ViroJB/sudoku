#include "main_frame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    _mainMenu = new MainMenu();
    SetMenuBar(_mainMenu);

    _drawBoard = new DrawBoard(this);

    Bind(wxEVT_MENU, &MainFrame::showAboutPopup, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::onNewGame, this, wxID_NEW);
}

void MainFrame::setGame(Game* game) {
    _game = game;
    _drawBoard->setGame(game);
}

Game* MainFrame::getGame() { return _game; }

void MainFrame::onNewGame(wxCommandEvent& event) { 
}

DrawBoard* MainFrame::getDrawBoard() { return _drawBoard; }

void MainFrame::showAboutPopup(wxCommandEvent& event) {
    wxAboutDialogInfo info;
    info.SetName("Sudoku");
    info.SetVersion("0.6.0");
    info.SetDescription("Craziest Sudoku game ever!\nBelieve it! or not...");
    info.SetCopyright("(C) 2024 Viro");
    wxAboutBox(info);
}
