#define MAX 100

typedef char Chuoi[MAX];

//int StrLen(Chuoi s)
//{
//	return strlen(s);
//}

int ChieuDai(Chuoi s)
{
	int i;
	for (i = 0; s[i] != NULL; i++);
	return i;
}

//void StrRev(Chuoi s)
//{
//	_strrev(s);
//}

void DaoChuoi(Chuoi s)
{
	char t;
	for (int i = 0; i <= strlen(s) / 2; i++)
	{
		t = s[strlen(s) - 1 - i];
		s[strlen(s) - 1 - i] = s[i];
		s[i] = t;
	}
}

//void StrCpy(Chuoi s, Chuoi t)
//{
//	strcpy_s(t, MAX, s);
//}

void ChepChuoi(char * s, char * t)
{
	while (*s) {
		*(t++) = *(s++);
	}
	*t = '\0';
}

//int StrCmp(Chuoi s, Chuoi t) //Phan biet chu hoa
//{
//	return strcmp(s, t);
//}

int StrSum(Chuoi s)
{
	int sum = 0;
	for (int i = 0; i < strlen(s); i++)
		sum += (int)s[i];
	return sum;
}

char SoSanh_Co(Chuoi s, Chuoi t)
{
	if (StrSum(s)>StrSum(t))
		return '>';
	else if (StrSum(s) == StrSum(t))
		return '=';
	else return'<';
}

//int StrCmpi(Chuoi s, Chuoi t) //Khong phan biet chu hoa
//{
//	return _strcmpi(s, t);
//}

char SoSanh_Khong(Chuoi s, Chuoi t)
{
	Chuoi a, b;
	strcpy_s(a, MAX, s);
	strcpy_s(b, MAX, t);
	_strlwr_s(a);
	_strlwr_s(b);
	if (StrSum(a) > StrSum(b))
		return '>';
	else if (StrSum(a) == StrSum(b))
		return '=';
	else return '<';
}

//void StrCat(Chuoi s, Chuoi t)
//{
//	strcat_s(t, MAX, s);
//}

void NoiChuoi(Chuoi s, Chuoi t)
{
	while (*t) //Tro toi vi tri cuoi cung
	{
		*(t++);
	}
	while (*s) { //Tien hanh chen
		*(t++) = *(s++);
	}
	*t = NULL;
}