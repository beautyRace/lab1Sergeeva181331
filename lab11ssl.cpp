#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
#include <openssl/aes.h>
#include <fstream>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")
//
//extern "C" _declspec(dllimport) int RSA_public_encrypt(int flen, const unsigned char *from, const unsigned char *to, RSA *rsa, int padding);

// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	// ������ � ��������������� OpenSSL:
	// 1) �������� ������� � �����������
	// 2) ����������, ����������	
	// 3) �����������
	// 4) � ����� ������������� ������

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������
	// �� ����� � ������� � �������������/������������ 



	unsigned char *plaintext = /*(unsigned char *)D;*/
		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// �������� �����
	int plaintext_len = strlen((char *)plaintext); // ����� ������
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	//  


	//
	//������� ���� � �������� ���� 
	//
	//
	//
	//f0.open("f0.txt", std::fstream::in | std::fstream::binary); // ���� � ��������� �������
	//

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate

	char str[256];
	int len = 0;
	int cryptedtext_len = len;
	ifstream input("input.txt", std::fstream::in | std::fstream::binary);
	std::fstream output;
	output.open("out.txt", std::fstream::out | std::fstream::in | std::fstream::trunc | std::fstream::binary);

	input.read(str, 256);
	while (input.gcount() > 0)

	{
		EVP_EncryptUpdate(ctx, // ������ � �����������
			cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
			&len, // �������� ��������: ����� ����������� �����
			(unsigned char *)str, input.gcount());
		// ������� ��������: ��� ���������
		// ������� �������� : ����� ������� ������
		cryptedtext_len = len;
		output.write((char *)cryptedtext, len);
		input.read(str, 256);

	}



	// 5. ����������� �������� ����������
	// ����������, ���� ��������� ���� �������� ������� �� ���������
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	cryptedtext_len += len;
	output.write((char *)cryptedtext, len);
	input.close();

	// 6. �������� ���������
	EVP_CIPHER_CTX_free(ctx);
	output.close();

	// ����� ������������� ������
	//for (int i = 0; i < cryptedtext_len; i++)
	//{
	//	cout << hex << cryptedtext[i];
	//	if ((i + 1) % 32 == 0) cout << endl;
	//	
	//}
	//fS << D << "������";

	//cout << endl;





	// �����������

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);// ������������� ������� AES, ������ � ��������


	std::fstream deshef_input;
	deshef_input.open("out.txt", std::fstream::in | std::fstream::binary);
	std::fstream deshef_output;
	deshef_output.open("deasd_output.txt", std::fstream::out | std::fstream::trunc | std::fstream::binary);
	char str2[256];
	deshef_input.read(str2, 256);
	while (deshef_input.gcount() > 0)
	{
		EVP_DecryptUpdate(ctx,
			decryptedtext,
			&len,
			(unsigned char *)str2,
			deshef_input.gcount());  // ����������, ����������

		cryptedtext_len = len;
		deshef_output.write((char *)decryptedtext, len);
		deshef_input.read(str2, 256);
	}
	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);


	deshef_output.write((char*)decryptedtext, len);
	deshef_output.close();
	deshef_input.close();
	EVP_CIPHER_CTX_free(ctx);

	// --- ���������� �����
	// ������������ ����� ��� ��, �� ��������, � �����
	// � �����
	/*
		1) �������� ������ � ��������� ���������� OpenSSL
		2) ���������� ������� �����
		3) while(���������_�������� > 0)
		{
			4) ���������� ����������
			5) ������ �������������� ������� � ����
			6) ���������� ���������� ���������
		}
		7) ���������� �������������� �������
		8) ������ ��������������� ����� � ����
		9) �������� ������
	*/
	getchar();
	return 0;
}