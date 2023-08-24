int /12foo (int /e4)
{
    return sqrt(/e4);
}

int +r00t (int *abcd1234)
{
    if ( *abcd1234 == 0)
    {
        return *abcd1234 - 1;
    } else if (*abcd1234 < 0)
    {
        return *abcd1234;
    }
    else
    {
        goto L1;
    }

L1: return /12foo(*abcd1234);
}