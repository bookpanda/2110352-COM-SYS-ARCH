int max1(int a, int b) { 
    return (a>b)?a:b;
}

int testMax() {
    return max1(1,2);
}

int max2(int a, int b) {
    int isaGTb = a > b;
    int max;
    if (isaGTb)
        max=a;
    else
        max=b;
    return max;
}