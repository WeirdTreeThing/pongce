int clamp(int num, int min, int max) {
    if (num > max)
        return max;
    else if (num < min)
        return min;
    else
        return num;
}

int check_collision(int x1, int xsize1, int y1, int ysize1, int x2, int xsize2, int y2, int ysize2) {
    if (
        x1 < x2 + xsize2 &&
        x1 + xsize1 > x2 &&
        y1 < y2 + ysize2 &&
        y1 + ysize1 > y2
    )
        return 1;
    else
        return 0;
}
