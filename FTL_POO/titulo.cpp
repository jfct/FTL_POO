#include "main.h"

void titulo(){

	Consola c;  // Este objecto dá acesso à funcionalidade da consola. Basta um por programa
	
	c.gotoxy(50, 2);
	cout << " *               *      *  *" << endl;
	c.gotoxy(50, 3);
	cout << "     *       *             *    *" << endl;
	c.gotoxy(50, 4);
	cout << "          ___" << endl;
	c.gotoxy(50, 5);
	cout << "    |     | |" << endl;
	c.gotoxy(50, 6);
	cout << "   | |    | |" << endl;
	c.gotoxy(50, 7);
	cout << "  |---|===|-|" << endl;
	c.gotoxy(50, 8);
	cout << "  |---|   |P|" << endl;
	c.gotoxy(50, 9);
	cout << " |  I  |  |O|" << endl;
	c.gotoxy(50, 10);
	cout << "||  S  || |O|" << endl;
	c.gotoxy(50, 11);
	cout << "||  E  ||=| |" << endl;
	c.gotoxy(50, 12);
	cout << "||  C  || | |" << endl;
	c.gotoxy(50, 13);
	cout << "|_______| |_|" << endl;
	c.gotoxy(50, 14);
	cout << " |@| |@|  | |" << endl;
	c.gotoxy(50, 15);
	cout << "_@@@@@@@__|_|_" << endl;

	c.gotoxy(25, 17);
	cout << "                                                                 " << endl;
	c.gotoxy(25, 18);
	cout << "               _|                                                " << endl;
	c.gotoxy(25, 19);
	cout << "   _|      _|        _|_|_|    _|_|_|    _|_|    _|_|_|  _|_|    " << endl;
	c.gotoxy(25, 20);
	cout << "   _|      _|  _|  _|    _|  _|    _|  _|_|_|_|  _|    _|    _|  " << endl;
	c.gotoxy(25, 21);
	cout << "     _|  _|    _|  _|    _|  _|    _|  _|        _|    _|    _|  " << endl;
	c.gotoxy(25, 22);
	cout << "       _|      _|    _|_|_|    _|_|_|    _|_|_|  _|    _|    _|  " << endl;
	c.gotoxy(25, 23);
	cout << "                                   _|                            " << endl;
	c.gotoxy(25, 24);
	cout << "                               _|_|                              " << endl << endl;
}