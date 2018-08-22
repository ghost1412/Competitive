%{
int _i1=0, _i2=0, _i3=0, _i4=0, _count = 0;	
void countInc(int*);	//Increment counter if different type of symbol present
void PassChecker();	//check type of password	
%}

line \n

%%
[0-9] {countInc(&_i1);};
[a-z] {countInc(&_i2);};
[A-Z] {countInc(&_i3);};
[!\];':-=_+\\|&*()\[",./<>?@#$%^] {countInc(&_i4);};
{line} {PassChecker();};
%%

void countInc(int* _i){
	if(*_i != 1){
		*_i = 1;	
		_count++;
	}
	return;
}

void Reset(){
	_i1=0; _i2=0; _i3=0; _i4=0;
	_count = 0;
}

void PassChecker(){
	if(_count == 4){		
		printf("Strong\n"); 
	}/*else
	if(_count == 3){
		printf("Strong\n");
	}else
	if(_count == 2){
		printf("Normal\n");
	}*/else{
		printf("Weak\n");
	}
	Reset();
}


int main(){
	yylex();	
}

