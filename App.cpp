#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("Hill Cipher");
	mainFrame->SetClientSize(400, 400);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
