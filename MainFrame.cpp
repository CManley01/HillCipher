#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

/// <summary>
/// Declares Functions
/// </summary>
void charToInt();
void intToChar();
void encrypt(int key[]);
void decrypt(int key[]);

/// <summary>
/// Global variables
/// </summary>
int KEY[4];
wxString MESSAGE = "aBCDefgHijklmnoPqrstuvwxyz";
int INT_MESSAGE [100];

//main
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    //panel
	wxPanel* panel = new wxPanel(this);

    //Labels
    wxStaticText* staticTextMessage = new wxStaticText(panel, wxID_ANY, "Message:", wxPoint(40, 50));
    wxStaticText* staticTextKey = new wxStaticText(panel, wxID_ANY, "Key:", wxPoint(60, 100));

    //Decryption and Encryption Bittons
	wxButton* eButton = new wxButton(panel, wxID_ANY, "Encrypt", wxPoint(100, 150), wxSize(100, 50));
	wxButton* dButton = new wxButton(panel, wxID_ANY, "Decrypt", wxPoint(200, 150), wxSize(100, 50));

    //Message input box
	wxTextCtrl* message = new wxTextCtrl(panel, wxID_ANY, "Please Enter a Message", wxPoint(100, 50), wxSize(200, -1));
    
	// Key input boxes
    wxSpinCtrl* spinCrtl1 = new wxSpinCtrl(panel, wxID_ANY,"", wxPoint(100, 100), wxSize(50, -1), 0, 0,9);
    wxSpinCtrl* spinCrtl2 = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(150, 100), wxSize(50, -1), 0, 0, 9);
    wxSpinCtrl* spinCrtl3 = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(200, 100), wxSize(50, -1), 0, 0, 9);
    wxSpinCtrl* spinCrtl4 = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(250, 100), wxSize(50, -1), 0, 0, 9);

    //Binding buttons
	eButton->Bind(wxEVT_BUTTON, &MainFrame::OnEButtonClicked, this);
	dButton->Bind(wxEVT_BUTTON, &MainFrame::OnDButtonClicked, this);
	message->Bind(wxEVT_TEXT, &MainFrame::OnMessageChanged, this);

    spinCrtl1->Bind(wxEVT_TEXT, &MainFrame::OnKeyChanged1, this);
    spinCrtl2->Bind(wxEVT_TEXT, &MainFrame::OnKeyChanged2, this);
    spinCrtl3->Bind(wxEVT_TEXT, &MainFrame::OnKeyChanged3, this);
    spinCrtl4->Bind(wxEVT_TEXT, &MainFrame::OnKeyChanged4, this);

    //Status bar
	CreateStatusBar();
}
 
//Method to convert message inputted to the message to be encrypted/decrypted
void MainFrame::OnMessageChanged(wxCommandEvent& evt) {

	MESSAGE = evt.GetString();
    charToInt();

    wxString str = wxString::Format("Message: %s", MESSAGE);
    wxLogStatus(str);
   
}

// method to change key
void MainFrame::OnKeyChanged1(wxCommandEvent& evt) {

    KEY[0] = evt.GetInt();

       wxString str = wxString::Format("Key[0]: %d", KEY[0]);
       wxLogStatus(str);
}

// method to change key
void MainFrame::OnKeyChanged2(wxCommandEvent& evt) {

    KEY[1] = evt.GetInt();
    wxString str = wxString::Format("Key[1]: %d", KEY[1]);
    wxLogStatus(str);

}

// method to change key
void MainFrame::OnKeyChanged3(wxCommandEvent& evt) {

    KEY[2] = evt.GetInt();

    wxString str = wxString::Format("Key[2]: %d", KEY[2]);
    wxLogStatus(str);

}

// method to change key
void MainFrame::OnKeyChanged4(wxCommandEvent& evt) {

    KEY[3] = evt.GetInt();

    wxString str = wxString::Format("Key[3]: %d", KEY[3]);
    wxLogStatus(str);
}

//Encryption Button
void MainFrame::OnEButtonClicked(wxCommandEvent& evt) {

    encrypt(KEY);

    wxString str = wxString::Format("Encryption: %s", MESSAGE);
    wxLogMessage(str);
    wxLogStatus(str);
}

void MainFrame::OnDButtonClicked(wxCommandEvent& evt) {

    decrypt(KEY);

    wxString str = wxString::Format("Decryption: %s", MESSAGE);
    wxLogMessage(str);
    wxLogStatus(str);
}

//method to convert the message into an int array
void charToInt() {
	
	for (int i = 0; i < MESSAGE.length(); i++) {
		char x = tolower(MESSAGE[i]);

        switch (x) {
            //cases
        case 'a':
            INT_MESSAGE[i] = 0;
            break;
        case 'b':
            INT_MESSAGE[i] = 1;
            break;
        case 'c':
            INT_MESSAGE[i] = 2;
            break;
        case 'd':
            INT_MESSAGE[i] = 3;
            break;
        case 'e':
            INT_MESSAGE[i] = 4;
            break;
        case 'f':
            INT_MESSAGE[i] = 5;
            break;
        case 'g':
            INT_MESSAGE[i] = 6;
            break;
        case 'h':
            INT_MESSAGE[i] = 7;
            break;
        case 'i':
            INT_MESSAGE[i] = 8;
            break;
        case 'j':
            INT_MESSAGE[i] = 9;
            break;
        case 'k':
            INT_MESSAGE[i] = 10;
            break;
        case 'l':
            INT_MESSAGE[i] = 11;
            break;
        case 'm':
            INT_MESSAGE[i] = 12;
            break;
        case 'n':
            INT_MESSAGE[i] = 13;
            break;
        case 'o':
            INT_MESSAGE[i] = 14;
            break;
        case 'p':
            INT_MESSAGE[i] = 15;
            break;
        case 'q':
            INT_MESSAGE[i] = 16;
            break;
        case 'r':
            INT_MESSAGE[i] = 17;
            break;
        case 's':
            INT_MESSAGE[i] = 18;
            break;
        case 't':
            INT_MESSAGE[i] = 19;
            break;
        case 'u':
            INT_MESSAGE[i] = 20;
            break;
        case 'v':
            INT_MESSAGE[i] = 21;
            break;
        case 'w':
            INT_MESSAGE[i] = 22;
            break;
        case 'x':
            INT_MESSAGE[i] = 23;
            break;
        case 'y':
            INT_MESSAGE[i] = 24;
            break;
        case 'z':
            INT_MESSAGE[i] = 25;
            break;

        default:
            break;
        }

    }
}

//method to convert int array to message
void intToChar() {

    for (int i = 0; i < MESSAGE.length(); i++) {
        int x = INT_MESSAGE[i];

        switch (x) {
            //cases
        case 0:
            MESSAGE[i] = 'a';
            break;
        case 1:
            MESSAGE[i] = 'b';
            break;
        case 2:
            MESSAGE[i] = 'c';
            break;
        case 3:
            MESSAGE[i] = 'd';
            break;
        case 4:
            MESSAGE[i] = 'e';
            break;
        case 5:
            MESSAGE[i] = 'f';
            break;
        case 6:
            MESSAGE[i] = 'g';
            break;
        case 7:
            MESSAGE[i] = 'h';
            break;
        case 8:
            MESSAGE[i] = 'i';
            break;
        case 9:
            MESSAGE[i] = 'j';
            break;
        case 10:
            MESSAGE[i] = 'k';
            break;
        case 11:
            MESSAGE[i] = 'l';
            break;
        case 12:
            MESSAGE[i] = 'm';
            break;
        case 13:
            MESSAGE[i] = 'n';
            break;
        case 14:
            MESSAGE[i] = 'o';
            break;
        case 15:
            MESSAGE[i] = 'p';
            break;
        case 16:
            MESSAGE[i] = 'q';
            break;
        case 17:
            MESSAGE[i] = 'r';
            break;
        case 18:
            MESSAGE[i] = 's';
            break;
        case 19:
            MESSAGE[i] = 't';
            break;
        case 20:
            MESSAGE[i] = 'u';
            break;
        case 21:
            MESSAGE[i] = 'v';
            break;
        case 22:
            MESSAGE[i] = 'w';
            break;
        case 23:
            MESSAGE[i] = 'x';
            break;
        case 24:
            MESSAGE[i] = 'y';
            break;
        case 25:
            MESSAGE[i] = 'z';
            break;
        
        default:
            break;
        }

    }
}


//method to encrypt message
void encrypt(int key[]) {
    
    charToInt();

    for(int i = 0; i < MESSAGE.Len(); i += 2) {

        int y = i + 1;
           
        int tempi = INT_MESSAGE[i];
        int tempy = INT_MESSAGE[y];
        INT_MESSAGE[i] = (((key[0] * tempi) + (key[1] * tempy)) % 26);
        INT_MESSAGE[y] = (((key[2] * tempi) + (key[3] * tempy)) % 26);
    }
        
        intToChar();
    
}

//method to decrypt message
void decrypt(int key []) {

// Math to get the multiplicitave inverse of the key
#pragma region MyRegion

    
    int a = 26;
    int b = ((key[0] * key[3]) - (key[1]*key[2]));
   
    if (b < 0) {
        b = 26 + b;
    }
    int q = a/b;
    int r = a % b;
    int t1 = 0;
    int t2 = 1;
    int t3 = (0-q);

    while (r != 0) {
        a = b;
        b = r;
        q = a / b;
        r = a % b;
        t1 = t2;
        t2 = t3;
        t3 = (t1 - (q * t2));
       
    }
#pragma endregion

    //Inverse matrix math
    int keyInverse[4] = { ((key[3] * t2) % 26),(((26 - key[1]) * t2) % 26), (((26 - key[2]) * t2) % 26),((key[0] * t2) % 26) };

    
    charToInt();

    //Multiplies the matrix by the inverse matrix
    for (int i = 0; i < MESSAGE.Len(); i += 2) {
        int y = i + 1;

        int tempi = INT_MESSAGE[i];
        int tempy = INT_MESSAGE[y];
        INT_MESSAGE[i] = (((keyInverse[0] * tempi) + (keyInverse[1] * tempy)) % 26);
        INT_MESSAGE[y] = (((keyInverse[2] * tempi) + (keyInverse[3] * tempy)) % 26);
    }

    intToChar();
}