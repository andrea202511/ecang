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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>

#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/timer.h>
//*)

#include <stdint.h>
#include <wx/arrimpl.cpp>
#include "ecaSetting.h"
#include "ecaPDO.h"
#include "ecaSlaves.h"
#include "ecaPDOFilter.h"
#include "ecaABOUT.h"
#include "ecaStruct.h"



class ecaFrame: public wxFrame
{
    public:

        ecaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ecaFrame();


    private:

        //(*Handlers(ecaFrame)
        void OnQuit(wxCommandEvent& event);
        void OpenFileENI(wxCommandEvent& event);
        void OpenFilePcapng(wxCommandEvent& event);
        void Clear(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void Elabora(wxCommandEvent& event);
        void PreElabora(void);
        //void OnButton4Click(wxCommandEvent& event);
        //void OnTextCtrl3Text(wxCommandEvent& event);
        void ShowFilterDataDialog(wxCommandEvent& event);
        void ShowSettingDialog(wxCommandEvent& event);
        void ShowAboutDialog(wxCommandEvent& event);
        //        void OnBitmapButton2Click(wxCommandEvent& event);
        //        void OnBitmapButton3Click(wxCommandEvent& event);
        //        void OnButton5Click(wxCommandEvent& event);
        //        void OnButton1Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnToolBarHelpButton(wxCommandEvent& event);
        //*)


        //(*Identifiers(ecaFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM6;
        static const long idMenuQuit;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM7;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBARITEM1;
        static const long ID_TOOLBARITEM2;
        static const long ID_TOOLBARITEM3;
        static const long ID_TOOLBARITEM4;
        static const long ID_TOOLBARITEM6;
        static const long ID_TOOLBARITEM5;
        static const long ID_TOOLBARITEM7;
        static const long ID_TOOLBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(ecaFrame)
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxFileDialog* FileDialog3;
        wxMenu* Menu4;
        wxMenuItem* Menu3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTimer Timer1;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem10;
        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem4;
        wxToolBarToolBase* ToolBarItem5;
        wxToolBarToolBase* ToolBarItem8;
        //*)

        ecaSetting* SettingDialog;
        ecaPDOFilter* FilterPDODialog;
        ecaABOUT* AboutDialog;

        wxString FileEni;
        wxString FilePcapng;
        MAC_ADDRESS MacSourceDirIn;

        int32_t ticks;

////        void ShowFilterPDODialog(void);


        DECLARE_EVENT_TABLE()
};

#endif // ECAMAIN_H
