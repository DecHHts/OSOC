#include <stdio.h>
#include <math.h>

struct complex_struct{
    double x,y;
};
double real_part(struct complex_struct z){
    return z.x;
}
double imag_part(struct complex_struct z){
    return z.y;
}
double magnitude(struct complex_struct z){
    return sqrt(z.x * z.x + z.y * z.y);
}
double angle(struct complex_struct z){
    return atan2(z.y, z.x);
}

struct complex_struct make_from_real_imag(double x, double y){
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}
struct complex_struct make_from_mag_ang(double r, double A){
    struct complex_struct z;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_real_imag(real_part(z1) + real_part(z2), imag_part(z1) + imag_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_real_imag(real_part(z1) - real_part(z2), imag_part(z1) - imag_part(z2));
}
struct complex_struct multiply_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}
struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z){
    double x = real_part(z);
    double y = imag_part(z);
    if(y > 0){
        printf("%.2f + %.2fi\n", x, y);
    }else if(y < 0){
        printf("%.2f - %.2fi\n", x, -y);
    }else{
        printf("%.2f\n", x);
    }
}

struct rational_struct{
    int numerator;
    int denominator;
};

struct rational_struct make_rational(int numerator, int denominator){
    struct rational_struct r;
    r.numerator = numerator;
    r.denominator = denominator;
    return r;
}
struct rational_struct add_rational(struct rational_struct r1, struct rational_struct r2){
    return make_rational(r1.numerator * r2.denominator + r2.numerator * r1.denominator, r1.denominator * r2.denominator);
}
struct rational_struct sub_rational(struct rational_struct r1, struct rational_struct r2){
    return make_rational(r1.numerator * r2.denominator - r2.numerator * r1.denominator, r1.denominator * r2.denominator);
}
struct rational_struct multiply_rational(struct rational_struct r1, struct rational_struct r2){
    return make_rational(r1.numerator * r2.numerator, r1.denominator * r2.denominator);
}
struct rational_struct div_rational(struct rational_struct r1, struct rational_struct r2){
    return make_rational(r1.numerator * r2.denominator, r1.denominator * r2.numerator);
}
void print_rational(struct rational_struct r){
    printf("%d/%d\n", r.numerator, r.denominator);
}   
int main(){
    struct complex_struct z1 = make_from_real_imag(3.0, 4.0);
    struct complex_struct z2 = make_from_real_imag(1.0, -2.0);
    struct complex_struct z3 = make_from_real_imag(8.0, 0.0);
    print_complex(z1);
    print_complex(z2);
    print_complex(z3);
    struct rational_struct a = make_rational(1, 8);
    struct rational_struct b = make_rational(-1, 8);
    print_rational(add_rational(a, b));
    print_rational(sub_rational(a, b));
    print_rational(multiply_rational(a, b));
    print_rational(div_rational(a, b));
    return 0;
}