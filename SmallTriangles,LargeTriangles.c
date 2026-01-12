#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
#include <stdio.h>
#include <math.h>

typedef struct {
    int a, b, c;
    double area;
} Triangle;

double get_area(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int n;
    scanf("%d", &n);

    Triangle t[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].c);
        t[i].area = get_area(t[i].a, t[i].b, t[i].c);
    }

    // Sort triangles by area (ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t[i].area > t[j].area) {
                Triangle temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    // Output sorted triangles
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", t[i].a, t[i].b, t[i].c);
    }

    return 0;
}
int compare(const void *p, const void *q) {
    triangle *t1 = (triangle *)p;
    triangle *t2 = (triangle *)q;
    if (t1->area2 < t2->area2) return -1;
    else return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    triangle *arr = malloc(n * sizeof(triangle));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
        arr[i].area2 = area_squared(arr[i].a, arr[i].b, arr[i].c);
    }

    qsort(arr, n, sizeof(triangle), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].c);
    }

    free(arr);
    return 0;
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
}

int main()