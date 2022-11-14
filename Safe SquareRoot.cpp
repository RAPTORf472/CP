int SSqrt(int x) {
    
    int tem = sqrt(x) + 3;
    
    while (tem * tem > x) tem--;
    
    return tem;
    
}
