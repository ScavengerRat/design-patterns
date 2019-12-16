#include <iostream>
using namespace std;
class File
{
	class FileState* current;
public:
	File();
	void setCurrent(FileState* s)
	{
		current = s;
	}
	void Open();
	void Close();


	void Read();
	void Write();
};

class FileState
{
public:
	virtual void Open(File* f)
	{
		cout << "Plik zostal juz otwarty\n";
	}
	virtual void Close(File* f)
	{
		cout << "Plik zostal juz zamkniety\n";
	}
	virtual void Read() = 0;
	virtual void Write() = 0;
};
void File::Open()
{
	current->Open(this);
}
void File::Close()
{
	current->Close(this);
}

void File::Read()
{
	current->Read();
}
void File::Write()
{
	current->Write();
}


class FileOpened : public FileState
{
public:
	FileOpened()
	{
		//cout<<"     FileOpened-ctor";
	};
	~FileOpened()
	{
		//cout<<"     dtor-FileOpened";
	};


	void Close(File* f);

	void Read()
	{
		cout << "Czytam z pliku" << endl;
	}
	void Write()
	{
		cout << "Pisze do Pliku" << endl;
	}
};

class FileClosed : public FileState
{
public:
	FileClosed()
	{
		//cout<<"     FileClosed-ctor";
	};
	~FileClosed()
	{
		//cout<<"     dtor-FileClosed";
	};

	void Open(File* f)
	{
		cout << "#################### Otwieram Plik ####################\n";
		f->setCurrent(new FileOpened());
		delete this;
	}

	void Read()
	{
		cout << "Plik zamkniety - nie moge czytac z Pliku" << endl;
	}
	void Write()
	{
		cout << "Plik zamkniety - nie moge pisac do Pliku" << endl;
	}
};
void FileOpened::Close(File* f)
{
	cout << "#################### Zamykam Plik ####################\n";
	f->setCurrent(new FileClosed());
	delete this;
}
File::File()
{
	current = new FileClosed();
	cout << "\n";
}



int main(void)
{
	File* plik = new File();
	plik->Write();
	plik->Read();
	plik->Open();
	plik->Open();
	plik->Open();
	plik->Write();
	plik->Read();
	plik->Close();
	plik->Close();
	plik->Read();
	plik->Write();
	plik->Close();

	return 0;
}
