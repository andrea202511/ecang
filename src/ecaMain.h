/***************************************************************
 * Name:      ecaMain.h
 * Purpose:   Defines Application Frame
 * Author:    AF ()
 * Created:   2021-11-11
 * Copyright: AF ()
 * License: GNU
 **************************************************************/

#ifndef ECAMAIN_H
#define ECAMAIN_H

//(*Headers(ecaDialog)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
//*)

#include <wx/arrimpl.cpp>
#include "ecaSetting.h"
#include "ecaPDO.h"
#include "ecaPDOFilter.h"
#include "ecaDataFilter.h"
#include "ecaABOUT.h"




class ecaDialog: public wxDialog
{
    public:

        ecaDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ecaDialog();


    private:

        //(*Handlers(ecaDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OpenFileENI(wxCommandEvent& event);
        void OpenFilePcapng(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void Elabora(wxCommandEvent& event);
        //void OnButton4Click(wxCommandEvent& event);
        //void OnTextCtrl3Text(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ecaDialog)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL2;
        static const long ID_BITMAPBUTTON1;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON5;
        static const long ID_BUTTON3;
        static const long ID_BITMAPBUTTON3;
        //*)

        //(*Declarations(ecaDialog)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button5;
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxFileDialog* FileDialog3;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        ecaSetting* SettingDialog;
        ecaPDOFilter* FilterPDODialog;
        ecaDataFilter* FilterDataDialog;
        ecaABOUT* AboutDialog;

        wxString FileEni;
        wxString FilePcapng;

        DECLARE_EVENT_TABLE()
};

#endif // ECAMAIN_H
