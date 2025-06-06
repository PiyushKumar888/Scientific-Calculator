#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// Mathematical Constants
#define PI 3.141592653589793
#define E 2.718281828459045
#define GOLDEN_RATIO 1.618033988749895

// Physics Constants
#define G 9.80665              // Gravitational acceleration (m/s²)
#define SPEED_OF_LIGHT 299792458.0 // Speed of light (m/s)
#define PLANCK 6.62607015e-34  // Planck's constant (J·s)
#define BOLTZMANN 1.380649e-23 // Boltzmann constant (J/K)
#define AVOGADRO 6.02214076e23 // Avogadro's number (mol⁻¹)

// Trigonometric Constants
#define SIN_30 0.5
#define COS_60 0.5
#define TAN_45 1.0

// Conversion Factors
#define DEG_TO_RAD (PI / 180.0) // Degrees to radians
#define RAD_TO_DEG (180.0 / PI) // Radians to degrees

// Additional Math Constants
#define SQRT_2 1.414213562373095
#define SQRT_3 1.732050807568877

void features(){
    printf("Choose an operation from the list below by entering the corresponding symbol:\n");
printf("-------------------------------------------------------------\n");
printf("+  : Addition\n");
printf("-  : Subtraction\n");
printf("*  : Multiplication\n");
printf("/  : Division\n");
printf("%%  : Modulus (Remainder)\n"); // Use %% to escape % in printf
printf("^  : Power (Exponentiation)\n");
printf("!  : Factorial\n");
printf("s  : Square\n");
printf("r  : Square Root\n");
printf("c  : Cube\n");
printf("q  : Solve Quadratic Equation\n");
printf("a  : Calculate Area (choose specific shape later)\n");
printf("l  : Length Conversion\n");
printf("x  : Logarithm (Log) Calculation\n");
printf("y  : Antilogarithm (Antilog) Calculation\n");
printf("e  : Exit\n");
printf("-------------------------------------------------------------\n");

}
double addition(double arr[],int len){
    double sum=0;
    int i;
    for(i=0;i<len;i++){
        sum+=arr[i];
    }
    return sum;
}
double subtraction(double arr[],int len){
    double minus=arr[0];
    int i;
    for(i=1;i<len;i++){
        minus-=arr[i];
    }
    return minus;
}
double multiplication(double arr[],int len){
    double result=1.0;
    int i;
    for(i=0;i<len;i++){
        result*=arr[i];
    }
    return result;
}
double division(double a, double b) {
    if (b == 0) {
        printf("Error: division by zero not allowed\n");
        return NAN;  
    }
    return a / b;
}
double modulus(double n){
    
    return fabs(n);
}
double powr(double a,int b){

    
    return pow(a,b);
}
int factorial(int n){
    if(n==0||n==1){
        return 1;
    }
    if(n<0){
        printf("enter a positive number\n");
    }
    else{
        return n*factorial(n-1);
    }
}
double square(double n){
    return n*n;
}
double square_root(double n){
    return sqrt(n);
}
double cube(double n){
    return n*n*n;
}
void quadratic_equation(){
    double a,b,c;
    printf("enter x^2,x,c");
    scanf("%lf%lf%lf",&a,&b,&c);
    double D,result;
    D=(b*b)-(4*a*c);
    if(D>0){
          printf("roots are real and unequal\n");
          double result1=(-b+sqrt(D))/(2*a);
          double result2=(-b-sqrt(D))/(2*a);
          printf("roots are x1: %lf and x2: %lf",result1,result2);
    }
    else if(D==0){
         printf("roots are real and equal\n");
         result=-b/(2*a);
         printf("roots are x1: %lf and x2: %lf",result,result);
    }
    else if(D<0){
        printf("roots are imaginary\n");
        double realpart=-b/(2*a);
        double imaginarypart=sqrt(-D)/(2*a);
        printf("x1: %lf+%lfi ",realpart,imaginarypart);
        printf("x2: %lf-%lfi",realpart,imaginarypart);
    }
}
double convert_to_radian(double angle,int isdegree){
    if(isdegree){
        return angle*DEG_TO_RAD;
    }
    else{
        return angle;
    }
}
int setmod(){
    printf("want to enter angle in radian or degree\n");
    printf("1 for radian\n2 for degree\n");
    int isdegree;
    scanf("%d",&isdegree);
    
       if(isdegree==2){
        printf("you choose degree\n");
         return 1;
       }
       else if(isdegree==1){
        printf("you choose radian\n");
        return 0;
       }
    
    else{
        printf("Invalid choice!! Defaulting to radian\n ");
        return 0;
    }
}
double log_base(double x, double b) {
    return log(x) / log(b);  
}

double antilog_base(double x, double b) {
    return pow(b, x);  
}


double trignometric_function(){
 int     isdegree=setmod();
 printf("\n");
    printf("Choose a trigonometric operation to perform:\n");
    printf("s : Sine (sin)\n");
    printf("c : Cosine (cos)\n");
    printf("t : Tangent (tan)\n");
    printf("a : Arcsine (asin)\n");
    printf("o : Arccosine (acos)\n");
    printf("g : Arctangent (atan)\n");
    printf("f : Sine of (a + b)\n");
    printf("k : Cosine of (a + b)\n");
    printf("m : Tangent of (a + b)\n");
    double angle1,angle2,result;
    char choice;
    printf("enter your choice\n");
    scanf(" %c",&choice);
     switch (choice) {
        case 's':
            printf("Enter angle: ");
            scanf("%lf", &angle1);
            angle1 = convert_to_radian(angle1, isdegree);
            result = sin(angle1);
            printf("sin(%lf): %lf\n", angle1, result);
            break;
        case 'c':
            printf("Enter angle: ");
            scanf("%lf", &angle1);
            angle1 = convert_to_radian(angle1, isdegree);
            result = cos(angle1);
            printf("cos(%lf): %lf\n", angle1, result);
            break;
        case 't':
            printf("Enter angle: ");
            scanf("%lf", &angle1);
            angle1 = convert_to_radian(angle1, isdegree);
            result = tan(angle1);
            printf("tan(%lf): %lf\n", angle1, result);
            break;
        case 'f':
            printf("Enter angle a: ");
            scanf("%lf", &angle1);
            printf("Enter angle b: ");
            scanf("%lf", &angle2);
            angle1 = convert_to_radian(angle1, isdegree);
            angle2 = convert_to_radian(angle2, isdegree);
            result = sin(angle1) * cos(angle2) + cos(angle1) * sin(angle2);
            printf("sin(%lf + %lf): %lf\n", angle1, angle2, result);
            break;
        case 'k':
            printf("Enter angle a: ");
            scanf("%lf", &angle1);
            printf("Enter angle b: ");
            scanf("%lf", &angle2);
            angle1 = convert_to_radian(angle1, isdegree);
            angle2 = convert_to_radian(angle2, isdegree);
            result = cos(angle1) * cos(angle2) - sin(angle1) * sin(angle2);
            printf("cos(%lf + %lf): %lf\n", angle1, angle2, result);
            break;
        case 'm':
            printf("Enter angle a: ");
            scanf("%lf", &angle1);
            printf("Enter angle b: ");
            scanf("%lf", &angle2);
            angle1 = convert_to_radian(angle1, isdegree);
            angle2 = convert_to_radian(angle2, isdegree);
            if (cos(angle1) * cos(angle2) != 0) {
                result = (tan(angle1) + tan(angle2)) / (1 - tan(angle1) * tan(angle2));
                printf("tan(%lf + %lf): %lf\n", angle1, angle2, result);
            } else {
                printf("Error: Undefined result (cos(a+b) = 0).\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }
    return result;
}
void length_conversion(){ double result;
      printf("Choose a length conversion operation:\n");
printf("--------------------------------------\n");
printf("1 : Meters to Kilometers\n");
printf("2 : Kilometers to Meters\n");
printf("3 : Centimeters to Meters\n");
printf("4 : Meters to Centimeters\n");
printf("5 : Inches to Centimeters\n");
printf("6 : Centimeters to Inches\n");
printf("7 : Feet to Meters\n");
printf("8 : Meters to Feet\n");
printf("9 : Yards to Meters\n");
printf("10: Meters to Yards\n");
printf("11: Miles to Kilometers\n");
printf("12: Kilometers to Miles\n");
printf("--------------------------------------\n");
int choice;
double value;
printf("enter your choice\n");
scanf("%d",&choice);
printf("enter value:");
scanf("%lf",&value);

    switch (choice) {
        case 1: // Meters to Kilometers
            result = value / 1000.0;
            printf("%.2lf meters is %.2lf kilometers\n", value, result);
            break;
        case 2: // Kilometers to Meters
            result = value * 1000.0;
            printf("%.2lf kilometers is %.2lf meters\n", value, result);
            break;
        case 3: // Centimeters to Meters
            result = value / 100.0;
            printf("%.2lf centimeters is %.2lf meters\n", value, result);
            break;
        case 4: // Meters to Centimeters
            result = value * 100.0;
            printf("%.2lf meters is %.2lf centimeters\n", value, result);
            break;
        case 5: // Inches to Centimeters
            result = value * 2.54;
            printf("%.2lf inches is %.2lf centimeters\n", value, result);
            break;
        case 6: // Centimeters to Inches
            result = value / 2.54;
            printf("%.2lf centimeters is %.2lf inches\n", value, result);
            break;
        case 7: // Feet to Meters
            result = value * 0.3048;
            printf("%.2lf feet is %.2lf meters\n", value, result);
            break;
        case 8: // Meters to Feet
            result = value / 0.3048;
            printf("%.2lf meters is %.2lf feet\n", value, result);
            break;
        case 9: // Yards to Meters
            result = value * 0.9144;
            printf("%.2lf yards is %.2lf meters\n", value, result);
            break;
        case 10: // Meters to Yards
            result = value / 0.9144;
            printf("%.2lf meters is %.2lf yards\n", value, result);
            break;
        case 11: // Miles to Kilometers
            result = value * 1.60934;
            printf("%.2lf miles is %.2lf kilometers\n", value, result);
            break;
        case 12: // Kilometers to Miles
            result = value / 1.60934;
            printf("%.2lf kilometers is %.2lf miles\n", value, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

    void area_calculation() {
    int shapeChoice;
    double area;
    
    printf("Choose a shape to calculate the area:\n");
    printf("1 : Square\n");
    printf("2 : Rectangle\n");
    printf("3 : Circle\n");
    printf("4 : Triangle\n");
    printf("5 : Parallelogram\n");
    printf("6 : Trapezoid\n");
    printf("---------------------------------\n");
    
    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &shapeChoice);
    
    // Switch case for various shapes
    switch (shapeChoice) {
        case 1: {  // Square
            double side;
            printf("Enter the side length of the square: ");
            scanf("%lf", &side);
            area = side * side;
            printf("Area of the square: %.2lf\n", area);
            break;
        }
        case 2: {  // Rectangle
            double length, width;
            printf("Enter the length and width of the rectangle: ");
            scanf("%lf %lf", &length, &width);
            area = length * width;
            printf("Area of the rectangle: %.2lf\n", area);
            break;
        }
        case 3: {  // Circle
            double radius;
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = PI * radius * radius;  // Using PI constant
            printf("Area of the circle: %.2lf\n", area);
            break;
        }
        case 4: {  // Triangle
            double base, height;
            printf("Enter the base and height of the triangle: ");
            scanf("%lf %lf", &base, &height);
            area = 0.5 * base * height;
            printf("Area of the triangle: %.2lf\n", area);
            break;
        }
        case 5: {  // Parallelogram
            double base, height;
            printf("Enter the base and height of the parallelogram: ");
            scanf("%lf %lf", &base, &height);
            area = base * height;
            printf("Area of the parallelogram: %.2lf\n", area);
            break;
        }
        case 6: {  // Trapezoid
            double base1, base2, height;
            printf("Enter the lengths of the two bases and the height of the trapezoid: ");
            scanf("%lf %lf %lf", &base1, &base2, &height);
            area = 0.5 * (base1 + base2) * height;
            printf("Area of the trapezoid: %.2lf\n", area);
            break;
        }
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}





int main(){
    char choice;

    while (1) {
        features();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'e') {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        switch (choice) {
            case '+': {
                int n;
                printf("Enter number of terms: ");
                scanf("%d", &n);
                double arr[n];
                printf("Enter the numbers: ");
                for (int i = 0; i < n; i++) {
                    scanf("%lf", &arr[i]);
                }
                printf("Sum: %.2lf\n", addition(arr, n));
                break;
            }
            case '-': {
                int n;
                printf("Enter number of terms: ");
                scanf("%d", &n);
                double arr[n];
                printf("Enter the numbers: ");
                for (int i = 0; i < n; i++) {
                    scanf("%lf", &arr[i]);
                }
                printf("Difference: %.2lf\n", subtraction(arr, n));
                break;
            }
            case '*': {
                int n;
                printf("Enter number of terms: ");
                scanf("%d", &n);
                double arr[n];
                printf("Enter the numbers: ");
                for (int i = 0; i < n; i++) {
                    scanf("%lf", &arr[i]);
                }
                printf("Product: %.2lf\n", multiplication(arr, n));
                break;
            }
            case '/': {
                int a,b;
                printf("enter the numerator and denominator respectively:");
                scanf("%d%d",&a,&b);
                double result=division( a, b);
                printf("Result: %.2lf\n", result);
                break;
            }
            case '%': {
                double a;
                printf("Enter number: ");
                scanf("%lf", &a);
                double result=modulus(a);
                printf("Remainder: %.2lf\n",result );
                break;
            }
            case '^': {
                double base, exp;
                printf("Enter the base and exponent: ");
                scanf("%lf %lf", &base, &exp);
                double result=powr(base,exp);
                printf("Result: %.2lf\n", result);
                break;
            }
            case '!': {
                int n;
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &n);
                int result=factorial(n);
                printf("Factorial: %d\n", result);
                break;
            }
            case 's': {
                double a;
                printf("Enter a number: ");
                scanf("%lf", &a);
                double result=square(a);
                printf("Square: %.2lf\n", result);
                break;
            }
            case 'r': {
                double a;
                printf("Enter a number: ");
                scanf("%lf", &a);
                double result=square_root(a);
                printf("Square root: %.2lf\n", result);
                break;
            }
            case 'c': {
                double a;
                printf("Enter a number: ");
                scanf("%lf", &a);
                double result=cube(a);
                printf("Cube: %.2lf\n", result);
                break;
            }
            case 'q': {
                quadratic_equation();
                printf("\n");
                break;
            }
            case 'a': {
                area_calculation();
                printf("\n");
                break;
            }
            case 'l': {
                length_conversion();
                printf("\n");
                break;
            }
             case 'x': {  
                double x, b;
                printf("Enter the number (x) and the base (b) for logarithm: ");
                scanf("%lf %lf", &x, &b);
                if (x <= 0 || b <= 0 || b == 1) {
                    printf("Invalid input! x must be > 0, and base b must be > 0 and not equal to 1.\n");
                } else {
                    double result = log_base(x, b);
                    printf("log base %.2lf of %.2lf is: %.4lf\n", b, x, result);
                }
                break;
            }
            case 'y': {  
                double x, b;
                printf("Enter the number (x) and the base (b) for antilogarithm: ");
                scanf("%lf %lf", &x, &b);
                if (b <= 0 || b == 1) {
                    printf("Invalid input! Base b must be > 0 and not equal to 1.\n");
                } else {
                    double result = antilog_base(x, b);
                    printf("Antilog base %.2lf of %.2lf is: %.4lf\n", b, x, result);
                }
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
 
