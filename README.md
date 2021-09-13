# Magic Cube

## Concept

The generation of Magic Cubes is closely related to the generation of the Magic Squares as they are 3D variants of Magic Squares. The core concept for the generation of magic square via the Siamese method is that the next element should not be in the same row or column of the initial element (unless the position is already filled). This is the reason why we move one position diagonally on the board. 

<img src="C:\Users\Sasank\AppData\Roaming\Typora\typora-user-images\image-20210908225714817.png" alt="image-20210908225714817" style="zoom:80%;" />



The same logic can be extended to the concept of Magic Cube. In the Extended Siamese Method, instead of moving on position *planarly* diagonal, we move one position _spatially_ diagonal. like, the magic square our goal is to insert consecutive elements in positions which do not share a row, column or layer (unless the position is already filled). The algorithm for generation of Magic Cube of order 3 is given below. We are using indexing from the number one (instead of the traditional C-style '0') to the number 3 to represent the positions inside the cube. All the triplets are in the format [Layer, Row, Column].

## Extended Siamese Method Algorithm

```
Move 1.  Number 1 is placed in the center of the top layer (Layer 1) [1, 2, 2].
Move 2.  Move to [Layer-1,Row-1,Column-1] (Diagonally one move spatially down).
Move 3.  If it is occupied move to [Layer-1,Row-1,Column].
Move 5.  If it is also occupied move to [Layer+1,Row,Column].
Move 6.  Fill the current cell with following number and keep iterating from Move 2 until all the blocks have been occupiednumbers from 1 to 27.
```

## Properties of Magic cube of Order 3

<img src="C:\Users\Sasank\AppData\Roaming\Typora\typora-user-images\image-20210909123005041.png" alt="image-20210909123005041" style="zoom:67%;" />

The sum of the major diagonals, pillars, rows and columns should equal **n(n^3+1)/2** or in our case **42**.



1. **Rows** are horizontal and planar and **each layer contains three of them**. 

   

2. **Columns** are horizontal and planar and **each layer contains three of them**. 

   

3. **Pillars** are vertical and spatial, they pierce through the layers vertically and **nine pillars exist for the nine blocks on each layer**. 

   

4. **Major diagonals** are all the **collinear lines that pass through the central block** i.e.. [1, 1, 1], the sum of all elements in a major diagonal is always 42.


