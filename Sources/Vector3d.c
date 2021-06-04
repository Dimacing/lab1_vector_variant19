#include "../include/Vector3d.h"

#define gc(a, x) *(double _Complex *)((*a).x)
#define gd(a, x) *(double *)((*a).x)

#define func_Complex(name)  name->sum = sum_Complex; \
                            name->diff = diff_Complex; \
                            name->cross = cross_Complex; \
                            name->dot = dot_Complex;  \
                            name->divide = divide_Complex; \
                            name->scan = scan_Complex

#define func_double(name)  name->sum = sum_double; \
                            name->diff = diff_double; \
                            name->cross = cross_double; \
                            name->dot = dot_double; \
                            name->divide = divide_double; \
                            name->scan = scan_double

Vertex *create_Complex()
{
    Vertex *vec = (Vertex *) malloc(sizeof(Vertex));
    (*vec).x = malloc(sizeof(double _Complex));
    (*vec).y = malloc(sizeof(double _Complex));
    (*vec).z = malloc(sizeof(double _Complex));
    func_Complex(vec);
    return vec;
}

Vertex *create_double()
{
    Vertex *vec = (Vertex *) malloc(sizeof(Vertex));
    (*vec).x = malloc(sizeof(double));
    (*vec).y = malloc(sizeof(double));
    (*vec).z = malloc(sizeof(double));
    func_double(vec);
    return vec;
}

/// сумма
Vertex *sum_Complex(Vertex *a, Vertex *b)
{
    Vertex *vec = create_Complex();
    *(double _Complex *) vec->x = (*(double _Complex *) ((*a).x) + *(double _Complex *) ((*b).x));
    *(double _Complex *) vec->y = (*(double _Complex *) ((*a).y) + *(double _Complex *) ((*b).y));
    *(double _Complex *) vec->z = (*(double _Complex *) ((*a).z) + *(double _Complex *) ((*b).z));
    return vec;
}

/// сумма
Vertex *sum_double(Vertex *a, Vertex *b)
{
    Vertex *vec = create_double();
    *(double *) vec->x = (*(double *) ((*a).x) + *(double *) ((*b).x));
    *(double *) vec->y = (*(double *) ((*a).y) + *(double *) ((*b).y));
    *(double *) vec->z = (*(double *) ((*a).z) + *(double *) ((*b).z));
    return vec;
}

/// разность
Vertex *diff_Complex(Vertex *a, Vertex *b)
{
    Vertex *vec = create_Complex();
    *(double _Complex *) vec->x = (*(double _Complex *) ((*a).x) - *(double _Complex *) ((*b).x));
    *(double _Complex *) vec->y = (*(double _Complex *) ((*a).y) - *(double _Complex *) ((*b).y));
    *(double _Complex *) vec->z = (*(double _Complex *) ((*a).z) - *(double _Complex *) ((*b).z));
    return vec;
}

/// разность
Vertex *diff_double(Vertex *a, Vertex *b)
{
    Vertex *vec = create_double();
    *(double *) vec->x = (*(double *) ((*a).x) - *(double *) ((*b).x));
    *(double *) vec->y = (*(double *) ((*a).y) - *(double *) ((*b).y));
    *(double *) vec->z = (*(double *) ((*a).z) - *(double *) ((*b).z));
    return vec;
}

/// скалярное произведение
double complex scalar_Complex(Vertex *a, Vertex *b)
{
    double complex res = gc(a, x) * gc(b, x) + gc(a, y) * gc(b, y) + gc(a, z) * gc(b, z);
    return res;
}

/// скалярное произведение
double scalar_double(Vertex *a, Vertex *b)
{
    double res = gd(a, x) * gd(b, x) + gd(a, y) * gd(b, y) + gd(a, z) * gd(b, z);
    return res;
}

/// векторное произведение
Vertex *cross_Complex(Vertex *a, Vertex *b)
{
    Vertex *vec = create_Complex();
    gc(vec, x) = gc(a, y) * gc(b, z) - gc(a, z) * gc(b, y);
    gc(vec, y) = -gc(a, x) * gc(b, z) + gc(a, z) * gc(b, x);
    gc(vec, z) = gc(a, x) * gc(b, y) - gc(a, y) * gc(a, x);
    return vec;
}

/// векторное произведение
Vertex *cross_double(Vertex *a, Vertex *b)
{
    Vertex *vec = create_double();
    gd(vec, x) = gd(a, y) * gd(b, z) - gd(a, z) * gd(b, y);
    gd(vec, y) = -gd(a, x) * gd(b, z) + gd(a, z) * gd(b, x);
    gd(vec, z) = gd(a, x) * gd(b, y) - gd(a, y) * gd(a, x);
    return vec;
}

/// модуль вектора
double mod_double(Vertex *a)
{
    double res = sqrt(gd(a, x) * gd(a, x) + gd(a, y) * gd(a, y) + gd(a, z) * gd(a, z));
    return res;
}

/// модуль вектора
double mod_Complex(Vertex *a)
{
    double res = sqrt(cabs(gc(a, x)) * cabs(gc(a, x)) + cabs(gc(a, y)) * cabs(gc(a, y)) + cabs(gc(a, z)) * cabs(gc(a, z)));
    return res;
}

/// умножение вектора на число
Vertex *dot_Complex(Vertex *vec, double c)
{
    Vertex *V_vec = create_Complex();
    gc(V_vec, x) = gc(vec, x) * c;
    gc(V_vec, y) = gc(vec, y) * c;
    gc(V_vec, z) = gc(vec, z) * c;
    return V_vec;
}

/// умножение вектора на число
Vertex *dot_double(Vertex *vec, double c)
{
    Vertex *V_vec = create_double();
    gd(V_vec, x) = gd(vec, x) * c;
    gd(V_vec, y) = gd(vec, y) * c;
    gd(V_vec, z) = gd(vec, z) * c;
    return V_vec;
}

/// деление вектора на число
Vertex *divide_Complex(Vertex *vec, double c)
{
    Vertex *V_vec = create_Complex();
    gc(V_vec, x) = gc(vec, x) / c;
    gc(V_vec, y) = gc(vec, y) / c;
    gc(V_vec, z) = gc(vec, z) / c;
    return V_vec;
}

/// деление вектора на число
Vertex *divide_double(Vertex *vec, double c)
{
    Vertex *V_vec = create_double();
    gd(V_vec, x) = gd(vec, x) / c;
    gd(V_vec, y) = gd(vec, y) / c;
    gd(V_vec, z) = gd(vec, z) / c;
    return V_vec;
}

/// вывод вектора
void print_Complex(Vertex *a)
{
    printf("{%.3f %+.3fi, %.3f %+.3fi, %.3f %+.3fi}\n", creal(gc(a, x)), cimag(gc(a, x)), creal(gc(a, y)), cimag(gc(a, y)), creal(gc(a, z)), cimag(gc(a, z)));
}

void print_double(Vertex *a)
{
    printf("{%.3f, %.3f, %.3f}\n", gd(a, x), gd(a, y), gd(a, z));
}

/// ввод вектора
Vertex *scan_Complex()
{
    Vertex *t = create_Complex();
    double a, b;
    scanf("%lf%lf", &a, &b);
    gc(t, x) = a + b * I;
    scanf("%lf%lf", &a, &b);
    gc(t, y) = a + b * I;
    scanf("%lf%lf", &a, &b);
    gc(t, z) = a + b * I;
    return t;
}

/// ввод вектора
Vertex *scan_double()
{
    Vertex *t = create_double();
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    gd(t, x) = a;
    gd(t, y) = b;
    gd(t, z) = c;
    return t;
}

/// чищу память
void deleteVertex(Vertex *a)
{
    free(a->x);
    free(a->y);
    free(a->z);
    free(a);
}