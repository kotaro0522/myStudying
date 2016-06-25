// test_omp.cpp : メイン プロジェクト ファイルです。

//#include "stdafx.h"
#include "stdio.h"
//#include <omp.h>
#include <time.h>

time_t timer1,timer2,ans;


int main()
{
	int nThreads = 0;
    
	//nThreads = omp_get_thread_num();
    
	//printf("Thread is %d \n",nThreads);
    
	int i,j,k,n=0;
    
	// この文により直後のfor文がマルチスレッド実行される。
	// ネストされた内側の変数jによるループはマルチスレッド化されない。
	// ただし、変数jをprivate 宣言しておかないと複数のスレッドで変数が共有されるため、
	// ループ回数が適切でなくなる。
	// omp文内部でループする場合は、共有しても良い変数か、個別化しなければならない変数か、区別が必要
	// 総和を求めるなど、最後に結果を結合しなければならない変数はreductionで指定する
	// その際、各スレッドの結果をどのように統合するかを()の前に指定し、:の後に対応する変数を書く
	// 足し算(+)、掛け算(*)の他、論理和、論理積なども利用可能
    
    time(&timer1);
//#pragma omp parallel for private (j,k) reduction (+:n)
#pragma omp parallel for    
	//for (i=0;i<200000;i++){
    for (i=0;i<2;i++){
		// 現在実行中のスレッド番号を取得
		//nThreads = omp_get_thread_num();
		k=0;
		for (j=0;j<100000000;j++){
			k=k+1;
		}
		n=n+k/j;
		printf("Thread is %d (i=%d,n=%d,j=%d,k=%d)\n",nThreads,i,n,j,k);
	}
    time(&timer2);
    ans = timer2 - timer1;
    printf("Total time is %ld(sec)\n",ans);
	// reductionで全スレッドの総和を取っているので、シングルスレッドの計算結果と同じ総和になる
	printf("Result n=%d\n",n);
    
    
	// こちらは 並列化指示対象の　for文の外なので、シングルスレッド実行
	//逆に言えば、上記の表記のままでは、ompコマンドが発生するたびにスレッドを作成するので
	//動作コストが大きくなる。スレッドを残し続けるには別の方法が必要。
	n=0;
	for (i=0;i<200000;i++){
		//nThreads = omp_get_thread_num();
		k=0;
		for (j=0;j<100000000;j++){
			k=k+1;
		}
		n=n+k/j;
		//printf("Thread is %d (i=%d,n=%d)\n",nThreads,i,n);
	}
    
    return 0;
    
}
