#pragma once
#include <wx/wx.h>


class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	
	void OnEButtonClicked(wxCommandEvent& evt);
	void OnDButtonClicked(wxCommandEvent& evt);
	void OnMessageChanged(wxCommandEvent& evt);
	void OnKeyChanged1(wxCommandEvent& evt);
	void OnKeyChanged2(wxCommandEvent& evt);
	void OnKeyChanged3(wxCommandEvent& evt);
	void OnKeyChanged4(wxCommandEvent& evt);

};

