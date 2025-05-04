# include <stdio.h>
# include <conio.h>

struct emp
{
char name[ 40 ] ;
int age ;
float bs ;
} ;
int main( )
{
FILE *fp ;
char another = 'Y' ;

struct emp e ;
 fp = fopen ("D:/Adeel/employee.txt", "w" );
if ( fp == NULL )
{
puts ( "Cannot open file" ) ;
exit ( 1 ) ;
}
while ( another == 'Y' )
{
printf ( "\nEnter name, age and basic salary: " ) ;
scanf ( "%s %d %f", e.name, &e.age, &e.bs ) ;
fprintf ( fp, "%s %d %f\n", e.name, e.age, e.bs ) ;
printf ( "Add another record (Y/N) " ) ;
fflush ( stdin ) ;
another = getche( ) ;
}

fclose ( fp ) ;
return 0 ;
}

