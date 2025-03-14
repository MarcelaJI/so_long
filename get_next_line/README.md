Proyecto Get_next_line

Este proyecto consiste en crear una función que lea una línea de un descriptor de archivo especificado y devuelva la línea. Este proyecto introduce nuevos conceptos como la función read() y las variables estáticas. Utilizando una variable estática con un tamaño de búfer especificado, somos capaces de leer desde un archivo y devolver una línea (hasta un carácter "\n" o el final del archivo) sin importar el tamaño del búfer. Cada llamada posterior de la función devolverá la siguiente línea, ya que la función read() conserva su lugar en el archivo que se está leyendo. Mediante el uso de una matriz estática de cadenas, somos capaces de leer desde múltiples FDs al mismo tiempo conservando nuestro lugar en todos ellos.

Recursos:

1. https://www.gnu.org/software/libc/manual/html_node/Processes.html#:~:text=A%20process%20executes%20a%20program,independently%20of%20the%20other%20copies.&text=The%20processes%20created%20by%20a%20given%20parent%20are%20called%20its%20child%20processes

2. https://www.geeksforgeeks.org/memory-layout-of-c-program

3. https://stackoverflow.com/questions/14042824/where-is-open-max-defined-for-linux-systems

4. https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/

5. https://man7.org/linux/man-pages/man2/open.2.html

6. https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm

7. https://www.educative.io/answers/what-is-a-buffer-in-c

8. https://www.educba.com/macros-in-c/

Proyecto entregado el 29/10/2024 con bonus 125/100

![Captura de pantalla 2024-10-29 131620](https://github.com/user-attachments/assets/51941029-31a4-4f3f-b7b3-7d5f267e68e0)
