/*
 cr.h: This file contains all the functions used in the crypter.

 * Author Krhertz 2017
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 [+]  This file contains all the routines to create the key and crypt/decrypt 
      text files.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A 15    //Fib
#define B 25	//KEY
#define C 7	//mod

unsigned int int_carac (char *cle, int size){

  unsigned int tot = 0;
  int i;
  int aux = 0;

  for (i = 0; i < size; i++){
        aux = *(cle + i);
        if (aux >= 32){
                tot = tot + aux;
                aux = 0;
        }
  }
  return tot;
}

unsigned int modul (unsigned int num_clav, int times){
  return num_clav % times;
}

unsigned int fi (unsigned int modul){

  unsigned int res = 0;
  int i;

  for (i = 0; i < A; i ++){
        res = (modul - 1) + modul;
        modul++;
  }
  return res;
}

void crypt(unsigned int llav, char *in_file, char *out_file){
  int i;
  int carac;

  FILE  *arch, *nue;

  if ((arch = fopen (in_file,"r")) != NULL){
	if ((nue = fopen (out_file,"w")) != NULL){
		  }else {
        		perror ("Error:");
        		exit(-1);
        		}

	do{
		char temp;
		temp = fgetc(arch);
		carac = temp;
		if (carac > 8 && carac < 128){
			temp = temp + llav;
			fputc(temp, nue);
		}
        }while(!feof(arch));
	rewind (arch);
	rewind (nue);
	fclose (arch);
	fclose (nue);
  }else {
          printf ("[!] The chosen in_file: \'%s\' doesn't exist or there was a problem while opening it. Verify its name or make sure it exists.\n", in_file);
          exit (-1);
	}
}

void decrypt(unsigned int llav, char *in_file, char *out_file){
  int i;

  FILE  *arch, *nue;

  if ((arch = fopen (in_file,"r")) != NULL){
	if ((nue = fopen (out_file,"w")) != NULL){
  		}else {
        		perror ("Error:");
        		exit(-1);
        		}
	do{
		char temp;
		temp = fgetc(arch);
		temp = temp - llav;

		if(temp > 8 && temp < 128){
			fputc(temp, nue);
		}

        }while(!feof(arch));
	rewind (arch);
	rewind (nue);
	fclose (arch);
	fclose (nue);
  }else {
          printf ("[!] The chosen in_file: \'%s\' doesn't exist or there was a problem while opening it. Verify its name or make sure it exists.\n", in_file);
	  exit (-1);
	}
}

unsigned int value (){

  char cle [B];
  char ti[C];
  int size , times;

  puts ("\n[*] Provide the custom key: ");
  fflush (stdin);
  fgets (cle, B, stdin);
  size = strlen(cle) + 1;

  printf ("[*] Module: ");
  fflush (stdin);
  fgets (ti, C , stdin);
  times = atoi (ti);

  return fi (modul(int_carac (cle, size), times ));
}
