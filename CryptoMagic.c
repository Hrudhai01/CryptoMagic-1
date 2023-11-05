#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    
    if(strcmp(argv[1], "-E")==0){

        printf("Encrypt File\n");
        FILE *inputfile = fopen(argv[2], "r"); // opens file specified by filename in read mode
        FILE *outputfile = fopen("myFile.txt", "w"); //opens file named "text.crp" in write mode
        int c;
        int outChar;
        while((c = fgetc(inputfile)) != EOF){ //reads each character in file until the end of the file is reached
        //encryption code here
            if(c == 9){
                fputc('T', outputfile); //transforms <tab> into TT
                fputc('T', outputfile); //transforms <tab> into TT
            }else{
                outChar = c - 16; // transform to hex (encrypt)
                if(outChar < 32){
                    outChar = (outChar - 32) + 144;
                }
            }
            fprintf(outputfile, "%02X", outChar); //writes as 2 digit hexadecimal value
        }
        fclose(inputfile); //closes files
        fclose(outputfile);
    }else if(strcmp(argv[1], "-D")==0){
        printf("Decrypt File\n");
        FILE *inputfile = fopen(argv[2], "r"); // opens file specified by filename in read mode
        FILE *outputfile = fopen("This.txt", "w"); //opens file named "text.crp" in write mode

        int outChar;
        int c;
        int c2;
        while((c = fgetc(inputfile)) != EOF){ //reads each character in file until the end of the file is reached
            //decryption code here
            if(c == 'T' && c2 == fgetc(inputfile) == 'T'){
                fputc('\t', outputfile);
            }else{
                c = c*16;
                // outChar = c + c2;
                outChar += 16;
                if(outChar > 127){
                outChar = (outChar - 144) + 32;
                }
            }
            fprintf(outputfile, "%c", outChar); //writes as decrypted message
        }
        fclose(inputfile); //closes files
        fclose(outputfile);
    }else{
        printf("Encrypt 1 File\n");
    }
return 0;
}
