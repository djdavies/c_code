#include <stdio.h>

/* Assume argv[1] is a type (text/binary/type of read)
 * argv[2] is input filename
 * argv[3] is output filename
 * Type 0 = binary
 *      1 = scanf/printf
 *      2 = fgetc/fputc
 *      3 = fgets, fputs
 */

int main (int argc, char *argv[]) {

  if (argc < 4) {
    fprintf (stderr, "Usage: %s <type> <input> <output>\n", argv[0]);
    return 1;
  }

  printf ("Read file %s\n", argv[2]);
  printf ("Write file %s\n", argv[3]);

  {
    char *pInputFileName = argv[2];
    char *pOutputFileName = argv[3];
    int iType = atoi (argv[1]);

    FILE *pfileInput = fopen (pInputFileName, iType == 0 ? "rb" : "r");
    FILE *pfileOutput = fopen (pOutputFileName, iType == 0 ? "wb" : "w");
    char buffer[1024];
    int iChar;

    if (pfileInput == NULL) {
      fprintf (stderr, "Unable to open input file : %s\n", pInputFileName);
      return 2;
    }

    if (pfileOutput == NULL) {
      fprintf (stderr, "Unable to open output file : %s\n", pOutputFileName);
      fclose(pfileInput);
      return 3;
    }

    switch (iType) {
      case 0: /* binary */
        while (!feof (pfileInput)) {
          int iNumberRead = fread (buffer, 1, 1024, pfileInput);
          printf ("Read binary block of %d bytes\n", iNumberRead);
          fwrite (buffer, iNumberRead, 1, pfileOutput);
        }
        break;
      case 1: /* fscanf, fprintf */
        while (!feof (pfileInput)) {
          if (fscanf (pfileInput, "%1023s", buffer) > 0) {
            printf ("Read scanf data: %s\n", buffer);
            fprintf (pfileOutput, "%s\n", buffer);
          }
        }
        break;
      case 2: /* fgetc, fputc */
        while (!feof (pfileInput)) {
          iChar = fgetc(pfileInput);
          if (iChar != EOF) {
            printf ("Read char '%c'\n", iChar);
            fputc (iChar, pfileOutput);
          }
        }
        break;
      case 3: /* fgets, fputs */
        while (!feof (pfileInput)) {
          if (fgets (buffer, 1023, pfileInput) != NULL) {
            printf ("Read fgets data: %s\n", buffer);
            fputs (buffer, pfileOutput);
          }
        }
        break;
      default:
        fprintf (stderr, "Unkown type %d\n", iType);
    }

    fclose (pfileOutput);
    fclose (pfileInput);
  }

  return 0;
}
