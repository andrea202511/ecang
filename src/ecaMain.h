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
#include <wx/timer.h>
//*)

#include <wx/arrimpl.cpp>
#include "ecaSetting.h"
#include "ecaPDO.h"
#include "ecaSlaves.h"
#include "ecaPDOFilter.h"
#include "ecaDataFilter.h"
#include "ecaABOUT.h"

#pragma pack(1)
struct MAC_ADDRESS {
 uint16_t part_1;
 uint16_t part_2;
 uint16_t part_3;
};

struct BLOCK_HEADER {
  uint32_t BlockType;
  uint32_t BlockLength;
};

struct EPB_PART1_HEADER {
  uint32_t InterfaceID;
  uint32_t TimestampH;
  uint32_t TimestampL;
  uint32_t CapturedPacked;
  uint32_t OriginalPacked;
};

//Ethercat header
struct EPB_PART2_HEADER {
  MAC_ADDRESS MacSource;
  MAC_ADDRESS MacDest;
  uint16_t Type;
  uint16_t EthercatHeader; //Lenght(11)-Reserved(1)-Type(4) //questa lunghezza è la lunghezza totale di tutti i datagram
};


struct DATAGRAM_HEADER {
  uint8_t Command;
  uint8_t Index;
  uint16_t Address; //include address e offset
  uint16_t Offset;
  uint16_t Mix; //Length(11)+Reserved(3)+Circulating(1)+Next(1)
  uint16_t IRQ;
};

struct MAILBOX_HEADER {
  uint16_t Lenght;
  uint16_t Address;
  uint16_t Mix; //Channel(6)+Priority(2)+Type(4)+Count(3)+Reserved(1)
};

struct MAILBOX_SERVICE {
  uint16_t Mix1;  //Number(9)+Reserved(3)+SDOservice(4)
         /*
         0x0020 SDO request
         0x0030 SDO res
         */
  uint8_t Mix2;  //Size(1)+Transfer(1)+Data(2)+Complete(1)+SDOcommand(3)
         /*
         0x2F = 1 byte write
         0x2B = 2 bytes write
         0x27 = 3 bytes write
         0x23 = 4 bytes write

         0x4F = 1 byte read
         0x4B = 2 bytes read
         0x47= 3 bytes read
         0x43 = 4 bytes read

         0x60 = SDO download ok  <--
         0x80 = SDO download ERROR (4 bytes x error code) <--
         */
  uint16_t Object;
  uint8_t Subindex;
//  uint32_t Size;  qui ci sono gli 8 bytes dati
};

#pragma pack(0)

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
        void OnTimer1Trigger(wxTimerEvent& event);
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
        static const long ID_TIMER1;
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
        wxTimer Timer1;
        //*)

        ecaSetting* SettingDialog;
        ecaPDOFilter* FilterPDODialog;
        ecaDataFilter* FilterDataDialog;
        ecaABOUT* AboutDialog;

        wxString FileEni;
        wxString FilePcapng;

        int32_t ticks;

        DECLARE_EVENT_TABLE()
};

#endif // ECAMAIN_H
