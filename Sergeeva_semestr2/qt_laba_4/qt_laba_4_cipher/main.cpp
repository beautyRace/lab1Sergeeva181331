#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <string.h>
#include <stdio.h>
//#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/applink.c>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int do_crypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, int do_encrypt)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    unsigned char *key = (unsigned char *)"0123456789abcdeF0123456789abcdeF";
    unsigned char *iv = (unsigned char *)"1234567887654321";

    if(1 != EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, do_encrypt))
        handleErrors();

    if(1 != EVP_CipherUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_CipherFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}


int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    //###########

        string stringtext;
        getline(cin, stringtext);
        unsigned char *plaintext = (unsigned char*)stringtext.c_str();

        //cout << (unsigned char *)plaintext << endl;

        unsigned char ciphertext[128];
        unsigned char decryptedtext[128];

        int decryptedtext_len, ciphertext_len;

        do_crypt(plaintext, strlen((char *)plaintext), ciphertext, 1);

        printf("Ciphertext is:\n");
        //BIO_dump_fp (stdout, (const char *)ciphertext, ciphertext_len);
        printf("%s\n", ciphertext);

        decryptedtext_len = do_crypt(ciphertext, strlen((char *)ciphertext), decryptedtext, 0);
        decryptedtext[decryptedtext_len] = '\0';
        printf("_________________________________________________________________\n");
        printf("Decrypted text is:\n");
        printf("%s\n", decryptedtext);

    //############

    return a.exec();
}
