#include <stdio.h>
#include <string.h>

void Encrypt(const char *filename){ //Encryption Function

}

void Decrypt(const char *filename){ //Decryption function

}

int main(int argc, char *argv[]){ //number of arguments passed, array containing arguments
    if(argc == 3 && strcmp(argv[1], "CryptoMagic") == 0){ //checks if the argument is 3 and if the first is "CryptoMagic"
        const char *filename = argv[2]; //extracts the filename and stores it in the filename variable
        if (strstr(filename, ".crp") != NULL) { //checks for ".crp" and if the extension is in the file name and then it calls the decrypt function
            decryptFile(filename); //decyrpt function
        } else {
            encryptFile(filename); //encrypt function
        }
    }
    }
    

    return 0;
}