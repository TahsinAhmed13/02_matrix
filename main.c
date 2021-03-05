#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

    /* Matrix Test */

    struct matrix *A = new_matrix(4, 4); 
    for(int j = 0; j < 4; ++j)
    {
        for(int i = 0; i < 4; ++i)
            A->m[i][j] = (i+1) * (j+1); 
        A->lastcol++; 
    }
    printf("Matrix A:\n"); 
    print_matrix(A); 
    printf("\n"); 

    struct matrix *B = new_matrix(4, 4); 
    ident(B); 
    printf("Identity B:\n"); 
    print_matrix(B); 
    printf("\n"); 

    matrix_mult(A, B);  
    printf("Multiply Identity:\n"); 
    print_matrix(B); 
    printf("\n"); 

    B->lastcol = 0; 
    for(int j = 0; j < 4; ++j)
    {
        for(int i = 0; i < 4; ++i)
            B->m[i][j] = (4-i) * (4-j); 
        B->lastcol++; 
    }
    printf("Matrix B:\n"); 
    print_matrix(B); 
    printf("\n"); 

    matrix_mult(A, B); 
    printf("Multiply A * B:\n"); 
    print_matrix(B); 
    printf("\n"); 

    free_matrix(A); 
    free_matrix(B); 

    /* Edges Test */

    screen s;
    color c = { 255, 255, 0 }; 
    struct matrix *edges;

    clear_screen(s); 
    edges = new_matrix(4, 4);

    add_edge(edges, 0, 0, 0, XRES/2.0, YRES, 0); 
    add_edge(edges, XRES/2.0, YRES, 0, XRES, 0, 0); 
    add_edge(edges, XRES, 0, 0, 0, 0, 0); 

    draw_lines(edges, s, c); 
    display(s); 
    save_extension(s, "triangle.png"); 

    free_matrix( edges );
}  
