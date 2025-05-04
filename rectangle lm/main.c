#include <stdio.h>
void main()
{
    int width,height,area,perimeter;
    printf("Enter width=");
    scanf("%d", &width);
    printf("Enter height=");
    scanf("%d", &height);
    area=width*height;
    perimeter=2*(width+height);
    printf("%d*%d=%d\n", width,height,area);
    printf("2(%d+%d)=%d",width,height,perimeter);
}
