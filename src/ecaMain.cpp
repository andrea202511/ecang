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
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

WX_DEFINE_OBJARRAY(PDOArray);
WX_DEFINE_OBJARRAY(SLVArray);

PDOArray ArrayPDO;
SLVArray ArraySlaves;


//(*InternalHeaders(ecaDialog)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
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
const long ecaDialog::ID_TIMER1 = wxNewId();
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
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrl1, 4, wxALL|wxEXPAND, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Disable();
    BoxSizer2->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Button2 = new wxButton(this, ID_BUTTON2, _("PCAPNG"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
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
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1000, false);
    Fit();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OpenFileENI);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton2Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OpenFilePcapng);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton1Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnButton5Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::Elabora);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDialog::OnBitmapButton3Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&ecaDialog::OnTimer1Trigger);
    //*)

    //MainCore = new ecaMainCore(this);
    SettingDialog = new ecaSetting(this);
    FilterPDODialog = new ecaPDOFilter(this);
    FilterDataDialog = new ecaDataFilter(this);
    AboutDialog = new ecaABOUT(this);
}

ecaDialog::~ecaDialog()
{
    //(*Destroy(ecaDialog)
    FileDialog1->Destroy();
    FileDialog2->Destroy();
    FileDialog3->Destroy();
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
    ecaSlaves SlvTmp;
    long int longtmp;
    uint16_t maxbytes;
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
                                    ArraySlaves.Add(SlvTmp);
                                    slaves++;
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
    str1.Printf(" Found %i slaves\n",slaves);
    TextCtrl3->AppendText(str1);
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
        str1="Open file: "+FilePcapng+"\n";
        TextCtrl3->AppendText(str1);
    }
}


/*--------------------------------------------------
 * Read PCAPNG file data and export to csv file
 * -------------------------------------------------*/
void ecaDialog::Elabora(wxCommandEvent& event)
{
    BLOCK_HEADER BlockHeader;
    EPB_PART1_HEADER EpbPart1Header;
    EPB_PART2_HEADER EpbPart2Header;
    DATAGRAM_HEADER DatagramHeader;
    MAILBOX_HEADER MailboxHeader;
    MAILBOX_SERVICE MailboxService;

    wxArrayString arrstr;
    arrstr.Add("12345679012345678901234567890",200);

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

    wxFile filecsv;
    wxFile filepcap;

    wxFileOffset punto=0;
    wxFileOffset puntoB=0;
    wxFileOffset puntoC=0;

    bool is_NOP;
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
    char datadatagram[2048];
    int percento;
    uint16_t col=0;

    str1.Alloc(2000);
    rigacsv.Alloc(5000);


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

    if (!filecsv.Open(fileCSV,wxFile::write))
        return;

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
    for (int i=0; i<200; i++)
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



                    //Estraggo i dati del datagramma
//questo lo devo togliere!!         filepcap.Read(&datadatagram,DatagramLenght); //per adesso questo serve solo a fare avanzare il puntatore al prossimo datagram
                    //       filepcap.Seek(DatagramLenght,wxFromCurrent);)

                    //mi sposto a fine datagram per leggere il WC da cui capisco la direzione
                    filepcap.Seek(puntoC+DatagramLenght);
                    filepcap.Read(&WorkingCount,2);
                    if (WorkingCount>0)
                        dirout=false;
                    else
                        dirout=true;
                    byteEstratti+=10+DatagramLenght+2;



                    //FPRD configured address physical read
                    if (is_FPRD_REG && !dirout)
                    {
                        filepcap.Seek(puntoC);
                        //           filepcap.Read(&MailboxHeader,6);
                        //          filepcap.Read(&MailboxService,10);
                        for (int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                            if (ArraySlaves[i].Slave_addr==DatagramHeader.Address  && ArraySlaves[i].Reg_enable)
                            {
                                int u=ArraySlaves[i].Regcol;
                                arrstr[u]=wxT("FpRD");
                                arrstr[++u]=wxString::Format("0x%X",DatagramHeader.Offset);
                                arrstr[++u]="h";
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

                                towrite=true;

                            }
                        }

                    }
                    //FPWR configured address physical write
                    if (is_FPWR_REG && dirout)
                    {
                        filepcap.Seek(puntoC);

                        //   filepcap.Read(&MailboxHeader,6);
                        // filepcap.Read(&MailboxService,10);
                        for (int i=0; i<ArraySlaves.GetCount(); i++)
                        {
                            if (ArraySlaves[i].Slave_addr==DatagramHeader.Address  && ArraySlaves[i].Reg_enable)
                            {
                                int u=ArraySlaves[i].Regcol;
                                arrstr[u]=wxT("FpWR");
                                arrstr[++u]=wxString::Format("0x%X",DatagramHeader.Offset);
                                arrstr[++u]="h";
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

                                towrite=true;
                            }
                        }
                    }
                    //FPRD configured address physical read
                    if (is_FPRD_SDO && !dirout)
                    {
                        filepcap.Seek(puntoC);
                        filepcap.Read(&MailboxHeader,6);
                        filepcap.Read(&MailboxService,6);


                        for (int i=0; i<ArraySlaves.GetCount(); i++)
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
                    //FPWR configured address physical write
                    if (is_FPWR_SDO && !dirout)
                    {
                        filepcap.Seek(puntoC);
                        filepcap.Read(&MailboxHeader,6);
                        filepcap.Read(&MailboxService,6);

                        for (int i=0; i<ArraySlaves.GetCount(); i++)
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
                    if (is_LRW_PDO && !dirout)
                    {

                        for (int i=0; i<ArrayPDO.GetCount(); i++)
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
                                        str1=wxString::Format(wxT("%08X"),ui32);
                                        outfile<<str1;
                                        ui32=(uint32_t)ui64;
                                        str1=wxString::Format(wxT("%08X"),ui32);
                                        arrstr[u]=str1;
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
    wxString messa;
    messa.Printf("Blocks managed: %i \nElapsed time: %is",blocchi,ticks);
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

void ecaDialog::OnTimer1Trigger(wxTimerEvent& event)
{
    ticks++;
}
