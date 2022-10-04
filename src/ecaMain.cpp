/***************************************************************
 * Name:      ecaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    AF ()
 * Created:   2021-11-11
 * Copyright: AF ()
 * License:
 **************************************************************/

#include "ecaMain.h"
#include "version.h"
#include <wx/msgdlg.h>
#include <wx/xml/xml.h>
#include <wx/file.h>
#include <wx/progdlg.h>

WX_DEFINE_OBJARRAY(PDOArray);

PDOArray ArrayPDO;


//(*InternalHeaders(ecaDialog)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
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

//(*IdInit(ecaDialog)
const long ecaDialog::ID_BUTTON1 = wxNewId();
const long ecaDialog::ID_TEXTCTRL1 = wxNewId();
const long ecaDialog::ID_BITMAPBUTTON2 = wxNewId();
const long ecaDialog::ID_BUTTON2 = wxNewId();
const long ecaDialog::ID_TEXTCTRL2 = wxNewId();
const long ecaDialog::ID_BITMAPBUTTON1 = wxNewId();
const long ecaDialog::ID_TEXTCTRL3 = wxNewId();
const long ecaDialog::ID_BUTTON5 = wxNewId();
const long ecaDialog::ID_BUTTON3 = wxNewId();
const long ecaDialog::ID_BITMAPBUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaDialog,wxDialog)
    //(*EventTable(ecaDialog)
    //*)
END_EVENT_TABLE()

ecaDialog::ecaDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ecaDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;

    Create(parent, id, _("ecang"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetMinSize(wxSize(480,320));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("ENI (xml)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrl1, 4, wxALL|wxEXPAND, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Disable();
    BoxSizer2->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Button2 = new wxButton(this, ID_BUTTON2, _("PCAPNG"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(TextCtrl2, 4, wxALL|wxEXPAND, 5);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->Disable();
    BoxSizer3->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxVSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextCtrl3Font(7,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    BoxSizer1->Add(TextCtrl3, 3, wxALL|wxEXPAND, 7);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button5 = new wxButton(this, ID_BUTTON5, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer4->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button3 = new wxButton(this, ID_BUTTON3, _("Export to CSV"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(Button3, 4, wxALL|wxEXPAND, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BoxSizer4->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file XML"), wxEmptyString, wxEmptyString, _("*.xml"), wxFD_DEFAULT_STYLE|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file PCAPNG"), wxEmptyString, wxEmptyString, _("*.pcapng"), wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog3 = new wxFileDialog(this, _("Select file CSV"), wxEmptyString, wxEmptyString, _("*.csv"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OpenFileENI);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton2Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OpenFilePcapng);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton1Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnButton5Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::Elabora);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton3Click);
    //*)

    SettingDialog = new ecaSetting(this);
    FilterPDODialog = new ecaPDOFilter(this);
    FilterDataDialog = new ecaDataFilter(this);
    AboutDialog = new ecaABOUT(this);
}

ecaDialog::~ecaDialog()
{
    //(*Destroy(ecaDialog)
    //*)
}

void ecaDialog::OnQuit(wxCommandEvent& event)
{
  Close();
}

void ecaDialog::OnAbout(wxCommandEvent& event)
{
  wxString msg = wxbuildinfo(long_f);
  wxMessageBox(msg, _("Welcome to..."));
}


/* -----------------------------------------------
 * Select, open and read all PDO's header from ENI
 * file. All data are stored in ArrayPDO
 * -----------------------------------------------*/
void ecaDialog::OpenFileENI(wxCommandEvent& event)
{

  if (FileDialog1->ShowModal() == wxID_OK)
  {
		FileEni=FileDialog1->GetPath();
		TextCtrl1->SetValue(FileEni);

	}

  wxString str1;
  wxString str2;

  wxXmlDocument docxml;
  wxXmlNode *child_liv1;
  wxXmlNode *child_liv2;
  wxXmlNode *child_liv3;
  wxXmlNode *child_liv4;
  wxXmlNode *child_liv5;

  if (!docxml.Load(FileEni))
    return;

  str1="Open file: "+FileEni+"\n";
  TextCtrl3->AppendText(str1);
  TextCtrl3->Refresh();

  BitmapButton2->Disable();
  ecaPDO PdoTmp;
  long int longtmp;
  uint16_t maxbytes;
  int pdoin=0;
  int pdout=0;

  ArrayPDO.Clear();

  //Loop to find Config/ProcessImage/Inputs|Outputs
  child_liv1 = docxml.GetRoot()->GetChildren();
  while (child_liv1)
  {
    str1=child_liv1->GetName();
    if (str1=="Config")
    {
      child_liv2=child_liv1->GetChildren();
      while (child_liv2)
      {
        str1=child_liv2->GetName();
        if (str1=="ProcessImage")
        {
          child_liv3=child_liv2->GetChildren();
          while (child_liv3)
          {
            str1=child_liv3->GetName();
            if (str1=="Inputs")
            {
              child_liv4=child_liv3->GetChildren();
              while (child_liv4)
              {
                str1=child_liv4->GetName();
                if (str1=="ByteSize")
                {
                  str2=child_liv4->GetNodeContent();
                  str2.ToLong(&longtmp);
                  maxbytes=(int16_t) (longtmp/8);
                }
                if (str1=="Variable")
                {
                  child_liv5=child_liv4->GetChildren();
                  while (child_liv5)
                  {
                    str1=child_liv5->GetName();
                    if (str1=="Name")
                    {
                      str2=child_liv5->GetNodeContent();
                      PdoTmp.PDO_name=str2;
                    }
                    if (str1=="BitSize")
                    {
                      str2=child_liv5->GetNodeContent();
                      str2.ToLong(&longtmp);
                      //Bits variables are managed by byte
                      if (longtmp<8)
                        longtmp=8;
                      PdoTmp.PDO_bytes=(int16_t)longtmp;
                    }
                    if (str1=="BitOffs")
                    {
                      str2=child_liv5->GetNodeContent();
                      str2.ToLong(&longtmp);
                      if(not(longtmp%8 == 0)) {
                        PdoTmp.PDO_offset=32000;  //se non allineato al byte lo salto
                      }
                      else {
                        PdoTmp.PDO_offset=(int16_t)(longtmp/8);
                      }
                    }
                    child_liv5=child_liv5->GetNext();
                  }
                  if ((PdoTmp.PDO_offset>0) && (PdoTmp.PDO_offset<30000)) { //=maxbytes)) {
                    PdoTmp.out=false;
                    ArrayPDO.Add(PdoTmp);
                    pdoin++;
                  }
                }
                child_liv4=child_liv4->GetNext();
              }
            }
            if (str1=="Outputs")
            {
              child_liv4=child_liv3->GetChildren();
              while (child_liv4)
              {
                str1=child_liv4->GetName();
                if (str1=="ByteSize")
                {
                  str2=child_liv4->GetNodeContent();
                  str2.ToLong(&longtmp);
                  maxbytes=(int16_t) (longtmp/8);
                }
                if (str1=="Variable")
                {
                  child_liv5=child_liv4->GetChildren();
                  while (child_liv5)
                  {
                    str1=child_liv5->GetName();
                    if (str1=="Name")
                    {
                      str2=child_liv5->GetNodeContent();
                      PdoTmp.PDO_name=str2;
                    }
                    if (str1=="BitSize")
                    {
                      str2=child_liv5->GetNodeContent();
                      str2.ToLong(&longtmp);
                      //variabili a bit sono gestite a gruppi di 8
                      if (longtmp<8)
                        longtmp=8;
                      PdoTmp.PDO_bytes=(int16_t)longtmp;
                    }
                    if (str1=="BitOffs")
                    {
                      str2=child_liv5->GetNodeContent();
                      str2.ToLong(&longtmp);
                      if(not(longtmp%8 == 0))
                      {
                         PdoTmp.PDO_offset=32000;
                      }
                      else
                      {
                        PdoTmp.PDO_offset=(int16_t)(longtmp/8);
                      }
                    }
                    child_liv5=child_liv5->GetNext();
                  }
                  if ((PdoTmp.PDO_offset>0) && (PdoTmp.PDO_offset<30000)) { //=maxbytes)) {
                     PdoTmp.out=true;
                     ArrayPDO.Add(PdoTmp);
                     pdout++;
                  }
                }
                child_liv4=child_liv4->GetNext();
              }
            }
            child_liv3=child_liv3->GetNext();
          }
        }
        child_liv2=child_liv2->GetNext();
      }
    }
    child_liv1=child_liv1->GetNext();
  }
  str1.Printf(" Found %i PDO Inputs\n",pdoin);
  TextCtrl3->AppendText(str1);
  str1.Printf(" Found %i PDO Outputs\n",pdout);
  TextCtrl3->AppendText(str1);
  TextCtrl3->ShowPosition(TextCtrl3->GetLastPosition());
  TextCtrl3->Refresh();
  TextCtrl3->Update();

  if (pdoin>0 || pdout>0)
    BitmapButton2->Enable();


}


/*--------------------------------------------------
 * Select PCAPNG file and put his name into
 * FilePcapng string
 * -------------------------------------------------*/
void ecaDialog::OpenFilePcapng(wxCommandEvent& event)
{
  wxString file,str1;
  if (FileDialog2->ShowModal() == wxID_OK)
  {
    FilePcapng=FileDialog2->GetPath();
		TextCtrl2->SetValue(FilePcapng);
		BitmapButton1->Enable();
		str1="Open file: "+file+"\n";
		TextCtrl3->AppendText(str1);
	}
}

void ecaDialog::Elabora(wxCommandEvent& event)
{


  uint32_t ui32;
  uint16_t ui16;
  uint64_t ui64;
  uint8_t ui8;
  bool dirout=true;
  wxString str1;
  wxString fileCSV;


  wxFile filepcap;
  if (!filepcap.Open(FilePcapng,wxFile::read))
     return;

  long int sizepcap=filepcap.Length();

  if (FileDialog3->ShowModal() == wxID_OK)
  {
		fileCSV=FileDialog3->GetPath();
  }
  else
  {
    return;
  }


  wxFile filecsv;
  if (!filecsv.Open(fileCSV,wxFile::write))
     return;

  wxProgressDialog ProgrDialog(wxT("Elaborazione"),
                              wxT("Reading pcapng file"),
                              sizepcap,
                              this,
                              wxPD_CAN_ABORT|wxPD_AUTO_HIDE);

  uint32_t BlockType;
  uint32_t BlockLength;
  uint32_t InterfaceID;
  uint32_t TimestampH;
  uint32_t TimestampL;
  uint32_t CapturedPacked;
  uint32_t OriginalPacked;
  uint64_t MacSource;
  uint64_t MacDest;
  wxString rigacsv;

  //Prima riga csv con intestazioni
  rigacsv="Block;Dir;WorkCnt;Note;Errors";
  for (unsigned int i=0; i<ArrayPDO.GetCount();i++) {
    if (ArrayPDO[i].enabled==false)
      continue;
    ecaPDO ep=ArrayPDO[i];
    rigacsv+=";";
    rigacsv+=ep.PDO_name;
    rigacsv+=wxString::Format(wxT(" %d %d"),ep.PDO_bytes,ep.PDO_offset);
  }
  rigacsv+="\n";
  filecsv.Write(rigacsv);


  wxFileOffset punto=0;
  wxFileOffset puntoB=0;

  wxFileOffset data_NOP;
  wxFileOffset data_BRD;
  wxFileOffset data_BWR;
  wxFileOffset data_BRW;
  wxFileOffset data_LRD;
  wxFileOffset data_LWR;
  wxFileOffset data_LRW;
  wxFileOffset data_ARMW;


  int blocchi=0;

  bool dout=true;
  //Ciclo su file
  while (filepcap.Eof()==0)
  {
    //Estrazione blocchi file pcapng
    filepcap.Seek(punto,wxFromStart);

    if (!ProgrDialog.Update((int)punto)) {
//        ProgrDialog.EndModal();
      break;
    }

    //lettura tipo e lunghezza blocco
    if (filepcap.Read(&BlockType,4)!=4) break;
    if (filepcap.Read(&BlockLength,4)!=4) break;


    //blocco header 0x0A0D0D0A
    if (BlockType==0x0A0D0D0A)
    {
    }
    //blocco Interface description 0x00000001
    if (BlockType==0x00000001)
    {
    }
    //blocco Simple pachet 0x00000003
    if (BlockType==0x00000003)
    {
    }
    //blocco Name resolution block 0x00000004
    if (BlockType==0x00000004)
    {
    }
    //blocco Interface statistic block 0x00000005
    if (BlockType==0x00000005)
    {
    }
    //blocco Enhanced pachet 0x00000006
    if (BlockType==0x00000006)
    {
      if (filepcap.Read(&InterfaceID,4)!=4) break;
      if (filepcap.Read(&TimestampH,4)!=4) break;
      if (filepcap.Read(&TimestampL,4)!=4) break;
      if (filepcap.Read(&CapturedPacked,4)!=4) break;
      if (filepcap.Read(&OriginalPacked,4)!=4) break;

      //Da qui inizia il blocco di dati così come visualizzato da wireshark.
      //Gli offset (espressi in bits) ricavati dal file XML si riferiscono a questo blocco
      //Lo memorizzo
      puntoB=filepcap.Tell();

      //  6+6 indirizzi schede
      if (filepcap.Read(&MacSource,6)!=6) break;
      if (filepcap.Read(&MacDest,6)!=6) break;


      uint16_t Type;

      uint16_t EthercatFrameHeader;
      uint16_t EthercatFrameLenght;
      //0x88A4 frame ethercat
      if (filepcap.Read(&Type,2)!=2) break;

      if (filepcap.Read(&EthercatFrameHeader,2)!=2) break;

      EthercatFrameLenght=EthercatFrameHeader & 0x07FF;

      uint16_t byteEstratti;

      uint8_t DatagramCommand;
      uint8_t DatagramIndex;
      uint32_t DatagramAddress;
      uint16_t DatagramHeader2;
      uint16_t DatagramIRQ;
      uint16_t WorkingCount;
      uint16_t DatagramLenght;
      uint8_t datadatagram[2048];

      data_NOP=-1;
      data_BRD=-1;
      data_BWR=-1;
      data_BRW=-1;
      data_LRD=-1;
      data_LWR=-1;
      data_LRW=-1;
      data_ARMW=-1;

      //bool bip;

      byteEstratti=0;
      dirout=true;
      //Se e' un frame ethercat ne analizzo i singoli datagram
      if (Type==0xA488) {

        while (byteEstratti<EthercatFrameLenght)
        {
          //qui inizia il giro estrazione Datagrams
          if (filepcap.Read(&DatagramCommand,1)!=1) break;
          if (filepcap.Read(&DatagramIndex,1)!=1) break;
          if (filepcap.Read(&DatagramAddress,4)!=4) break;
          if (filepcap.Read(&DatagramHeader2,2)!=2) break; //length+reserved+circulating+next
          if (filepcap.Read(&DatagramIRQ,2)!=2) break;

          DatagramLenght=DatagramHeader2 & 0x07FF;

          if(DatagramCommand==0x00)  //NOP
            data_NOP=filepcap.Tell();

          if(DatagramCommand==0x07)  //BRD broadcast read
            data_BRD=filepcap.Tell();

          if(DatagramCommand==0x08)  //BWR broadcast write
            data_BWR=filepcap.Tell();

          if(DatagramCommand==0x09)  //BRW broadcast read/write
            data_BRW=filepcap.Tell();

          if(DatagramCommand==0x0A)  //LRD logical read
            data_LRD=filepcap.Tell();

          if(DatagramCommand==0x0B)  //LWR logical write
            data_LWR=filepcap.Tell();

          if(DatagramCommand==0x0C)  //LRW logical read/write
            data_LRW=filepcap.Tell();   //qui ci sono i PDO

          if(DatagramCommand==0x0d)  //ARMW Auto increment physical  Read Multiple Wrire
            data_ARMW=filepcap.Tell(); //contiene il DC

          //Estraggo i dati del datagramma
          filepcap.Read(&datadatagram,DatagramLenght);
          if (filepcap.Read(&WorkingCount,2)!=2) break;
          if (WorkingCount>0)
            dirout=false;
          byteEstratti+=10+DatagramLenght+2;
        }
      }

      if (data_LRW>0) {
        //block number
        rigacsv=wxString::Format(wxT("%d"),(uint16_t)blocchi);

        rigacsv+=";";
        //direction
        if (dirout==true)
        {
          rigacsv+="M => S;";
        }
        else {
          rigacsv+="M <= S;";
        }
        //WorkingCount
        rigacsv+=wxString::Format(wxT("%d;"),(uint16_t)WorkingCount);
        //note
        rigacsv+=" ;";
        //errors
        rigacsv+=" ";


        for (unsigned int i=0; i<ArrayPDO.GetCount(); i++) {
          if (ArrayPDO[i].enabled==false)
            continue;
          if (ArrayPDO[i].out==dirout)
          {
            filepcap.Seek(puntoB+ArrayPDO[i].PDO_offset);
            if (ArrayPDO[i].PDO_bytes==64) {
              filepcap.Read(&ui64,8);
              if  (SettingDialog->format64in==0) {
         //       str1=wxString::Format(wxT("%d"),ui64);
              }
              else if (SettingDialog->format64in==1) {
         //       str1=wxString::Format(wxT("%016X"),ui64);
              }
              else {
         //       str1=wxString::Format(wxT("0x%016X"),ui64);
              }
          }
            else if (ArrayPDO[i].PDO_bytes==32) {
              filepcap.Read(&ui32,4);
            str1=wxString::Format(wxT("%d"),ui32);

              if  (SettingDialog->format32in==0) {
                str1=wxString::Format(wxT("%d"),ui32);
              }
              else if (SettingDialog->format32in==1) {
                str1=wxString::Format(wxT("0x%08X"),ui32);
              }
              else {
                str1="b";
                for (int i=0;i<32;i++)
                {
                  if (ui32&0x80000000)
                    str1=str1+"1";
                  else
                    str1=str1+"0";
                  ui32=ui32<<1;
                }
              }

            }
            else if (ArrayPDO[i].PDO_bytes==16) {
              filepcap.Read(&ui16,2);
              if  (SettingDialog->format16in==0) {
                str1=wxString::Format(wxT("%d"),ui16);
              }
              else if (SettingDialog->format16in==1) {
                str1=wxString::Format(wxT("0x%04X"),ui16);
              }
              else {
                str1="b";
                for (int i=0;i<16;i++)
                {
                  if (ui16&0x8000)
                    str1=str1+"1";
                  else
                    str1=str1+"0";
                  ui16=ui16<<1;
                }
             }
            }
            else {
              filepcap.Read(&ui8,1);
              str1=wxString::Format(wxT("%d"),ui8);
              if  (SettingDialog->format8in==0) {
                str1=wxString::Format(wxT("%d"),ui8);
              }
              else if (SettingDialog->format8in==1) {
                str1=wxString::Format(wxT("0x%02X"),ui8);
              }
              else {
                str1="b";
                for (int i=0;i<8;i++)
                {
                  if (ui8&0x80)
                    str1=str1+"1";
                  else
                    str1=str1+"0";
                  ui8=ui8<<1;
                }
              }
            }
          }
          else
          {
            str1="";
          }
          rigacsv+=";";
          rigacsv+=str1;
        }
        rigacsv+="\n";
        filecsv.Write(rigacsv);
      }
    }

    blocchi++;
    punto+=BlockLength;

    //dirout=!dirout;
  }
  filecsv.Close();
  wxString messa;
  messa.Printf("Blocks managed:%i",blocchi);
  wxMessageBox(messa,wxT("- Finish -"),wxICON_INFORMATION);

}



void ecaDialog::OnBitmapButton1Click(wxCommandEvent& event)
{
  FilterDataDialog->ShowModal();
}

void ecaDialog::OnBitmapButton2Click(wxCommandEvent& event)
{
  FilterPDODialog->ShowModal();
}

void ecaDialog::OnBitmapButton3Click(wxCommandEvent& event)
{
  SettingDialog->ShowModal();
}

void ecaDialog::OnButton5Click(wxCommandEvent& event)
{
  AboutDialog->ShowModal();
}

void ecaDialog::OnButton1Click(wxCommandEvent& event)
{
}
