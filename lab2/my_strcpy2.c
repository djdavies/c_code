    #include <stdio.h> 
    
    char *my_strcpy (char *dest, char *src) {
        char *p = dest;
        char *q = src;
        // while (*(p++) = *(q++));
        while (*q) {
          *p = *q;
          p++;
          q++;
        }
        return dest;
   }

    int main (int argc, char **argv) {
        char *src = "Test1";
        char dest[] = "Changed";
          
        printf ("%s (at %p) -> %s (at %p)\n\n", src, src, dest, dest);
          
        my_strcpy (dest, src);
         
        printf ("%s == %s\n", src, dest);
          
        return 0;
    }
      
