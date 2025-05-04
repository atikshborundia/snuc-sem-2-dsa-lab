// calculate areas using classes
#include <stdio.h>
#include <stdlib.h>

class shapes
{
    // private
    private:
        float length;
        float breadth;
        float height;
    
    public:
        // setter functions
        void set_length(float l) { length = l; }
        void set_breadth(float b) { breadth = b; }
        void set_height(float h) { height = h; }
    
        // area fn
        void find_area()
        {
            // general formula for all shapes' area
            printf("%.2f\n", (2.0 * ((breadth * length) + (breadth * height) + (length * height))));
        }
};

int main()
{
    shapes square;
    shapes cube;
    shapes rectangle;
    shapes cuboid;
    
    float length, breadth, height;

    // scanning the values
    printf("Enter the length of the shape\n");
    scanf("%f", &length);
    printf("\n");
    
    printf("Enter the breadth of the shape\n");
    scanf("%f", &breadth);
    printf("\n");
    
    printf("Enter the height of the shape\n");
    scanf("%f", &height);
    printf("\n");
    
    // setting the values
    cuboid.set_length(length);
    cuboid.set_breadth(breadth);
    cuboid.set_height(height);
    
    char choice = 'f';
    
    while(choice != 'd' || choice != 'D')
    { 
        printf("Main Menu:\n\n");
        printf("a. Square\n");
        printf("b. Cube\n");
        printf("c. Rectangle\n");
        printf("d. Cuboid\n");
        printf("e. Exit\n");
        
        printf("PLease choose one of the options:");
        scanf(" %c", &choice);
        
        switch (choice)
        {
            case 'a':
            case 'A':
                // changing the values according to square for a general formula
                square.set_length(length);
                square.set_breadth(length / 2);
                square.set_height(0);
                square.find_area();
                break;
            
            case 'b':
            case 'B':
                // changing the values according to cube for a general formula
                cube.set_length(length);
                cube.set_breadth(length);
                cube.set_height(length);
                cube.find_area();
                break;
            
            case 'c':
            case 'C':
                // changing the values according to rectangle for a general formula
                rectangle.set_length(length);
                rectangle.set_breadth(breadth / 2);
                rectangle.set_height(0);
                rectangle.find_area();
                break;
            
            case 'd':
            case 'D':
                cuboid.find_area();
                break;
            
            case 'e':
            case 'E':
                printf("Thank you for using our program.\n");
                printf("Please come again\n");
                return 0;
            
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    
    return 0;
}
