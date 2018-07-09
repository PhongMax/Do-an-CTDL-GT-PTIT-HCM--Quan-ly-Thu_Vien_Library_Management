#include "Ngay_Thang.h"

bool namNhuan(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) ||
		(year % 400 == 0));
}

int ngayHopLe(NGAY_THANG nt)
{
	// return 0 chi ngay sai, 1 chi thang sai , 2 chi nam sai va 3 chi ngay gio dung format
	
	if (nt.nam > MAX_NAM || nt.nam < MIN_NAM)
		return 2;
	if (nt.thang < 1 || nt.thang > 12)
		return 1;
	if (nt.ngay < 1 || nt.ngay > 31)
		return 0;

	// xu ly thang 2 voi nam  nhuan
	if (nt.thang == 2)
	{
		if (namNhuan(nt.nam))
		{
			if (nt.ngay > 29)
				return 0;
		}
		else
		{
			if (nt.ngay > 28)
			{
				return 0;
			}
		}
	}
	if ((nt.thang == 4 || nt.thang == 6 || nt.thang == 9 || nt.thang == 11) && (nt.ngay > 30))
	{
		return 0;
	}
	return 3;
}

void xuatNgayThang(NGAY_THANG dt, int x, int y)
{
	gotoxy(x, y);
	cout << dt.ngay << " /";
	gotoxy(x + 4, y);
	cout << dt.thang << " /";
	gotoxy(x + 8, y);
	cout << dt.nam;
}

void LayNgayGioHT(NGAY_THANG &d)
{
	//    int ngay,thang,nam ;
	tm today;
	time_t ltime;
	time(&ltime);
	// today = localtime( &ltime );
	localtime_s(&today, &ltime);
	d.ngay = today.tm_mday;
	d.thang = today.tm_mon + 1;
	d.nam = today.tm_year + 1900;
}

int LayNamHT()
{
	tm today;
	time_t ltime;
	time(&ltime);
	// today = localtime( &ltime );
	localtime_s(&today, &ltime);
	return (today.tm_year + 1900);
}

int tinhNgay(NGAY_THANG dt)
{
	if (dt.thang < 3) {
		dt.nam--;
		dt.thang += 12;
	}
	return 365 * dt.nam + dt.nam / 4 - dt.nam / 10 + dt.nam / 400 + (153 * dt.thang - 457) / 5 + dt.ngay - 306;
}

int KhoangCachNgay(NGAY_THANG nt1)
{
	NGAY_THANG nt2;
	LayNgayGioHT(nt2);
	return (tinhNgay(nt2) - tinhNgay(nt1));
}

int SoSanhNgay(NGAY_THANG nt1, NGAY_THANG nt2)
{
	return (tinhNgay(nt2) - tinhNgay(nt1));
}
