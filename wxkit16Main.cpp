/***************************************************************
 * Name:      wxkit16Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-09-06
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxkit16Main.h"
#include <wx/msgdlg.h>
#include <algorithm>



//(*InternalHeaders(wxkit16Frame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxkit16Frame)
const long wxkit16Frame::ID_TEXTCTRL1 = wxNewId();
const long wxkit16Frame::ID_TEXTCTRL2 = wxNewId();
const long wxkit16Frame::ID_BUTTON1 = wxNewId();
const long wxkit16Frame::ID_BUTTON2 = wxNewId();
const long wxkit16Frame::ID_BUTTON3 = wxNewId();
const long wxkit16Frame::ID_BUTTON4 = wxNewId();
const long wxkit16Frame::ID_BUTTON5 = wxNewId();
const long wxkit16Frame::ID_LISTCTRL1 = wxNewId();
const long wxkit16Frame::ID_BUTTON6 = wxNewId();
const long wxkit16Frame::ID_BUTTON7 = wxNewId();
const long wxkit16Frame::ID_TEXTCTRL3 = wxNewId();
const long wxkit16Frame::ID_BUTTON8 = wxNewId();
const long wxkit16Frame::ID_BUTTON9 = wxNewId();
const long wxkit16Frame::ID_BUTTON10 = wxNewId();
const long wxkit16Frame::ID_BUTTON11 = wxNewId();
const long wxkit16Frame::ID_BUTTON12 = wxNewId();
const long wxkit16Frame::ID_TEXTCTRL4 = wxNewId();
const long wxkit16Frame::ID_STATICTEXT1 = wxNewId();
const long wxkit16Frame::ID_STATICTEXT2 = wxNewId();
const long wxkit16Frame::idMenuQuit = wxNewId();
const long wxkit16Frame::idMenuAbout = wxNewId();
const long wxkit16Frame::ID_STATUSBAR1 = wxNewId();
const long wxkit16Frame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxkit16Frame,wxFrame)
    //(*EventTable(wxkit16Frame)
    //*)
END_EVENT_TABLE()

wxkit16Frame::wxkit16Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxkit16Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Kodolas-szerkeszto"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(570,450));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    TextCtrlKod = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,16), wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrlJel = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,16), wxSize(132,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    A = new wxButton(this, ID_BUTTON1, _("A"), wxPoint(8,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    B = new wxButton(this, ID_BUTTON2, _("B"), wxPoint(104,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    C = new wxButton(this, ID_BUTTON3, _("C"), wxPoint(200,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ForceAdd = new wxButton(this, ID_BUTTON4, _("Force Add"), wxPoint(304,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Add = new wxButton(this, ID_BUTTON5, _("Add"), wxPoint(304,56), wxSize(75,32), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxPoint(16,96), wxSize(176,200), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON6, _("Test"), wxPoint(304,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button2 = new wxButton(this, ID_BUTTON7, _("Delete"), wxPoint(304,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(40,96), wxSize(200,216), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    A_test = new wxButton(this, ID_BUTTON8, _("Test A"), wxPoint(400,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    B_test = new wxButton(this, ID_BUTTON9, _("Test B"), wxPoint(400,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    C_test = new wxButton(this, ID_BUTTON10, _("Test C"), wxPoint(400,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    TestButton = new wxButton(this, ID_BUTTON11, _("Test"), wxPoint(400,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    ButtonBack = new wxButton(this, ID_BUTTON12, _("Back"), wxPoint(400,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    TextCtrlTest = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(16,40), wxSize(272,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Add meg a tesztelni kívánt kódot :"), wxPoint(16,24), wxSize(200,13), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("A kód jelentése, ha létezik :"), wxPoint(40,80), wxSize(144,13), 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MessageDialog1 = new wxMessageDialog(this, _("Incorrect Code"), _("Error"), wxICON_ERROR, wxDefaultPosition);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnAClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnBClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnCClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnForceAddClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnAddClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&wxkit16Frame::OnListCtrl1ItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&wxkit16Frame::OnListCtrl1ColumnClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnButtonTest1Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnButtonDelClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnA_testClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnB_testClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnC_testClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnTestButtonClick1);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxkit16Frame::OnButtonBackClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkit16Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxkit16Frame::OnAbout);
    //*)

    in_list();
    //in_test();
    TextCtrlTest->Disable();
    TextCtrlTest->Hide();
    A_test->Disable();
    A_test->Hide();
    B_test->Disable();
    B_test->Hide();
    C_test->Disable();
    C_test->Hide();
    ButtonBack->Hide();
    ButtonBack->Disable();
    TestButton->Hide();
    TestButton->Disable();
    TextCtrl1->Hide();
    TextCtrl1->Disable();
    StaticText1->Hide();
    StaticText2->Hide();




}

wxkit16Frame::~wxkit16Frame()
{
    //(*Destroy(wxkit16Frame)
    //*)
}

void wxkit16Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxkit16Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxkit16Frame::OnAClick(wxCommandEvent& event)
{
    TextCtrlKod->AppendText("A");
}

void wxkit16Frame::OnBClick(wxCommandEvent& event)
{
    TextCtrlKod->AppendText("B");
}

void wxkit16Frame::OnCClick(wxCommandEvent& event)
{
    TextCtrlKod->AppendText("C");
}



void wxkit16Frame::OnAddClick(wxCommandEvent& event){

   if(TextCtrlKod->GetValue() != "" && TextCtrlJel->GetValue() != ""  ){
            //string jelentesszoveg;
            Code valid;
            //jelentesszoveg = TextCtrlJel->GetValue();
            valid.jelentes = TextCtrlJel->GetValue();
            valid.kod = TextCtrlKod->GetValue();
            if(ellenoriz()){
                vekt.push_back(valid);
                frissit(vekt.size()-1);
                urit(TextCtrlJel,TextCtrlKod);
            }

            else
                MessageDialog1->ShowModal();
                urit(TextCtrlJel,TextCtrlKod);
            }
    }


void wxkit16Frame::OnListCtrl1ItemSelect(wxListEvent& event)
{
    selected = event.GetIndex();
}


void wxkit16Frame::OnButtonDelClick(wxCommandEvent& event){
c = 0; ///hossz korrekcio
if (selected != -1){
        vekt.erase(vekt.begin()+selected-c);
        ++c;
        ListCtrl1->DeleteAllItems();
        }
        selected = -1;
for(int i = 0;i<vekt.size();i++){
    frissit(i);
}
}

bool kodrendez(const Code &a, const Code &b){
return a.kod < b.kod;
}

bool jelentesrendez(const Code &a, const Code &b){
return a.jelentes < b.jelentes;
}


void wxkit16Frame::OnListCtrl1ColumnClick(wxListEvent& event)   ///rendezes
{
    int col = event.GetColumn();
    ListCtrl1->DeleteAllItems();
    switch(col){
case 0:
    sort(vekt.begin(),vekt.end(),kodrendez);
    for(int i = 0; i<vekt.size();i++){
        frissit(i);
    }
    break;
case 1:
    sort(vekt.begin(),vekt.end(),jelentesrendez);
    for(int i = 0;i<vekt.size();i++){
        frissit(i);
    }
    break;
    }
}

void wxkit16Frame::OnForceAddClick(wxCommandEvent& event)
{

    if(TextCtrlKod->GetValue() != "" && TextCtrlJel->GetValue() != ""  ){
        Code valid;
        valid.jelentes = TextCtrlJel->GetValue();
        valid.kod = TextCtrlKod->GetValue();
        if(ellenoriz()){
                vekt.push_back(valid);
                frissit(vekt.size()-1);
                urit(TextCtrlJel,TextCtrlKod);
            }
            else{
                for(int i = 0; i<vekt.size();i++){
                    int length = valid.kod.size();
                    if(length<=vekt[i].kod.size()){
                        string tmp (vekt[i].kod,0,length);
                        if(valid.kod == tmp){
                            vekt[i].kod = valid.kod;
                            vekt[i].jelentes = valid.jelentes;

                        }
                    }
                    else {
                        int hossz = vekt[i].kod.size();
                        string temp (valid.kod,0,hossz);
                        if(vekt[i].kod == temp){
                            vekt[i].kod = valid.kod;
                            vekt[i].jelentes = valid.jelentes;

                        }
                    }
                }

                ListCtrl1->DeleteAllItems();
                for(int i = 0; i<vekt.size();i++){
                    frissit(i);
                }
                urit(TextCtrlJel,TextCtrlKod);
            }
    }

}


void wxkit16Frame::OnButtonTest1Click(wxCommandEvent& event)
{

    TextCtrlJel->Hide();
    TextCtrlJel->Disable();
    TextCtrlKod->Hide();
    TextCtrlKod->Hide();
    A->Hide();
    A->Disable();
    B->Hide();
    B->Disable();
    C->Hide();
    C->Disable();
    ForceAdd->Hide();
    ForceAdd->Disable();
    Add->Hide();
    Add->Disable();
    ListCtrl1->Hide();
   // ListCtrl1->Disable();
    Button1->Hide();
    Button1->Disable();
    Button2->Hide();
    Button2->Disable();
    TextCtrlTest->Show();
    TextCtrlTest->Enable();
    A_test->Enable();
    A_test->Show();
    B_test->Enable();
    B_test->Show();
    C_test->Enable();
    C_test->Show();
    ButtonBack->Show();
    ButtonBack->Enable();
    TestButton->Show();
    TestButton->Enable();
    TextCtrl1->Enable();
    TextCtrl1->Show();
    StaticText1->Show();
    StaticText2->Show();

}

void wxkit16Frame::OnA_testClick(wxCommandEvent& event)
{
    TextCtrlTest->AppendText("A");
    keres_hibakod_nelkul(TextCtrlTest,TextCtrl1);
}

void wxkit16Frame::OnB_testClick(wxCommandEvent& event)
{
    TextCtrlTest->AppendText("B");
    keres_hibakod_nelkul(TextCtrlTest,TextCtrl1);
}

void wxkit16Frame::OnC_testClick(wxCommandEvent& event)
{
    TextCtrlTest->AppendText("C");
    keres_hibakod_nelkul(TextCtrlTest,TextCtrl1);
}


void wxkit16Frame::OnButtonBackClick(wxCommandEvent& event)
{
    TextCtrlJel->Show();
    TextCtrlJel->Enable();
    TextCtrlKod->Show();
    TextCtrlKod->Enable();
    A->Show();
    A->Enable();
    B->Show();
    B->Enable();
    C->Show();
    C->Enable();
    ForceAdd->Show();
    ForceAdd->Enable();
    Add->Show();
    Add->Enable();
    ListCtrl1->Show();
    ListCtrl1->Enable();
    Button1->Show();
    Button1->Enable();
    Button2->Show();
    Button2->Enable();
    TextCtrlTest->Hide();
    TextCtrlTest->Disable();
    A_test->Hide();
    A_test->Disable();
    B_test->Disable();
    B_test->Hide();
    C_test->Disable();
    C_test->Hide();
    ButtonBack->Hide();
    ButtonBack->Disable();
    TestButton->Hide();
    TestButton->Disable();
    TextCtrl1->Disable();
    TextCtrl1->Hide();
    StaticText1->Hide();
    StaticText2->Hide();

}


void wxkit16Frame::OnTestButtonClick1(wxCommandEvent& event)
{
    keres_hibakoddal(TextCtrlTest,TextCtrl1,MessageDialog1);
}
