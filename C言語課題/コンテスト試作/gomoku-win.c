#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void title(void);//タイトル画面を表示させる。
void shokika(char masu[10][10][10], int check[10][10][1]);//マスを初期化する。
void AIshokika(int AI[10][10][1]);
void hyoji(char masu[10][10][10]);//盤面を表示する。
void player(char masu[10][10][10], int check[10][10][1]);//プレイヤーが置く場所を決める。
void computer(char masu[10][10][10], int AI[10][10][1], int check[10][10][1], int i1, int j1);//コンピュータが置く場所を決める。
int tatecheck(int check[10][10][1], int AI[10][10][1], int i, int j);//縦に揃ってるかチェックする。
int yokocheck(int check[10][10][1], int AI[10][10][1], int i, int j);//横に揃ってるかチェックする。
int nanamecheck(int check[10][10][1], int AI[10][10][1], int i, int j);//斜めに揃ってるかチェックする。
int hantei(int check[10][10][1], int AI[10][10][1]);//5つ揃ってるかチェックする。
int owari(int check[10][10][1]);//マスが埋まりきったら終わり。

////////////////////////////////////////////////////////////////////////////////

int main(){
	//コマンドプロンプトのサイズを変更
	BOOL bRtn;
	HANDLE hWrite;
	SMALL_RECT rctWindowRect = {0,0,119,44};
	COORD dwCoord = {120,45};
	
	hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
	bRtn = SetConsoleScreenBufferSize(hWrite, dwCoord);
	bRtn = SetConsoleWindowInfo(hWrite,TRUE,&rctWindowRect);
	//ここまで
	
	int i1,j1;//一番最初にコンピュータが置いたマス。
	int i,j;
	int flag=1;//ループのフラグ。
	int you=0;//プレイヤーのフラグ。
	int com=0;//コンピュータのフラグ。
	int draw=0;//ドローのフラグ。
	char masu[10][10][10];//マス表示用の配列
	int check[10][10][1];//マスに何が置いてあるのかをチェックするための配列
	int AI[10][10][1];//コンピュータがどこに置くべきかを参考にするための配列
	
	title();
	
	srand(time(NULL));//シードを設定。
	
	shokika(masu,check);//初期化。
	AIshokika(AI);//AIの初期化。
	hyoji(masu);//表示。
	
	//コンピュータが弱すぎるので、先手は取らせてあげる。
	printf("コンピュータの番です。\n");
	printf("Enterキーを押してください。\n");
	getchar();
	while(flag){
		i1=rand()%9;
		j1=rand()%9;
		if(i1>1 && i1<7 && j1>1 && j1<7) flag=0;
	}
	
	check[i1][j1][0]=3;//このマスに置いたよーっていう印をつける。
	strcpy(masu[i1][j1],"★");
	
	hyoji(masu);
	
	flag=1;//フラグを立て直す。
	while(flag){//どっちかが勝つまで終わらない。
		
		player(masu,check);//プレイヤーのターン。
		hyoji(masu);//表示。
		
		AIshokika(AI);
		
		if(hantei(check,AI)==1){//プレイヤーが勝ってるかチェック。
			you=1;
			break;
		}
		
		if(owari(check)==1){//マスが埋まりきってないかチェック。
			draw=1;
			break;
		}
		
		computer(masu,AI,check,i1,j1);//コンピュータのターン。
		hyoji(masu);//表示。
		
		if(hantei(check,AI)==1){//コンピュータが勝ってるかチェック。
			com=1;
			break;
		}
		
		if(owari(check)==1){//マスが埋まりきってないかチェック。
			draw=1;
			break;
		}
		
	}
	if(you) printf("YOU WIN!\n");
	if(com) printf("YOU LOSE...\n");
	if(draw) printf("DRAW.\n");
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

void title(void){//タイトル。
	printf("\n");
	
	printf("　　　　　五五五五五五五五　　　　　目目目目目目目目　　　　　　　並　　　　　並　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　五　　　　　　　　　目　　　　　　目　　　　　　並並並並並並並並並　　　　　　べ　　べ　べ　　　\n");
	printf("　　　　　　　　五　　　　　　　　　目目目目目目目目　　　　　　　　並　　　並　　　　　　　べ　べ　べ　べ　　　\n");
	printf("　　　　　五五五五五五　　　　　　　目　　　　　　目　　　　　　並　並　　　並　並　　　　べ　　　べ　　　　　　\n");
	printf("　　　　　　　五　　五　　　　　　　目目目目目目目目　　　　　　並　　並　並　　並　　　べ　　　　　べ　　　　　\n");
	printf("　　　　　　五　　　五　　　　　　　目　　　　　　目　　　　　　　並　並　並　並　　　　　　　　　　　べ　　　　\n");
	printf("　　　　五五五五五五五五五五五　　　目目目目目目目目　　　　　並並並並並並並並並並並　　　　　　　　　　べ　　　\n");
	
	printf("\n");
	printf("始めるにはEnterキーを押してください。\n");
	getchar();
	
}

////////////////////////////////////////////////////////////////////////////////

void shokika(char masu[10][10][10], int check[10][10][1]){//初期化。
	int i,j;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			strcpy(masu[i][j],"□");
			check[i][j][0]=1;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////

void AIshokika(int AI[10][10][1]){//AIの初期化。
	int i,j;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			AI[i][j][0]=1;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////

void hyoji(char masu[10][10][10]){//表示。
	int i,j;
	
	printf("　1　2　3　4　5　6　7　8　9\n");
	
	for(i=0;i<9;i++){
		printf("%d ",i+1);//頭の数を表示。
		for(j=0;j<9;j++){
			printf("%s ",masu[i][j]);
		}
		printf("\n");//行終わりに改行。
	}
	printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////

void player(char masu[10][10][10], int check[10][10][1]){//プレイヤー。
	int i,j;
	int flag=1;
	
	printf("あなたの番です。\n");
	printf("置くマスを指定してください。(例；1 4 だと縦が1で横が4のマス)\n");
	while(flag){
		if(scanf("%d%d",&i,&j) != 2) scanf("%*s");//整数以外を入力したら、もう一度。
		else if(i<1 || i>9 || j<1 || j>9) printf("もう一度入力してください。\n");//1から9の間に収まってなかったら、もう一度。
		else if(check[i-1][j-1][0]==2 || check[i-1][j-1][0]==3) printf("そのマスには置けません。\n");//既に置いてるマスには置けません。
		else flag=0;
	}
	scanf("%*c");//改行を空読みして処理。
	check[i-1][j-1][0]=2;//このマスに置いたよーっていう印をつける。
	strcpy(masu[i-1][j-1],"●");
}

/*///////////////////////////////////////////////////////////////////////////////////////

400000 自分が4,飛び4
40000 相手が4,飛び4
30010 自分が飛び3
3010 相手が飛び3
3000 自分が3
300 相手が3
20 自分が2

//////////////////////////////////////////////////////////////////////////////////////*/

void computer(char masu[10][10][10], int AI[10][10][1], int check[10][10][1], int i1, int j1){//コンピュータ。
	int i,j;
	int flag=1;//ランダム用のフラグ
	int flag2=0;//相手が4つ(飛び4を含む)揃ってる時のフラグ
	int flag3=0;//相手が3つ揃ってる時のフラグ
	int flag4=0;//自分が3つ揃ってる時のフラグ
	int flag5=0;//とりあえず最初に置いたとこの周辺が置けそうな時のフラグ
	int flag6=0;//自分が飛び3の時のフラグ
	int flag7=0;//相手が飛び3の時のフラグ
	int flag8=0;//自分が2ができてるときのフラグ
	int decide=0;//自分が4つ(飛び4を含む)揃ってる時のフラグ
	int tmp,tmp0;//自分が4つ(飛び4を含む)揃ってるとき用の座標の一時保存。
	int tmp1,tmp2;//相手が4つ(飛び4を含む)の同上
	int tmp3,tmp4;//相手が3つの同上
	int tmp5,tmp6;//自分が3つの同上
	int tmp7,tmp8;//最初の周辺の同上
	int tmp9,tmp10;//自分が飛び3の同上
	int tmp11,tmp12;//相手が飛び3の同上
	int tmp13,tmp14;//相手が飛び4の同上
	int tmp15,tmp16;//自分が2の時の同上
	
	printf("コンピュータの番です。\n");
	printf("Enterキーを押してください。\n");
	getchar();
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(AI[i][j][0]==400000){//コンピュータ4
				if(check[i][j][0]==1){
					flag=0;
					decide=1;
					tmp=i;
					tmp0=j;
					break;
				}
			}
			if(AI[i][j][0]==40000){//プレイヤー4
				if(check[i][j][0]==1){
					flag=0;
					flag2=1;
					tmp1=i;
					tmp2=j;
				}
			}
			if(AI[i][j][0]==30010){//コンピュータ飛び3
				if(check[i][j][0]==1){
					flag=0;
					flag6=1;
					tmp9=i;
					tmp10=j;
				}
			}
			if(AI[i][j][0]==3010){//プレイヤー飛び3
				if(check[i][j][0]==1){
					flag=0;
					flag7=1;
					tmp11=i;
					tmp12=j;
				}
			}
			if(AI[i][j][0]==3000){//コンピュータ3
				if(check[i][j][0]==1){
					flag=0;
					flag4=1;
					tmp5=i;
					tmp6=j;
				}
			}
			if(AI[i][j][0]==300){//プレイヤー3
				if(check[i][j][0]==1){
					flag=0;
					flag3=1;
					tmp3=i;
					tmp4=j;
				}
			}
			if(AI[i][j][0]==20){//コンピュータ2
				if(check[i][j][0]==1){
					flag=0;
					flag8=1;
					tmp15=i;
					tmp16=j;
				}
			}
		}
		if(decide==1) break;
	}
	
	for(i=-1;i<2;i++){//最初に置いたとこの周辺に置かせてみる。
		for(j=-1;j<2;j++){
			if(check[i1+i][j1+j][0]==1){
				flag=0;
				flag5=1;
				tmp7=i1+i;
				tmp8=j1+j;
			}
		}
	}
	
	while(flag){
		i=rand()%9;
		j=rand()%9;
		if(check[i][j][0]==1) flag=0;//まだ置いてないマスならおっけー。
	}
	
	if(flag5){//最初置いたとこの周辺
		i=tmp7;
		j=tmp8;
	}
	if(flag8){//コンピュータ2
		i=tmp15;
		j=tmp16;
	}
	if(flag3){//プレイヤー3
		i=tmp3;
		j=tmp4;
	}
	if(flag4){//コンピュータ3
		i=tmp5;
		j=tmp6;
	}
	if(flag7){//プレイヤー飛び3
		i=tmp11;
		j=tmp12;
	}
	if(flag6){//コンピュータ飛び3
		i=tmp9;
		j=tmp10;
	}
	if(flag2){//プレイヤー4、飛び4
		i=tmp1;
		j=tmp2;
	}
	if(decide){//コンピュータ4、飛び4
		i=tmp;
		j=tmp0;
	}
	
	check[i][j][0]=3;//このマスに置いたよーっていう印をつける。
	strcpy(masu[i][j],"★");
}

/////////////////////////////////////////////////////////////////////////////////////////

int tatecheck(int check[10][10][1], int AI[10][10][1], int i, int j){//縦チェック。
	int kekka=0;
	
	//逆サイドに置かれてないかを確認した上で3、飛び3は認識させる。
	
	if(check[i][j][0]==2){
		if(check[i+1][j][0]==2){
			if(check[i+3][j][0]==2){
				if((check[i-1][j][0] == 1 || check[i-1][j][0] == 2) && (check[i+4][j][0] == 1 || check[i+4][j][0] == 2)) if(AI[i+2][j][0]<3010) AI[i+2][j][0]=3010;//飛び3
				if(check[i+4][j][0]==2) if(AI[i+2][j][0]<40000) AI[i+2][j][0]=40000;//飛び4
			}
			if(check[i-2][j][0]==2) if((check[i-3][j][0] == 1 || check[i-3][j][0] == 2) && (check[i+2][j][0] == 1 || check[i+2][j][0] == 2)) if(AI[i-1][j][0]<3010) AI[i-1][j][0]=3010;//飛び3
			if(check[i+2][j][0]==2){
				if(check[i-1][j][0]==1) if((i+3) != 8) if(AI[i+3][j][0]<300) AI[i+3][j][0]=300;//3
				if(check[i+3][j][0]==1) if((i-1) != 0) if(AI[i-1][j][0]<300) AI[i-1][j][0]=300;//同上
				if(check[i+4][j][0]==2) if(AI[i+3][j][0]<40000) AI[i+3][j][0]=40000;//飛び4
				if(check[i-2][j][0]==2) if(AI[i-1][j][0]<40000) AI[i-1][j][0]=40000;//同上
				if(check[i+3][j][0]==2){
					if(AI[i+4][j][0]<40000) AI[i+4][j][0]=40000;
					if(AI[i-1][j][0]<40000) AI[i-1][j][0]=40000;
					if(check[i+4][j][0]==2){
						kekka=1;
					}
				}
			}
		}
	}
	
	if(check[i][j][0]==3){
		if(check[i+1][j][0]==3){
			if(check[i-1][j][0]==1 && check[i+2][j][0]==1){//2
				if((i-1) != 0) if(AI[i-1][j][0]<20) AI[i-1][j][0]=20;
				if((i+2) != 8) if(AI[i+2][j][0]<20) AI[i+2][j][0]=20;
			}
			if(check[i+3][j][0]==3){
				if((check[i-1][j][0] == 1 || check[i-1][j][0] == 3) && (check[i+4][j][0] == 1 || check[i+4][j][0] == 3)) if(AI[i+2][j][0]<30010) AI[i+2][j][0]=30010;//飛び3
				if(check[i+4][j][0]==3) AI[i+2][j][0]=400000;//飛び4
			}
			if(check[i-2][j][0]==3) if((check[i-3][j][0] == 1 || check[i-3][j][0] == 3) && (check[i+2][j][0] == 1 || check[i+2][j][0] == 3)) if(AI[i-1][j][0]<30010) AI[i-1][j][0]=30010;//飛び3
			if(check[i+2][j][0]==3){
				if(check[i-1][j][0]==1) if((i+3) != 8) if(AI[i+3][j][0]<3000) AI[i+3][j][0]=3000;//3
				if(check[i+3][j][0]==1) if((i-1) != 0) if(AI[i-1][j][0]<3000) AI[i-1][j][0]=3000;//同上
				if(check[i+4][j][0]==2) AI[i+3][j][0]=400000;//飛び4
				if(check[i-2][j][0]==2) AI[i-1][j][0]=400000;//同上
				if(check[i+3][j][0]==3){
					AI[i+4][j][0]=400000;
					AI[i-1][j][0]=400000;
					if(check[i+4][j][0]==3){
						kekka=1;
					}
				}
			}
		}
	}
	
	return kekka;
}

///////////////////////////////////////////////////////////////////////////////////////////////

int yokocheck(int check[10][10][1], int AI[10][10][1], int i, int j){//横チェック。
	int kekka=0;
	
	//逆サイドに置かれてないかを確認した上で3、飛び3は認識させる。
	
	if(check[i][j][0]==2){
		if(check[i][j+1][0]==2){
			if(check[i][j+3][0]==2){
				if((check[i][j-1][0] == 1 || check[i][j-1][0] == 2) && (check[i][j+4][0] == 1 || check[i][j+4][0] == 2)) if(AI[i][j+2][0]<3010) AI[i][j+2][0]=3010;//飛び3
				if(check[i][j+4][0]==2) if(AI[i][j+2][0]<40000) AI[i][j+2][0]=40000;//飛び4
			}
			if(check[i][j-2][0]==2) if((check[i][j-3][0] == 1 || check[i][j-3][0] == 2) && (check[i][j+2][0] == 1 || check[i][j+2][0] == 2)) if(AI[i][j-1][0]<3010) AI[i][j-1][0]=3010;//同上
			if(check[i][j+2][0]==2){
				if(check[i][j-1][0]==1) if((j+3) != 8) if(AI[i][j+3][0]<300) AI[i][j+3][0]=300;//3
				if(check[i][j+3][0]==1) if((j-1) != 0) if(AI[i][j-1][0]<300) AI[i][j-1][0]=300;//同上
				if(check[i][j+4][0]==2) if(AI[i][j+3][0]<40000) AI[i][j+3][0]=40000;//飛び4
				if(check[i][j-2][0]==2) if(AI[i][j-1][0]<40000) AI[i][j-1][0]=40000;//同上
				if(check[i][j+3][0]==2){
					if(AI[i][j+4][0]<40000) AI[i][j+4][0]=40000;
					if(AI[i][j-1][0]<40000) AI[i][j-1][0]=40000;
					if(check[i][j+4][0]==2){
						kekka=1;
					}
				}
			}
		}
	}
	
	if(check[i][j][0]==3){
		if(check[i][j+1][0]==3){
			if(check[i][j-1][0]==1 && check[i][j+2][0]==1){//2
				if((j-1) != 0) if(AI[i][j-1][0]<20) AI[i][j-1][0]=20;
				if((j+2) != 8) if(AI[i][j+2][0]<20) AI[i][j+2][0]=20;
			}
			if(check[i][j+3][0]==3){
				if((check[i][j-1][0] == 1 || check[i][j-1][0] == 3) && (check[i][j+4][0] == 1 || check[i][j+4][0] == 3)) if(AI[i][j+2][0]<30010) AI[i][j+2][0]=30010;//飛び3
				if(check[i][j+4][0]==3) AI[i][j+2][0]=400000;//飛び4
			}
			if(check[i][j-2][0]==3) if((check[i][j-3][0] == 1 || check[i][j-3][0] == 3) && (check[i][j+2][0] == 1 || check[i][j+2][0] == 3)) if(AI[i][j-1][0]=30010) AI[i][j-1][0]=30010;//同上
			if(check[i][j+2][0]==3){
				if(check[i][j-1][0]==1) if((j+3) != 8) if(AI[i][j+3][0]<3000) AI[i][j+3][0]=3000;//3
				if(check[i][j+3][0]==1) if((j-1) != 0) if(AI[i][j-1][0]<3000) AI[i][j-1][0]=3000;//同上
				if(check[i][j+4][0]==2) AI[i][j+3][0]=400000;//飛び4
				if(check[i][j-2][0]==2) AI[i][j-1][0]=400000;//同上
				if(check[i][j+3][0]==3){
					AI[i][j+4][0]=400000;
					AI[i][j-1][0]=400000;
					if(check[i][j+4][0]==3){
						kekka=1;
					}
				}
			}
		}
	}
	
	return kekka;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int nanamecheck(int check[10][10][1], int AI[10][10][1], int i, int j){//斜めチェック。
	int kekka=0;
	
	//逆サイドに置かれてないかを確認した上で3、飛び3は認識させる。
	
	if(check[i][j][0]==2){
		if(check[i+1][j+1][0]==2){
			if(check[i+3][j+3][0]==2){
				if((check[i-1][j-1][0] == 1 || check[i-1][j-1][0] == 2) && (check[i+4][j+4][0] == 1 || check[i+4][j+4][0] == 2)) if(AI[i+2][j+2][0]<3010) AI[i+2][j+2][0]=3010;//飛び3
				if(check[i+4][j+4][0]==2) if(AI[i+2][j+2][0]<40000) AI[i+2][j+2][0]=40000;//飛び4
			}
			if(check[i-2][j-2][0]==2) if((check[i-3][j-3][0] == 1 || check[i-3][j-3][0] == 2) && (check[i+2][j+2][0] == 1 || check[i+2][j+2][0] == 2)) if(AI[i-1][j-1][0]<3010) AI[i-1][j-1][0]=3010;//同上
			if(check[i+2][j+2][0]==2){
				if(check[i-1][j-1][0]==1) if((i+3) != 8 && (j+3) != 8) if(AI[i+3][j+3][0]<300) AI[i+3][j+3][0]=300;//3
				if(check[i+3][j+3][0]==1) if((i-1) != 0 && (j-1) != 0) if(AI[i-1][j-1][0]<300) AI[i-1][j-1][0]=300;//同上
				if(check[i+4][j+4][0]==2) if(AI[i+3][j+3][0]<40000) AI[i+3][j+3][0]=40000;//飛び4
				if(check[i-2][j-2][0]==2) if(AI[i-1][j-1][0]<40000) AI[i-1][j-1][0]=40000;//飛び4
				if(check[i+3][j+3][0]==2){
					if(AI[i+4][j+4][0]<40000) AI[i+4][j+4][0]=40000;
					if(AI[i-1][j-1][0]<40000) AI[i-1][j-1][0]=40000;
					if(check[i+4][j+4][0]==2){
						kekka=1;
					}
				}
			}
		}
	}
	
	if(check[i][j][0]==2){
		if(check[i-1][j+1][0]==2){
			if(check[i+2][j-2][0]==2) if((check[i-2][j+2][0] == 1 || check[i-2][j+2][0] == 2) && (check[i+3][j-3][0] == 1 || check[i+3][j-3][0] == 2)) if(AI[i+1][j-1][0]<3010) AI[i+1][j-1][0]=3010;//飛び3
			if(check[i-3][i+3][0]==2){
				if((check[i-4][j+4][0] == 1 || check[i-4][j+4][0] == 2) && (check[i+1][j-1][0] == 1 || check[i+1][j-1][0] == 2)) if(AI[i-2][j+2][0]<3010) AI[i-2][j+2][0]=3010;//同上
				if(check[i-4][j+4][0]==2) if(AI[i-2][j+2][0]<40000) AI[i-2][j+2][0]=40000;//飛び4
			}
			if(check[i-2][j+2][0]==2){
				if(check[i+1][j-1][0]==1) if((i-3) != 0 && (j+3) != 8) if(AI[i-3][j+3][0]<300) AI[i-3][j+3][0]=300;//3
				if(check[i-3][j+3][0]==1) if((i+1) != 8 && (j-1) != 0) if(AI[i+1][j-1][0]<300) AI[i+1][j-1][0]=300;//同上
				if(check[i-4][j+4][0]==2) if(AI[i-3][j+3][0]<40000) AI[i-3][j+3][0]=40000;//飛び4
				if(check[i+2][j-2][0]==2) if(AI[i+1][j-1][0]<40000) AI[i+1][j-1][0]=40000;//同上
				if(check[i-3][j+3][0]==2){
					if(AI[i-4][j+4][0]<40000) AI[i-4][j+4][0]=40000;
					if(AI[i+1][j-1][0]<40000) AI[i+1][j-1][0]=40000;
					if(check[i-4][j+4][0]==2){
						kekka=1;
					}
				}
			}
		}
	}
	
	if(check[i][j][0]==3){
		if(check[i+1][j+1][0]==3){
			if(check[i-1][j-1][0]==1 && check[i+2][j+2][0]==1){//2
				if((i-1) != 0 && (j-1) != 0) if(AI[i-1][j-1][0]<20) AI[i-1][j-1][0]=20;
				if((i+2) != 8 && (j+2) != 8) if(AI[i+2][j+2][0]<20) AI[i+2][j+2][0]=20;
			}
			if(check[i+3][j+3][0]==3){
				if((check[i-1][j-1][0] == 1 || check[i-1][j-1][0] == 3) && (check[i+4][j+4][0] == 1 || check[i+4][j+4][0] == 3)) if(AI[i+2][j+2][0]<30010) AI[i+2][j+2][0]=30010;//飛び3
				if(check[i+4][j+4][0]==3) AI[i+2][j+2][0]=400000;//飛び4
			}
			if(check[i-2][j-2][0]==3) if((check[i-3][j-3][0] == 1 || check[i-3][j-3][0] == 3) && (check[i+2][j+2][0] == 1 || check[i+2][j+2][0] == 3)) if(AI[i-1][j-1][0]<30010) AI[i-1][j-1][0]=30010;//同上
			if(check[i+2][j+2][0]==3){
				if(check[i-1][j-1][0]==1) if((i+3) != 8 && (j+3) != 8) if(AI[i+3][j+3][0]<3000) AI[i+3][j+3][0]=3000;//3
				if(check[i+3][j+3][0]==1) if((i-1) != 0 && (j-1) != 0) if(AI[i-1][j-1][0]<3000) AI[i-1][j-1][0]=3000;//同上
				if(check[i+4][j+4][0]==2) AI[i+3][j+3][0]=400000;//飛び4
				if(check[i-2][j-2][0]==2) AI[i-1][j-1][0]=400000;//飛び4
				if(check[i+3][j+3][0]==3){
					AI[i+4][j+4][0]=400000;
					AI[i-1][j-1][0]=400000;
					if(check[i+4][j+4][0]==3){
						kekka=1;
					}
				}
			}
		}
	}
	
	if(check[i][j][0]==3){
		if(check[i-1][j+1][0]==3){
			if(check[i+1][j-1][0]==1 && check[i-2][j+2][0]==1){//2
				if((i+1) != 8 && (j-1) != 0) if(AI[i+1][j-1][0]<20) AI[i+1][j-1][0]=20;
				if((i-2) != 0 && (j+2) != 8) if(AI[i-2][j+2][0]<20) AI[i-2][j+2][0]=20;
			}
			if(check[i+2][j-2][0]==3) if((check[i-2][j+2][0] == 1 || check[i-2][j+2][0] == 3) && (check[i+3][j-3][0] == 1 || check[i+3][j-3][0] == 3)) if(AI[i+1][j-1][0]<30010) AI[i+1][j-1][0]=30010;//飛び3
			if(check[i-3][i+3][0]==3){
				if((check[i-4][j+4][0] == 1 || check[i-4][j+4][0] == 3) && (check[i+1][j-1][0] == 1 || check[i+1][j-1][0] == 3)) if(AI[i-2][j+2][0]<30010) AI[i-2][j+2][0]=30010;//同上
				if(check[i-4][j+4][0]==3) AI[i-4][j+4][0]=400000;//飛び4
			}
			if(check[i-2][j+2][0]==3){
				if(check[i+1][j-1][0]==1) if((i-3) != 0 && (j+3) != 8) if(AI[i-3][j+3][0]<3000) AI[i-3][j+3][0]=3000;//3
				if(check[i-3][j+3][0]==1) if((i+1) != 8 && (j-1) != 0) if(AI[i+1][j-1][0]<3000) AI[i+1][j-1][0]=3000;//同上
				if(check[i-4][j+4][0]==2) AI[i-3][j+3][0]=400000;//飛び4
				if(check[i+2][j-2][0]==2) AI[i+1][j-1][0]=400000;//同上
				if(check[i-3][j+3][0]==3){
					AI[i-4][j+4][0]=400000;
					AI[i+1][j-1][0]=400000;
					if(check[i-4][j+4][0]==3){
						kekka=1;
					}
				}
			}
		}
	}
	
	return kekka;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int hantei(int check[10][10][1], int AI[10][10][1]){//揃ってるかチェック。
	int i,j;
	int kekka=0;
	int flag=0;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(tatecheck(check,AI,i,j)){
				flag=1;
				break;
			}
			if(yokocheck(check,AI,i,j)){
				flag=1;
				break;
			}
			if(nanamecheck(check,AI,i,j)){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) kekka=1;
	
	return kekka;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int owari(int check[10][10][1]){//マスが残ってるかチェック。
	int i,j;
	int kekka=1;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(check[i][j][0]==1) kekka=0;//空いてるマスがあるかどうか。
		}
	}
	
	return kekka;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*AI確認用

printf("  1 2 3 4 5 6 7 8 9\n");

for(i=0;i<9;i++){
	printf("%d ",i+1);//頭の数を表示。
	for(j=0;j<9;j++){
		printf("%d ",AI[i][j][0]);
	}
	printf("\n");//行終わりに改行。
}

printf("\n");
*/
