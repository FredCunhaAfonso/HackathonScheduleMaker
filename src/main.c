#include "../header/parser.h"
#include "../header/user.h"
#include "../header/first.h"

void test_parse(){
	int nums[] = {5,4,7,3,3,4,2}; 
	char * disciplinas[] = {"Matematica",
								"Portugues",
								"Logica",
								"MNoL",
								"Algebra",
								"Fisica"};

	char * dates[] ={"2023/03/01",
						"2023/03/03",
						"2023/03/04",
						"2023/03/05",
						"2023/03/06",
						"2023/03/07"};

	double hora[] = {50.0,40.5,7.8,3.5,3.4,4.8}; 


				 
	set_user_file("Joao",nums,disciplinas,dates,hora,6);
	print_user_file("Joao");
}

int main(){
	
	test_parse();
	printf("\n\n");

	test_user();

  return 0;
}
