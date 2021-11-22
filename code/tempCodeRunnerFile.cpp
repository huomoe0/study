if(cmp < t)
        len++;

    if(len <= k)
    {
        for(int i = 0;i < k;i++)
        {
            printf("3");
        }
    }
    else
    {
        printf("3");
        for(int i = 0;i < len-k;i++)
        printf("0");
        for(int i = 0;i < k-1;i++)
        printf("3");
    }