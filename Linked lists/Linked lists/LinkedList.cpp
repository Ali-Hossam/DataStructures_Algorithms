/*
while using templates, you have to have your template defintions available
at the calling site. That means no .cpp files. The reason is templates cannot be compiled. Think of functions
as cookies and the compiler is an oven.

Templates are only a cookie cutter, because they don't know what type of cookie
they are. It only tells the compiler how to make the function when given a type, but
in itself, it can't be used because there is no concrete type being operatedon.

You can't cook a cookie cutter. Only when you have the cookie ready, you can cut
it and cook it.

Likewise, only when you actually use the template with a certain type an the compiler
generate the actual function, and compile it. It can't do this, however, if the template
definition is missing. You have to move it into the header file, so the caller of the 
function can make the cookie.

https://stackoverflow.com/questions/1639797/template-issue-causes-linker-error-c

*/
