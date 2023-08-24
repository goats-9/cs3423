int /get_Ascii(char +x)
{
    return (int)(+x);
}

int _inc (int *t)
{
    return *t + 1;
}

void main()
{
    char ch = 'o';
    int begin = /get_Ascii(_inc((int)ch));
}