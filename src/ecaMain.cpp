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
#include "ecaLogo.xpm"
#include <wx/msgdlg.h>
#include <wx/xml/xml.h>
#include <wx/file.h>
#include <wx/progdlg.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

#include <wx/msgdlg.h>

WX_DEFINE_OBJARRAY(PDOArray);
WX_DEFINE_OBJARRAY(SLVArray);

PDOArray ArrayPDO;
SLVArray ArraySlaves;


//(*InternalHeaders(ecaFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(ecaFrame)
const long ecaFrame::ID_STATICTEXT1 = wxNewId();
const long ecaFrame::ID_TEXTCTRL1 = wxNewId();
const long ecaFrame::ID_STATICTEXT2 = wxNewId();
const long ecaFrame::ID_TEXTCTRL2 = wxNewId();
const long ecaFrame::ID_TEXTCTRL3 = wxNewId();
const long ecaFrame::ID_MENUITEM1 = wxNewId();
const long ecaFrame::ID_MENUITEM2 = wxNewId();
const long ecaFrame::ID_MENUITEM6 = wxNewId();
const long ecaFrame::idMenuQuit = wxNewId();
const long ecaFrame::ID_MENUITEM3 = wxNewId();
const long ecaFrame::ID_MENUITEM4 = wxNewId();
const long ecaFrame::ID_MENUITEM5 = wxNewId();
const long ecaFrame::ID_MENUITEM7 = wxNewId();
const long ecaFrame::idMenuAbout = wxNewId();
const long ecaFrame::ID_STATUSBAR1 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM1 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM2 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM3 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM4 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM6 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM5 = wxNewId();
const long ecaFrame::ID_TOOLBARITEM7 = wxNewId();
const long ecaFrame::ID_TOOLBAR1 = wxNewId();
const long ecaFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaFrame,wxFrame)
    //(*EventTable(ecaFrame)
    //*)
END_EVENT_TABLE()

ecaFrame::ecaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ecaFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Ecang"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE, _T("id"));
    SetMinSize(wxSize(550,450));
    wxFont thisFont(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    SetExtraStyle( GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
    {
      wxIcon FrameIcon;
      FrameIcon.CopyFromBitmap(wxBitmap(ecaLogo64_xpm));
      SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ENI"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(BoxSizer3, 1, wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("PCAPNG"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer4->Add(TextCtrl2, 1, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(BoxSizer4, 1, wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2|wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer1->Add(TextCtrl3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    Menu3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Load ENI"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(Menu3);
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Load PCAPNG"), _("Load PCAPNG file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem7 = new wxMenuItem(Menu1, ID_MENUITEM6, _("Clear"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu4 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu4, ID_MENUITEM3, _("Filter"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu4, ID_MENUITEM4, _("Option"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem5);
    Menu4->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu4, ID_MENUITEM5, _("Execute"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem6);
    MenuBar1->Append(Menu4, _("Build"));
    Menu2 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu2, ID_MENUITEM7, _("Help"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem8);
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxBORDER_DOUBLE, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT|wxTB_TOP|wxALWAYS_SHOW_SB, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("ENI"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Load ENI file"), wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARITEM2, _("PCAPNG"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Load PCAPNG file"), wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem3 = ToolBar1->AddTool(ID_TOOLBARITEM3, _("CLEAR"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_TOOLBAR), wxITEM_NORMAL, _("Clear"), wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBar1->AddSeparator();
    ToolBarItem4 = ToolBar1->AddTool(ID_TOOLBARITEM4, _("FILTER"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_TOOLBAR), wxITEM_NORMAL, _("Datagram filters"), wxEmptyString);
    ToolBarItem5 = ToolBar1->AddTool(ID_TOOLBARITEM6, _("OPTIONS"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_EXECUTABLE_FILE")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_EXECUTABLE_FILE")),wxART_TOOLBAR), wxITEM_NORMAL, _("Program options"), wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBar1->AddSeparator();
    ToolBarItem8 = ToolBar1->AddTool(ID_TOOLBARITEM5, _("EXECUTE"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GOTO_LAST")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GOTO_LAST")),wxART_TOOLBAR), wxITEM_NORMAL, _("Go!"), wxEmptyString);
    ToolBar1->AddStretchableSpace();
    ToolBarItem10 = ToolBar1->AddTool(ID_TOOLBARITEM7, _("Help"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_HELP")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_HELP")),wxART_TOOLBAR), wxITEM_NORMAL, _("Help"), wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file XML"), wxEmptyString, wxEmptyString, _("*.xml"), wxFD_DEFAULT_STYLE|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file PCAPNG"), wxEmptyString, wxEmptyString, _("*.pcapng"), wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog3 = new wxFileDialog(this, _("Select file CSV"), wxEmptyString, wxEmptyString, _("*.csv"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1000, false);
    Fit();

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::OpenFileENI);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::OpenFilePcapng);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::Clear);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::OnQuit);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::ShowFilterDataDialog);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::ShowSettingDialog);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::Elabora);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ecaFrame::ShowAboutDialog);
    Connect(ID_TOOLBARITEM1,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::OpenFileENI);
    Connect(ID_TOOLBARITEM2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::OpenFilePcapng);
    Connect(ID_TOOLBARITEM3,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::Clear);
    Connect(ID_TOOLBARITEM4,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::ShowFilterDataDialog);
    Connect(ID_TOOLBARITEM6,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::ShowSettingDialog);
    Connect(ID_TOOLBARITEM5,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ecaFrame::Elabora);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&ecaFrame::OnTimer1Trigger);
    //*)

    SettingDialog = new ecaSetting(this);
    FilterPDODialog = new ecaPDOFilter(this);
    AboutDialog = new ecaABOUT(this);
}

ecaFrame::~ecaFrame()
{
    //(*Destroy(ecaFrame)
    FileDialog1->Destroy();
    FileDialog2->Destroy();
    FileDialog3->Destroy();
    //*)
}

void ecaFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}


/* -----------------------------------------------
 * Select, open and read all PDO's header from ENI
 * file. Data are stored in ArrayPDO and ArraySlaves
 * -----------------------------------------------*/
void ecaFrame::OpenFileENI(wxCommandEvent& event)
{

    FileDialog1->SetDirectory(SettingDialog->pathEni);
    if (FileDialog1->ShowModal() == wxID_OK)
    {
        FileEni=FileDialog1->GetPath();
        SettingDialog->pathEni=FileDialog1->GetDirectory();
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

    str1=_("Open file: ")+FileEni+"\n";
    TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
    TextCtrl3->AppendText(str1);
    TextCtrl3->Refresh();

////    BitmapButton2->Disable();

    ecaPDO PdoTmp;
    ecaSlaves SlvTmp;
    long int longtmp;
    uint16_t maxbytes=0;
    int slaves=0;
    int pdoin=0;
    int pdout=0;

    ArrayPDO.Clear();
    ArraySlaves.Clear();

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
                                    maxbytes=(int16_t) (longtmp/8)*2;  //need double
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
                                            if(not(longtmp%8 == 0))
                                            {
                                                PdoTmp.PDO_offset=32000;  //se non allineato al byte lo salto
                                            }
                                            else
                                            {
                                                PdoTmp.PDO_offset=(int16_t)(longtmp/8);
                                            }
                                        }
                                        child_liv5=child_liv5->GetNext();
                                    }
                                    if ((PdoTmp.PDO_offset>0) && (PdoTmp.PDO_offset<maxbytes))
                                    {
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
                                    maxbytes=(int16_t) (longtmp/8)*2; //need double!
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
                                    if ((PdoTmp.PDO_offset>0) && (PdoTmp.PDO_offset<maxbytes))
                                    {
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
                if (str1=="Slave")
                {
                    child_liv3=child_liv2->GetChildren();
                    str1=child_liv3->GetName();
                    if (str1=="Info")
                    {
                        child_liv4=child_liv3->GetChildren();
                        while (child_liv4)
                        {
                            str1=child_liv4->GetName();
                            str2=child_liv4->GetNodeContent();
                            if (str1=="Name")
                            {
                                SlvTmp.Slave_name=str2;
                            }
                            if (str1=="PhysAddr")
                            {
                                str2.ToLong(&longtmp);
                                SlvTmp.Slave_addr=(int16_t) longtmp;
                                if (SlvTmp.Slave_name!="")
                                {
                                    slaves++;
                                    ArraySlaves.Add(SlvTmp);
                                }
                                SlvTmp.Slave_name="";
                            }
                            child_liv4=child_liv4->GetNext();
                        }
                        child_liv3=child_liv3->GetNext();
                    }
                }
                child_liv2=child_liv2->GetNext();
            }
        }
        child_liv1=child_liv1->GetNext();
    }

    for (unsigned int i=0; i<ArraySlaves.GetCount(); i++)
    {
      ArraySlaves[i].Slave_incr=slaves-i;
    }

    str1.Printf(_(" Found %i slaves\n"),slaves);
    TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
    TextCtrl3->AppendText(str1);
    str1.Printf(_(" Found %i PDO Inputs\n"),pdoin);
    TextCtrl3->AppendText(str1);
    str1.Printf(_(" Found %i PDO Outputs\n"),pdout);
    TextCtrl3->AppendText(str1);
    TextCtrl3->ShowPosition(TextCtrl3->GetLastPosition());
    TextCtrl3->Refresh();
    TextCtrl3->Update();

////    if (pdoin>0 || pdout>0)
////        BitmapButton2->Enable();


}


/*--------------------------------------------------
 * Select PCAPNG file and put his name into
 * FilePcapng string
 * -------------------------------------------------*/
void ecaFrame::OpenFilePcapng(wxCommandEvent& event)
{
    wxString file,str1;
    FileDialog2->SetDirectory(SettingDialog->pathPca);
    if (FileDialog2->ShowModal() == wxID_OK)
    {
        FilePcapng=FileDialog2->GetPath();
        SettingDialog->pathPca=FileDialog2->GetDirectory();
        TextCtrl2->SetValue(FilePcapng);
        str1=_("Open file: ")+FilePcapng+"\n";
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
        TextCtrl3->AppendText(str1);
        PreElabora();
    }
}

/*--------------------------------------------------
 * Read PCAPNG file data just to find Master/Slaves
 * addresses and define timing limits
 * -------------------------------------------------*/
void ecaFrame::PreElabora(void)
{
    BLOCK_HEADER BlockHeader;
    EPB_PART1_HEADER EpbPart1Header;
    EPB_PART2_HEADER EpbPart2Header;
    DATAGRAM_HEADER DatagramHeader;

    MacSourceDirIn.part_1=0;
    MacSourceDirIn.part_2=0;
    MacSourceDirIn.part_3=0;

    wxFile filepcap;
    wxString str1;

    wxFileOffset punto=0;
    wxFileOffset puntoC=0;

    uint16_t byteEstratti=0;
    uint16_t WorkingCount=0;
    uint16_t DatagramLenght=0;

    uint32_t blocchi=0,blocknr=0;
    uint32_t ui32=0;
    int32_t offs=0;
    uint16_t ui16;
    uint8_t ui8;
    bool mac_found=false;

    if (!filepcap.Open(FilePcapng,wxFile::read))
        return;


    //First check if at the end there is a "Statistic block"
    filepcap.Seek(-4,wxFromEnd);
    filepcap.Read(&offs,4);
    filepcap.Seek(-offs,wxFromEnd);
    filepcap.Read(&ui32,4);
    if (ui32==0x0005)
    {
      filepcap.Read(&ui32,4); //lenght
      filepcap.Read(&ui32,4); //interface id
      filepcap.Read(&ui32,4); //timestamo H
      filepcap.Read(&ui32,4); //timestamp L
      while (filepcap.Eof()==0)
      {
        filepcap.Read(&ui16,2); //option
       if (ui16==0x0004)
        {
           filepcap.Read(&ui16,2); //lenght
           filepcap.Read(&blocknr,4);
          break;
        }
        filepcap.Read(&ui16,2); //lenght
        for (uint16_t i=0; i<ui16; i++)
          filepcap.Read(&ui8,1);
      }
    }


    //Ciclo su file
    while (filepcap.Eof()==0)
    {
        wxYield();
        //Estrazione blocchi file pcapng
        filepcap.Seek(punto,wxFromStart);

        //lettura tipo e lunghezza blocco
        if (filepcap.Read(&BlockHeader,8)!=8) break;

        if (!mac_found)
        {

        //blocco Enhanced packet 0x00000006 (EPB)
        if (BlockHeader.BlockType==0x00000006)
        {
            if (filepcap.Read(&EpbPart1Header,20)!=20) break;

            uint16_t EthercatFrameLenght;

            if (filepcap.Read(&EpbPart2Header,16)!=16) break;

            EthercatFrameLenght=EpbPart2Header.EthercatHeader & 0x07FF;

            byteEstratti=0;

            //Se e' un frame ethercat ne analizzo i singoli datagram
            if (EpbPart2Header.Type==0xA488)
            {
;
                while (byteEstratti<EthercatFrameLenght)
                {

                    //qui inizia il giro estrazione Datagrams
                    //estraggo tutto l'header
                    if (filepcap.Read(&DatagramHeader,10)!=10) break;

                    //Da qui iniziano i data del datagramam
                    //Lo memorizzo
                    puntoC=filepcap.Tell();

                    DatagramLenght=DatagramHeader.Mix & 0x07FF;

                   filepcap.Seek(puntoC+DatagramLenght);
                    filepcap.Read(&WorkingCount,2);
                    if (WorkingCount>0)
                   {
                        MacSourceDirIn=EpbPart2Header.MacSource;
                        break;
                   }
                   byteEstratti+=10+DatagramLenght+2;
                }
            }
        }
        if (WorkingCount>0 && (blocchi>10000 || blocknr>0))
          {
          filepcap.Close();
          break;
          }
        }
        blocchi++;
        punto+=BlockHeader.BlockLength;
    }
    if (blocknr>0)
      str1=wxString::Format(_("Frames in the file: %i\n"),blocknr);
    else if (blocchi>10000)
      str1=wxString::Format(_("Frames in the file: >10000\n"));
    else
      str1=wxString::Format(_("Frames in the file: %i\n"),blocchi);
    TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
    TextCtrl3->AppendText(str1);
    if(MacSourceDirIn.part_1!=0 || MacSourceDirIn.part_2!=0 || MacSourceDirIn.part_3!=0)
    {
      str1=_("Master/Slaves mac address find...Done\n");
      TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
      TextCtrl3->AppendText(str1);
    }
    else
    {
      str1=_("Master/Slaves mac address find...FAIL\n");
      TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
      TextCtrl3->AppendText(str1);
    }


}


/*--------------------------------------------------
 * Clear eni-pcapng-log fields
 * -------------------------------------------------*/
void ecaFrame::Clear(wxCommandEvent& event)
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
}





/*--------------------------------------------------
 * Read PCAPNG file data and export to csv file
 * -------------------------------------------------*/
void ecaFrame::Elabora(wxCommandEvent& event)
{
    BLOCK_HEADER BlockHeader;
    EPB_PART1_HEADER EpbPart1Header;
    EPB_PART2_HEADER EpbPart2Header;
    DATAGRAM_HEADER DatagramHeader;
    MAILBOX_HEADER MailboxHeader;
    MAILBOX_SERVICE MailboxService;

    wxArrayString arrstr;
    arrstr.Add("12345679012345678901234567890",1000);

    uint32_t ui32;
    uint16_t ui16;
    uint64_t ui64;
    uint8_t ui8;
    int32_t i32;
    bool dirout=true;
    uint16_t Pdocol;
    wxString str1;
    wxString str2;
    wxString fileCSV;
    wxString rigacsv;
    wxString datagramdata;

    wxFile filecsv;
    wxFile filepcap;

    wxFileOffset punto=0;
    wxFileOffset puntoB=0;
    wxFileOffset puntoC=0;

    bool is_NOP;
    bool is_APRD;
    bool is_APWR;
    bool is_APRW;
    bool is_FPRD_REG;
    bool is_FPWR_REG;
    bool is_FPRD_SDO;
    bool is_FPWR_SDO;
    bool is_BRD;
    bool is_BWR;
    bool is_BRW;
    bool is_LRD;
    bool is_LWR;
    bool is_LRW_PDO;
    bool is_ARMW;

    bool towrite;


    int blocchi=0;
    uint16_t byteEstratti;
    uint16_t WorkingCount;
    uint16_t DatagramLenght;
 //   char datadatagram[2048];
    int percento;
    uint16_t col=0;

    str1.Alloc(2000);
    rigacsv.Alloc(5000);

    int checked=0;

    if (ArrayPDO.GetCount()<1)
    {
        str1=_("Open a valid ENI file before Execute\n");
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
        TextCtrl3->AppendText(str1);
        return;
    }

    if (!filepcap.Open(FilePcapng,wxFile::read))
    {
        str1=_("PCAPNG file not found\nOpen a valid PCAPNG file before Execute\n");
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
        TextCtrl3->AppendText(str1);
        return;
    }

    for (int i=0; i<ArraySlaves.GetCount(); i++)
    {
        if (ArraySlaves[i].Reg_enable==true)
            checked++;
        if (ArraySlaves[i].Sdo_enable==true)
            checked++;
    }
    for (int i=0; i<ArrayPDO.GetCount(); i++)
    {
        if (ArrayPDO[i].enabled==true)
            checked++;
    }
    if (checked==0)
    {
        str1=_("Select at least one element in the Filter dialog before Execute\n");
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
        TextCtrl3->AppendText(str1);
        return;
    }


    long int sizepcap=filepcap.Length();
    FileDialog3->SetDirectory(SettingDialog->pathCsv);

    if (FileDialog3->ShowModal() == wxID_OK)
    {
        fileCSV=FileDialog3->GetPath();
        SettingDialog->pathCsv=FileDialog3->GetDirectory();
     }
    else
    {
        str1=_("Select a valid CSV to Execute\n");
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
        TextCtrl3->AppendText(str1);
        return;
    }

    if (!filecsv.Open(fileCSV,wxFile::write))
    {
        str1=_("CSV file open error\n");
        TextCtrl3->SetDefaultStyle(wxTextAttr(*wxRED));
        TextCtrl3->AppendText(str1);
        return;
    }

    wxFileOutputStream outfilecsv(filecsv);
    wxTextOutputStream outfile(outfilecsv);

    wxProgressDialog ProgrDialog(wxT("Progress"),
                                 wxT("Reading pcapng file"),
                                 100,
                                 this,
                                 wxPD_CAN_ABORT|wxPD_AUTO_HIDE);
//ProgressDialog1 = new wxProgressDialog(wxEmptyString, wxEmptyString, 100, this, wxPD_APP_MODAL|wxPD_AUTO_HIDE|wxPD_CAN_ABORT|wxPD_REMAINING_TIME);

    //header
    arrstr[0]="Block";
    arrstr[1]="Dir";
    arrstr[2]="workCnt";
    arrstr[3]="Note";
    arrstr[4]="Errors";
    col=5;

    str1=_("Execute running...\n");
    TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
    TextCtrl3->AppendText(str1);

    for (uint16_t i=0; i<ArraySlaves.GetCount(); i++)
    {
        if (ArraySlaves[i].Reg_enable==true)
        {
            ArraySlaves[i].Regcol=col;
            str1="REG-";
            str1+=(ArraySlaves[i].Slave_name);
            str2=str1+(".cmd");
            arrstr[col]=str2;
            col++;
            str2=str1+(".ado");
            arrstr[col]=str2;
            col++;
            str2=str1+(".val");
            arrstr[col]=str2;
            col++;
        }
        if (ArraySlaves[i].Sdo_enable==true)
        {
            ArraySlaves[i].Sdocol=col;
            str1="SDO-";
            str1+=(ArraySlaves[i].Slave_name);
            str2=str1+(".cmd");
            arrstr[col]=str2;
            col++;
            str2=str1+(".pro");
            arrstr[col]=str2;
            col++;
            str2=str1+(".ofs");
            arrstr[col]=str2;
            col++;
            str2=str1+(".obj");
            arrstr[col]=str2;
            col++;
            str2=str1+(".sse");
            arrstr[col]=str2;
            col++;
            str2=str1+(".sco");
            arrstr[col]=str2;
            col++;
            str2=str1+(".val");
            arrstr[col]=str2;
            col++;
        }
    }
    Pdocol=col;

//\  outfile<<wxT("Block;Dir;WorkCnt;Note;Errors");
    for (uint16_t i=0; i<ArrayPDO.GetCount(); i++)
    {
        if (ArrayPDO[i].enabled==false)
            continue;
        str1=ArrayPDO[i].PDO_name+wxString::Format(wxT(" %i"),ArrayPDO[i].PDO_bytes); //+" "+ArrayPDO[i].PDO_bytes;
        arrstr[col]=str1;
        col++;
//\   ecaPDO ep=ArrayPDO[i];
//\    outfile<<wxT(";");
//\    outfile<<ep.PDO_name;
//\    outfile<<wxT(" ");
//\    outfile<<ep.PDO_bytes;
//\    outfile<<wxT(" ");
//\    outfile<<ep.PDO_offset;
    }
    for (uint16_t i=0; i<col; i++)
    {
        outfile<<arrstr[i];
        outfile<<wxT(";");
    }
    outfile<<wxT("\n");

    //reset the array
    for (int i=0; i<500; i++)
        arrstr[i]="";


    Timer1.Start(1000);
    ticks=0;

    //Ciclo su file
    while (filepcap.Eof()==0)
    {
        wxYield();
        //Estrazione blocchi file pcapng
        filepcap.Seek(punto,wxFromStart);

        percento=(int)((((int)punto)*100)/sizepcap);
        if (!ProgrDialog.Update(percento))
        {
            break;
        }
        //lettura tipo e lunghezza blocco
        if (filepcap.Read(&BlockHeader,8)!=8) break;

        //blocco header 0x0A0D0D0A
        if (BlockHeader.BlockType==0x0A0D0D0A)
        {
        }
        //blocco Interface description 0x00000001
        if (BlockHeader.BlockType==0x00000001)
        {
        }
        //blocco Simple packet 0x00000003
        if (BlockHeader.BlockType==0x00000003)
        {
        }
        //blocco Name resolution block 0x00000004
        if (BlockHeader.BlockType==0x00000004)
        {
        }
        //blocco Interface statistic block 0x00000005
        if (BlockHeader.BlockType==0x00000005)
        {
        }
        //blocco Enhanced packet 0x00000006 (EPB)
        if (BlockHeader.BlockType==0x00000006)
        {
            if (filepcap.Read(&EpbPart1Header,20)!=20) break;

            //Da qui inizia il blocco di dati così come visualizzato da wireshark.
            //Gli offset dei PDO (espressi in bits) ricavati dal file XML si riferiscono a questo blocco
            //Lo memorizzo
            puntoB=filepcap.Tell();

            uint16_t EthercatFrameLenght;

            if (filepcap.Read(&EpbPart2Header,16)!=16) break;

            EthercatFrameLenght=EpbPart2Header.EthercatHeader & 0x07FF;

            //bool bip;

            byteEstratti=0;
            dirout=true;
            //Se e' un frame ethercat ne analizzo i singoli datagram
            if (EpbPart2Header.Type==0xA488)
            {

                towrite=false;
                while (byteEstratti<EthercatFrameLenght)
                {

                    is_NOP=false;
                    is_APRD=false;
                    is_APWR=false;
                    is_APRW=false;
                    is_FPRD_REG=false;
                    is_FPWR_REG=false;
                    is_FPRD_SDO=false;
                    is_FPWR_SDO=false;
                    is_BRD=false;
                    is_BWR=false;
                    is_BRW=false;
                    is_LRD=false;
                    is_LWR=false;
                    is_LRW_PDO=false;
                    is_ARMW=false;

                    //qui inizia il giro estrazione Datagrams
                    //estraggo tutto l'header
                    if (filepcap.Read(&DatagramHeader,10)!=10) break;

                    //Da qui iniziano i data del datagramam
                    //Lo memorizzo
                    puntoC=filepcap.Tell();

                    DatagramLenght=DatagramHeader.Mix & 0x07FF;

                    if(DatagramHeader.Command==0x00)  //NOP
                        is_NOP=true;
                    if(DatagramHeader.Command==0x01)  //Auto increment physical read
                        is_APRD=true;
                    if(DatagramHeader.Command==0x02)  //Auto increment physical write
                        is_APWR=true;
                    if(DatagramHeader.Command==0x03)  //Auto increment physical read write
                        is_APRW=true;

                    if(DatagramHeader.Command==0x04) //FPRD configured address physical read
                    {
                        if(DatagramHeader.Offset<0x1000)
                            is_FPRD_REG=true;    //lettura registro
                        else
                            is_FPRD_SDO=true;    //lettura SDO
                    }

                    if(DatagramHeader.Command==0x05)  //FPWR configured address physical write
                    {
                        if(DatagramHeader.Offset<0x1000)
                            is_FPWR_REG=true;    //scrittura registro
                        else
                            is_FPWR_SDO=true;    //scrittura SDO
                    }

                    if(DatagramHeader.Command==0x07)  //BRD broadcast read
                        is_BRD=true;

                    if(DatagramHeader.Command==0x08)  //BWR broadcast write
                        is_BWR=true;

                    if(DatagramHeader.Command==0x09)  //BRW broadcast read/write
                        is_BRW=true;

                    if(DatagramHeader.Command==0x0A)  //LRD logical read
                        is_LRD=true;

                    if(DatagramHeader.Command==0x0B)  //LWR logical write
                        is_LWR=true;

                    if(DatagramHeader.Command==0x0C)  //LRW logical read/write
                        is_LRW_PDO=true;   //qui ci sono i PDO

                    if(DatagramHeader.Command==0x0d)  //ARMW Auto increment physical  Read Multiple Write
                        is_ARMW=true; //contiene il DC

                    //Slaves to Master or viceversa
                    if(MacSourceDirIn.part_1==EpbPart2Header.MacSource.part_1 &&
                       MacSourceDirIn.part_2==EpbPart2Header.MacSource.part_2 &&
                       MacSourceDirIn.part_3==EpbPart2Header.MacSource.part_3)
                      dirout=0;
                    else
                      dirout=1;

                    //Estraggo i dati del datagramma
//questo lo devo togliere!!         filepcap.Read(&datadatagram,DatagramLenght); //per adesso questo serve solo a fare avanzare il puntatore al prossimo datagram
                    //       filepcap.Seek(DatagramLenght,wxFromCurrent);)

                    //mi sposto a fine datagram per leggere il WC da cui capisco la direzione
 //                   filepcap.Seek(puntoC+DatagramLenght);
  //                  filepcap.Read(&WorkingCount,2);
   //                 if (WorkingCount>0)
    //                    dirout=false;
     //               else
      //                  dirout=true;

                    //leggo subito in WorkingCount
                    filepcap.Seek(puntoC+DatagramLenght);
                    filepcap.Read(&WorkingCount,2);


                    //FPRD configured address physical read
                    if ((is_FPRD_REG || is_APRD) && !dirout)
                    {
                        filepcap.Seek(puntoC);

                        datagramdata="";
                        for (int j=0; j<DatagramLenght; j++)
                        {
                            filepcap.Read(&ui8,1);
                            datagramdata+=wxString::Format(" %02X",ui8);
                            if (j>30)
                            {
                                datagramdata+="...";
                                break;
                            }
                        }

                        for (unsigned int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                            if (((ArraySlaves[i].Slave_addr==DatagramHeader.Address && is_FPRD_REG) ||
                                (ArraySlaves[i].Slave_incr==DatagramHeader.Address && is_APRD)) &&
                              ArraySlaves[i].Reg_enable)
                            {
                                int u=ArraySlaves[i].Regcol;
                                if (is_FPRD_REG) {
                                  arrstr[u]=wxT("FpRD");
                                }
                                else if (is_APRD) {
                                  arrstr[u]=wxT("ApRD");
                                }
//                                else
//                                  arrstr[u]=wxT("BRD");
                                arrstr[++u]=wxString::Format("0x%X",DatagramHeader.Offset);
                                arrstr[++u]="h";
                                arrstr[u]+=datagramdata;
                                /*
                                for (int j=0; j<DatagramLenght; j++)
                                {
                                    filepcap.Read(&ui8,1);
                                    arrstr[u]+=wxString::Format(" %02X",ui8);
                                    if (j>30)
                                    {
                                        arrstr[u]+="...";
                                        break;
                                    }
                                }
                                */
                                towrite=true;

                            }
                        }

                    }
                    //FPWR configured address physical write
                    if ((is_FPWR_REG || is_APWR || is_BWR) && !dirout)
                    {
                        filepcap.Seek(puntoC);

                        datagramdata="";
                        for (int j=0; j<DatagramLenght; j++)
                        {
                            filepcap.Read(&ui8,1);
                            datagramdata+=wxString::Format(" %02X",ui8);
                            if (j>30)
                            {
                                datagramdata+="...";
                                break;
                            }
                        }

                        for (unsigned int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                           if (((ArraySlaves[i].Slave_addr==DatagramHeader.Address && (is_FPWR_REG || is_BWR) ) ||
                                (ArraySlaves[i].Slave_incr==DatagramHeader.Address && is_APWR)) &&
                                ArraySlaves[i].Reg_enable)
                              {
                                int u=ArraySlaves[i].Regcol;
                                if (is_FPWR_REG) {
                                  arrstr[u]=wxT("FpWR");
                                }
                                else if (is_APWR) {
                                  arrstr[u]=wxT("ApWR");
                                }
                               else if (is_BWR) {
                                  arrstr[u]=wxT("BWR");
                               }
                                arrstr[++u]=wxString::Format("0x%X",DatagramHeader.Offset);
                                arrstr[++u]="h";
                                arrstr[u]+=datagramdata;
                                /*
                                for (int j=0; j<DatagramLenght; j++)
                                {
                                    filepcap.Read(&ui8,1);
                                    arrstr[u]+=wxString::Format(" %02X",ui8);
                                    if (j>30)
                                    {
                                        arrstr[u]+="...";
                                        break;
                                    }
                                }
                                */
                                towrite=true;
                            }
                        }
                        if (is_BWR && towrite)
                        {
                            //write to file
                           //block number
                            i32=blocchi-1;
                            arrstr[0]=wxString::Format(wxT("%i"),i32);
                            for (int i=0; i<col; i++)
                            {
                              outfile<<arrstr[i];
                              outfile<<wxT(";");
                            }
                            outfile<<wxT("\n");

                            //reset the array
                            for (int i=0; i<col; i++)
                                arrstr[i]="";
                            towrite=false;
                        }
                    }
                    //FPRD configured address physical read
                    if (is_FPRD_SDO && !dirout)
                    {
                        filepcap.Seek(puntoC);
                        filepcap.Read(&MailboxHeader,6);
                        filepcap.Read(&MailboxService,6);


                        for (unsigned int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                            if (ArraySlaves[i].Slave_addr==DatagramHeader.Address  && ArraySlaves[i].Sdo_enable)
                            {
                                int u=ArraySlaves[i].Sdocol;
                                arrstr[u]=wxT("FpRD");
                                if((MailboxHeader.Mix & 0x0F00) == 0x0300)
                                {
                                    arrstr[++u]="CoE";
                                    arrstr[++u]=wxString::Format("0x%04X",DatagramHeader.Offset);
                                    arrstr[++u]=wxString::Format("0x%04X.%X",MailboxService.Object,MailboxService.Subindex);
                                    ui8=MailboxService.Mix1>>12;
                                    arrstr[++u]=wxString::Format("0x%02X",ui8);
                                    ui8=MailboxService.Mix2;
                                    arrstr[++u]=wxString::Format("0x%02X",ui8);
                                    int k=0;
                                    if ((ui8==0x2F) || (ui8==0x4F))
                                        k=1;
                                    else if ((ui8==0x2B) || (ui8==0x4B))
                                        k=2;
                                    else if ((ui8==0x27) || (ui8==0x47))
                                       k=3;
                                    else if ((ui8==0x23) || (ui8==0x43))
                                        k=4;
//                                    else if ((ui8==0x22) || (ui8==0x21) || (ui8==0x42) || (ui8==0x41))
//                                        k=8;
                                    else if (ui8==0x60)
                                        k=0;
                                    else if (ui8==0x80)
                                        k=4;
                                   if (k>0)
                                        arrstr[++u]="h";
                                    for (int j=0; j<k; j++)
                                    {
                                        filepcap.Read(&ui8,1);
                                        arrstr[u]+=wxString::Format(" %02X",ui8);
                                    }
                                }
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0200)
                                    arrstr[++u]="EoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0100)
                                    arrstr[++u]="AoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0800)
                                    arrstr[++u]="FoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x1000)
                                    arrstr[++u]="SoE";
                                else
                                    arrstr[++u]="---";

                                towrite=true;
                            }
                        }


                    }
                    //FPWR configured address physical write
                    if (is_FPWR_SDO && !dirout)
                    {
                        filepcap.Seek(puntoC);
                        filepcap.Read(&MailboxHeader,6);
                        filepcap.Read(&MailboxService,6);

                        for (unsigned int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                            if (ArraySlaves[i].Slave_addr==DatagramHeader.Address  && ArraySlaves[i].Sdo_enable)
                            {
                                int u=ArraySlaves[i].Sdocol;
                                arrstr[u]=wxT("FpWR");
                                if((MailboxHeader.Mix & 0x0F00) == 0x0300)
                                {
                                    arrstr[++u]="CoE";
                                    arrstr[++u]=wxString::Format("0x%04X",DatagramHeader.Offset);
                                    arrstr[++u]=wxString::Format("0x%04X.%X",MailboxService.Object,MailboxService.Subindex);
                                    ui8=MailboxService.Mix1>>12;
                                    arrstr[++u]=wxString::Format("0x%02X",ui8);
                                    ui8=MailboxService.Mix2;
                                    arrstr[++u]=wxString::Format("0x%02X",ui8);
                                    int k=0;
                                    if ((ui8==0x2F) || (ui8==0x4F))
                                        k=1;
                                    else if ((ui8==0x2B) || (ui8==0x4B))
                                        k=2;
                                    else if ((ui8==0x27) || (ui8==0x47))
                                        k=3;
                                    else if ((ui8==0x23) || (ui8==0x43))
                                        k=4;
// 0x21 initiate download                                   else if ((ui8==0x22) || (ui8==0x21) || (ui8==0x42) || (ui8==0x41))
// dopo subindex 4 byte lunghezza                                       k=8;
                                    else if (ui8==0x60)
                                        k=0;
                                    else if (ui8==0x80)
                                        k=4;

                                    if (k>0)
                                        arrstr[++u]="h";
                                    for (int j=0; j<k; j++)
                                    {
                                        filepcap.Read(&ui8,1);
                                        arrstr[u]+=wxString::Format(" %02X",ui8);
                                    }

                                }
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0200)
                                    arrstr[++u]="EoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0100)
                                    arrstr[++u]="AoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x0800)
                                    arrstr[++u]="FoE";
                                else if ((MailboxHeader.Mix & 0x0F00) == 0x1000)
                                    arrstr[++u]="SoE";
                                else
                                    arrstr[++u]="???";

                                towrite=true;
                            }
                        }
                    }

                    //LRW logical read/write
                    if (is_LRW_PDO && !dirout && WorkingCount>0)
                    {

                        for (unsigned int i=0; i<ArrayPDO.GetCount(); i++)
                        {
                            if (ArrayPDO[i].enabled==false)
                                continue;
                            int u=Pdocol+i;
                            towrite=true;
                            if (true) //(ArrayPDO[i].out==dirout)
                            {
                                filepcap.Seek(puntoB+ArrayPDO[i].PDO_offset);
                                if (ArrayPDO[i].PDO_bytes==64)
                                {
                                    filepcap.Read(&ui64,8);
                                    if  (SettingDialog->format64in==0)
                                    {
                                        arrstr[u]=wxString::Format(wxT("%i"),(signed)ui64);
                                    }
                                    else if (SettingDialog->format64in==1)
                                    {
                                        ui32=(uint32_t)(ui64>>32);
                                        str1=wxString::Format(wxT("0x%08X"),ui32);
                                        arrstr[u]=str1;
                                        ui32=(uint32_t)ui64;
                                        str1=wxString::Format(wxT("%08X"),ui32);
                                        arrstr[u]+=str1;
                                    }
                                    else
                                    {

                                        str1="b";
                                        for (int ii=0; ii<64; ii++)
                                        {
                                            if (ui64 & 0x8000000000000000)
                                                str1+="1";
                                            else
                                                str1+="0";
                                            ui64=ui64<<1;
                                        }
                                        arrstr[u]=str1;
                                    }
                                }
                                else if (ArrayPDO[i].PDO_bytes==32)
                                {
                                    filepcap.Read(&ui32,4);
                                    //outfile<<wxT(";");
                                    if  (SettingDialog->format32in==0)
                                    {
                                        str1=wxString::Format(wxT("%i"),ui32);
                                        arrstr[u]=str1;
                                    }
                                    else if (SettingDialog->format32in==1)
                                    {
                                        str1=wxString::Format(wxT("0x%08X"),ui32);
                                        arrstr[u]=str1;
                                    }
                                    else
                                    {
                                        str1="b";
                                        for (int ii=0; ii<32; ii++)
                                        {
                                            if (ui32 & 0x80000000)
                                                str1+="1";
                                            else
                                                str1+="0";
                                            ui32=ui32<<1;
                                        }
                                        arrstr[u]=str1;
                                    }

                                }
                                else if (ArrayPDO[i].PDO_bytes==16)
                                {
                                    filepcap.Read(&ui16,2);
                                    //          outfile<<wxT(";");
                                    if  (SettingDialog->format16in==0)
                                    {
                                        str1=wxString::Format(wxT("%i"),ui16);
                                        arrstr[u]=str1;
                                    }
                                    else if (SettingDialog->format16in==1)
                                    {
                                        str1=wxString::Format(wxT("0x%04X"),ui16);
                                        arrstr[u]=str1;
                                    }
                                    else
                                    {
                                        str1="b";
                                        for (int ii=0; ii<16; ii++)
                                        {
                                            if (ui16 & 0x8000)
                                                str1+="1";
                                            else
                                                str1+="0";
                                            ui16=ui16<<1;
                                        }
                                        arrstr[u]=str1;
                                    }
                                }
                                else
                                {
                                    filepcap.Read(&ui8,1);
                                    //          outfile<<wxT(";");
                                    if  (SettingDialog->format8in==0)
                                    {
                                        str1=wxString::Format(wxT("%i"),ui8);
                                        arrstr[u]=str1;
                                    }
                                    else if (SettingDialog->format8in==1)
                                    {
                                        str1=wxString::Format(wxT("0x%02X"),ui8);
                                        arrstr[u]=str1;
                                    }
                                    else
                                    {
                                        str1="b";
                                        for (int ii=0; ii<8; ii++)
                                        {
                                            if (ui8 & 0x80)
                                                str1+="1";
                                            else
                                                str1+="0";
                                            ui8=ui8<<1;
                                        }
                                        arrstr[u]=str1;
                                    }
                                }
                            }
                            else
                            {
                                arrstr[u]="";
                            }
                        }
                        //outfile<<endl;
                    }

                    //vado al prossimo datagram
                    filepcap.Seek(puntoC+DatagramLenght);
                    filepcap.Read(&WorkingCount,2);
                    byteEstratti+=(10+DatagramLenght+2);
                }

                if (towrite==true)
                {

                    //block number
                    i32=blocchi-1;
                    arrstr[0]=wxString::Format(wxT("%i"),i32);

                    //direction
                    if (dirout==true)
                        arrstr[1]=wxT("M => S");
                    else
                        arrstr[1]=wxT("M <= S");

                    //work counter
                    arrstr[2]=wxString::Format(wxT("%i"),WorkingCount);

                    //Note
                    arrstr[3]="";
                    //Errors
                    arrstr[4]="";

                    //write to file
                    for (int i=0; i<col; i++)
                    {
                        outfile<<arrstr[i];
                        outfile<<wxT(";");
                    }
                    outfile<<wxT("\n");

                    //reset the array
                    for (int i=0; i<col; i++)
                        arrstr[i]="";

                }

            }
        }

        blocchi++;
        punto+=BlockHeader.BlockLength;
    }
    filecsv.Close();

    str1=_("Execute terminate\n");
    TextCtrl3->SetDefaultStyle(wxTextAttr(*wxBLACK));
    TextCtrl3->AppendText(str1);

    wxString messa;
    messa.Printf(_("Blocks managed: %i \nElapsed time: %is"),blocchi,ticks);
    wxMessageBox(messa,_("- Finish -"),wxICON_INFORMATION);

}


void ecaFrame::ShowFilterDataDialog(wxCommandEvent& event)
{
    FilterPDODialog->ShowModal();
}


/*
void ecaFrame::OnBitmapButton2Click(wxCommandEvent& event)
{
    FilterPDODialog->ShowModal();
}
*/


void ecaFrame::ShowSettingDialog(wxCommandEvent& event)
{
    SettingDialog->ShowModal();
    SettingDialog->SaveSetting();
}

void ecaFrame::ShowAboutDialog(wxCommandEvent& event)
{
    AboutDialog->ShowModal();
}


void ecaFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    ticks++;
}
