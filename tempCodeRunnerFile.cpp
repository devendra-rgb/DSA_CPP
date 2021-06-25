 int iterations;
    for(int o=0;o<iterations;o++)

{
    
    int number,number1,i,j,min=0,max=0,count=0;
    
    scanf("%d",&number1);
    scanf("%d",&number);
   // scanf("%d",&number1);

    int primes[number+1];

    //populating array with naturals numbers
    for(i = 2; i<=number; i++)
        primes[i] = i;

    i = 2;
    while ((i*i) <= number)
    {
        if (primes[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (primes[i]*j > number)
                    break;
                else
                    // Instead of deleteing , making elemnets 0
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }

    for(int m=number1;m<=number;m++)
    {
        if(primes[m]!=0)
        {
            count++;
        if(min==0)
        min=primes[m];
        if(m>max)
        max=primes[m];
        }
    }
    if(count==0)
    printf("%d",-1);
    if(count>0)
    {
    printf("%d\n",max-min);
     }
}  