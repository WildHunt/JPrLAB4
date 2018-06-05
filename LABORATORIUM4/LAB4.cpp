#include <iostream>
#include <string>

class Student
{
protected:
	std::string imie;
	std::string nazwisko;
	int semestr;
	std::string kierunek;
	std::string numerIndeksu;
	int id;
public:
	Student()
	{
		this->id = 0;
	}
	Student(std::string imie, std::string nazwisko, int semestr, std::string kierunek, std::string numerIndeksu, int id = 0)
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->semestr = semestr;
		this->numerIndeksu = numerIndeksu;
		this->kierunek = kierunek;
		this->id = id;
	}

	friend std::ostream& operator << (std::ostream& out, Student & s)
	{
		out << "Imie: " << s.imie << std::endl;
		out << "Naziwsko: " << s.nazwisko << std::endl;
		out << "Semestr: " << s.semestr << std::endl;
		out << "Kierunek: " << s.kierunek << std::endl;
		out << "Numer indeksu: " << s.numerIndeksu << std::endl;
		return out;
	}

	std::string getImie()
	{
		return imie;
	}


	void setImie(std::string imie)
	{
		this->imie = imie;
	}

	int getId()
	{
		return id;
	}

	virtual ~Student() {}


	friend std::istream& operator >> (std::istream& in, Student &s)
	{
		in >> s.imie;
		in >> s.nazwisko;
		in >> s.semestr;
		in >> s.kierunek;
		in >> s.numerIndeksu;
		return in;
	}

};

class GeniuszMatematyczny
{
private:
	int iq = 0;
	int liczbaWygranychOlimpiad = 0;
	int wynikMaturalnyZMatematyki = 0;

public:

	int getIq()
	{
		return iq;
	}
	void setIq(int iq)
	{
		this->iq = iq;
	}
	int getLiczbaWygranychOlimpiad()
	{
		return liczbaWygranychOlimpiad;
	}
	void setLiczbaWygranychOlimpiad(int liczbaWygranychOlimpiad)
	{
		this->liczbaWygranychOlimpiad = liczbaWygranychOlimpiad;
	}
	int getWynikMaturalnyZMatematyki()
	{
		return wynikMaturalnyZMatematyki;
	}
	void setWynikMaturalnyZMatematyki(int wynikMaturalnyZMatematyki)
	{
		this->wynikMaturalnyZMatematyki = wynikMaturalnyZMatematyki;
	}

	friend std::ostream& operator << (std::ostream& out, GeniuszMatematyczny &gm)
	{
		if (gm.iq) out << "IQ studenta wynosi: " << gm.iq << std::endl;
		if (gm.liczbaWygranychOlimpiad) out << "Wygral " << gm.liczbaWygranychOlimpiad << " olimpiad matematycznych" <<
			std::endl;
		if (gm.wynikMaturalnyZMatematyki) out << "Na maturze uzyskal wynik " << gm.wynikMaturalnyZMatematyki << "%." <<
			std::endl;
		return out;
	}

};

class PrzyjacielZwierzat
{
private:
	bool maPsaLubKota;
	int liczbaZnanychGatunkow;
	double wydatkiNaPokarm;

public:

	bool getMaPsaLubKota()
	{
		return maPsaLubKota;
	}

	void setMaPsaLubKota(bool maPsaLubKota)
	{
		this->maPsaLubKota = maPsaLubKota;
	}

	int getliczbaZnanychGatunkow()
	{
		return liczbaZnanychGatunkow;
	}

	void setliczbaZnanychGatunkow(int liczbaZnanychGatunkow)
	{
		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;
	}

	double getwydatkiNaPokarm()
	{
		return wydatkiNaPokarm;
	}

	void setwydatkiNaPokarm(double wydatkiNaPokarm)
	{
		this->wydatkiNaPokarm = wydatkiNaPokarm;
	}

	friend std::ostream& operator << (std::ostream& out, PrzyjacielZwierzat &pz)
	{
		if (pz.maPsaLubKota) out << "Ta osoba posiada psa lub kota" << std::endl;
		else out << "Ta osoba nie posiada psa ani kota" << std::endl;
		if (pz.liczbaZnanychGatunkow) out << "Ta osoba zna: " << pz.liczbaZnanychGatunkow << " gatunkow." << std::endl;
		if (pz.wydatkiNaPokarm) out << "Jej wydatki miesieczne na pokarm wynosza " << pz.wydatkiNaPokarm << " zl." << std::endl;
		return out;
	}
};

class StudentInformatyki : public Student, public GeniuszMatematyczny
{
private:
	bool znaCpp;
	int id;

public:
	StudentInformatyki() 
	{
		this->id = 1;
	}

	StudentInformatyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, bool znaCpp, int id = 1) :
		Student(imie, nazwisko, semestr,"Informatyka",numerIndeksu, 1)
	{
		this->znaCpp = znaCpp;
	}

	bool isZnaCpp()
	{
		return znaCpp;
	}

	void setZnaCpp(bool znaCpp)
	{
		this->znaCpp = znaCpp;
	}

	void modyfikujNumerIndeksu()
	{
		if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
	}

	friend std::ostream& operator << (std::ostream& out, StudentInformatyki & s)
	{
		out << static_cast<Student &>(s);
		if (s.znaCpp) out << "Zna C++";
		else out << "Dopiero sie uczy w C++";
		out << std::endl;
		out << static_cast<GeniuszMatematyczny &>(s);
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentInformatyki &si)
	{
		in >> si.imie;
		in >> si.nazwisko;
		in >> si.semestr;
		in >> si.numerIndeksu;
		si.kierunek = "Informatyka";
		in >> si.znaCpp;
		return in;
	}



};

class StudentBiologi : public Student, public PrzyjacielZwierzat
{
private:
	int id;
public:
	StudentBiologi() 
	{
		this->id = 3;
	}
	StudentBiologi(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu)	: 
		Student(imie, nazwisko, semestr,"Biologia", numerIndeksu, 3) {}

	friend std::ostream& operator << (std::ostream& out, StudentBiologi &sb)
	{
		out << static_cast<Student &>(sb);
		out << static_cast<PrzyjacielZwierzat &>(sb);
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentBiologi &sb)
	{
		in >> sb.imie;
		in >> sb.nazwisko;
		in >> sb.semestr;
		sb.kierunek = "Biologia";
		in >> sb.numerIndeksu;
		return in;
	}

};

class StudentPolonistyki : public Student
{
private:
	int liczbaPrzeczytanychKsiazek;
	int id;

public:
	StudentPolonistyki()
	{
		this->id = 2;
	}
	StudentPolonistyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, int liczbaPrzeczytanychKsiazek) :
		Student(imie, nazwisko, semestr,"Polonistyka", numerIndeksu, 2)
	{
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
		modyfikujIndeks();
	}

	int getLiczbaPrzeczytanychKsiazek()
	{
		return liczbaPrzeczytanychKsiazek;
	}

	int setLiczbaPrzeczytanychKsiazek(int liczbaPrzeczytanychKsiazek)
	{
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
	}

	void modyfikujIndeks()
	{
		if (numerIndeksu[0] != 'M') numerIndeksu = 'M' + numerIndeksu;
	}

	friend std::ostream& operator << (std::ostream& out, StudentPolonistyki &sp)
	{
		out << static_cast<Student &>(sp);
		if (sp.liczbaPrzeczytanychKsiazek > 100) out << "Przeczytal kilka ksiazek";
		else out << "Slaby czytelnik - chyba nie skonczy studiow";
		out << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentPolonistyki &sp)
	{
		in >> sp.imie;
		in >> sp.nazwisko;
		in >> sp.semestr;
		in >> sp.numerIndeksu;
		sp.kierunek = "Polonistyka";
		in >> sp.liczbaPrzeczytanychKsiazek;
		return in;
	}


};

class Uczelnia
{
private:
	std::string nazwa;
	Student *listaStudentow[100];
	int liczbaStudentow=0;

public:
	Uczelnia(){}
	Uczelnia(std::string nazwa)
	{
		this->nazwa = nazwa;
		std::cout << "Utworzono uczelnie " << nazwa << std::endl;
	}
	
	std::string getNazwa()
	{
		return nazwa;
	}

	int getLiczbaStuentow()
	{
		return liczbaStudentow;
	}

	Student getLista(int i)
	{
		return *listaStudentow[i];

	}

	~Uczelnia() {}

	void dodajStudenta(Student *s)
	{
		listaStudentow[liczbaStudentow] = s;
		liczbaStudentow++;
	}

	friend std::ostream& operator << (std::ostream& out, Uczelnia & u)
	{
		int i;
		if (u.liczbaStudentow > 0)
		{
			out << std::endl << "Oto lista studentow:" << std::endl;
			for (i = 0; i < u.liczbaStudentow; i++)
			{
				{
					out << std::endl << "Oto dane #" << i + 1 << " studenta:" << std::endl << std::endl;
					switch (u.listaStudentow[i]->getId())
					{
					case 0:
						out << *u.listaStudentow[i];
						break;
					case 1:
						out << *static_cast<StudentInformatyki *>(u.listaStudentow[i]);
						break;
					case 2:
						out << *static_cast<StudentPolonistyki *>(u.listaStudentow[i]);
						break;
					case 3:
						out << *static_cast<StudentBiologi *>(u.listaStudentow[i]);
						break;
					default:
						out << "Obiekt nieznanej klasy" << std::endl;
						break;
					}
					out << typeid(*u.listaStudentow[i]).name() << std::endl;
					out << std::endl;
				}
			}
		}
		else out << "Na tej uczelni nie ma jeszcze studentow." << std::endl;

		return out;
	}

	int znajdzStudenta(Student *s)
	{
		for (int i = 0; i < liczbaStudentow; i++)
		{
			if (s == listaStudentow[i])
			{
				std::cout << "Student znajduje sie na liscie pod numerem " << i << std::endl;
				return 1;
			}
		}
		std::cout << "Student nie znajduje sie na liscie" << std::endl;
		return 0;
	}

	friend std::istream& operator >>(std::istream& in, Uczelnia &u)
	{
		in >> u.nazwa;
		return in;
	}

};

int main(int argc, char *argv[])
{
	/*
	StudentInformatyki s1;
	std::cin >> s1;
	s1.setLiczbaWygranychOlimpiad(40);
	s1.setWynikMaturalnyZMatematyki(100);
	s1.setIq(150);

	std::cout << s1;*/

	Student s1("Daniel", "Najdrowski", 3,"WF", "253692");
	StudentPolonistyki s2("Franek", "Kowalski", 2, "12345", 150);
	StudentInformatyki s3("Maciej", "Reszke", 5, "23313", true);
	s3.modyfikujNumerIndeksu();
	s3.setLiczbaWygranychOlimpiad(2);
	s3.setWynikMaturalnyZMatematyki(14);

	StudentInformatyki s4("Piotr", "Bombowiec", 1, "253899", false);
	s3.setWynikMaturalnyZMatematyki(80);
	s3.setIq(200);

	StudentBiologi s5("Piotr", "Stul", 6, "997123");
	s5.setliczbaZnanychGatunkow(150);
	s5.setMaPsaLubKota(true);
	s5.setwydatkiNaPokarm(150.24);


	Student *s[] = { &s1,&s2,&s3,&s4 };

	std::cout << *s[3];

	
	/*for (int i = 0; i < 4; i++)
	{		
		switch (s[i]->getId())
		{
			case 0:
			std::cout << *s[i];
			break;
			case 1:
			std::cout << *static_cast<StudentInformatyki *>(s[i]);
			break;
			case 2:
			std::cout << *static_cast<StudentPolonistyki *>(s[i]);
			break;
			default:
			std::cout << "Obiekt nieznanej klasy" << std::endl;
			break;
		}
		std::cout << std::endl;
	}
*/
	//Uczelnia ug("uniwersystet gdanski");
	//ug.dodajStudenta(&s1);
	//ug.dodajStudenta(&s2);
	//ug.dodajStudenta(&s3);
	//ug.dodajStudenta(&s4);
	//ug.dodajStudenta(&s5);
	//std::cout << ug;


	/*Uczelnia *uc= new Uczelnia;
	int n;
	std::cout << "Witaj w aplikacji bazy danych studentow dla uczelni!" << std::endl;
	std::cout << "Najpierw utworz swoja uczelnie podaj nazwe: ";
	std::cin >> *uc;
	std::cout << "Utworzono uczelnie " << uc->getNazwa() << std::endl;
	do
	{
		std::cout << std::endl << "Oto opcje programu: \n0 - koniec dzialania programu\n1 - dopisz studenta\n2 - wypisz liste studentow" << std::endl;
		std::cout << "Co chcesz zrobic?: ";
		std::cin >> n;
		switch (n)
		{
			case 0:
				break;
			case 1:
				int m;
				if (uc->getLiczbaStuentow() < 100)
				{
					std::cout << std::endl << "Jakie studenta chcesz dopisac?\n0-Student\n1-Student Informatyki\n2-Student Polonistyki\n3-Student Biologi\nWybor: ";
					std::cin >> m;
					if (m == 0)
					{
						Student *s = new Student;
						std::cout << std::endl <<"Podaj dane studenta w kolejnosci (imie,nazwisko,semestr,kierunek,numer indeksu):\n";
						std::cin >> *s;
						uc->dodajStudenta(s);
						break;
					}
					else if (m == 1)
					{
						StudentInformatyki *si= new StudentInformatyki;
						std::cout << std::endl << "Podaj dane studenta w kolejnosci (imie,nazwisko,semestr,numer indeksu,czy zna C++ [ 1 - TAK, 0 - NIE ]:\n";
						std::cin >> *si;
						uc->dodajStudenta(si);
						break;
					}
					else if (m == 2)
					{
						StudentPolonistyki* sp = new StudentPolonistyki;
						std::cout << std::endl << "Podaj dane studenta w kolejnosci (imie,nazwisko,semestr,numer indeksu, ile ksiazek przeczytal):\n";
						std::cin >> *sp;
						uc->dodajStudenta(sp);
						break;
					}
					else if (m == 3)
					{
						StudentBiologi *sb = new StudentBiologi;
						std::cout << std::endl << "Podaj dane studenta w kolejnosci (imie,nazwisko,semestr,numer indeksu):\n";
						std::cin >> *sb;
						uc->dodajStudenta(sb);
						break;
					}
					else
					{
						std::cout << "Bledna wartosc! Powrot do menu glownego!" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "Przekroczono pojemnosc tablicy!" << std::endl;
					break;
				}
			case 2:
				std::cout << std::endl << *uc;
				break;
		}
	}
	while (n != 0);
*/
	system("pause");
	return 0;
}
