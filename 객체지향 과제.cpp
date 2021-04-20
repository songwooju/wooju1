#include <iostream>

// quiz1 ����
int countMatchedNumberLetterInString(const char* str, int digit)
{
	int len = strlen(str);

	int count = 0;

	for (int i = 0; i < len; i++) // ó������ ������ �˻�
	{
		if (str[i] - '0' == digit) // str�� ���� char���̿��� 0�� �ƽ�Ű�ڵ尪�� ���ְ� ������ digit�� ���� ��
			count++;
	}
	return count;
}

// quiz2 ����
void excludeRedundantLetters(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++) // �˻縦 �ϴ� ���� ���ں��� ������ �ִ��� üũ
		{
			if (str[i] == str[j])
				for (int k = j; k < len; k++)
				{
					str[k] = str[k + 1]; // �� ���ں��� �� ĭ�� ������ ��ܿ�
					if (str[k] == '\0') // length���� for���� ��� ���� �ʾƵ� null���ڰ� ������ ����
						break;
				}
			else if (str[j] == '\0')// length���� for���� ��� ���� �ʾƵ� null���ڰ� ������ ����
				break;
		}
	}
}
// quiz3 ����
int countWords(const char* str)
{
	int len = strlen(str);

	int count = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i + 1] == ' ' || str[i] != ' ' && str[i + 1] == '\0' || str[i] != ' ' && str[i + 1] == '	') 
	// �չ迭�� ���� �����̰� �׵ڿ� �迭�� �������� �˻�, ���ڿ� '\0'�� ���ӵǵ� ����
			count++;
	}
	return count;
}


// quiz4 ����
bool examinePairedParenthesis(const char* str)
{
	int len = strlen(str);
	int count = 0;

		if (str[0] == ')' || str[len-1] == '(') // ù��° ���� : ù���� ���� ) �ų� ���������� (�̸� ����
			return false;
		
		if (str[0] == '(' && str[len-1] == ')') // ù��°�� ( �������� ) �̸�
		{
			for (int i = 0; i < len; i++) // ( �� ) ������ ��ġ�ϴ��� Ȯ��
			{
				if (str[i] == '(')
					count++;
				
				else if (str[i] == ')')
					count--;

				if (count < 0) // �ι�° ���� : ���࿡ ()) �� ���� ( ���� )������ �������� false
					return false;
			}
			return count == 0 ? true : false; // 3��° ���� ( �� )�� ���� ��ġ�ؾߵȴ�. ��ġ�ϸ� true ��ġ���� ������ false
		}
	return false;
}


// quiz5 ����
void convertString(char* str)
{
	for (int i = 0; i < strlen(str); i++) // str�� ũ�Ⱑ ��� �ٲ� ���� �־��ش�.
		if (str[i] == ' ')
		{
			for (int j = strlen(str); j > i; j--)
			{
				str[j + 2] = str[j]; // ���������� �ڷ� �� ĭ�� ���� ���ڵ��� �о��ش�
			}

			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0'; // �ڷ� �� ĭ�� �о����Ƿ� ���ʴ�� %, 2, 0�� �־��ش�.
		}
}




int main()
{
	int count = countMatchedNumberLetterInString("112233443311334913201234", 4);
	printf("quiz1: %d\n", count);

	char data[100]{ "hello world" };
	excludeRedundantLetters(data);
	printf("quiz2: %s\n", data);

	int nWords = countWords("Hello World.	Here is the train\n");
	printf("quiz3: %d\n", nWords);

	bool result = examinePairedParenthesis("((()))");
	printf("quiz4: %s\n", result == true ? "true" : "false");

	char input[100] = "Hello World. Nice to Meet you";
	convertString(input);
	printf("quiz5: %s\n", input);

	return 0;
}
