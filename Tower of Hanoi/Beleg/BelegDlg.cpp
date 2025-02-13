
// BelegDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "Beleg.h"
#include "BelegDlg.h"
#include "afxdialogex.h"
#include "CGame.h"
//#include "CGame.h"

//#include "CGame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CBelegDlg-Dialogfeld



CBelegDlg::CBelegDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BELEG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBelegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBelegDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CBelegDlg-Meldungshandler

BOOL CBelegDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (!m_bkg.Load("background.BMP")) { //Load background File
		AfxMessageBox(L"konnte background.BMP nicht laden");
		OnCancel();
	}

	if (!m_button[0].Load("buttons_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button[0].SetZ(100);
	m_button[0].SetPosition(70, 60);
	m_button[0].SetSpriteNumber(0, 0);


	if (!m_button[1].Load("buttons_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button[1].SetZ(100);
	m_button[1].SetPosition(70, 150);
	m_button[1].SetSpriteNumber(0, 2);

	if (!m_button[2].Load("buttons_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button[2].SetZ(100);
	m_button[2].SetPosition(70, 240);
	m_button[2].SetSpriteNumber(0, 4);

	if (!m_button[3].Load("buttons_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button[3].SetZ(100);
	m_button[3].SetPosition(70, 330);
	m_button[3].SetSpriteNumber(0, 6);

	if (!about.Load("about.BMP", CSize(400, 300))) {
		AfxMessageBox(L"konnte about.BMP nicht laden");
		OnCancel();
	}
	about.SetZ(200);
	about.SetPosition(1000, 1000);

	if (!m_button2[0].Load("buttons2_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons2_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button2[0].SetZ(100);
	m_button2[0].SetPosition(1000, 1000);
	m_button2[0].SetSpriteNumber(0, 0);

	if (!m_button2[1].Load("buttons2_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons2_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button2[1].SetZ(100);
	m_button2[1].SetPosition(1000, 1000);
	m_button2[1].SetSpriteNumber(0, 2);

	if (!m_button2[2].Load("buttons2_111x31.BMP", CSize(111, 31))) {
		AfxMessageBox(L"konnte buttons2_111x31.BMP nicht laden");
		OnCancel();
	}
	m_button2[2].SetZ(100);
	m_button2[2].SetPosition(1000, 1000);
	m_button2[2].SetSpriteNumber(0, 6);

	if (!icon.Load("icon.bmp", CSize(75, 112))) {
		AfxMessageBox(L"konnte icon.bmp nicht laden");
		OnCancel();
	}
	icon.SetZ(200);
	icon.SetPosition(1000, 1000);
	icon.SetSpriteNumber(0, 0);

	if (!count.Load("Count.bmp", CSize(130,60))) {
		AfxMessageBox(L"konnte Count.bmp nicht laden");
		OnCancel();
	}
	count.SetZ(200);
	count.SetPosition(1000, 1000);
	count.SetSpriteNumber(0, 0);

	if (!zahlen.Load("Zahlen.bmp", CSize(44,44))) {
		AfxMessageBox(L"konnte Zahlen.bmp nicht laden");
		OnCancel();
	}
	zahlen.SetZ(200);
	zahlen.SetPosition(1000, 1000);
	zahlen.SetSpriteNumber(0, 0);
	
	

	SetWindowPos(NULL, 0, 0,
		m_bkg.DibWidth(), // Fensterbreite								Fenstergröße einstellen
		m_bkg.DibHeight() + 25, // Fensterhöhe
		SWP_NOZORDER | SWP_NOMOVE);

	m_bkg.SetZ(0);
	m_buff.Load("background.bmp");
	m_list.SetWorkspace(&m_buff);
	m_list.Insert(&m_bkg);
	m_list.Insert(&m_button[0]);
	m_list.Insert(&m_button[1]);
	m_list.Insert(&m_button[2]);
	m_list.Insert(&m_button[3]);
	m_list.Insert(&m_button2[0]);
	m_list.Insert(&m_button2[1]);
	m_list.Insert(&m_button2[2]);
	m_list.Insert(&about);
	m_list.Insert(&icon);
	m_list.Insert(&count);
	m_list.Insert(&zahlen);
	SetTimer(1, 80, NULL); //war 50





	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CBelegDlg::OnPaint()
{
	CPaintDC dc(this); // Gerätekontext zum Zeichnen
	if (IsIconic())
	{
		
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		m_list.RedrawAll(&dc, 0, 0);
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CBelegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBelegDlg::OnTimer(UINT_PTR nIDEvent)			//logo bewegt sich
{
	static int i = 0; static bool oben = TRUE;
	CClientDC dc(this);

	if (oben){
		icon.SetSpriteNumber(i % 4, 0);  i++;
		if (i % 4 == 0)
			oben = FALSE;
	}
	
	else {
		icon.SetSpriteNumber(i % 4, 1); i++;
			if (i % 4 == 0)
			oben = TRUE;
}
	m_list.Update(&dc, 0, 0);
 }



void CBelegDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	CClientDC dc(this);
	CSprite* hit = m_list.HitTest(point);
	if (hit == &m_button[0]) { // if mouse hit my sprite
		m_button[0].SetSpriteNumber(0, 1);
	}
	else {
		m_button[0].SetSpriteNumber(0, 0);
	}

	if (hit == &m_button[1]) { // if mouse hit my sprite
		m_button[1].SetSpriteNumber(0, 3);
	}
	else {
		m_button[1].SetSpriteNumber(0, 2);
	}

	if (hit == &m_button[2]) { // if mouse hit my sprite
		m_button[2].SetSpriteNumber(0, 5);
	}
	else {
		m_button[2].SetSpriteNumber(0, 4);
	}

	if (hit == &m_button2[0]) { // if mouse hit my sprite        optionsknöpfe
		m_button2[0].SetSpriteNumber(0, 1);
	}
	else {
		m_button2[0].SetSpriteNumber(0, 0);
	}

	if (hit == &m_button2[1]) { // if mouse hit my sprite
		m_button2[1].SetSpriteNumber(0, 3);
	}
	else {
		m_button2[1].SetSpriteNumber(0, 2);
	}
	if (dd) {
	//Drag and Drop
	CSize offset; // offset of mousemove CSize(Breite, Höhe)
	CPoint moveto; // destination point of sprite 
	if (m_Captured && (nFlags & MK_RBUTTON)) { // if sprite captured ?
		offset = point - m_mousePos; // differenz to formal position
		moveto = m_Captured->GetPos() + offset; // add offset
		m_Captured->SetPosition(moveto.x, moveto.y);// new position
		m_mousePos = point; // store mouse position
	}
	else {
		m_Captured = NULL; // uncapture sprite
	}
}


	m_list.Update(&dc, 0, 0);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CBelegDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	CClientDC dc(this);
	CSprite* hit = m_list.HitTest(point);
	if (hit == &m_button[0]) { // if mouse hit my sprite				//spiel

		icon.SetPosition(660,25); //icon laden
		count.SetPosition(20, 18);
		zahlen.SetPosition(150, 23);
		about.SetPosition(1000,1000);
					   
		TowerofHanoi.GameInit(m_list);//spiel initialisieren
		

		///////////////			Menu aus dem Weg
			   
		m_button[0].SetPosition(1000, 1000);
		m_button[1].SetPosition(1000, 1000);
		m_button[2].SetPosition(1000, 1000);
		m_button[3].SetPosition(1000, 1000);
		//////////////			Das Spiel kann beginnen!
	}
	else if (hit == &m_button[1]) { // if mouse hit my sprite			//about bild einfügen
		if (about.GetXPos() == 165)
		about.SetPosition(1000, 1000);
		else
		about.SetPosition(165, 160);
	}
	
	else if (hit == &m_button[2]) { // if mouse hit my sprite			//optionen
		m_button[0].SetPosition(1000, 1000);
		m_button[1].SetPosition(1000, 1000);
		m_button[2].SetPosition(1000, 1000);
		m_button[3].SetPosition(1000, 1000);
		m_button2[0].SetPosition(70, 60);
		m_button2[1].SetPosition(70, 150);
		m_button2[2].SetPosition(70,240);
	}
	else if (hit == &m_button[3]) { // if mouse hit my sprite			//exit
		OnOK(); //exit dialog
	}

	else if (hit == &m_button2[2]) { // if mouse hit my sprite			//zurück
		m_button2[0].SetPosition(1000, 1000);
		m_button2[1].SetPosition(1000, 1000);				//hauptmenu
		m_button2[2].SetPosition(1000, 1000);
		if(links) {
		m_button[0].SetPosition(70, 60);
		m_button[1].SetPosition(70, 150);
		m_button[2].SetPosition(70, 240);
		m_button[3].SetPosition(70, 330);
		}
		else {
		m_button[0].SetPosition(600, 60);
		m_button[1].SetPosition(600, 150);
		m_button[2].SetPosition(600, 240);
		m_button[3].SetPosition(600, 330);

		}
	}

	else if (hit == &m_button2[0]) { // if mouse hit my sprite			//left/right Menue
		if (links)
			links = FALSE;
		else
			links = TRUE;
	}

	else if (hit == &m_button2[1]) {									//Drag and Drop an/aus
		if (dd)
			dd = FALSE;
		else
			dd = TRUE;
		}

	//Großer Block für das Bewegen der Scheiben										
	else if (TowerofHanoi.hittest(hit)) {						//Turm angeklickt?	
		if (m_captured != NULL) {								//bereits ein captured vorhanden
			From = TowerofHanoi.Wichtower(m_captured);			//From Und To Turmzeiger initialisieren
			To = TowerofHanoi.Wichtower(hit);
			if ( From != To) {				// nicht vom selben nehmen an den man gibt	
				if (From->GetAnz() != 0 && To->GetAnz() != 3) {		//nicht von leerem Turm und nicht auf vollen Turm
					if (From->GetSize() < To->GetSize()) {			//Groesse der Scheiben wird ueberprueft		
																	
						static int j = 0;
						TowerofHanoi.Add(From->GetDisk(), To);		//Scheibe bei To hinzufügen
						TowerofHanoi.Remove(From);					//Scheibe bei From abziehen
						j++;
						zahlen.SetSpriteNumber(j, 0);				//Zugzaehler weiterzaehlen
						m_captured = NULL;
						if (TowerofHanoi.GameOver())				//Siegbedingung checken
						{
							OnOK();
							AfxMessageBox(L"Sieg! Du hast das Spiel gewonnen! (:");
						}
					}
						else 
					AfxMessageBox(L"Du kannst nur kleinere auf groessere Scheiben legen. Versuche es nochmal! (:");		
					m_captured = NULL;				
				}
				else {
					AfxMessageBox(L"Es wurde von einem leeren Turm genommen oder an einen vollen Turm gegeben! Versuche es nochmal! (:");
					m_captured = NULL;}	
			}
			else {
				AfxMessageBox(L"Du kannst keine scheiben auf den selben Turm legen, von dem du nimmst. Versuche es nochmal! (:");
				m_captured = NULL;
			}																	//Bei fehlerhaftem Klick captured auf NULL setzen
		} 
		else 
				m_captured = hit;}												//Noch kein captured vorhanden, angeklicketes wird zu captured
	

	else m_captured = NULL;														//wird gar kein Turm angeklickt wird captured auch auf NULL gesetzt

	m_list.Update(&dc, 0, 0);
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CBelegDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.
	if (dd) {
	CSprite* hit = m_list.HitTest(point);						//Drag and Drop fuer ICON
	if (hit == &icon) { // if mouse hit my sprite
		m_Captured = hit; // sprite is captured
		m_mousePos = point; // store mouse position
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);

}
