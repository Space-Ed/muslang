#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <cerrno>

using namespace std;

std::string get_file_contents(const char *filename)
{
  //instantiate input file stream called in
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
  }
  throw(errno);
}

enum TOKENS {
	TONE, TONALITY
};

struct Token {
	TOKENS kind;
	string content;
};

class Scanner {
	public:
		Scanner();
		vector<Token> scan(string input);
	private:
		int pos;
		void skipWhitespace();
};

Scanner::Scanner(void){
	pos = 0;
}

vector<Token> Scanner::scan(string input){

	vector<Token> tokens;

	char inch = input[pos];

	while(inch != '\n'){
		// decide what to do with the character
		Token token;

		if (inch == 'a'){
			token.content = inch;
			token.kind = TONE;
		}else {
			token.content = inch;
			token.kind = TONALITY;
		}

		tokens.push_back(token);

		inch = input[++pos];
	}
}

void interpret(string program){
	Scanner scanner();
	vector<Token> tokens;

	tokens = scanner.scan(program);

	for (Token token: tokens ){
		cout << "<" << token.content << ">";
	}

//	Node root = parser.parse(tokens);
//	execute(root);
}

int main(int argc, char **argv) {

	char * filename = *(argv + 1);

	if(!filename){
		cout << "must provide file" << endl;
		return 1;
 	}

	cout << "parsing file" << filename << endl;
	
	try {
		string program = get_file_contents(filename);
		interpret(program);
	} catch (int e){
		cout << "Problem opening file: " << e << endl;
	}


	return 0;
}
