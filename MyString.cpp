#include <iostream>

//El chem gri menak es angam :) :)
using namespace std;

class MyString{
    private:
		char * ch;
		int length;
		
    public:
		MyString ();
		MyString ( const char * );
		~MyString ();
		MyString ( const MyString & );
		void print ( void );
		void operator = ( const MyString );
};

MyString :: MyString () {
    ch = 0;
    length = 0;    
}

MyString :: MyString(const char *n) {
    length = sizeof(n);
    ch = new char [ length ];
    for ( int i = 0 ; i < length ; i++ ){
    ch [i] = n [i];
    }
    ch [length] = '\0';
    }


MyString :: ~ MyString () {
    delete [] ch;
    ch = 0;
}


MyString :: MyString ( const MyString & x ) {
    length = x.length;
    ch = new char [length];
    for( int i = 0 ; i < length ; i++ ){
    ch [i] = x.ch [i];
    }
    ch[length] = '\0';
}

void MyString :: print( void ) {
    cout <<""<< ch << endl;
}

void MyString :: operator = ( const MyString x ) {
    length = x.length;
    ch = new char [length];
    for( int i = 0 ; i < length ; i++ ){
	ch[i] = x.ch[i];
    }
    ch[length] = '\0';
}

int main() {
    MyString word1 ("MyString");
    MyString word2;
    word2 = word1;
    word1.print();
    word2.print();
}
