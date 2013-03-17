#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define a structure which will contain the details for a person */
struct Person {
  char pFirstName[1024];
  char pLastName[1024];
  int iAge;
};

/* Array for 5 people */
struct Person g_pArrayPeople[5];

/* Count of number of Person items in the array; initially zero */
int g_iPersonCount = 0;

/* Display the stored Person details from the array */
void DisplayStored () {
  int i;
  for (i = 0; i < g_iPersonCount; ++i) {
    printf( "%s %s : Age %d\n", g_pArrayPeople[i].pFirstName,
                                g_pArrayPeople[i].pLastName,
                                g_pArrayPeople[i].iAge );
  }
  return;
}

void StorePerson (char *strFirstName, char *strLastName, int iAge) {
  printf ("DEBUG:\n");
  printf ("List of people before storing new one:\n");
  DisplayStored ();
  printf ("END DEBUG\n\n");

  /* We had room for 5 people */
  if (g_iPersonCount < 5) {
    strcpy (g_pArrayPeople[g_iPersonCount].pFirstName, strFirstName);
    strcpy (g_pArrayPeople[g_iPersonCount].pLastName, strLastName);
    g_pArrayPeople[g_iPersonCount].iAge = iAge;
    g_iPersonCount++; /* Increment the count */
  }

  return;
}

/* Ask the user for input */
void GetInput() {
  /* The strings to receive the input must be big enough for the biggest input the user will supply. */
  char strFirstName[1024];
  char strLastName[1024];
  int iAge = 0;
  int iInputCount;
  char cConfirm;

  printf ("Please supply the customer details:\n");

  printf ("First/personal Name (or 'exit'): ");
  /* Ask for a string to be put into the array strFirstName */
  scanf ("%1023s", strFirstName);
  if (strcmp (strFirstName, "exit") == 0) {
    /* If the string passed in is the same as the string "exit" then exist program */
    exit(0);
  }
  printf ("First/personal name: %s\n", strFirstName);

  printf ("\nLast/family Name: ");
  scanf ("%1023s", strLastName);
  strLastName[1023] = 0; /* Ensure terminated */
  printf ("Last/family name: %s\n", strLastName);

  printf ("\nAge: ");
  scanf ("%d", &iAge);
  printf ("Age: %d\n", iAge);

  printf ("You entered:\n");
  printf ("First/personal name : %s\n", strFirstName);
  printf ("Last/family name    : %s\n", strLastName);
  printf ("Age                 : %d\n", iAge);
  printf ("Is this correct (Y/N):\n");
  /* Loop forever - or until a break is met! */
  while (1) {
    scanf ("%c", &cConfirm);
    if (tolower (cConfirm) == 'y') {
      /* We got a 'y' so store the person and end the loop */
      StorePerson (strFirstName, strLastName, iAge);
      break;
    } else if (tolower(cConfirm) == 'n') {
      /* We got a 'n' so end the loop without storing the person */
      break;
    }
  }

  return;
}

int main (int argc, char* argv[]) {
  /* Loop forever: note that there is an 'exit(0)' above this which ends the program */
  while (1) {
    GetInput ();

    printf ("\n\n\nList of people so far:\n");
    DisplayStored ();
    printf ("\n");
  }

  /* Should never get here due to the infinite loop */
  return 0;
}
