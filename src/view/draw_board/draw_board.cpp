#include "draw_board.h"

DrawBoard::DrawBoard(wxFrame* parent) : wxPanel(parent) {
    Bind(wxEVT_PAINT, &DrawBoard::paintEvent, this);
    Bind(wxEVT_SIZE, &DrawBoard::onSize, this);
    Bind(wxEVT_LEFT_DOWN, &DrawBoard::onBoardClick, this);
}

void DrawBoard::setInputNumberPopupOpen(bool isOpen) { _isInputNumberPopupOpen = isOpen; }

void DrawBoard::onBoardClick(wxMouseEvent& event) {
    // FIXME somewhere here is a bug, crashes when clicking on the board, send an input and then click again
    //       some segmentation fault, trying to close the popup but there isnt any, i think...
    wxSize const size = this->GetSize();
    int boardSize = _game->getBoardSize();

    int fieldSizeWidth = size.GetWidth() / boardSize;
    int fieldSizeHeight = size.GetHeight() / boardSize;

    int x = event.GetX() / fieldSizeWidth;
    int y = event.GetY() / fieldSizeHeight;

    if (_isInputNumberPopupOpen) {
        _inputNumberPopup->Close();
        _inputNumberPopup = nullptr;
        _isInputNumberPopupOpen = false;
    }

    wxPoint parentWindowPosition = GetParent()->GetPosition();
    parentWindowPosition.x += event.GetX();
    parentWindowPosition.y += event.GetY();
    _inputNumberPopup = new InputNumberPopup(GetParent(), x, y, parentWindowPosition.x, parentWindowPosition.y);
    _inputNumberPopup->Show(true);
    _isInputNumberPopupOpen = true;
}

// trigger repaint on windows size change
void DrawBoard::onSize(wxSizeEvent& event) {
    Refresh();
    event.Skip();
}

void DrawBoard::paintEvent(wxPaintEvent& evt) {
    wxPaintDC dc(this);
    render(dc);
}

void DrawBoard::paintNow() {
    wxClientDC dc(this);
    render(dc);
}

void DrawBoard::render(wxDC& dc) {
    dc.SetBackground(*wxGREY_BRUSH);
    dc.Clear();

    drawGrid(dc);
}

void DrawBoard::setGame(Game* game) { _game = game; }

wxPoint DrawBoard::getCenterOfNode(int x, int y) {
    wxSize const size = this->GetSize();
    int boardSize = _game->getBoardSize();

    int fieldSizeWidth = size.GetWidth() / boardSize;
    int fieldSizeHeight = size.GetHeight() / boardSize;

    return wxPoint(x * fieldSizeWidth + fieldSizeWidth / 2, y * fieldSizeHeight + fieldSizeHeight / 2);
}

void DrawBoard::drawGrid(wxDC& dc) {
    int boardSize = _game->getBoardSize();
    wxSize const size = this->GetSize();

    int fieldSizeWidth = size.GetWidth() / boardSize;
    int fieldSizeHeight = size.GetHeight() / boardSize;

    // draw board content
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            if (_game->getBoard()->at(x).at(y) != 0) {
                wxPoint center = getCenterOfNode(x, y);
                int fontSize = size.GetHeight() / boardSize / 3;
                center.x -= fontSize / 2;  // remove half of the font size to center the text
                center.y -= fontSize / 2;
                dc.SetFont(wxFont(fontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
                dc.DrawText(std::to_string(_game->getBoard()->at(x).at(y)), center);
            }
        }
    }

    // draw grid
    for (int i = 0; i < boardSize; i++) {
        if (i % 3 == 0) {
            dc.SetPen(wxPen(wxColour(0, 0, 0), 3));
        } else {
            dc.SetPen(wxPen(wxColour(0, 0, 0), 1));
        }
        dc.DrawLine(0, i * fieldSizeHeight, size.GetWidth(), i * fieldSizeHeight);
        dc.DrawLine(i * fieldSizeWidth, 0, i * fieldSizeWidth, size.GetHeight());
    }
}