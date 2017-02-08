/*
 PASS-CRYPT-v0.1

 * author Krhertz 2017
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

  [+] This is the main file, that is used to parse options from terminal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "lib/cr.h"

const char *argp_program_version = "PASS-CRYPT-v0.1";

static char doc [] = "PASS-CRYPT-v0.1";

static char args_doc [] = "start";

static struct argp_option options[] = {

  {"in_file",  'i',  "FILE",       0,                    "In-file to crypt or decrypt"},
  {"out_file", 'o',  "FILE",       0,                    "Out-file: result (crypted or decrypted output)"},
  {"crypt",    'c',   0,           OPTION_ARG_OPTIONAL,  "Crypt In-file and save to Out-file"},
  {"decrypt",  'd',   0,           OPTION_ARG_OPTIONAL,  "Decrypt In-file and save to Out-file"},
  {"\'start\'",  0,   0,           OPTION_DOC,           "Always type the word \'start\' at the end of all arguments."},
  { 0 }
};

struct arguments {
  char *args[1];
  char *in_file;
  char *out_file;
  int crypt;
  int decrypt;

};

static error_t
parse_opt (int key, char *arg, struct argp_state *state){

  struct arguments *arguments = state->input;

  switch (key){

	case 'i':
		arguments->in_file = arg;
		break;
	case 'o':
		arguments->out_file = arg;
		break;
	case 'c':
		arguments->crypt = 1;
		break;
	case 'd':
		arguments->decrypt = 1;
		break;
	case ARGP_KEY_ARG:
     		if (state->arg_num >= 1)
        		argp_usage (state);
 		break;
	case ARGP_KEY_END:
      		if (state->arg_num < 1)
		        argp_usage (state);
		break;
	default:
		return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

int main (int argc, char **argv){

  struct arguments arguments;
  unsigned int llav;
  char cmd[] = "rm -rf ";
  int opt;

  arguments.in_file = NULL;
  arguments.out_file = NULL;
  arguments.crypt = 0;
  arguments.decrypt = 0;

  argp_parse (&argp, argc, argv, 0, 0, &arguments);

  if (arguments.crypt == 1 && arguments.decrypt == 1){
	printf ("[!] Please choose just crypt or decrypt\n");
	exit (0);
  }

  if (arguments.crypt == 1){
	opt = 1;

 } else if (arguments.decrypt == 1){
	opt = 2;
 }else if (arguments.crypt == 0 && arguments.decrypt == 0){
	printf ("[+] Please select \'-c\' or \'-d\' option.\n    For more information use --help\n");
	printf ("[!] Not all arguments.\n");
	exit (0);
 }

  llav = value ();

  if (opt == 1){
	crypt (llav, arguments.in_file, arguments.out_file);
  }else if (opt == 2){
	decrypt (llav, arguments.in_file, arguments.out_file);
  }

  char sec;

  printf ("[!] If crypting, it is recommended to delete the file, for security purposes.\n");
  printf ("    If decrypting, verify all variables before completely delete your file original file.\n\n");
  printf ("[*] Do you wish to delete \'%s\' file? (s/n): ", arguments.in_file);
  fflush (stdin);
  sec = fgetc (stdin);

  if (sec == 's'){
  	strcat (cmd, arguments.in_file);
	system (cmd);
	printf ("[+] Credentials Secured -> Deleted: \'%s\' file\n", arguments.in_file);
  }else{
	printf ("[*] Keeping both files.\n");
  }
  printf ("[+] Everything went smoothly.\n[*] Output file: %s\n",arguments.out_file);
  printf ("[+] Created By: Kr3rtz\n[+] Happy Hacking.\n\n");
  exit (0);
}
