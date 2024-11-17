#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int left;
    int right;
};

int compare(const void* a, const void* b) {
    struct Interval* intervalA = (struct Interval*)a;
    struct Interval* intervalB = (struct Interval*)b;

       return intervalA->right - intervalB->right;
}

int main() {
    int n;
    scanf("%d", &n);

        struct Interval intervals[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &intervals[i].left, &intervals[i].right);
    }

        qsort(intervals, n, sizeof(struct Interval), compare);

        int count = 1;
    int end = intervals[0].right;

    for (int i = 1; i < n; ++i) {
        if (intervals[i].left > end) {  
            count++;
            end = intervals[i].right;
        }
    }

    printf("%d\n", count);  
    return 0;
}
