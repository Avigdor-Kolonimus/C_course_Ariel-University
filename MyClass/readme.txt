We want to write a class in C language. Although there is no such thing we will use structures. 
Our structure will be called myClass and will have an int m_x int
And a function for the add () function, which will receive two parameters: a pointer to myClass, 
and a pointer to the object itself, and parameter y. The function will add y to m_x.

Now we want to create a mechanism for inheritance. There are two types of inheritance:
- Overriding inheritance
  The Derived class preserves the structure of myClass, but instead of the add () function adding y to m_x it will do xor between them.

- Expanding inheritance
  Expanded inheritance adds additional organs and functions to the basic structure of the parent department.
  For example the Derived2 class will have another m_y organ. By calling the add () function besides adding y to m_x, 
  we also save the parameter value y into m_y.
