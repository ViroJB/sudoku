#include "app.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    _mainFrame = new MainFrame("Sudoku", wxPoint(300, 300), wxSize(Config::DEFAULT_WIN_SIZE_X, Config::DEFAULT_WIN_SIZE_Y));
    _mainFrame->Show(true); 
    _mainFrame->SetWindowStyle(_mainFrame->GetWindowStyle() | wxFULL_REPAINT_ON_RESIZE);
    _game = new Game();
    _mainFrame->setGame(_game);

    return true;
}