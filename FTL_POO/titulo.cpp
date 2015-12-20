#include "main.h"

void titulo(){

	Consola c;  // Este objecto dá acesso à funcionalidade da consola. Basta um por programa

	c.setScreenSize(30, 120);
	c.setTextColor(c.VERDE_CLARO);
	
	c.gotoxy(20, 12);
	cout << " *               *      *  *" << endl;
	c.gotoxy(20, 13);
	cout << "     *       *             *    *" << endl;
	c.gotoxy(20, 14);
	cout << "          ___" << endl;
	c.gotoxy(20, 15);
	cout << "    |     | |" << endl;
	c.gotoxy(20, 16);
	cout << "   | |    | |" << endl;
	c.gotoxy(20, 17);
	cout << "  |---|===|-|" << endl;
	c.gotoxy(20, 18);
	cout << "  |---|   |P|" << endl;
	c.gotoxy(20, 19);
	cout << " |  I  |  |O|" << endl;
	c.gotoxy(20, 20);
	cout << "||  S  || |O|" << endl;
	c.gotoxy(20, 21);
	cout << "||  E  ||=| |" << endl;
	c.gotoxy(20, 22);
	cout << "||  C  || | |" << endl;
	c.gotoxy(20, 23);
	cout << "|_______| |_|" << endl;
	c.gotoxy(20, 24);
	cout << " |@| |@|  | |" << endl;
	c.gotoxy(20, 25);
	cout << "_@@@@@@@__|_|_" << endl;

	cout << "                                                                 " << endl;
	cout << "               _|                                                " << endl;
	cout << "   _|      _|        _|_|_|    _|_|_|    _|_|    _|_|_|  _|_|    " << endl;
	cout << "   _|      _|  _|  _|    _|  _|    _|  _|_|_|_|  _|    _|    _|  " << endl;
	cout << "     _|  _|    _|  _|    _|  _|    _|  _|        _|    _|    _|  " << endl;
	cout << "       _|      _|    _|_|_|    _|_|_|    _|_|_|  _|    _|    _|  " << endl;
	cout << "                                   _|                            " << endl;
	cout << "                               _|_|                              " << endl << endl << endl;

	cout << "\t                         Novo Jogo" << endl;
	cout << "\t                            Sair" << endl;
}