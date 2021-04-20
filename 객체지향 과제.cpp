#include <iostream>

// quiz1 성공
int countMatchedNumberLetterInString(const char* str, int digit)
{
	int len = strlen(str);

	int count = 0;

	for (int i = 0; i < len; i++) // 처음부터 끝까지 검색
	{
		if (str[i] - '0' == digit) // str의 값은 char형이여서 0의 아스키코드값을 빼주고 정수형 digit의 값과 비교
			count++;
	}
	return count;
}

// quiz2 성공
void excludeRedundantLetters(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++) // 검사를 하는 다음 문자부터 같은게 있는지 체크
		{
			if (str[i] == str[j])
				for (int k = j; k < len; k++)
				{
					str[k] = str[k + 1]; // 그 문자부터 한 칸씩 앞으로 당겨옴
					if (str[k] == '\0') // length까지 for문이 모두 돌지 않아도 null문자가 나오면 종료
						break;
				}
			else if (str[j] == '\0')// length까지 for문이 모두 돌지 않아도 null문자가 나오면 종료
				break;
		}
	}
}
// quiz3 성공
int countWords(const char* str)
{
	int len = strlen(str);

	int count = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i + 1] == ' ' || str[i] != ' ' && str[i + 1] == '\0' || str[i] != ' ' && str[i + 1] == '	') 
	// 앞배열의 값이 문자이고 그뒤에 배열이 공백인지 검사, 문자와 '\0'이 연속되도 증가
			count++;
	}
	return count;
}


// quiz4 성공
bool examinePairedParenthesis(const char* str)
{
	int len = strlen(str);
	int count = 0;

		if (str[0] == ')' || str[len-1] == '(') // 첫번째 조건 : 첫번쨰 값이 ) 거나 마지막값이 (이면 거짓
			return false;
		
		if (str[0] == '(' && str[len-1] == ')') // 첫번째가 ( 마지막이 ) 이면
		{
			for (int i = 0; i < len; i++) // ( 와 ) 개수가 일치하는지 확인
			{
				if (str[i] == '(')
					count++;
				
				else if (str[i] == ')')
					count--;

				if (count < 0) // 두번째 조건 : 만약에 ()) 와 같이 ( 보다 )개수가 많아지면 false
					return false;
			}
			return count == 0 ? true : false; // 3번째 조건 ( 와 )의 수가 일치해야된다. 일치하면 true 일치하지 않으면 false
		}
	return false;
}


// quiz5 성공
void convertString(char* str)
{
	for (int i = 0; i < strlen(str); i++) // str의 크기가 계속 바뀌어서 직접 넣어준다.
		if (str[i] == ' ')
		{
			for (int j = strlen(str); j > i; j--)
			{
				str[j + 2] = str[j]; // 끝에서부터 뒤로 두 칸씩 먼저 문자들을 밀어준다
			}

			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0'; // 뒤로 두 칸씩 밀었으므로 차례대로 %, 2, 0을 넣어준다.
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
