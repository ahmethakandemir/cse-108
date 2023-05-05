#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
    double z;
} vector;

double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec) {
    vector cross_prod;
    cross_prod.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    cross_prod.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
    cross_prod.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
    double cross_prod_mag = sqrt((cross_prod.x * cross_prod.x) + (cross_prod.y * cross_prod.y) + (cross_prod.z * cross_prod.z));
    double angle = acos(((vec_1.x * vec_2.x) + (vec_1.y * vec_2.y) + (vec_1.z * vec_2.z)) / (sqrt((vec_1.x * vec_1.x) + (vec_1.y * vec_1.y) + (vec_1.z * vec_1.z)) * sqrt((vec_2.x * vec_2.x) + (vec_2.y * vec_2.y) + (vec_2.z * vec_2.z)))) * 180.0 / M_PI;

    output_vec->x = cross_prod.x / cross_prod_mag;
    output_vec->y = cross_prod.y / cross_prod_mag;
    output_vec->z = cross_prod.z / cross_prod_mag;

    return angle;
}

int main() {
    vector vec_1, vec_2, ortho_vec;

    printf("Enter the x, y, z coordinates of vector 1: ");
    scanf("%lf%lf%lf", &vec_1.x, &vec_1.y, &vec_1.z);

    printf("Enter the x, y, z coordinates of vector 2: ");
    scanf("%lf%lf%lf", &vec_2.x, &vec_2.y, &vec_2.z);

    double angle = find_orthogonal(vec_1, vec_2, &ortho_vec);

    printf("Angle between the two vectors: %lf degrees\n", angle);
    if(angle != 0)
        printf("Vector orthogonal to the two vectors: (%lf, %lf, %lf)\n", ortho_vec.x, ortho_vec.y, ortho_vec.z);
    else
        printf("couldn't calculate because angle between is zero!");
    return 0;
}