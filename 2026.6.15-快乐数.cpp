/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。*/
bool isHappy(int n) {
    int arr[10]={0,1,4,9,16,25,36,49,64,81},sum=0,cnt=0;
    while(1){
        while(n){
            sum+=arr[n%10];
            n/=10;
            cnt++;
        }
        if(sum==1){
            return true;
        }
        n=sum;
        sum=0;
        if(cnt>100000){
            return false;
        }
    }
    return false;
}
/*c语言第二板
bool isHappy(int n) {
    int sum=0,cnt=0;
    while(1){
        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }
            cnt++;
        if(sum==1){
            return true;
        }
        n=sum;
        sum=0;
        if(cnt>810){
            return false;
        }
        //int的极限是2147483647，故平方和的极限是9*9*10=810, 所以超过810就说明进入了死循环.如果平方和与之前出现过的数重合,那么依照规律,那个数最终会回到这个数,所以说明进入了死循环,故最多810次就能判断出是否是快乐数
    }
    return false;
}*/