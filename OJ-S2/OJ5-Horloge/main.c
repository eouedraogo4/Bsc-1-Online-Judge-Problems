#include <stdio.h>

int main(){
     start:{
        int a[10], clocks[10];
        int stop=1;
        for(int i = 0; i < 9; ++i){
            if(stop!=EOF)
                stop=scanf("%d",&clocks[i]);
            else
                return 0;
        }
        for( a[0] = 0; a[0] < 4; ++a[0]){
            for(a[1] = 0; a[1] < 4; ++a[1]){
                for( a[2] = 0; a[2] < 4; ++a[2]){
                    for( a[3] = 0; a[3] < 4; ++a[3]){
                        for( a[4] = 0; a[4] < 4; ++a[4]){
                            for( a[5] = 0; a[5] < 4; ++a[5]){
                                for( a[6] = 0; a[6] < 4; ++a[6]){
							        for( a[7] = 0; a[7] < 4; ++a[7]){
							            for( a[8] = 0; a[8] < 4; ++a[8]){
										    int sum = 0;
                                            sum += (clocks[0]+3*(a[0]+a[1]+a[2]))%4;
										    sum += (clocks[1]+3*(a[0]+a[1]+a[3]+a[4]))%4;
                                            sum += (clocks[2]+3*(a[0]+a[3]+a[5]))%4;
                                            sum += (clocks[3]+3*(a[1]+a[2]+a[4]+a[6]))%4;
                                            sum += (clocks[4]+3*(a[1]+a[3]+a[4]+a[6]+a[7]))%4;
                                            sum	+= (clocks[5]+3*(a[3]+a[4]+a[5]+a[7]))%4;
                                            sum += (clocks[6]+3*(a[2]+a[6]+a[8]))%4;
                                            sum += (clocks[7]+3*(a[4]+a[6]+a[7]+a[8]))%4;
                                            sum += (clocks[8]+3*(a[5]+a[7]+a[8]))%4;
										    if(sum == 0){
										        for(int i = 0; i < 9; ++i){
										            while(a[i]--){
													    printf("%d ",i);
                                                    }
                                                }
                                            putchar('\n');
                                            goto start;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
