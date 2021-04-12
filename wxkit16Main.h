/***************************************************************
 * Name:      wxkit16Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-09-06
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXKIT16MAIN_H
#define WXKIT16MAIN_H
#include <map>
#include <iostream>
#include <vector>

using namespace std;



//(*Headers(wxkit16Frame)
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)




class Code{
    public:
        string kod;
        string jelentes;
};


class wxkit16Frame: public wxFrame
{
    public:




        wxkit16Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxkit16Frame();

        void in_list() {            ListCtrl1 -> InsertColumn(0,"Kód");
            ListCtrl1 -> InsertColumn(1,"Jelentés");
        }



//        void alap(){
//        Code tmp;
//        tmp.kodok["AAA"] = "lolci";
//        tmp.kodok["BBB"] = "poharaspacal";
//        for (map<wxString,wxString> ::reverse_iterator it=tmp.kodok.rbegin();it != tmp.kodok.rend();it++)
//    {
//
//        long index = ListCtrl1->InsertItem(0,(*it).first);
//        ListCtrl1->SetItem(index,1,(*it).second);
////            }
//        }


    private:

        //(*Handlers(wxkit16Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnAddClick(wxCommandEvent& event);
        void OnAClick(wxCommandEvent& event);
        void OnBClick(wxCommandEvent& event);
        void OnCClick(wxCommandEvent& event);
        void OnAddClick1(wxCommandEvent& event);
        void OnButtonDeleteClick(wxCommandEvent& event);
        void OnButtonDelClick(wxCommandEvent& event);
        void OnListCtrl1ItemSelect(wxListEvent& event);
        void OnListCtrl1ColumnClick(wxListEvent& event);
        void OnForceAddClick(wxCommandEvent& event);
        void OnButtonTest1Click(wxCommandEvent& event);
        void OnA_testClick(wxCommandEvent& event);
        void OnB_testClick(wxCommandEvent& event);
        void OnC_testClick(wxCommandEvent& event);
        void OnButtonBackClick(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnTestButtonClick(wxCommandEvent& event);
        void OnTextCtrlTestTextEnter(wxCommandEvent& event);
        void OnTestButtonClick1(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxkit16Frame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_BUTTON10;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(wxkit16Frame)
        wxButton* B_test;
        wxButton* B;
        wxButton* Add;
        wxListCtrl* ListCtrl1;
        wxStaticText* StaticText2;
        wxButton* A;
        wxButton* Button1;
        wxButton* C_test;
        wxButton* TestButton;
        wxStaticText* StaticText1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlTest;
        wxTextCtrl* TextCtrlKod;
        wxButton* C;
        wxButton* ButtonBack;
        wxTextCtrl* TextCtrl1;
        wxButton* ForceAdd;
        wxButton* A_test;
        wxTextCtrl* TextCtrlJel;
        wxMessageDialog* MessageDialog1;
        //*)


        vector<Code> vekt;
        string ideigstring;
        int c;

        float selected = -1;

        void frissit (int n){
            wxListItem item;
            item.SetId(n); /// hanyadik elem a listitemben
            wxString str; ///stringet wx stringbe konvertalom
            str << vekt[n].kod;
            ListCtrl1->InsertItem(item);
            ListCtrl1->SetItem(n,0,str,-1);
            str.clear();
            str << vekt[n].jelentes;
            ListCtrl1->SetItem(n,1,str,-1);
        }

        bool ellenoriz (){
            string buff;
            buff = TextCtrlKod->GetValue();
            for(int i = 0; i<vekt.size();i++){
                int length = buff.size();
                if(length <= vekt[i].kod.size()){
                    string tmp (vekt[i].kod,0,length);  /// karaltertol karakterig bemasolja a tmp be
                    if(buff == tmp){
                        return false;
                    }
                }
                else
                {
                    int hossz = vekt[i].kod.size();
                    string temp (buff,0,hossz);
                    if(vekt[i].kod == temp){
                        return false;
                    }
                }
            }
            return true;
        }

        void urit(wxTextCtrl* text1, wxTextCtrl* text2){
                text1->SetValue("");
                text2->SetValue("");
        }



void keres_hibakod_nelkul(wxTextCtrl* test, wxTextCtrl* kiir){

string mivanbenne;
bool bennevan = false;

        for(int i = 0; i < vekt.size() ;i++){

            if (test->GetValue() == vekt[i].kod){
                bennevan = true;
                mivanbenne = vekt[i].jelentes;

            }

            }

    switch(bennevan){
case 1:
    kiir->AppendText(mivanbenne+ "\n");
    test->Clear();
    break;
    }

        }

void keres_hibakoddal(wxTextCtrl* test, wxTextCtrl* kiir, wxMessageDialog* hibakod){

string mivanbenne;
bool bennevan = false;

        for(int i = 0; i < vekt.size() ;i++){

            if (test->GetValue() == vekt[i].kod){
                bennevan = true;
                mivanbenne = vekt[i].jelentes;

            }

            }

    switch(bennevan){
case 1:
    kiir->AppendText(mivanbenne+ "\n");
    test->Clear();
    break;
case 0:
    hibakod->ShowModal();
    test->Clear();
    break;
    }



        }

        DECLARE_EVENT_TABLE()

};

#endif // WXKIT16MAIN_H
