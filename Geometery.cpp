bool does_The_Points_makeLine(double x[3] , double y[3]){
    double d[3];
    d[0] = sqrt(pow(abs(x[0]-x[1]) , 2) + pow(abs(y[0] - y[1]) ,2));
    d[1] = sqrt(pow(abs(x[0]-x[2]) , 2) + pow(abs(y[0] - y[2]) ,2));
    d[2] = sqrt(pow(abs(x[2]-x[1]) , 2) + pow(abs(y[2] - y[1]) ,2));
    sort(d,d+3);
    if(d[0]+d[1] - d[2] < 1e-6)return 1;
    return 0;
} 
