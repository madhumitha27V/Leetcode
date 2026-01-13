double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    long double totalArea = 0.0L;
    long double low = 1e18, high = 0.0;

    for (int i = 0; i < squaresSize; i++) {
        long double y = squares[i][1];
        long double l = squares[i][2];
        totalArea += l * l;

        if (y < low) low = y;
        if (y + l > high) high = y + l;
    }

    long double target = totalArea / 2.0;

    auto long double areaBelow(double h) {
        long double sum = 0.0;
        for (int i = 0; i < squaresSize; i++) {
            long double y = squares[i][1];
            long double l = squares[i][2];

            if (h <= y) continue;                    
            else if (h >= y + l) sum += l * l;       
            else sum += (h - y) * l;               
        }
        return sum;
    }

    for (int iter = 0; iter < 100; iter++) {
        long double mid = (low + high) / 2.0;
        if (areaBelow(mid) < target)
            low = mid;
        else
            high = mid;
    }

    return (double)((low + high) / 2.0);
}
