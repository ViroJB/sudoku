#include "input_number_popup.h"

InputNumberPopup::InputNumberPopup(wxWindow* parent, int x, int y, int posX, int posY)
    : wxFrame(parent, wxID_ANY, "Input Number", wxPoint(posX, posY), wxDefaultSize) {
    _x = x;
    _y = y;
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Enter number:");
    sizer->Add(text, 0, wxALL, 5);
    auto input = new wxTextCtrl(panel, ID_INPUT, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    sizer->Add(input, 0, wxALL, 5);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* okButton = new wxButton(panel, wxID_OK, "OK");
    wxButton* cancelButton = new wxButton(panel, wxID_CANCEL, "Cancel");
    buttonSizer->Add(okButton, 0, wxALL, 5);
    buttonSizer->Add(cancelButton, 0, wxALL, 5);
    sizer->Add(buttonSizer, 0, wxALIGN_CENTER);
    panel->SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
    Bind(wxEVT_BUTTON, &InputNumberPopup::onOk, this, wxID_OK);
    Bind(wxEVT_BUTTON, &InputNumberPopup::onCancel, this, wxID_CANCEL);
    std::cout << "InputNumberPopup created" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl;
}

// TODO check if input is a number
void InputNumberPopup::onOk(wxCommandEvent& event) {
    std::cout << "onOk" << std::endl;
    wxTextCtrl* input = (wxTextCtrl*)FindWindowById(ID_INPUT);
    if (input->GetValue().ToStdString().empty()) {
        std::cout << "empty" << std::endl;
        return;
    }
    // check if input is int
    if (input->GetValue().ToStdString().find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "not a number" << std::endl;
        Close(); // TODO show error message
        return;
    }

    _number = std::stoi(input->GetValue().ToStdString());
    // check if number is between 1-9
    if (_number < 1 || _number > 9) {
        std::cout << "not between 1-9" << std::endl;
        Close(); // TODO show error message
        return;
    }  

    wxFrame* parent = (wxFrame*)GetParent();
    if (parent) {
        MainFrame* mainFrame = dynamic_cast<MainFrame*>(parent);
        if (mainFrame) {
            mainFrame->getGame()->setNode(_x, _y, _number);
            mainFrame->Refresh();
            mainFrame->getDrawBoard()->setInputNumberPopupOpen(false);
        }
    }

    Close();
}

void InputNumberPopup::onCancel(wxCommandEvent& event) {
    wxFrame* parent = (wxFrame*)GetParent();
    MainFrame* mainFrame = dynamic_cast<MainFrame*>(parent);
    mainFrame->getDrawBoard()->setInputNumberPopupOpen(false);
    std::cout << "onCancel" << std::endl;
    _number = -1;
    Close();
}

int InputNumberPopup::getNumber() const { return _number; }