# PASS-CRYPT-v0.1

Optimized version of PASS-CRYPT

Password Crypter version 0.1

Sometimes, it is necessary to keep our credentials in secret, yet we all know that keeping this info in a 
computer is not always a good idea. In this case we can use "PASS-CRYPT". This tool is intended to be used as a 
crypter of plain text. This is accomplished by using several algorithms that will generate a key, which 
will then be used to "obf" the text.

[+] To keep the integrity of data, and somehow avoid password cracking, there are several variables that can be
modified in order to have complete control of them throughout the process of key generation. Those variables are:

    Custom key:	The key provided by the user (completely randomized in lengh and characters).
   
    Module:	    This is a number completely necessary for the process of key generation.
    
    A:	    Times to generate a routine. 
    
    B: 	    Key length.
    
    C:	    Length of number for modulus got in the 'Module' option.

	NOTE: For modify the  A, B and C variables, check:  "lib/cr.h".    


[+] The way to interact with the crypter, is by using:

	OPTIONS
	  -c, --crypt                Crypt In-file and save to Out-file
	  -d, --decrypt              Decrypt In-file and save to Out-file
	  -i, --in_file=FILE         In-file to crypt or decrypt
	  -o, --out_file=FILE        Out-file: = result (crypted or decrypted output)
	  'start'                    Always type the word 'start' at the end of all
				     arguments.
	  -?, --help                 Give this help list
	      --usage                Give a short usage message
	  -V, --version              Print program version

	Usage: PASS-CRYPT [-cd?V] [-i FILE] [-o FILE] [--crypt] [--decrypt]
		    [--in_file=FILE] [--out_file=FILE] [--'start'] [--help] [--usage]
		    [--version] start


[+] SOME INFORMATION [+]


[+] If there is any doubt about usage, you can use the --help or --usage commands.

[+] In comparison with the last version of this tool, you can now choose the file to crypt/decrypt,
having a better interaction with the tool. To accomplish this, the library argparse has been used.

[+] To start the crypter simply:

    sudo make PASS-CRYPT
    sudo ./PASS-CRYPT -i in_file.txt -o out_file.txt start

Once started, the crypter will ask for a custom key as well as for a modul value. This information is crutial
for the key generation process.

[!]NOTE: While decrypting, use the same values you enter, otherwise the output will be ureadable data. 
Capital and small letters shoul be respected for the key and the modul just numbers:

	eg
	key: password
	modul: 4
	
	is not the same as:
	
	key: PassworD
	modul: 44


[!] Disclaimer: Keep all your credentials in a safe place. By studying the code, you can have complete control of the
            key generation process. Use ascii characters only. Try to use 'sudo' all the time. You can also crypt 
	    entire texts.

Created by: 

	==================================================================
	| ##   ## ######## ##   ##   ###### ########  ######## ########   |
	| ##  ##  ##    ## ##   ##       #  ##    ##     ##          #    |
	| ## ##   ##    ## ##   ##      ##  ##    ##     ##         #     |
	| ## ##   ######   #######        # ######       ##       #       |
	| ##  ##  ##   ##  ##   ##        # ##   ##      ##     #         |
	| ##   ## ##    ## ##   ##   #####  ##    ##     ##    ########   |
	|                                                                 |
	|     Exploiting vulnerabilities, creating new ways through...    |
	==================================================================
	
	Happy hacking.
