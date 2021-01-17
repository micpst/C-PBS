/*
 *  Plik: cli.h
 *  Opis: Naglowek metod umozliwiajacych pobranie danych 
 *        od uzytkownika z linii komend.
 */

#ifndef CLI_H
#define CLI_H

/* Pobiera lancuch od uzytkowika i zapisuje go w buforze */
void cli_get_string(char *msg, char *buf, size_t len);

/* Pobiera i zwraca liczbe wpisana przez uzytkownika */
long cli_get_number(char *msg);

#endif