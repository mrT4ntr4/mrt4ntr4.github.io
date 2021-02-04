char *crackPass(BYTE *pass) {
	DATA_BLOB in;
	DATA_BLOB out;

	BYTE tmp[1024];
	memcpy(tmp, pass, 1024);
	int size = sizeof(tmp) / sizeof(tmp[0]);

	in.pbData = pass;
	in.cbData = size + 1;
	char str[1024] = "";
	char *s_ptr = str;

	if (CryptUnprotectData(&in, NULL, NULL, NULL, NULL, 0, &out)) {
		for (int i = 0; i < out.cbData; i++)
			str[i] = out.pbData[i];
		str[out.cbData] = '\0';

		if (str[0] == '\0')
			return NULL;

		return s_ptr;
	}
	else
		return NULL; //Error on decryption
}