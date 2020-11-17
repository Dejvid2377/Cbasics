#include <stdio.h>
#include <math.h>
#include <stdio.h>

int main() 
{
  float a,b,c,delta;

  printf("Program oblicza pierwiastki rownania w postaci\n");
  printf("  a x + b x +c =0\n");
  printf("Podaj wartosc a:");
  scanf("%f",&a);
  printf("Podaj wartosc b:");
  scanf("%f",&b);
  printf("Podaj wartosc c:");
  scanf("%f",&c);
  
  if (a==0.0) {  /*przypadek rownania liniowego */ 
    if (b!=0.0) { 
      printf("Jest to równanie liniowe o rozwiazaniu x=%.2f\n",-b/c); }
    else  if (c==0.0) {  /* oraz a==b==0.0 */
      printf("Rozwiazaniem jest dowolne x\n"); }
    else {              /* a==b==0.0 != c  */
      printf("Brak rozwiazan\n"); }}
  else {   /*przypadek rownania kwadratowego */
    delta=pow(b,2)-4.0*a*c;
    if (delta<0) {
      printf("Brak rozwiazan rzeczywistych\n"); }
    else if (delta>0) {             /* delta>=0 */
      printf("Rozwiazaniem sa x1=%.2f i x2=%.2f\n",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a)); }
    else if (delta==0) {
    	printf("Rozwiazaniem sa x1=x2=%.2f\n",-b/(2*a)); }
  }
  return 0;
}
